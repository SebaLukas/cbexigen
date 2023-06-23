use crate::app_handshake::app_hand_datatypes::*;
use crate::common::exi_basetypes_decoder::{decoder_characters, decoder_nbit_uint, decoder_u16};
use crate::common::exi_bitstream::ExiBitstream;
use crate::common::exi_error_codes::ExiError;
use crate::common::exi_header::exi_header_read_and_check;
use crate::common::exi_types_decoder::decode_exi_type_u32;

fn decode_app_protocol_type(stream: &mut ExiBitstream) -> Result<AppHandAppProtocolType, ExiError> {
    let mut protocol_namespace = String::new();
    let mut version_number_major: u32 = 0;
    let mut version_number_minor: u32 = 0;
    let mut schema_id: u8 = 0;
    let mut priority: u8 = 0;

    let mut done = false;
    let mut grammar_id = 0;

    while !done {
        match grammar_id {
            0 => {
                // Start(ProtocolNamespace)
                if decoder_nbit_uint(stream, 1)? == 0 {
                    // Start(ProtocolNamespace, protocolNamespaceType (anyURI))
                    if decoder_nbit_uint(stream, 1)? == 0 {
                        let characters_len = decoder_u16(stream)?;
                        if characters_len >= 2 {
                            protocol_namespace = decoder_characters(
                                stream,
                                (characters_len - 2) as usize,
                                APP_HAND_PROTOCOL_NAMESPACE_CHARACTER_SIZE as usize,
                            )?;
                        } else {
                            return Err(ExiError::StringvaluesNotSupported);
                        }
                    } else {
                        return Err(ExiError::UnsupportedSubEvent);
                    }
                    // EE
                    if decoder_nbit_uint(stream, 1)? == 0 {
                        grammar_id = 1;
                    } else {
                        return Err(ExiError::DeviantsNotSupported);
                    }
                } else {
                    return Err(ExiError::UnknownEventCode);
                }
            }
            1 => {
                // Start(VersionNumberMajor)
                if decoder_nbit_uint(stream, 1)? == 0 {
                    version_number_major = decode_exi_type_u32(stream)?;
                    grammar_id = 2;
                } else {
                    return Err(ExiError::UnknownEventCode);
                }
            }
            2 => {
                // Start(VersionNumberMinor)
                if decoder_nbit_uint(stream, 1)? == 0 {
                    version_number_minor = decode_exi_type_u32(stream)?;
                    grammar_id = 3;
                } else {
                    return Err(ExiError::UnknownEventCode);
                }
            }
            3 => {
                // Start(SchemaID)
                if decoder_nbit_uint(stream, 1)? == 0 {
                    // Start(SchemaID, idType (unsignedByte)
                    if decoder_nbit_uint(stream, 1)? == 0 {
                        schema_id = decoder_nbit_uint(stream, 8)? as u8;
                    } else {
                        return Err(ExiError::UnsupportedSubEvent);
                    }
                    // EE
                    if decoder_nbit_uint(stream, 1)? == 0 {
                        grammar_id = 4;
                    } else {
                        return Err(ExiError::DeviantsNotSupported);
                    }
                } else {
                    return Err(ExiError::UnknownEventCode);
                }
            }
            4 => {
                // Start(Priority)
                if decoder_nbit_uint(stream, 1)? == 0 {
                    // Start(Priority, priorityType (unsignedByte))
                    if decoder_nbit_uint(stream, 1)? == 0 {
                        priority = decoder_nbit_uint(stream, 5)? as u8 + 1;
                    } else {
                        return Err(ExiError::UnsupportedSubEvent);
                    }
                    // EE
                    if decoder_nbit_uint(stream, 1)? == 0 {
                        grammar_id = 5;
                    } else {
                        return Err(ExiError::DeviantsNotSupported);
                    }
                } else {
                    return Err(ExiError::UnknownEventCode);
                }
            }
            5 => {
                // EE
                if decoder_nbit_uint(stream, 1)? == 0 {
                    done = true;
                } else {
                    return Err(ExiError::UnknownEventCode);
                }
            }
            _ => return Err(ExiError::UnknownGrammarId),
        }
    }
    Ok(AppHandAppProtocolType::new(
        protocol_namespace,
        version_number_major,
        version_number_minor,
        schema_id,
        priority,
    ))
}

fn decode_supported_app_protocol_req(
    stream: &mut ExiBitstream,
) -> Result<AppHandSupportedAppProtocolReq, ExiError> {
    let mut app_hand_request: Vec<AppHandAppProtocolType> = Vec::new();
    let mut grammar_id = 7;
    let mut done = false;

    while !done {
        match grammar_id {
            7 => {
                if decoder_nbit_uint(stream, 1)? == 0 {
                    if app_hand_request.len() < APP_HAND_APPPROTOCOLTYPE_5_ARRAY_SIZE as usize {
                        app_hand_request.push(decode_app_protocol_type(stream)?);
                    } else {
                        return Err(ExiError::ArrayOutOfBounds);
                    }
                    grammar_id = 8;
                } else {
                    return Err(ExiError::UnknownEventCode);
                }
            }
            8..=11 => match decoder_nbit_uint(stream, 2)? {
                0 => {
                    if app_hand_request.len() < APP_HAND_APPPROTOCOLTYPE_5_ARRAY_SIZE as usize {
                        app_hand_request.push(decode_app_protocol_type(stream)?);
                    } else {
                        return Err(ExiError::ArrayOutOfBounds);
                    }
                    if grammar_id == 11 {
                        grammar_id = 5;
                    } else {
                        grammar_id += 1;
                    }
                }
                1 => done = true,
                _ => return Err(ExiError::UnknownEventCode),
            },
            5 => {
                if decoder_nbit_uint(stream, 1)? == 0 {
                    done = true;
                } else {
                    return Err(ExiError::UnknownEventCode);
                }
            }
            _ => return Err(ExiError::UnknownGrammarId),
        }
    }
    Ok(AppHandSupportedAppProtocolReq::new(app_hand_request))
}

fn decode_supported_app_protocol_res(
    stream: &mut ExiBitstream,
) -> Result<AppHandSupportedAppProtocolRes, ExiError> {
    let mut grammer_id = 12;
    let mut done = false;
    let mut response_code = ResponseCode::FailedNoNegotiation;
    let mut schema_id = None;

    while !done {
        match grammer_id {
            12 => {
                // Start(ResponseCode)
                let event_code = decoder_nbit_uint(stream, 1);
                if event_code.is_ok() {
                    // Start(ResponseCodeType)
                    if decoder_nbit_uint(stream, 1)? == 0 {
                        let value = decoder_nbit_uint(stream, 2)?;
                        response_code = ResponseCode::try_from(value).unwrap();
                    } else {
                        return Err(ExiError::UnsupportedSubEvent);
                    }
                    // EE
                    if decoder_nbit_uint(stream, 1)? == 0 {
                        grammer_id = 13;
                    } else {
                        return Err(ExiError::DeviantsNotSupported);
                    }
                } else {
                    return Err(ExiError::UnknownEventCode);
                }
            }
            13 => {
                let event_code = decoder_nbit_uint(stream, 2)?;
                match event_code {
                    0 => {
                        // Start(SchemaID)
                        if decoder_nbit_uint(stream, 1)? == 0 {
                            schema_id = Some(decoder_nbit_uint(stream, 8)? as u8);
                        } else {
                            return Err(ExiError::UnsupportedSubEvent);
                        }
                        // EE
                        if decoder_nbit_uint(stream, 1)? == 0 {
                            grammer_id = 5;
                        } else {
                            return Err(ExiError::DeviantsNotSupported);
                        }
                    }
                    1 => {
                        // EE
                        done = true;
                    }
                    _ => return Err(ExiError::UnknownEventCode),
                }
            }
            5 => {
                // EE
                if decoder_nbit_uint(stream, 1)? == 0 {
                    done = true;
                } else {
                    return Err(ExiError::UnknownEventCode);
                }
            }
            _ => return Err(ExiError::UnknownGrammarId),
        }
    }
    Ok(AppHandSupportedAppProtocolRes::new(
        response_code,
        schema_id,
    ))
}

pub fn decode_exi_document(stream: &mut ExiBitstream) -> Result<AppProtocolExiDocument, ExiError> {
    exi_header_read_and_check(stream)?;

    let event_code = decoder_nbit_uint(stream, 2)?;
    match event_code {
        0 => {
            let request = decode_supported_app_protocol_req(stream)?;
            Ok(AppProtocolExiDocument::SupportedAppProtocolReq(request))
        }
        1 => {
            let response = decode_supported_app_protocol_res(stream)?;
            Ok(AppProtocolExiDocument::SupportedAppProtocolRes(response))
        }
        _ => Err(ExiError::UnsupportedSubEvent),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_decode_app_protocol_req_1() {
        let vector = vec![
            128, 0, 219, 171, 147, 113, 211, 35, 75, 113, 209, 185, 129, 137, 145, 137, 209, 145,
            129, 137, 145, 210, 107, 155, 58, 35, 43, 48, 2, 0, 0, 4, 0, 64,
        ];

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        let decode_response = decode_exi_document(&mut exi_stream);

        let app_protocol_type = vec![AppHandAppProtocolType::new(
            "urn:din:70121:2012:MsgDef".to_owned(),
            2,
            0,
            1,
            1,
        )];

        let expected = AppProtocolExiDocument::SupportedAppProtocolReq(
            AppHandSupportedAppProtocolReq::new(app_protocol_type),
        );
        assert_eq!(decode_response, Ok(expected));
    }

    #[test]
    fn test_decode_app_protocol_req_2() {
        let vector = vec![
            128, 0, 219, 171, 147, 113, 211, 35, 75, 113, 209, 185, 129, 137, 145, 137, 209, 145,
            129, 137, 145, 210, 107, 155, 58, 35, 43, 48, 2, 0, 0, 4, 4, 1, 215, 87, 38, 227, 166,
            151, 54, 243, 163, 19, 83, 19, 19, 131, 163, 35, 163, 35, 3, 19, 51, 164, 215, 54, 116,
            70, 86, 96, 4, 0, 0, 0, 0, 128,
        ];

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        let decode_response = decode_exi_document(&mut exi_stream);

        let app_protocol_type = vec![
            AppHandAppProtocolType::new("urn:din:70121:2012:MsgDef".to_owned(), 2, 0, 1, 2),
            AppHandAppProtocolType::new("urn:iso:15118:2:2013:MsgDef".to_owned(), 2, 0, 0, 1),
        ];

        let expected = AppProtocolExiDocument::SupportedAppProtocolReq(
            AppHandSupportedAppProtocolReq::new(app_protocol_type),
        );
        assert_eq!(decode_response, Ok(expected));
    }

    #[test]
    fn test_app_protocol_res() {
        let mut vector = vec![0; 1024];
        // Exi: 80400000
        vector[0] = 0x80;
        vector[1] = 0x40;
        vector[2] = 0x00;
        vector[3] = 0x00;
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        let decode_response = decode_exi_document(&mut exi_stream);

        let expected = AppProtocolExiDocument::SupportedAppProtocolRes(
            AppHandSupportedAppProtocolRes::new(ResponseCode::OkSuccessfulNegotiation, Some(0)),
        );
        assert_eq!(decode_response, Ok(expected));
    }
}

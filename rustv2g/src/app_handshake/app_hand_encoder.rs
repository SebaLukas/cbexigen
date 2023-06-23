use crate::app_handshake::app_hand_datatypes::*;
use crate::common::exi_basetypes_encoder::{
    encoder_characters, encoder_nbit_uint, encoder_u16, encoder_u32,
};
use crate::common::exi_bitstream::ExiBitstream;
use crate::common::exi_error_codes::ExiError;
use crate::common::exi_header::exi_header_write;

fn encode_app_protocol_type(
    stream: &mut ExiBitstream,
    app_protocol_type: &AppHandAppProtocolType,
) -> Result<(), ExiError> {
    let mut grammar_id = 0;
    let mut done = false;

    while !done {
        match grammar_id {
            0 => {
                // Start(ProtocolNamespace)
                encoder_nbit_uint(stream, 1, 0)?;
                // Start(anyUri)
                encoder_nbit_uint(stream, 1, 0)?;
                // string should not be found in table, so add 2
                encoder_u16(stream, (app_protocol_type.namespace().len() + 2) as u16)?;
                // String
                encoder_characters(
                    stream,
                    app_protocol_type.namespace(),
                    APP_HAND_PROTOCOL_NAMESPACE_CHARACTER_SIZE as usize,
                )?;
                // EE
                encoder_nbit_uint(stream, 1, 0)?;
                grammar_id = 1;
            }
            1 => {
                // Start(VersionNumberMajor)
                encoder_nbit_uint(stream, 1, 0)?;
                // Start(uLong)
                encoder_nbit_uint(stream, 1, 0)?;
                encoder_u32(stream, app_protocol_type.version_number_major())?;
                // EE
                encoder_nbit_uint(stream, 1, 0)?;
                grammar_id = 2;
            }
            2 => {
                // Start(VersionNumberMinor)
                encoder_nbit_uint(stream, 1, 0)?;
                // Start(uLong)
                encoder_nbit_uint(stream, 1, 0)?;
                encoder_u32(stream, app_protocol_type.version_number_minor())?;
                // EE
                encoder_nbit_uint(stream, 1, 0)?;
                grammar_id = 3;
            }
            3 => {
                // Start(SchemaID)
                encoder_nbit_uint(stream, 1, 0)?;
                // Start(uBytes)
                encoder_nbit_uint(stream, 1, 0)?;
                encoder_nbit_uint(stream, 8, app_protocol_type.schema_id() as u32)?;
                // EE
                encoder_nbit_uint(stream, 1, 0)?;
                grammar_id = 4;
            }
            4 => {
                // Start(Priority)
                encoder_nbit_uint(stream, 1, 0)?;
                // Start(uBytes)
                encoder_nbit_uint(stream, 1, 0)?;
                encoder_nbit_uint(stream, 5, (app_protocol_type.priority() - 1) as u32)?;
                // EE
                encoder_nbit_uint(stream, 1, 0)?;
                grammar_id = 5;
            }
            5 => {
                // End Element
                encoder_nbit_uint(stream, 1, 0)?;
                done = true;
                grammar_id = 6;
            }
            _ => return Err(ExiError::UnknownGrammarId),
        }
    }
    Ok(())
}

fn encode_supported_app_protocol_req(
    stream: &mut ExiBitstream,
    request: AppHandSupportedAppProtocolReq,
) -> Result<(), ExiError> {
    let mut grammar_id = 7;
    let mut done = false;
    let mut index = 0;

    while !done {
        match grammar_id {
            7 => {
                if index < request.app_protocol().len() {
                    // Start(AppProtocol)
                    encoder_nbit_uint(stream, 1, 0)?;
                    // Start(AppProtocolType)
                    encode_app_protocol_type(stream, &request.app_protocol()[index])?;
                    index += 1;
                    grammar_id = 8;
                } else {
                    return Err(ExiError::UnknownEventCode);
                }
            }
            8..=11 => {
                if index < request.app_protocol().len() {
                    encoder_nbit_uint(stream, 2, 0)?;
                    // Start(AppProtocolType)
                    encode_app_protocol_type(stream, &request.app_protocol()[index])?;
                    index += 1;
                    if grammar_id == 11 {
                        grammar_id = 5;
                    } else {
                        grammar_id += 1;
                    }
                } else {
                    // EE
                    encoder_nbit_uint(stream, 2, 1)?;
                    done = true;
                }
            }
            5 => {
                // EE
                encoder_nbit_uint(stream, 1, 0)?;
                done = true;
            }
            _ => return Err(ExiError::UnknownGrammarId),
        }
    }

    Ok(())
}

fn encode_supported_app_protocol_res(
    stream: &mut ExiBitstream,
    response: AppHandSupportedAppProtocolRes,
) -> Result<(), ExiError> {
    let mut grammar_id = 12;
    let mut done = false;

    while !done {
        match grammar_id {
            12 => {
                // Start(ResponseCode)
                encoder_nbit_uint(stream, 1, 0)?;
                // Start(String)
                encoder_nbit_uint(stream, 1, 0)?;
                encoder_nbit_uint(stream, 2, response.response_code() as u32)?;
                // EE
                encoder_nbit_uint(stream, 1, 0)?;
                grammar_id = 13;
            }
            13 => {
                if response.schema_id().is_some() {
                    // Start(SchemaId)
                    encoder_nbit_uint(stream, 2, 0)?;
                    // Start(SchemaId, uByte)
                    encoder_nbit_uint(stream, 1, 0)?;
                    encoder_nbit_uint(stream, 8, response.schema_id().unwrap() as u32)?;
                    // EE
                    encoder_nbit_uint(stream, 1, 0)?;
                    grammar_id = 5;
                } else {
                    // EE
                    encoder_nbit_uint(stream, 2, 1)?;
                    done = true;
                }
            }
            5 => {
                // EE
                encoder_nbit_uint(stream, 1, 0)?;
                done = true;
            }
            _ => return Err(ExiError::UnknownGrammarId),
        }
    }
    Ok(())
}

pub fn encode_exi_document(
    stream: &mut ExiBitstream,
    exi_doc: AppProtocolExiDocument,
) -> Result<(), ExiError> {
    exi_header_write(stream)?;

    match exi_doc {
        AppProtocolExiDocument::SupportedAppProtocolReq(request) => {
            encoder_nbit_uint(stream, 2, 0)?;
            encode_supported_app_protocol_req(stream, request)?;
        }
        AppProtocolExiDocument::SupportedAppProtocolRes(response) => {
            encoder_nbit_uint(stream, 2, 1)?;
            encode_supported_app_protocol_res(stream, response)?;
        }
    }

    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_app_protocol_req() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        let app_protocol_type = vec![AppHandAppProtocolType::new(
            "urn:din:70121:2012:MsgDef".to_owned(),
            2,
            0,
            1,
            1,
        )];
        let request = AppHandSupportedAppProtocolReq::new(app_protocol_type);

        let exi_doc = AppProtocolExiDocument::SupportedAppProtocolReq(request);

        assert_eq!(encode_exi_document(&mut exi_stream, exi_doc).is_ok(), true);
        exi_stream.reset();

        // Exi: 8000dbab9371d3234b71d1b981899189d191818991d26b9b3a232b30020000040040
        let exi_bytes = vec![
            128, 0, 219, 171, 147, 113, 211, 35, 75, 113, 209, 185, 129, 137, 145, 137, 209, 145,
            129, 137, 145, 210, 107, 155, 58, 35, 43, 48, 2, 0, 0, 4, 0, 64,
        ];

        for exi in exi_bytes {
            assert_eq!(exi_stream.read_octet(), Ok(exi));
        }
    }

    #[test]
    fn test_app_protocol_req_2() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        let app_protocol_type = vec![
            AppHandAppProtocolType::new("urn:din:70121:2012:MsgDef".to_owned(), 2, 0, 1, 2),
            AppHandAppProtocolType::new("urn:iso:15118:2:2013:MsgDef".to_owned(), 2, 0, 0, 1),
        ];
        let request = AppHandSupportedAppProtocolReq::new(app_protocol_type);

        let exi_doc = AppProtocolExiDocument::SupportedAppProtocolReq(request);

        assert_eq!(encode_exi_document(&mut exi_stream, exi_doc).is_ok(), true);
        exi_stream.reset();

        // Exi: 8000dbab9371d3234b71d1b981899189d191818991d26b9b3a232b30020000040401d75726e3a69736f3a31353131383a323a323031333a4d73674465660040000000080
        let exi_bytes = vec![
            128, 0, 219, 171, 147, 113, 211, 35, 75, 113, 209, 185, 129, 137, 145, 137, 209, 145,
            129, 137, 145, 210, 107, 155, 58, 35, 43, 48, 2, 0, 0, 4, 4, 1, 215, 87, 38, 227, 166,
            151, 54, 243, 163, 19, 83, 19, 19, 131, 163, 35, 163, 35, 3, 19, 51, 164, 215, 54, 116,
            70, 86, 96, 4, 0, 0, 0, 0, 128,
        ];

        for exi in exi_bytes {
            assert_eq!(exi_stream.read_octet(), Ok(exi));
        }
    }

    #[test]
    fn test_app_protocol_res() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        let exi_doc = AppProtocolExiDocument::SupportedAppProtocolRes(
            AppHandSupportedAppProtocolRes::new(ResponseCode::OkSuccessfulNegotiation, Some(0)),
        );

        assert_eq!(encode_exi_document(&mut exi_stream, exi_doc).is_ok(), true);
        exi_stream.reset();

        // Exi: 80400000
        assert_eq!(exi_stream.read_octet(), Ok(0x80));
        assert_eq!(exi_stream.read_octet(), Ok(0x40));
        assert_eq!(exi_stream.read_octet(), Ok(0x00));
        assert_eq!(exi_stream.read_octet(), Ok(0x00));
    }
}

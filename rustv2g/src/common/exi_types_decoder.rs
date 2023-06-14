use crate::common::exi_basetypes_decoder::{
    decoder_bytes, decoder_i16, decoder_i32, decoder_i64, decoder_i8, decoder_nbit_uint,
    decoder_u16, decoder_u32, decoder_u64, decoder_u8,
};
use crate::common::exi_bitstream::ExiBitstream;
use crate::common::exi_error_codes::ExiError;

// ******************
// HexBinary
// ******************
pub fn decode_exi_type_hex_binary(
    stream: &mut ExiBitstream,
    value_len: &mut u16,
    value_buffer: &mut [u8],
    value_buffer_size: usize,
) -> Result<(), ExiError> {
    if decoder_nbit_uint(stream, 1)? == 0 {
        *value_len = decoder_u16(stream)?;
        decoder_bytes(stream, *value_len as usize, value_buffer, value_buffer_size)?;
    } else {
        return Err(ExiError::UnsupportedSubEvent);
    }

    if decoder_nbit_uint(stream, 1)? != 0 {
        Err(ExiError::DeviantsNotSupported)
    } else {
        Ok(())
    }
}

// ******************
// integers
// ******************
pub fn decode_exi_type_i8(stream: &mut ExiBitstream) -> Result<i8, ExiError> {
    let value;

    if decoder_nbit_uint(stream, 1)? == 0 {
        value = decoder_i8(stream)?;
    } else {
        return Err(ExiError::UnsupportedSubEvent);
    }

    if decoder_nbit_uint(stream, 1)? != 0 {
        Err(ExiError::DeviantsNotSupported)
    } else {
        Ok(value)
    }
}

pub fn decode_exi_type_i16(stream: &mut ExiBitstream) -> Result<i16, ExiError> {
    let value;

    if decoder_nbit_uint(stream, 1)? == 0 {
        value = decoder_i16(stream)?;
    } else {
        return Err(ExiError::UnsupportedSubEvent);
    }

    if decoder_nbit_uint(stream, 1)? != 0 {
        Err(ExiError::DeviantsNotSupported)
    } else {
        Ok(value)
    }
}

pub fn decode_exi_type_i32(stream: &mut ExiBitstream) -> Result<i32, ExiError> {
    let value;

    if decoder_nbit_uint(stream, 1)? == 0 {
        value = decoder_i32(stream)?;
    } else {
        return Err(ExiError::UnsupportedSubEvent);
    }

    if decoder_nbit_uint(stream, 1)? != 0 {
        Err(ExiError::DeviantsNotSupported)
    } else {
        Ok(value)
    }
}

pub fn decode_exi_type_i64(stream: &mut ExiBitstream) -> Result<i64, ExiError> {
    let value;

    if decoder_nbit_uint(stream, 1)? == 0 {
        value = decoder_i64(stream)?;
    } else {
        return Err(ExiError::UnsupportedSubEvent);
    }

    if decoder_nbit_uint(stream, 1)? != 0 {
        Err(ExiError::DeviantsNotSupported)
    } else {
        Ok(value)
    }
}

// ******************
// unsigned integers
// ******************
pub fn decode_exi_type_u8(stream: &mut ExiBitstream) -> Result<u8, ExiError> {
    let value;

    if decoder_nbit_uint(stream, 1)? == 0 {
        value = decoder_u8(stream)?;
    } else {
        return Err(ExiError::UnsupportedSubEvent);
    }

    if decoder_nbit_uint(stream, 1)? != 0 {
        Err(ExiError::DeviantsNotSupported)
    } else {
        Ok(value)
    }
}

pub fn decode_exi_type_u16(stream: &mut ExiBitstream) -> Result<u16, ExiError> {
    let value;

    if decoder_nbit_uint(stream, 1)? == 0 {
        value = decoder_u16(stream)?;
    } else {
        return Err(ExiError::UnsupportedSubEvent);
    }

    if decoder_nbit_uint(stream, 1)? != 0 {
        Err(ExiError::DeviantsNotSupported)
    } else {
        Ok(value)
    }
}

pub fn decode_exi_type_u32(stream: &mut ExiBitstream) -> Result<u32, ExiError> {
    let value;

    if decoder_nbit_uint(stream, 1)? == 0 {
        value = decoder_u32(stream)?;
    } else {
        return Err(ExiError::UnsupportedSubEvent);
    }

    if decoder_nbit_uint(stream, 1)? != 0 {
        Err(ExiError::DeviantsNotSupported)
    } else {
        Ok(value)
    }
}

pub fn decode_exi_type_u64(stream: &mut ExiBitstream) -> Result<u64, ExiError> {
    let value;

    if decoder_nbit_uint(stream, 1)? == 0 {
        value = decoder_u64(stream)?;
    } else {
        return Err(ExiError::UnsupportedSubEvent);
    }

    if decoder_nbit_uint(stream, 1)? != 0 {
        Err(ExiError::DeviantsNotSupported)
    } else {
        Ok(value)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    // #[test]
    // fn test_decode_exi_type_hex_binary() {
    //     let mut vector = vec![0; 1024];
    //     vector[0] = 0xAB;
    //     vector[1] = 0x05;

    //     let vector_len = vector.len();
    //     let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

    // }
}
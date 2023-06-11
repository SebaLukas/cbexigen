use crate::common::exi_basetypes::ExiUnsigned;
use crate::common::exi_bitstream::ExiBitstream;
use crate::common::exi_error_codes::ExiError;

use crate::common::exi_basetypes::{
    EXI_BASETYPES_MAX_OCTETS_SUPPORTED, EXI_BASETYPES_UINT16_MAX_OCTETS,
    EXI_BASETYPES_UINT32_MAX_OCTETS, EXI_BASETYPES_UINT8_MAX_OCTETS,
};

fn read_unsigned(stream: &mut ExiBitstream) -> Result<ExiUnsigned, ExiError> {
    const MSB: u8 = 128;
    let mut octets = [0; EXI_BASETYPES_MAX_OCTETS_SUPPORTED];
    let mut octets_count = 0;

    while octets_count < EXI_BASETYPES_MAX_OCTETS_SUPPORTED {
        let current_octet = stream.read_octet()?;
        octets[octets_count] = current_octet;
        octets_count += 1;
        if current_octet & MSB == 0 {
            return Ok(ExiUnsigned::new(octets, octets_count));
        }
    }
    Err(ExiError::SupportedMaxOctetsOverrun)
}

/*****************************************************************************
 * interface functions - bool
 *****************************************************************************/
pub fn decoder_bool(stream: &mut ExiBitstream) -> Result<bool, ExiError> {
    if stream.read_bits(1)? == 0 {
        Ok(false)
    } else {
        Ok(true)
    }
}

/*****************************************************************************
 * interface functions - bytes, binary
 *****************************************************************************/
pub fn decoder_bytes(
    stream: &mut ExiBitstream,
    bytes_len: usize,
    bytes: &mut [u8],
    bytes_size: usize,
) -> Result<(), ExiError> {
    if bytes_len > bytes_size {
        return Err(ExiError::ByteBufferTooSmall);
    }
    for n in 0..bytes_len {
        bytes[n] = stream.read_octet()?;
    }
    Ok(())
}

/*****************************************************************************
 * interface functions - unsigned integer
 *****************************************************************************/
pub fn decoder_nbit_uint(stream: &mut ExiBitstream, bit_count: usize) -> Result<u32, ExiError> {
    stream.read_bits(bit_count)
}

pub fn decoder_u8(stream: &mut ExiBitstream) -> Result<u8, ExiError> {
    let exi_unsigned = read_unsigned(stream)?;
    let value = exi_unsigned.convert32_from(EXI_BASETYPES_UINT8_MAX_OCTETS)?;
    Ok(value as u8)
}

pub fn decoder_u16(stream: &mut ExiBitstream) -> Result<u16, ExiError> {
    let exi_unsigned = read_unsigned(stream)?;
    let value = exi_unsigned.convert32_from(EXI_BASETYPES_UINT16_MAX_OCTETS)?;
    Ok(value as u16)
}

pub fn decoder_u32(stream: &mut ExiBitstream) -> Result<u32, ExiError> {
    let exi_unsigned = read_unsigned(stream)?;
    exi_unsigned.convert32_from(EXI_BASETYPES_UINT32_MAX_OCTETS)
}

pub fn decoder_u64(stream: &mut ExiBitstream) -> Result<u64, ExiError> {
    let exi_unsigned = read_unsigned(stream)?;
    exi_unsigned.convert64_from()
}

/*****************************************************************************
 * interface functions - integer
 *****************************************************************************/
pub fn decoder_i8(stream: &mut ExiBitstream) -> Result<i8, ExiError> {
    let sign = decoder_bool(stream)?;
    let value = decoder_u8(stream)?;
    if sign == true {
        Ok(-(value as i8))
    } else {
        Ok(value as i8)
    }
}

pub fn decoder_i16(stream: &mut ExiBitstream) -> Result<i16, ExiError> {
    let sign = decoder_bool(stream)?;
    let value = decoder_u16(stream)?;
    if sign == true {
        Ok(-(value as i16))
    } else {
        Ok(value as i16)
    }
}

pub fn decoder_i32(stream: &mut ExiBitstream) -> Result<i32, ExiError> {
    let sign = decoder_bool(stream)?;
    let value = decoder_u32(stream)?;
    if sign == true {
        Ok(-(value as i32))
    } else {
        Ok(value as i32)
    }
}

pub fn decoder_i64(stream: &mut ExiBitstream) -> Result<i64, ExiError> {
    let sign = decoder_bool(stream)?;
    let value = decoder_u64(stream)?;
    if sign == true {
        Ok(-(value as i64))
    } else {
        Ok(value as i64)
    }
}

/*****************************************************************************
 * interface functions - characters, string
 *****************************************************************************/
pub fn decoder_characters(
    stream: &mut ExiBitstream,
    characters_len: usize,
    characters_size: usize,
) -> Result<String, ExiError> {
    if characters_len + 1 > characters_size {
        return Err(ExiError::CharacterBufferTooSmall);
    }
    let mut string = String::new();
    for _ in 0..characters_len {
        let current_char = stream.read_octet()?;
        if !current_char.is_ascii() {
            return Err(ExiError::UnsupportedCharacterValue);
        }
        string.push(current_char as char);
    }

    Ok(string)
}

mod tests {
    use super::*;

    #[test]
    fn local_read_unsigned_u8() {
        let mut vector = vec![0; 1024];
        vector[0] = 0x6B;

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        let exi_unsigned = read_unsigned(&mut exi_stream).unwrap();
        assert_eq!(exi_unsigned.octets()[0], 0x6B);
    }

    #[test]
    fn local_read_unsigned_u16() {
        let mut vector = vec![0; 1024];
        vector[0] = 0xAB;
        vector[1] = 0x05;

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        let exi_unsigned = read_unsigned(&mut exi_stream).unwrap();
        assert_eq!(exi_unsigned.octets()[0], 0xAB);
        assert_eq!(exi_unsigned.octets()[1], 0x05);
    }

    #[test]
    fn test_decoder_bool() {
        let mut vector = vec![0; 1024];
        vector[0] = 0x80;

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        assert_eq!(decoder_bool(&mut exi_stream), Ok(true));
    }

    #[test]
    fn test_decoder_bytes() {
        let mut vector = vec![0; 1024];
        vector[0] = 0x80;
        vector[1] = 0x56;
        vector[2] = 0x5f;
        vector[3] = 0xfa;

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        let mut vector = vec![0; 4];
        assert_eq!(decoder_bytes(&mut exi_stream, 4, &mut vector, 5), Ok(()));
        assert_eq!(vector, vec![0x80, 0x56, 0x5f, 0xfa]);
    }

    #[test]
    fn test_decoder_u8() {
        let mut vector = vec![0; 1024];
        vector[0] = 0xAB;
        vector[1] = 0x01;

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        assert_eq!(decoder_u8(&mut exi_stream), Ok(0xAB));
    }

    #[test]
    fn test_decoder_u16() {
        let mut vector = vec![0; 1024];
        vector[0] = 0xAB;
        vector[1] = 0x05;

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        assert_eq!(decoder_u16(&mut exi_stream), Ok(0x2AB));
    }

    #[test]
    fn test_decoder_u32() {
        let mut vector = vec![0; 1024];
        vector[0] = 0xAB;
        vector[1] = 0x05;

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        assert_eq!(decoder_u32(&mut exi_stream), Ok(0x2AB));
    }

    #[test]
    fn test_decoder_u64() {
        let mut vector = vec![0; 1024];
        vector[0] = 0xAB;
        vector[1] = 0x05;

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        assert_eq!(decoder_u64(&mut exi_stream), Ok(0x2AB));
    }

    #[test]
    fn test_decoder_i8_positive() {
        let mut vector = vec![0; 1024];
        vector[0] = 0x15;
        vector[1] = 0x80;

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        assert_eq!(decoder_i8(&mut exi_stream), Ok(0x2B));
    }

    #[test]
    fn test_decoder_i8_negative() {
        let mut vector = vec![0; 1024];
        vector[0] = 0x95;
        vector[1] = 0x80;

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        assert_eq!(decoder_i8(&mut exi_stream), Ok(-43));
    }

    #[test]
    fn test_decoder_i16_positive() {
        let mut vector = vec![0; 1024];
        vector[0] = 0b01010101;
        vector[1] = 0b10000010;
        vector[2] = 0b10000000;

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        assert_eq!(decoder_i16(&mut exi_stream), Ok(683));
    }

    #[test]
    fn test_decoder_i16_negative() {
        let mut vector = vec![0; 1024];
        vector[0] = 0b11010101;
        vector[1] = 0b10000010;
        vector[2] = 0b10000000;

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        assert_eq!(decoder_i16(&mut exi_stream), Ok(-683));
    }

    #[test]
    fn test_decoder_i32_positive() {
        let mut vector = vec![0; 1024];
        vector[0] = 0b01010101;
        vector[1] = 0b10000010;
        vector[2] = 0b10000000;

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        assert_eq!(decoder_i32(&mut exi_stream), Ok(683));
    }

    #[test]
    fn test_decoder_i32_negative() {
        let mut vector = vec![0; 1024];
        vector[0] = 0b11010101;
        vector[1] = 0b10000010;
        vector[2] = 0b10000000;

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        assert_eq!(decoder_i32(&mut exi_stream), Ok(-683));
    }

    #[test]
    fn test_decoder_i64_positive() {
        let mut vector = vec![0; 1024];
        vector[0] = 0b01010101;
        vector[1] = 0b10000010;
        vector[2] = 0b10000000;

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        assert_eq!(decoder_i64(&mut exi_stream), Ok(683));
    }

    #[test]
    fn test_decoder_i64_negative() {
        let mut vector = vec![0; 1024];
        vector[0] = 0b11010101;
        vector[1] = 0b10000010;
        vector[2] = 0b10000000;

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        assert_eq!(decoder_i64(&mut exi_stream), Ok(-683));
    }

    #[test]
    fn test_decoder_characters() {
        let mut vector = vec![0; 1024];
        let string = String::from("Hello");
        let mut index = 0;
        for &n in string.as_bytes() {
            vector[index] = n;
            index += 1;
        }

        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        assert_eq!(decoder_characters(&mut exi_stream, 5, 10), Ok(string));
    }
}

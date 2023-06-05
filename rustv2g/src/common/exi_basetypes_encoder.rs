use crate::common::exi_error_codes::ExiError;
use crate::common::exi_bitstream::ExiBitstream;
use crate::common::exi_basetypes::ExiUnsigned;

use crate::common::exi_basetypes::{
    EXI_BASETYPES_MAX_OCTETS_SUPPORTED,
    EXI_BASETYPES_UINT8_MAX_OCTETS,
    EXI_BASETYPES_UINT16_MAX_OCTETS,
    EXI_BASETYPES_UINT32_MAX_OCTETS,
};

fn write_unsigned(stream: &mut ExiBitstream, exi_unsigned: &ExiUnsigned) -> Result<(), ExiError> {

    for n in 0..*exi_unsigned.octets_count() {
        stream.write_octet(exi_unsigned.octets()[n])?;
    }
    Ok(())
}

/*****************************************************************************
 * interface functions - bool
 *****************************************************************************/
pub fn encoder_bool(stream: &mut ExiBitstream, value: bool) -> Result<(), ExiError> {
    stream.write_bits(1, value as u32)
}

/*****************************************************************************
 * interface functions - bytes, binary
 *****************************************************************************/
pub fn encoder_bytes(stream: &mut ExiBitstream, bytes_len: usize, bytes: &[u8], bytes_size: usize) -> Result<(), ExiError> {

    if bytes_len > bytes_size {
        return Err(ExiError::ByteBufferTooSmall)
    }

    for n in 0..bytes_len {
        stream.write_octet(bytes[n])?;
    }
    Ok(())
}

/*****************************************************************************
 * interface functions - unsigned integer
 *****************************************************************************/
pub fn encoder_nbit_uint(stream: &mut ExiBitstream, bit_count: usize, value: u32) -> Result<(), ExiError> {
    stream.write_bits(bit_count, value)
}

pub fn encoder_u8(stream: &mut ExiBitstream, value: u8) -> Result<(), ExiError> {

    let mut exi_unsigned = ExiUnsigned::new([0; EXI_BASETYPES_MAX_OCTETS_SUPPORTED], 0);
    exi_unsigned.convert32_to(value as u32, EXI_BASETYPES_UINT8_MAX_OCTETS)?;

    write_unsigned(stream, &mut exi_unsigned)
}

pub fn encoder_u16(stream: &mut ExiBitstream, value: u16) -> Result<(), ExiError> {

    let mut exi_unsigned = ExiUnsigned::new([0; EXI_BASETYPES_MAX_OCTETS_SUPPORTED], 0);
    exi_unsigned.convert32_to(value as u32, EXI_BASETYPES_UINT16_MAX_OCTETS)?;

    write_unsigned(stream, &mut exi_unsigned)
}

pub fn encoder_u32(stream: &mut ExiBitstream, value: u32) -> Result<(), ExiError> {

    let mut exi_unsigned = ExiUnsigned::new([0; EXI_BASETYPES_MAX_OCTETS_SUPPORTED], 0);
    exi_unsigned.convert32_to(value, EXI_BASETYPES_UINT32_MAX_OCTETS)?;

    write_unsigned(stream, &mut exi_unsigned)
}

pub fn encoder_u64(stream: &mut ExiBitstream, value: u64) -> Result<(), ExiError> {

    let mut exi_unsigned = ExiUnsigned::new([0; EXI_BASETYPES_MAX_OCTETS_SUPPORTED], 0);
    exi_unsigned.convert64_to(value)?;

    write_unsigned(stream, &mut exi_unsigned)
}

mod tests {
    use super::*;
    use crate::common::exi_basetypes::{
        EXI_BASETYPES_MAX_OCTETS_SUPPORTED,
        EXI_BASETYPES_UINT16_MAX_OCTETS
    };

    #[test]
    fn local_write_unsigned() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        let mut exi_unsigned = ExiUnsigned::new([0; EXI_BASETYPES_MAX_OCTETS_SUPPORTED], 0);

        assert_eq!(exi_unsigned.convert32_to(0x5678, EXI_BASETYPES_UINT16_MAX_OCTETS).is_ok(), true);
        assert_eq!(write_unsigned(&mut exi_stream, &exi_unsigned).is_ok(), true);

        exi_stream.reset();

        assert_eq!(exi_stream.read_octet(), Ok(0b11111000));
        assert_eq!(exi_stream.read_octet(), Ok(0b10101100));
        assert_eq!(exi_stream.read_octet(), Ok(0b00000001));
    }

    #[test]
    fn test_encoder_bool() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        
        assert_eq!(encoder_bool(&mut exi_stream, true).is_ok(), true);
        exi_stream.reset();
        let value = exi_stream.read_bits(1).unwrap();
        assert_eq!(true, value != 0);
    }

    #[test]
    fn test_encoder_bytes() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        
        let bytes = vec![1,2,3,4,5];
        assert_eq!(encoder_bytes(&mut exi_stream, bytes.len(), &bytes, 5).is_ok(), true);
        
        exi_stream.reset();

        let mut expected = Vec::new();
        for _ in 0..5 {
            expected.push(exi_stream.read_octet().unwrap())
        }
        assert_eq!(expected, bytes);
    }

    #[test]
    fn test_encoder_u8() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        
        assert_eq!(encoder_u8(&mut exi_stream, 0x56).is_ok(), true);

        exi_stream.reset();
        assert_eq!(exi_stream.read_octet(), Ok(0x56));
    }

    #[test]
    fn test_encoder_u16() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        
        assert_eq!(encoder_u16(&mut exi_stream, 0x5678).is_ok(), true);

        exi_stream.reset();
        assert_eq!(exi_stream.read_octet(), Ok(0b11111000));
        assert_eq!(exi_stream.read_octet(), Ok(0b10101100));
        assert_eq!(exi_stream.read_octet(), Ok(0b00000001));
    }

    #[test]
    fn test_encoder_u32() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        
        assert_eq!(encoder_u32(&mut exi_stream, 0x5678).is_ok(), true);

        exi_stream.reset();
        assert_eq!(exi_stream.read_octet(), Ok(0b11111000));
        assert_eq!(exi_stream.read_octet(), Ok(0b10101100));
        assert_eq!(exi_stream.read_octet(), Ok(0b00000001));
    }

    #[test]
    fn test_encoder_u64() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        
        assert_eq!(encoder_u64(&mut exi_stream, 0x5678).is_ok(), true);

        exi_stream.reset();
        assert_eq!(exi_stream.read_octet(), Ok(0b11111000));
        assert_eq!(exi_stream.read_octet(), Ok(0b10101100));
        assert_eq!(exi_stream.read_octet(), Ok(0b00000001));
    }

}

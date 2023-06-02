use crate::common::exi_error_codes::ExiError;
use crate::common::exi_bitstream::ExiBitstream;
use crate::common::exi_basetypes::ExiUnsigned;

fn write_unsigned(stream: &mut ExiBitstream, exi_unsigned: &ExiUnsigned) -> ExiError{

    for n in 0..*exi_unsigned.octets_count() {
        let error = stream.write_octet(exi_unsigned.octets()[n]);
        if error != ExiError::NoError {
            return error;
        }
    }
    ExiError::NoError
}

/*****************************************************************************
 * interface functions - bool
 *****************************************************************************/
pub fn encoder_bool(stream: &mut ExiBitstream, value: bool) -> ExiError{
    stream.write_bits(1, value as u32)
}

/*****************************************************************************
 * interface functions - bytes, binary
 *****************************************************************************/
pub fn encoder_bytes(stream: &mut ExiBitstream, bytes_len: usize, bytes: &[u8], bytes_size: usize) -> ExiError {

    if bytes_len > bytes_size {
        return ExiError::ByteBufferTooSmall;
    }

    for n in 0..bytes_len {
        let error = stream.write_octet(bytes[n]);
        if error != ExiError::NoError {
            return error;
        }
    }
    ExiError::NoError
}



mod tests {
    use super::{*};
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

        let mut error = exi_unsigned.convert32_to(0x5678, EXI_BASETYPES_UINT16_MAX_OCTETS);
        assert_eq!(error, ExiError::NoError);
        error = write_unsigned(&mut exi_stream, &exi_unsigned);
        assert_eq!(error, ExiError::NoError);

        exi_stream.reset();

        let mut value = 0;
        error = exi_stream.read_octet(&mut value);
        assert_eq!(error, ExiError::NoError);
        assert_eq!(value, 0b11111000);
        error = exi_stream.read_octet(&mut value);
        assert_eq!(error, ExiError::NoError);
        assert_eq!(value, 0b10101100);
        error = exi_stream.read_octet(&mut value);
        assert_eq!(error, ExiError::NoError);
        assert_eq!(value, 0b00000001);
    }

    #[test]
    fn test_encoder_bool() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);
        
        let error = encoder_bool(&mut exi_stream, true);
        assert_eq!(error, ExiError::NoError);
        exi_stream.reset();
        let mut value = 0;
        exi_stream.read_bits(1, &mut value);
        assert_eq!(true, value != 0);
    }

    #[test]
    fn test_encoder_bytes() {
        
    }

}

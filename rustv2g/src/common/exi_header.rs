use crate::common::exi_error_codes::ExiError;
use crate::common::exi_bitstream::ExiBitstream;

const EXI_SIMPLE_HEADER_BIT_SIZE: usize = 8;
const EXI_SIMPLE_HEADER_VALUE: u32 = 0x80;

pub fn exi_header_write(stream: &mut ExiBitstream) -> Result<(), ExiError> {
    stream.write_bits(EXI_SIMPLE_HEADER_BIT_SIZE, EXI_SIMPLE_HEADER_VALUE)
}

pub fn exi_header_read(stream: &mut ExiBitstream) -> Result<u32, ExiError> {
    stream.read_bits(EXI_SIMPLE_HEADER_BIT_SIZE)
}

pub fn exi_header_read_and_check(stream: &mut ExiBitstream) -> Result<(), ExiError>  {

    let header = exi_header_read(stream)?;

    if header == '$' as u32 {
        Err(ExiError::HeaderCookieNotSupported)
    } else if (header & 0x20) == 1 {
        Err(ExiError::HeaderOptionsNotSupported)
    } else {
        Ok(())
    }
}

mod tests {
    use super::*;

    #[test]
    fn header_write() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        assert_eq!(exi_header_write(&mut exi_stream).is_ok(), true);

        exi_stream.reset();

        assert_eq!(exi_stream.read_octet(), Ok(EXI_SIMPLE_HEADER_VALUE as u8));
    }
    #[test]
    fn header_read() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        assert_eq!(exi_stream.write_bits(EXI_SIMPLE_HEADER_BIT_SIZE, EXI_SIMPLE_HEADER_VALUE).is_ok(), true);

        exi_stream.reset();

        let value = exi_header_read(&mut exi_stream);
        assert_eq!(value, Ok(EXI_SIMPLE_HEADER_VALUE));
    }
    #[test]
    fn header_read_check() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        assert_eq!(exi_stream.write_bits(EXI_SIMPLE_HEADER_BIT_SIZE, EXI_SIMPLE_HEADER_VALUE).is_ok(), true);

        exi_stream.reset();

        assert_eq!(exi_header_read_and_check(&mut exi_stream).is_ok(), true);
    }

}
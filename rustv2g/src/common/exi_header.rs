use crate::common::exi_error_codes::ExiError;
use crate::common::exi_bitstream::ExiBitstream;

const EXI_SIMPLE_HEADER_BIT_SIZE: usize = 8;
const EXI_SIMPLE_HEADER_VALUE: u32 = 0x80;

pub fn exi_header_write(stream: &mut ExiBitstream) -> ExiError {
    stream.write_bits(EXI_SIMPLE_HEADER_BIT_SIZE, EXI_SIMPLE_HEADER_VALUE)
}

pub fn exi_header_read(stream: &mut ExiBitstream, header: &mut u32) -> ExiError {
    stream.read_bits(EXI_SIMPLE_HEADER_BIT_SIZE, header)
}

pub fn exi_header_read_and_check(stream: &mut ExiBitstream) -> ExiError {

    let mut header: u32 = 0;
    let error = exi_header_read(stream, &mut header);
    if error != ExiError::NoError {
        return error;
    }

    if header == '$' as u32 {
        ExiError::HeaderCookieNotSupported
    } else if (header & 0x20) == 1 {
        ExiError::HeaderOptionsNotSupported
    } else {
        ExiError::NoError
    }
}

mod tests {
    use super::*;

    #[test]
    fn header_write() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        let error = exi_header_write(&mut exi_stream);
        assert_eq!(error, ExiError::NoError);

        exi_stream.reset();

        let mut value: u8 = 0;
        exi_stream.read_octet(&mut value);

        assert_eq!(value, EXI_SIMPLE_HEADER_VALUE as u8);
    }
    #[test]
    fn header_read() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        let mut error = exi_stream.write_bits(EXI_SIMPLE_HEADER_BIT_SIZE, EXI_SIMPLE_HEADER_VALUE);
        assert_eq!(error, ExiError::NoError);

        exi_stream.reset();

        let mut value: u32 = 0;
        error = exi_header_read(&mut exi_stream, &mut value);

        assert_eq!(error, ExiError::NoError);
        assert_eq!(value, EXI_SIMPLE_HEADER_VALUE);
    }
    #[test]
    fn header_read_check() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        let mut error = exi_stream.write_bits(EXI_SIMPLE_HEADER_BIT_SIZE, EXI_SIMPLE_HEADER_VALUE);
        assert_eq!(error, ExiError::NoError);

        exi_stream.reset();

        error = exi_header_read_and_check(&mut exi_stream);

        assert_eq!(error, ExiError::NoError);
    }

}
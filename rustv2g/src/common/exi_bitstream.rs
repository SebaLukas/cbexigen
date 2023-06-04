use crate::common::exi_error_codes::ExiError;

const EXI_BITSTREAM_MAX_BIT_COUNT: u8 = 8;

#[derive(Debug, PartialEq)]
pub struct ExiBitstream {
    /* byte array size and data */
    data: Vec<u8>,
    data_size: usize,

    /* byte array current byte and bit position in array */
    bit_count: u8,
    byte_pos: usize,

    /* flags for reset and length function */
    _new_called: bool,
    _flag_byte_pos: usize,
}

impl ExiBitstream {

    pub fn new(data: Vec<u8>, data_size: usize, data_offset: usize) -> Self {
        Self {data, data_size, bit_count: 0,
            byte_pos: data_offset,
            _new_called: true,
            _flag_byte_pos: data_offset
        }
    }

    pub fn reset(&mut self) {
        if self._new_called {
            self.byte_pos = self._flag_byte_pos;
        } else {
            self.byte_pos = 0;
        }
        self.bit_count = 0;
    }

    pub fn get_length(&self) -> usize {
        let mut length: usize = self.byte_pos;

        if self._new_called == true && (self._flag_byte_pos > 0) {
            length -= self._flag_byte_pos;
        }

        if self.bit_count > 0 {
            length += 1;
        }

        return length;
    }

    fn has_overflow(&mut self) -> Result<(), ExiError> {

        if self.bit_count == EXI_BITSTREAM_MAX_BIT_COUNT {
            
            if self.byte_pos < self.data_size {
                self.byte_pos += 1;
                self.bit_count = 0;
            } else {
                return Err(ExiError::BitstreamOverflow);
            }
        }
        Ok(())
    }

    fn write_bit(&mut self, bit: bool) -> Result<(), ExiError> {

        self.has_overflow()?;

        let current_byte = self.data.get_mut(self.byte_pos);

        match current_byte {
            None => return Err(ExiError::BitstreamOverflow),
            Some(byte) => {
                if self.bit_count == 0 {
                    *byte = 0;
                }
                if bit {
                    *byte = *byte | (1 << (EXI_BITSTREAM_MAX_BIT_COUNT - (self.bit_count + 1)));
                }
                self.bit_count +=1;
            },
        }
        Ok(())
    }

    fn read_bit(&mut self) -> Result<bool, ExiError> {

        self.has_overflow()?;

        let current_bit = (self.data[self.byte_pos]) >> (EXI_BITSTREAM_MAX_BIT_COUNT - (self.bit_count + 1));

        self.bit_count += 1;

        if current_bit & 1 == 0 {
            return Ok(false);
        } else {
            return Ok(true);
        }
    }

    pub fn write_bits(&mut self, bit_count: usize, value: u32) -> Result<(), ExiError> {

        if bit_count > 32 {
            return  Err(ExiError::BitCountLargerThanTypeSize);
        }

        for n in 0..bit_count {
            let bit = (value & (1 << (bit_count - n - 1))) > 0;
            self.write_bit(bit)?;
        }
        Ok(())
    }

    pub fn write_octet(&mut self, value: u8) -> Result<(), ExiError> {
        self.write_bits(8, value as u32)
    }

    pub fn read_bits(&mut self, bit_count: usize) -> Result<u32, ExiError> {

        let mut value: u32 = 0;

        if bit_count > 32 {
            return Err(ExiError::BitCountLargerThanTypeSize);
        }

        for _ in 0..bit_count {
            let bit = self.read_bit()?;

            value = (value << 1) | bit as u32;
        }

        Ok(value)
    }

    pub fn read_octet(&mut self) -> Result<u8, ExiError> {

        let mut value = 0;
        for _ in 0..8 {
            let bit = self.read_bit()?;
            value = (value << 1) | bit as u8;
        }

        Ok(value)
    }

}



#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn create_bitstream() {
        let vector = vec![0;2048];
        let vector_len = vector.len();

        let exi_stream = ExiBitstream::new(vector, vector_len, 0);

        let expected = ExiBitstream {
            data: vec![0;2048],
            data_size: 2048,
            bit_count: 0,
            byte_pos: 0,
            _new_called: true,
            _flag_byte_pos: 0
        };
        assert_eq!(exi_stream, expected);
    }
    #[test]
    fn internal_has_overflow_good_case() {
        let mut existream = ExiBitstream {
            data: vec![0;3],
            data_size: 3,
            bit_count: 8,
            byte_pos: 0,
            _new_called: false,
            _flag_byte_pos: 0
        };

        let error = existream.has_overflow();

        assert_eq!(existream.bit_count, 0);
        assert_eq!(existream.byte_pos, 1);
        assert_eq!(error.is_ok(), true);
    }
    #[test]
    fn internal_has_overflow_bad_case() {
        let mut existream = ExiBitstream {
            data: vec![0;3],
            data_size: 3,
            bit_count: 8,
            byte_pos: 4,
            _new_called: false,
            _flag_byte_pos: 0
        };
        assert_eq!(existream.has_overflow(), Err(ExiError::BitstreamOverflow));
    }
    #[test]
    fn internal_write_bit() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        let error = exi_stream.write_bit(true);
        assert_eq!(error.is_ok(), true);
        let error = exi_stream.write_bit(true);
        assert_eq!(error.is_ok(), true);
        let error = exi_stream.write_bit(false);
        assert_eq!(error.is_ok(), true);
        let error = exi_stream.write_bit(true);
        assert_eq!(error.is_ok(), true);
        assert_eq!(0xD0, exi_stream.data[0]);
    }
    #[test]
    fn write_bits() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        let error = exi_stream.write_bits(4, 10);
        assert_eq!(error.is_ok(), true);
        assert_eq!(160, exi_stream.data[0]);

        let error = exi_stream.write_bits(4, 10);
        assert_eq!(error.is_ok(), true);
        assert_eq!(0xAA, exi_stream.data[0]);
    }
    #[test]
    fn write_bits_bit_count_error(){
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        let error = exi_stream.write_bits(64, 10);
        assert_eq!(error, Err(ExiError::BitCountLargerThanTypeSize));
    }
    #[test]
    fn reset() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let data_offset = 0;
        let mut exi_stream = ExiBitstream::new(vector, vector_len, data_offset);

        let error = exi_stream.write_bits(16, 0xFFFF);
        assert_eq!(error.is_ok(), true);
        assert_eq!(0xFF, exi_stream.data[0]);
        assert_eq!(0xFF, exi_stream.data[1]);
        assert_eq!(exi_stream.byte_pos, 1);

        exi_stream.reset();

        assert_eq!(exi_stream.byte_pos, data_offset);
        assert_eq!(exi_stream.bit_count, 0);

    }
    #[test]
    fn get_length() {
        let vector = vec![0; 1024];
        let vector_len = vector.len();
        let data_offset = 0;
        let mut exi_stream = ExiBitstream::new(vector, vector_len, data_offset);

        let error = exi_stream.write_bits(12, 0xFFF);
        assert_eq!(error.is_ok(), true);
        assert_eq!(exi_stream.get_length(), 2);
    }
    #[test]
    fn internal_read_bit() {
        let mut vector = vec![0; 1024];
        vector[0] = 0xF0;
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        assert_eq!(exi_stream.read_bit(), Ok(true));
        assert_eq!(exi_stream.read_bit(), Ok(true));
    }
    #[test]
    fn read_bits() {
        let mut vector = vec![0; 1024];
        vector[0] = 0xAA;
        let vector_len = vector.len();
        let mut exi_stream = ExiBitstream::new(vector, vector_len, 0);

        assert_eq!(exi_stream.read_bits(8), Ok(0xAA));
    }


}

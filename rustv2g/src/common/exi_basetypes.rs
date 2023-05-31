use crate::common::exi_error_codes::ExiError;

const EXI_BASETYPES_MAX_OCTETS_SUPPORTED: usize = 10;

const EXI_BASETYPES_OCTET_SEQ_FLAG_MASK: u32 = 0x80;
const EXI_BASETYPES_OCTET_SEQ_VALUE_MASK: u32= 0x7F;

const EXI_BASETYPES_UINT8_MAX_OCTETS: usize = 2;
const EXI_BASETYPES_UINT16_MAX_OCTETS: usize = 3;
const EXI_BASETYPES_UINT32_MAX_OCTETS: usize = 5;
const EXI_BASETYPES_UINT64_MAX_OCTETS: usize = 10;

#[derive(Debug, PartialEq)]
pub struct ExiUnsigned {
    octets: [u8; EXI_BASETYPES_MAX_OCTETS_SUPPORTED],
    octets_count: usize,
}

impl ExiUnsigned {
    
    pub fn convert32_to(&mut self, value: u32, max_octets: usize) -> ExiError {

        self.octets_count = 0;
        let mut dummy = value;

        for n in 0..EXI_BASETYPES_UINT32_MAX_OCTETS {
            self.octets_count += 1;
            self.octets[n] = (dummy & EXI_BASETYPES_OCTET_SEQ_VALUE_MASK) as u8;
            dummy = dummy >> 7;
            if dummy == 0 {
                break;
            }
            self.octets[n] |= EXI_BASETYPES_OCTET_SEQ_FLAG_MASK as u8;
        }

        if self.octets_count <= max_octets {
            ExiError::NoError
        } else {
            ExiError::OctetCountLargerThanTypeSupports
        }
    }

    pub fn convert64_to(&mut self, value: u64) -> ExiError {

        self.octets_count = 0;
        let mut dummy = value;

        for n in 0..EXI_BASETYPES_UINT64_MAX_OCTETS {
            self.octets_count += 1;
            self.octets[n] = (dummy & EXI_BASETYPES_OCTET_SEQ_VALUE_MASK as u64) as u8;
            dummy = dummy >> 7;
            if dummy == 0 {
                break;
            }
            self.octets[n] |= EXI_BASETYPES_OCTET_SEQ_FLAG_MASK as u8;
        }

        if self.octets_count <= EXI_BASETYPES_UINT64_MAX_OCTETS {
            ExiError::NoError
        } else {
            ExiError::OctetCountLargerThanTypeSupports
        }
    }

    pub fn convert32_from(&self, value: &mut u32, max_octets: usize) -> ExiError {

        if self.octets_count > max_octets {
            return ExiError::OctetCountLargerThanTypeSupports;
        }
        *value = 0;

        for n in 0..self.octets_count {
            *value |= (self.octets[n] as u32 & EXI_BASETYPES_OCTET_SEQ_VALUE_MASK) << (n * 7);
        }
        ExiError::NoError
    }

    pub fn convert64_from(&self, value: &mut u64) -> ExiError {

        if self.octets_count > EXI_BASETYPES_UINT64_MAX_OCTETS {
            return ExiError::OctetCountLargerThanTypeSupports;
        }
        *value = 0;

        for n in 0..self.octets_count {
            *value |= ((self.octets[n] as u32 & EXI_BASETYPES_OCTET_SEQ_VALUE_MASK) << (n * 7)) as u64;
        }

        ExiError::NoError
    }

}

mod tests {
    use super::*;

    #[test]
    fn u8_convert32_to() {
        let mut exi_unsigned = ExiUnsigned {
            octets: [0; EXI_BASETYPES_MAX_OCTETS_SUPPORTED],
            octets_count: 0,
        };

        let error = exi_unsigned.convert32_to(0x02, EXI_BASETYPES_UINT8_MAX_OCTETS);
        assert_eq!(error, ExiError::NoError);
        assert_eq!(exi_unsigned.octets_count, 1);
        assert_eq!(exi_unsigned.octets[0], 0x02);
    }

    #[test]
    fn u16_convert32_to() {
        let mut exi_unsigned = ExiUnsigned {
            octets: [0; EXI_BASETYPES_MAX_OCTETS_SUPPORTED],
            octets_count: 0,
        };

        let error = exi_unsigned.convert32_to(0x5678, EXI_BASETYPES_UINT16_MAX_OCTETS);
        assert_eq!(error, ExiError::NoError);
        assert_eq!(exi_unsigned.octets_count, 3);
        assert_eq!(exi_unsigned.octets[0], 0b11111000);
        assert_eq!(exi_unsigned.octets[1], 0b10101100);
        assert_eq!(exi_unsigned.octets[2], 0b00000001);
    }

    #[test]
    fn u32_convert32_to() {
        let mut exi_unsigned = ExiUnsigned {
            octets: [0; EXI_BASETYPES_MAX_OCTETS_SUPPORTED],
            octets_count: 0,
        };

        let error = exi_unsigned.convert32_to(0x105678, EXI_BASETYPES_UINT32_MAX_OCTETS);
        assert_eq!(error, ExiError::NoError);
        assert_eq!(exi_unsigned.octets_count, 3);
        assert_eq!(exi_unsigned.octets[0], 0b11111000);
        assert_eq!(exi_unsigned.octets[1], 0b10101100);
        assert_eq!(exi_unsigned.octets[2], 0b01000001);
    }

    #[test]
    fn convert64_to() {
        let mut exi_unsigned = ExiUnsigned {
            octets: [0; EXI_BASETYPES_MAX_OCTETS_SUPPORTED],
            octets_count: 0,
        };

        let error = exi_unsigned.convert64_to(0x105678);
        assert_eq!(error, ExiError::NoError);
        assert_eq!(exi_unsigned.octets_count, 3);
        assert_eq!(exi_unsigned.octets[0], 0b11111000);
        assert_eq!(exi_unsigned.octets[1], 0b10101100);
        assert_eq!(exi_unsigned.octets[2], 0b01000001);
    }

    #[test]
    fn convert32_from() {
        let mut exi_unsigned = ExiUnsigned {
            octets: [0; EXI_BASETYPES_MAX_OCTETS_SUPPORTED],
            octets_count: 0,
        };

        let expected = 0x5678;

        let mut error = exi_unsigned.convert32_to(expected, EXI_BASETYPES_UINT16_MAX_OCTETS);
        assert_eq!(error, ExiError::NoError);

        let mut value = 0;

        error = exi_unsigned.convert32_from(&mut value, EXI_BASETYPES_UINT16_MAX_OCTETS);
        assert_eq!(error, ExiError::NoError);
        assert_eq!(value, expected);
    }

    #[test]
    fn convert64_from() {
        let mut exi_unsigned = ExiUnsigned {
            octets: [0; EXI_BASETYPES_MAX_OCTETS_SUPPORTED],
            octets_count: 0,
        };
        let expected = 0x105678;
        let mut error = exi_unsigned.convert64_to(expected);
        assert_eq!(error, ExiError::NoError);

        let mut value = 0;

        error = exi_unsigned.convert64_from(&mut value);
        assert_eq!(error, ExiError::NoError);
        assert_eq!(value, expected);
    }

}
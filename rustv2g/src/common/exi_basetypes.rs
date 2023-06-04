use crate::common::exi_error_codes::ExiError;

pub const EXI_BASETYPES_MAX_OCTETS_SUPPORTED: usize = 10;

pub const EXI_BASETYPES_OCTET_SEQ_FLAG_MASK: u32 = 0x80;
pub const EXI_BASETYPES_OCTET_SEQ_VALUE_MASK: u32= 0x7F;

pub const EXI_BASETYPES_UINT8_MAX_OCTETS: usize = 2;
pub const EXI_BASETYPES_UINT16_MAX_OCTETS: usize = 3;
pub const EXI_BASETYPES_UINT32_MAX_OCTETS: usize = 5;
pub const EXI_BASETYPES_UINT64_MAX_OCTETS: usize = 10;

#[derive(Debug, PartialEq)]
pub struct ExiUnsigned {
    octets: [u8; EXI_BASETYPES_MAX_OCTETS_SUPPORTED],
    octets_count: usize,
}

impl ExiUnsigned {

    pub fn new(octets: [u8; EXI_BASETYPES_MAX_OCTETS_SUPPORTED], octets_count: usize) -> Self {
        Self { octets, octets_count }
    }

    pub fn octets(&self) -> &[u8] {
        &self.octets
    }

    pub fn octets_count(&self) -> &usize {
        &self.octets_count
    }
    
    pub fn convert32_to(&mut self, value: u32, max_octets: usize) -> Result<(), ExiError> {

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
            Ok(())
        } else {
            Err(ExiError::OctetCountLargerThanTypeSupports)
        }
    }

    pub fn convert64_to(&mut self, value: u64) -> Result<(), ExiError> {

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
            Ok(())
        } else {
            Err(ExiError::OctetCountLargerThanTypeSupports)
        }
    }

    pub fn convert32_from(&self, max_octets: usize) -> Result<u32, ExiError> {

        if self.octets_count > max_octets {
            return Err(ExiError::OctetCountLargerThanTypeSupports);
        }
        let mut value = 0;

        for n in 0..self.octets_count {
            value |= (self.octets[n] as u32 & EXI_BASETYPES_OCTET_SEQ_VALUE_MASK) << (n * 7);
        }
        Ok(value)
    }

    pub fn convert64_from(&self) -> Result<u64, ExiError> {

        if self.octets_count > EXI_BASETYPES_UINT64_MAX_OCTETS {
            return Err(ExiError::OctetCountLargerThanTypeSupports);
        }
        let mut value = 0;

        for n in 0..self.octets_count {
            value |= ((self.octets[n] as u32 & EXI_BASETYPES_OCTET_SEQ_VALUE_MASK) << (n * 7)) as u64;
        }
        Ok(value)
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

        assert_eq!(exi_unsigned.convert32_to(0x02, EXI_BASETYPES_UINT8_MAX_OCTETS).is_ok(), true);
        assert_eq!(exi_unsigned.octets_count, 1);
        assert_eq!(exi_unsigned.octets[0], 0x02);
    }

    #[test]
    fn u16_convert32_to() {
        let mut exi_unsigned = ExiUnsigned {
            octets: [0; EXI_BASETYPES_MAX_OCTETS_SUPPORTED],
            octets_count: 0,
        };

        assert_eq!(exi_unsigned.convert32_to(0x5678, EXI_BASETYPES_UINT16_MAX_OCTETS).is_ok(), true);
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

        assert_eq!(exi_unsigned.convert32_to(0x105678, EXI_BASETYPES_UINT32_MAX_OCTETS).is_ok(), true);
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

        assert_eq!(exi_unsigned.convert64_to(0x105678).is_ok(), true);
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

        assert_eq!(exi_unsigned.convert32_to(0x5678, EXI_BASETYPES_UINT16_MAX_OCTETS).is_ok(), true);
        assert_eq!(exi_unsigned.convert32_from(EXI_BASETYPES_UINT16_MAX_OCTETS), Ok(0x5678));
    }

    #[test]
    fn convert64_from() {
        let mut exi_unsigned = ExiUnsigned {
            octets: [0; EXI_BASETYPES_MAX_OCTETS_SUPPORTED],
            octets_count: 0,
        };
        assert_eq!(exi_unsigned.convert64_to(0x105678).is_ok(), true);
        assert_eq!(exi_unsigned.convert64_from(), Ok(0x105678));
    }

}
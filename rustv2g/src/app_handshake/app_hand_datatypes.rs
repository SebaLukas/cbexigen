use std::convert::TryFrom;

pub const APP_HAND_PROTOCOL_NAMESPACE_CHARACTER_SIZE: u8 = 100;
pub const APP_HAND_APPPROTOCOLTYPE_5_ARRAY_SIZE: u8 = 5;
#[derive(Debug, PartialEq)]
pub enum ResponseCode {
    OkSuccessfulNegotiation = 0,
    OkSuccessfulNegotiationWithMinorDeviation = 1,
    FailedNoNegotiation = 2,
}

impl TryFrom<u32> for ResponseCode {
    type Error = ();

    fn try_from(value: u32) -> Result<Self, Self::Error> {
        match value {
            x if x == ResponseCode::OkSuccessfulNegotiation as u32 => {
                Ok(ResponseCode::OkSuccessfulNegotiation)
            }
            x if x == ResponseCode::OkSuccessfulNegotiationWithMinorDeviation as u32 => {
                Ok(ResponseCode::OkSuccessfulNegotiationWithMinorDeviation)
            }
            x if x == ResponseCode::FailedNoNegotiation as u32 => {
                Ok(ResponseCode::FailedNoNegotiation)
            }
            _ => Err(()),
        }
    }
}

#[derive(Debug, PartialEq)]
pub struct AppHandAppProtocolType {
    protocol_namespace: String,
    version_number_major: u32,
    version_number_minor: u32,
    schema_id: u8,
    priority: u8,
}

impl AppHandAppProtocolType {
    pub fn new(
        protocol_namespace: String,
        version_number_major: u32,
        version_number_minor: u32,
        schema_id: u8,
        priority: u8,
    ) -> Self {
        Self {
            protocol_namespace,
            version_number_major,
            version_number_minor,
            schema_id,
            priority,
        }
    }

    pub fn namespace(&self) -> String {
        self.protocol_namespace.clone()
    }

    pub fn version_number_major(&self) -> u32 {
        self.version_number_major
    }

    pub fn version_number_minor(&self) -> u32 {
        self.version_number_minor
    }

    pub fn schema_id(&self) -> u8 {
        self.schema_id
    }

    pub fn priority(&self) -> u8 {
        self.priority
    }
}

#[derive(Debug, PartialEq)]
pub struct AppHandSupportedAppProtocolReq {
    app_protocol: Vec<AppHandAppProtocolType>,
}

impl AppHandSupportedAppProtocolReq {
    pub fn new(app_protocol: Vec<AppHandAppProtocolType>) -> Self {
        Self { app_protocol }
    }
    pub fn app_protocol(&self) -> &Vec<AppHandAppProtocolType> {
        &self.app_protocol
    }
}

#[derive(Debug, PartialEq)]
pub struct AppHandSupportedAppProtocolRes {
    response_code: ResponseCode,
    schema_id: Option<u8>,
}

impl AppHandSupportedAppProtocolRes {
    pub fn new(response_code: ResponseCode, schema_id: Option<u8>) -> Self {
        Self {
            response_code,
            schema_id,
        }
    }

    pub fn response_code(&self) -> u8 {
        match self.response_code {
            ResponseCode::OkSuccessfulNegotiation => 0,
            ResponseCode::OkSuccessfulNegotiationWithMinorDeviation => 1,
            ResponseCode::FailedNoNegotiation => 2,
        }
    }
    pub fn schema_id(&self) -> Option<u8> {
        self.schema_id
    }
}

#[derive(Debug, PartialEq)]
pub enum AppProtocolExiDocument {
    SupportedAppProtocolReq(AppHandSupportedAppProtocolReq),
    SupportedAppProtocolRes(AppHandSupportedAppProtocolRes),
}

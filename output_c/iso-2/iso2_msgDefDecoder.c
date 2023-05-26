/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2022-2023 chargebyte GmbH
 * Copyright (C) 2022-2023 Contributors to EVerest
 */

/*****************************************************
 *
 * @author
 * @version
 *
 * The Code is generated! Changes may be overwritten.
 *
 *****************************************************/

/**
  * @file iso2_msgDefDecoder.c
  * @brief Description goes here
  *
  **/
#include <stdint.h>

#include "exi_basetypes.h"
#include "exi_basetypes_decoder.h"
#include "exi_error_codes.h"
#include "exi_header.h"
#include "exi_types_decoder.h"
#include "iso2_msgDefDatatypes.h"
#include "iso2_msgDefDecoder.h"



static int decode_iso2_CostType(exi_bitstream_t* stream, struct iso2_CostType* CostType);
static int decode_iso2_TransformType(exi_bitstream_t* stream, struct iso2_TransformType* TransformType);
static int decode_iso2_IntervalType(exi_bitstream_t* stream, struct iso2_IntervalType* IntervalType);
static int decode_iso2_TransformsType(exi_bitstream_t* stream, struct iso2_TransformsType* TransformsType);
static int decode_iso2_DSAKeyValueType(exi_bitstream_t* stream, struct iso2_DSAKeyValueType* DSAKeyValueType);
static int decode_iso2_X509IssuerSerialType(exi_bitstream_t* stream, struct iso2_X509IssuerSerialType* X509IssuerSerialType);
static int decode_iso2_RelativeTimeIntervalType(exi_bitstream_t* stream, struct iso2_RelativeTimeIntervalType* RelativeTimeIntervalType);
static int decode_iso2_DigestMethodType(exi_bitstream_t* stream, struct iso2_DigestMethodType* DigestMethodType);
static int decode_iso2_RSAKeyValueType(exi_bitstream_t* stream, struct iso2_RSAKeyValueType* RSAKeyValueType);
static int decode_iso2_CanonicalizationMethodType(exi_bitstream_t* stream, struct iso2_CanonicalizationMethodType* CanonicalizationMethodType);
static int decode_iso2_SignatureMethodType(exi_bitstream_t* stream, struct iso2_SignatureMethodType* SignatureMethodType);
static int decode_iso2_KeyValueType(exi_bitstream_t* stream, struct iso2_KeyValueType* KeyValueType);
static int decode_iso2_ReferenceType(exi_bitstream_t* stream, struct iso2_ReferenceType* ReferenceType);
static int decode_iso2_RetrievalMethodType(exi_bitstream_t* stream, struct iso2_RetrievalMethodType* RetrievalMethodType);
static int decode_iso2_X509DataType(exi_bitstream_t* stream, struct iso2_X509DataType* X509DataType);
static int decode_iso2_PGPDataType(exi_bitstream_t* stream, struct iso2_PGPDataType* PGPDataType);
static int decode_iso2_SPKIDataType(exi_bitstream_t* stream, struct iso2_SPKIDataType* SPKIDataType);
static int decode_iso2_SignedInfoType(exi_bitstream_t* stream, struct iso2_SignedInfoType* SignedInfoType);
static int decode_iso2_DC_EVSEStatusType(exi_bitstream_t* stream, struct iso2_DC_EVSEStatusType* DC_EVSEStatusType);
static int decode_iso2_AC_EVSEStatusType(exi_bitstream_t* stream, struct iso2_AC_EVSEStatusType* AC_EVSEStatusType);
static int decode_iso2_SelectedServiceType(exi_bitstream_t* stream, struct iso2_SelectedServiceType* SelectedServiceType);
static int decode_iso2_ServiceType(exi_bitstream_t* stream, struct iso2_ServiceType* ServiceType);
static int decode_iso2_SignatureValueType(exi_bitstream_t* stream, struct iso2_SignatureValueType* SignatureValueType);
static int decode_iso2_DC_EVStatusType(exi_bitstream_t* stream, struct iso2_DC_EVStatusType* DC_EVStatusType);
static int decode_iso2_SubCertificatesType(exi_bitstream_t* stream, struct iso2_SubCertificatesType* SubCertificatesType);
static int decode_iso2_KeyInfoType(exi_bitstream_t* stream, struct iso2_KeyInfoType* KeyInfoType);
static int decode_iso2_PhysicalValueType(exi_bitstream_t* stream, struct iso2_PhysicalValueType* PhysicalValueType);
static int decode_iso2_ConsumptionCostType(exi_bitstream_t* stream, struct iso2_ConsumptionCostType* ConsumptionCostType);
static int decode_iso2_PMaxScheduleEntryType(exi_bitstream_t* stream, struct iso2_PMaxScheduleEntryType* PMaxScheduleEntryType);
static int decode_iso2_SalesTariffEntryType(exi_bitstream_t* stream, struct iso2_SalesTariffEntryType* SalesTariffEntryType);
static int decode_iso2_ParameterType(exi_bitstream_t* stream, struct iso2_ParameterType* ParameterType);
static int decode_iso2_PMaxScheduleType(exi_bitstream_t* stream, struct iso2_PMaxScheduleType* PMaxScheduleType);
static int decode_iso2_SalesTariffType(exi_bitstream_t* stream, struct iso2_SalesTariffType* SalesTariffType);
static int decode_iso2_ParameterSetType(exi_bitstream_t* stream, struct iso2_ParameterSetType* ParameterSetType);
static int decode_iso2_SAScheduleTupleType(exi_bitstream_t* stream, struct iso2_SAScheduleTupleType* SAScheduleTupleType);
static int decode_iso2_ProfileEntryType(exi_bitstream_t* stream, struct iso2_ProfileEntryType* ProfileEntryType);
static int decode_iso2_ObjectType(exi_bitstream_t* stream, struct iso2_ObjectType* ObjectType);
static int decode_iso2_SupportedEnergyTransferModeType(exi_bitstream_t* stream, struct iso2_SupportedEnergyTransferModeType* SupportedEnergyTransferModeType);
static int decode_iso2_CertificateChainType(exi_bitstream_t* stream, struct iso2_CertificateChainType* CertificateChainType);
static int decode_iso2_BodyBaseType(exi_bitstream_t* stream, struct iso2_BodyBaseType* BodyBaseType);
static int decode_iso2_NotificationType(exi_bitstream_t* stream, struct iso2_NotificationType* NotificationType);
static int decode_iso2_SelectedServiceListType(exi_bitstream_t* stream, struct iso2_SelectedServiceListType* SelectedServiceListType);
static int decode_iso2_EVSEStatusType(exi_bitstream_t* stream, struct iso2_EVSEStatusType* EVSEStatusType);
static int decode_iso2_PaymentOptionListType(exi_bitstream_t* stream, struct iso2_PaymentOptionListType* PaymentOptionListType);
static int decode_iso2_SignatureType(exi_bitstream_t* stream, struct iso2_SignatureType* SignatureType);
static int decode_iso2_DC_EVChargeParameterType(exi_bitstream_t* stream, struct iso2_DC_EVChargeParameterType* DC_EVChargeParameterType);
static int decode_iso2_AC_EVChargeParameterType(exi_bitstream_t* stream, struct iso2_AC_EVChargeParameterType* AC_EVChargeParameterType);
static int decode_iso2_EVChargeParameterType(exi_bitstream_t* stream, struct iso2_EVChargeParameterType* EVChargeParameterType);
static int decode_iso2_ListOfRootCertificateIDsType(exi_bitstream_t* stream, struct iso2_ListOfRootCertificateIDsType* ListOfRootCertificateIDsType);
static int decode_iso2_ServiceParameterListType(exi_bitstream_t* stream, struct iso2_ServiceParameterListType* ServiceParameterListType);
static int decode_iso2_SASchedulesType(exi_bitstream_t* stream, struct iso2_SASchedulesType* SASchedulesType);
static int decode_iso2_SAScheduleListType(exi_bitstream_t* stream, struct iso2_SAScheduleListType* SAScheduleListType);
static int decode_iso2_ChargingProfileType(exi_bitstream_t* stream, struct iso2_ChargingProfileType* ChargingProfileType);
static int decode_iso2_ChargeServiceType(exi_bitstream_t* stream, struct iso2_ChargeServiceType* ChargeServiceType);
static int decode_iso2_EVSEChargeParameterType(exi_bitstream_t* stream, struct iso2_EVSEChargeParameterType* EVSEChargeParameterType);
static int decode_iso2_DC_EVSEChargeParameterType(exi_bitstream_t* stream, struct iso2_DC_EVSEChargeParameterType* DC_EVSEChargeParameterType);
static int decode_iso2_AC_EVSEChargeParameterType(exi_bitstream_t* stream, struct iso2_AC_EVSEChargeParameterType* AC_EVSEChargeParameterType);
static int decode_iso2_ContractSignatureEncryptedPrivateKeyType(exi_bitstream_t* stream, struct iso2_ContractSignatureEncryptedPrivateKeyType* ContractSignatureEncryptedPrivateKeyType);
static int decode_iso2_EVPowerDeliveryParameterType(exi_bitstream_t* stream, struct iso2_EVPowerDeliveryParameterType* EVPowerDeliveryParameterType);
static int decode_iso2_DC_EVPowerDeliveryParameterType(exi_bitstream_t* stream, struct iso2_DC_EVPowerDeliveryParameterType* DC_EVPowerDeliveryParameterType);
static int decode_iso2_ServiceListType(exi_bitstream_t* stream, struct iso2_ServiceListType* ServiceListType);
static int decode_iso2_DiffieHellmanPublickeyType(exi_bitstream_t* stream, struct iso2_DiffieHellmanPublickeyType* DiffieHellmanPublickeyType);
static int decode_iso2_EMAIDType(exi_bitstream_t* stream, struct iso2_EMAIDType* EMAIDType);
static int decode_iso2_MeterInfoType(exi_bitstream_t* stream, struct iso2_MeterInfoType* MeterInfoType);
static int decode_iso2_MessageHeaderType(exi_bitstream_t* stream, struct iso2_MessageHeaderType* MessageHeaderType);
static int decode_iso2_ServiceDetailReqType(exi_bitstream_t* stream, struct iso2_ServiceDetailReqType* ServiceDetailReqType);
static int decode_iso2_ChargeParameterDiscoveryReqType(exi_bitstream_t* stream, struct iso2_ChargeParameterDiscoveryReqType* ChargeParameterDiscoveryReqType);
static int decode_iso2_CertificateUpdateReqType(exi_bitstream_t* stream, struct iso2_CertificateUpdateReqType* CertificateUpdateReqType);
static int decode_iso2_PreChargeReqType(exi_bitstream_t* stream, struct iso2_PreChargeReqType* PreChargeReqType);
static int decode_iso2_SessionStopResType(exi_bitstream_t* stream, struct iso2_SessionStopResType* SessionStopResType);
static int decode_iso2_ServiceDetailResType(exi_bitstream_t* stream, struct iso2_ServiceDetailResType* ServiceDetailResType);
static int decode_iso2_ChargeParameterDiscoveryResType(exi_bitstream_t* stream, struct iso2_ChargeParameterDiscoveryResType* ChargeParameterDiscoveryResType);
static int decode_iso2_CertificateUpdateResType(exi_bitstream_t* stream, struct iso2_CertificateUpdateResType* CertificateUpdateResType);
static int decode_iso2_CableCheckResType(exi_bitstream_t* stream, struct iso2_CableCheckResType* CableCheckResType);
static int decode_iso2_PreChargeResType(exi_bitstream_t* stream, struct iso2_PreChargeResType* PreChargeResType);
static int decode_iso2_PowerDeliveryReqType(exi_bitstream_t* stream, struct iso2_PowerDeliveryReqType* PowerDeliveryReqType);
static int decode_iso2_PaymentServiceSelectionReqType(exi_bitstream_t* stream, struct iso2_PaymentServiceSelectionReqType* PaymentServiceSelectionReqType);
static int decode_iso2_CertificateInstallationReqType(exi_bitstream_t* stream, struct iso2_CertificateInstallationReqType* CertificateInstallationReqType);
static int decode_iso2_CurrentDemandReqType(exi_bitstream_t* stream, struct iso2_CurrentDemandReqType* CurrentDemandReqType);
static int decode_iso2_PowerDeliveryResType(exi_bitstream_t* stream, struct iso2_PowerDeliveryResType* PowerDeliveryResType);
static int decode_iso2_PaymentServiceSelectionResType(exi_bitstream_t* stream, struct iso2_PaymentServiceSelectionResType* PaymentServiceSelectionResType);
static int decode_iso2_CertificateInstallationResType(exi_bitstream_t* stream, struct iso2_CertificateInstallationResType* CertificateInstallationResType);
static int decode_iso2_CurrentDemandResType(exi_bitstream_t* stream, struct iso2_CurrentDemandResType* CurrentDemandResType);
static int decode_iso2_MeteringReceiptReqType(exi_bitstream_t* stream, struct iso2_MeteringReceiptReqType* MeteringReceiptReqType);
static int decode_iso2_SessionSetupReqType(exi_bitstream_t* stream, struct iso2_SessionSetupReqType* SessionSetupReqType);
static int decode_iso2_PaymentDetailsReqType(exi_bitstream_t* stream, struct iso2_PaymentDetailsReqType* PaymentDetailsReqType);
static int decode_iso2_ChargingStatusReqType(exi_bitstream_t* stream, struct iso2_ChargingStatusReqType* ChargingStatusReqType);
static int decode_iso2_WeldingDetectionReqType(exi_bitstream_t* stream, struct iso2_WeldingDetectionReqType* WeldingDetectionReqType);
static int decode_iso2_SessionSetupResType(exi_bitstream_t* stream, struct iso2_SessionSetupResType* SessionSetupResType);
static int decode_iso2_PaymentDetailsResType(exi_bitstream_t* stream, struct iso2_PaymentDetailsResType* PaymentDetailsResType);
static int decode_iso2_MeteringReceiptResType(exi_bitstream_t* stream, struct iso2_MeteringReceiptResType* MeteringReceiptResType);
static int decode_iso2_ChargingStatusResType(exi_bitstream_t* stream, struct iso2_ChargingStatusResType* ChargingStatusResType);
static int decode_iso2_WeldingDetectionResType(exi_bitstream_t* stream, struct iso2_WeldingDetectionResType* WeldingDetectionResType);
static int decode_iso2_ServiceDiscoveryReqType(exi_bitstream_t* stream, struct iso2_ServiceDiscoveryReqType* ServiceDiscoveryReqType);
static int decode_iso2_SessionStopReqType(exi_bitstream_t* stream, struct iso2_SessionStopReqType* SessionStopReqType);
static int decode_iso2_AuthorizationReqType(exi_bitstream_t* stream, struct iso2_AuthorizationReqType* AuthorizationReqType);
static int decode_iso2_CableCheckReqType(exi_bitstream_t* stream, struct iso2_CableCheckReqType* CableCheckReqType);
static int decode_iso2_ServiceDiscoveryResType(exi_bitstream_t* stream, struct iso2_ServiceDiscoveryResType* ServiceDiscoveryResType);
static int decode_iso2_AuthorizationResType(exi_bitstream_t* stream, struct iso2_AuthorizationResType* AuthorizationResType);
static int decode_iso2_BodyType(exi_bitstream_t* stream, struct iso2_BodyType* BodyType);
static int decode_iso2_V2G_Message(exi_bitstream_t* stream, struct iso2_V2G_Message* V2G_Message);

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}Cost; type={urn:iso:15118:2:2013:MsgDataTypes}CostType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: costKind, costKindType (1, 1); amount, unsignedInt (1, 1); amountMultiplier, unitMultiplierType (0, 1);
static int decode_iso2_CostType(exi_bitstream_t* stream, struct iso2_CostType* CostType) {
    int grammar_id = 0;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_CostType(CostType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 0:
            // Grammar: ID=0; read/write bits=1; START (costKind)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (costKind, costKindType (string)); next=1
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                CostType->costKind = (iso2_costKindType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 1;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 1:
            // Grammar: ID=1; read/write bits=1; START (amount)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (amount, unsignedInt (unsignedLong)); next=2
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &CostType->amount);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=2; END Element, START (amountMultiplier)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (amountMultiplier, unitMultiplierType (byte)); next=3
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 3, &value);
                            if (error == 0)
                            {
                                // type has min_value = -3
                                CostType->amountMultiplier = (int8_t)(value + -3);
                                CostType->amountMultiplier_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Transform; type={http://www.w3.org/2000/09/xmldsig#}TransformType; base type=; content type=mixed;
//          abstract=False; final=False; choice=True;
// Particle: Algorithm, anyURI (1, 1); XPath, string (0, 1);
static int decode_iso2_TransformType(exi_bitstream_t* stream, struct iso2_TransformType* TransformType) {
    int grammar_id = 5;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_TransformType(TransformType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 5:
            // Grammar: ID=5; read/write bits=1; START (Algorithm)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Algorithm, anyURI (anyURI)); next=6
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &TransformType->Algorithm.charactersLen);
                            if (error == 0)
                            {
                                if (TransformType->Algorithm.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    TransformType->Algorithm.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, TransformType->Algorithm.charactersLen, TransformType->Algorithm.characters, iso2_Algorithm_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 6;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 6:
            // Grammar: ID=6; read/write bits=2; END Element, START, START (XPath)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (None); next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                case 1:
                    // Event: START (XPath, string (string)); next=3
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &TransformType->XPath.charactersLen);
                            if (error == 0)
                            {
                                if (TransformType->XPath.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    TransformType->XPath.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, TransformType->XPath.charactersLen, TransformType->XPath.characters, iso2_XPath_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                TransformType->XPath_isUsed = 1u;
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}TimeInterval; type={urn:iso:15118:2:2013:MsgDataTypes}IntervalType; base type=; content type=empty;
//          abstract=True; final=False;
static int decode_iso2_IntervalType(exi_bitstream_t* stream, struct iso2_IntervalType* IntervalType) {
    // Element has no particles, so the function just returns zero
    (void)stream;
    (void)IntervalType;

    return 0;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Transforms; type={http://www.w3.org/2000/09/xmldsig#}TransformsType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Transform, TransformType (1, 1);
static int decode_iso2_TransformsType(exi_bitstream_t* stream, struct iso2_TransformsType* TransformsType) {
    int grammar_id = 7;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_TransformsType(TransformsType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 7:
            // Grammar: ID=7; read/write bits=1; START (Transform)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Transform, TransformType (TransformType)); next=8
                    // decode: element
                    error = decode_iso2_TransformType(stream, &TransformsType->Transform);
                    if (error == 0)
                    {
                        grammar_id = 8;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 8:
            // Grammar: ID=8; read/write bits=2; END Element, START (Transform)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Transform, TransformType (TransformType)); next=3
                    // decode: element
                    error = decode_iso2_TransformType(stream, &TransformsType->Transform);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}DSAKeyValue; type={http://www.w3.org/2000/09/xmldsig#}DSAKeyValueType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: P, CryptoBinary (0, 1)(was 1, 1)(seq. ['P', 'Q']); Q, CryptoBinary (0, 1)(was 1, 1)(seq. ['P', 'Q']); G, CryptoBinary (0, 1); Y, CryptoBinary (1, 1); J, CryptoBinary (0, 1); Seed, CryptoBinary (0, 1)(was 1, 1)(seq. ['Seed', 'PgenCounter']); PgenCounter, CryptoBinary (0, 1)(was 1, 1)(seq. ['Seed', 'PgenCounter']);
static int decode_iso2_DSAKeyValueType(exi_bitstream_t* stream, struct iso2_DSAKeyValueType* DSAKeyValueType) {
    int grammar_id = 9;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_DSAKeyValueType(DSAKeyValueType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 9:
            // Grammar: ID=9; read/write bits=2; START (P), START (G), START (Y)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (P, CryptoBinary (base64Binary)); next=10
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->P.bytesLen, &DSAKeyValueType->P.bytes[0], iso2_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->P_isUsed = 1u;
                        grammar_id = 10;
                    }
                    break;
                case 1:
                    // Event: START (G, CryptoBinary (base64Binary)); next=12
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->G.bytesLen, &DSAKeyValueType->G.bytes[0], iso2_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->G_isUsed = 1u;
                        grammar_id = 12;
                    }
                    break;
                case 2:
                    // Event: START (Y, CryptoBinary (base64Binary)); next=13
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Y.bytesLen, &DSAKeyValueType->Y.bytes[0], iso2_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 13;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 10:
            // Grammar: ID=10; read/write bits=1; START (Q)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Q, CryptoBinary (base64Binary)); next=11
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Q.bytesLen, &DSAKeyValueType->Q.bytes[0], iso2_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->Q_isUsed = 1u;
                        grammar_id = 11;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 11:
            // Grammar: ID=11; read/write bits=2; START (G), START (Y)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (G, CryptoBinary (base64Binary)); next=12
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->G.bytesLen, &DSAKeyValueType->G.bytes[0], iso2_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->G_isUsed = 1u;
                        grammar_id = 12;
                    }
                    break;
                case 1:
                    // Event: START (Y, CryptoBinary (base64Binary)); next=13
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Y.bytesLen, &DSAKeyValueType->Y.bytes[0], iso2_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 13;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 12:
            // Grammar: ID=12; read/write bits=1; START (Y)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Y, CryptoBinary (base64Binary)); next=13
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Y.bytesLen, &DSAKeyValueType->Y.bytes[0], iso2_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 13;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 13:
            // Grammar: ID=13; read/write bits=2; END Element, START (J), START (Seed)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (J, CryptoBinary (base64Binary)); next=14
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->J.bytesLen, &DSAKeyValueType->J.bytes[0], iso2_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->J_isUsed = 1u;
                        grammar_id = 14;
                    }
                    break;
                case 1:
                    // Event: START (Seed, CryptoBinary (base64Binary)); next=15
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Seed.bytesLen, &DSAKeyValueType->Seed.bytes[0], iso2_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->Seed_isUsed = 1u;
                        grammar_id = 15;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 14:
            // Grammar: ID=14; read/write bits=2; END Element, START (Seed)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Seed, CryptoBinary (base64Binary)); next=15
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Seed.bytesLen, &DSAKeyValueType->Seed.bytes[0], iso2_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->Seed_isUsed = 1u;
                        grammar_id = 15;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 15:
            // Grammar: ID=15; read/write bits=2; END Element, START (PgenCounter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PgenCounter, CryptoBinary (base64Binary)); next=3
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->PgenCounter.bytesLen, &DSAKeyValueType->PgenCounter.bytes[0], iso2_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->PgenCounter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}X509IssuerSerial; type={http://www.w3.org/2000/09/xmldsig#}X509IssuerSerialType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: X509IssuerName, string (1, 1); X509SerialNumber, integer (1, 1);
static int decode_iso2_X509IssuerSerialType(exi_bitstream_t* stream, struct iso2_X509IssuerSerialType* X509IssuerSerialType) {
    int grammar_id = 16;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_X509IssuerSerialType(X509IssuerSerialType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 16:
            // Grammar: ID=16; read/write bits=1; START (X509IssuerName)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (X509IssuerName, string (string)); next=17
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &X509IssuerSerialType->X509IssuerName.charactersLen);
                            if (error == 0)
                            {
                                if (X509IssuerSerialType->X509IssuerName.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    X509IssuerSerialType->X509IssuerName.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, X509IssuerSerialType->X509IssuerName.charactersLen, X509IssuerSerialType->X509IssuerName.characters, iso2_X509IssuerName_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 17;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 17:
            // Grammar: ID=17; read/write bits=1; START (X509SerialNumber)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (X509SerialNumber, integer (decimal)); next=3
                    // decode: int
                    error = decode_exi_type_integer32(stream, &X509IssuerSerialType->X509SerialNumber);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}RelativeTimeInterval; type={urn:iso:15118:2:2013:MsgDataTypes}RelativeTimeIntervalType; base type=IntervalType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: start, AnonType (1, 1); duration, AnonType (0, 1);
static int decode_iso2_RelativeTimeIntervalType(exi_bitstream_t* stream, struct iso2_RelativeTimeIntervalType* RelativeTimeIntervalType) {
    int grammar_id = 18;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_RelativeTimeIntervalType(RelativeTimeIntervalType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 18:
            // Grammar: ID=18; read/write bits=1; START (start)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (start, AnonType (unsignedInt)); next=19
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &RelativeTimeIntervalType->start);
                    if (error == 0)
                    {
                        grammar_id = 19;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 19:
            // Grammar: ID=19; read/write bits=2; END Element, START (duration)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (duration, AnonType (unsignedInt)); next=3
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &RelativeTimeIntervalType->duration);
                    if (error == 0)
                    {
                        RelativeTimeIntervalType->duration_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}DigestMethod; type={http://www.w3.org/2000/09/xmldsig#}DigestMethodType; base type=; content type=mixed;
//          abstract=False; final=False;
// Particle: Algorithm, anyURI (1, 1);
static int decode_iso2_DigestMethodType(exi_bitstream_t* stream, struct iso2_DigestMethodType* DigestMethodType) {
    int grammar_id = 20;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_DigestMethodType(DigestMethodType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 20:
            // Grammar: ID=20; read/write bits=1; START (Algorithm)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Algorithm, anyURI (anyURI)); next=3
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &DigestMethodType->Algorithm.charactersLen);
                            if (error == 0)
                            {
                                if (DigestMethodType->Algorithm.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    DigestMethodType->Algorithm.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, DigestMethodType->Algorithm.charactersLen, DigestMethodType->Algorithm.characters, iso2_Algorithm_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}RSAKeyValue; type={http://www.w3.org/2000/09/xmldsig#}RSAKeyValueType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Modulus, CryptoBinary (1, 1); Exponent, CryptoBinary (1, 1);
static int decode_iso2_RSAKeyValueType(exi_bitstream_t* stream, struct iso2_RSAKeyValueType* RSAKeyValueType) {
    int grammar_id = 21;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_RSAKeyValueType(RSAKeyValueType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 21:
            // Grammar: ID=21; read/write bits=1; START (Modulus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Modulus, CryptoBinary (base64Binary)); next=22
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &RSAKeyValueType->Modulus.bytesLen, &RSAKeyValueType->Modulus.bytes[0], iso2_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 22;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 22:
            // Grammar: ID=22; read/write bits=1; START (Exponent)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Exponent, CryptoBinary (base64Binary)); next=3
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &RSAKeyValueType->Exponent.bytesLen, &RSAKeyValueType->Exponent.bytes[0], iso2_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}CanonicalizationMethod; type={http://www.w3.org/2000/09/xmldsig#}CanonicalizationMethodType; base type=; content type=mixed;
//          abstract=False; final=False;
// Particle: Algorithm, anyURI (1, 1);
static int decode_iso2_CanonicalizationMethodType(exi_bitstream_t* stream, struct iso2_CanonicalizationMethodType* CanonicalizationMethodType) {
    int grammar_id = 23;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_CanonicalizationMethodType(CanonicalizationMethodType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 23:
            // Grammar: ID=23; read/write bits=1; START (Algorithm)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Algorithm, anyURI (anyURI)); next=3
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &CanonicalizationMethodType->Algorithm.charactersLen);
                            if (error == 0)
                            {
                                if (CanonicalizationMethodType->Algorithm.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    CanonicalizationMethodType->Algorithm.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, CanonicalizationMethodType->Algorithm.charactersLen, CanonicalizationMethodType->Algorithm.characters, iso2_Algorithm_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignatureMethod; type={http://www.w3.org/2000/09/xmldsig#}SignatureMethodType; base type=; content type=mixed;
//          abstract=False; final=False;
// Particle: Algorithm, anyURI (1, 1); HMACOutputLength, HMACOutputLengthType (0, 1);
static int decode_iso2_SignatureMethodType(exi_bitstream_t* stream, struct iso2_SignatureMethodType* SignatureMethodType) {
    int grammar_id = 24;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_SignatureMethodType(SignatureMethodType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 24:
            // Grammar: ID=24; read/write bits=1; START (Algorithm)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Algorithm, anyURI (anyURI)); next=25
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &SignatureMethodType->Algorithm.charactersLen);
                            if (error == 0)
                            {
                                if (SignatureMethodType->Algorithm.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    SignatureMethodType->Algorithm.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, SignatureMethodType->Algorithm.charactersLen, SignatureMethodType->Algorithm.characters, iso2_Algorithm_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 25;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 25:
            // Grammar: ID=25; read/write bits=2; END Element, START (HMACOutputLength)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (HMACOutputLength, HMACOutputLengthType (integer)); next=3
                    // decode: int
                    error = decode_exi_type_integer32(stream, &SignatureMethodType->HMACOutputLength);
                    if (error == 0)
                    {
                        SignatureMethodType->HMACOutputLength_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}KeyValue; type={http://www.w3.org/2000/09/xmldsig#}KeyValueType; base type=; content type=mixed;
//          abstract=False; final=False; choice=True;
// Particle: DSAKeyValue, DSAKeyValueType (0, 1); RSAKeyValue, RSAKeyValueType (0, 1);
static int decode_iso2_KeyValueType(exi_bitstream_t* stream, struct iso2_KeyValueType* KeyValueType) {
    int grammar_id = 26;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_KeyValueType(KeyValueType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 26:
            // Grammar: ID=26; read/write bits=2; START (DSAKeyValue), START (RSAKeyValue), START
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DSAKeyValue, DSAKeyValueType (DSAKeyValueType)); next=3
                    // decode: element
                    error = decode_iso2_DSAKeyValueType(stream, &KeyValueType->DSAKeyValue);
                    if (error == 0)
                    {
                        KeyValueType->DSAKeyValue_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: START (RSAKeyValue, RSAKeyValueType (RSAKeyValueType)); next=3
                    // decode: element
                    error = decode_iso2_RSAKeyValueType(stream, &KeyValueType->RSAKeyValue);
                    if (error == 0)
                    {
                        KeyValueType->RSAKeyValue_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 2:
                    // Event: START (None); next=3
                    done = 1;
                    grammar_id = 3;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Reference; type={http://www.w3.org/2000/09/xmldsig#}ReferenceType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); URI, anyURI (0, 1); Type, anyURI (0, 1); Transforms, TransformsType (0, 1); DigestMethod, DigestMethodType (1, 1); DigestValue, DigestValueType (1, 1);
static int decode_iso2_ReferenceType(exi_bitstream_t* stream, struct iso2_ReferenceType* ReferenceType) {
    int grammar_id = 27;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ReferenceType(ReferenceType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 27:
            // Grammar: ID=27; read/write bits=3; START (Id), START (URI), START (Type), START (Transforms), START (DigestMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=28
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->Id.charactersLen);
                            if (error == 0)
                            {
                                if (ReferenceType->Id.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ReferenceType->Id.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ReferenceType->Id.charactersLen, ReferenceType->Id.characters, iso2_Id_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ReferenceType->Id_isUsed = 1u;
                                grammar_id = 28;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (URI, anyURI (anyURI)); next=29
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->URI.charactersLen);
                            if (error == 0)
                            {
                                if (ReferenceType->URI.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ReferenceType->URI.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ReferenceType->URI.charactersLen, ReferenceType->URI.characters, iso2_URI_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ReferenceType->URI_isUsed = 1u;
                                grammar_id = 29;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: START (Type, anyURI (anyURI)); next=30
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->Type.charactersLen);
                            if (error == 0)
                            {
                                if (ReferenceType->Type.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ReferenceType->Type.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ReferenceType->Type.charactersLen, ReferenceType->Type.characters, iso2_Type_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ReferenceType->Type_isUsed = 1u;
                                grammar_id = 30;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 3:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=31
                    // decode: element
                    error = decode_iso2_TransformsType(stream, &ReferenceType->Transforms);
                    if (error == 0)
                    {
                        ReferenceType->Transforms_isUsed = 1u;
                        grammar_id = 31;
                    }
                    break;
                case 4:
                    // Event: START (DigestMethod, DigestMethodType (DigestMethodType)); next=32
                    // decode: element
                    error = decode_iso2_DigestMethodType(stream, &ReferenceType->DigestMethod);
                    if (error == 0)
                    {
                        grammar_id = 32;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 28:
            // Grammar: ID=28; read/write bits=3; START (URI), START (Type), START (Transforms), START (DigestMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (URI, anyURI (anyURI)); next=29
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->URI.charactersLen);
                            if (error == 0)
                            {
                                if (ReferenceType->URI.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ReferenceType->URI.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ReferenceType->URI.charactersLen, ReferenceType->URI.characters, iso2_URI_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ReferenceType->URI_isUsed = 1u;
                                grammar_id = 29;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (Type, anyURI (anyURI)); next=30
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->Type.charactersLen);
                            if (error == 0)
                            {
                                if (ReferenceType->Type.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ReferenceType->Type.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ReferenceType->Type.charactersLen, ReferenceType->Type.characters, iso2_Type_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ReferenceType->Type_isUsed = 1u;
                                grammar_id = 30;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=31
                    // decode: element
                    error = decode_iso2_TransformsType(stream, &ReferenceType->Transforms);
                    if (error == 0)
                    {
                        ReferenceType->Transforms_isUsed = 1u;
                        grammar_id = 31;
                    }
                    break;
                case 3:
                    // Event: START (DigestMethod, DigestMethodType (DigestMethodType)); next=32
                    // decode: element
                    error = decode_iso2_DigestMethodType(stream, &ReferenceType->DigestMethod);
                    if (error == 0)
                    {
                        grammar_id = 32;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 29:
            // Grammar: ID=29; read/write bits=2; START (Type), START (Transforms), START (DigestMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Type, anyURI (anyURI)); next=30
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->Type.charactersLen);
                            if (error == 0)
                            {
                                if (ReferenceType->Type.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ReferenceType->Type.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ReferenceType->Type.charactersLen, ReferenceType->Type.characters, iso2_Type_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ReferenceType->Type_isUsed = 1u;
                                grammar_id = 30;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=31
                    // decode: element
                    error = decode_iso2_TransformsType(stream, &ReferenceType->Transforms);
                    if (error == 0)
                    {
                        ReferenceType->Transforms_isUsed = 1u;
                        grammar_id = 31;
                    }
                    break;
                case 2:
                    // Event: START (DigestMethod, DigestMethodType (DigestMethodType)); next=32
                    // decode: element
                    error = decode_iso2_DigestMethodType(stream, &ReferenceType->DigestMethod);
                    if (error == 0)
                    {
                        grammar_id = 32;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 30:
            // Grammar: ID=30; read/write bits=2; START (Transforms), START (DigestMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=31
                    // decode: element
                    error = decode_iso2_TransformsType(stream, &ReferenceType->Transforms);
                    if (error == 0)
                    {
                        ReferenceType->Transforms_isUsed = 1u;
                        grammar_id = 31;
                    }
                    break;
                case 1:
                    // Event: START (DigestMethod, DigestMethodType (DigestMethodType)); next=32
                    // decode: element
                    error = decode_iso2_DigestMethodType(stream, &ReferenceType->DigestMethod);
                    if (error == 0)
                    {
                        grammar_id = 32;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 31:
            // Grammar: ID=31; read/write bits=1; START (DigestMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DigestMethod, DigestMethodType (DigestMethodType)); next=32
                    // decode: element
                    error = decode_iso2_DigestMethodType(stream, &ReferenceType->DigestMethod);
                    if (error == 0)
                    {
                        grammar_id = 32;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 32:
            // Grammar: ID=32; read/write bits=1; START (DigestValue)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DigestValue, DigestValueType (base64Binary)); next=3
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &ReferenceType->DigestValue.bytesLen, &ReferenceType->DigestValue.bytes[0], iso2_DigestValueType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}RetrievalMethod; type={http://www.w3.org/2000/09/xmldsig#}RetrievalMethodType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: URI, anyURI (0, 1); Type, anyURI (0, 1); Transforms, TransformsType (0, 1);
static int decode_iso2_RetrievalMethodType(exi_bitstream_t* stream, struct iso2_RetrievalMethodType* RetrievalMethodType) {
    int grammar_id = 33;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_RetrievalMethodType(RetrievalMethodType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 33:
            // Grammar: ID=33; read/write bits=3; END Element, START (URI), START (Type), START (Transforms)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (URI, anyURI (anyURI)); next=34
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &RetrievalMethodType->URI.charactersLen);
                            if (error == 0)
                            {
                                if (RetrievalMethodType->URI.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    RetrievalMethodType->URI.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, RetrievalMethodType->URI.charactersLen, RetrievalMethodType->URI.characters, iso2_URI_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                RetrievalMethodType->URI_isUsed = 1u;
                                grammar_id = 34;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (Type, anyURI (anyURI)); next=35
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &RetrievalMethodType->Type.charactersLen);
                            if (error == 0)
                            {
                                if (RetrievalMethodType->Type.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    RetrievalMethodType->Type.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, RetrievalMethodType->Type.charactersLen, RetrievalMethodType->Type.characters, iso2_Type_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                RetrievalMethodType->Type_isUsed = 1u;
                                grammar_id = 35;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=3
                    // decode: element
                    error = decode_iso2_TransformsType(stream, &RetrievalMethodType->Transforms);
                    if (error == 0)
                    {
                        RetrievalMethodType->Transforms_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 3:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 34:
            // Grammar: ID=34; read/write bits=2; END Element, START (Type), START (Transforms)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Type, anyURI (anyURI)); next=35
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &RetrievalMethodType->Type.charactersLen);
                            if (error == 0)
                            {
                                if (RetrievalMethodType->Type.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    RetrievalMethodType->Type.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, RetrievalMethodType->Type.charactersLen, RetrievalMethodType->Type.characters, iso2_Type_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                RetrievalMethodType->Type_isUsed = 1u;
                                grammar_id = 35;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=3
                    // decode: element
                    error = decode_iso2_TransformsType(stream, &RetrievalMethodType->Transforms);
                    if (error == 0)
                    {
                        RetrievalMethodType->Transforms_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 35:
            // Grammar: ID=35; read/write bits=2; END Element, START (Transforms)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=3
                    // decode: element
                    error = decode_iso2_TransformsType(stream, &RetrievalMethodType->Transforms);
                    if (error == 0)
                    {
                        RetrievalMethodType->Transforms_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}X509Data; type={http://www.w3.org/2000/09/xmldsig#}X509DataType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: X509IssuerSerial, X509IssuerSerialType (0, 1); X509SKI, base64Binary (0, 1); X509SubjectName, string (0, 1); X509Certificate, base64Binary (0, 1); X509CRL, base64Binary (0, 1);
static int decode_iso2_X509DataType(exi_bitstream_t* stream, struct iso2_X509DataType* X509DataType) {
    int grammar_id = 36;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_X509DataType(X509DataType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 36:
            // Grammar: ID=36; read/write bits=3; START (X509IssuerSerial), START (X509SKI), START (X509SubjectName), START (X509Certificate), START (X509CRL), START
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (X509IssuerSerial, X509IssuerSerialType (X509IssuerSerialType)); next=3
                    // decode: element
                    error = decode_iso2_X509IssuerSerialType(stream, &X509DataType->X509IssuerSerial);
                    if (error == 0)
                    {
                        X509DataType->X509IssuerSerial_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: START (X509SKI, base64Binary (base64Binary)); next=3
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &X509DataType->X509SKI.bytesLen, &X509DataType->X509SKI.bytes[0], iso2_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        X509DataType->X509SKI_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 2:
                    // Event: START (X509SubjectName, string (string)); next=3
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &X509DataType->X509SubjectName.charactersLen);
                            if (error == 0)
                            {
                                if (X509DataType->X509SubjectName.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    X509DataType->X509SubjectName.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, X509DataType->X509SubjectName.charactersLen, X509DataType->X509SubjectName.characters, iso2_X509SubjectName_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                X509DataType->X509SubjectName_isUsed = 1u;
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 3:
                    // Event: START (X509Certificate, base64Binary (base64Binary)); next=3
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &X509DataType->X509Certificate.bytesLen, &X509DataType->X509Certificate.bytes[0], iso2_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        X509DataType->X509Certificate_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 4:
                    // Event: START (X509CRL, base64Binary (base64Binary)); next=3
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &X509DataType->X509CRL.bytesLen, &X509DataType->X509CRL.bytes[0], iso2_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        X509DataType->X509CRL_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 5:
                    // Event: START (None); next=3
                    done = 1;
                    grammar_id = 3;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}PGPData; type={http://www.w3.org/2000/09/xmldsig#}PGPDataType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False; choice=True; sequence=True (2;
// Particle: PGPKeyID, base64Binary (1, 1); PGPKeyPacket, base64Binary (0, 1); PGPKeyPacket, base64Binary (1, 1);
static int decode_iso2_PGPDataType(exi_bitstream_t* stream, struct iso2_PGPDataType* PGPDataType) {
    int grammar_id = 37;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_PGPDataType(PGPDataType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 37:
            // Grammar: ID=37; read/write bits=1; START (PGPKeyID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PGPKeyID, base64Binary (base64Binary)); next=38
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_1.PGPKeyID.bytesLen, &PGPDataType->choice_1.PGPKeyID.bytes[0], iso2_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 38;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 38:
            // Grammar: ID=38; read/write bits=2; START (PGPKeyPacket), START (PGPKeyPacket)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PGPKeyPacket, base64Binary (base64Binary)); next=39
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_1.PGPKeyPacket.bytesLen, &PGPDataType->choice_1.PGPKeyPacket.bytes[0], iso2_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        PGPDataType->choice_1.PGPKeyPacket_isUsed = 1u;
                        grammar_id = 39;
                    }
                    break;
                case 1:
                    // Event: START (PGPKeyPacket, base64Binary (base64Binary)); next=3
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_2.PGPKeyPacket.bytesLen, &PGPDataType->choice_2.PGPKeyPacket.bytes[0], iso2_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 39:
            // Grammar: ID=39; read/write bits=1; START (PGPKeyPacket)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PGPKeyPacket, base64Binary (base64Binary)); next=3
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_2.PGPKeyPacket.bytesLen, &PGPDataType->choice_2.PGPKeyPacket.bytes[0], iso2_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SPKIData; type={http://www.w3.org/2000/09/xmldsig#}SPKIDataType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: SPKISexp, base64Binary (1, 1);
static int decode_iso2_SPKIDataType(exi_bitstream_t* stream, struct iso2_SPKIDataType* SPKIDataType) {
    int grammar_id = 40;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_SPKIDataType(SPKIDataType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 40:
            // Grammar: ID=40; read/write bits=1; START (SPKISexp)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SPKISexp, base64Binary (base64Binary)); next=3
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SPKIDataType->SPKISexp.bytesLen, &SPKIDataType->SPKISexp.bytes[0], iso2_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignedInfo; type={http://www.w3.org/2000/09/xmldsig#}SignedInfoType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); CanonicalizationMethod, CanonicalizationMethodType (1, 1); SignatureMethod, SignatureMethodType (1, 1); Reference, ReferenceType (1, 1);
static int decode_iso2_SignedInfoType(exi_bitstream_t* stream, struct iso2_SignedInfoType* SignedInfoType) {
    int grammar_id = 41;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_SignedInfoType(SignedInfoType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 41:
            // Grammar: ID=41; read/write bits=2; START (Id), START (CanonicalizationMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=42
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &SignedInfoType->Id.charactersLen);
                            if (error == 0)
                            {
                                if (SignedInfoType->Id.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    SignedInfoType->Id.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, SignedInfoType->Id.charactersLen, SignedInfoType->Id.characters, iso2_Id_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                SignedInfoType->Id_isUsed = 1u;
                                grammar_id = 42;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (CanonicalizationMethod, CanonicalizationMethodType (CanonicalizationMethodType)); next=43
                    // decode: element
                    error = decode_iso2_CanonicalizationMethodType(stream, &SignedInfoType->CanonicalizationMethod);
                    if (error == 0)
                    {
                        grammar_id = 43;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 42:
            // Grammar: ID=42; read/write bits=1; START (CanonicalizationMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (CanonicalizationMethod, CanonicalizationMethodType (CanonicalizationMethodType)); next=43
                    // decode: element
                    error = decode_iso2_CanonicalizationMethodType(stream, &SignedInfoType->CanonicalizationMethod);
                    if (error == 0)
                    {
                        grammar_id = 43;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 43:
            // Grammar: ID=43; read/write bits=1; START (SignatureMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SignatureMethod, SignatureMethodType (SignatureMethodType)); next=44
                    // decode: element
                    error = decode_iso2_SignatureMethodType(stream, &SignedInfoType->SignatureMethod);
                    if (error == 0)
                    {
                        grammar_id = 44;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 44:
            // Grammar: ID=44; read/write bits=1; START (Reference)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Reference, ReferenceType (ReferenceType)); next=45
                    // decode: element
                    error = decode_iso2_ReferenceType(stream, &SignedInfoType->Reference);
                    if (error == 0)
                    {
                        grammar_id = 45;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 45:
            // Grammar: ID=45; read/write bits=2; END Element, START (Reference)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Reference, ReferenceType (ReferenceType)); next=3
                    // decode: element
                    error = decode_iso2_ReferenceType(stream, &SignedInfoType->Reference);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEStatus; type={urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEStatusType; base type=EVSEStatusType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: NotificationMaxDelay, unsignedShort (1, 1); EVSENotification, EVSENotificationType (1, 1); EVSEIsolationStatus, isolationLevelType (0, 1); EVSEStatusCode, DC_EVSEStatusCodeType (1, 1);
static int decode_iso2_DC_EVSEStatusType(exi_bitstream_t* stream, struct iso2_DC_EVSEStatusType* DC_EVSEStatusType) {
    int grammar_id = 46;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_DC_EVSEStatusType(DC_EVSEStatusType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 46:
            // Grammar: ID=46; read/write bits=1; START (NotificationMaxDelay)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (NotificationMaxDelay, unsignedShort (unsignedInt)); next=47
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &DC_EVSEStatusType->NotificationMaxDelay);
                    if (error == 0)
                    {
                        grammar_id = 47;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 47:
            // Grammar: ID=47; read/write bits=1; START (EVSENotification)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSENotification, EVSENotificationType (string)); next=48
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                DC_EVSEStatusType->EVSENotification = (iso2_EVSENotificationType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 48;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 48:
            // Grammar: ID=48; read/write bits=2; START (EVSEIsolationStatus), START (EVSEStatusCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEIsolationStatus, isolationLevelType (string)); next=49
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 3, &value);
                            if (error == 0)
                            {
                                DC_EVSEStatusType->EVSEIsolationStatus = (iso2_isolationLevelType)value;
                                DC_EVSEStatusType->EVSEIsolationStatus_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 49;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (EVSEStatusCode, DC_EVSEStatusCodeType (string)); next=3
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 4, &value);
                            if (error == 0)
                            {
                                DC_EVSEStatusType->EVSEStatusCode = (iso2_DC_EVSEStatusCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 49:
            // Grammar: ID=49; read/write bits=1; START (EVSEStatusCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEStatusCode, DC_EVSEStatusCodeType (string)); next=3
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 4, &value);
                            if (error == 0)
                            {
                                DC_EVSEStatusType->EVSEStatusCode = (iso2_DC_EVSEStatusCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEStatus; type={urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEStatusType; base type=EVSEStatusType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: NotificationMaxDelay, unsignedShort (1, 1); EVSENotification, EVSENotificationType (1, 1); RCD, boolean (1, 1);
static int decode_iso2_AC_EVSEStatusType(exi_bitstream_t* stream, struct iso2_AC_EVSEStatusType* AC_EVSEStatusType) {
    int grammar_id = 50;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_AC_EVSEStatusType(AC_EVSEStatusType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 50:
            // Grammar: ID=50; read/write bits=1; START (NotificationMaxDelay)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (NotificationMaxDelay, unsignedShort (unsignedInt)); next=51
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &AC_EVSEStatusType->NotificationMaxDelay);
                    if (error == 0)
                    {
                        grammar_id = 51;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 51:
            // Grammar: ID=51; read/write bits=1; START (EVSENotification)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSENotification, EVSENotificationType (string)); next=52
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                AC_EVSEStatusType->EVSENotification = (iso2_EVSENotificationType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 52;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 52:
            // Grammar: ID=52; read/write bits=1; START (RCD)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RCD, boolean (boolean)); next=3
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                AC_EVSEStatusType->RCD = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}SelectedService; type={urn:iso:15118:2:2013:MsgDataTypes}SelectedServiceType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: ServiceID, serviceIDType (1, 1); ParameterSetID, short (0, 1);
static int decode_iso2_SelectedServiceType(exi_bitstream_t* stream, struct iso2_SelectedServiceType* SelectedServiceType) {
    int grammar_id = 53;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_SelectedServiceType(SelectedServiceType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 53:
            // Grammar: ID=53; read/write bits=1; START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=54
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &SelectedServiceType->ServiceID);
                    if (error == 0)
                    {
                        grammar_id = 54;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 54:
            // Grammar: ID=54; read/write bits=2; END Element, START (ParameterSetID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ParameterSetID, short (int)); next=3
                    // decode: short
                    error = decode_exi_type_integer16(stream, &SelectedServiceType->ParameterSetID);
                    if (error == 0)
                    {
                        SelectedServiceType->ParameterSetID_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}Service; type={urn:iso:15118:2:2013:MsgDataTypes}ServiceType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: ServiceID, serviceIDType (1, 1); ServiceName, serviceNameType (0, 1); ServiceCategory, serviceCategoryType (1, 1); ServiceScope, serviceScopeType (0, 1); FreeService, boolean (1, 1);
static int decode_iso2_ServiceType(exi_bitstream_t* stream, struct iso2_ServiceType* ServiceType) {
    int grammar_id = 55;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ServiceType(ServiceType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 55:
            // Grammar: ID=55; read/write bits=1; START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=56
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &ServiceType->ServiceID);
                    if (error == 0)
                    {
                        grammar_id = 56;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 56:
            // Grammar: ID=56; read/write bits=2; START (ServiceName), START (ServiceCategory)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceName, serviceNameType (string)); next=57
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ServiceType->ServiceName.charactersLen);
                            if (error == 0)
                            {
                                if (ServiceType->ServiceName.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ServiceType->ServiceName.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ServiceType->ServiceName.charactersLen, ServiceType->ServiceName.characters, iso2_ServiceName_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ServiceType->ServiceName_isUsed = 1u;
                                grammar_id = 57;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (ServiceCategory, serviceCategoryType (string)); next=58
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                ServiceType->ServiceCategory = (iso2_serviceCategoryType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 58;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 57:
            // Grammar: ID=57; read/write bits=1; START (ServiceCategory)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceCategory, serviceCategoryType (string)); next=58
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                ServiceType->ServiceCategory = (iso2_serviceCategoryType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 58;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 58:
            // Grammar: ID=58; read/write bits=2; START (ServiceScope), START (FreeService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceScope, serviceScopeType (string)); next=59
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ServiceType->ServiceScope.charactersLen);
                            if (error == 0)
                            {
                                if (ServiceType->ServiceScope.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ServiceType->ServiceScope.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ServiceType->ServiceScope.charactersLen, ServiceType->ServiceScope.characters, iso2_ServiceScope_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ServiceType->ServiceScope_isUsed = 1u;
                                grammar_id = 59;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (FreeService, boolean (boolean)); next=3
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ServiceType->FreeService = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 59:
            // Grammar: ID=59; read/write bits=1; START (FreeService)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (FreeService, boolean (boolean)); next=3
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ServiceType->FreeService = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignatureValue; type={http://www.w3.org/2000/09/xmldsig#}SignatureValueType; base type=base64Binary; content type=simple;
//          abstract=False; final=False; derivation=extension;
// Particle: Id, ID (0, 1); CONTENT, SignatureValueType (1, 1);
static int decode_iso2_SignatureValueType(exi_bitstream_t* stream, struct iso2_SignatureValueType* SignatureValueType) {
    int grammar_id = 60;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_SignatureValueType(SignatureValueType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 60:
            // Grammar: ID=60; read/write bits=2; START (Id), START (CONTENT)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=61
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &SignatureValueType->Id.charactersLen);
                            if (error == 0)
                            {
                                if (SignatureValueType->Id.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    SignatureValueType->Id.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, SignatureValueType->Id.charactersLen, SignatureValueType->Id.characters, iso2_Id_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                SignatureValueType->Id_isUsed = 1u;
                                grammar_id = 61;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (CONTENT, SignatureValueType (base64Binary)); next=3
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SignatureValueType->CONTENT.bytesLen, &SignatureValueType->CONTENT.bytes[0], iso2_SignatureValueType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 61:
            // Grammar: ID=61; read/write bits=1; START (CONTENT)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (CONTENT, SignatureValueType (base64Binary)); next=3
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SignatureValueType->CONTENT.bytesLen, &SignatureValueType->CONTENT.bytes[0], iso2_SignatureValueType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}DC_EVStatus; type={urn:iso:15118:2:2013:MsgDataTypes}DC_EVStatusType; base type=EVStatusType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVReady, boolean (1, 1); EVErrorCode, DC_EVErrorCodeType (1, 1); EVRESSSOC, percentValueType (1, 1);
static int decode_iso2_DC_EVStatusType(exi_bitstream_t* stream, struct iso2_DC_EVStatusType* DC_EVStatusType) {
    int grammar_id = 62;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_DC_EVStatusType(DC_EVStatusType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 62:
            // Grammar: ID=62; read/write bits=1; START (EVReady)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVReady, boolean (boolean)); next=63
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                DC_EVStatusType->EVReady = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 63;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 63:
            // Grammar: ID=63; read/write bits=1; START (EVErrorCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVErrorCode, DC_EVErrorCodeType (string)); next=64
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 4, &value);
                            if (error == 0)
                            {
                                DC_EVStatusType->EVErrorCode = (iso2_DC_EVErrorCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 64;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 64:
            // Grammar: ID=64; read/write bits=1; START (EVRESSSOC)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVRESSSOC, percentValueType (byte)); next=3
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                DC_EVStatusType->EVRESSSOC = (int8_t)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}SubCertificates; type={urn:iso:15118:2:2013:MsgDataTypes}SubCertificatesType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Certificate, certificateType (1, 4);
static int decode_iso2_SubCertificatesType(exi_bitstream_t* stream, struct iso2_SubCertificatesType* SubCertificatesType) {
    int grammar_id = 65;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_SubCertificatesType(SubCertificatesType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 65:
            // Grammar: ID=65; read/write bits=1; START (Certificate)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Certificate, certificateType (base64Binary)); next=66
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SubCertificatesType->Certificate.bytesLen, &SubCertificatesType->Certificate.bytes[0], iso2_certificateType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 66;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 66:
            // Grammar: ID=66; read/write bits=2; END Element, START (Certificate)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Certificate, certificateType (base64Binary)); next=67
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SubCertificatesType->Certificate.bytesLen, &SubCertificatesType->Certificate.bytes[0], iso2_certificateType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 67;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 67:
            // Grammar: ID=67; read/write bits=2; END Element, START (Certificate)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Certificate, certificateType (base64Binary)); next=68
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SubCertificatesType->Certificate.bytesLen, &SubCertificatesType->Certificate.bytes[0], iso2_certificateType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 68;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 68:
            // Grammar: ID=68; read/write bits=2; END Element, START (Certificate)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Certificate, certificateType (base64Binary)); next=3
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SubCertificatesType->Certificate.bytesLen, &SubCertificatesType->Certificate.bytes[0], iso2_certificateType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}KeyInfo; type={http://www.w3.org/2000/09/xmldsig#}KeyInfoType; base type=; content type=mixed;
//          abstract=False; final=False; choice=True;
// Particle: Id, ID (0, 1); KeyName, string (0, 1); KeyValue, KeyValueType (0, 1); RetrievalMethod, RetrievalMethodType (0, 1); X509Data, X509DataType (0, 1); PGPData, PGPDataType (0, 1); SPKIData, SPKIDataType (0, 1); MgmtData, string (0, 1);
static int decode_iso2_KeyInfoType(exi_bitstream_t* stream, struct iso2_KeyInfoType* KeyInfoType) {
    int grammar_id = 69;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_KeyInfoType(KeyInfoType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 69:
            // Grammar: ID=69; read/write bits=4; START (Id), START (KeyName), START (KeyValue), START (RetrievalMethod), START (X509Data), START (PGPData), START (SPKIData), START (MgmtData), START
            error = exi_basetypes_decoder_nbit_uint(stream, 4, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=70
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &KeyInfoType->Id.charactersLen);
                            if (error == 0)
                            {
                                if (KeyInfoType->Id.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    KeyInfoType->Id.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, KeyInfoType->Id.charactersLen, KeyInfoType->Id.characters, iso2_Id_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                KeyInfoType->Id_isUsed = 1u;
                                grammar_id = 70;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (KeyName, string (string)); next=3
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &KeyInfoType->KeyName.charactersLen);
                            if (error == 0)
                            {
                                if (KeyInfoType->KeyName.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    KeyInfoType->KeyName.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, KeyInfoType->KeyName.charactersLen, KeyInfoType->KeyName.characters, iso2_KeyName_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                KeyInfoType->KeyName_isUsed = 1u;
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: START (KeyValue, KeyValueType (KeyValueType)); next=3
                    // decode: element
                    error = decode_iso2_KeyValueType(stream, &KeyInfoType->KeyValue);
                    if (error == 0)
                    {
                        KeyInfoType->KeyValue_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 3:
                    // Event: START (RetrievalMethod, RetrievalMethodType (RetrievalMethodType)); next=3
                    // decode: element
                    error = decode_iso2_RetrievalMethodType(stream, &KeyInfoType->RetrievalMethod);
                    if (error == 0)
                    {
                        KeyInfoType->RetrievalMethod_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 4:
                    // Event: START (X509Data, X509DataType (X509DataType)); next=3
                    // decode: element
                    error = decode_iso2_X509DataType(stream, &KeyInfoType->X509Data);
                    if (error == 0)
                    {
                        KeyInfoType->X509Data_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 5:
                    // Event: START (PGPData, PGPDataType (PGPDataType)); next=3
                    // decode: element
                    error = decode_iso2_PGPDataType(stream, &KeyInfoType->PGPData);
                    if (error == 0)
                    {
                        KeyInfoType->PGPData_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 6:
                    // Event: START (SPKIData, SPKIDataType (SPKIDataType)); next=3
                    // decode: element
                    error = decode_iso2_SPKIDataType(stream, &KeyInfoType->SPKIData);
                    if (error == 0)
                    {
                        KeyInfoType->SPKIData_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 7:
                    // Event: START (MgmtData, string (string)); next=3
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &KeyInfoType->MgmtData.charactersLen);
                            if (error == 0)
                            {
                                if (KeyInfoType->MgmtData.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    KeyInfoType->MgmtData.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, KeyInfoType->MgmtData.charactersLen, KeyInfoType->MgmtData.characters, iso2_MgmtData_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                KeyInfoType->MgmtData_isUsed = 1u;
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 8:
                    // Event: START (None); next=3
                    done = 1;
                    grammar_id = 3;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 70:
            // Grammar: ID=70; read/write bits=4; START (KeyName), START (KeyValue), START (RetrievalMethod), START (X509Data), START (PGPData), START (SPKIData), START (MgmtData), START
            error = exi_basetypes_decoder_nbit_uint(stream, 4, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (KeyName, string (string)); next=3
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &KeyInfoType->KeyName.charactersLen);
                            if (error == 0)
                            {
                                if (KeyInfoType->KeyName.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    KeyInfoType->KeyName.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, KeyInfoType->KeyName.charactersLen, KeyInfoType->KeyName.characters, iso2_KeyName_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                KeyInfoType->KeyName_isUsed = 1u;
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (KeyValue, KeyValueType (KeyValueType)); next=3
                    // decode: element
                    error = decode_iso2_KeyValueType(stream, &KeyInfoType->KeyValue);
                    if (error == 0)
                    {
                        KeyInfoType->KeyValue_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 2:
                    // Event: START (RetrievalMethod, RetrievalMethodType (RetrievalMethodType)); next=3
                    // decode: element
                    error = decode_iso2_RetrievalMethodType(stream, &KeyInfoType->RetrievalMethod);
                    if (error == 0)
                    {
                        KeyInfoType->RetrievalMethod_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 3:
                    // Event: START (X509Data, X509DataType (X509DataType)); next=3
                    // decode: element
                    error = decode_iso2_X509DataType(stream, &KeyInfoType->X509Data);
                    if (error == 0)
                    {
                        KeyInfoType->X509Data_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 4:
                    // Event: START (PGPData, PGPDataType (PGPDataType)); next=3
                    // decode: element
                    error = decode_iso2_PGPDataType(stream, &KeyInfoType->PGPData);
                    if (error == 0)
                    {
                        KeyInfoType->PGPData_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 5:
                    // Event: START (SPKIData, SPKIDataType (SPKIDataType)); next=3
                    // decode: element
                    error = decode_iso2_SPKIDataType(stream, &KeyInfoType->SPKIData);
                    if (error == 0)
                    {
                        KeyInfoType->SPKIData_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 6:
                    // Event: START (MgmtData, string (string)); next=3
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &KeyInfoType->MgmtData.charactersLen);
                            if (error == 0)
                            {
                                if (KeyInfoType->MgmtData.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    KeyInfoType->MgmtData.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, KeyInfoType->MgmtData.charactersLen, KeyInfoType->MgmtData.characters, iso2_MgmtData_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                KeyInfoType->MgmtData_isUsed = 1u;
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 7:
                    // Event: START (None); next=3
                    done = 1;
                    grammar_id = 3;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}EVMaximumCurrentLimit; type={urn:iso:15118:2:2013:MsgDataTypes}PhysicalValueType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Multiplier, unitMultiplierType (1, 1); Unit, unitSymbolType (1, 1); Value, short (1, 1);
static int decode_iso2_PhysicalValueType(exi_bitstream_t* stream, struct iso2_PhysicalValueType* PhysicalValueType) {
    int grammar_id = 71;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_PhysicalValueType(PhysicalValueType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 71:
            // Grammar: ID=71; read/write bits=1; START (Multiplier)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Multiplier, unitMultiplierType (byte)); next=72
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 3, &value);
                            if (error == 0)
                            {
                                // type has min_value = -3
                                PhysicalValueType->Multiplier = (int8_t)(value + -3);
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 72;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 72:
            // Grammar: ID=72; read/write bits=1; START (Unit)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Unit, unitSymbolType (string)); next=73
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 3, &value);
                            if (error == 0)
                            {
                                PhysicalValueType->Unit = (iso2_unitSymbolType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 73;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 73:
            // Grammar: ID=73; read/write bits=1; START (Value)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Value, short (int)); next=3
                    // decode: short
                    error = decode_exi_type_integer16(stream, &PhysicalValueType->Value);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}ConsumptionCost; type={urn:iso:15118:2:2013:MsgDataTypes}ConsumptionCostType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: startValue, PhysicalValueType (1, 1); Cost, CostType (1, 3);
static int decode_iso2_ConsumptionCostType(exi_bitstream_t* stream, struct iso2_ConsumptionCostType* ConsumptionCostType) {
    int grammar_id = 74;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ConsumptionCostType(ConsumptionCostType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 74:
            // Grammar: ID=74; read/write bits=1; START (startValue)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (startValue, PhysicalValueType (PhysicalValueType)); next=75
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &ConsumptionCostType->startValue);
                    if (error == 0)
                    {
                        grammar_id = 75;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 75:
            // Grammar: ID=75; read/write bits=1; START (Cost)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Cost, CostType (CostType)); next=76
                    // decode: element array
                    if (ConsumptionCostType->Cost.arrayLen < iso2_CostType_3_ARRAY_SIZE)
                    {
                        error = decode_iso2_CostType(stream, &ConsumptionCostType->Cost.array[ConsumptionCostType->Cost.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 76;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 76:
            // Grammar: ID=76; read/write bits=2; END Element, START (Cost)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Cost, CostType (CostType)); next=77
                    // decode: element array
                    if (ConsumptionCostType->Cost.arrayLen < iso2_CostType_3_ARRAY_SIZE)
                    {
                        error = decode_iso2_CostType(stream, &ConsumptionCostType->Cost.array[ConsumptionCostType->Cost.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 77;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 77:
            // Grammar: ID=77; read/write bits=2; END Element, START (Cost)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Cost, CostType (CostType)); next=3
                    // decode: element array
                    if (ConsumptionCostType->Cost.arrayLen < iso2_CostType_3_ARRAY_SIZE)
                    {
                        error = decode_iso2_CostType(stream, &ConsumptionCostType->Cost.array[ConsumptionCostType->Cost.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}PMaxScheduleEntry; type={urn:iso:15118:2:2013:MsgDataTypes}PMaxScheduleEntryType; base type=EntryType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: RelativeTimeInterval, RelativeTimeIntervalType (0, 1); TimeInterval, IntervalType (0, 1); PMax, PhysicalValueType (1, 1);
static int decode_iso2_PMaxScheduleEntryType(exi_bitstream_t* stream, struct iso2_PMaxScheduleEntryType* PMaxScheduleEntryType) {
    int grammar_id = 78;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_PMaxScheduleEntryType(PMaxScheduleEntryType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 78:
            // Grammar: ID=78; read/write bits=2; START (RelativeTimeInterval), START (TimeInterval)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RelativeTimeInterval, RelativeTimeIntervalType (IntervalType)); next=79
                    // decode: element
                    error = decode_iso2_RelativeTimeIntervalType(stream, &PMaxScheduleEntryType->RelativeTimeInterval);
                    if (error == 0)
                    {
                        PMaxScheduleEntryType->RelativeTimeInterval_isUsed = 1u;
                        grammar_id = 79;
                    }
                    break;
                case 1:
                    // Event: START (TimeInterval, IntervalType (IntervalType)); next=79
                    // decode: element
                    error = decode_iso2_IntervalType(stream, &PMaxScheduleEntryType->TimeInterval);
                    if (error == 0)
                    {
                        PMaxScheduleEntryType->TimeInterval_isUsed = 1u;
                        grammar_id = 79;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 79:
            // Grammar: ID=79; read/write bits=1; START (PMax)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PMax, PhysicalValueType (PhysicalValueType)); next=3
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &PMaxScheduleEntryType->PMax);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}SalesTariffEntry; type={urn:iso:15118:2:2013:MsgDataTypes}SalesTariffEntryType; base type=EntryType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: RelativeTimeInterval, RelativeTimeIntervalType (0, 1); TimeInterval, IntervalType (0, 1); EPriceLevel, unsignedByte (0, 1); ConsumptionCost, ConsumptionCostType (0, 3);
static int decode_iso2_SalesTariffEntryType(exi_bitstream_t* stream, struct iso2_SalesTariffEntryType* SalesTariffEntryType) {
    int grammar_id = 80;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_SalesTariffEntryType(SalesTariffEntryType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 80:
            // Grammar: ID=80; read/write bits=2; START (RelativeTimeInterval), START (TimeInterval)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RelativeTimeInterval, RelativeTimeIntervalType (IntervalType)); next=81
                    // decode: element
                    error = decode_iso2_RelativeTimeIntervalType(stream, &SalesTariffEntryType->RelativeTimeInterval);
                    if (error == 0)
                    {
                        SalesTariffEntryType->RelativeTimeInterval_isUsed = 1u;
                        grammar_id = 81;
                    }
                    break;
                case 1:
                    // Event: START (TimeInterval, IntervalType (IntervalType)); next=81
                    // decode: element
                    error = decode_iso2_IntervalType(stream, &SalesTariffEntryType->TimeInterval);
                    if (error == 0)
                    {
                        SalesTariffEntryType->TimeInterval_isUsed = 1u;
                        grammar_id = 81;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 81:
            // Grammar: ID=81; read/write bits=2; END Element, START (EPriceLevel), START (ConsumptionCost)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EPriceLevel, unsignedByte (unsignedShort)); next=84
                    // decode: unsigned byte
                    error = decode_exi_type_uint8(stream, &SalesTariffEntryType->EPriceLevel);
                    if (error == 0)
                    {
                        SalesTariffEntryType->EPriceLevel_isUsed = 1u;
                        grammar_id = 84;
                    }
                    break;
                case 1:
                    // Event: START (ConsumptionCost, ConsumptionCostType (ConsumptionCostType)); next=3
                    // decode: element array
                    if (SalesTariffEntryType->ConsumptionCost.arrayLen < iso2_ConsumptionCostType_3_ARRAY_SIZE)
                    {
                        error = decode_iso2_ConsumptionCostType(stream, &SalesTariffEntryType->ConsumptionCost.array[SalesTariffEntryType->ConsumptionCost.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 2:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 82:
            // Grammar: ID=82; read/write bits=2; END Element, START (ConsumptionCost)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ConsumptionCost, ConsumptionCostType (ConsumptionCostType)); next=83
                    // decode: element array
                    if (SalesTariffEntryType->ConsumptionCost.arrayLen < iso2_ConsumptionCostType_3_ARRAY_SIZE)
                    {
                        error = decode_iso2_ConsumptionCostType(stream, &SalesTariffEntryType->ConsumptionCost.array[SalesTariffEntryType->ConsumptionCost.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 83;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 83:
            // Grammar: ID=83; read/write bits=2; END Element, START (ConsumptionCost)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ConsumptionCost, ConsumptionCostType (ConsumptionCostType)); next=84
                    // decode: element array
                    if (SalesTariffEntryType->ConsumptionCost.arrayLen < iso2_ConsumptionCostType_3_ARRAY_SIZE)
                    {
                        error = decode_iso2_ConsumptionCostType(stream, &SalesTariffEntryType->ConsumptionCost.array[SalesTariffEntryType->ConsumptionCost.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 84;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 84:
            // Grammar: ID=84; read/write bits=2; END Element, START (ConsumptionCost)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ConsumptionCost, ConsumptionCostType (ConsumptionCostType)); next=85
                    // decode: element array
                    if (SalesTariffEntryType->ConsumptionCost.arrayLen < iso2_ConsumptionCostType_3_ARRAY_SIZE)
                    {
                        error = decode_iso2_ConsumptionCostType(stream, &SalesTariffEntryType->ConsumptionCost.array[SalesTariffEntryType->ConsumptionCost.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 85;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 85:
            // Grammar: ID=85; read/write bits=2; END Element, START (ConsumptionCost)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ConsumptionCost, ConsumptionCostType (ConsumptionCostType)); next=86
                    // decode: element array
                    if (SalesTariffEntryType->ConsumptionCost.arrayLen < iso2_ConsumptionCostType_3_ARRAY_SIZE)
                    {
                        error = decode_iso2_ConsumptionCostType(stream, &SalesTariffEntryType->ConsumptionCost.array[SalesTariffEntryType->ConsumptionCost.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 86;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 86:
            // Grammar: ID=86; read/write bits=2; END Element, START (ConsumptionCost)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ConsumptionCost, ConsumptionCostType (ConsumptionCostType)); next=3
                    // decode: element array
                    if (SalesTariffEntryType->ConsumptionCost.arrayLen < iso2_ConsumptionCostType_3_ARRAY_SIZE)
                    {
                        error = decode_iso2_ConsumptionCostType(stream, &SalesTariffEntryType->ConsumptionCost.array[SalesTariffEntryType->ConsumptionCost.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}Parameter; type={urn:iso:15118:2:2013:MsgDataTypes}ParameterType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False; choice=True;
// Particle: Name, string (1, 1); boolValue, boolean (0, 1); byteValue, byte (0, 1); shortValue, short (0, 1); intValue, int (0, 1); physicalValue, PhysicalValueType (0, 1); stringValue, string (0, 1);
static int decode_iso2_ParameterType(exi_bitstream_t* stream, struct iso2_ParameterType* ParameterType) {
    int grammar_id = 87;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ParameterType(ParameterType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 87:
            // Grammar: ID=87; read/write bits=1; START (Name)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Name, string (string)); next=88
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ParameterType->Name.charactersLen);
                            if (error == 0)
                            {
                                if (ParameterType->Name.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ParameterType->Name.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ParameterType->Name.charactersLen, ParameterType->Name.characters, iso2_Name_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 88;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 88:
            // Grammar: ID=88; read/write bits=3; START (boolValue), START (byteValue), START (shortValue), START (intValue), START (physicalValue), START (stringValue)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (boolValue, boolean (boolean)); next=3
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ParameterType->boolValue = value;
                                ParameterType->boolValue_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (byteValue, byte (short)); next=3
                    // decode: byte
                    error = decode_exi_type_integer8(stream, &ParameterType->byteValue);
                    if (error == 0)
                    {
                        ParameterType->byteValue_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 2:
                    // Event: START (shortValue, short (int)); next=3
                    // decode: short
                    error = decode_exi_type_integer16(stream, &ParameterType->shortValue);
                    if (error == 0)
                    {
                        ParameterType->shortValue_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 3:
                    // Event: START (intValue, int (long)); next=3
                    // decode: int
                    error = decode_exi_type_integer32(stream, &ParameterType->intValue);
                    if (error == 0)
                    {
                        ParameterType->intValue_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 4:
                    // Event: START (physicalValue, PhysicalValueType (PhysicalValueType)); next=3
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &ParameterType->physicalValue);
                    if (error == 0)
                    {
                        ParameterType->physicalValue_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 5:
                    // Event: START (stringValue, string (string)); next=3
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ParameterType->stringValue.charactersLen);
                            if (error == 0)
                            {
                                if (ParameterType->stringValue.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ParameterType->stringValue.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ParameterType->stringValue.charactersLen, ParameterType->stringValue.characters, iso2_stringValue_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ParameterType->stringValue_isUsed = 1u;
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}PMaxSchedule; type={urn:iso:15118:2:2013:MsgDataTypes}PMaxScheduleType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: PMaxScheduleEntry, PMaxScheduleEntryType (1, 12);
static int decode_iso2_PMaxScheduleType(exi_bitstream_t* stream, struct iso2_PMaxScheduleType* PMaxScheduleType) {
    int grammar_id = 89;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_PMaxScheduleType(PMaxScheduleType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 89:
            // Grammar: ID=89; read/write bits=1; START (PMaxScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PMaxScheduleEntry, PMaxScheduleEntryType (EntryType)); next=90
                    // decode: element array
                    if (PMaxScheduleType->PMaxScheduleEntry.arrayLen < iso2_PMaxScheduleEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_PMaxScheduleEntryType(stream, &PMaxScheduleType->PMaxScheduleEntry.array[PMaxScheduleType->PMaxScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 90;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 90:
            // Grammar: ID=90; read/write bits=2; END Element, START (PMaxScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PMaxScheduleEntry, PMaxScheduleEntryType (EntryType)); next=91
                    // decode: element array
                    if (PMaxScheduleType->PMaxScheduleEntry.arrayLen < iso2_PMaxScheduleEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_PMaxScheduleEntryType(stream, &PMaxScheduleType->PMaxScheduleEntry.array[PMaxScheduleType->PMaxScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 91;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 91:
            // Grammar: ID=91; read/write bits=2; END Element, START (PMaxScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PMaxScheduleEntry, PMaxScheduleEntryType (EntryType)); next=92
                    // decode: element array
                    if (PMaxScheduleType->PMaxScheduleEntry.arrayLen < iso2_PMaxScheduleEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_PMaxScheduleEntryType(stream, &PMaxScheduleType->PMaxScheduleEntry.array[PMaxScheduleType->PMaxScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 92;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 92:
            // Grammar: ID=92; read/write bits=2; END Element, START (PMaxScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PMaxScheduleEntry, PMaxScheduleEntryType (EntryType)); next=93
                    // decode: element array
                    if (PMaxScheduleType->PMaxScheduleEntry.arrayLen < iso2_PMaxScheduleEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_PMaxScheduleEntryType(stream, &PMaxScheduleType->PMaxScheduleEntry.array[PMaxScheduleType->PMaxScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 93;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 93:
            // Grammar: ID=93; read/write bits=2; END Element, START (PMaxScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PMaxScheduleEntry, PMaxScheduleEntryType (EntryType)); next=94
                    // decode: element array
                    if (PMaxScheduleType->PMaxScheduleEntry.arrayLen < iso2_PMaxScheduleEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_PMaxScheduleEntryType(stream, &PMaxScheduleType->PMaxScheduleEntry.array[PMaxScheduleType->PMaxScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 94;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 94:
            // Grammar: ID=94; read/write bits=2; END Element, START (PMaxScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PMaxScheduleEntry, PMaxScheduleEntryType (EntryType)); next=95
                    // decode: element array
                    if (PMaxScheduleType->PMaxScheduleEntry.arrayLen < iso2_PMaxScheduleEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_PMaxScheduleEntryType(stream, &PMaxScheduleType->PMaxScheduleEntry.array[PMaxScheduleType->PMaxScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 95;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 95:
            // Grammar: ID=95; read/write bits=2; END Element, START (PMaxScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PMaxScheduleEntry, PMaxScheduleEntryType (EntryType)); next=96
                    // decode: element array
                    if (PMaxScheduleType->PMaxScheduleEntry.arrayLen < iso2_PMaxScheduleEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_PMaxScheduleEntryType(stream, &PMaxScheduleType->PMaxScheduleEntry.array[PMaxScheduleType->PMaxScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 96;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 96:
            // Grammar: ID=96; read/write bits=2; END Element, START (PMaxScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PMaxScheduleEntry, PMaxScheduleEntryType (EntryType)); next=97
                    // decode: element array
                    if (PMaxScheduleType->PMaxScheduleEntry.arrayLen < iso2_PMaxScheduleEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_PMaxScheduleEntryType(stream, &PMaxScheduleType->PMaxScheduleEntry.array[PMaxScheduleType->PMaxScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 97;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 97:
            // Grammar: ID=97; read/write bits=2; END Element, START (PMaxScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PMaxScheduleEntry, PMaxScheduleEntryType (EntryType)); next=98
                    // decode: element array
                    if (PMaxScheduleType->PMaxScheduleEntry.arrayLen < iso2_PMaxScheduleEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_PMaxScheduleEntryType(stream, &PMaxScheduleType->PMaxScheduleEntry.array[PMaxScheduleType->PMaxScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 98;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 98:
            // Grammar: ID=98; read/write bits=2; END Element, START (PMaxScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PMaxScheduleEntry, PMaxScheduleEntryType (EntryType)); next=99
                    // decode: element array
                    if (PMaxScheduleType->PMaxScheduleEntry.arrayLen < iso2_PMaxScheduleEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_PMaxScheduleEntryType(stream, &PMaxScheduleType->PMaxScheduleEntry.array[PMaxScheduleType->PMaxScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 99;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 99:
            // Grammar: ID=99; read/write bits=2; END Element, START (PMaxScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PMaxScheduleEntry, PMaxScheduleEntryType (EntryType)); next=100
                    // decode: element array
                    if (PMaxScheduleType->PMaxScheduleEntry.arrayLen < iso2_PMaxScheduleEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_PMaxScheduleEntryType(stream, &PMaxScheduleType->PMaxScheduleEntry.array[PMaxScheduleType->PMaxScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 100;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 100:
            // Grammar: ID=100; read/write bits=2; END Element, START (PMaxScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PMaxScheduleEntry, PMaxScheduleEntryType (EntryType)); next=3
                    // decode: element array
                    if (PMaxScheduleType->PMaxScheduleEntry.arrayLen < iso2_PMaxScheduleEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_PMaxScheduleEntryType(stream, &PMaxScheduleType->PMaxScheduleEntry.array[PMaxScheduleType->PMaxScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}SalesTariff; type={urn:iso:15118:2:2013:MsgDataTypes}SalesTariffType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); SalesTariffID, SAIDType (1, 1); SalesTariffDescription, tariffDescriptionType (0, 1); NumEPriceLevels, unsignedByte (0, 1); SalesTariffEntry, SalesTariffEntryType (1, 12);
static int decode_iso2_SalesTariffType(exi_bitstream_t* stream, struct iso2_SalesTariffType* SalesTariffType) {
    int grammar_id = 101;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_SalesTariffType(SalesTariffType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 101:
            // Grammar: ID=101; read/write bits=2; START (Id), START (SalesTariffID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=102
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &SalesTariffType->Id.charactersLen);
                            if (error == 0)
                            {
                                if (SalesTariffType->Id.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    SalesTariffType->Id.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, SalesTariffType->Id.charactersLen, SalesTariffType->Id.characters, iso2_Id_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                SalesTariffType->Id_isUsed = 1u;
                                grammar_id = 102;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (SalesTariffID, SAIDType (unsignedByte)); next=103
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                // type has min_value = 1
                                SalesTariffType->SalesTariffID = (uint8_t)(value + 1);
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 103;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 102:
            // Grammar: ID=102; read/write bits=1; START (SalesTariffID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffID, SAIDType (unsignedByte)); next=103
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                // type has min_value = 1
                                SalesTariffType->SalesTariffID = (uint8_t)(value + 1);
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 103;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 103:
            // Grammar: ID=103; read/write bits=2; START (SalesTariffDescription), START (NumEPriceLevels), START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffDescription, tariffDescriptionType (string)); next=115
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &SalesTariffType->SalesTariffDescription.charactersLen);
                            if (error == 0)
                            {
                                if (SalesTariffType->SalesTariffDescription.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    SalesTariffType->SalesTariffDescription.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, SalesTariffType->SalesTariffDescription.charactersLen, SalesTariffType->SalesTariffDescription.characters, iso2_SalesTariffDescription_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                SalesTariffType->SalesTariffDescription_isUsed = 1u;
                                grammar_id = 115;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (NumEPriceLevels, unsignedByte (unsignedShort)); next=127
                    // decode: unsigned byte
                    error = decode_exi_type_uint8(stream, &SalesTariffType->NumEPriceLevels);
                    if (error == 0)
                    {
                        SalesTariffType->NumEPriceLevels_isUsed = 1u;
                        grammar_id = 127;
                    }
                    break;
                case 2:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=3
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 104:
            // Grammar: ID=104; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=105
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 105;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 105:
            // Grammar: ID=105; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=106
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 106;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 106:
            // Grammar: ID=106; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=107
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 107;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 107:
            // Grammar: ID=107; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=108
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 108;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 108:
            // Grammar: ID=108; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=109
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 109;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 109:
            // Grammar: ID=109; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=110
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 110;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 110:
            // Grammar: ID=110; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=111
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 111;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 111:
            // Grammar: ID=111; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=112
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 112;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 112:
            // Grammar: ID=112; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=113
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 113;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 113:
            // Grammar: ID=113; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=114
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 114;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 114:
            // Grammar: ID=114; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=115
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 115;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 115:
            // Grammar: ID=115; read/write bits=2; START (NumEPriceLevels), START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (NumEPriceLevels, unsignedByte (unsignedShort)); next=127
                    // decode: unsigned byte
                    error = decode_exi_type_uint8(stream, &SalesTariffType->NumEPriceLevels);
                    if (error == 0)
                    {
                        SalesTariffType->NumEPriceLevels_isUsed = 1u;
                        grammar_id = 127;
                    }
                    break;
                case 1:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=3
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 116:
            // Grammar: ID=116; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=117
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 117;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 117:
            // Grammar: ID=117; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=118
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 118;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 118:
            // Grammar: ID=118; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=119
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 119;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 119:
            // Grammar: ID=119; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=120
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 120;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 120:
            // Grammar: ID=120; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=121
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 121;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 121:
            // Grammar: ID=121; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=122
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 122;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 122:
            // Grammar: ID=122; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=123
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 123;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 123:
            // Grammar: ID=123; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=124
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 124;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 124:
            // Grammar: ID=124; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=125
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 125;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 125:
            // Grammar: ID=125; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=126
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 126;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 126:
            // Grammar: ID=126; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=127
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 127;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 127:
            // Grammar: ID=127; read/write bits=1; START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=128
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 128;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 128:
            // Grammar: ID=128; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=129
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 129;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 129:
            // Grammar: ID=129; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=130
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 130;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 130:
            // Grammar: ID=130; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=131
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 131;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 131:
            // Grammar: ID=131; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=132
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 132;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 132:
            // Grammar: ID=132; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=133
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 133;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 133:
            // Grammar: ID=133; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=134
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 134;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 134:
            // Grammar: ID=134; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=135
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 135;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 135:
            // Grammar: ID=135; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=136
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 136;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 136:
            // Grammar: ID=136; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=137
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 137;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 137:
            // Grammar: ID=137; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=138
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 138;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 138:
            // Grammar: ID=138; read/write bits=2; END Element, START (SalesTariffEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariffEntry, SalesTariffEntryType (EntryType)); next=3
                    // decode: element array
                    if (SalesTariffType->SalesTariffEntry.arrayLen < iso2_SalesTariffEntryType_12_ARRAY_SIZE)
                    {
                        error = decode_iso2_SalesTariffEntryType(stream, &SalesTariffType->SalesTariffEntry.array[SalesTariffType->SalesTariffEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}ParameterSet; type={urn:iso:15118:2:2013:MsgDataTypes}ParameterSetType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: ParameterSetID, short (1, 1); Parameter, ParameterType (1, 16);
static int decode_iso2_ParameterSetType(exi_bitstream_t* stream, struct iso2_ParameterSetType* ParameterSetType) {
    int grammar_id = 139;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ParameterSetType(ParameterSetType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 139:
            // Grammar: ID=139; read/write bits=1; START (ParameterSetID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ParameterSetID, short (int)); next=140
                    // decode: short
                    error = decode_exi_type_integer16(stream, &ParameterSetType->ParameterSetID);
                    if (error == 0)
                    {
                        grammar_id = 140;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 140:
            // Grammar: ID=140; read/write bits=1; START (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Parameter, ParameterType (ParameterType)); next=141
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso2_ParameterType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 141;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 141:
            // Grammar: ID=141; read/write bits=2; END Element, START (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Parameter, ParameterType (ParameterType)); next=142
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso2_ParameterType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 142;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 142:
            // Grammar: ID=142; read/write bits=2; END Element, START (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Parameter, ParameterType (ParameterType)); next=143
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso2_ParameterType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 143;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 143:
            // Grammar: ID=143; read/write bits=2; END Element, START (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Parameter, ParameterType (ParameterType)); next=144
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso2_ParameterType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 144;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 144:
            // Grammar: ID=144; read/write bits=2; END Element, START (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Parameter, ParameterType (ParameterType)); next=145
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso2_ParameterType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 145;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 145:
            // Grammar: ID=145; read/write bits=2; END Element, START (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Parameter, ParameterType (ParameterType)); next=146
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso2_ParameterType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 146;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 146:
            // Grammar: ID=146; read/write bits=2; END Element, START (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Parameter, ParameterType (ParameterType)); next=147
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso2_ParameterType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 147;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 147:
            // Grammar: ID=147; read/write bits=2; END Element, START (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Parameter, ParameterType (ParameterType)); next=148
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso2_ParameterType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 148;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 148:
            // Grammar: ID=148; read/write bits=2; END Element, START (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Parameter, ParameterType (ParameterType)); next=149
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso2_ParameterType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 149;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 149:
            // Grammar: ID=149; read/write bits=2; END Element, START (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Parameter, ParameterType (ParameterType)); next=150
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso2_ParameterType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 150;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 150:
            // Grammar: ID=150; read/write bits=2; END Element, START (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Parameter, ParameterType (ParameterType)); next=151
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso2_ParameterType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 151;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 151:
            // Grammar: ID=151; read/write bits=2; END Element, START (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Parameter, ParameterType (ParameterType)); next=152
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso2_ParameterType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 152;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 152:
            // Grammar: ID=152; read/write bits=2; END Element, START (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Parameter, ParameterType (ParameterType)); next=153
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso2_ParameterType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 153;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 153:
            // Grammar: ID=153; read/write bits=2; END Element, START (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Parameter, ParameterType (ParameterType)); next=154
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso2_ParameterType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 154;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 154:
            // Grammar: ID=154; read/write bits=2; END Element, START (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Parameter, ParameterType (ParameterType)); next=155
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso2_ParameterType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 155;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 155:
            // Grammar: ID=155; read/write bits=2; END Element, START (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Parameter, ParameterType (ParameterType)); next=3
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso2_ParameterType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}SAScheduleTuple; type={urn:iso:15118:2:2013:MsgDataTypes}SAScheduleTupleType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: SAScheduleTupleID, SAIDType (1, 1); PMaxSchedule, PMaxScheduleType (1, 1); SalesTariff, SalesTariffType (0, 1);
static int decode_iso2_SAScheduleTupleType(exi_bitstream_t* stream, struct iso2_SAScheduleTupleType* SAScheduleTupleType) {
    int grammar_id = 156;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_SAScheduleTupleType(SAScheduleTupleType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 156:
            // Grammar: ID=156; read/write bits=1; START (SAScheduleTupleID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SAScheduleTupleID, SAIDType (unsignedByte)); next=157
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                // type has min_value = 1
                                SAScheduleTupleType->SAScheduleTupleID = (uint8_t)(value + 1);
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 157;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 157:
            // Grammar: ID=157; read/write bits=1; START (PMaxSchedule)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PMaxSchedule, PMaxScheduleType (PMaxScheduleType)); next=158
                    // decode: element
                    error = decode_iso2_PMaxScheduleType(stream, &SAScheduleTupleType->PMaxSchedule);
                    if (error == 0)
                    {
                        grammar_id = 158;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 158:
            // Grammar: ID=158; read/write bits=2; END Element, START (SalesTariff)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SalesTariff, SalesTariffType (SalesTariffType)); next=3
                    // decode: element
                    error = decode_iso2_SalesTariffType(stream, &SAScheduleTupleType->SalesTariff);
                    if (error == 0)
                    {
                        SAScheduleTupleType->SalesTariff_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}ProfileEntry; type={urn:iso:15118:2:2013:MsgDataTypes}ProfileEntryType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: ChargingProfileEntryStart, unsignedInt (1, 1); ChargingProfileEntryMaxPower, PhysicalValueType (1, 1); ChargingProfileEntryMaxNumberOfPhasesInUse, maxNumPhasesType (0, 1);
static int decode_iso2_ProfileEntryType(exi_bitstream_t* stream, struct iso2_ProfileEntryType* ProfileEntryType) {
    int grammar_id = 159;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ProfileEntryType(ProfileEntryType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 159:
            // Grammar: ID=159; read/write bits=1; START (ChargingProfileEntryStart)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ChargingProfileEntryStart, unsignedInt (unsignedLong)); next=160
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &ProfileEntryType->ChargingProfileEntryStart);
                    if (error == 0)
                    {
                        grammar_id = 160;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 160:
            // Grammar: ID=160; read/write bits=1; START (ChargingProfileEntryMaxPower)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ChargingProfileEntryMaxPower, PhysicalValueType (PhysicalValueType)); next=161
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &ProfileEntryType->ChargingProfileEntryMaxPower);
                    if (error == 0)
                    {
                        grammar_id = 161;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 161:
            // Grammar: ID=161; read/write bits=2; END Element, START (ChargingProfileEntryMaxNumberOfPhasesInUse)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ChargingProfileEntryMaxNumberOfPhasesInUse, maxNumPhasesType (byte)); next=3
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                // type has min_value = 1
                                ProfileEntryType->ChargingProfileEntryMaxNumberOfPhasesInUse = (int8_t)(value + 1);
                                ProfileEntryType->ChargingProfileEntryMaxNumberOfPhasesInUse_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Object; type={http://www.w3.org/2000/09/xmldsig#}ObjectType; base type=; content type=mixed;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); MimeType, string (0, 1); Encoding, anyURI (0, 1);
static int decode_iso2_ObjectType(exi_bitstream_t* stream, struct iso2_ObjectType* ObjectType) {
    int grammar_id = 162;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ObjectType(ObjectType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 162:
            // Grammar: ID=162; read/write bits=3; END Element, START (Id), START (MimeType), START (Encoding)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=163
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ObjectType->Id.charactersLen);
                            if (error == 0)
                            {
                                if (ObjectType->Id.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ObjectType->Id.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ObjectType->Id.charactersLen, ObjectType->Id.characters, iso2_Id_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ObjectType->Id_isUsed = 1u;
                                grammar_id = 163;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (MimeType, string (string)); next=164
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ObjectType->MimeType.charactersLen);
                            if (error == 0)
                            {
                                if (ObjectType->MimeType.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ObjectType->MimeType.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ObjectType->MimeType.charactersLen, ObjectType->MimeType.characters, iso2_MimeType_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ObjectType->MimeType_isUsed = 1u;
                                grammar_id = 164;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: START (Encoding, anyURI (anyURI)); next=3
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ObjectType->Encoding.charactersLen);
                            if (error == 0)
                            {
                                if (ObjectType->Encoding.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ObjectType->Encoding.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ObjectType->Encoding.charactersLen, ObjectType->Encoding.characters, iso2_Encoding_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ObjectType->Encoding_isUsed = 1u;
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 3:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 163:
            // Grammar: ID=163; read/write bits=2; END Element, START (MimeType), START (Encoding)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MimeType, string (string)); next=164
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ObjectType->MimeType.charactersLen);
                            if (error == 0)
                            {
                                if (ObjectType->MimeType.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ObjectType->MimeType.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ObjectType->MimeType.charactersLen, ObjectType->MimeType.characters, iso2_MimeType_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ObjectType->MimeType_isUsed = 1u;
                                grammar_id = 164;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (Encoding, anyURI (anyURI)); next=3
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ObjectType->Encoding.charactersLen);
                            if (error == 0)
                            {
                                if (ObjectType->Encoding.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ObjectType->Encoding.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ObjectType->Encoding.charactersLen, ObjectType->Encoding.characters, iso2_Encoding_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ObjectType->Encoding_isUsed = 1u;
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 164:
            // Grammar: ID=164; read/write bits=2; END Element, START (Encoding)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Encoding, anyURI (anyURI)); next=3
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ObjectType->Encoding.charactersLen);
                            if (error == 0)
                            {
                                if (ObjectType->Encoding.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ObjectType->Encoding.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ObjectType->Encoding.charactersLen, ObjectType->Encoding.characters, iso2_Encoding_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ObjectType->Encoding_isUsed = 1u;
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}SupportedEnergyTransferMode; type={urn:iso:15118:2:2013:MsgDataTypes}SupportedEnergyTransferModeType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EnergyTransferMode, EnergyTransferModeType (1, 6);
static int decode_iso2_SupportedEnergyTransferModeType(exi_bitstream_t* stream, struct iso2_SupportedEnergyTransferModeType* SupportedEnergyTransferModeType) {
    int grammar_id = 165;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_SupportedEnergyTransferModeType(SupportedEnergyTransferModeType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 165:
            // Grammar: ID=165; read/write bits=1; START (EnergyTransferMode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EnergyTransferMode, EnergyTransferModeType (string)); next=166
                    // decode: enum array
                    if (SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen < iso2_EnergyTransferModeType_6_ARRAY_SIZE)
                    {
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                uint32_t value;
                                error = exi_basetypes_decoder_nbit_uint(stream, 3, &value);
                                if (error == 0)
                                {
                                    SupportedEnergyTransferModeType->EnergyTransferMode.array[SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen] = (iso2_EnergyTransferModeType)value;
                                    SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen++;
                                }
                            }
                            else
                            {
                                // second level event is not supported
                                error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                            }
                        }
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 166;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 166:
            // Grammar: ID=166; read/write bits=2; END Element, START (EnergyTransferMode)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EnergyTransferMode, EnergyTransferModeType (string)); next=167
                    // decode: enum array
                    if (SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen < iso2_EnergyTransferModeType_6_ARRAY_SIZE)
                    {
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                uint32_t value;
                                error = exi_basetypes_decoder_nbit_uint(stream, 3, &value);
                                if (error == 0)
                                {
                                    SupportedEnergyTransferModeType->EnergyTransferMode.array[SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen] = (iso2_EnergyTransferModeType)value;
                                    SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen++;
                                }
                            }
                            else
                            {
                                // second level event is not supported
                                error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                            }
                        }
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 167;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 167:
            // Grammar: ID=167; read/write bits=2; END Element, START (EnergyTransferMode)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EnergyTransferMode, EnergyTransferModeType (string)); next=168
                    // decode: enum array
                    if (SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen < iso2_EnergyTransferModeType_6_ARRAY_SIZE)
                    {
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                uint32_t value;
                                error = exi_basetypes_decoder_nbit_uint(stream, 3, &value);
                                if (error == 0)
                                {
                                    SupportedEnergyTransferModeType->EnergyTransferMode.array[SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen] = (iso2_EnergyTransferModeType)value;
                                    SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen++;
                                }
                            }
                            else
                            {
                                // second level event is not supported
                                error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                            }
                        }
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 168;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 168:
            // Grammar: ID=168; read/write bits=2; END Element, START (EnergyTransferMode)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EnergyTransferMode, EnergyTransferModeType (string)); next=169
                    // decode: enum array
                    if (SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen < iso2_EnergyTransferModeType_6_ARRAY_SIZE)
                    {
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                uint32_t value;
                                error = exi_basetypes_decoder_nbit_uint(stream, 3, &value);
                                if (error == 0)
                                {
                                    SupportedEnergyTransferModeType->EnergyTransferMode.array[SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen] = (iso2_EnergyTransferModeType)value;
                                    SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen++;
                                }
                            }
                            else
                            {
                                // second level event is not supported
                                error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                            }
                        }
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 169;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 169:
            // Grammar: ID=169; read/write bits=2; END Element, START (EnergyTransferMode)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EnergyTransferMode, EnergyTransferModeType (string)); next=170
                    // decode: enum array
                    if (SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen < iso2_EnergyTransferModeType_6_ARRAY_SIZE)
                    {
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                uint32_t value;
                                error = exi_basetypes_decoder_nbit_uint(stream, 3, &value);
                                if (error == 0)
                                {
                                    SupportedEnergyTransferModeType->EnergyTransferMode.array[SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen] = (iso2_EnergyTransferModeType)value;
                                    SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen++;
                                }
                            }
                            else
                            {
                                // second level event is not supported
                                error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                            }
                        }
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 170;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 170:
            // Grammar: ID=170; read/write bits=2; END Element, START (EnergyTransferMode)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EnergyTransferMode, EnergyTransferModeType (string)); next=3
                    // decode: enum array
                    if (SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen < iso2_EnergyTransferModeType_6_ARRAY_SIZE)
                    {
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                uint32_t value;
                                error = exi_basetypes_decoder_nbit_uint(stream, 3, &value);
                                if (error == 0)
                                {
                                    SupportedEnergyTransferModeType->EnergyTransferMode.array[SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen] = (iso2_EnergyTransferModeType)value;
                                    SupportedEnergyTransferModeType->EnergyTransferMode.arrayLen++;
                                }
                            }
                            else
                            {
                                // second level event is not supported
                                error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                            }
                        }
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}ContractSignatureCertChain; type={urn:iso:15118:2:2013:MsgDataTypes}CertificateChainType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); Certificate, certificateType (1, 1); SubCertificates, SubCertificatesType (0, 1);
static int decode_iso2_CertificateChainType(exi_bitstream_t* stream, struct iso2_CertificateChainType* CertificateChainType) {
    int grammar_id = 171;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_CertificateChainType(CertificateChainType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 171:
            // Grammar: ID=171; read/write bits=2; START (Id), START (Certificate)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=172
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &CertificateChainType->Id.charactersLen);
                            if (error == 0)
                            {
                                if (CertificateChainType->Id.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    CertificateChainType->Id.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, CertificateChainType->Id.charactersLen, CertificateChainType->Id.characters, iso2_Id_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                CertificateChainType->Id_isUsed = 1u;
                                grammar_id = 172;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (Certificate, certificateType (base64Binary)); next=173
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &CertificateChainType->Certificate.bytesLen, &CertificateChainType->Certificate.bytes[0], iso2_certificateType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 173;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 172:
            // Grammar: ID=172; read/write bits=1; START (Certificate)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Certificate, certificateType (base64Binary)); next=173
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &CertificateChainType->Certificate.bytesLen, &CertificateChainType->Certificate.bytes[0], iso2_certificateType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 173;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 173:
            // Grammar: ID=173; read/write bits=2; END Element, START (SubCertificates)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SubCertificates, SubCertificatesType (SubCertificatesType)); next=3
                    // decode: element
                    error = decode_iso2_SubCertificatesType(stream, &CertificateChainType->SubCertificates);
                    if (error == 0)
                    {
                        CertificateChainType->SubCertificates_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}BodyElement; type={urn:iso:15118:2:2013:MsgBody}BodyBaseType; base type=; content type=empty;
//          abstract=True; final=False;
static int decode_iso2_BodyBaseType(exi_bitstream_t* stream, struct iso2_BodyBaseType* BodyBaseType) {
    // Element has no particles, so the function just returns zero
    (void)stream;
    (void)BodyBaseType;

    return 0;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgHeader}Notification; type={urn:iso:15118:2:2013:MsgDataTypes}NotificationType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: FaultCode, faultCodeType (1, 1); FaultMsg, faultMsgType (0, 1);
static int decode_iso2_NotificationType(exi_bitstream_t* stream, struct iso2_NotificationType* NotificationType) {
    int grammar_id = 174;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_NotificationType(NotificationType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 174:
            // Grammar: ID=174; read/write bits=1; START (FaultCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (FaultCode, faultCodeType (string)); next=175
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                NotificationType->FaultCode = (iso2_faultCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 175;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 175:
            // Grammar: ID=175; read/write bits=2; END Element, START (FaultMsg)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (FaultMsg, faultMsgType (string)); next=3
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &NotificationType->FaultMsg.charactersLen);
                            if (error == 0)
                            {
                                if (NotificationType->FaultMsg.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    NotificationType->FaultMsg.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, NotificationType->FaultMsg.charactersLen, NotificationType->FaultMsg.characters, iso2_FaultMsg_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                NotificationType->FaultMsg_isUsed = 1u;
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}SelectedServiceList; type={urn:iso:15118:2:2013:MsgDataTypes}SelectedServiceListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: SelectedService, SelectedServiceType (1, 16);
static int decode_iso2_SelectedServiceListType(exi_bitstream_t* stream, struct iso2_SelectedServiceListType* SelectedServiceListType) {
    int grammar_id = 176;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_SelectedServiceListType(SelectedServiceListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 176:
            // Grammar: ID=176; read/write bits=1; START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=177
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso2_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 177;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 177:
            // Grammar: ID=177; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=178
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso2_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 178;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 178:
            // Grammar: ID=178; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=179
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso2_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 179;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 179:
            // Grammar: ID=179; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=180
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso2_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 180;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 180:
            // Grammar: ID=180; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=181
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso2_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 181;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 181:
            // Grammar: ID=181; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=182
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso2_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 182;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 182:
            // Grammar: ID=182; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=183
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso2_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 183;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 183:
            // Grammar: ID=183; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=184
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso2_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 184;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 184:
            // Grammar: ID=184; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=185
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso2_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 185;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 185:
            // Grammar: ID=185; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=186
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso2_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 186;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 186:
            // Grammar: ID=186; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=187
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso2_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 187;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 187:
            // Grammar: ID=187; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=188
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso2_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 188;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 188:
            // Grammar: ID=188; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=189
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso2_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 189;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 189:
            // Grammar: ID=189; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=190
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso2_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 190;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 190:
            // Grammar: ID=190; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=191
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso2_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 191;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 191:
            // Grammar: ID=191; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=3
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso2_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso2_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}EVSEStatus; type={urn:iso:15118:2:2013:MsgDataTypes}EVSEStatusType; base type=; content type=ELEMENT-ONLY;
//          abstract=True; final=False;
// Particle: NotificationMaxDelay, unsignedShort (1, 1); EVSENotification, EVSENotificationType (1, 1); DC_EVSEStatus, DC_EVSEStatusType (1, 1); AC_EVSEStatus, AC_EVSEStatusType (1, 1);
static int decode_iso2_EVSEStatusType(exi_bitstream_t* stream, struct iso2_EVSEStatusType* EVSEStatusType) {
    int grammar_id = 192;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_EVSEStatusType(EVSEStatusType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 192:
            // Grammar: ID=192; read/write bits=1; START (NotificationMaxDelay)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (NotificationMaxDelay, unsignedShort (unsignedInt)); next=193
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &EVSEStatusType->NotificationMaxDelay);
                    if (error == 0)
                    {
                        grammar_id = 193;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 193:
            // Grammar: ID=193; read/write bits=1; START (EVSENotification)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSENotification, EVSENotificationType (string)); next=194
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                EVSEStatusType->EVSENotification = (iso2_EVSENotificationType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 194;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 194:
            // Grammar: ID=194; read/write bits=1; START (DC_EVSEStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DC_EVSEStatus, DC_EVSEStatusType (EVSEStatusType)); next=195
                    // decode: element
                    error = decode_iso2_DC_EVSEStatusType(stream, &EVSEStatusType->DC_EVSEStatus);
                    if (error == 0)
                    {
                        grammar_id = 195;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 195:
            // Grammar: ID=195; read/write bits=1; START (AC_EVSEStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AC_EVSEStatus, AC_EVSEStatusType (EVSEStatusType)); next=3
                    // decode: element
                    error = decode_iso2_AC_EVSEStatusType(stream, &EVSEStatusType->AC_EVSEStatus);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}PaymentOptionList; type={urn:iso:15118:2:2013:MsgDataTypes}PaymentOptionListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: PaymentOption, paymentOptionType (1, 2);
static int decode_iso2_PaymentOptionListType(exi_bitstream_t* stream, struct iso2_PaymentOptionListType* PaymentOptionListType) {
    int grammar_id = 196;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_PaymentOptionListType(PaymentOptionListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 196:
            // Grammar: ID=196; read/write bits=1; START (PaymentOption)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PaymentOption, paymentOptionType (string)); next=197
                    // decode: enum array
                    if (PaymentOptionListType->PaymentOption.arrayLen < iso2_paymentOptionType_2_ARRAY_SIZE)
                    {
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                uint32_t value;
                                error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                                if (error == 0)
                                {
                                    PaymentOptionListType->PaymentOption.array[PaymentOptionListType->PaymentOption.arrayLen] = (iso2_paymentOptionType)value;
                                    PaymentOptionListType->PaymentOption.arrayLen++;
                                }
                            }
                            else
                            {
                                // second level event is not supported
                                error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                            }
                        }
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 197;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 197:
            // Grammar: ID=197; read/write bits=2; END Element, START (PaymentOption)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PaymentOption, paymentOptionType (string)); next=3
                    // decode: enum array
                    if (PaymentOptionListType->PaymentOption.arrayLen < iso2_paymentOptionType_2_ARRAY_SIZE)
                    {
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                uint32_t value;
                                error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                                if (error == 0)
                                {
                                    PaymentOptionListType->PaymentOption.array[PaymentOptionListType->PaymentOption.arrayLen] = (iso2_paymentOptionType)value;
                                    PaymentOptionListType->PaymentOption.arrayLen++;
                                }
                            }
                            else
                            {
                                // second level event is not supported
                                error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                            }
                        }
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Signature; type={http://www.w3.org/2000/09/xmldsig#}SignatureType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); SignedInfo, SignedInfoType (1, 1); SignatureValue, SignatureValueType (1, 1); KeyInfo, KeyInfoType (0, 1); Object, ObjectType (0, 1);
static int decode_iso2_SignatureType(exi_bitstream_t* stream, struct iso2_SignatureType* SignatureType) {
    int grammar_id = 198;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_SignatureType(SignatureType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 198:
            // Grammar: ID=198; read/write bits=2; START (Id), START (SignedInfo)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=199
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &SignatureType->Id.charactersLen);
                            if (error == 0)
                            {
                                if (SignatureType->Id.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    SignatureType->Id.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, SignatureType->Id.charactersLen, SignatureType->Id.characters, iso2_Id_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                SignatureType->Id_isUsed = 1u;
                                grammar_id = 199;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (SignedInfo, SignedInfoType (SignedInfoType)); next=200
                    // decode: element
                    error = decode_iso2_SignedInfoType(stream, &SignatureType->SignedInfo);
                    if (error == 0)
                    {
                        grammar_id = 200;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 199:
            // Grammar: ID=199; read/write bits=1; START (SignedInfo)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SignedInfo, SignedInfoType (SignedInfoType)); next=200
                    // decode: element
                    error = decode_iso2_SignedInfoType(stream, &SignatureType->SignedInfo);
                    if (error == 0)
                    {
                        grammar_id = 200;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 200:
            // Grammar: ID=200; read/write bits=1; START (SignatureValue)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SignatureValue, SignatureValueType (base64Binary)); next=201
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SignatureType->SignatureValue.CONTENT.bytesLen, &SignatureType->SignatureValue.CONTENT.bytes[0], iso2_SignatureValueType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 201;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 201:
            // Grammar: ID=201; read/write bits=2; END Element, START (KeyInfo), START (Object)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (KeyInfo, KeyInfoType (KeyInfoType)); next=203
                    // decode: element
                    error = decode_iso2_KeyInfoType(stream, &SignatureType->KeyInfo);
                    if (error == 0)
                    {
                        SignatureType->KeyInfo_isUsed = 1u;
                        grammar_id = 203;
                    }
                    break;
                case 1:
                    // Event: START (Object, ObjectType (ObjectType)); next=3
                    // decode: element
                    error = decode_iso2_ObjectType(stream, &SignatureType->Object);
                    if (error == 0)
                    {
                        SignatureType->Object_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 202:
            // Grammar: ID=202; read/write bits=2; END Element, START (Object)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Object, ObjectType (ObjectType)); next=203
                    // decode: element
                    error = decode_iso2_ObjectType(stream, &SignatureType->Object);
                    if (error == 0)
                    {
                        SignatureType->Object_isUsed = 1u;
                        grammar_id = 203;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 203:
            // Grammar: ID=203; read/write bits=2; END Element, START (Object)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Object, ObjectType (ObjectType)); next=204
                    // decode: element
                    error = decode_iso2_ObjectType(stream, &SignatureType->Object);
                    if (error == 0)
                    {
                        SignatureType->Object_isUsed = 1u;
                        grammar_id = 204;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 204:
            // Grammar: ID=204; read/write bits=2; END Element, START (Object)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Object, ObjectType (ObjectType)); next=3
                    // decode: element
                    error = decode_iso2_ObjectType(stream, &SignatureType->Object);
                    if (error == 0)
                    {
                        SignatureType->Object_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}DC_EVChargeParameter; type={urn:iso:15118:2:2013:MsgDataTypes}DC_EVChargeParameterType; base type=EVChargeParameterType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DepartureTime, unsignedInt (0, 1); DC_EVStatus, DC_EVStatusType (1, 1); EVMaximumCurrentLimit, PhysicalValueType (1, 1); EVMaximumPowerLimit, PhysicalValueType (0, 1); EVMaximumVoltageLimit, PhysicalValueType (1, 1); EVEnergyCapacity, PhysicalValueType (0, 1); EVEnergyRequest, PhysicalValueType (0, 1); FullSOC, percentValueType (0, 1); BulkSOC, percentValueType (0, 1);
static int decode_iso2_DC_EVChargeParameterType(exi_bitstream_t* stream, struct iso2_DC_EVChargeParameterType* DC_EVChargeParameterType) {
    int grammar_id = 205;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_DC_EVChargeParameterType(DC_EVChargeParameterType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 205:
            // Grammar: ID=205; read/write bits=2; START (DepartureTime), START (DC_EVStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DepartureTime, unsignedInt (unsignedLong)); next=206
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &DC_EVChargeParameterType->DepartureTime);
                    if (error == 0)
                    {
                        DC_EVChargeParameterType->DepartureTime_isUsed = 1u;
                        grammar_id = 206;
                    }
                    break;
                case 1:
                    // Event: START (DC_EVStatus, DC_EVStatusType (EVStatusType)); next=207
                    // decode: element
                    error = decode_iso2_DC_EVStatusType(stream, &DC_EVChargeParameterType->DC_EVStatus);
                    if (error == 0)
                    {
                        grammar_id = 207;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 206:
            // Grammar: ID=206; read/write bits=1; START (DC_EVStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DC_EVStatus, DC_EVStatusType (EVStatusType)); next=207
                    // decode: element
                    error = decode_iso2_DC_EVStatusType(stream, &DC_EVChargeParameterType->DC_EVStatus);
                    if (error == 0)
                    {
                        grammar_id = 207;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 207:
            // Grammar: ID=207; read/write bits=1; START (EVMaximumCurrentLimit)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVMaximumCurrentLimit, PhysicalValueType (PhysicalValueType)); next=208
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &DC_EVChargeParameterType->EVMaximumCurrentLimit);
                    if (error == 0)
                    {
                        grammar_id = 208;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 208:
            // Grammar: ID=208; read/write bits=2; START (EVMaximumPowerLimit), START (EVMaximumVoltageLimit)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVMaximumPowerLimit, PhysicalValueType (PhysicalValueType)); next=209
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &DC_EVChargeParameterType->EVMaximumPowerLimit);
                    if (error == 0)
                    {
                        DC_EVChargeParameterType->EVMaximumPowerLimit_isUsed = 1u;
                        grammar_id = 209;
                    }
                    break;
                case 1:
                    // Event: START (EVMaximumVoltageLimit, PhysicalValueType (PhysicalValueType)); next=210
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &DC_EVChargeParameterType->EVMaximumVoltageLimit);
                    if (error == 0)
                    {
                        grammar_id = 210;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 209:
            // Grammar: ID=209; read/write bits=1; START (EVMaximumVoltageLimit)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVMaximumVoltageLimit, PhysicalValueType (PhysicalValueType)); next=210
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &DC_EVChargeParameterType->EVMaximumVoltageLimit);
                    if (error == 0)
                    {
                        grammar_id = 210;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 210:
            // Grammar: ID=210; read/write bits=3; END Element, START (EVEnergyCapacity), START (EVEnergyRequest), START (FullSOC), START (BulkSOC)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVEnergyCapacity, PhysicalValueType (PhysicalValueType)); next=211
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &DC_EVChargeParameterType->EVEnergyCapacity);
                    if (error == 0)
                    {
                        DC_EVChargeParameterType->EVEnergyCapacity_isUsed = 1u;
                        grammar_id = 211;
                    }
                    break;
                case 1:
                    // Event: START (EVEnergyRequest, PhysicalValueType (PhysicalValueType)); next=212
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &DC_EVChargeParameterType->EVEnergyRequest);
                    if (error == 0)
                    {
                        DC_EVChargeParameterType->EVEnergyRequest_isUsed = 1u;
                        grammar_id = 212;
                    }
                    break;
                case 2:
                    // Event: START (FullSOC, percentValueType (byte)); next=213
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                DC_EVChargeParameterType->FullSOC = (int8_t)value;
                                DC_EVChargeParameterType->FullSOC_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 213;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 3:
                    // Event: START (BulkSOC, percentValueType (byte)); next=3
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                DC_EVChargeParameterType->BulkSOC = (int8_t)value;
                                DC_EVChargeParameterType->BulkSOC_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 4:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 211:
            // Grammar: ID=211; read/write bits=3; END Element, START (EVEnergyRequest), START (FullSOC), START (BulkSOC)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVEnergyRequest, PhysicalValueType (PhysicalValueType)); next=212
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &DC_EVChargeParameterType->EVEnergyRequest);
                    if (error == 0)
                    {
                        DC_EVChargeParameterType->EVEnergyRequest_isUsed = 1u;
                        grammar_id = 212;
                    }
                    break;
                case 1:
                    // Event: START (FullSOC, percentValueType (byte)); next=213
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                DC_EVChargeParameterType->FullSOC = (int8_t)value;
                                DC_EVChargeParameterType->FullSOC_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 213;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: START (BulkSOC, percentValueType (byte)); next=3
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                DC_EVChargeParameterType->BulkSOC = (int8_t)value;
                                DC_EVChargeParameterType->BulkSOC_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 3:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 212:
            // Grammar: ID=212; read/write bits=2; END Element, START (FullSOC), START (BulkSOC)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (FullSOC, percentValueType (byte)); next=213
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                DC_EVChargeParameterType->FullSOC = (int8_t)value;
                                DC_EVChargeParameterType->FullSOC_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 213;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (BulkSOC, percentValueType (byte)); next=3
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                DC_EVChargeParameterType->BulkSOC = (int8_t)value;
                                DC_EVChargeParameterType->BulkSOC_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 213:
            // Grammar: ID=213; read/write bits=2; END Element, START (BulkSOC)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (BulkSOC, percentValueType (byte)); next=3
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                DC_EVChargeParameterType->BulkSOC = (int8_t)value;
                                DC_EVChargeParameterType->BulkSOC_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}AC_EVChargeParameter; type={urn:iso:15118:2:2013:MsgDataTypes}AC_EVChargeParameterType; base type=EVChargeParameterType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DepartureTime, unsignedInt (0, 1); EAmount, PhysicalValueType (1, 1); EVMaxVoltage, PhysicalValueType (1, 1); EVMaxCurrent, PhysicalValueType (1, 1); EVMinCurrent, PhysicalValueType (1, 1);
static int decode_iso2_AC_EVChargeParameterType(exi_bitstream_t* stream, struct iso2_AC_EVChargeParameterType* AC_EVChargeParameterType) {
    int grammar_id = 214;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_AC_EVChargeParameterType(AC_EVChargeParameterType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 214:
            // Grammar: ID=214; read/write bits=2; START (DepartureTime), START (EAmount)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DepartureTime, unsignedInt (unsignedLong)); next=215
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &AC_EVChargeParameterType->DepartureTime);
                    if (error == 0)
                    {
                        AC_EVChargeParameterType->DepartureTime_isUsed = 1u;
                        grammar_id = 215;
                    }
                    break;
                case 1:
                    // Event: START (EAmount, PhysicalValueType (PhysicalValueType)); next=216
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &AC_EVChargeParameterType->EAmount);
                    if (error == 0)
                    {
                        grammar_id = 216;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 215:
            // Grammar: ID=215; read/write bits=1; START (EAmount)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EAmount, PhysicalValueType (PhysicalValueType)); next=216
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &AC_EVChargeParameterType->EAmount);
                    if (error == 0)
                    {
                        grammar_id = 216;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 216:
            // Grammar: ID=216; read/write bits=1; START (EVMaxVoltage)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVMaxVoltage, PhysicalValueType (PhysicalValueType)); next=217
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &AC_EVChargeParameterType->EVMaxVoltage);
                    if (error == 0)
                    {
                        grammar_id = 217;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 217:
            // Grammar: ID=217; read/write bits=1; START (EVMaxCurrent)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVMaxCurrent, PhysicalValueType (PhysicalValueType)); next=218
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &AC_EVChargeParameterType->EVMaxCurrent);
                    if (error == 0)
                    {
                        grammar_id = 218;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 218:
            // Grammar: ID=218; read/write bits=1; START (EVMinCurrent)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVMinCurrent, PhysicalValueType (PhysicalValueType)); next=3
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &AC_EVChargeParameterType->EVMinCurrent);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}EVChargeParameter; type={urn:iso:15118:2:2013:MsgDataTypes}EVChargeParameterType; base type=; content type=ELEMENT-ONLY;
//          abstract=True; final=False;
// Particle: DepartureTime, unsignedInt (0, 1); DC_EVChargeParameter, DC_EVChargeParameterType (1, 1); AC_EVChargeParameter, AC_EVChargeParameterType (1, 1);
static int decode_iso2_EVChargeParameterType(exi_bitstream_t* stream, struct iso2_EVChargeParameterType* EVChargeParameterType) {
    int grammar_id = 219;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_EVChargeParameterType(EVChargeParameterType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 219:
            // Grammar: ID=219; read/write bits=2; START (DepartureTime), START (DC_EVChargeParameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DepartureTime, unsignedInt (unsignedLong)); next=220
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &EVChargeParameterType->DepartureTime);
                    if (error == 0)
                    {
                        EVChargeParameterType->DepartureTime_isUsed = 1u;
                        grammar_id = 220;
                    }
                    break;
                case 1:
                    // Event: START (DC_EVChargeParameter, DC_EVChargeParameterType (EVChargeParameterType)); next=221
                    // decode: element
                    error = decode_iso2_DC_EVChargeParameterType(stream, &EVChargeParameterType->DC_EVChargeParameter);
                    if (error == 0)
                    {
                        grammar_id = 221;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 220:
            // Grammar: ID=220; read/write bits=1; START (DC_EVChargeParameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DC_EVChargeParameter, DC_EVChargeParameterType (EVChargeParameterType)); next=221
                    // decode: element
                    error = decode_iso2_DC_EVChargeParameterType(stream, &EVChargeParameterType->DC_EVChargeParameter);
                    if (error == 0)
                    {
                        grammar_id = 221;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 221:
            // Grammar: ID=221; read/write bits=1; START (AC_EVChargeParameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AC_EVChargeParameter, AC_EVChargeParameterType (EVChargeParameterType)); next=3
                    // decode: element
                    error = decode_iso2_AC_EVChargeParameterType(stream, &EVChargeParameterType->AC_EVChargeParameter);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}ListOfRootCertificateIDs; type={urn:iso:15118:2:2013:MsgDataTypes}ListOfRootCertificateIDsType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: RootCertificateID, X509IssuerSerialType (1, 5);
static int decode_iso2_ListOfRootCertificateIDsType(exi_bitstream_t* stream, struct iso2_ListOfRootCertificateIDsType* ListOfRootCertificateIDsType) {
    int grammar_id = 222;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ListOfRootCertificateIDsType(ListOfRootCertificateIDsType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 222:
            // Grammar: ID=222; read/write bits=1; START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=223
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso2_X509IssuerSerialType_5_ARRAY_SIZE)
                    {
                        error = decode_iso2_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 223;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 223:
            // Grammar: ID=223; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=224
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso2_X509IssuerSerialType_5_ARRAY_SIZE)
                    {
                        error = decode_iso2_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 224;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 224:
            // Grammar: ID=224; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=225
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso2_X509IssuerSerialType_5_ARRAY_SIZE)
                    {
                        error = decode_iso2_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 225;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 225:
            // Grammar: ID=225; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=226
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso2_X509IssuerSerialType_5_ARRAY_SIZE)
                    {
                        error = decode_iso2_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 226;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 226:
            // Grammar: ID=226; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=3
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso2_X509IssuerSerialType_5_ARRAY_SIZE)
                    {
                        error = decode_iso2_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}ServiceParameterList; type={urn:iso:15118:2:2013:MsgDataTypes}ServiceParameterListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: ParameterSet, ParameterSetType (1, 5);
static int decode_iso2_ServiceParameterListType(exi_bitstream_t* stream, struct iso2_ServiceParameterListType* ServiceParameterListType) {
    int grammar_id = 227;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ServiceParameterListType(ServiceParameterListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 227:
            // Grammar: ID=227; read/write bits=1; START (ParameterSet)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ParameterSet, ParameterSetType (ParameterSetType)); next=228
                    // decode: element array
                    if (ServiceParameterListType->ParameterSet.arrayLen < iso2_ParameterSetType_5_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterSetType(stream, &ServiceParameterListType->ParameterSet.array[ServiceParameterListType->ParameterSet.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 228;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 228:
            // Grammar: ID=228; read/write bits=2; END Element, START (ParameterSet)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ParameterSet, ParameterSetType (ParameterSetType)); next=229
                    // decode: element array
                    if (ServiceParameterListType->ParameterSet.arrayLen < iso2_ParameterSetType_5_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterSetType(stream, &ServiceParameterListType->ParameterSet.array[ServiceParameterListType->ParameterSet.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 229;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 229:
            // Grammar: ID=229; read/write bits=2; END Element, START (ParameterSet)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ParameterSet, ParameterSetType (ParameterSetType)); next=230
                    // decode: element array
                    if (ServiceParameterListType->ParameterSet.arrayLen < iso2_ParameterSetType_5_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterSetType(stream, &ServiceParameterListType->ParameterSet.array[ServiceParameterListType->ParameterSet.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 230;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 230:
            // Grammar: ID=230; read/write bits=2; END Element, START (ParameterSet)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ParameterSet, ParameterSetType (ParameterSetType)); next=231
                    // decode: element array
                    if (ServiceParameterListType->ParameterSet.arrayLen < iso2_ParameterSetType_5_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterSetType(stream, &ServiceParameterListType->ParameterSet.array[ServiceParameterListType->ParameterSet.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 231;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 231:
            // Grammar: ID=231; read/write bits=2; END Element, START (ParameterSet)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ParameterSet, ParameterSetType (ParameterSetType)); next=3
                    // decode: element array
                    if (ServiceParameterListType->ParameterSet.arrayLen < iso2_ParameterSetType_5_ARRAY_SIZE)
                    {
                        error = decode_iso2_ParameterSetType(stream, &ServiceParameterListType->ParameterSet.array[ServiceParameterListType->ParameterSet.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}SASchedules; type={urn:iso:15118:2:2013:MsgDataTypes}SASchedulesType; base type=; content type=empty;
//          abstract=True; final=False;
static int decode_iso2_SASchedulesType(exi_bitstream_t* stream, struct iso2_SASchedulesType* SASchedulesType) {
    // Element has no particles, so the function just returns zero
    (void)stream;
    (void)SASchedulesType;

    return 0;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}SAScheduleList; type={urn:iso:15118:2:2013:MsgDataTypes}SAScheduleListType; base type=SASchedulesType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: SAScheduleTuple, SAScheduleTupleType (1, 3);
static int decode_iso2_SAScheduleListType(exi_bitstream_t* stream, struct iso2_SAScheduleListType* SAScheduleListType) {
    int grammar_id = 232;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_SAScheduleListType(SAScheduleListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 232:
            // Grammar: ID=232; read/write bits=1; START (SAScheduleTuple)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SAScheduleTuple, SAScheduleTupleType (SAScheduleTupleType)); next=233
                    // decode: element array
                    if (SAScheduleListType->SAScheduleTuple.arrayLen < iso2_SAScheduleTupleType_3_ARRAY_SIZE)
                    {
                        error = decode_iso2_SAScheduleTupleType(stream, &SAScheduleListType->SAScheduleTuple.array[SAScheduleListType->SAScheduleTuple.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 233;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 233:
            // Grammar: ID=233; read/write bits=2; END Element, START (SAScheduleTuple)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SAScheduleTuple, SAScheduleTupleType (SAScheduleTupleType)); next=234
                    // decode: element array
                    if (SAScheduleListType->SAScheduleTuple.arrayLen < iso2_SAScheduleTupleType_3_ARRAY_SIZE)
                    {
                        error = decode_iso2_SAScheduleTupleType(stream, &SAScheduleListType->SAScheduleTuple.array[SAScheduleListType->SAScheduleTuple.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 234;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 234:
            // Grammar: ID=234; read/write bits=2; END Element, START (SAScheduleTuple)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SAScheduleTuple, SAScheduleTupleType (SAScheduleTupleType)); next=3
                    // decode: element array
                    if (SAScheduleListType->SAScheduleTuple.arrayLen < iso2_SAScheduleTupleType_3_ARRAY_SIZE)
                    {
                        error = decode_iso2_SAScheduleTupleType(stream, &SAScheduleListType->SAScheduleTuple.array[SAScheduleListType->SAScheduleTuple.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}ChargingProfile; type={urn:iso:15118:2:2013:MsgDataTypes}ChargingProfileType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: ProfileEntry, ProfileEntryType (1, 24);
static int decode_iso2_ChargingProfileType(exi_bitstream_t* stream, struct iso2_ChargingProfileType* ChargingProfileType) {
    int grammar_id = 235;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ChargingProfileType(ChargingProfileType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 235:
            // Grammar: ID=235; read/write bits=1; START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=236
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 236;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 236:
            // Grammar: ID=236; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=237
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 237;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 237:
            // Grammar: ID=237; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=238
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 238;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 238:
            // Grammar: ID=238; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=239
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 239;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 239:
            // Grammar: ID=239; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=240
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 240;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 240:
            // Grammar: ID=240; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=241
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 241;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 241:
            // Grammar: ID=241; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=242
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 242;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 242:
            // Grammar: ID=242; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=243
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 243;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 243:
            // Grammar: ID=243; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=244
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 244;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 244:
            // Grammar: ID=244; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=245
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 245;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 245:
            // Grammar: ID=245; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=246
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 246;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 246:
            // Grammar: ID=246; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=247
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 247;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 247:
            // Grammar: ID=247; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=248
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 248;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 248:
            // Grammar: ID=248; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=249
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 249;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 249:
            // Grammar: ID=249; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=250
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 250;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 250:
            // Grammar: ID=250; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=251
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 251;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 251:
            // Grammar: ID=251; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=252
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 252;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 252:
            // Grammar: ID=252; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=253
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 253;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 253:
            // Grammar: ID=253; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=254
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 254;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 254:
            // Grammar: ID=254; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=255
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 255;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 255:
            // Grammar: ID=255; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=256
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 256;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 256:
            // Grammar: ID=256; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=257
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 257;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 257:
            // Grammar: ID=257; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=258
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 258;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 258:
            // Grammar: ID=258; read/write bits=2; END Element, START (ProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProfileEntry, ProfileEntryType (ProfileEntryType)); next=3
                    // decode: element array
                    if (ChargingProfileType->ProfileEntry.arrayLen < iso2_ProfileEntryType_24_ARRAY_SIZE)
                    {
                        error = decode_iso2_ProfileEntryType(stream, &ChargingProfileType->ProfileEntry.array[ChargingProfileType->ProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}ChargeService; type={urn:iso:15118:2:2013:MsgDataTypes}ChargeServiceType; base type=ServiceType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ServiceID, serviceIDType (1, 1); ServiceName, serviceNameType (0, 1); ServiceCategory, serviceCategoryType (1, 1); ServiceScope, serviceScopeType (0, 1); FreeService, boolean (1, 1); SupportedEnergyTransferMode, SupportedEnergyTransferModeType (1, 1);
static int decode_iso2_ChargeServiceType(exi_bitstream_t* stream, struct iso2_ChargeServiceType* ChargeServiceType) {
    int grammar_id = 259;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ChargeServiceType(ChargeServiceType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 259:
            // Grammar: ID=259; read/write bits=1; START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=260
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &ChargeServiceType->ServiceID);
                    if (error == 0)
                    {
                        grammar_id = 260;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 260:
            // Grammar: ID=260; read/write bits=2; START (ServiceName), START (ServiceCategory)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceName, serviceNameType (string)); next=261
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ChargeServiceType->ServiceName.charactersLen);
                            if (error == 0)
                            {
                                if (ChargeServiceType->ServiceName.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ChargeServiceType->ServiceName.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ChargeServiceType->ServiceName.charactersLen, ChargeServiceType->ServiceName.characters, iso2_ServiceName_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ChargeServiceType->ServiceName_isUsed = 1u;
                                grammar_id = 261;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (ServiceCategory, serviceCategoryType (string)); next=262
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                ChargeServiceType->ServiceCategory = (iso2_serviceCategoryType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 262;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 261:
            // Grammar: ID=261; read/write bits=1; START (ServiceCategory)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceCategory, serviceCategoryType (string)); next=262
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                ChargeServiceType->ServiceCategory = (iso2_serviceCategoryType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 262;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 262:
            // Grammar: ID=262; read/write bits=2; START (ServiceScope), START (FreeService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceScope, serviceScopeType (string)); next=263
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ChargeServiceType->ServiceScope.charactersLen);
                            if (error == 0)
                            {
                                if (ChargeServiceType->ServiceScope.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ChargeServiceType->ServiceScope.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ChargeServiceType->ServiceScope.charactersLen, ChargeServiceType->ServiceScope.characters, iso2_ServiceScope_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ChargeServiceType->ServiceScope_isUsed = 1u;
                                grammar_id = 263;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (FreeService, boolean (boolean)); next=264
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ChargeServiceType->FreeService = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 264;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 263:
            // Grammar: ID=263; read/write bits=1; START (FreeService)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (FreeService, boolean (boolean)); next=264
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ChargeServiceType->FreeService = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 264;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 264:
            // Grammar: ID=264; read/write bits=1; START (SupportedEnergyTransferMode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SupportedEnergyTransferMode, SupportedEnergyTransferModeType (SupportedEnergyTransferModeType)); next=3
                    // decode: element
                    error = decode_iso2_SupportedEnergyTransferModeType(stream, &ChargeServiceType->SupportedEnergyTransferMode);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}EVSEChargeParameter; type={urn:iso:15118:2:2013:MsgDataTypes}EVSEChargeParameterType; base type=; content type=empty;
//          abstract=True; final=False;
static int decode_iso2_EVSEChargeParameterType(exi_bitstream_t* stream, struct iso2_EVSEChargeParameterType* EVSEChargeParameterType) {
    // Element has no particles, so the function just returns zero
    (void)stream;
    (void)EVSEChargeParameterType;

    return 0;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEChargeParameter; type={urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEChargeParameterType; base type=EVSEChargeParameterType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DC_EVSEStatus, DC_EVSEStatusType (1, 1); EVSEMaximumCurrentLimit, PhysicalValueType (1, 1); EVSEMaximumPowerLimit, PhysicalValueType (1, 1); EVSEMaximumVoltageLimit, PhysicalValueType (1, 1); EVSEMinimumCurrentLimit, PhysicalValueType (1, 1); EVSEMinimumVoltageLimit, PhysicalValueType (1, 1); EVSECurrentRegulationTolerance, PhysicalValueType (0, 1); EVSEPeakCurrentRipple, PhysicalValueType (1, 1); EVSEEnergyToBeDelivered, PhysicalValueType (0, 1);
static int decode_iso2_DC_EVSEChargeParameterType(exi_bitstream_t* stream, struct iso2_DC_EVSEChargeParameterType* DC_EVSEChargeParameterType) {
    int grammar_id = 265;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_DC_EVSEChargeParameterType(DC_EVSEChargeParameterType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 265:
            // Grammar: ID=265; read/write bits=1; START (DC_EVSEStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DC_EVSEStatus, DC_EVSEStatusType (EVSEStatusType)); next=266
                    // decode: element
                    error = decode_iso2_DC_EVSEStatusType(stream, &DC_EVSEChargeParameterType->DC_EVSEStatus);
                    if (error == 0)
                    {
                        grammar_id = 266;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 266:
            // Grammar: ID=266; read/write bits=1; START (EVSEMaximumCurrentLimit)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEMaximumCurrentLimit, PhysicalValueType (PhysicalValueType)); next=267
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &DC_EVSEChargeParameterType->EVSEMaximumCurrentLimit);
                    if (error == 0)
                    {
                        grammar_id = 267;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 267:
            // Grammar: ID=267; read/write bits=1; START (EVSEMaximumPowerLimit)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEMaximumPowerLimit, PhysicalValueType (PhysicalValueType)); next=268
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &DC_EVSEChargeParameterType->EVSEMaximumPowerLimit);
                    if (error == 0)
                    {
                        grammar_id = 268;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 268:
            // Grammar: ID=268; read/write bits=1; START (EVSEMaximumVoltageLimit)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEMaximumVoltageLimit, PhysicalValueType (PhysicalValueType)); next=269
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &DC_EVSEChargeParameterType->EVSEMaximumVoltageLimit);
                    if (error == 0)
                    {
                        grammar_id = 269;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 269:
            // Grammar: ID=269; read/write bits=1; START (EVSEMinimumCurrentLimit)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEMinimumCurrentLimit, PhysicalValueType (PhysicalValueType)); next=270
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &DC_EVSEChargeParameterType->EVSEMinimumCurrentLimit);
                    if (error == 0)
                    {
                        grammar_id = 270;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 270:
            // Grammar: ID=270; read/write bits=1; START (EVSEMinimumVoltageLimit)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEMinimumVoltageLimit, PhysicalValueType (PhysicalValueType)); next=271
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &DC_EVSEChargeParameterType->EVSEMinimumVoltageLimit);
                    if (error == 0)
                    {
                        grammar_id = 271;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 271:
            // Grammar: ID=271; read/write bits=2; START (EVSECurrentRegulationTolerance), START (EVSEPeakCurrentRipple)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSECurrentRegulationTolerance, PhysicalValueType (PhysicalValueType)); next=272
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &DC_EVSEChargeParameterType->EVSECurrentRegulationTolerance);
                    if (error == 0)
                    {
                        DC_EVSEChargeParameterType->EVSECurrentRegulationTolerance_isUsed = 1u;
                        grammar_id = 272;
                    }
                    break;
                case 1:
                    // Event: START (EVSEPeakCurrentRipple, PhysicalValueType (PhysicalValueType)); next=273
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &DC_EVSEChargeParameterType->EVSEPeakCurrentRipple);
                    if (error == 0)
                    {
                        grammar_id = 273;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 272:
            // Grammar: ID=272; read/write bits=1; START (EVSEPeakCurrentRipple)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEPeakCurrentRipple, PhysicalValueType (PhysicalValueType)); next=273
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &DC_EVSEChargeParameterType->EVSEPeakCurrentRipple);
                    if (error == 0)
                    {
                        grammar_id = 273;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 273:
            // Grammar: ID=273; read/write bits=2; END Element, START (EVSEEnergyToBeDelivered)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEEnergyToBeDelivered, PhysicalValueType (PhysicalValueType)); next=3
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &DC_EVSEChargeParameterType->EVSEEnergyToBeDelivered);
                    if (error == 0)
                    {
                        DC_EVSEChargeParameterType->EVSEEnergyToBeDelivered_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEChargeParameter; type={urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEChargeParameterType; base type=EVSEChargeParameterType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: AC_EVSEStatus, AC_EVSEStatusType (1, 1); EVSENominalVoltage, PhysicalValueType (1, 1); EVSEMaxCurrent, PhysicalValueType (1, 1);
static int decode_iso2_AC_EVSEChargeParameterType(exi_bitstream_t* stream, struct iso2_AC_EVSEChargeParameterType* AC_EVSEChargeParameterType) {
    int grammar_id = 274;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_AC_EVSEChargeParameterType(AC_EVSEChargeParameterType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 274:
            // Grammar: ID=274; read/write bits=1; START (AC_EVSEStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AC_EVSEStatus, AC_EVSEStatusType (EVSEStatusType)); next=275
                    // decode: element
                    error = decode_iso2_AC_EVSEStatusType(stream, &AC_EVSEChargeParameterType->AC_EVSEStatus);
                    if (error == 0)
                    {
                        grammar_id = 275;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 275:
            // Grammar: ID=275; read/write bits=1; START (EVSENominalVoltage)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSENominalVoltage, PhysicalValueType (PhysicalValueType)); next=276
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &AC_EVSEChargeParameterType->EVSENominalVoltage);
                    if (error == 0)
                    {
                        grammar_id = 276;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 276:
            // Grammar: ID=276; read/write bits=1; START (EVSEMaxCurrent)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEMaxCurrent, PhysicalValueType (PhysicalValueType)); next=3
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &AC_EVSEChargeParameterType->EVSEMaxCurrent);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}ContractSignatureEncryptedPrivateKey; type={urn:iso:15118:2:2013:MsgDataTypes}ContractSignatureEncryptedPrivateKeyType; base type=privateKeyType; content type=simple;
//          abstract=False; final=False; derivation=extension;
// Particle: Id, ID (1, 1); CONTENT, ContractSignatureEncryptedPrivateKeyType (1, 1);
static int decode_iso2_ContractSignatureEncryptedPrivateKeyType(exi_bitstream_t* stream, struct iso2_ContractSignatureEncryptedPrivateKeyType* ContractSignatureEncryptedPrivateKeyType) {
    int grammar_id = 277;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ContractSignatureEncryptedPrivateKeyType(ContractSignatureEncryptedPrivateKeyType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 277:
            // Grammar: ID=277; read/write bits=1; START (Id)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=278
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ContractSignatureEncryptedPrivateKeyType->Id.charactersLen);
                            if (error == 0)
                            {
                                if (ContractSignatureEncryptedPrivateKeyType->Id.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ContractSignatureEncryptedPrivateKeyType->Id.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ContractSignatureEncryptedPrivateKeyType->Id.charactersLen, ContractSignatureEncryptedPrivateKeyType->Id.characters, iso2_Id_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 278;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 278:
            // Grammar: ID=278; read/write bits=1; START (CONTENT)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (CONTENT, ContractSignatureEncryptedPrivateKeyType (base64Binary)); next=3
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &ContractSignatureEncryptedPrivateKeyType->CONTENT.bytesLen, &ContractSignatureEncryptedPrivateKeyType->CONTENT.bytes[0], iso2_ContractSignatureEncryptedPrivateKeyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}EVPowerDeliveryParameter; type={urn:iso:15118:2:2013:MsgDataTypes}EVPowerDeliveryParameterType; base type=; content type=empty;
//          abstract=True; final=False;
static int decode_iso2_EVPowerDeliveryParameterType(exi_bitstream_t* stream, struct iso2_EVPowerDeliveryParameterType* EVPowerDeliveryParameterType) {
    // Element has no particles, so the function just returns zero
    (void)stream;
    (void)EVPowerDeliveryParameterType;

    return 0;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDataTypes}DC_EVPowerDeliveryParameter; type={urn:iso:15118:2:2013:MsgDataTypes}DC_EVPowerDeliveryParameterType; base type=EVPowerDeliveryParameterType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DC_EVStatus, DC_EVStatusType (1, 1); BulkChargingComplete, boolean (0, 1); ChargingComplete, boolean (1, 1);
static int decode_iso2_DC_EVPowerDeliveryParameterType(exi_bitstream_t* stream, struct iso2_DC_EVPowerDeliveryParameterType* DC_EVPowerDeliveryParameterType) {
    int grammar_id = 279;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_DC_EVPowerDeliveryParameterType(DC_EVPowerDeliveryParameterType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 279:
            // Grammar: ID=279; read/write bits=1; START (DC_EVStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DC_EVStatus, DC_EVStatusType (EVStatusType)); next=280
                    // decode: element
                    error = decode_iso2_DC_EVStatusType(stream, &DC_EVPowerDeliveryParameterType->DC_EVStatus);
                    if (error == 0)
                    {
                        grammar_id = 280;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 280:
            // Grammar: ID=280; read/write bits=2; START (BulkChargingComplete), START (ChargingComplete)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (BulkChargingComplete, boolean (boolean)); next=281
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                DC_EVPowerDeliveryParameterType->BulkChargingComplete = value;
                                DC_EVPowerDeliveryParameterType->BulkChargingComplete_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 281;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (ChargingComplete, boolean (boolean)); next=3
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                DC_EVPowerDeliveryParameterType->ChargingComplete = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 281:
            // Grammar: ID=281; read/write bits=1; START (ChargingComplete)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ChargingComplete, boolean (boolean)); next=3
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                DC_EVPowerDeliveryParameterType->ChargingComplete = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}ServiceList; type={urn:iso:15118:2:2013:MsgDataTypes}ServiceListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Service, ServiceType (1, 8);
static int decode_iso2_ServiceListType(exi_bitstream_t* stream, struct iso2_ServiceListType* ServiceListType) {
    int grammar_id = 282;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ServiceListType(ServiceListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 282:
            // Grammar: ID=282; read/write bits=1; START (Service)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Service, ServiceType (ServiceType)); next=283
                    // decode: element array
                    if (ServiceListType->Service.arrayLen < iso2_ServiceType_8_ARRAY_SIZE)
                    {
                        error = decode_iso2_ServiceType(stream, &ServiceListType->Service.array[ServiceListType->Service.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 283;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 283:
            // Grammar: ID=283; read/write bits=2; END Element, START (Service)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Service, ServiceType (ServiceType)); next=284
                    // decode: element array
                    if (ServiceListType->Service.arrayLen < iso2_ServiceType_8_ARRAY_SIZE)
                    {
                        error = decode_iso2_ServiceType(stream, &ServiceListType->Service.array[ServiceListType->Service.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 284;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 284:
            // Grammar: ID=284; read/write bits=2; END Element, START (Service)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Service, ServiceType (ServiceType)); next=285
                    // decode: element array
                    if (ServiceListType->Service.arrayLen < iso2_ServiceType_8_ARRAY_SIZE)
                    {
                        error = decode_iso2_ServiceType(stream, &ServiceListType->Service.array[ServiceListType->Service.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 285;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 285:
            // Grammar: ID=285; read/write bits=2; END Element, START (Service)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Service, ServiceType (ServiceType)); next=286
                    // decode: element array
                    if (ServiceListType->Service.arrayLen < iso2_ServiceType_8_ARRAY_SIZE)
                    {
                        error = decode_iso2_ServiceType(stream, &ServiceListType->Service.array[ServiceListType->Service.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 286;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 286:
            // Grammar: ID=286; read/write bits=2; END Element, START (Service)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Service, ServiceType (ServiceType)); next=287
                    // decode: element array
                    if (ServiceListType->Service.arrayLen < iso2_ServiceType_8_ARRAY_SIZE)
                    {
                        error = decode_iso2_ServiceType(stream, &ServiceListType->Service.array[ServiceListType->Service.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 287;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 287:
            // Grammar: ID=287; read/write bits=2; END Element, START (Service)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Service, ServiceType (ServiceType)); next=288
                    // decode: element array
                    if (ServiceListType->Service.arrayLen < iso2_ServiceType_8_ARRAY_SIZE)
                    {
                        error = decode_iso2_ServiceType(stream, &ServiceListType->Service.array[ServiceListType->Service.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 288;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 288:
            // Grammar: ID=288; read/write bits=2; END Element, START (Service)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Service, ServiceType (ServiceType)); next=289
                    // decode: element array
                    if (ServiceListType->Service.arrayLen < iso2_ServiceType_8_ARRAY_SIZE)
                    {
                        error = decode_iso2_ServiceType(stream, &ServiceListType->Service.array[ServiceListType->Service.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 289;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 289:
            // Grammar: ID=289; read/write bits=2; END Element, START (Service)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Service, ServiceType (ServiceType)); next=3
                    // decode: element array
                    if (ServiceListType->Service.arrayLen < iso2_ServiceType_8_ARRAY_SIZE)
                    {
                        error = decode_iso2_ServiceType(stream, &ServiceListType->Service.array[ServiceListType->Service.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}DHpublickey; type={urn:iso:15118:2:2013:MsgDataTypes}DiffieHellmanPublickeyType; base type=dHpublickeyType; content type=simple;
//          abstract=False; final=False; derivation=extension;
// Particle: Id, ID (1, 1); CONTENT, DiffieHellmanPublickeyType (1, 1);
static int decode_iso2_DiffieHellmanPublickeyType(exi_bitstream_t* stream, struct iso2_DiffieHellmanPublickeyType* DiffieHellmanPublickeyType) {
    int grammar_id = 290;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_DiffieHellmanPublickeyType(DiffieHellmanPublickeyType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 290:
            // Grammar: ID=290; read/write bits=1; START (Id)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=291
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &DiffieHellmanPublickeyType->Id.charactersLen);
                            if (error == 0)
                            {
                                if (DiffieHellmanPublickeyType->Id.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    DiffieHellmanPublickeyType->Id.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, DiffieHellmanPublickeyType->Id.charactersLen, DiffieHellmanPublickeyType->Id.characters, iso2_Id_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 291;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 291:
            // Grammar: ID=291; read/write bits=1; START (CONTENT)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (CONTENT, DiffieHellmanPublickeyType (base64Binary)); next=3
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DiffieHellmanPublickeyType->CONTENT.bytesLen, &DiffieHellmanPublickeyType->CONTENT.bytes[0], iso2_DiffieHellmanPublickeyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}eMAID; type={urn:iso:15118:2:2013:MsgDataTypes}EMAIDType; base type=eMAIDType; content type=simple;
//          abstract=False; final=False; derivation=extension;
// Particle: Id, ID (1, 1); CONTENT, EMAIDType (1, 1);
static int decode_iso2_EMAIDType(exi_bitstream_t* stream, struct iso2_EMAIDType* EMAIDType) {
    int grammar_id = 292;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_EMAIDType(EMAIDType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 292:
            // Grammar: ID=292; read/write bits=1; START (Id)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=293
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &EMAIDType->Id.charactersLen);
                            if (error == 0)
                            {
                                if (EMAIDType->Id.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    EMAIDType->Id.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, EMAIDType->Id.charactersLen, EMAIDType->Id.characters, iso2_Id_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 293;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 293:
            // Grammar: ID=293; read/write bits=1; START (CONTENT)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (CONTENT, EMAIDType (string)); next=3
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &EMAIDType->CONTENT.charactersLen);
                            if (error == 0)
                            {
                                if (EMAIDType->CONTENT.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    EMAIDType->CONTENT.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, EMAIDType->CONTENT.charactersLen, EMAIDType->CONTENT.characters, iso2_CONTENT_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}MeterInfo; type={urn:iso:15118:2:2013:MsgDataTypes}MeterInfoType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: MeterID, meterIDType (1, 1); MeterReading, unsignedLong (0, 1); SigMeterReading, sigMeterReadingType (0, 1); MeterStatus, meterStatusType (0, 1); TMeter, long (0, 1);
static int decode_iso2_MeterInfoType(exi_bitstream_t* stream, struct iso2_MeterInfoType* MeterInfoType) {
    int grammar_id = 294;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_MeterInfoType(MeterInfoType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 294:
            // Grammar: ID=294; read/write bits=1; START (MeterID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MeterID, meterIDType (string)); next=295
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &MeterInfoType->MeterID.charactersLen);
                            if (error == 0)
                            {
                                if (MeterInfoType->MeterID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    MeterInfoType->MeterID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, MeterInfoType->MeterID.charactersLen, MeterInfoType->MeterID.characters, iso2_MeterID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 295;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 295:
            // Grammar: ID=295; read/write bits=3; END Element, START (MeterReading), START (SigMeterReading), START (MeterStatus), START (TMeter)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MeterReading, unsignedLong (nonNegativeInteger)); next=296
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &MeterInfoType->MeterReading);
                    if (error == 0)
                    {
                        MeterInfoType->MeterReading_isUsed = 1u;
                        grammar_id = 296;
                    }
                    break;
                case 1:
                    // Event: START (SigMeterReading, sigMeterReadingType (base64Binary)); next=297
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &MeterInfoType->SigMeterReading.bytesLen, &MeterInfoType->SigMeterReading.bytes[0], iso2_sigMeterReadingType_BYTES_SIZE);
                    if (error == 0)
                    {
                        MeterInfoType->SigMeterReading_isUsed = 1u;
                        grammar_id = 297;
                    }
                    break;
                case 2:
                    // Event: START (MeterStatus, meterStatusType (short)); next=298
                    // decode: short
                    error = decode_exi_type_integer16(stream, &MeterInfoType->MeterStatus);
                    if (error == 0)
                    {
                        MeterInfoType->MeterStatus_isUsed = 1u;
                        grammar_id = 298;
                    }
                    break;
                case 3:
                    // Event: START (TMeter, long (integer)); next=3
                    // decode: long int
                    error = decode_exi_type_integer64(stream, &MeterInfoType->TMeter);
                    if (error == 0)
                    {
                        MeterInfoType->TMeter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 4:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 296:
            // Grammar: ID=296; read/write bits=3; END Element, START (SigMeterReading), START (MeterStatus), START (TMeter)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SigMeterReading, sigMeterReadingType (base64Binary)); next=297
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &MeterInfoType->SigMeterReading.bytesLen, &MeterInfoType->SigMeterReading.bytes[0], iso2_sigMeterReadingType_BYTES_SIZE);
                    if (error == 0)
                    {
                        MeterInfoType->SigMeterReading_isUsed = 1u;
                        grammar_id = 297;
                    }
                    break;
                case 1:
                    // Event: START (MeterStatus, meterStatusType (short)); next=298
                    // decode: short
                    error = decode_exi_type_integer16(stream, &MeterInfoType->MeterStatus);
                    if (error == 0)
                    {
                        MeterInfoType->MeterStatus_isUsed = 1u;
                        grammar_id = 298;
                    }
                    break;
                case 2:
                    // Event: START (TMeter, long (integer)); next=3
                    // decode: long int
                    error = decode_exi_type_integer64(stream, &MeterInfoType->TMeter);
                    if (error == 0)
                    {
                        MeterInfoType->TMeter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 3:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 297:
            // Grammar: ID=297; read/write bits=2; END Element, START (MeterStatus), START (TMeter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MeterStatus, meterStatusType (short)); next=298
                    // decode: short
                    error = decode_exi_type_integer16(stream, &MeterInfoType->MeterStatus);
                    if (error == 0)
                    {
                        MeterInfoType->MeterStatus_isUsed = 1u;
                        grammar_id = 298;
                    }
                    break;
                case 1:
                    // Event: START (TMeter, long (integer)); next=3
                    // decode: long int
                    error = decode_exi_type_integer64(stream, &MeterInfoType->TMeter);
                    if (error == 0)
                    {
                        MeterInfoType->TMeter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 298:
            // Grammar: ID=298; read/write bits=2; END Element, START (TMeter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TMeter, long (integer)); next=3
                    // decode: long int
                    error = decode_exi_type_integer64(stream, &MeterInfoType->TMeter);
                    if (error == 0)
                    {
                        MeterInfoType->TMeter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDef}Header; type={urn:iso:15118:2:2013:MsgHeader}MessageHeaderType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: SessionID, sessionIDType (1, 1); Notification, NotificationType (0, 1); Signature, SignatureType (0, 1);
static int decode_iso2_MessageHeaderType(exi_bitstream_t* stream, struct iso2_MessageHeaderType* MessageHeaderType) {
    int grammar_id = 299;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_MessageHeaderType(MessageHeaderType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 299:
            // Grammar: ID=299; read/write bits=1; START (SessionID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SessionID, sessionIDType (hexBinary)); next=300
                    // decode exi type: hexBinary
                    error = decode_exi_type_hex_binary(stream, &MessageHeaderType->SessionID.bytesLen, &MessageHeaderType->SessionID.bytes[0], iso2_sessionIDType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 300;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 300:
            // Grammar: ID=300; read/write bits=2; END Element, START (Notification), START (Signature)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Notification, NotificationType (NotificationType)); next=301
                    // decode: element
                    error = decode_iso2_NotificationType(stream, &MessageHeaderType->Notification);
                    if (error == 0)
                    {
                        MessageHeaderType->Notification_isUsed = 1u;
                        grammar_id = 301;
                    }
                    break;
                case 1:
                    // Event: START (Signature, SignatureType (SignatureType)); next=3
                    // decode: element
                    error = decode_iso2_SignatureType(stream, &MessageHeaderType->Signature);
                    if (error == 0)
                    {
                        MessageHeaderType->Signature_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 301:
            // Grammar: ID=301; read/write bits=2; END Element, START (Signature)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Signature, SignatureType (SignatureType)); next=3
                    // decode: element
                    error = decode_iso2_SignatureType(stream, &MessageHeaderType->Signature);
                    if (error == 0)
                    {
                        MessageHeaderType->Signature_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}ServiceDetailReq; type={urn:iso:15118:2:2013:MsgBody}ServiceDetailReqType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ServiceID, serviceIDType (1, 1);
static int decode_iso2_ServiceDetailReqType(exi_bitstream_t* stream, struct iso2_ServiceDetailReqType* ServiceDetailReqType) {
    int grammar_id = 302;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ServiceDetailReqType(ServiceDetailReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 302:
            // Grammar: ID=302; read/write bits=1; START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=3
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &ServiceDetailReqType->ServiceID);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}ChargeParameterDiscoveryReq; type={urn:iso:15118:2:2013:MsgBody}ChargeParameterDiscoveryReqType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: MaxEntriesSAScheduleTuple, unsignedShort (0, 1); RequestedEnergyTransferMode, EnergyTransferModeType (1, 1); AC_EVChargeParameter, AC_EVChargeParameterType (0, 1); DC_EVChargeParameter, DC_EVChargeParameterType (0, 1); EVChargeParameter, EVChargeParameterType (0, 1);
static int decode_iso2_ChargeParameterDiscoveryReqType(exi_bitstream_t* stream, struct iso2_ChargeParameterDiscoveryReqType* ChargeParameterDiscoveryReqType) {
    int grammar_id = 303;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ChargeParameterDiscoveryReqType(ChargeParameterDiscoveryReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 303:
            // Grammar: ID=303; read/write bits=2; START (MaxEntriesSAScheduleTuple), START (RequestedEnergyTransferMode)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MaxEntriesSAScheduleTuple, unsignedShort (unsignedInt)); next=304
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &ChargeParameterDiscoveryReqType->MaxEntriesSAScheduleTuple);
                    if (error == 0)
                    {
                        ChargeParameterDiscoveryReqType->MaxEntriesSAScheduleTuple_isUsed = 1u;
                        grammar_id = 304;
                    }
                    break;
                case 1:
                    // Event: START (RequestedEnergyTransferMode, EnergyTransferModeType (string)); next=305
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 3, &value);
                            if (error == 0)
                            {
                                ChargeParameterDiscoveryReqType->RequestedEnergyTransferMode = (iso2_EnergyTransferModeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 305;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 304:
            // Grammar: ID=304; read/write bits=1; START (RequestedEnergyTransferMode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RequestedEnergyTransferMode, EnergyTransferModeType (string)); next=305
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 3, &value);
                            if (error == 0)
                            {
                                ChargeParameterDiscoveryReqType->RequestedEnergyTransferMode = (iso2_EnergyTransferModeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 305;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 305:
            // Grammar: ID=305; read/write bits=2; START (AC_EVChargeParameter), START (DC_EVChargeParameter), START (EVChargeParameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AC_EVChargeParameter, AC_EVChargeParameterType (EVChargeParameterType)); next=3
                    // decode: element
                    error = decode_iso2_AC_EVChargeParameterType(stream, &ChargeParameterDiscoveryReqType->AC_EVChargeParameter);
                    if (error == 0)
                    {
                        ChargeParameterDiscoveryReqType->AC_EVChargeParameter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: START (DC_EVChargeParameter, DC_EVChargeParameterType (EVChargeParameterType)); next=3
                    // decode: element
                    error = decode_iso2_DC_EVChargeParameterType(stream, &ChargeParameterDiscoveryReqType->DC_EVChargeParameter);
                    if (error == 0)
                    {
                        ChargeParameterDiscoveryReqType->DC_EVChargeParameter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 2:
                    // Event: START (EVChargeParameter, EVChargeParameterType (EVChargeParameterType)); next=3
                    // decode: element
                    error = decode_iso2_EVChargeParameterType(stream, &ChargeParameterDiscoveryReqType->EVChargeParameter);
                    if (error == 0)
                    {
                        ChargeParameterDiscoveryReqType->EVChargeParameter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}CertificateUpdateReq; type={urn:iso:15118:2:2013:MsgBody}CertificateUpdateReqType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Id, ID (1, 1); ContractSignatureCertChain, CertificateChainType (1, 1); eMAID, eMAIDType (1, 1); ListOfRootCertificateIDs, ListOfRootCertificateIDsType (1, 1);
static int decode_iso2_CertificateUpdateReqType(exi_bitstream_t* stream, struct iso2_CertificateUpdateReqType* CertificateUpdateReqType) {
    int grammar_id = 306;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_CertificateUpdateReqType(CertificateUpdateReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 306:
            // Grammar: ID=306; read/write bits=1; START (Id)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=307
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &CertificateUpdateReqType->Id.charactersLen);
                            if (error == 0)
                            {
                                if (CertificateUpdateReqType->Id.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    CertificateUpdateReqType->Id.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, CertificateUpdateReqType->Id.charactersLen, CertificateUpdateReqType->Id.characters, iso2_Id_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 307;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 307:
            // Grammar: ID=307; read/write bits=1; START (ContractSignatureCertChain)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ContractSignatureCertChain, CertificateChainType (CertificateChainType)); next=308
                    // decode: element
                    error = decode_iso2_CertificateChainType(stream, &CertificateUpdateReqType->ContractSignatureCertChain);
                    if (error == 0)
                    {
                        grammar_id = 308;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 308:
            // Grammar: ID=308; read/write bits=1; START (eMAID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (eMAID, eMAIDType (string)); next=309
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &CertificateUpdateReqType->eMAID.charactersLen);
                            if (error == 0)
                            {
                                if (CertificateUpdateReqType->eMAID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    CertificateUpdateReqType->eMAID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, CertificateUpdateReqType->eMAID.charactersLen, CertificateUpdateReqType->eMAID.characters, iso2_eMAID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 309;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 309:
            // Grammar: ID=309; read/write bits=1; START (ListOfRootCertificateIDs)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ListOfRootCertificateIDs, ListOfRootCertificateIDsType (ListOfRootCertificateIDsType)); next=3
                    // decode: element
                    error = decode_iso2_ListOfRootCertificateIDsType(stream, &CertificateUpdateReqType->ListOfRootCertificateIDs);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}PreChargeReq; type={urn:iso:15118:2:2013:MsgBody}PreChargeReqType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DC_EVStatus, DC_EVStatusType (1, 1); EVTargetVoltage, PhysicalValueType (1, 1); EVTargetCurrent, PhysicalValueType (1, 1);
static int decode_iso2_PreChargeReqType(exi_bitstream_t* stream, struct iso2_PreChargeReqType* PreChargeReqType) {
    int grammar_id = 310;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_PreChargeReqType(PreChargeReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 310:
            // Grammar: ID=310; read/write bits=1; START (DC_EVStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DC_EVStatus, DC_EVStatusType (EVStatusType)); next=311
                    // decode: element
                    error = decode_iso2_DC_EVStatusType(stream, &PreChargeReqType->DC_EVStatus);
                    if (error == 0)
                    {
                        grammar_id = 311;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 311:
            // Grammar: ID=311; read/write bits=1; START (EVTargetVoltage)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVTargetVoltage, PhysicalValueType (PhysicalValueType)); next=312
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &PreChargeReqType->EVTargetVoltage);
                    if (error == 0)
                    {
                        grammar_id = 312;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 312:
            // Grammar: ID=312; read/write bits=1; START (EVTargetCurrent)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVTargetCurrent, PhysicalValueType (PhysicalValueType)); next=3
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &PreChargeReqType->EVTargetCurrent);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}SessionStopRes; type={urn:iso:15118:2:2013:MsgBody}SessionStopResType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ResponseCode, responseCodeType (1, 1);
static int decode_iso2_SessionStopResType(exi_bitstream_t* stream, struct iso2_SessionStopResType* SessionStopResType) {
    int grammar_id = 313;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_SessionStopResType(SessionStopResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 313:
            // Grammar: ID=313; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=3
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 5, &value);
                            if (error == 0)
                            {
                                SessionStopResType->ResponseCode = (iso2_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}ServiceDetailRes; type={urn:iso:15118:2:2013:MsgBody}ServiceDetailResType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ResponseCode, responseCodeType (1, 1); ServiceID, serviceIDType (1, 1); ServiceParameterList, ServiceParameterListType (0, 1);
static int decode_iso2_ServiceDetailResType(exi_bitstream_t* stream, struct iso2_ServiceDetailResType* ServiceDetailResType) {
    int grammar_id = 314;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ServiceDetailResType(ServiceDetailResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 314:
            // Grammar: ID=314; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=315
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 5, &value);
                            if (error == 0)
                            {
                                ServiceDetailResType->ResponseCode = (iso2_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 315;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 315:
            // Grammar: ID=315; read/write bits=1; START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=316
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &ServiceDetailResType->ServiceID);
                    if (error == 0)
                    {
                        grammar_id = 316;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 316:
            // Grammar: ID=316; read/write bits=2; END Element, START (ServiceParameterList)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceParameterList, ServiceParameterListType (ServiceParameterListType)); next=3
                    // decode: element
                    error = decode_iso2_ServiceParameterListType(stream, &ServiceDetailResType->ServiceParameterList);
                    if (error == 0)
                    {
                        ServiceDetailResType->ServiceParameterList_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}ChargeParameterDiscoveryRes; type={urn:iso:15118:2:2013:MsgBody}ChargeParameterDiscoveryResType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ResponseCode, responseCodeType (1, 1); EVSEProcessing, EVSEProcessingType (1, 1); SAScheduleList, SAScheduleListType (0, 1); SASchedules, SASchedulesType (0, 1); AC_EVSEChargeParameter, AC_EVSEChargeParameterType (0, 1); DC_EVSEChargeParameter, DC_EVSEChargeParameterType (0, 1); EVSEChargeParameter, EVSEChargeParameterType (0, 1);
static int decode_iso2_ChargeParameterDiscoveryResType(exi_bitstream_t* stream, struct iso2_ChargeParameterDiscoveryResType* ChargeParameterDiscoveryResType) {
    int grammar_id = 317;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ChargeParameterDiscoveryResType(ChargeParameterDiscoveryResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 317:
            // Grammar: ID=317; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=318
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 5, &value);
                            if (error == 0)
                            {
                                ChargeParameterDiscoveryResType->ResponseCode = (iso2_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 318;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 318:
            // Grammar: ID=318; read/write bits=1; START (EVSEProcessing)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEProcessing, EVSEProcessingType (string)); next=319
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                ChargeParameterDiscoveryResType->EVSEProcessing = (iso2_EVSEProcessingType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 319;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 319:
            // Grammar: ID=319; read/write bits=3; START (SAScheduleList), START (SASchedules), START (AC_EVSEChargeParameter), START (DC_EVSEChargeParameter), START (EVSEChargeParameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SAScheduleList, SAScheduleListType (SASchedulesType)); next=320
                    // decode: element
                    error = decode_iso2_SAScheduleListType(stream, &ChargeParameterDiscoveryResType->SAScheduleList);
                    if (error == 0)
                    {
                        ChargeParameterDiscoveryResType->SAScheduleList_isUsed = 1u;
                        grammar_id = 320;
                    }
                    break;
                case 1:
                    // Event: START (SASchedules, SASchedulesType (SASchedulesType)); next=320
                    // decode: element
                    error = decode_iso2_SASchedulesType(stream, &ChargeParameterDiscoveryResType->SASchedules);
                    if (error == 0)
                    {
                        ChargeParameterDiscoveryResType->SASchedules_isUsed = 1u;
                        grammar_id = 320;
                    }
                    break;
                case 2:
                    // Event: START (AC_EVSEChargeParameter, AC_EVSEChargeParameterType (EVSEChargeParameterType)); next=3
                    // decode: element
                    error = decode_iso2_AC_EVSEChargeParameterType(stream, &ChargeParameterDiscoveryResType->AC_EVSEChargeParameter);
                    if (error == 0)
                    {
                        ChargeParameterDiscoveryResType->AC_EVSEChargeParameter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 3:
                    // Event: START (DC_EVSEChargeParameter, DC_EVSEChargeParameterType (EVSEChargeParameterType)); next=3
                    // decode: element
                    error = decode_iso2_DC_EVSEChargeParameterType(stream, &ChargeParameterDiscoveryResType->DC_EVSEChargeParameter);
                    if (error == 0)
                    {
                        ChargeParameterDiscoveryResType->DC_EVSEChargeParameter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 4:
                    // Event: START (EVSEChargeParameter, EVSEChargeParameterType (EVSEChargeParameterType)); next=3
                    // decode: element
                    error = decode_iso2_EVSEChargeParameterType(stream, &ChargeParameterDiscoveryResType->EVSEChargeParameter);
                    if (error == 0)
                    {
                        ChargeParameterDiscoveryResType->EVSEChargeParameter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 320:
            // Grammar: ID=320; read/write bits=2; START (AC_EVSEChargeParameter), START (DC_EVSEChargeParameter), START (EVSEChargeParameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AC_EVSEChargeParameter, AC_EVSEChargeParameterType (EVSEChargeParameterType)); next=3
                    // decode: element
                    error = decode_iso2_AC_EVSEChargeParameterType(stream, &ChargeParameterDiscoveryResType->AC_EVSEChargeParameter);
                    if (error == 0)
                    {
                        ChargeParameterDiscoveryResType->AC_EVSEChargeParameter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: START (DC_EVSEChargeParameter, DC_EVSEChargeParameterType (EVSEChargeParameterType)); next=3
                    // decode: element
                    error = decode_iso2_DC_EVSEChargeParameterType(stream, &ChargeParameterDiscoveryResType->DC_EVSEChargeParameter);
                    if (error == 0)
                    {
                        ChargeParameterDiscoveryResType->DC_EVSEChargeParameter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 2:
                    // Event: START (EVSEChargeParameter, EVSEChargeParameterType (EVSEChargeParameterType)); next=3
                    // decode: element
                    error = decode_iso2_EVSEChargeParameterType(stream, &ChargeParameterDiscoveryResType->EVSEChargeParameter);
                    if (error == 0)
                    {
                        ChargeParameterDiscoveryResType->EVSEChargeParameter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}CertificateUpdateRes; type={urn:iso:15118:2:2013:MsgBody}CertificateUpdateResType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ResponseCode, responseCodeType (1, 1); SAProvisioningCertificateChain, CertificateChainType (1, 1); ContractSignatureCertChain, CertificateChainType (1, 1); ContractSignatureEncryptedPrivateKey, ContractSignatureEncryptedPrivateKeyType (1, 1); DHpublickey, DiffieHellmanPublickeyType (1, 1); eMAID, EMAIDType (1, 1); RetryCounter, short (0, 1);
static int decode_iso2_CertificateUpdateResType(exi_bitstream_t* stream, struct iso2_CertificateUpdateResType* CertificateUpdateResType) {
    int grammar_id = 321;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_CertificateUpdateResType(CertificateUpdateResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 321:
            // Grammar: ID=321; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=322
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 5, &value);
                            if (error == 0)
                            {
                                CertificateUpdateResType->ResponseCode = (iso2_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 322;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 322:
            // Grammar: ID=322; read/write bits=1; START (SAProvisioningCertificateChain)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SAProvisioningCertificateChain, CertificateChainType (CertificateChainType)); next=323
                    // decode: element
                    error = decode_iso2_CertificateChainType(stream, &CertificateUpdateResType->SAProvisioningCertificateChain);
                    if (error == 0)
                    {
                        grammar_id = 323;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 323:
            // Grammar: ID=323; read/write bits=1; START (ContractSignatureCertChain)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ContractSignatureCertChain, CertificateChainType (CertificateChainType)); next=324
                    // decode: element
                    error = decode_iso2_CertificateChainType(stream, &CertificateUpdateResType->ContractSignatureCertChain);
                    if (error == 0)
                    {
                        grammar_id = 324;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 324:
            // Grammar: ID=324; read/write bits=1; START (ContractSignatureEncryptedPrivateKey)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ContractSignatureEncryptedPrivateKey, ContractSignatureEncryptedPrivateKeyType (privateKeyType)); next=325
                    // decode: element
                    error = decode_iso2_ContractSignatureEncryptedPrivateKeyType(stream, &CertificateUpdateResType->ContractSignatureEncryptedPrivateKey);
                    if (error == 0)
                    {
                        grammar_id = 325;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 325:
            // Grammar: ID=325; read/write bits=1; START (DHpublickey)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DHpublickey, DiffieHellmanPublickeyType (dHpublickeyType)); next=326
                    // decode: element
                    error = decode_iso2_DiffieHellmanPublickeyType(stream, &CertificateUpdateResType->DHpublickey);
                    if (error == 0)
                    {
                        grammar_id = 326;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 326:
            // Grammar: ID=326; read/write bits=1; START (eMAID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (eMAID, EMAIDType (eMAIDType)); next=327
                    // decode: element
                    error = decode_iso2_EMAIDType(stream, &CertificateUpdateResType->eMAID);
                    if (error == 0)
                    {
                        grammar_id = 327;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 327:
            // Grammar: ID=327; read/write bits=2; END Element, START (RetryCounter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RetryCounter, short (int)); next=3
                    // decode: short
                    error = decode_exi_type_integer16(stream, &CertificateUpdateResType->RetryCounter);
                    if (error == 0)
                    {
                        CertificateUpdateResType->RetryCounter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}CableCheckRes; type={urn:iso:15118:2:2013:MsgBody}CableCheckResType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ResponseCode, responseCodeType (1, 1); DC_EVSEStatus, DC_EVSEStatusType (1, 1); EVSEProcessing, EVSEProcessingType (1, 1);
static int decode_iso2_CableCheckResType(exi_bitstream_t* stream, struct iso2_CableCheckResType* CableCheckResType) {
    int grammar_id = 328;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_CableCheckResType(CableCheckResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 328:
            // Grammar: ID=328; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=329
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 5, &value);
                            if (error == 0)
                            {
                                CableCheckResType->ResponseCode = (iso2_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 329;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 329:
            // Grammar: ID=329; read/write bits=1; START (DC_EVSEStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DC_EVSEStatus, DC_EVSEStatusType (EVSEStatusType)); next=330
                    // decode: element
                    error = decode_iso2_DC_EVSEStatusType(stream, &CableCheckResType->DC_EVSEStatus);
                    if (error == 0)
                    {
                        grammar_id = 330;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 330:
            // Grammar: ID=330; read/write bits=1; START (EVSEProcessing)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEProcessing, EVSEProcessingType (string)); next=3
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                CableCheckResType->EVSEProcessing = (iso2_EVSEProcessingType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}PreChargeRes; type={urn:iso:15118:2:2013:MsgBody}PreChargeResType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ResponseCode, responseCodeType (1, 1); DC_EVSEStatus, DC_EVSEStatusType (1, 1); EVSEPresentVoltage, PhysicalValueType (1, 1);
static int decode_iso2_PreChargeResType(exi_bitstream_t* stream, struct iso2_PreChargeResType* PreChargeResType) {
    int grammar_id = 331;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_PreChargeResType(PreChargeResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 331:
            // Grammar: ID=331; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=332
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 5, &value);
                            if (error == 0)
                            {
                                PreChargeResType->ResponseCode = (iso2_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 332;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 332:
            // Grammar: ID=332; read/write bits=1; START (DC_EVSEStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DC_EVSEStatus, DC_EVSEStatusType (EVSEStatusType)); next=333
                    // decode: element
                    error = decode_iso2_DC_EVSEStatusType(stream, &PreChargeResType->DC_EVSEStatus);
                    if (error == 0)
                    {
                        grammar_id = 333;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 333:
            // Grammar: ID=333; read/write bits=1; START (EVSEPresentVoltage)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEPresentVoltage, PhysicalValueType (PhysicalValueType)); next=3
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &PreChargeResType->EVSEPresentVoltage);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}PowerDeliveryReq; type={urn:iso:15118:2:2013:MsgBody}PowerDeliveryReqType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ChargeProgress, chargeProgressType (1, 1); SAScheduleTupleID, SAIDType (1, 1); ChargingProfile, ChargingProfileType (0, 1); DC_EVPowerDeliveryParameter, DC_EVPowerDeliveryParameterType (0, 1); EVPowerDeliveryParameter, EVPowerDeliveryParameterType (0, 1);
static int decode_iso2_PowerDeliveryReqType(exi_bitstream_t* stream, struct iso2_PowerDeliveryReqType* PowerDeliveryReqType) {
    int grammar_id = 334;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_PowerDeliveryReqType(PowerDeliveryReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 334:
            // Grammar: ID=334; read/write bits=1; START (ChargeProgress)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ChargeProgress, chargeProgressType (string)); next=335
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                PowerDeliveryReqType->ChargeProgress = (iso2_chargeProgressType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 335;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 335:
            // Grammar: ID=335; read/write bits=1; START (SAScheduleTupleID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SAScheduleTupleID, SAIDType (unsignedByte)); next=336
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                // type has min_value = 1
                                PowerDeliveryReqType->SAScheduleTupleID = (uint8_t)(value + 1);
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 336;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 336:
            // Grammar: ID=336; read/write bits=3; END Element, START (ChargingProfile), START (DC_EVPowerDeliveryParameter), START (EVPowerDeliveryParameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ChargingProfile, ChargingProfileType (ChargingProfileType)); next=337
                    // decode: element
                    error = decode_iso2_ChargingProfileType(stream, &PowerDeliveryReqType->ChargingProfile);
                    if (error == 0)
                    {
                        PowerDeliveryReqType->ChargingProfile_isUsed = 1u;
                        grammar_id = 337;
                    }
                    break;
                case 1:
                    // Event: START (DC_EVPowerDeliveryParameter, DC_EVPowerDeliveryParameterType (EVPowerDeliveryParameterType)); next=3
                    // decode: element
                    error = decode_iso2_DC_EVPowerDeliveryParameterType(stream, &PowerDeliveryReqType->DC_EVPowerDeliveryParameter);
                    if (error == 0)
                    {
                        PowerDeliveryReqType->DC_EVPowerDeliveryParameter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 2:
                    // Event: START (EVPowerDeliveryParameter, EVPowerDeliveryParameterType (EVPowerDeliveryParameterType)); next=3
                    // decode: element
                    error = decode_iso2_EVPowerDeliveryParameterType(stream, &PowerDeliveryReqType->EVPowerDeliveryParameter);
                    if (error == 0)
                    {
                        PowerDeliveryReqType->EVPowerDeliveryParameter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 3:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 337:
            // Grammar: ID=337; read/write bits=2; END Element, START (DC_EVPowerDeliveryParameter), START (EVPowerDeliveryParameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DC_EVPowerDeliveryParameter, DC_EVPowerDeliveryParameterType (EVPowerDeliveryParameterType)); next=3
                    // decode: element
                    error = decode_iso2_DC_EVPowerDeliveryParameterType(stream, &PowerDeliveryReqType->DC_EVPowerDeliveryParameter);
                    if (error == 0)
                    {
                        PowerDeliveryReqType->DC_EVPowerDeliveryParameter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: START (EVPowerDeliveryParameter, EVPowerDeliveryParameterType (EVPowerDeliveryParameterType)); next=3
                    // decode: element
                    error = decode_iso2_EVPowerDeliveryParameterType(stream, &PowerDeliveryReqType->EVPowerDeliveryParameter);
                    if (error == 0)
                    {
                        PowerDeliveryReqType->EVPowerDeliveryParameter_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}PaymentServiceSelectionReq; type={urn:iso:15118:2:2013:MsgBody}PaymentServiceSelectionReqType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: SelectedPaymentOption, paymentOptionType (1, 1); SelectedServiceList, SelectedServiceListType (1, 1);
static int decode_iso2_PaymentServiceSelectionReqType(exi_bitstream_t* stream, struct iso2_PaymentServiceSelectionReqType* PaymentServiceSelectionReqType) {
    int grammar_id = 338;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_PaymentServiceSelectionReqType(PaymentServiceSelectionReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 338:
            // Grammar: ID=338; read/write bits=1; START (SelectedPaymentOption)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedPaymentOption, paymentOptionType (string)); next=339
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                PaymentServiceSelectionReqType->SelectedPaymentOption = (iso2_paymentOptionType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 339;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 339:
            // Grammar: ID=339; read/write bits=1; START (SelectedServiceList)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedServiceList, SelectedServiceListType (SelectedServiceListType)); next=3
                    // decode: element
                    error = decode_iso2_SelectedServiceListType(stream, &PaymentServiceSelectionReqType->SelectedServiceList);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}CertificateInstallationReq; type={urn:iso:15118:2:2013:MsgBody}CertificateInstallationReqType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Id, ID (1, 1); OEMProvisioningCert, certificateType (1, 1); ListOfRootCertificateIDs, ListOfRootCertificateIDsType (1, 1);
static int decode_iso2_CertificateInstallationReqType(exi_bitstream_t* stream, struct iso2_CertificateInstallationReqType* CertificateInstallationReqType) {
    int grammar_id = 340;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_CertificateInstallationReqType(CertificateInstallationReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 340:
            // Grammar: ID=340; read/write bits=1; START (Id)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=341
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &CertificateInstallationReqType->Id.charactersLen);
                            if (error == 0)
                            {
                                if (CertificateInstallationReqType->Id.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    CertificateInstallationReqType->Id.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, CertificateInstallationReqType->Id.charactersLen, CertificateInstallationReqType->Id.characters, iso2_Id_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 341;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 341:
            // Grammar: ID=341; read/write bits=1; START (OEMProvisioningCert)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OEMProvisioningCert, certificateType (base64Binary)); next=342
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &CertificateInstallationReqType->OEMProvisioningCert.bytesLen, &CertificateInstallationReqType->OEMProvisioningCert.bytes[0], iso2_certificateType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 342;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 342:
            // Grammar: ID=342; read/write bits=1; START (ListOfRootCertificateIDs)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ListOfRootCertificateIDs, ListOfRootCertificateIDsType (ListOfRootCertificateIDsType)); next=3
                    // decode: element
                    error = decode_iso2_ListOfRootCertificateIDsType(stream, &CertificateInstallationReqType->ListOfRootCertificateIDs);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}CurrentDemandReq; type={urn:iso:15118:2:2013:MsgBody}CurrentDemandReqType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DC_EVStatus, DC_EVStatusType (1, 1); EVTargetCurrent, PhysicalValueType (1, 1); EVMaximumVoltageLimit, PhysicalValueType (0, 1); EVMaximumCurrentLimit, PhysicalValueType (0, 1); EVMaximumPowerLimit, PhysicalValueType (0, 1); BulkChargingComplete, boolean (0, 1); ChargingComplete, boolean (1, 1); RemainingTimeToFullSoC, PhysicalValueType (0, 1); RemainingTimeToBulkSoC, PhysicalValueType (0, 1); EVTargetVoltage, PhysicalValueType (1, 1);
static int decode_iso2_CurrentDemandReqType(exi_bitstream_t* stream, struct iso2_CurrentDemandReqType* CurrentDemandReqType) {
    int grammar_id = 343;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_CurrentDemandReqType(CurrentDemandReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 343:
            // Grammar: ID=343; read/write bits=1; START (DC_EVStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DC_EVStatus, DC_EVStatusType (EVStatusType)); next=344
                    // decode: element
                    error = decode_iso2_DC_EVStatusType(stream, &CurrentDemandReqType->DC_EVStatus);
                    if (error == 0)
                    {
                        grammar_id = 344;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 344:
            // Grammar: ID=344; read/write bits=1; START (EVTargetCurrent)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVTargetCurrent, PhysicalValueType (PhysicalValueType)); next=345
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandReqType->EVTargetCurrent);
                    if (error == 0)
                    {
                        grammar_id = 345;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 345:
            // Grammar: ID=345; read/write bits=3; START (EVMaximumVoltageLimit), START (EVMaximumCurrentLimit), START (EVMaximumPowerLimit), START (BulkChargingComplete), START (ChargingComplete)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVMaximumVoltageLimit, PhysicalValueType (PhysicalValueType)); next=346
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandReqType->EVMaximumVoltageLimit);
                    if (error == 0)
                    {
                        CurrentDemandReqType->EVMaximumVoltageLimit_isUsed = 1u;
                        grammar_id = 346;
                    }
                    break;
                case 1:
                    // Event: START (EVMaximumCurrentLimit, PhysicalValueType (PhysicalValueType)); next=347
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandReqType->EVMaximumCurrentLimit);
                    if (error == 0)
                    {
                        CurrentDemandReqType->EVMaximumCurrentLimit_isUsed = 1u;
                        grammar_id = 347;
                    }
                    break;
                case 2:
                    // Event: START (EVMaximumPowerLimit, PhysicalValueType (PhysicalValueType)); next=348
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandReqType->EVMaximumPowerLimit);
                    if (error == 0)
                    {
                        CurrentDemandReqType->EVMaximumPowerLimit_isUsed = 1u;
                        grammar_id = 348;
                    }
                    break;
                case 3:
                    // Event: START (BulkChargingComplete, boolean (boolean)); next=349
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                CurrentDemandReqType->BulkChargingComplete = value;
                                CurrentDemandReqType->BulkChargingComplete_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 349;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 4:
                    // Event: START (ChargingComplete, boolean (boolean)); next=350
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                CurrentDemandReqType->ChargingComplete = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 350;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 346:
            // Grammar: ID=346; read/write bits=3; START (EVMaximumCurrentLimit), START (EVMaximumPowerLimit), START (BulkChargingComplete), START (ChargingComplete)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVMaximumCurrentLimit, PhysicalValueType (PhysicalValueType)); next=347
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandReqType->EVMaximumCurrentLimit);
                    if (error == 0)
                    {
                        CurrentDemandReqType->EVMaximumCurrentLimit_isUsed = 1u;
                        grammar_id = 347;
                    }
                    break;
                case 1:
                    // Event: START (EVMaximumPowerLimit, PhysicalValueType (PhysicalValueType)); next=348
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandReqType->EVMaximumPowerLimit);
                    if (error == 0)
                    {
                        CurrentDemandReqType->EVMaximumPowerLimit_isUsed = 1u;
                        grammar_id = 348;
                    }
                    break;
                case 2:
                    // Event: START (BulkChargingComplete, boolean (boolean)); next=349
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                CurrentDemandReqType->BulkChargingComplete = value;
                                CurrentDemandReqType->BulkChargingComplete_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 349;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 3:
                    // Event: START (ChargingComplete, boolean (boolean)); next=350
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                CurrentDemandReqType->ChargingComplete = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 350;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 347:
            // Grammar: ID=347; read/write bits=2; START (EVMaximumPowerLimit), START (BulkChargingComplete), START (ChargingComplete)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVMaximumPowerLimit, PhysicalValueType (PhysicalValueType)); next=348
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandReqType->EVMaximumPowerLimit);
                    if (error == 0)
                    {
                        CurrentDemandReqType->EVMaximumPowerLimit_isUsed = 1u;
                        grammar_id = 348;
                    }
                    break;
                case 1:
                    // Event: START (BulkChargingComplete, boolean (boolean)); next=349
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                CurrentDemandReqType->BulkChargingComplete = value;
                                CurrentDemandReqType->BulkChargingComplete_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 349;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: START (ChargingComplete, boolean (boolean)); next=350
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                CurrentDemandReqType->ChargingComplete = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 350;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 348:
            // Grammar: ID=348; read/write bits=2; START (BulkChargingComplete), START (ChargingComplete)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (BulkChargingComplete, boolean (boolean)); next=349
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                CurrentDemandReqType->BulkChargingComplete = value;
                                CurrentDemandReqType->BulkChargingComplete_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 349;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (ChargingComplete, boolean (boolean)); next=350
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                CurrentDemandReqType->ChargingComplete = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 350;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 349:
            // Grammar: ID=349; read/write bits=1; START (ChargingComplete)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ChargingComplete, boolean (boolean)); next=350
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                CurrentDemandReqType->ChargingComplete = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 350;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 350:
            // Grammar: ID=350; read/write bits=2; START (RemainingTimeToFullSoC), START (RemainingTimeToBulkSoC), START (EVTargetVoltage)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RemainingTimeToFullSoC, PhysicalValueType (PhysicalValueType)); next=351
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandReqType->RemainingTimeToFullSoC);
                    if (error == 0)
                    {
                        CurrentDemandReqType->RemainingTimeToFullSoC_isUsed = 1u;
                        grammar_id = 351;
                    }
                    break;
                case 1:
                    // Event: START (RemainingTimeToBulkSoC, PhysicalValueType (PhysicalValueType)); next=352
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandReqType->RemainingTimeToBulkSoC);
                    if (error == 0)
                    {
                        CurrentDemandReqType->RemainingTimeToBulkSoC_isUsed = 1u;
                        grammar_id = 352;
                    }
                    break;
                case 2:
                    // Event: START (EVTargetVoltage, PhysicalValueType (PhysicalValueType)); next=3
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandReqType->EVTargetVoltage);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 351:
            // Grammar: ID=351; read/write bits=2; START (RemainingTimeToBulkSoC), START (EVTargetVoltage)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RemainingTimeToBulkSoC, PhysicalValueType (PhysicalValueType)); next=352
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandReqType->RemainingTimeToBulkSoC);
                    if (error == 0)
                    {
                        CurrentDemandReqType->RemainingTimeToBulkSoC_isUsed = 1u;
                        grammar_id = 352;
                    }
                    break;
                case 1:
                    // Event: START (EVTargetVoltage, PhysicalValueType (PhysicalValueType)); next=3
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandReqType->EVTargetVoltage);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 352:
            // Grammar: ID=352; read/write bits=1; START (EVTargetVoltage)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVTargetVoltage, PhysicalValueType (PhysicalValueType)); next=3
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandReqType->EVTargetVoltage);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}PowerDeliveryRes; type={urn:iso:15118:2:2013:MsgBody}PowerDeliveryResType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ResponseCode, responseCodeType (1, 1); AC_EVSEStatus, AC_EVSEStatusType (0, 1); DC_EVSEStatus, DC_EVSEStatusType (0, 1); EVSEStatus, EVSEStatusType (0, 1);
static int decode_iso2_PowerDeliveryResType(exi_bitstream_t* stream, struct iso2_PowerDeliveryResType* PowerDeliveryResType) {
    int grammar_id = 353;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_PowerDeliveryResType(PowerDeliveryResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 353:
            // Grammar: ID=353; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=354
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 5, &value);
                            if (error == 0)
                            {
                                PowerDeliveryResType->ResponseCode = (iso2_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 354;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 354:
            // Grammar: ID=354; read/write bits=2; START (AC_EVSEStatus), START (DC_EVSEStatus), START (EVSEStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AC_EVSEStatus, AC_EVSEStatusType (EVSEStatusType)); next=3
                    // decode: element
                    error = decode_iso2_AC_EVSEStatusType(stream, &PowerDeliveryResType->AC_EVSEStatus);
                    if (error == 0)
                    {
                        PowerDeliveryResType->AC_EVSEStatus_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: START (DC_EVSEStatus, DC_EVSEStatusType (EVSEStatusType)); next=3
                    // decode: element
                    error = decode_iso2_DC_EVSEStatusType(stream, &PowerDeliveryResType->DC_EVSEStatus);
                    if (error == 0)
                    {
                        PowerDeliveryResType->DC_EVSEStatus_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 2:
                    // Event: START (EVSEStatus, EVSEStatusType (EVSEStatusType)); next=3
                    // decode: element
                    error = decode_iso2_EVSEStatusType(stream, &PowerDeliveryResType->EVSEStatus);
                    if (error == 0)
                    {
                        PowerDeliveryResType->EVSEStatus_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}PaymentServiceSelectionRes; type={urn:iso:15118:2:2013:MsgBody}PaymentServiceSelectionResType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ResponseCode, responseCodeType (1, 1);
static int decode_iso2_PaymentServiceSelectionResType(exi_bitstream_t* stream, struct iso2_PaymentServiceSelectionResType* PaymentServiceSelectionResType) {
    int grammar_id = 355;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_PaymentServiceSelectionResType(PaymentServiceSelectionResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 355:
            // Grammar: ID=355; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=3
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 5, &value);
                            if (error == 0)
                            {
                                PaymentServiceSelectionResType->ResponseCode = (iso2_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}CertificateInstallationRes; type={urn:iso:15118:2:2013:MsgBody}CertificateInstallationResType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ResponseCode, responseCodeType (1, 1); SAProvisioningCertificateChain, CertificateChainType (1, 1); ContractSignatureCertChain, CertificateChainType (1, 1); ContractSignatureEncryptedPrivateKey, ContractSignatureEncryptedPrivateKeyType (1, 1); DHpublickey, DiffieHellmanPublickeyType (1, 1); eMAID, EMAIDType (1, 1);
static int decode_iso2_CertificateInstallationResType(exi_bitstream_t* stream, struct iso2_CertificateInstallationResType* CertificateInstallationResType) {
    int grammar_id = 356;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_CertificateInstallationResType(CertificateInstallationResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 356:
            // Grammar: ID=356; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=357
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 5, &value);
                            if (error == 0)
                            {
                                CertificateInstallationResType->ResponseCode = (iso2_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 357;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 357:
            // Grammar: ID=357; read/write bits=1; START (SAProvisioningCertificateChain)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SAProvisioningCertificateChain, CertificateChainType (CertificateChainType)); next=358
                    // decode: element
                    error = decode_iso2_CertificateChainType(stream, &CertificateInstallationResType->SAProvisioningCertificateChain);
                    if (error == 0)
                    {
                        grammar_id = 358;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 358:
            // Grammar: ID=358; read/write bits=1; START (ContractSignatureCertChain)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ContractSignatureCertChain, CertificateChainType (CertificateChainType)); next=359
                    // decode: element
                    error = decode_iso2_CertificateChainType(stream, &CertificateInstallationResType->ContractSignatureCertChain);
                    if (error == 0)
                    {
                        grammar_id = 359;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 359:
            // Grammar: ID=359; read/write bits=1; START (ContractSignatureEncryptedPrivateKey)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ContractSignatureEncryptedPrivateKey, ContractSignatureEncryptedPrivateKeyType (privateKeyType)); next=360
                    // decode: element
                    error = decode_iso2_ContractSignatureEncryptedPrivateKeyType(stream, &CertificateInstallationResType->ContractSignatureEncryptedPrivateKey);
                    if (error == 0)
                    {
                        grammar_id = 360;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 360:
            // Grammar: ID=360; read/write bits=1; START (DHpublickey)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DHpublickey, DiffieHellmanPublickeyType (dHpublickeyType)); next=361
                    // decode: element
                    error = decode_iso2_DiffieHellmanPublickeyType(stream, &CertificateInstallationResType->DHpublickey);
                    if (error == 0)
                    {
                        grammar_id = 361;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 361:
            // Grammar: ID=361; read/write bits=1; START (eMAID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (eMAID, EMAIDType (eMAIDType)); next=3
                    // decode: element
                    error = decode_iso2_EMAIDType(stream, &CertificateInstallationResType->eMAID);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}CurrentDemandRes; type={urn:iso:15118:2:2013:MsgBody}CurrentDemandResType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ResponseCode, responseCodeType (1, 1); DC_EVSEStatus, DC_EVSEStatusType (1, 1); EVSEPresentVoltage, PhysicalValueType (1, 1); EVSEPresentCurrent, PhysicalValueType (1, 1); EVSECurrentLimitAchieved, boolean (1, 1); EVSEVoltageLimitAchieved, boolean (1, 1); EVSEPowerLimitAchieved, boolean (1, 1); EVSEMaximumVoltageLimit, PhysicalValueType (0, 1); EVSEMaximumCurrentLimit, PhysicalValueType (0, 1); EVSEMaximumPowerLimit, PhysicalValueType (0, 1); EVSEID, evseIDType (1, 1); SAScheduleTupleID, SAIDType (1, 1); MeterInfo, MeterInfoType (0, 1); ReceiptRequired, boolean (0, 1);
static int decode_iso2_CurrentDemandResType(exi_bitstream_t* stream, struct iso2_CurrentDemandResType* CurrentDemandResType) {
    int grammar_id = 362;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_CurrentDemandResType(CurrentDemandResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 362:
            // Grammar: ID=362; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=363
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 5, &value);
                            if (error == 0)
                            {
                                CurrentDemandResType->ResponseCode = (iso2_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 363;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 363:
            // Grammar: ID=363; read/write bits=1; START (DC_EVSEStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DC_EVSEStatus, DC_EVSEStatusType (EVSEStatusType)); next=364
                    // decode: element
                    error = decode_iso2_DC_EVSEStatusType(stream, &CurrentDemandResType->DC_EVSEStatus);
                    if (error == 0)
                    {
                        grammar_id = 364;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 364:
            // Grammar: ID=364; read/write bits=1; START (EVSEPresentVoltage)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEPresentVoltage, PhysicalValueType (PhysicalValueType)); next=365
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandResType->EVSEPresentVoltage);
                    if (error == 0)
                    {
                        grammar_id = 365;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 365:
            // Grammar: ID=365; read/write bits=1; START (EVSEPresentCurrent)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEPresentCurrent, PhysicalValueType (PhysicalValueType)); next=366
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandResType->EVSEPresentCurrent);
                    if (error == 0)
                    {
                        grammar_id = 366;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 366:
            // Grammar: ID=366; read/write bits=1; START (EVSECurrentLimitAchieved)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSECurrentLimitAchieved, boolean (boolean)); next=367
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                CurrentDemandResType->EVSECurrentLimitAchieved = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 367;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 367:
            // Grammar: ID=367; read/write bits=1; START (EVSEVoltageLimitAchieved)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEVoltageLimitAchieved, boolean (boolean)); next=368
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                CurrentDemandResType->EVSEVoltageLimitAchieved = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 368;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 368:
            // Grammar: ID=368; read/write bits=1; START (EVSEPowerLimitAchieved)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEPowerLimitAchieved, boolean (boolean)); next=369
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                CurrentDemandResType->EVSEPowerLimitAchieved = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 369;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 369:
            // Grammar: ID=369; read/write bits=3; START (EVSEMaximumVoltageLimit), START (EVSEMaximumCurrentLimit), START (EVSEMaximumPowerLimit), START (EVSEID)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEMaximumVoltageLimit, PhysicalValueType (PhysicalValueType)); next=370
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandResType->EVSEMaximumVoltageLimit);
                    if (error == 0)
                    {
                        CurrentDemandResType->EVSEMaximumVoltageLimit_isUsed = 1u;
                        grammar_id = 370;
                    }
                    break;
                case 1:
                    // Event: START (EVSEMaximumCurrentLimit, PhysicalValueType (PhysicalValueType)); next=371
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandResType->EVSEMaximumCurrentLimit);
                    if (error == 0)
                    {
                        CurrentDemandResType->EVSEMaximumCurrentLimit_isUsed = 1u;
                        grammar_id = 371;
                    }
                    break;
                case 2:
                    // Event: START (EVSEMaximumPowerLimit, PhysicalValueType (PhysicalValueType)); next=372
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandResType->EVSEMaximumPowerLimit);
                    if (error == 0)
                    {
                        CurrentDemandResType->EVSEMaximumPowerLimit_isUsed = 1u;
                        grammar_id = 372;
                    }
                    break;
                case 3:
                    // Event: START (EVSEID, evseIDType (string)); next=373
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &CurrentDemandResType->EVSEID.charactersLen);
                            if (error == 0)
                            {
                                if (CurrentDemandResType->EVSEID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    CurrentDemandResType->EVSEID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, CurrentDemandResType->EVSEID.charactersLen, CurrentDemandResType->EVSEID.characters, iso2_EVSEID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 373;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 370:
            // Grammar: ID=370; read/write bits=2; START (EVSEMaximumCurrentLimit), START (EVSEMaximumPowerLimit), START (EVSEID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEMaximumCurrentLimit, PhysicalValueType (PhysicalValueType)); next=371
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandResType->EVSEMaximumCurrentLimit);
                    if (error == 0)
                    {
                        CurrentDemandResType->EVSEMaximumCurrentLimit_isUsed = 1u;
                        grammar_id = 371;
                    }
                    break;
                case 1:
                    // Event: START (EVSEMaximumPowerLimit, PhysicalValueType (PhysicalValueType)); next=372
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandResType->EVSEMaximumPowerLimit);
                    if (error == 0)
                    {
                        CurrentDemandResType->EVSEMaximumPowerLimit_isUsed = 1u;
                        grammar_id = 372;
                    }
                    break;
                case 2:
                    // Event: START (EVSEID, evseIDType (string)); next=373
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &CurrentDemandResType->EVSEID.charactersLen);
                            if (error == 0)
                            {
                                if (CurrentDemandResType->EVSEID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    CurrentDemandResType->EVSEID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, CurrentDemandResType->EVSEID.charactersLen, CurrentDemandResType->EVSEID.characters, iso2_EVSEID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 373;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 371:
            // Grammar: ID=371; read/write bits=2; START (EVSEMaximumPowerLimit), START (EVSEID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEMaximumPowerLimit, PhysicalValueType (PhysicalValueType)); next=372
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &CurrentDemandResType->EVSEMaximumPowerLimit);
                    if (error == 0)
                    {
                        CurrentDemandResType->EVSEMaximumPowerLimit_isUsed = 1u;
                        grammar_id = 372;
                    }
                    break;
                case 1:
                    // Event: START (EVSEID, evseIDType (string)); next=373
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &CurrentDemandResType->EVSEID.charactersLen);
                            if (error == 0)
                            {
                                if (CurrentDemandResType->EVSEID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    CurrentDemandResType->EVSEID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, CurrentDemandResType->EVSEID.charactersLen, CurrentDemandResType->EVSEID.characters, iso2_EVSEID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 373;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 372:
            // Grammar: ID=372; read/write bits=1; START (EVSEID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEID, evseIDType (string)); next=373
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &CurrentDemandResType->EVSEID.charactersLen);
                            if (error == 0)
                            {
                                if (CurrentDemandResType->EVSEID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    CurrentDemandResType->EVSEID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, CurrentDemandResType->EVSEID.charactersLen, CurrentDemandResType->EVSEID.characters, iso2_EVSEID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 373;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 373:
            // Grammar: ID=373; read/write bits=1; START (SAScheduleTupleID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SAScheduleTupleID, SAIDType (unsignedByte)); next=374
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                // type has min_value = 1
                                CurrentDemandResType->SAScheduleTupleID = (uint8_t)(value + 1);
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 374;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 374:
            // Grammar: ID=374; read/write bits=2; END Element, START (MeterInfo), START (ReceiptRequired)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MeterInfo, MeterInfoType (MeterInfoType)); next=375
                    // decode: element
                    error = decode_iso2_MeterInfoType(stream, &CurrentDemandResType->MeterInfo);
                    if (error == 0)
                    {
                        CurrentDemandResType->MeterInfo_isUsed = 1u;
                        grammar_id = 375;
                    }
                    break;
                case 1:
                    // Event: START (ReceiptRequired, boolean (boolean)); next=3
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                CurrentDemandResType->ReceiptRequired = value;
                                CurrentDemandResType->ReceiptRequired_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 375:
            // Grammar: ID=375; read/write bits=2; END Element, START (ReceiptRequired)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ReceiptRequired, boolean (boolean)); next=3
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                CurrentDemandResType->ReceiptRequired = value;
                                CurrentDemandResType->ReceiptRequired_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}MeteringReceiptReq; type={urn:iso:15118:2:2013:MsgBody}MeteringReceiptReqType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Id, ID (0, 1); SessionID, sessionIDType (1, 1); SAScheduleTupleID, SAIDType (0, 1); MeterInfo, MeterInfoType (1, 1);
static int decode_iso2_MeteringReceiptReqType(exi_bitstream_t* stream, struct iso2_MeteringReceiptReqType* MeteringReceiptReqType) {
    int grammar_id = 376;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_MeteringReceiptReqType(MeteringReceiptReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 376:
            // Grammar: ID=376; read/write bits=2; START (Id), START (SessionID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=377
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &MeteringReceiptReqType->Id.charactersLen);
                            if (error == 0)
                            {
                                if (MeteringReceiptReqType->Id.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    MeteringReceiptReqType->Id.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, MeteringReceiptReqType->Id.charactersLen, MeteringReceiptReqType->Id.characters, iso2_Id_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                MeteringReceiptReqType->Id_isUsed = 1u;
                                grammar_id = 377;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (SessionID, sessionIDType (hexBinary)); next=378
                    // decode exi type: hexBinary
                    error = decode_exi_type_hex_binary(stream, &MeteringReceiptReqType->SessionID.bytesLen, &MeteringReceiptReqType->SessionID.bytes[0], iso2_sessionIDType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 378;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 377:
            // Grammar: ID=377; read/write bits=1; START (SessionID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SessionID, sessionIDType (hexBinary)); next=378
                    // decode exi type: hexBinary
                    error = decode_exi_type_hex_binary(stream, &MeteringReceiptReqType->SessionID.bytesLen, &MeteringReceiptReqType->SessionID.bytes[0], iso2_sessionIDType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 378;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 378:
            // Grammar: ID=378; read/write bits=2; START (SAScheduleTupleID), START (MeterInfo)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SAScheduleTupleID, SAIDType (unsignedByte)); next=379
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                // type has min_value = 1
                                MeteringReceiptReqType->SAScheduleTupleID = (uint8_t)(value + 1);
                                MeteringReceiptReqType->SAScheduleTupleID_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 379;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (MeterInfo, MeterInfoType (MeterInfoType)); next=3
                    // decode: element
                    error = decode_iso2_MeterInfoType(stream, &MeteringReceiptReqType->MeterInfo);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 379:
            // Grammar: ID=379; read/write bits=1; START (MeterInfo)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MeterInfo, MeterInfoType (MeterInfoType)); next=3
                    // decode: element
                    error = decode_iso2_MeterInfoType(stream, &MeteringReceiptReqType->MeterInfo);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}SessionSetupReq; type={urn:iso:15118:2:2013:MsgBody}SessionSetupReqType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVCCID, evccIDType (1, 1);
static int decode_iso2_SessionSetupReqType(exi_bitstream_t* stream, struct iso2_SessionSetupReqType* SessionSetupReqType) {
    int grammar_id = 380;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_SessionSetupReqType(SessionSetupReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 380:
            // Grammar: ID=380; read/write bits=1; START (EVCCID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVCCID, evccIDType (hexBinary)); next=3
                    // decode exi type: hexBinary
                    error = decode_exi_type_hex_binary(stream, &SessionSetupReqType->EVCCID.bytesLen, &SessionSetupReqType->EVCCID.bytes[0], iso2_evccIDType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}PaymentDetailsReq; type={urn:iso:15118:2:2013:MsgBody}PaymentDetailsReqType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: eMAID, eMAIDType (1, 1); ContractSignatureCertChain, CertificateChainType (1, 1);
static int decode_iso2_PaymentDetailsReqType(exi_bitstream_t* stream, struct iso2_PaymentDetailsReqType* PaymentDetailsReqType) {
    int grammar_id = 381;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_PaymentDetailsReqType(PaymentDetailsReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 381:
            // Grammar: ID=381; read/write bits=1; START (eMAID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (eMAID, eMAIDType (string)); next=382
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &PaymentDetailsReqType->eMAID.charactersLen);
                            if (error == 0)
                            {
                                if (PaymentDetailsReqType->eMAID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    PaymentDetailsReqType->eMAID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, PaymentDetailsReqType->eMAID.charactersLen, PaymentDetailsReqType->eMAID.characters, iso2_eMAID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 382;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 382:
            // Grammar: ID=382; read/write bits=1; START (ContractSignatureCertChain)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ContractSignatureCertChain, CertificateChainType (CertificateChainType)); next=3
                    // decode: element
                    error = decode_iso2_CertificateChainType(stream, &PaymentDetailsReqType->ContractSignatureCertChain);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}ChargingStatusReq; type={urn:iso:15118:2:2013:MsgBody}ChargingStatusReqType; base type=BodyBaseType; content type=empty;
//          abstract=False; final=False; derivation=extension;
static int decode_iso2_ChargingStatusReqType(exi_bitstream_t* stream, struct iso2_ChargingStatusReqType* ChargingStatusReqType) {
    // Element has no particles, so the function just returns zero
    (void)stream;
    (void)ChargingStatusReqType;

    return 0;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}WeldingDetectionReq; type={urn:iso:15118:2:2013:MsgBody}WeldingDetectionReqType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DC_EVStatus, DC_EVStatusType (1, 1);
static int decode_iso2_WeldingDetectionReqType(exi_bitstream_t* stream, struct iso2_WeldingDetectionReqType* WeldingDetectionReqType) {
    int grammar_id = 383;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_WeldingDetectionReqType(WeldingDetectionReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 383:
            // Grammar: ID=383; read/write bits=1; START (DC_EVStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DC_EVStatus, DC_EVStatusType (EVStatusType)); next=3
                    // decode: element
                    error = decode_iso2_DC_EVStatusType(stream, &WeldingDetectionReqType->DC_EVStatus);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}SessionSetupRes; type={urn:iso:15118:2:2013:MsgBody}SessionSetupResType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ResponseCode, responseCodeType (1, 1); EVSEID, evseIDType (1, 1); EVSETimeStamp, long (0, 1);
static int decode_iso2_SessionSetupResType(exi_bitstream_t* stream, struct iso2_SessionSetupResType* SessionSetupResType) {
    int grammar_id = 384;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_SessionSetupResType(SessionSetupResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 384:
            // Grammar: ID=384; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=385
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 5, &value);
                            if (error == 0)
                            {
                                SessionSetupResType->ResponseCode = (iso2_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 385;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 385:
            // Grammar: ID=385; read/write bits=1; START (EVSEID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEID, evseIDType (string)); next=386
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &SessionSetupResType->EVSEID.charactersLen);
                            if (error == 0)
                            {
                                if (SessionSetupResType->EVSEID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    SessionSetupResType->EVSEID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, SessionSetupResType->EVSEID.charactersLen, SessionSetupResType->EVSEID.characters, iso2_EVSEID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 386;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 386:
            // Grammar: ID=386; read/write bits=2; END Element, START (EVSETimeStamp)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSETimeStamp, long (integer)); next=3
                    // decode: long int
                    error = decode_exi_type_integer64(stream, &SessionSetupResType->EVSETimeStamp);
                    if (error == 0)
                    {
                        SessionSetupResType->EVSETimeStamp_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}PaymentDetailsRes; type={urn:iso:15118:2:2013:MsgBody}PaymentDetailsResType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ResponseCode, responseCodeType (1, 1); GenChallenge, genChallengeType (1, 1); EVSETimeStamp, long (1, 1);
static int decode_iso2_PaymentDetailsResType(exi_bitstream_t* stream, struct iso2_PaymentDetailsResType* PaymentDetailsResType) {
    int grammar_id = 387;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_PaymentDetailsResType(PaymentDetailsResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 387:
            // Grammar: ID=387; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=388
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 5, &value);
                            if (error == 0)
                            {
                                PaymentDetailsResType->ResponseCode = (iso2_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 388;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 388:
            // Grammar: ID=388; read/write bits=1; START (GenChallenge)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (GenChallenge, genChallengeType (base64Binary)); next=389
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PaymentDetailsResType->GenChallenge.bytesLen, &PaymentDetailsResType->GenChallenge.bytes[0], iso2_genChallengeType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 389;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 389:
            // Grammar: ID=389; read/write bits=1; START (EVSETimeStamp)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSETimeStamp, long (integer)); next=3
                    // decode: long int
                    error = decode_exi_type_integer64(stream, &PaymentDetailsResType->EVSETimeStamp);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}MeteringReceiptRes; type={urn:iso:15118:2:2013:MsgBody}MeteringReceiptResType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ResponseCode, responseCodeType (1, 1); AC_EVSEStatus, AC_EVSEStatusType (0, 1); DC_EVSEStatus, DC_EVSEStatusType (0, 1); EVSEStatus, EVSEStatusType (0, 1);
static int decode_iso2_MeteringReceiptResType(exi_bitstream_t* stream, struct iso2_MeteringReceiptResType* MeteringReceiptResType) {
    int grammar_id = 390;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_MeteringReceiptResType(MeteringReceiptResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 390:
            // Grammar: ID=390; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=391
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 5, &value);
                            if (error == 0)
                            {
                                MeteringReceiptResType->ResponseCode = (iso2_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 391;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 391:
            // Grammar: ID=391; read/write bits=2; START (AC_EVSEStatus), START (DC_EVSEStatus), START (EVSEStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AC_EVSEStatus, AC_EVSEStatusType (EVSEStatusType)); next=3
                    // decode: element
                    error = decode_iso2_AC_EVSEStatusType(stream, &MeteringReceiptResType->AC_EVSEStatus);
                    if (error == 0)
                    {
                        MeteringReceiptResType->AC_EVSEStatus_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: START (DC_EVSEStatus, DC_EVSEStatusType (EVSEStatusType)); next=3
                    // decode: element
                    error = decode_iso2_DC_EVSEStatusType(stream, &MeteringReceiptResType->DC_EVSEStatus);
                    if (error == 0)
                    {
                        MeteringReceiptResType->DC_EVSEStatus_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 2:
                    // Event: START (EVSEStatus, EVSEStatusType (EVSEStatusType)); next=3
                    // decode: element
                    error = decode_iso2_EVSEStatusType(stream, &MeteringReceiptResType->EVSEStatus);
                    if (error == 0)
                    {
                        MeteringReceiptResType->EVSEStatus_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}ChargingStatusRes; type={urn:iso:15118:2:2013:MsgBody}ChargingStatusResType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ResponseCode, responseCodeType (1, 1); EVSEID, evseIDType (1, 1); SAScheduleTupleID, SAIDType (1, 1); EVSEMaxCurrent, PhysicalValueType (0, 1); MeterInfo, MeterInfoType (0, 1); ReceiptRequired, boolean (0, 1); AC_EVSEStatus, AC_EVSEStatusType (1, 1);
static int decode_iso2_ChargingStatusResType(exi_bitstream_t* stream, struct iso2_ChargingStatusResType* ChargingStatusResType) {
    int grammar_id = 392;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ChargingStatusResType(ChargingStatusResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 392:
            // Grammar: ID=392; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=393
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 5, &value);
                            if (error == 0)
                            {
                                ChargingStatusResType->ResponseCode = (iso2_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 393;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 393:
            // Grammar: ID=393; read/write bits=1; START (EVSEID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEID, evseIDType (string)); next=394
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ChargingStatusResType->EVSEID.charactersLen);
                            if (error == 0)
                            {
                                if (ChargingStatusResType->EVSEID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ChargingStatusResType->EVSEID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ChargingStatusResType->EVSEID.charactersLen, ChargingStatusResType->EVSEID.characters, iso2_EVSEID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 394;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 394:
            // Grammar: ID=394; read/write bits=1; START (SAScheduleTupleID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SAScheduleTupleID, SAIDType (unsignedByte)); next=395
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                // type has min_value = 1
                                ChargingStatusResType->SAScheduleTupleID = (uint8_t)(value + 1);
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 395;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 395:
            // Grammar: ID=395; read/write bits=3; START (EVSEMaxCurrent), START (MeterInfo), START (ReceiptRequired), START (AC_EVSEStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEMaxCurrent, PhysicalValueType (PhysicalValueType)); next=396
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &ChargingStatusResType->EVSEMaxCurrent);
                    if (error == 0)
                    {
                        ChargingStatusResType->EVSEMaxCurrent_isUsed = 1u;
                        grammar_id = 396;
                    }
                    break;
                case 1:
                    // Event: START (MeterInfo, MeterInfoType (MeterInfoType)); next=397
                    // decode: element
                    error = decode_iso2_MeterInfoType(stream, &ChargingStatusResType->MeterInfo);
                    if (error == 0)
                    {
                        ChargingStatusResType->MeterInfo_isUsed = 1u;
                        grammar_id = 397;
                    }
                    break;
                case 2:
                    // Event: START (ReceiptRequired, boolean (boolean)); next=398
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ChargingStatusResType->ReceiptRequired = value;
                                ChargingStatusResType->ReceiptRequired_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 398;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 3:
                    // Event: START (AC_EVSEStatus, AC_EVSEStatusType (EVSEStatusType)); next=3
                    // decode: element
                    error = decode_iso2_AC_EVSEStatusType(stream, &ChargingStatusResType->AC_EVSEStatus);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 396:
            // Grammar: ID=396; read/write bits=2; START (MeterInfo), START (ReceiptRequired), START (AC_EVSEStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MeterInfo, MeterInfoType (MeterInfoType)); next=397
                    // decode: element
                    error = decode_iso2_MeterInfoType(stream, &ChargingStatusResType->MeterInfo);
                    if (error == 0)
                    {
                        ChargingStatusResType->MeterInfo_isUsed = 1u;
                        grammar_id = 397;
                    }
                    break;
                case 1:
                    // Event: START (ReceiptRequired, boolean (boolean)); next=398
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ChargingStatusResType->ReceiptRequired = value;
                                ChargingStatusResType->ReceiptRequired_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 398;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: START (AC_EVSEStatus, AC_EVSEStatusType (EVSEStatusType)); next=3
                    // decode: element
                    error = decode_iso2_AC_EVSEStatusType(stream, &ChargingStatusResType->AC_EVSEStatus);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 397:
            // Grammar: ID=397; read/write bits=2; START (ReceiptRequired), START (AC_EVSEStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ReceiptRequired, boolean (boolean)); next=398
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ChargingStatusResType->ReceiptRequired = value;
                                ChargingStatusResType->ReceiptRequired_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 398;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (AC_EVSEStatus, AC_EVSEStatusType (EVSEStatusType)); next=3
                    // decode: element
                    error = decode_iso2_AC_EVSEStatusType(stream, &ChargingStatusResType->AC_EVSEStatus);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 398:
            // Grammar: ID=398; read/write bits=1; START (AC_EVSEStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AC_EVSEStatus, AC_EVSEStatusType (EVSEStatusType)); next=3
                    // decode: element
                    error = decode_iso2_AC_EVSEStatusType(stream, &ChargingStatusResType->AC_EVSEStatus);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}WeldingDetectionRes; type={urn:iso:15118:2:2013:MsgBody}WeldingDetectionResType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ResponseCode, responseCodeType (1, 1); DC_EVSEStatus, DC_EVSEStatusType (1, 1); EVSEPresentVoltage, PhysicalValueType (1, 1);
static int decode_iso2_WeldingDetectionResType(exi_bitstream_t* stream, struct iso2_WeldingDetectionResType* WeldingDetectionResType) {
    int grammar_id = 399;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_WeldingDetectionResType(WeldingDetectionResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 399:
            // Grammar: ID=399; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=400
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 5, &value);
                            if (error == 0)
                            {
                                WeldingDetectionResType->ResponseCode = (iso2_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 400;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 400:
            // Grammar: ID=400; read/write bits=1; START (DC_EVSEStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DC_EVSEStatus, DC_EVSEStatusType (EVSEStatusType)); next=401
                    // decode: element
                    error = decode_iso2_DC_EVSEStatusType(stream, &WeldingDetectionResType->DC_EVSEStatus);
                    if (error == 0)
                    {
                        grammar_id = 401;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 401:
            // Grammar: ID=401; read/write bits=1; START (EVSEPresentVoltage)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEPresentVoltage, PhysicalValueType (PhysicalValueType)); next=3
                    // decode: element
                    error = decode_iso2_PhysicalValueType(stream, &WeldingDetectionResType->EVSEPresentVoltage);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}ServiceDiscoveryReq; type={urn:iso:15118:2:2013:MsgBody}ServiceDiscoveryReqType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ServiceScope, serviceScopeType (0, 1); ServiceCategory, serviceCategoryType (0, 1);
static int decode_iso2_ServiceDiscoveryReqType(exi_bitstream_t* stream, struct iso2_ServiceDiscoveryReqType* ServiceDiscoveryReqType) {
    int grammar_id = 402;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ServiceDiscoveryReqType(ServiceDiscoveryReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 402:
            // Grammar: ID=402; read/write bits=2; END Element, START (ServiceScope), START (ServiceCategory)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceScope, serviceScopeType (string)); next=403
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ServiceDiscoveryReqType->ServiceScope.charactersLen);
                            if (error == 0)
                            {
                                if (ServiceDiscoveryReqType->ServiceScope.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ServiceDiscoveryReqType->ServiceScope.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ServiceDiscoveryReqType->ServiceScope.charactersLen, ServiceDiscoveryReqType->ServiceScope.characters, iso2_ServiceScope_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ServiceDiscoveryReqType->ServiceScope_isUsed = 1u;
                                grammar_id = 403;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (ServiceCategory, serviceCategoryType (string)); next=3
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                ServiceDiscoveryReqType->ServiceCategory = (iso2_serviceCategoryType)value;
                                ServiceDiscoveryReqType->ServiceCategory_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 403:
            // Grammar: ID=403; read/write bits=2; END Element, START (ServiceCategory)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceCategory, serviceCategoryType (string)); next=3
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                ServiceDiscoveryReqType->ServiceCategory = (iso2_serviceCategoryType)value;
                                ServiceDiscoveryReqType->ServiceCategory_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}SessionStopReq; type={urn:iso:15118:2:2013:MsgBody}SessionStopReqType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ChargingSession, chargingSessionType (1, 1);
static int decode_iso2_SessionStopReqType(exi_bitstream_t* stream, struct iso2_SessionStopReqType* SessionStopReqType) {
    int grammar_id = 404;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_SessionStopReqType(SessionStopReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 404:
            // Grammar: ID=404; read/write bits=1; START (ChargingSession)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ChargingSession, chargingSessionType (string)); next=3
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                SessionStopReqType->ChargingSession = (iso2_chargingSessionType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}AuthorizationReq; type={urn:iso:15118:2:2013:MsgBody}AuthorizationReqType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Id, ID (0, 1); GenChallenge, genChallengeType (0, 1);
static int decode_iso2_AuthorizationReqType(exi_bitstream_t* stream, struct iso2_AuthorizationReqType* AuthorizationReqType) {
    int grammar_id = 405;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_AuthorizationReqType(AuthorizationReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 405:
            // Grammar: ID=405; read/write bits=2; END Element, START (Id), START (GenChallenge)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=406
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &AuthorizationReqType->Id.charactersLen);
                            if (error == 0)
                            {
                                if (AuthorizationReqType->Id.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    AuthorizationReqType->Id.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, AuthorizationReqType->Id.charactersLen, AuthorizationReqType->Id.characters, iso2_Id_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                AuthorizationReqType->Id_isUsed = 1u;
                                grammar_id = 406;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (GenChallenge, genChallengeType (base64Binary)); next=3
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &AuthorizationReqType->GenChallenge.bytesLen, &AuthorizationReqType->GenChallenge.bytes[0], iso2_genChallengeType_BYTES_SIZE);
                    if (error == 0)
                    {
                        AuthorizationReqType->GenChallenge_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 406:
            // Grammar: ID=406; read/write bits=2; END Element, START (GenChallenge)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (GenChallenge, genChallengeType (base64Binary)); next=3
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &AuthorizationReqType->GenChallenge.bytesLen, &AuthorizationReqType->GenChallenge.bytes[0], iso2_genChallengeType_BYTES_SIZE);
                    if (error == 0)
                    {
                        AuthorizationReqType->GenChallenge_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}CableCheckReq; type={urn:iso:15118:2:2013:MsgBody}CableCheckReqType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DC_EVStatus, DC_EVStatusType (1, 1);
static int decode_iso2_CableCheckReqType(exi_bitstream_t* stream, struct iso2_CableCheckReqType* CableCheckReqType) {
    int grammar_id = 407;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_CableCheckReqType(CableCheckReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 407:
            // Grammar: ID=407; read/write bits=1; START (DC_EVStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DC_EVStatus, DC_EVStatusType (EVStatusType)); next=3
                    // decode: element
                    error = decode_iso2_DC_EVStatusType(stream, &CableCheckReqType->DC_EVStatus);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}ServiceDiscoveryRes; type={urn:iso:15118:2:2013:MsgBody}ServiceDiscoveryResType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ResponseCode, responseCodeType (1, 1); PaymentOptionList, PaymentOptionListType (1, 1); ChargeService, ChargeServiceType (1, 1); ServiceList, ServiceListType (0, 1);
static int decode_iso2_ServiceDiscoveryResType(exi_bitstream_t* stream, struct iso2_ServiceDiscoveryResType* ServiceDiscoveryResType) {
    int grammar_id = 408;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_ServiceDiscoveryResType(ServiceDiscoveryResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 408:
            // Grammar: ID=408; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=409
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 5, &value);
                            if (error == 0)
                            {
                                ServiceDiscoveryResType->ResponseCode = (iso2_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 409;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 409:
            // Grammar: ID=409; read/write bits=1; START (PaymentOptionList)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PaymentOptionList, PaymentOptionListType (PaymentOptionListType)); next=410
                    // decode: element
                    error = decode_iso2_PaymentOptionListType(stream, &ServiceDiscoveryResType->PaymentOptionList);
                    if (error == 0)
                    {
                        grammar_id = 410;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 410:
            // Grammar: ID=410; read/write bits=1; START (ChargeService)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ChargeService, ChargeServiceType (ServiceType)); next=411
                    // decode: element
                    error = decode_iso2_ChargeServiceType(stream, &ServiceDiscoveryResType->ChargeService);
                    if (error == 0)
                    {
                        grammar_id = 411;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 411:
            // Grammar: ID=411; read/write bits=2; END Element, START (ServiceList)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceList, ServiceListType (ServiceListType)); next=3
                    // decode: element
                    error = decode_iso2_ServiceListType(stream, &ServiceDiscoveryResType->ServiceList);
                    if (error == 0)
                    {
                        ServiceDiscoveryResType->ServiceList_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgBody}AuthorizationRes; type={urn:iso:15118:2:2013:MsgBody}AuthorizationResType; base type=BodyBaseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: ResponseCode, responseCodeType (1, 1); EVSEProcessing, EVSEProcessingType (1, 1);
static int decode_iso2_AuthorizationResType(exi_bitstream_t* stream, struct iso2_AuthorizationResType* AuthorizationResType) {
    int grammar_id = 412;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_AuthorizationResType(AuthorizationResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 412:
            // Grammar: ID=412; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=413
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 5, &value);
                            if (error == 0)
                            {
                                AuthorizationResType->ResponseCode = (iso2_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 413;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 413:
            // Grammar: ID=413; read/write bits=1; START (EVSEProcessing)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEProcessing, EVSEProcessingType (string)); next=3
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                AuthorizationResType->EVSEProcessing = (iso2_EVSEProcessingType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDef}Body; type={urn:iso:15118:2:2013:MsgBody}BodyType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: AuthorizationReq, AuthorizationReqType (0, 1); AuthorizationRes, AuthorizationResType (0, 1); BodyElement, BodyBaseType (0, 1); CableCheckReq, CableCheckReqType (0, 1); CableCheckRes, CableCheckResType (0, 1); CertificateInstallationReq, CertificateInstallationReqType (0, 1); CertificateInstallationRes, CertificateInstallationResType (0, 1); CertificateUpdateReq, CertificateUpdateReqType (0, 1); CertificateUpdateRes, CertificateUpdateResType (0, 1); ChargeParameterDiscoveryReq, ChargeParameterDiscoveryReqType (0, 1); ChargeParameterDiscoveryRes, ChargeParameterDiscoveryResType (0, 1); ChargingStatusReq, ChargingStatusReqType (0, 1); ChargingStatusRes, ChargingStatusResType (0, 1); CurrentDemandReq, CurrentDemandReqType (0, 1); CurrentDemandRes, CurrentDemandResType (0, 1); MeteringReceiptReq, MeteringReceiptReqType (0, 1); MeteringReceiptRes, MeteringReceiptResType (0, 1); PaymentDetailsReq, PaymentDetailsReqType (0, 1); PaymentDetailsRes, PaymentDetailsResType (0, 1); PaymentServiceSelectionReq, PaymentServiceSelectionReqType (0, 1); PaymentServiceSelectionRes, PaymentServiceSelectionResType (0, 1); PowerDeliveryReq, PowerDeliveryReqType (0, 1); PowerDeliveryRes, PowerDeliveryResType (0, 1); PreChargeReq, PreChargeReqType (0, 1); PreChargeRes, PreChargeResType (0, 1); ServiceDetailReq, ServiceDetailReqType (0, 1); ServiceDetailRes, ServiceDetailResType (0, 1); ServiceDiscoveryReq, ServiceDiscoveryReqType (0, 1); ServiceDiscoveryRes, ServiceDiscoveryResType (0, 1); SessionSetupReq, SessionSetupReqType (0, 1); SessionSetupRes, SessionSetupResType (0, 1); SessionStopReq, SessionStopReqType (0, 1); SessionStopRes, SessionStopResType (0, 1); WeldingDetectionReq, WeldingDetectionReqType (0, 1); WeldingDetectionRes, WeldingDetectionResType (0, 1);
static int decode_iso2_BodyType(exi_bitstream_t* stream, struct iso2_BodyType* BodyType) {
    int grammar_id = 414;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_BodyType(BodyType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 414:
            // Grammar: ID=414; read bits=6; START (BodyMessage)
            error = exi_basetypes_decoder_nbit_uint(stream, 6, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: AuthorizationReq
                    // decode: namespace element
                    error = decode_iso2_AuthorizationReqType(stream, &BodyType->AuthorizationReq);
                    if (error == 0)
                    {
                        BodyType->AuthorizationReq_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 1:
                    // Event: AuthorizationRes
                    // decode: namespace element
                    error = decode_iso2_AuthorizationResType(stream, &BodyType->AuthorizationRes);
                    if (error == 0)
                    {
                        BodyType->AuthorizationRes_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 2:
                    // Event: BodyElement
                    // decode: namespace element
                    error = decode_iso2_BodyBaseType(stream, &BodyType->BodyElement);
                    if (error == 0)
                    {
                        BodyType->BodyElement_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 3:
                    // Event: CableCheckReq
                    // decode: namespace element
                    error = decode_iso2_CableCheckReqType(stream, &BodyType->CableCheckReq);
                    if (error == 0)
                    {
                        BodyType->CableCheckReq_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 4:
                    // Event: CableCheckRes
                    // decode: namespace element
                    error = decode_iso2_CableCheckResType(stream, &BodyType->CableCheckRes);
                    if (error == 0)
                    {
                        BodyType->CableCheckRes_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 5:
                    // Event: CertificateInstallationReq
                    // decode: namespace element
                    error = decode_iso2_CertificateInstallationReqType(stream, &BodyType->CertificateInstallationReq);
                    if (error == 0)
                    {
                        BodyType->CertificateInstallationReq_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 6:
                    // Event: CertificateInstallationRes
                    // decode: namespace element
                    error = decode_iso2_CertificateInstallationResType(stream, &BodyType->CertificateInstallationRes);
                    if (error == 0)
                    {
                        BodyType->CertificateInstallationRes_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 7:
                    // Event: CertificateUpdateReq
                    // decode: namespace element
                    error = decode_iso2_CertificateUpdateReqType(stream, &BodyType->CertificateUpdateReq);
                    if (error == 0)
                    {
                        BodyType->CertificateUpdateReq_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 8:
                    // Event: CertificateUpdateRes
                    // decode: namespace element
                    error = decode_iso2_CertificateUpdateResType(stream, &BodyType->CertificateUpdateRes);
                    if (error == 0)
                    {
                        BodyType->CertificateUpdateRes_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 9:
                    // Event: ChargeParameterDiscoveryReq
                    // decode: namespace element
                    error = decode_iso2_ChargeParameterDiscoveryReqType(stream, &BodyType->ChargeParameterDiscoveryReq);
                    if (error == 0)
                    {
                        BodyType->ChargeParameterDiscoveryReq_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 10:
                    // Event: ChargeParameterDiscoveryRes
                    // decode: namespace element
                    error = decode_iso2_ChargeParameterDiscoveryResType(stream, &BodyType->ChargeParameterDiscoveryRes);
                    if (error == 0)
                    {
                        BodyType->ChargeParameterDiscoveryRes_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 11:
                    // Event: ChargingStatusReq
                    // decode: namespace element
                    error = decode_iso2_ChargingStatusReqType(stream, &BodyType->ChargingStatusReq);
                    if (error == 0)
                    {
                        BodyType->ChargingStatusReq_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 12:
                    // Event: ChargingStatusRes
                    // decode: namespace element
                    error = decode_iso2_ChargingStatusResType(stream, &BodyType->ChargingStatusRes);
                    if (error == 0)
                    {
                        BodyType->ChargingStatusRes_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 13:
                    // Event: CurrentDemandReq
                    // decode: namespace element
                    error = decode_iso2_CurrentDemandReqType(stream, &BodyType->CurrentDemandReq);
                    if (error == 0)
                    {
                        BodyType->CurrentDemandReq_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 14:
                    // Event: CurrentDemandRes
                    // decode: namespace element
                    error = decode_iso2_CurrentDemandResType(stream, &BodyType->CurrentDemandRes);
                    if (error == 0)
                    {
                        BodyType->CurrentDemandRes_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 15:
                    // Event: MeteringReceiptReq
                    // decode: namespace element
                    error = decode_iso2_MeteringReceiptReqType(stream, &BodyType->MeteringReceiptReq);
                    if (error == 0)
                    {
                        BodyType->MeteringReceiptReq_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 16:
                    // Event: MeteringReceiptRes
                    // decode: namespace element
                    error = decode_iso2_MeteringReceiptResType(stream, &BodyType->MeteringReceiptRes);
                    if (error == 0)
                    {
                        BodyType->MeteringReceiptRes_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 17:
                    // Event: PaymentDetailsReq
                    // decode: namespace element
                    error = decode_iso2_PaymentDetailsReqType(stream, &BodyType->PaymentDetailsReq);
                    if (error == 0)
                    {
                        BodyType->PaymentDetailsReq_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 18:
                    // Event: PaymentDetailsRes
                    // decode: namespace element
                    error = decode_iso2_PaymentDetailsResType(stream, &BodyType->PaymentDetailsRes);
                    if (error == 0)
                    {
                        BodyType->PaymentDetailsRes_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 19:
                    // Event: PaymentServiceSelectionReq
                    // decode: namespace element
                    error = decode_iso2_PaymentServiceSelectionReqType(stream, &BodyType->PaymentServiceSelectionReq);
                    if (error == 0)
                    {
                        BodyType->PaymentServiceSelectionReq_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 20:
                    // Event: PaymentServiceSelectionRes
                    // decode: namespace element
                    error = decode_iso2_PaymentServiceSelectionResType(stream, &BodyType->PaymentServiceSelectionRes);
                    if (error == 0)
                    {
                        BodyType->PaymentServiceSelectionRes_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 21:
                    // Event: PowerDeliveryReq
                    // decode: namespace element
                    error = decode_iso2_PowerDeliveryReqType(stream, &BodyType->PowerDeliveryReq);
                    if (error == 0)
                    {
                        BodyType->PowerDeliveryReq_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 22:
                    // Event: PowerDeliveryRes
                    // decode: namespace element
                    error = decode_iso2_PowerDeliveryResType(stream, &BodyType->PowerDeliveryRes);
                    if (error == 0)
                    {
                        BodyType->PowerDeliveryRes_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 23:
                    // Event: PreChargeReq
                    // decode: namespace element
                    error = decode_iso2_PreChargeReqType(stream, &BodyType->PreChargeReq);
                    if (error == 0)
                    {
                        BodyType->PreChargeReq_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 24:
                    // Event: PreChargeRes
                    // decode: namespace element
                    error = decode_iso2_PreChargeResType(stream, &BodyType->PreChargeRes);
                    if (error == 0)
                    {
                        BodyType->PreChargeRes_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 25:
                    // Event: ServiceDetailReq
                    // decode: namespace element
                    error = decode_iso2_ServiceDetailReqType(stream, &BodyType->ServiceDetailReq);
                    if (error == 0)
                    {
                        BodyType->ServiceDetailReq_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 26:
                    // Event: ServiceDetailRes
                    // decode: namespace element
                    error = decode_iso2_ServiceDetailResType(stream, &BodyType->ServiceDetailRes);
                    if (error == 0)
                    {
                        BodyType->ServiceDetailRes_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 27:
                    // Event: ServiceDiscoveryReq
                    // decode: namespace element
                    error = decode_iso2_ServiceDiscoveryReqType(stream, &BodyType->ServiceDiscoveryReq);
                    if (error == 0)
                    {
                        BodyType->ServiceDiscoveryReq_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 28:
                    // Event: ServiceDiscoveryRes
                    // decode: namespace element
                    error = decode_iso2_ServiceDiscoveryResType(stream, &BodyType->ServiceDiscoveryRes);
                    if (error == 0)
                    {
                        BodyType->ServiceDiscoveryRes_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 29:
                    // Event: SessionSetupReq
                    // decode: namespace element
                    error = decode_iso2_SessionSetupReqType(stream, &BodyType->SessionSetupReq);
                    if (error == 0)
                    {
                        BodyType->SessionSetupReq_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 30:
                    // Event: SessionSetupRes
                    // decode: namespace element
                    error = decode_iso2_SessionSetupResType(stream, &BodyType->SessionSetupRes);
                    if (error == 0)
                    {
                        BodyType->SessionSetupRes_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 31:
                    // Event: SessionStopReq
                    // decode: namespace element
                    error = decode_iso2_SessionStopReqType(stream, &BodyType->SessionStopReq);
                    if (error == 0)
                    {
                        BodyType->SessionStopReq_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 32:
                    // Event: SessionStopRes
                    // decode: namespace element
                    error = decode_iso2_SessionStopResType(stream, &BodyType->SessionStopRes);
                    if (error == 0)
                    {
                        BodyType->SessionStopRes_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 33:
                    // Event: WeldingDetectionReq
                    // decode: namespace element
                    error = decode_iso2_WeldingDetectionReqType(stream, &BodyType->WeldingDetectionReq);
                    if (error == 0)
                    {
                        BodyType->WeldingDetectionReq_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;
                case 34:
                    // Event: WeldingDetectionRes
                    // decode: namespace element
                    error = decode_iso2_WeldingDetectionResType(stream, &BodyType->WeldingDetectionRes);
                    if (error == 0)
                    {
                        BodyType->WeldingDetectionRes_isUsed = 1u;
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;

        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:15118:2:2013:MsgDef}V2G_Message; type=AnonymousType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Header, MessageHeaderType (1, 1); Body, BodyType (1, 1);
static int decode_iso2_V2G_Message(exi_bitstream_t* stream, struct iso2_V2G_Message* V2G_Message) {
    int grammar_id = 415;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso2_V2G_Message(V2G_Message);

    while(!done)
    {
        switch(grammar_id)
        {
        case 415:
            // Grammar: ID=415; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=416
                    // decode: element
                    error = decode_iso2_MessageHeaderType(stream, &V2G_Message->Header);
                    if (error == 0)
                    {
                        grammar_id = 416;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 416:
            // Grammar: ID=416; read/write bits=1; START (Body)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Body, BodyType (BodyType)); next=3
                    // decode: element
                    error = decode_iso2_BodyType(stream, &V2G_Message->Body);
                    if (error == 0)
                    {
                        grammar_id = 3;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=3; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=4
                    done = 1;
                    grammar_id = 4;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}


// main function for decoding
int decode_iso2_exiDocument(exi_bitstream_t* stream, struct iso2_exiDocument* exiDoc)
{
    uint32_t eventCode;
    int error = exi_header_read_and_check(stream);

    if (error == EXI_ERROR__NO_ERROR)
    {
        init_iso2_exiDocument(exiDoc);

        error = exi_basetypes_decoder_nbit_uint(stream, 7, &eventCode);
        if (error == EXI_ERROR__NO_ERROR)
        {
            switch(eventCode)
            {
            case 0:
            case 76:
                error = decode_iso2_V2G_Message(stream, &exiDoc->V2G_Message);
                break;
            default:
                error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                break;
            }
        }
    }

    return error;
}



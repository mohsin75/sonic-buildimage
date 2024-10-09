/*****************************************************************
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated by xfc_map_parser
 * from the NPL output file(s) map.yml.
 * Edits to this file will be lost when it is regenerated.
 *
 * $Id: $
 * Copyright 2018-2024 Broadcom. All rights reserved.
 * The term 'Broadcom' refers to Broadcom Inc. and/or its subsidiaries.
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License 
 * version 2 as published by the Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * A copy of the GNU General Public License version 2 (GPLv2) can
 * be found in the LICENSES folder.
 * All Rights Reserved.$
 *
 * Tool Path: $SDK/INTERNAL/fltg/xfc_map_parser
 *
 ****************************************************************/

#ifndef BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_DATA_H
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_DATA_H

/*!
 * \name RX flex metadata field IDs.
 */
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_DROP_CODE_15_0                                 0
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_DVP_15_0                                       1
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_EFFECTIVE_TTL_7_0                              2
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_ENTROPY_LABEL_HIGH_3_0                         3
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_ENTROPY_LABEL_LOW_15_0                         4
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_EP_NIH_HDR_DROP_CODE_15_0                      5
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_EP_NIH_HDR_RECIRC_CODE_3_0                     6
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_EP_NIH_HDR_TIMESTAMP_15_0                      7
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_EP_NIH_HDR_TIMESTAMP_31_16                     8
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_ERSPAN3_GBP_SID_15_0                           9
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_EVENT_TRACE_VECTOR_15_0                        10
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_EVENT_TRACE_VECTOR_31_16                       11
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_EVENT_TRACE_VECTOR_47_32                       12
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_I2E_CLASS_ID_15_0                              13
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_ING_TIMESTAMP_15_0                             14
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_ING_TIMESTAMP_31_16                            15
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_INGRESS_PP_PORT_7_0                            16
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_INGRESS_QOS_REMAP_VALUE_OR_IFP_OPAQUE_OBJ_15_0 17
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_INGRESS_QOS_REMARK_CTRL_3_0                    18
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_INT_PRI_3_0                                    19
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_L2_IIF_10_0                                    20
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_L2_OIF_10_0                                    21
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_L2_TUNNEL_SVP_15_0                             22
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_L3_IIF_13_0                                    23
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_L3_OIF_1_13_0                                  24
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_NHOP_2_OR_ECMP_GROUP_INDEX_1_14_0              25
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_NHOP_INDEX_1_14_0                              26
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_PARSER_VHLEN_0_15_0                            27
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_PKT_MISC_CTRL_0_3_0                            28
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_SVP_NETWORK_GROUP_BITMAP_3_0                   29
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_SYSTEM_DESTINATION_15_0                        30
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_SYSTEM_OPCODE_3_0                              31
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_SYSTEM_SOURCE_15_0                             32
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_TAG_ACTION_CTRL_1_0                            33
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_TUNNEL_PROCESSING_RESULTS_1_3_0                34
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_VFI_15_0                                       35

#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_FID_COUNT                       36
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_COUNT                    21

/*!
 * \name Packet Flex Reason Types.
 */
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_CML_FLAGS                  0
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_IFP                        1
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_IFP_METER                  2
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_IVXLT                      3
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_L2_DST_LOOKUP              4
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_L2_DST_LOOKUP_MISS         5
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_L2_SRC_DISCARD             6
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_L2_SRC_STATIC_MOVE         7
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_L3_DST_LOOKUP              8
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_L3_DST_LOOKUP_MISS         9
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_L3_HDR_ERROR               10
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_L3_TTL_ERROR               11
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_LEARN_CACHE_FULL           12
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_MACSA_MULTICAST            13
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_MEMBERSHIP_CHECK_FAILED    14
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_NO_COPY_TO_CPU             15
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_PKT_INTEGRITY_CHECK_FAILED 16
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_PROTOCOL_PKT               17
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_SPANNING_TREE_CHECK_FAILED 18
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_TRACE_DOP                  19
#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_VFP                        20

#define BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_NAME_MAP_INIT \
    {"CML_FLAGS", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_CML_FLAGS},\
    {"IFP", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_IFP},\
    {"IFP_METER", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_IFP_METER},\
    {"IVXLT", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_IVXLT},\
    {"L2_DST_LOOKUP", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_L2_DST_LOOKUP},\
    {"L2_DST_LOOKUP_MISS", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_L2_DST_LOOKUP_MISS},\
    {"L2_SRC_DISCARD", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_L2_SRC_DISCARD},\
    {"L2_SRC_STATIC_MOVE", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_L2_SRC_STATIC_MOVE},\
    {"L3_DST_LOOKUP", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_L3_DST_LOOKUP},\
    {"L3_DST_LOOKUP_MISS", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_L3_DST_LOOKUP_MISS},\
    {"L3_HDR_ERROR", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_L3_HDR_ERROR},\
    {"L3_TTL_ERROR", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_L3_TTL_ERROR},\
    {"LEARN_CACHE_FULL", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_LEARN_CACHE_FULL},\
    {"MACSA_MULTICAST", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_MACSA_MULTICAST},\
    {"MEMBERSHIP_CHECK_FAILED", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_MEMBERSHIP_CHECK_FAILED},\
    {"NO_COPY_TO_CPU", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_NO_COPY_TO_CPU},\
    {"PKT_INTEGRITY_CHECK_FAILED", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_PKT_INTEGRITY_CHECK_FAILED},\
    {"PROTOCOL_PKT", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_PROTOCOL_PKT},\
    {"SPANNING_TREE_CHECK_FAILED", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_SPANNING_TREE_CHECK_FAILED},\
    {"TRACE_DOP", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_TRACE_DOP},\
    {"VFP", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_VFP},\
    {"flex reason count", BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_REASON_COUNT}

#endif /* BCM56780_A0_CNA_6_5_30_2_0_BCMPKT_RXPMD_FLEX_DATA_H */

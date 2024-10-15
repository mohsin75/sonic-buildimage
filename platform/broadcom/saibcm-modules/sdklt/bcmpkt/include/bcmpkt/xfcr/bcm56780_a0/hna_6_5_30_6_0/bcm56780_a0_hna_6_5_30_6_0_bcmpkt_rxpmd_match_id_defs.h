/*****************************************************************
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated by xfc_map_parser
 * from the NPL output file(s) bcm56780_a0_hna_6_5_30_6_0_sf_match_id_info.yml
 * for device bcm56780_a0 and variant hna_6_5_30_6_0.
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

#ifndef BCM56780_A0_HNA_6_5_30_6_0_BCMPKT_RXPMD_MATCH_ID_DEFS_H
#define BCM56780_A0_HNA_6_5_30_6_0_BCMPKT_RXPMD_MATCH_ID_DEFS_H

#include <bcmpkt/bcmpkt_rxpmd_match_id.h>

/*!
 * \brief Get the Match ID DataBase information.
 *
 * \retval bcmpkt_rxpmd_match_id_db_info_t Match ID DataBase information.
*/
extern bcmpkt_rxpmd_match_id_db_info_t *
    bcm56780_a0_hna_6_5_30_6_0_rxpmd_match_id_db_info_get(void);

/*!
 * \brief Get the Match ID Mapping information.
 *
 * \retval bcmpkt_rxpmd_match_id_map_info_t Match ID Mapping information.
*/
extern bcmpkt_rxpmd_match_id_map_info_t *
    bcm56780_a0_hna_6_5_30_6_0_rxpmd_match_id_map_info_get(void);

/*!
  \name RXPMD Match IDs
*/
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L2_HDR_ETAG  0
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L2_HDR_ITAG  1
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L2_HDR_L2  2
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L2_HDR_NONE  3
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L2_HDR_OTAG  4
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L2_HDR_SNAP_OR_LLC  5
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L2_HDR_SVTAG  6
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L2_HDR_VNTAG  7
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_ARP  8
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_AUTH_EXT_1  9
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_AUTH_EXT_2  10
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_BFD  11
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_ESP_EXT  12
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_ETHERTYPE  13
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_FRAG_EXT_1  14
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_FRAG_EXT_2  15
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_GPE  16
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_GRE  17
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_GRE_CHKSUM  18
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_GRE_KEY  19
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_GRE_ROUT  20
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_GRE_SEQ  21
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_ICMP  22
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_IFA_METADATA  23
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_IGMP  24
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_IPV4  25
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_IPV6  26
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS0  27
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS1  28
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS2  29
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS3  30
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS4  31
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS5  32
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS6  33
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS_ACH  34
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS_CW  35
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_NONE  36
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_P_1588  37
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_RARP  38
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_TCP_FIRST_4BYTES  39
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_TCP_LAST_16BYTES  40
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_UDP  41
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_UNKNOWN_L3  42
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_UNKNOWN_L4  43
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_UNKNOWN_L5  44
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_VXLAN  45
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_SYS_HDR_EP_NIH  46
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_SYS_HDR_LOOPBACK  47
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_SYS_HDR_NONE  48
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L2_HDR_ETAG  49
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L2_HDR_ITAG  50
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L2_HDR_L2  51
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L2_HDR_NONE  52
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L2_HDR_OTAG  53
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L2_HDR_SNAP_OR_LLC  54
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L2_HDR_SVTAG  55
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L2_HDR_VNTAG  56
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_ARP  57
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_AUTH_EXT_1  58
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_AUTH_EXT_2  59
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_BFD  60
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_ESP_EXT  61
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_ETHERTYPE  62
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_FRAG_EXT_1  63
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_FRAG_EXT_2  64
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_GPE  65
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_GRE  66
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_GRE_CHKSUM  67
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_GRE_KEY  68
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_GRE_ROUT  69
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_GRE_SEQ  70
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_ICMP  71
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_IFA_METADATA  72
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_IGMP  73
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_IPV4  74
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_IPV6  75
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS0  76
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS1  77
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS2  78
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS3  79
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS4  80
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS5  81
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS6  82
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS_ACH  83
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS_CW  84
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_NONE  85
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_P_1588  86
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_RARP  87
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_TCP_FIRST_4BYTES  88
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_TCP_LAST_16BYTES  89
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_UDP  90
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_UNKNOWN_L3  91
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_UNKNOWN_L4  92
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_UNKNOWN_L5  93
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_VXLAN  94
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L2_HDR_ETAG  95
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L2_HDR_ITAG  96
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L2_HDR_L2  97
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L2_HDR_NONE  98
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L2_HDR_OTAG  99
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L2_HDR_SNAP_OR_LLC  100
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L2_HDR_VNTAG  101
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_ARP  102
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_AUTH_EXT_1  103
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_AUTH_EXT_2  104
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_BFD  105
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_ESP_EXT  106
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_ETHERTYPE  107
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_FRAG_EXT_1  108
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_FRAG_EXT_2  109
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_ICMP  110
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_IFA_METADATA  111
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_IGMP  112
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_IPV4  113
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_IPV6  114
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_NONE  115
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_P_1588  116
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_RARP  117
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_TCP_FIRST_4BYTES  118
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_TCP_LAST_16BYTES  119
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_UDP  120
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_UNKNOWN_L3  121
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_UNKNOWN_L4  122
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_UNKNOWN_L5  123
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L2_HDR_ETAG  124
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L2_HDR_ITAG  125
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L2_HDR_L2  126
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L2_HDR_NONE  127
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L2_HDR_OTAG  128
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L2_HDR_SNAP_OR_LLC  129
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L2_HDR_SVTAG  130
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L2_HDR_VNTAG  131
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_ARP  132
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_AUTH_EXT_1  133
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_AUTH_EXT_2  134
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_BFD  135
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_ESP_EXT  136
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_ETHERTYPE  137
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_FRAG_EXT_1  138
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_FRAG_EXT_2  139
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_GPE  140
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_GRE  141
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_GRE_CHKSUM  142
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_GRE_KEY  143
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_GRE_ROUT  144
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_GRE_SEQ  145
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_ICMP  146
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_IFA_METADATA  147
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_IGMP  148
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_IPV4  149
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_IPV6  150
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS0  151
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS1  152
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS2  153
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS3  154
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS4  155
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS5  156
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS6  157
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS_ACH  158
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS_CW  159
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_NONE  160
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_P_1588  161
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_RARP  162
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_TCP_FIRST_4BYTES  163
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_TCP_LAST_16BYTES  164
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_UDP  165
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_UNKNOWN_L3  166
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_UNKNOWN_L4  167
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_UNKNOWN_L5  168
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_VXLAN  169
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_SYS_HDR_EP_NIH  170
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_SYS_HDR_LOOPBACK  171
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_SYS_HDR_NONE  172
#define BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_COUNT  173

#define BCM56780_A0_HNA_6_5_30_6_0_BCMPKT_RXPMD_MATCH_ID_FIELD_NAME_MAP_INIT \
    {"EGRESS_PKT_FWD_L2_HDR_ETAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L2_HDR_ETAG}, \
    {"EGRESS_PKT_FWD_L2_HDR_ITAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L2_HDR_ITAG}, \
    {"EGRESS_PKT_FWD_L2_HDR_L2", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L2_HDR_L2}, \
    {"EGRESS_PKT_FWD_L2_HDR_NONE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L2_HDR_NONE}, \
    {"EGRESS_PKT_FWD_L2_HDR_OTAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L2_HDR_OTAG}, \
    {"EGRESS_PKT_FWD_L2_HDR_SNAP_OR_LLC", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L2_HDR_SNAP_OR_LLC}, \
    {"EGRESS_PKT_FWD_L2_HDR_SVTAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L2_HDR_SVTAG}, \
    {"EGRESS_PKT_FWD_L2_HDR_VNTAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L2_HDR_VNTAG}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_ARP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_ARP}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_AUTH_EXT_1", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_AUTH_EXT_1}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_AUTH_EXT_2", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_AUTH_EXT_2}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_BFD", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_BFD}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_ESP_EXT", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_ESP_EXT}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_ETHERTYPE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_ETHERTYPE}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_FRAG_EXT_1", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_FRAG_EXT_1}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_FRAG_EXT_2", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_FRAG_EXT_2}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_GPE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_GPE}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_GRE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_GRE}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_GRE_CHKSUM", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_GRE_CHKSUM}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_GRE_KEY", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_GRE_KEY}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_GRE_ROUT", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_GRE_ROUT}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_GRE_SEQ", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_GRE_SEQ}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_ICMP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_ICMP}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_IFA_METADATA", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_IFA_METADATA}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_IGMP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_IGMP}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_IPV4", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_IPV4}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_IPV6", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_IPV6}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_MPLS0", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS0}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_MPLS1", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS1}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_MPLS2", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS2}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_MPLS3", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS3}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_MPLS4", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS4}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_MPLS5", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS5}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_MPLS6", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS6}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_MPLS_ACH", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS_ACH}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_MPLS_CW", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_MPLS_CW}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_NONE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_NONE}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_P_1588", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_P_1588}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_RARP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_RARP}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_TCP_FIRST_4BYTES", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_TCP_FIRST_4BYTES}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_TCP_LAST_16BYTES", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_TCP_LAST_16BYTES}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_UDP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_UDP}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_UNKNOWN_L3", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_UNKNOWN_L3}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_UNKNOWN_L4", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_UNKNOWN_L4}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_UNKNOWN_L5", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_UNKNOWN_L5}, \
    {"EGRESS_PKT_FWD_L3_L4_HDR_VXLAN", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_FWD_L3_L4_HDR_VXLAN}, \
    {"EGRESS_PKT_SYS_HDR_EP_NIH", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_SYS_HDR_EP_NIH}, \
    {"EGRESS_PKT_SYS_HDR_LOOPBACK", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_SYS_HDR_LOOPBACK}, \
    {"EGRESS_PKT_SYS_HDR_NONE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_SYS_HDR_NONE}, \
    {"EGRESS_PKT_TUNNEL_L2_HDR_ETAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L2_HDR_ETAG}, \
    {"EGRESS_PKT_TUNNEL_L2_HDR_ITAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L2_HDR_ITAG}, \
    {"EGRESS_PKT_TUNNEL_L2_HDR_L2", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L2_HDR_L2}, \
    {"EGRESS_PKT_TUNNEL_L2_HDR_NONE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L2_HDR_NONE}, \
    {"EGRESS_PKT_TUNNEL_L2_HDR_OTAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L2_HDR_OTAG}, \
    {"EGRESS_PKT_TUNNEL_L2_HDR_SNAP_OR_LLC", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L2_HDR_SNAP_OR_LLC}, \
    {"EGRESS_PKT_TUNNEL_L2_HDR_SVTAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L2_HDR_SVTAG}, \
    {"EGRESS_PKT_TUNNEL_L2_HDR_VNTAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L2_HDR_VNTAG}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_ARP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_ARP}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_AUTH_EXT_1", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_AUTH_EXT_1}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_AUTH_EXT_2", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_AUTH_EXT_2}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_BFD", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_BFD}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_ESP_EXT", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_ESP_EXT}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_ETHERTYPE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_ETHERTYPE}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_FRAG_EXT_1", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_FRAG_EXT_1}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_FRAG_EXT_2", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_FRAG_EXT_2}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_GPE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_GPE}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_GRE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_GRE}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_GRE_CHKSUM", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_GRE_CHKSUM}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_GRE_KEY", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_GRE_KEY}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_GRE_ROUT", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_GRE_ROUT}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_GRE_SEQ", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_GRE_SEQ}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_ICMP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_ICMP}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_IFA_METADATA", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_IFA_METADATA}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_IGMP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_IGMP}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_IPV4", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_IPV4}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_IPV6", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_IPV6}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS0", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS0}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS1", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS1}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS2", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS2}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS3", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS3}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS4", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS4}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS5", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS5}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS6", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS6}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS_ACH", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS_ACH}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS_CW", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_MPLS_CW}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_NONE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_NONE}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_P_1588", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_P_1588}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_RARP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_RARP}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_TCP_FIRST_4BYTES", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_TCP_FIRST_4BYTES}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_TCP_LAST_16BYTES", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_TCP_LAST_16BYTES}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_UDP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_UDP}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_UNKNOWN_L3", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_UNKNOWN_L3}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_UNKNOWN_L4", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_UNKNOWN_L4}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_UNKNOWN_L5", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_UNKNOWN_L5}, \
    {"EGRESS_PKT_TUNNEL_L3_L4_HDR_VXLAN", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_EGRESS_PKT_TUNNEL_L3_L4_HDR_VXLAN}, \
    {"INGRESS_PKT_INNER_L2_HDR_ETAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L2_HDR_ETAG}, \
    {"INGRESS_PKT_INNER_L2_HDR_ITAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L2_HDR_ITAG}, \
    {"INGRESS_PKT_INNER_L2_HDR_L2", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L2_HDR_L2}, \
    {"INGRESS_PKT_INNER_L2_HDR_NONE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L2_HDR_NONE}, \
    {"INGRESS_PKT_INNER_L2_HDR_OTAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L2_HDR_OTAG}, \
    {"INGRESS_PKT_INNER_L2_HDR_SNAP_OR_LLC", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L2_HDR_SNAP_OR_LLC}, \
    {"INGRESS_PKT_INNER_L2_HDR_VNTAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L2_HDR_VNTAG}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_ARP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_ARP}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_AUTH_EXT_1", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_AUTH_EXT_1}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_AUTH_EXT_2", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_AUTH_EXT_2}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_BFD", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_BFD}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_ESP_EXT", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_ESP_EXT}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_ETHERTYPE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_ETHERTYPE}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_FRAG_EXT_1", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_FRAG_EXT_1}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_FRAG_EXT_2", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_FRAG_EXT_2}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_ICMP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_ICMP}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_IFA_METADATA", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_IFA_METADATA}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_IGMP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_IGMP}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_IPV4", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_IPV4}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_IPV6", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_IPV6}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_NONE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_NONE}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_P_1588", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_P_1588}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_RARP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_RARP}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_TCP_FIRST_4BYTES", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_TCP_FIRST_4BYTES}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_TCP_LAST_16BYTES", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_TCP_LAST_16BYTES}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_UDP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_UDP}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_UNKNOWN_L3", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_UNKNOWN_L3}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_UNKNOWN_L4", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_UNKNOWN_L4}, \
    {"INGRESS_PKT_INNER_L3_L4_HDR_UNKNOWN_L5", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_INNER_L3_L4_HDR_UNKNOWN_L5}, \
    {"INGRESS_PKT_OUTER_L2_HDR_ETAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L2_HDR_ETAG}, \
    {"INGRESS_PKT_OUTER_L2_HDR_ITAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L2_HDR_ITAG}, \
    {"INGRESS_PKT_OUTER_L2_HDR_L2", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L2_HDR_L2}, \
    {"INGRESS_PKT_OUTER_L2_HDR_NONE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L2_HDR_NONE}, \
    {"INGRESS_PKT_OUTER_L2_HDR_OTAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L2_HDR_OTAG}, \
    {"INGRESS_PKT_OUTER_L2_HDR_SNAP_OR_LLC", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L2_HDR_SNAP_OR_LLC}, \
    {"INGRESS_PKT_OUTER_L2_HDR_SVTAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L2_HDR_SVTAG}, \
    {"INGRESS_PKT_OUTER_L2_HDR_VNTAG", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L2_HDR_VNTAG}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_ARP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_ARP}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_AUTH_EXT_1", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_AUTH_EXT_1}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_AUTH_EXT_2", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_AUTH_EXT_2}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_BFD", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_BFD}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_ESP_EXT", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_ESP_EXT}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_ETHERTYPE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_ETHERTYPE}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_FRAG_EXT_1", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_FRAG_EXT_1}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_FRAG_EXT_2", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_FRAG_EXT_2}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_GPE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_GPE}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_GRE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_GRE}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_GRE_CHKSUM", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_GRE_CHKSUM}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_GRE_KEY", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_GRE_KEY}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_GRE_ROUT", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_GRE_ROUT}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_GRE_SEQ", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_GRE_SEQ}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_ICMP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_ICMP}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_IFA_METADATA", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_IFA_METADATA}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_IGMP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_IGMP}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_IPV4", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_IPV4}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_IPV6", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_IPV6}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_MPLS0", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS0}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_MPLS1", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS1}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_MPLS2", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS2}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_MPLS3", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS3}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_MPLS4", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS4}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_MPLS5", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS5}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_MPLS6", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS6}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_MPLS_ACH", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS_ACH}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_MPLS_CW", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_MPLS_CW}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_NONE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_NONE}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_P_1588", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_P_1588}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_RARP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_RARP}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_TCP_FIRST_4BYTES", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_TCP_FIRST_4BYTES}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_TCP_LAST_16BYTES", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_TCP_LAST_16BYTES}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_UDP", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_UDP}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_UNKNOWN_L3", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_UNKNOWN_L3}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_UNKNOWN_L4", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_UNKNOWN_L4}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_UNKNOWN_L5", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_UNKNOWN_L5}, \
    {"INGRESS_PKT_OUTER_L3_L4_HDR_VXLAN", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_OUTER_L3_L4_HDR_VXLAN}, \
    {"INGRESS_PKT_SYS_HDR_EP_NIH", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_SYS_HDR_EP_NIH}, \
    {"INGRESS_PKT_SYS_HDR_LOOPBACK", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_SYS_HDR_LOOPBACK}, \
    {"INGRESS_PKT_SYS_HDR_NONE", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_INGRESS_PKT_SYS_HDR_NONE}, \
    {"rxpmd_match_id_count", BCM56780_A0_HNA_6_5_30_6_0_RXPMD_MATCH_ID_COUNT}

#endif /*! BCM56780_A0_HNA_6_5_30_6_0_BCMPKT_RXPMD_MATCH_ID_DEFS_H */

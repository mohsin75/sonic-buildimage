/*
 * Copyright (C) 2009-2020 Realtek Semiconductor Corp.
 * All Rights Reserved.
 *
 * This program is the proprietary software of Realtek Semiconductor
 * Corporation and/or its licensors, and only be used, duplicated,
 * modified or distributed under the authorized license from Realtek.
 *
 * ANY USE OF THE SOFTWARE OTHER THAN AS AUTHORIZED UNDER
 * THIS LICENSE OR COPYRIGHT LAW IS PROHIBITED.
 *
 * $Revision: 104061 $
 * $Date: 2020-02-14 13:24:09 +0800 (Fri, 14 Feb 2020) $
 *
 * Purpose : Definition of Port API
 *
 * Feature : The file have include the following module and sub-modules
 *           (1) PHY functions
 */

/*
 * Include Files
 */
#include <common/rt_type.h>
#include <common/rt_error.h>
#include <common/util/rt_util.h>
#include <dal/dal_mgmt.h>
#include <dal/dal_linkMon.h>
#include <rtk/default.h>
#include <rtk/port.h>
#include <dal/dal_waMon.h>

/*
 * Symbol Definition
 */

/*
 * Data Declaration
 */

/*
 * Function Declaration
 */

/* Function Name:
 *      rtk_phy_init
 * Description:
 *      Initialize phy module of the specified device.
 * Input:
 *      unit - unit id
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID - invalid unit id
 * Applicable:
 *      8261, 8264, 8380, 8390, 9300, 9310
 * Note:
 *      Must initialize port module before calling any port APIs.
 * Changes:
 *      None
 */
int32
rtk_phy_init(uint32 unit)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->phy_init(unit);
} /* end of rtk_phy_init */

/* Module Name    : PHY                                       */
/* Sub-module Name: Parameter settings for the port-based view */

/* Function Name:
 *      rtk_port_linkMedia_get
 * Description:
 *      Get the link status with media information of the specific port
 * Input:
 *      unit    - unit id
 *      port    - port id
 * Output:
 *      pStatus - pointer to the link status
 *      pMedia  - pointer to the media type
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8380, 8390, 9300, 9310
 * Note:
 *      (1) The link status of the port is as following:
 *          - PORT_LINKDOWN
 *          - PORT_LINKUP
 *      (2) The media type of the port is as following:
 *          - PORT_MEDIA_COPPER
 *          - PORT_MEDIA_FIBER
 *      (3) When the link status is link-down, the return media should be ignored.
 * Changes:
 *      None
 */
int32
rtk_port_linkMedia_get(uint32 unit, rtk_port_t port, rtk_port_linkStatus_t *pStatus, rtk_port_media_t *pMedia)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_linkMedia_get(unit, port, pStatus, pMedia);
} /* end of rtk_port_linkMedia_get */

/* Function Name:
 *      rtk_port_speedDuplex_get
 * Description:
 *      Get the negotiated port speed and duplex status of the specific port
 * Input:
 *      unit    - unit id
 *      port    - port id
 * Output:
 *      pSpeed  - pointer to the port speed
 *      pDuplex - pointer to the port duplex
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID       - invalid unit id
 *      RT_ERR_NOT_INIT      - The module is not initial
 *      RT_ERR_PORT_ID       - invalid port id
 *      RT_ERR_NULL_POINTER  - input parameter may be null pointer
 *      RT_ERR_PORT_LINKDOWN - link down port status
 * Applicable:
 *      8261, 8264, 8380, 8390, 9300, 9310
 * Note:
 *      (1) The speed type of the port is as following:
 *          - PORT_SPEED_10M
 *          - PORT_SPEED_100M
 *          - PORT_SPEED_1000M
 *          - PORT_SPEED_2G  (Applicable to 8380)
 *          - PORT_SPEED_10G (Applicable to 8390)
 *          - PORT_SPEED_500M (Applicable to 9300, 9310)
 *          - PORT_SPEED_2_5G (Applicable to 9300, 9310)
 *          - PORT_SPEED_5G (Applicable to 9300, 9310)
 *      (2) The duplex mode of the port is as following:
 *          - PORT_HALF_DUPLEX
 *          - PORT_FULL_DUPLEX
 * Changes:
 *      None
 */
int32
rtk_port_speedDuplex_get(
    uint32            unit,
    rtk_port_t        port,
    rtk_port_speed_t  *pSpeed,
    rtk_port_duplex_t *pDuplex)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_speedDuplex_get(unit, port, pSpeed, pDuplex);

} /* end of rtk_port_speedDuplex_get */

/* Function Name:
 *      rtk_port_adminEnable_get
 * Description:
 *      Get port admin status of the specific port
 * Input:
 *      unit    - unit id
 *      port    - port id
 * Output:
 *      pEnable - pointer to the port admin status
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8380, 8390, 9300, 9310
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_adminEnable_get(uint32 unit, rtk_port_t port, rtk_enable_t *pEnable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_adminEnable_get(unit, port, pEnable);

} /* end of rtk_port_adminEnable_get */

/* Function Name:
 *      rtk_port_adminEnable_set
 * Description:
 *      Set port admin configuration of the specific port
 * Input:
 *      unit   - unit id
 *      port   - port id
 *      enable - port admin configuration
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT_ID  - invalid port id
 *      RT_ERR_INPUT    - invalid input parameter
 * Applicable:
 *      8261, 8264, 8380, 8390, 9300, 9310
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_adminEnable_set(uint32 unit, rtk_port_t port, rtk_enable_t enable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_adminEnable_set(unit, port, enable);

} /* end of rtk_port_adminEnable_set */

/* Function Name:
 *      rtk_port_phyAutoNegoEnable_get
 * Description:
 *      Get PHY ability of the specific port
 * Input:
 *      unit    - unit id
 *      port    - port id
 * Output:
 *      pEnable - pointer to PHY auto negotiation status
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8208G, 8208D, 8208L, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8295R, 8214QF, 8218D, 9300SDS, 8390SDS, 8380SDS, 9310SDS, 8226, 8226B
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phyAutoNegoEnable_get(uint32 unit, rtk_port_t port, rtk_enable_t *pEnable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyAutoNegoEnable_get(unit, port, pEnable);

} /* end of rtk_port_phyAutoNegoEnable_get */

/* Function Name:
 *      rtk_port_phyAutoNegoEnable_set
 * Description:
 *      Set PHY ability of the specific port
 * Input:
 *      unit   - unit id
 *      port   - port id
 *      enable - enable PHY auto negotiation
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT_ID  - invalid port id
 *      RT_ERR_INPUT    - input parameter out of range
 * Applicable:
 *      8208G, 8208D, 8208L, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8295R, 8214QF, 8218D, 9300SDS, 8390SDS, 8380SDS, 9310SDS, 8226, 8226B
 * Note:
 *      - ENABLED : switch to PHY auto negotiation mode
 *      - DISABLED: switch to PHY force mode
 *      - Once the abilities of both auto-nego and force mode are set,
 *        you can freely switch the mode without calling ability setting API again
 * Changes:
 *      None
 */
int32
rtk_port_phyAutoNegoEnable_set(uint32 unit, rtk_port_t port, rtk_enable_t enable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyAutoNegoEnable_set(unit, port, enable);

}

/* Function Name:
 *      rtk_port_phyAutoNegoAbilityLocal_get
 * Description:
 *      Get complete abilities for auto negotiation of the specific port
 * Input:
 *      unit    - unit id
 *      port    - port id
 *
 * Output:
 *      pAbility - pointer to PHY auto negotiation ability
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264
 * Note:
 *      None
 * Changes:
 *      [SDK_3.8.0]
 *          New added function.
 */
int32
rtk_port_phyAutoNegoAbilityLocal_get(uint32 unit, rtk_port_t port, rtk_port_phy_ability_t *pAbility)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyAutoNegoAbilityLocal_get(unit, port, pAbility);
}

/* Function Name:
 *      rtk_port_phyAutoNegoAbility_get
 * Description:
 *      Get PHY auto negotiation ability of the specific port
 * Input:
 *      unit    - unit id
 *      port    - port id
 * Output:
 *      pAbility - pointer to the PHY ability
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8208G, 8208D, 8208L, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8295R, 8214QF, 8218D, 9300SDS, 8390SDS, 8380SDS, 9310SDS, 8226, 8226B
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phyAutoNegoAbility_get(
    uint32                  unit,
    rtk_port_t              port,
    rtk_port_phy_ability_t  *pAbility)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyAutoNegoAbility_get(unit, port, pAbility);

} /* end of rtk_port_phyAutoNegoAbility_get */

/* Function Name:
 *      rtk_port_phyAutoNegoAbility_set
 * Description:
 *      Set PHY auto negotiation ability of the specific port
 * Input:
 *      unit     - unit id
 *      port     - port id
 *      pAbility - pointer to the PHY ability
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8208G, 8208D, 8208L, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8295R, 8214QF, 8218D, 9300SDS, 8390SDS, 8380SDS, 9310SDS, 8226, 8226B
 * Note:
 *      You can set these abilities no matter which mode PHY currently stays on
 * Changes:
 *      None
 */
int32
rtk_port_phyAutoNegoAbility_set(
    uint32                  unit,
    rtk_port_t              port,
    rtk_port_phy_ability_t  *pAbility)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyAutoNegoAbility_set(unit, port, pAbility);

} /* end of rtk_port_phyAutoNegoAbility_set */

/* Function Name:
 *      rtk_port_phyForceModeAbility_get
 * Description:
 *      Get PHY ability status of the specific port
 * Input:
 *      unit         - unit id
 *      port         - port id
 * Output:
 *      pSpeed       - pointer to the port speed
 *      pDuplex      - pointer to the port duplex
 *      pFlowControl - pointer to the flow control enable status
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8208G, 8208D, 8208L, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8295R, 8214QF, 8218D, 9300SDS, 8390SDS, 8380SDS, 9310SDS
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phyForceModeAbility_get(
    uint32              unit,
    rtk_port_t          port,
    rtk_port_speed_t    *pSpeed,
    rtk_port_duplex_t   *pDuplex,
    rtk_enable_t        *pFlowControl)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyForceModeAbility_get(unit, port, pSpeed, pDuplex, pFlowControl);

} /* end of rtk_port_phyForceModeAbility_get */

/* Function Name:
 *      rtk_port_phyForceModeAbility_set
 * Description:
 *      Set the port speed/duplex mode/pause/asy_pause in the PHY force mode
 * Input:
 *      unit        - unit id
 *      port        - port id
 *      speed       - port speed
 *      duplex      - port duplex mode
 *      flowControl - enable flow control
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID    - invalid unit id
 *      RT_ERR_NOT_INIT   - The module is not initial
 *      RT_ERR_PORT_ID    - invalid port id
 *      RT_ERR_PHY_SPEED  - invalid PHY speed setting
 *      RT_ERR_PHY_DUPLEX - invalid PHY duplex setting
 *      RT_ERR_INPUT      - invalid input parameter
 * Applicable:
 *      8261, 8264, 8208G, 8208D, 8208L, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8295R, 8214QF, 8218D, 9300SDS, 8390SDS, 8380SDS, 9310SDS
 * Note:
 *      (1) You can set these abilities no matter which mode PHY currently stays on
 *      (2) The speed type of the port is as following:
 *          - PORT_SPEED_10M
 *          - PORT_SPEED_100M
 *          - PORT_SPEED_1000M (only for fiber media)
 *      (3) The duplex mode of the port is as following:
 *          - PORT_HALF_DUPLEX
 *          - PORT_FULL_DUPLEX
 * Changes:
 *      None
 */
int32
rtk_port_phyForceModeAbility_set(
    uint32              unit,
    rtk_port_t          port,
    rtk_port_speed_t    speed,
    rtk_port_duplex_t   duplex,
    rtk_enable_t        flowControl)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyForceModeAbility_set(unit, port, speed, duplex, flowControl);

} /* end of rtk_port_phyForceModeAbility_set */

/* Function Name:
 *      rtk_port_phyForceFlowctrlMode_get
 * Description:
 *      Get the port flow control mode in the PHY force mode
 * Input:
 *      unit        - unit id
 *      port        - port id
 * Output:
 *      pMode     - pointer to the port flow control mode
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID    - invalid unit id
 *      RT_ERR_NOT_INIT   - The module is not initial
 *      RT_ERR_PORT_ID    - invalid port id
 *      RT_ERR_PHY_SPEED  - invalid PHY speed setting
 *      RT_ERR_PHY_DUPLEX - invalid PHY duplex setting
 *      RT_ERR_INPUT      - invalid input parameter
 * Applicable:
 *      8380, 8390, 9300, 9310
 * Note:
 *      None
 * Changes:
 *      [3.2.0]
 *          New added function.
 */
int32
rtk_port_phyForceFlowctrlMode_get(
    uint32                      unit,
    rtk_port_t                  port,
    rtk_port_flowctrl_mode_t    *pMode)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyForceFlowctrlMode_get(unit, port, pMode);
}/* end of rtk_port_phyForceFlowctrlMode_get */

/* Function Name:
 *      rtk_port_phyForceFlowctrlMode_set
 * Description:
 *      Set the port flow control mode in the PHY force mode.
 * Input:
 *      unit        - unit id
 *      port        - port id
 *      pMode     - pointer to the port flow control mode
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID    - invalid unit id
 *      RT_ERR_NOT_INIT   - The module is not initial
 *      RT_ERR_PORT_ID    - invalid port id
 *      RT_ERR_PHY_SPEED  - invalid PHY speed setting
 *      RT_ERR_PHY_DUPLEX - invalid PHY duplex setting
 *      RT_ERR_INPUT      - invalid input parameter
 * Applicable:
 *      8380, 8390SDS, 9300, 9310SDS
 * Note:
 *      This API configure the flow control mode to a software shadow database,
 *      it shall use together with rtk_port_phyForceModeAbility_set() to apply the config to the chip.
 * Changes:
 *      [3.2.0]
 *          New added function.
 */
int32
rtk_port_phyForceFlowctrlMode_set(
    uint32                      unit,
    rtk_port_t                  port,
    rtk_port_flowctrl_mode_t    *pMode)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyForceFlowctrlMode_set(unit, port, pMode);
}/* end of rtk_port_phyForceFlowctrlMode_set */

/* Function Name:
 *      rtk_port_phyMasterSlave_get
 * Description:
 *      Get PHY configuration of master/slave mode of the specific port
 * Input:
 *      unit                - unit id
 *      port                - port id
 * Output:
 *      pMasterSlaveCfg     - pointer to the PHY master slave configuration
 *      pMasterSlaveActual  - pointer to the PHY master slave actual link status
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8208G, 8208D, 8208L, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8218D, 8226, 8226B
 * Note:
 *      This function only works on giga/ 10g port to get its master/slave mode configuration.
 * Changes:
 *      None
 */
int32
rtk_port_phyMasterSlave_get(
    uint32              unit,
    rtk_port_t          port,
    rtk_port_masterSlave_t   *pMasterSlaveCfg,
    rtk_port_masterSlave_t   *pMasterSlaveActual)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyMasterSlave_get(unit, port, pMasterSlaveCfg, pMasterSlaveActual);
}/* end of rtk_port_phyMasterSlave_get */

/* Function Name:
 *      rtk_port_phyMasterSlave_set
 * Description:
 *      Set PHY configuration of master/slave mode of the specific port
 * Input:
 *      unit        - unit id
 *      port        - port id
 *      masterSlave - PHY master slave configuration
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT_ID  - invalid port id
 *      RT_ERR_INPUT    - invalid input parameter
 * Applicable:
 *      8261, 8264, 8208G, 8208D, 8208L, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8218D, 8226, 8226B
 * Note:
 *      This function only works on giga/ 10g port to set its master/slave mode configuration.
 * Changes:
 *      None
 */
int32
rtk_port_phyMasterSlave_set(
    uint32                  unit,
    rtk_port_t              port,
    rtk_port_masterSlave_t  masterSlave)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyMasterSlave_set(unit, port, masterSlave);
}/* end of rtk_port_phyMasterSlave_set */

/* Function Name:
 *      rtk_port_phyReg_get
 * Description:
 *      Get PHY register data of the specific port
 * Input:
 *      unit  - unit id
 *      port  - port id
 *      page  - page id
 *      reg   - reg id
 * Output:
 *      pData - pointer to the PHY reg data
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_PHY_PAGE_ID  - invalid page id
 *      RT_ERR_PHY_REG_ID   - invalid reg id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8208G, 8208D, 8208L, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8295R, 8214QF, 8218D, 9300SDS, 8380SDS
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phyReg_get(
    uint32              unit,
    rtk_port_t          port,
    uint32              page,
    rtk_port_phy_reg_t  reg,
    uint32              *pData)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyReg_get(unit, port, page, reg, pData);

} /* end of rtk_port_phyReg_get */

/* Function Name:
 *      rtk_port_phyReg_set
 * Description:
 *      Set PHY register data of the specific port
 * Input:
 *      unit - unit id
 *      port - port id
 *      page - page id
 *      reg  - reg id
 *      data - reg data
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID     - invalid unit id
 *      RT_ERR_NOT_INIT    - The module is not initial
 *      RT_ERR_PORT_ID     - invalid port id
 *      RT_ERR_PHY_PAGE_ID - invalid page id
 *      RT_ERR_PHY_REG_ID  - invalid reg id
 * Applicable:
 *      8261, 8264, 8208G, 8208D, 8208L, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8295R, 8214QF, 8218D, 9300SDS, 8380SDS
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phyReg_set(
    uint32              unit,
    rtk_port_t          port,
    uint32              page,
    rtk_port_phy_reg_t  reg,
    uint32              data)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyReg_set(unit, port, page, reg, data);

} /* end of rtk_port_phyReg_set */

/* Function Name:
 *      rtk_port_phyExtParkPageReg_get
 * Description:
 *      Get PHY register data of the specific port with extension page and parking page parameters
 * Input:
 *      unit     - unit id
 *      port     - port id
 *      mainPage - main page id
 *      extPage  - extension page id
 *      parkPage - parking page id
 *      reg      - reg id
 * Output:
 *      pData    - pointer to the PHY reg data
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_PHY_PAGE_ID  - invalid page id
 *      RT_ERR_PHY_REG_ID   - invalid reg id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8390
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phyExtParkPageReg_get(
    uint32              unit,
    rtk_port_t          port,
    uint32              mainPage,
    uint32              extPage,
    uint32              parkPage,
    rtk_port_phy_reg_t  reg,
    uint32              *pData)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyExtParkPageReg_get(unit, port, mainPage, extPage, parkPage, reg, pData);
} /* end of rtk_port_phyExtParkPageReg_get */

/* Function Name:
 *      rtk_port_phyExtParkPageReg_set
 * Description:
 *      Set PHY register data of the specific port with extension page and parking page parameters
 * Input:
 *      unit     - unit id
 *      port     - port id
 *      mainPage - main page id
 *      extPage  - extension page id
 *      parkPage - parking page id
 *      reg      - reg id
 *      data     - reg data
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID     - invalid unit id
 *      RT_ERR_NOT_INIT    - The module is not initial
 *      RT_ERR_PORT_ID     - invalid port id
 *      RT_ERR_PHY_PAGE_ID - invalid page id
 *      RT_ERR_PHY_REG_ID  - invalid reg id
 * Applicable:
 *      8390
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phyExtParkPageReg_set(
    uint32              unit,
    rtk_port_t          port,
    uint32              mainPage,
    uint32              extPage,
    uint32              parkPage,
    rtk_port_phy_reg_t  reg,
    uint32              data)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyExtParkPageReg_set(unit, port, mainPage, extPage, parkPage, reg, data);
} /* end of rtk_port_phyExtParkPageReg_set */

/* Function Name:
 *      rtk_port_phymaskExtParkPageReg_set
 * Description:
 *      Set PHY register data of the specific portmask with extension page and parking page parameters
 * Input:
 *      unit      - unit id
 *      pPortmask - pointer to the portmask
 *      mainPage  - main page id
 *      extPage   - extension page id
 *      parkPage  - parking page id
 *      reg       - reg id
 *      data      - reg data
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_PHY_PAGE_ID  - invalid page id
 *      RT_ERR_PHY_REG_ID   - invalid reg id
 * Applicable:
 *      8390
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phymaskExtParkPageReg_set(
    uint32              unit,
    rtk_portmask_t      *pPortmask,
    uint32              mainPage,
    uint32              extPage,
    uint32              parkPage,
    rtk_port_phy_reg_t  reg,
    uint32              data)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phymaskExtParkPageReg_set(unit, pPortmask, mainPage, extPage, parkPage, reg, data);
} /* end of rtk_port_phymaskExtParkPageReg_set */

/* Function Name:
 *      rtk_port_phyMmdReg_get
 * Description:
 *      Get PHY MMD register data of the specific port
 * Input:
 *      unit    - unit id
 *      port    - port id
 *      mmdAddr - mmd device address
 *      mmdReg  - mmd reg id
 * Output:
 *      pData   - pointer to the PHY reg data
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8380, 8390, 9300, 9310
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phyMmdReg_get(
    uint32              unit,
    rtk_port_t          port,
    uint32              mmdAddr,
    uint32              mmdReg,
    uint32              *pData)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyMmdReg_get(unit, port, mmdAddr, mmdReg, pData);
} /* end of rtk_port_phyMmdReg_get */

/* Function Name:
 *      rtk_port_phyMmdReg_set
 * Description:
 *      Set PHY MMD register data of the specific port
 * Input:
 *      unit    - unit id
 *      port    - port id
 *      mmdAddr - mmd device address
 *      mmdReg  - mmd reg id
 *      data    - reg data
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT_ID  - invalid port id
 * Applicable:
 *      8261, 8264, 8380, 8390, 9300, 9310
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phyMmdReg_set(
    uint32              unit,
    rtk_port_t          port,
    uint32              mmdAddr,
    uint32              mmdReg,
    uint32              data)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyMmdReg_set(unit, port, mmdAddr, mmdReg, data);
} /* end of rtk_port_phyMmdReg_set */

/* Function Name:
 *      rtk_port_phymaskMmdReg_set
 * Description:
 *      Set PHY MMD register data of the specific portmask
 * Input:
 *      unit      - unit id
 *      pPortmask - pointer to the portmask
 *      mmdAddr   - mmd device address
 *      mmdReg    - mmd reg id
 *      data      - reg data
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT_ID  - invalid port id
 * Applicable:
 *      8380, 8390, 9300, 9310
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phymaskMmdReg_set(
    uint32              unit,
    rtk_portmask_t      *pPortmask,
    uint32              mmdAddr,
    uint32              mmdReg,
    uint32              data)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phymaskMmdReg_set(unit, pPortmask, mmdAddr, mmdReg, data);
} /* end of rtk_port_phymaskMmdReg_set */

/* Function Name:
 *      rtk_port_phyComboPortMedia_get
 * Description:
 *      Get PHY port media of the specific port
 * Input:
 *      unit   - unit id
 *      port   - port id
 * Output:
 *      pMedia - pointer to the port media
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8208G, 8208D, 8208L, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8295R, 8214QF, 9300SDS, 8390SDS, 8380SDS
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phyComboPortMedia_get(uint32 unit, rtk_port_t port, rtk_port_media_t *pMedia)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyComboPortMedia_get(unit, port, pMedia);

} /* end of rtk_port_phyComboPortMedia_get */

/* Function Name:
 *      rtk_port_phyComboPortMedia_set
 * Description:
 *      Set PHY port media of the specific port
 * Input:
 *      unit  - unit id
 *      port  - port id
 *      media - port media
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT_ID  - invalid port id
 *      RT_ERR_INPUT    - invalid input parameter
 * Applicable:
 *      8208D, 8208L, 8214FB, 8214B, 8212B, 8218FB, 8214FC
 * Note:
 *      (1) The media value is as following:
 *          - PORT_MEDIA_COPPER
 *          - PORT_MEDIA_FIBER
 * Changes:
 *      None
 */
int32
rtk_port_phyComboPortMedia_set(uint32 unit, rtk_port_t port, rtk_port_media_t media)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);
    RT_PARAM_CHK((media >= PORT_MEDIA_END), RT_ERR_INPUT);

    return RT_MAPPER(unit)->port_phyComboPortMedia_set(unit, port, media);

} /* end of rtk_port_phyComboPortMedia_set */

/* Function Name:
 *      rtk_port_greenEnable_get
 * Description:
 *      Get the status of green feature of the specific port in the specific unit
 * Input:
 *      unit    - unit id
 *      port    - port id
 * Output:
 *      pEnable - pointer to status of green feature
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8208G, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8218D, 8226, 8226B
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_greenEnable_get(uint32 unit, rtk_port_t port, rtk_enable_t *pEnable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_greenEnable_get(unit, port, pEnable);
} /* end of rtk_port_greenEnable_get */

/* Function Name:
 *      rtk_port_greenEnable_set
 * Description:
 *      Set the statue of green feature of the specific port in the specific unit
 * Input:
 *      unit   - unit id
 *      port   - port id
 *      enable - status of green feature
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT_ID  - invalid port id
 *      RT_ERR_INPUT    - invalid input parameter
 * Applicable:
 *      8261, 8264, 8208G, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8218D, 8226, 8226B
 * Note:
 *      Needs to restart auto-negotiation for the configuration to take effect.
 * Changes:
 *      None
 */
int32
rtk_port_greenEnable_set(uint32 unit, rtk_port_t port, rtk_enable_t enable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_greenEnable_set(unit, port, enable);
} /* end of rtk_port_greenEnable_set */

/* Function Name:
 *      rtk_port_phyCrossOverMode_get
 * Description:
 *      Get cross over mode in the specified port.
 * Input:
 *      unit  - unit id
 *      port  - port id
 * Output:
 *      pMode - pointer to cross over mode
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8208G, 8208D, 8208L, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8218D, 8226, 8226B
 * Note:
 *      The valid value of mode is as following:
 *      - PORT_CROSSOVER_MODE_AUTO
 *      - PORT_CROSSOVER_MODE_MDI
 *      - PORT_CROSSOVER_MODE_MDIX
 * Changes:
 *      None
 */
int32
rtk_port_phyCrossOverMode_get(uint32 unit, rtk_port_t port, rtk_port_crossOver_mode_t *pMode)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyCrossOverMode_get(unit, port, pMode);
} /* end of rtk_port_phyCrossOverMode_get */

/* Function Name:
 *      rtk_port_phyCrossOverMode_set
 * Description:
 *      Set cross over mode in the specified port.
 * Input:
 *      unit - unit id
 *      port - port id
 *      mode - cross over mode
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT_ID  - invalid port id
 *      RT_ERR_INPUT    - invalid input parameter
 * Applicable:
 *      8261, 8264, 8208G, 8208D, 8208L, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8218D, 8226, 8226B
 * Note:
 *      The valid value of mode is as following:
 *      - PORT_CROSSOVER_MODE_AUTO
 *      - PORT_CROSSOVER_MODE_MDI
 *      - PORT_CROSSOVER_MODE_MDIX
 * Changes:
 *      None
 */
int32
rtk_port_phyCrossOverMode_set(uint32 unit, rtk_port_t port, rtk_port_crossOver_mode_t mode)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyCrossOverMode_set(unit, port, mode);
} /* end of rtk_port_phyCrossOverMode_set */

/* Function Name:
 *      rtk_port_phyCrossOverStatus_get
 * Description:
 *      Get cross over status in the specified port.
 * Input:
 *      unit  - unit id
 *      port  - port id
 * Output:
 *      pStatus - pointer to cross over mode status
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 *      RT_ERR_PHY_FIBER_LINKUP - This feature is not supported in this mode
 * Applicable:
 *      8261, 8264, 8214C, 8218B, 8218FB, 8214FC, 8218D, 8226, 8226B
 * Note:
 *      The valid value of mode is as following:
 *      - PORT_CROSSOVER_MODE_MDI
 *      - PORT_CROSSOVER_MODE_MDIX
 * Changes:
 *      None
 */
int32
rtk_port_phyCrossOverStatus_get(uint32 unit, rtk_port_t port, rtk_port_crossOver_status_t *pStatus)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyCrossOverStatus_get(unit, port, pStatus);
} /* end of rtk_port_phyCrossOverStatus_get */

/* Function Name:
 *      rtk_port_phyComboPortFiberMedia_get
 * Description:
 *      Get PHY port fiber media of the specific port
 * Input:
 *      unit   - unit id
 *      port   - port id
 * Output:
 *      pMedia - pointer to the port fiber media
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8214FB, 8214B, 8212B, 8218FB, 8214FC
 * Note:
 *      1. fiber media type value is as following:
 *      - PORT_FIBER_MEDIA_1000
 *      - PORT_FIBER_MEDIA_100
 *      - PORT_FIBER_MEDIA_AUTO
 * Changes:
 *      None
 */
int32
rtk_port_phyComboPortFiberMedia_get(uint32 unit, rtk_port_t port, rtk_port_fiber_media_t *pMedia)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyComboPortFiberMedia_get(unit, port, pMedia);
} /* end of rtk_port_phyComboPortFiberMedia_get */

/* Function Name:
 *      rtk_port_phyComboPortFiberMedia_set
 * Description:
 *      Set PHY port fiber media of the specific port
 * Input:
 *      unit  - unit id
 *      port  - port id
 *      media - port fiber media
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID - invalid unit id
 *      RT_ERR_PORT_ID - invalid port id
 *      RT_ERR_INPUT   - invalid input parameter
 * Applicable:
 *      8214FB, 8214B, 8212B, 8218FB, 8214FC
 * Note:
 *      1. fiber media type value is as following:
 *      - PORT_FIBER_MEDIA_1000
 *      - PORT_FIBER_MEDIA_100
 *      - PORT_FIBER_MEDIA_AUTO
 * Changes:
 *      None
 */
int32
rtk_port_phyComboPortFiberMedia_set(uint32 unit, rtk_port_t port, rtk_port_fiber_media_t media)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);
    RT_PARAM_CHK((media >= PORT_FIBER_MEDIA_END), RT_ERR_INPUT);

    return RT_MAPPER(unit)->port_phyComboPortFiberMedia_set(unit, port, media);
} /* end of rtk_port_phyComboPortFiberMedia_set */

/* Function Name:
 *      rtk_port_linkDownPowerSavingEnable_get
 * Description:
 *      Get the statue of link-down power saving of the specific port in the specific unit
 * Input:
 *      unit    - unit id
 *      port    - port id
 * Output:
 *      pEnable - pointer to status of green feature
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8208G, 8208D, 8208L, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8218D, 8226, 8226B
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_linkDownPowerSavingEnable_get(uint32 unit, rtk_port_t port, rtk_enable_t *pEnable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_linkDownPowerSavingEnable_get(unit, port, pEnable);
} /* end of rtk_port_linkDownPowerSavingEnable_get */

/* Function Name:
 *      rtk_port_linkDownPowerSavingEnable_set
 * Description:
 *      Set the statue of link-down power saving of the specific port in the specific unit
 * Input:
 *      unit   - unit id
 *      port   - port id
 *      enable - status of green feature
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT_ID  - invalid port id
 *      RT_ERR_INPUT    - input parameter out of range
 * Applicable:
 *      8261, 8264, 8208G, 8208D, 8208L, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8218D, 8226, 8226B
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_linkDownPowerSavingEnable_set(uint32 unit, rtk_port_t port, rtk_enable_t enable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_linkDownPowerSavingEnable_set(unit, port, enable);
} /* end of rtk_port_linkDownPowerSavingEnable_set */

/* Function Name:
 *      rtk_port_gigaLiteEnable_get
 * Description:
 *      Get the statue of Giga Lite of the specific port in the specific unit
 * Input:
 *      unit    - unit id
 *      port    - port id
 * Output:
 *      pEnable - pointer to status of Giga Lite
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8214C, 8218B, 8218FB, 8214FC, 8218D, 8226, 8226B
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_gigaLiteEnable_get(uint32 unit, rtk_port_t port, rtk_enable_t *pEnable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_gigaLiteEnable_get(unit, port, pEnable);
} /* end of rtk_port_gigaLiteEnable_get */

/* Function Name:
 *      rtk_port_gigaLiteEnable_set
 * Description:
 *      Set the statue of Giga Lite of the specific port in the specific unit
 * Input:
 *      unit   - unit id
 *      port   - port id
 *      enable - status of Giga Lite
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT_ID  - invalid port id
 *      RT_ERR_INPUT    - input parameter out of range
 * Applicable:
 *      8214C, 8218B, 8218FB, 8214FC, 8218D, 8226, 8226B
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_gigaLiteEnable_set(uint32 unit, rtk_port_t port, rtk_enable_t enable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_gigaLiteEnable_set(unit, port, enable);
} /* end of rtk_port_gigaLiteEnable_set */

/* Function Name:
 *      rtk_port_2pt5gLiteEnable_get
 * Description:
 *      Get the statue of 2.5G Lite of the specific port in the specific unit
 * Input:
 *      unit    - unit id
 *      port    - port id
 * Output:
 *      pEnable - pointer to status of 2.5G Lite
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8226, 8226B, 8284
 * Note:
 *      None
 * Changes:
 *      [SDK_3.6.2]
 *          New added function.
 */
int32
rtk_port_2pt5gLiteEnable_get(uint32 unit, rtk_port_t port, rtk_enable_t *pEnable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || NULL == RT_MGMT(unit), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phy2pt5gLiteEnable_get(unit, port, pEnable);
}

/* Function Name:
 *      rtk_port_2pt5gLiteEnable_set
 * Description:
 *      Set the statue of 2.5G Lite of the specific port in the specific unit
 * Input:
 *      unit   - unit id
 *      port   - port id
 *      enable - status of 2.5G Lite
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT_ID  - invalid port id
 *      RT_ERR_INPUT    - input parameter out of range
 * Applicable:
 *      8226, 8226B, 8284
 * Note:
 *      None
 * Changes:
 *      [SDK_3.6.2]
 *          New added function.
 */
int32
rtk_port_2pt5gLiteEnable_set(uint32 unit, rtk_port_t port, rtk_enable_t enable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || NULL == RT_MGMT(unit), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phy2pt5gLiteEnable_set(unit, port, enable);
}

/* Function Name:
 *      rtk_port_phyReconfig_register
 * Description:
 *      Register callback function for PHY need to reconfigure notification
 * Input:
 *       unit                                - unit index
 *       phyNotification_callback    - callback function for reconfigure notification
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8380, 8390, 9300, 9310
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phyReconfig_register(uint32 unit, rtk_port_phyReconfig_callback_t phyNotification_callback)
{
#ifndef __BOOTLOADER__
    return dal_waMon_phyReconfig_register(phyNotification_callback);
#else
    return RT_ERR_OK;
#endif
} /* end of rtk_port_linkMon_register */

/* Function Name:
 *      rtk_port_phyReconfig_unregister
 * Description:
 *      UnRegister callback function for PHY need to reconfigure notification
 * Input:
 *	  unit					 - unit index
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_NOT_INIT - The module is not initial
 * Applicable:
 *      8261, 8264, 8380, 8390, 9300, 9310
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phyReconfig_unregister(uint32 unit)
{
#ifndef __BOOTLOADER__
    return dal_waMon_phyReconfig_unregister();
#else
    return RT_ERR_OK;
#endif

} /* end of rtk_port_linkMon_unregister */

/* Function Name:
 *      rtk_port_downSpeedEnable_get
 * Description:
 *      Get down speed status of the specific port
 * Input:
 *      unit   - unit id
 *      port   - port id
 * Output:
 *      pEnable - down speed status
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_PHY_FIBER_LINKUP - This feature is not supported in this mode
 * Applicable:
 *      8261, 8264, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8218D, 8226, 8226B
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_downSpeedEnable_get(uint32 unit, rtk_port_t port,
    rtk_enable_t *pEnable)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_downSpeedEnable_get(unit, port, pEnable);
}   /* end of rtk_port_downSpeedEnable_get */

/* Function Name:
 *      rtk_port_downSpeedEnable_set
 * Description:
 *      Set down speed status of the specific port
 * Input:
 *      unit   - unit id
 *      port   - port id
 *      enable - down speed status
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_PHY_FIBER_LINKUP - This feature is not supported in this mode
 * Applicable:
 *      8261, 8264, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8218D, 8226, 8226B
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_downSpeedEnable_set(uint32 unit, rtk_port_t port,
    rtk_enable_t enable)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_downSpeedEnable_set(unit, port, enable);
}   /* end of rtk_port_downSpeedEnable_set */

/* Function Name:
 *      rtk_port_downSpeedStatus_get
 * Description:
 *      Get the statue of down speed status of the specific port in the specific unit
 * Input:
 *      unit    - unit id
 *      port    - port id
 * Output:
 *      pDownSpeedStatus - pointer to status of down speed.
 *                         TRUE: link is up due to down speed; FALSE: down speed is not performed.
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 *      RT_ERR_PHY_FIBER_LINKUP - This feature is not supported in this mode
 * Applicable:
 *      8261, 8264, 8218B, 8218FB, 8214FC, 8218D
 * Note:
 *      None
 * Changes:
 *      [SDK_3.8.0]
 *          New added function.
 */
int32
rtk_port_downSpeedStatus_get(uint32 unit, rtk_port_t port, uint32 *pDownSpeedStatus)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || NULL == RT_MGMT(unit), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_downSpeedStatus_get(unit, port, pDownSpeedStatus);
}

/* Function Name:
 *      rtk_port_fiberNwayForceLinkEnable_get
 * Description:
 *      When fiber port is configured N-way,
 *      which can link with link partner is configured force mode.
 * Input:
 *      unit   - unit id
 *      port   - port id
 * Output:
 *      pEnable - fiber Nway force links status
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_PORT_ID      - invalid port id
 * Applicable:
 *      8218FB, 8214FC, 8295R, 8214QF
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_fiberNwayForceLinkEnable_get(uint32 unit, rtk_port_t port,
    rtk_enable_t *pEnable)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_fiberNwayForceLinkEnable_get(unit, port, pEnable);
}   /* end of rtk_port_fiberNwayForceLinkEnable_get */

/* Function Name:
 *      rtk_port_fiberNwayForceLinkEnable_set
 * Description:
 *      When fiber port is configured N-way,
 *      which can link with link partner is configured force mode.
 * Input:
 *      unit   - unit id
 *      port   - port id
 *      enable - fiber Nway force links status
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_PORT_ID      - invalid port id
 * Applicable:
 *      8218FB, 8214FC, 8295R, 8214QF
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_fiberNwayForceLinkEnable_set(uint32 unit, rtk_port_t port,
    rtk_enable_t enable)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_fiberNwayForceLinkEnable_set(unit, port, enable);
}   /* end of rtk_port_fiberNwayForceLinkEnable_set */

/* Function Name:
 *      rtk_port_phyLoopBackEnable_get
 * Description:
 *      Get PHY Loopback featrue
 * Input:
 *      unit   - unit id
 *      port   - port id
 *      pEnable - ENABLED: Enable loopback;
 *               DISABLED: Disable loopback. PHY back to normal operation.
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_PORT_ID      - invalid port id
 * Applicable:
 *      8261, 8264, 8214C, 8218B, 8218FB, 8214FC, 8295R, 8214QF, 8218D, 9300SDS, 8226, 8226B
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phyLoopBackEnable_get(uint32 unit, rtk_port_t port, rtk_enable_t *pEnable)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyLoopBackEnable_get(unit, port, pEnable);

}   /* end of rtk_port_phyLoopBackEnable_get */

/* Function Name:
 *      rtk_port_phyLoopBackEnable_set
 * Description:
 *      Set PHY Loopback featrue
 * Input:
 *      unit   - unit id
 *      port   - port id
 *      enable - ENABLED: Enable loopback;
 *               DISABLED: Disable loopback. PHY back to normal operation.
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_PORT_ID      - invalid port id
 * Applicable:
 *      8261, 8264, 8214C, 8218B, 8218FB, 8214FC, 8295R, 8214QF, 8218D, 9300SDS, 8226, 8226B
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phyLoopBackEnable_set(uint32 unit, rtk_port_t port, rtk_enable_t enable)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyLoopBackEnable_set(unit, port, enable);

}   /* end of rtk_port_phyLoopBackEnable_set */

/* Function Name:
 *      rtk_port_10gMedia_set
 * Description:
 *      Set 10G port media of the specific port
 * Input:
 *      unit  - unit id
 *      port  - port id
 *      media - port media
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT_ID  - invalid port id
 *      RT_ERR_INPUT    - invalid input parameter
 *      RT_ERR_CHIP_NOT_SUPPORTED - chip not support the function
 *      RT_ERR_TIMEOUT  - exec function time out
 * Applicable:
 *      8295R, 8390SDS, 9300SDS, 9310SDS
 * Note:
 *      (1) The media value is as following:
 *          - PORT_10GMEDIA_FIBER_10G,
 *          - PORT_10GMEDIA_FIBER_1G,
 *          - PORT_10GMEDIA_DAC_50CM,
 *          - PORT_10GMEDIA_DAC_100CM,
 *          - PORT_10GMEDIA_DAC_300CM,
 * Changes:
 *      None
 */
int32
rtk_port_10gMedia_set(uint32 unit, rtk_port_t port, rtk_port_10gMedia_t media)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_10gMedia_set(unit, port, media);
}   /* end of rtk_port_10gMedia_set */

/* Function Name:
 *      rtk_port_10gMedia_get
 * Description:
 *      Get 10G port media of the specific port
 * Input:
 *      unit    - unit id
 *      port    - port id
 * Output:
 *      media   - pointer to the media type
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8295R, 8390SDS, 9300SDS, 9310SDS
 * Note:
 *      (1) The media type of the port is as following:
 *          - PORT_10GMEDIA_FIBER_10G,
 *          - PORT_10GMEDIA_FIBER_1G,
 *          - PORT_10GMEDIA_DAC_50CM,
 *          - PORT_10GMEDIA_DAC_100CM,
 *          - PORT_10GMEDIA_DAC_300CM,
 * Changes:
 *      None
 */
int32
rtk_port_10gMedia_get(uint32 unit, rtk_port_t port, rtk_port_10gMedia_t *media)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_10gMedia_get(unit, port, media);
}   /* end of rtk_port_10gMedia_get */

/* Function Name:
 *      rtk_port_phyFiberTxDis_set
 * Description:
 *      Set PHY fiber Tx disable signal
 * Input:
 *      unit    - unit id
 *      port    - port id
 *      enable  - ENABLED: Enable Tx disable signal;
 *                DISABLED: Disable Tx disable signal.
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_PORT_ID      - invalid port id
 * Applicable:
 *      8218FB, 8214FC, 8295R, 8214QF
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phyFiberTxDis_set(uint32 unit, rtk_port_t port, rtk_enable_t enable)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyFiberTxDis_set(unit, port, enable);
}   /* end of rtk_port_phyFiberTxDis_set */

/* Function Name:
 *      rtk_port_phyFiberTxDisPin_set
 * Description:
 *      Set PHY fiber Tx disable signal GPO output
 * Input:
 *      unit        - unit id
 *      port        - port id
 *      data      - GPO pin value
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_PORT_ID      - invalid port id
 * Applicable:
 *      8218FB, 8214FC, 8295R, 8214QF
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phyFiberTxDisPin_set(uint32 unit, rtk_port_t port, uint32 data)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyFiberTxDisPin_set(unit, port, data);
}   /* end of rtk_port_phyFiberTxDisPin_set */

/* Function Name:
 *      rtk_port_fiberRxEnable_get
 * Description:
 *      Get fiber Rx enable status of the specific port
 * Input:
 *      unit   - unit id
 *      port   - port id
 * Output:
 *      pEnable - fiber Rx enable status
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_PORT_ID      - invalid port id
 * Applicable:
 *      8214FC, 8218FB
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_fiberRxEnable_get(uint32 unit, rtk_port_t port,
    rtk_enable_t *pEnable)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_fiberRxEnable_get(unit, port, pEnable);
}   /* end of rtk_port_fiberRxEnable_get */

/* Function Name:
 *      rtk_port_fiberRxEnable_set
 * Description:
 *      Set fiber Rx enable status of the specific port
 * Input:
 *      unit   - unit id
 *      port   - port id
 *      enable - fiber Rx enable status
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_PORT_ID      - invalid port id
 * Applicable:
 *      8214FC, 8218FB
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_fiberRxEnable_set(uint32 unit, rtk_port_t port,
    rtk_enable_t enable)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_fiberRxEnable_set(unit, port, enable);
}   /* end of rtk_port_fiberRxEnable_set */

/* Function Name:
 *      rtk_port_phyIeeeTestMode_set
 * Description:
 *      Set test mode for Giga PHY transmitter test
 * Input:
 *      unit  - unit id
 *      port  - port id
 *      pTestMode->mode  - test mode 1 ~ 4 which is defined in IEEE 40.6.1.1.2
 *      pTestMode->channel  - Channel A, B, C, D, or none
 *      pTestMode->flags -
 *          RTK_PORT_PHYTESTMODE_FLAG_ALL_PHY_PORTS -
 *              apply the test on all ports of the PHY.
 *              To use this feature, the "port" parameter shall set to the first port of the PHY.
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK     - OK
 *      RT_ERR_NOT_ALLOWED - The operation is not allowed
 *      RT_ERR_PORT_NOT_SUPPORTED - test mode is not supported
 * Applicable:
 *      8261, 8264, 8218B, 8214FC, 8218FB, 8214FB, 8214B, 8212B, 8218D, 8226, 8226B
 * Note:
 *      None
 * Changes:
 *      [SDK_3.0.0]
 *          New added function.
 */
int32
rtk_port_phyIeeeTestMode_set(uint32 unit, rtk_port_t port, rtk_port_phyTestMode_t *pTestMode)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyIeeeTestMode_set(unit, port, pTestMode);
}

/* Function Name:
 *      rtk_port_phyPolar_get
 * Description:
 *      Get 10GE fiber port polarity configure
 * Input:
 *      unit   - unit id
 *      port   - port id
 * Output:
 *      pPolarCtrl - polarity configuration
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 * Applicable:
 *      8295R, 9300SDS
 * Note:
 *      None
 * Changes:
 *      [SDK_3.0.0]
 *          New added function.
 */
int32
rtk_port_phyPolar_get(uint32 unit, rtk_port_t port, rtk_port_phyPolarCtrl_t *pPolarCtrl)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyPolar_get(unit, port, pPolarCtrl);
}

/* Function Name:
 *      rtk_port_phyPolar_set
 * Description:
 *      Configure 10GE fiber port polarity
 * Input:
 *      unit   - unit id
 *      port   - port id
 *      polarCtrl - polarity configuration
 * Output:
  *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 * Applicable:
 *      8295R, 9300SDS
 * Note:
 *      None
 * Changes:
 *      [SDK_3.0.0]
 *          New added function.
 */
int32
rtk_port_phyPolar_set(uint32 unit, rtk_port_t port, rtk_port_phyPolarCtrl_t *pPolarCtrl)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyPolar_set(unit, port, pPolarCtrl);
}

/* Function Name:
 *      rtk_port_phyEyeMonitor_start
 * Description:
 *      Trigger eye monitor function
 * Input:
 *      unit    - unit id
 *      port    - port id
 *      sdsId   - serdes id or 0 for serdes port or the PHY has no serdes id.
 *      frameNum- frame number
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_PORT_ID      - invalid port id
 * Applicable:
 *      8295R, 8214QF, 9300SDS, 8261, 8264
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_port_phyEyeMonitor_start(uint32 unit, rtk_port_t port, uint32 sdsId, uint32 frameNum)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyEyeMonitor_start(unit, port, sdsId, frameNum);
}   /* end of rtk_port_phyEyeMonitor_start */

/* Function Name:
 *      rtk_port_phyEyeMonitorInfo_get
 * Description:
 *      Get the statue of eye monitor height and width of the specific port in the specific unit
 * Input:
 *      unit    - unit id
 *      port    - base port id of the PHY
 *      sds     - SerDes id of the PHY
 *      frameNum- frame number
 * Output:
 *      pInfo - pointer to the information of eye monitor height and width
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_PORT_ID  - invalid port id
 *      RT_ERR_PORT_NOT_SUPPORTED   - This function is not supported by the PHY of this port
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 *      RT_ERR_BUSYWAIT_TIMEOUT - Read information timeout
 * Applicable:
 *      8218D, 8295R, 8214QF, 8261, 8264
 * Note:
 *      None
 * Changes:
 *      [SDK_3.6.2]
 *          New added function.
 */
int32
rtk_port_phyEyeMonitorInfo_get(uint32 unit, rtk_port_t port, uint32 sds, uint32 frameNum, rtk_sds_eyeMonInfo_t *pInfo)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyEyeMonitorInfo_get(unit, port, sds, frameNum, pInfo);
}   /* end of rtk_port_phyEyeMonitorInfo_get */

/* Function Name:
 *      rtk_port_imageFlash_load
 * Description:
 *      load PHY config image into flash
 * Input:
 *      unit - unit id
 *      port - port id
 *      size - image size
 *      image - image
 * Output:
  *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 * Applicable:
 *      cust_phy1
 * Note:
 *      None
 * Changes:
 *      [SDK_3.0.0]
 *          New added function.
 */
int32
rtk_port_imageFlash_load(uint32 unit, rtk_port_t port, uint32 size, uint8 *image)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_imageFlash_load(unit, port, size, image);
}

/* Function Name:
 *      rtk_port_phySdsRxCaliStatus_get
 * Description:
 *      Get PHY SerDes rx-calibration status
 * Input:
 *      unit    - unit id
 *      port    - port id
 *      sdsId   - serdes ID
 * Output:
 *      rtk_port_phySdsRxCaliStatus_t   - rx-calibration status
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_UNIT_ID - invalid unit id
 *      RT_ERR_OUT_OF_RANGE - invalid serdes id
 * Applicable:
 *      8295R
 * Note:
 *      None
 * Changes:
 *      [3.2.0]
 *          New added function.
 */
int32
rtk_port_phySdsRxCaliStatus_get(uint32 unit, rtk_port_t port, uint32 sdsId, rtk_port_phySdsRxCaliStatus_t *pStatus)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phySdsRxCaliStatus_get(unit, port, sdsId, pStatus);
}

/* Function Name:
 *      rtk_port_phyReset_set
 * Description:
 *      Set PHY standard register Reset bit (0.15).
 * Input:
 *      unit                - unit id
 *      port                - port id
 *      enable              - ENABLED  : Set Reset bit; Reset PHY;
 *                            DISABLED : Clear Reset bit; PHY back to normal operation..
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID - invalid unit id
 * Applicable:
 *      8261, 8264, 8218D
 * Note:
 *      None
 * Changes:
 *      [SDK_3.4.1]
 *          New added function.
 */
int32
rtk_port_phyReset_set(uint32 unit, rtk_port_t port)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyReset_set(unit, port);
}   /* end of rtk_port_phyReset_set */

/* Function Name:
 *      rtk_port_phyLinkStatus_get
 * Description:
 *      Get PHY link status from standard register (1.2).
 * Input:
 *      unit    - unit id
 *      port    - port id
 * Output:
 *      pStatus - pointer to the link status
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8218D
 * Note:
 *      The Link Status bit (Status Register 1.2) has LL (Latching Low) attribute
 *      for link failure. Please refer IEEE 802.3 for detailed.
 * Changes:
 *      [SDK_3.4.1]
 *          New added function.
 */
int32
rtk_port_phyLinkStatus_get(uint32 unit, rtk_port_t port,
    rtk_port_linkStatus_t *pStatus)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyLinkStatus_get(unit, port, pStatus);
}   /* end of rtk_port_phyLinkStatus_get */

/* Function Name:
 *      rtk_port_phyPeerAutoNegoAbility_get
 * Description:
 *      Get ability from link partner advertisement auto negotiation of the specific port
 * Input:
 *      unit - unit id
 *      port - port id
 * Output:
 *      pAbility - pointer to PHY auto negotiation ability
 * Return:
 *      RT_ERR_OK     - OK
 *      RT_ERR_FAILED - invalid parameter
 *      RT_ERR_UNIT_ID - invalid unit id
 * Applicable:
 *      8261, 8264, 8218D
 * Note:
 *      None
 * Changes:
 *      [SDK_3.4.1]
 *          New added function.
 */
int32
rtk_port_phyPeerAutoNegoAbility_get(uint32 unit, rtk_port_t port,
    rtk_port_phy_ability_t *pAbility)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyPeerAutoNegoAbility_get(unit, port, pAbility);
}   /* end of rtk_port_phyPeerAutoNegoAbility_get */

/* Function Name:
 *      rtk_port_phyMacIntfSerdesMode_get
 * Description:
 *      Get PHY's MAC side interface serdes mode
 * Input:
 *      unit    - unit ID
 *      port    - Base mac ID of the PHY
 * Output:
 *      pSerdesMode  - PHY serdes mode
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID - invalid unit id
 * Applicable:
 *      8261, 8264, 8218D
 * Note:
 *      None
 * Changes:
 *      [SDK_3.4.1]
 *          New added function.
 */
int32
rtk_port_phyMacIntfSerdesMode_get(uint32 unit, rtk_port_t port,
    rt_serdesMode_t *pSerdesMode)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyMacIntfSerdesMode_get(unit, port, pSerdesMode);
}   /* end of rtk_port_phyMacIntfSerdesMode_get */

/* Function Name:
 *      rtk_port_phyLedMode_set
 * Description:
 *      Configure LED mode to PHY. PHY will send out data to LED panel for port status indication
 * Input:
 *      unit    - unit ID
 *      port    - Base mac ID of the PHY
 *      pLedMode - LED mode select.
 *                 led_id is used to specify which LED to config.
 *                 mdi is PHY port ID of each PHY (starting from 0). It config the LED to display which port's status.
 *                 led_ind_status_sel can select multiple indicators by OR with mutiple RTK_PHY_LED_IND_STATUS_SEL_xxx macros.
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID - invalid unit id
 * Applicable:
 *      8218D
 * Note:
 *      None
 * Changes:
 *      [SDK_3.4.1]
 *         New added function.
 */
int32
rtk_port_phyLedMode_set(uint32 unit, rtk_port_t port, rtk_phy_ledMode_t *pLedMode)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyLedMode_set(unit, port, pLedMode);
}   /* end of rtk_port_phyLedMode_set */

/* Function Name:
 *      rtk_port_phyLedCtrl_set
 * Description:
 *      Ger Configuration of LED for PHY control LED
 * Input:
 *      unit    - unit ID
 *      port    - Base mac ID of the PHY
 * Output:
 *      pLedCtrl - PHY LED control
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID - invalid unit id
 * Applicable:
 *      8218D
 * Note:
 *      None
 * Changes:
 *      [SDK_3.4.1]
 *         New added function.
 */
int32
rtk_port_phyLedCtrl_get(uint32 unit, rtk_port_t port, rtk_phy_ledCtrl_t *pLedCtrl)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyLedCtrl_get(unit, port, pLedCtrl);
}   /* end of rtk_port_phyLedCtrl_set */

/* Function Name:
 *      rtk_port_phyLedCtrl_set
 * Description:
 *      Configure LED for PHY control LED
 * Input:
 *      unit    - unit ID
 *      port    - Base mac ID of the PHY
 *      pLedCtrl - PHY LED control
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID - invalid unit id
 * Applicable:
 *      8218D
 * Note:
 *      None
 * Changes:
 *      [SDK_3.4.1]
 *          New added function.
 */
int32
rtk_port_phyLedCtrl_set(uint32 unit, rtk_port_t port, rtk_phy_ledCtrl_t *pLedCtrl)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyLedCtrl_set(unit, port, pLedCtrl);
}   /* end of rtk_port_phyLedCtrl_set */

/* Function Name:
 *      rtk_port_phyMacIntfSerdesLinkStatus_get
 * Description:
 *      Get PHY's MAC side interface serdes link status
 * Input:
 *      unit    - unit ID
 *      port    - Base mac ID of the PHY
 * Output:
 *      pStatus - link status of the SerDes
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID - invalid unit id
 *      RT_ERR_PORT_NOT_SUPPORTED   - This function is not supported by the PHY of this port
 * Applicable:
 *      8261, 8264, 8218D, 8226, 8226B
 * Note:
 *      None
 * Changes:
 *      [SDK_3.4.2]
 *         New added function.
 */
int32
rtk_port_phyMacIntfSerdesLinkStatus_get(uint32 unit, rtk_port_t port,
    rtk_phy_macIntfSdsLinkStatus_t *pStatus)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyMacIntfSerdesLinkStatus_get(unit, port, pStatus);
}   /* end of rtk_port_phyMacIntfSerdesLinkStatus_get */

/* Function Name:
 *      rtk_port_phySdsEyeParam_get
 * Description:
 *      Get SerDes eye parameters
 * Input:
 *      unit    - unit ID
 *      port    - Base mac ID of the PHY
 * Output:
 *      pEyeParam - eye parameter
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID - invalid unit id
 * Applicable:
 *      8261, 8264, 8218D, 8214QF, 8295R
 * Note:
 *      None
 * Changes:
 *      [SDK_3.5.0]
 *          New added function.
 */
int32
rtk_port_phySdsEyeParam_get(uint32 unit, rtk_port_t port, uint32 sdsId, rtk_sds_eyeParam_t *pEyeParam)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phySdsEyeParam_get(unit, port, sdsId, pEyeParam);
}   /* end of rtrpc_port_phyLedCtrl_set */

/* Function Name:
 *      rtk_port_phySdsEyeParam_set
 * Description:
 *      Set SerDes eye parameters
 * Input:
 *      unit    - unit ID
 *      port    - Base mac ID of the PHY
 *      pEyeParam - eye parameter
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID - invalid unit id
 * Applicable:
 *      8261, 8264, 8218D, 8214QF, 8295R
 * Note:
 *      None
 * Changes:
 *      [SDK_3.5.0]
 *          New added function.
 */
int32
rtk_port_phySdsEyeParam_set(uint32 unit, rtk_port_t port, uint32 sdsId, rtk_sds_eyeParam_t *pEyeParam)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phySdsEyeParam_set(unit, port, sdsId, pEyeParam);
}

/* Function Name:
 *      rtk_port_phyMdiLoopbackEnable_get
 * Description:
 *      Enable port MDI loopback for connecting with RJ45 loopback connector
 * Input:
 *      unit    - unit id
 *      port    - port id
 * Output:
 *      pEnable - pointer to status of MDI loopback
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8218D
 * Note:
 *      None
 * Changes:
 *      [SDK_3.7.0]
 *          New added function.
 */
int32
rtk_port_phyMdiLoopbackEnable_get(uint32 unit, rtk_port_t port, rtk_enable_t *pEnable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || NULL == RT_MGMT(unit), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyMdiLoopbackEnable_get(unit, port, pEnable);
}

/* Function Name:
 *      rtk_port_phyMdiLoopbackEnable_set
 * Description:
 *      Enable port MDI loopback for connecting with RJ45 loopback connector
 * Input:
 *      unit   - unit id
 *      port   - port id
 *      enable - status of MDI loopback
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT_ID  - invalid port id
 *      RT_ERR_INPUT    - input parameter out of range
 * Applicable:
 *      8261, 8264, 8218D
 * Note:
 *      Require setting cross-over to MDI or MDIX.
 * Changes:
 *      [SDK_3.7.0]
 *          New added function.
 */
int32
rtk_port_phyMdiLoopbackEnable_set(uint32 unit, rtk_port_t port, rtk_enable_t enable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || NULL == RT_MGMT(unit), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyMdiLoopbackEnable_set(unit, port, enable);
}

/* Function Name:
 *      rtk_port_phyIntr_init
 * Description:
 *      Initialize the type of PHY interrupt function of the specified PHY chip.
 * Input:
 *      unit    - unit id
 *      port    - base mac ID number of the PHY
 *      phyIntr - PHY interrupt type
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT     - invalid port id
 *      RT_ERR_INPUT    - invalid input parameter
 * Applicable:
 *      8218D
 * Note:
 *      None
 * Changes:
 *      [SDK_3.6.2]
 *          New added function.
 */
int32
rtk_port_phyIntr_init(uint32 unit, rtk_port_t port, rtk_phy_intr_t phyIntr)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || NULL == RT_MGMT(unit), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyIntr_init(unit, port, phyIntr);
}

/* Function Name:
 *      rtk_port_phyIntrEnable_get
 * Description:
 *      Get the type of PHY interrupt enable status of the specified port.
 * Input:
 *      unit    - unit id
 *      port    - port id
 *      phyIntr - PHY interrupt type
 * Output:
 *      pEnable - pointer to status of interrupt enable
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT     - invalid port id
 *      RT_ERR_INPUT    - invalid input parameter
 * Applicable:
 *      8261, 8264, 8218D
 * Note:
 *      None
 * Changes:
 *      [SDK_3.6.2]
 *          New added function.
 */
int32
rtk_port_phyIntrEnable_get(uint32 unit, rtk_port_t port, rtk_phy_intr_status_t phyIntr, rtk_enable_t *pEnable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || NULL == RT_MGMT(unit), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyIntrEnable_get(unit, port, phyIntr, pEnable);
}

/* Function Name:
 *      rtk_port_phyIntrEnable_set
 * Description:
 *      Set the type of PHY interrupt enable status of the specified port.
 * Input:
 *      unit    - unit id
 *      port    - port id
 *      phyIntr - PHY interrupt type
 *      enable  - status
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT     - invalid port id
 *      RT_ERR_INPUT    - invalid input parameter
 * Applicable:
 *      8261, 8264, 8218D
 * Note:
 *      None
 * Changes:
 *      [SDK_3.6.2]
 *          New added function.
 */
int32
rtk_port_phyIntrEnable_set(uint32 unit, rtk_port_t port, rtk_phy_intr_status_t phyIntr, rtk_enable_t enable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || NULL == RT_MGMT(unit), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyIntrEnable_set(unit, port, phyIntr, enable);
}

/* Function Name:
 *      rtk_port_phyIntrStatus_get
 * Description:
 *      Get specified PHY interrupt status.
 * Input:
 *      unit    - unit id
 *      port    - port id or base mac ID number of the PHY
 *      phyIntr - PHY interrupt type
 * Output:
 *      pStatus - interrupt triggered status for specified PHY interrupt
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT     - invalid port id
 *      RT_ERR_INPUT    - invalid input parameter
 * Applicable:
 *      8261, 8264, 8218D
 * Note:
 *      The PHY interrupt status register is read-clear.
 * Changes:
 *      [SDK_3.6.2]
 *          New added function.
 */
int32
rtk_port_phyIntrStatus_get(uint32 unit, rtk_port_t port, rtk_phy_intr_t phyIntr, rtk_phy_intrStatusVal_t *pStatus)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyIntrStatus_get(unit, port, phyIntr, pStatus);
}

/* Function Name:
 *      rtk_port_phyIntrMask_get
 * Description:
 *      Get PHY interrupt mask status of the specified port.
 * Input:
 *      unit    - unit id
 *      port    - port id
 *      phyIntr - PHY interrupt type
 * Output:
 *      pMask   - pointer to status of PHY interrupt mask
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT     - invalid port id
 *      RT_ERR_INPUT    - invalid input parameter
 * Applicable:
 *      8261, 8264, 8218D
 * Note:
 *      None
 * Changes:
 *      [SDK_3.6.2]
 *          New added function.
 */
int32
rtk_port_phyIntrMask_get(uint32 unit, rtk_port_t port, rtk_phy_intr_t phyIntr, uint32 *pMask)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || NULL == RT_MGMT(unit), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyIntrMask_get(unit, port, phyIntr, pMask);
}

/* Function Name:
 *      rtk_port_phyIntrMask_set
 * Description:
 *      Set PHY interrupt mask status of the specified port.
 * Input:
 *      unit    - unit id
 *      port    - port id
 *      phyIntr - PHY interrupt type
 *      mask    - mask
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT     - invalid port id
 *      RT_ERR_INPUT    - invalid input parameter
 * Applicable:
 *      8261, 8264, 8218D
 * Note:
 *      None
 * Changes:
 *      [SDK_3.6.2]
 *          New added function.
 */
int32
rtk_port_phyIntrMask_set(uint32 unit, rtk_port_t port, rtk_phy_intr_t phyIntr, uint32 mask)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || NULL == RT_MGMT(unit), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyIntrMask_set(unit, port, phyIntr, mask);
}

/* Function Name:
 *      rtk_port_phySdsTestMode_set
 * Description:
 *      Set SerDes test mode.
 * Input:
 *      unit        - unit id
 *      port        - base mac ID number of the PHY
 *      sdsId       - SerDes id
 *      testMode    - test mode
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT         - invalid port id
 * Applicable:
 *      8261, 8264, 8218D, 8214QF
 * Note:
 *      None
 * Changes:
 *      [SDK_3.8.0]
 *          New added function.
 */
int32
rtk_port_phySdsTestMode_set(uint32 unit, rtk_port_t port, uint32 sdsId, rtk_sds_testMode_t testMode)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || NULL == RT_MGMT(unit), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phySdsTestMode_set(unit, port, sdsId, testMode);
}

/* Function Name:
 *      rtk_port_phySdsTestModeCnt_get
 * Description:
 *      Get SerDes test mode test pattern error counter.
 * Input:
 *      unit        - unit id
 *      port        - base mac ID number of the PHY
 *      sdsId       - SerDes id
 * Output:
 *      pCnt        - test pattern error counter
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT         - invalid port id
 * Applicable:
 *      8261, 8264, 8218D, 8214QF
 * Note:
 *      The test pattern error counter register is read-clear.
 * Changes:
 *      [SDK_3.8.0]
 *          New added function.
 */
int32
rtk_port_phySdsTestModeCnt_get(uint32 unit, rtk_port_t port, uint32 sdsId, uint32 *pCnt)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || NULL == RT_MGMT(unit), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phySdsTestModeCnt_get(unit, port, sdsId, pCnt);
}

/* Function Name:
 *      rtk_port_phySdsLeq_get
 * Description:
 *      Get the statue of LEQ of the specific PHY's SerDes in the specific unit
 * Input:
 *      unit    - unit id
 *      port    - base port id of the PHY
 *      sdsId   - SerDes of the PHY
 * Output:
 *      pManual_en - pointer to manual LEQ config satus
 *      pLeq_val   - pointer to current LEQ value
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8214QF, 8218D
 * Note:
 *      None
 * Changes:
 *      [SDK_3.6.2]
 *          New added function.
 */
int32
rtk_port_phySdsLeq_get(uint32 unit, rtk_port_t port, uint32 sdsId, rtk_enable_t *pManual_en, uint32 *pLeq_val)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phySdsLeq_get(unit, port, sdsId, pManual_en, pLeq_val);
}

/* Function Name:
 *      rtk_port_phySdsLeq_set
 * Description:
 *      Get the statue of LEQ of the specific PHY's SerDes in the specific unit
 * Input:
 *      unit    - unit id
 *      port    - base port id of the PHY
 *      sdsId   - SerDes of the PHY
 *      manual_en - ENABLED: LEQ in manual-mode; DISABLED: LEQ is auto-mode.
 *      leq_val - Fixed LEQ value when manual_en is set to ENABLED;
 *                this field is not used in driver when manual_en set to DISABLED, just keep it set to 0.
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT_ID  - invalid port id
 *      RT_ERR_INPUT    - input parameter out of range
 * Applicable:
 *      8214QF, 8218D
 * Note:
 *      None
 * Changes:
 *      [SDK_3.6.2]
 *          New added function.
 */
int32
rtk_port_phySdsLeq_set(uint32 unit, rtk_port_t port, uint32 sdsId, rtk_enable_t manual_en, uint32 leq_val)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || NULL == RT_MGMT(unit) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phySdsLeq_set(unit, port, sdsId, manual_en, leq_val);
}

/* Function Name:
 *      rtk_port_phySds_get
 * Description:
 *      Get PHY SerDes
 * Input:
 *      unit    - unit id
 *      port    - port id
 *      sdsCfg  - SerDes configuration
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_UNIT_ID - invalid unit id
 * Applicable:
 *      8380, 8390
 * Note:
 *      None
 * Changes:
 *      [SDK_3.1.1]
 *          New added function.
 */
int32
rtk_port_phySds_get(uint32 unit, rtk_port_t port, rtk_sdsCfg_t *sdsCfg)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phySds_get(unit, port, sdsCfg);
}   /* end of rtk_port_phySds_get */

/* Function Name:
 *      rtk_port_phySds_set
 * Description:
 *      Configure PHY SerDes
 * Input:
 *      unit    - unit id
 *      port    - port id
 *      sdsCfg  - SerDes configuration
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_UNIT_ID - invalid unit id
 * Applicable:
 *      8380, 8390
 * Note:
 *      None
 * Changes:
 *      [SDK_3.1.1]
 *          New added function.
 */
int32
rtk_port_phySds_set(uint32 unit, rtk_port_t port, rtk_sdsCfg_t *sdsCfg)
{
    /* function body */
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phySds_set(unit, port, sdsCfg);
}   /* end of rtk_port_phySds_set */

/* Function Name:
 *      rtk_port_phyCtrl_get
 * Description:
 *      Get Port/PHY specific settings
 * Input:
 *      unit      - unit id
 *      port      - port id
 *      ctrl_type - setting type
 * Output:
 *      pValue    - pointer to setting value
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 * Applicable:
 *      8261, 8264
 * Note:
 *      None
 * Changes:
 *      [SDK_3.8.0]
 *          New added function.
 */
int32
rtk_port_phyCtrl_get(uint32 unit, rtk_port_t port, rtk_phy_ctrl_t ctrl_type, uint32 *pValue)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyCtrl_get(unit, port, ctrl_type, pValue);
}

/* Function Name:
 *      rtk_port_phyCtrl_set
 * Description:
 *      Set Port/PHY specific settings
 * Input:
 *      unit      - unit id
 *      port      - port id
 *      ctrl_type - setting type
 *      value     - setting value
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 * Applicable:
 *      8261, 8264
 * Note:
 *      None
 * Changes:
 *      [SDK_3.8.0]
 *          New added function.
 */
int32
rtk_port_phyCtrl_set(uint32 unit, rtk_port_t port, rtk_phy_ctrl_t ctrl_type, uint32 value)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || NULL == RT_MGMT(unit) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyCtrl_set(unit, port, ctrl_type, value);
}

/* Function Name:
 *      rtk_port_phyLiteEnable_get
 * Description:
 *      Get the status of Lite setting
 * Input:
 *      unit    - unit id
 *      port    - port id
 *      mode    - Lite speed mode
 * Output:
 *      pEnable - pointer to status of Lite
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264
 * Note:
 *      None
 * Changes:
 *      [SDK_3.8.0]
 *          New added function.
 */
int32
rtk_port_phyLiteEnable_get(uint32 unit, rtk_port_t port, rtk_port_lite_mode_t mode, rtk_enable_t *pEnable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyLiteEnable_get(unit, port, mode, pEnable);
}

/* Function Name:
 *      rtk_port_phyLiteEnable_set
 * Description:
 *      Set the status of Lite setting
 * Input:
 *      unit   - unit id
 *      port   - port id
 *      mode    - Lite speed mode
 *      enable  - status of Lite
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT_ID  - invalid port id
 *      RT_ERR_INPUT    - input parameter out of range
 * Applicable:
 *      8261, 8264
 * Note:
 *      None
 * Changes:
 *      [SDK_3.8.0]
 *          New added function.
 */
int32
rtk_port_phyLiteEnable_set(uint32 unit, rtk_port_t port, rtk_port_lite_mode_t mode, rtk_enable_t enable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || NULL == RT_MGMT(unit) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyLiteEnable_set(unit, port, mode, enable);
}

/* Function Name:
 *      rtk_port_phyDbgCounter_get
 * Description:
 *      Get the status of debug counter
 * Input:
 *      unit - unit id
 *      port - port id
 *      type - counter type
 * Output:
 *      pCnt - pointer to counter value
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264
 * Note:
 *      None
 * Changes:
 *      [SDK_3.8.0]
 *          New added function.
 */
int32
rtk_port_phyDbgCounter_get(uint32 unit, rtk_port_t port, rtk_port_phy_dbg_cnt_t type, uint64 *pCnt)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->port_phyDbgCounter_get(unit, port, type, pCnt);
}

/* Function Name:
 *      rtk_eee_portEnable_get
 * Description:
 *      Get enable status of EEE function in the specified port.
 * Input:
 *      unit    - unit id
 *      port    - port id
 * Output:
 *      pEnable - pointer to enable status of EEE
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_PORT_ID      - invalid port id
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8380, 8390, 9300, 9310
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_eee_portEnable_get(uint32 unit, rtk_port_t port, rtk_enable_t *pEnable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->eee_portEnable_get(unit, port, pEnable);

} /* end of rtk_eee_portEnable_get */

/* Function Name:
 *      rtk_eee_portEnable_set
 * Description:
 *      Set enable status of EEE function in the specified port.
 * Input:
 *      unit   - unit id
 *      port   - port id
 *      enable - enable status of EEE
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID  - invalid unit id
 *      RT_ERR_NOT_INIT - The module is not initial
 *      RT_ERR_PORT_ID  - invalid port id
 *      RT_ERR_INPUT    - invalid input parameter
 * Applicable:
 *      8261, 8264, 8380, 8390, 9300, 9310
 * Note:
 *      Needs to restart auto-negotiation for the configuration to take effect.
 * Changes:
 *      None
 */
int32
rtk_eee_portEnable_set(uint32 unit, rtk_port_t port, rtk_enable_t enable)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->eee_portEnable_set(unit, port, enable);

} /* end of rtk_eee_portEnable_set */

/* Function Name:
 *      rtk_diag_portRtctResult_get
 * Description:
 *      Get test result of Realtek Cable Tester.
 * Input:
 *      unit        - unit id
 *      port        - the port for retriving RTCT test result
 * Output:
 *      pRtctResult - RTCT result
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID             - invalid unit id
 *      RT_ERR_NOT_INIT            - The module is not initial
 *      RT_ERR_PORT_ID             - invalid port id
 *      RT_ERR_PHY_RTCT_NOT_FINISH - RTCT not finish. Need to wait a while.
 *      RT_ERR_TIMEOUT             - RTCT test timeout in this port.
 *      RT_ERR_NULL_POINTER        - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8208G, 8208D, 8208L, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8218D
 * Note:
 *      (1) If linkType is PORT_SPEED_1000M, test result will be stored in ge_result.
 *          If linkType is PORT_SPEED_10M or PORT_SPEED_100M, test result will be stored in fe_result.
 *      (2) The unit of cable lenght is centimeter.
 * Changes:
 *      [3.2.0]
 *          rtk_rtctResult_t adds HiImpedance, Cross, PartialCross, and PairBusy.
 */
int32
rtk_diag_portRtctResult_get(uint32 unit, rtk_port_t port, rtk_rtctResult_t *pRtctResult)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->diag_portRtctResult_get(unit, port, pRtctResult);

} /* end of rtk_diag_portRtctResult_get */

/* Function Name:
 *      rtk_diag_rtctEnable_set
 * Description:
 *      Start Realtek Cable Tester for ports.
 * Input:
 *      unit      - unit id
 *      pPortmask - the ports for RTCT test
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 *      RT_ERR_NULL_POINTER - input parameter may be null pointer
 * Applicable:
 *      8261, 8264, 8208G, 8208D, 8208L, 8214C, 8214FB, 8214B, 8212B, 8218B, 8218FB, 8214FC, 8218D
 * Note:
 *      When RTCT starts, the port won't transmit and receive normal traffic.
 * Changes:
 *      None
 */
int32
rtk_diag_rtctEnable_set(uint32 unit, rtk_portmask_t *pPortmask)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->diag_rtctEnable_set(unit, pPortmask);

} /* end of rtk_diag_rtctEnable_set */

/* Function Name:
 *      rtk_phy_debug_get
 * Description:
 *      Dump RealTek PHY debug information
 * Input:
 *      unit  - unit id
 *      pDbg  - pointer to the parameter structure
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 *      RT_ERR_UNIT_ID      - invalid unit id
 *      RT_ERR_NOT_INIT     - The module is not initial
 * Applicable:
 *      8261, 8264
 * Note:
 *      None
 * Changes:
 *      None
 */
int32
rtk_phy_debug_get(uint32 unit, rtk_phy_debug_t *pDbg)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->debug_phy_get(unit, pDbg);
}

/* Function Name:
 *      rtk_phy_debug_batch_port_set
 * Description:
 *      Set target port list for debug batch tool
 * Input:
 *      unit      - unit id
 *      pPortmask - the ports for debug batch
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 * Applicable:
 *
 * Note:
 *
 * Changes:
 *      [SDK_3.6.5]
 *          New added function.
 */
int32
rtk_phy_debug_batch_port_set(uint32 unit, rtk_portmask_t *pPortmask)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->debug_phy_batch_port_set(unit, pPortmask);

}

/* Function Name:
 *      rtk_phy_debug_batch_op_set
 * Description:
 *      debug batch command
 * Input:
 *      unit      - unit id
 *      pPara     - input parameter
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 * Applicable:
 *
 * Note:
 *
 * Changes:
 *      [SDK_3.6.5]
 *          New added function.
 */
int32
rtk_phy_debug_batch_op_set(uint32 unit, rtk_phy_batch_para_t *pPara)
{
    RT_PARAM_CHK((unit > RTK_MAX_UNIT_ID) || (NULL == RT_MGMT(unit)) || (NULL == RT_MAPPER(unit)), RT_ERR_UNIT_ID);

    return RT_MAPPER(unit)->debug_phy_batch_op_set(unit, pPara);
}

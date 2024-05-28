/*
 * @Author: LiHeng
 * @Date: 2024-03-02 11:50:24
 * @LastEditors: LiHeng
 * @LastEditTime: 2024-05-28 10:46:48
 * @FilePath: /rt1170_rtems_source_1176/bsps/arm/imxrt/boards/evkimxrt1170/pin_mux.c
 * @Description:
 *
 * Copyright (c) 2024 by LiHeng, All Rights Reserved.
 */
/*
 * Copyright 2018 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include <bsp.h>
#include <bspopts.h>
#include <bsp/start.h>

BSP_START_TEXT_SECTION
void BOARD_InitDEBUG_UARTPins(void)
{
    CLOCK_EnableClock(kCLOCK_Iomuxc);

/* for 1166*/
#if 0
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_02_LPUART8_TXD, 0U);
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_03_LPUART8_RXD, 0U);
  IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_02_LPUART8_TXD, 0x10B0u);
  IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_03_LPUART8_RXD, 0x10B0u);

  /* for 1176*/
  IOMUXC_SetPinMux(
       IOMUXC_GPIO_AD_24_LPUART1_TXD,          /* GPIO_AD_24 is configured as LPUART1_TXD */
       0U);                                    /* Software Input On Field: Input Path is determined by functionality */
   IOMUXC_SetPinMux(
       IOMUXC_GPIO_AD_25_LPUART1_RXD,          /* GPIO_AD_25 is configured as LPUART1_RXD */
       0U);                                    /* Software Input On Field: Input Path is determined by functionality */
   IOMUXC_SetPinConfig(
       IOMUXC_GPIO_AD_24_LPUART1_TXD,          /* GPIO_AD_24 PAD functional properties : */
       0x02U);                                 /* Slew Rate Field: Slow Slew Rate
                                                  Drive Strength Field: high drive strength
                                                  Pull / Keep Select Field: Pull Disable, Highz
                                                  Pull Up / Down Config. Field: Weak pull down
                                                  Open Drain Field: Disabled
                                                  Domain write protection: Both cores are allowed
                                                  Domain write protection lock: Neither of DWP bits is locked */
   IOMUXC_SetPinConfig(
       IOMUXC_GPIO_AD_25_LPUART1_RXD,          /* GPIO_AD_25 PAD functional properties : */
       0x02U);                                 /* Slew Rate Field: Slow Slew Rate
                                                  Drive Strength Field: high drive strength
                                                  Pull / Keep Select Field: Pull Disable, Highz
                                                  Pull Up / Down Config. Field: Weak pull down
                                                  Open Drain Field: Disabled
                                                  Domain write protection: Both cores are allowed
                                                  Domain write protection lock: Neither of DWP bits is locked */
#endif

    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B2_10_LPUART2_TXD, /* GPIO_DISP_B2_10 is configured as LPUART2_TXD */
        0U);                                /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B2_11_LPUART2_RXD, /* GPIO_DISP_B2_11 is configured as LPUART2_RXD */
        0U);                                /* Software Input On Field: Input Path is determined by functionality */

    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_DISP_B2_10_LPUART2_TXD, /* GPIO_DISP_B2_10 PAD functional properties : */
        0x02U);

    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_DISP_B2_11_LPUART2_RXD,
        0x02U);
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitEnetPins:
- options: {callFromInitBoot: 'false', coreID: cm7, enableClock: 'true'}
- pin_list:
  - {pin_num: P17, peripheral: GPIO9, signal: 'gpio_io, 11', pin_signal: GPIO_AD_12}
  - {pin_num: K16, peripheral: ENET, signal: enet_mdc, pin_signal: GPIO_AD_32}
  - {pin_num: H17, peripheral: ENET, signal: enet_mdio, pin_signal: GPIO_AD_33}
  - {pin_num: E9, peripheral: ENET, signal: 'enet_tdata, 00', pin_signal: GPIO_DISP_B2_02}
  - {pin_num: D7, peripheral: ENET, signal: 'enet_tdata, 01', pin_signal: GPIO_DISP_B2_03}
  - {pin_num: C7, peripheral: ENET, signal: enet_tx_en, pin_signal: GPIO_DISP_B2_04}
  - {pin_num: C9, peripheral: ENET, signal: enet_ref_clk, pin_signal: GPIO_DISP_B2_05, software_input_on: Enable, slew_rate: Fast}
  - {pin_num: C6, peripheral: ENET, signal: 'enet_rdata, 00', pin_signal: GPIO_DISP_B2_06}
  - {pin_num: D6, peripheral: ENET, signal: 'enet_rdata, 01', pin_signal: GPIO_DISP_B2_07}
  - {pin_num: B5, peripheral: ENET, signal: enet_rx_en, pin_signal: GPIO_DISP_B2_08}
  - {pin_num: D8, peripheral: ENET, signal: enet_rx_er, pin_signal: GPIO_DISP_B2_09}
  - {pin_num: U5, peripheral: GPIO12, signal: 'gpio_io, 12', pin_signal: GPIO_LPSR_12}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitEnetPins, assigned for the Cortex-M7F core.
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
#ifdef USE_ENET
void BOARD_InitEnetPins(void)
{
    CLOCK_EnableClock(kCLOCK_Iomuxc);      /* LPCG on: LPCG is ON. */
    CLOCK_EnableClock(kCLOCK_Iomuxc_Lpsr); /* LPCG on: LPCG is ON. */

    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_12_GPIO9_IO11, /* GPIO_AD_12 is configured as GPIO9_IO11 */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_32_ENET_MDC, /* GPIO_AD_32 is configured as ENET_MDC */
        0U);                        /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_33_ENET_MDIO, /* GPIO_AD_33 is configured as ENET_MDIO */
        0U);                         /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B2_02_ENET_TX_DATA00, /* GPIO_DISP_B2_02 is configured as ENET_TX_DATA00 */
        0U);                                   /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B2_03_ENET_TX_DATA01, /* GPIO_DISP_B2_03 is configured as ENET_TX_DATA01 */
        0U);                                   /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B2_04_ENET_TX_EN, /* GPIO_DISP_B2_04 is configured as ENET_TX_EN */
        0U);                               /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B2_05_ENET_REF_CLK, /* GPIO_DISP_B2_05 is configured as ENET_REF_CLK */
        1U);                                 /* Software Input On Field: Force input path of pad GPIO_DISP_B2_05 */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B2_06_ENET_RX_DATA00, /* GPIO_DISP_B2_06 is configured as ENET_RX_DATA00 */
        0U);                                   /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B2_07_ENET_RX_DATA01, /* GPIO_DISP_B2_07 is configured as ENET_RX_DATA01 */
        0U);                                   /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B2_08_ENET_RX_EN, /* GPIO_DISP_B2_08 is configured as ENET_RX_EN */
        0U);                               /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B2_09_ENET_RX_ER, /* GPIO_DISP_B2_09 is configured as ENET_RX_ER */
        0U);                               /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_GPR->GPR4 = ((IOMUXC_GPR->GPR4 &
                         (~(IOMUXC_GPR_GPR4_ENET_REF_CLK_DIR_MASK))) /* Mask bits to zero which are setting */
                        | IOMUXC_GPR_GPR4_ENET_REF_CLK_DIR(0x01U)    /* ENET_REF_CLK direction control: 0x01U */
    );
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_LPSR_12_GPIO12_IO12, /* GPIO_LPSR_12 is configured as GPIO12_IO12 */
        0U);                             /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_DISP_B2_05_ENET_REF_CLK, /* GPIO_DISP_B2_05 PAD functional properties : */
        0x03U);                              /* Slew Rate Field: Fast Slew Rate
                                                Drive Strength Field: high drive strength
                                                Pull / Keep Select Field: Pull Disable, Highz
                                                Pull Up / Down Config. Field: Weak pull down
                                                Open Drain Field: Disabled
                                                Domain write protection: Both cores are allowed
                                                Domain write protection lock: Neither of DWP bits is locked */
}
#endif

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitEnet1GPins:
- options: {callFromInitBoot: 'false', coreID: cm7, enableClock: 'true'}
- pin_list:
  - {pin_num: E13, peripheral: ENET_1G, signal: enet_rx_en, pin_signal: GPIO_DISP_B1_00}
  - {pin_num: D13, peripheral: ENET_1G, signal: enet_rx_clk, pin_signal: GPIO_DISP_B1_01}
  - {pin_num: D11, peripheral: ENET_1G, signal: 'enet_rdata, 00', pin_signal: GPIO_DISP_B1_02}
  - {pin_num: E11, peripheral: ENET_1G, signal: 'enet_rdata, 01', pin_signal: GPIO_DISP_B1_03}
  - {pin_num: E10, peripheral: ENET_1G, signal: 'enet_rdata, 02', pin_signal: GPIO_DISP_B1_04}
  - {pin_num: C11, peripheral: ENET_1G, signal: 'enet_rdata, 03', pin_signal: GPIO_DISP_B1_05}
  - {pin_num: D10, peripheral: ENET_1G, signal: 'enet_tdata, 03', pin_signal: GPIO_DISP_B1_06}
  - {pin_num: E12, peripheral: ENET_1G, signal: 'enet_tdata, 02', pin_signal: GPIO_DISP_B1_07}
  - {pin_num: A15, peripheral: ENET_1G, signal: 'enet_tdata, 01', pin_signal: GPIO_DISP_B1_08}
  - {pin_num: C13, peripheral: ENET_1G, signal: 'enet_tdata, 00', pin_signal: GPIO_DISP_B1_09}
  - {pin_num: B14, peripheral: ENET_1G, signal: enet_tx_en, pin_signal: GPIO_DISP_B1_10}
  - {pin_num: A14, peripheral: ENET_1G, signal: enet_tx_clk_io, pin_signal: GPIO_DISP_B1_11}
  - {pin_num: A5, peripheral: GPIO11, signal: 'gpio_io, 14', pin_signal: GPIO_DISP_B2_13}
  - {pin_num: U2, peripheral: ENET_1G, signal: enet_mdc, pin_signal: GPIO_EMC_B2_19}
  - {pin_num: R3, peripheral: ENET_1G, signal: enet_mdio, pin_signal: GPIO_EMC_B2_20}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitEnet1GPins, assigned for the Cortex-M7F core.
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitEnet1GPins(void)
{
    CLOCK_EnableClock(kCLOCK_Iomuxc); /* LPCG on: LPCG is ON. */

    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B1_00_ENET_1G_RX_EN, /* GPIO_DISP_B1_00 is configured as ENET_1G_RX_EN */
        0U);                                  /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B1_01_ENET_1G_RX_CLK, /* GPIO_DISP_B1_01 is configured as ENET_1G_RX_CLK */
        0U);                                   /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B1_02_ENET_1G_RX_DATA00, /* GPIO_DISP_B1_02 is configured as ENET_1G_RX_DATA00 */
        0U);                                      /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B1_03_ENET_1G_RX_DATA01, /* GPIO_DISP_B1_03 is configured as ENET_1G_RX_DATA01 */
        0U);                                      /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B1_04_ENET_1G_RX_DATA02, /* GPIO_DISP_B1_04 is configured as ENET_1G_RX_DATA02 */
        0U);                                      /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B1_05_ENET_1G_RX_DATA03, /* GPIO_DISP_B1_05 is configured as ENET_1G_RX_DATA03 */
        0U);                                      /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B1_06_ENET_1G_TX_DATA03, /* GPIO_DISP_B1_06 is configured as ENET_1G_TX_DATA03 */
        0U);                                      /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B1_07_ENET_1G_TX_DATA02, /* GPIO_DISP_B1_07 is configured as ENET_1G_TX_DATA02 */
        0U);                                      /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B1_08_ENET_1G_TX_DATA01, /* GPIO_DISP_B1_08 is configured as ENET_1G_TX_DATA01 */
        0U);                                      /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B1_09_ENET_1G_TX_DATA00, /* GPIO_DISP_B1_09 is configured as ENET_1G_TX_DATA00 */
        0U);                                      /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B1_10_ENET_1G_TX_EN, /* GPIO_DISP_B1_10 is configured as ENET_1G_TX_EN */
        0U);                                  /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B1_11_ENET_1G_TX_CLK_IO, /* GPIO_DISP_B1_11 is configured as ENET_1G_TX_CLK_IO */
        0U);                                      /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_DISP_B2_13_GPIO11_IO14, /* GPIO_DISP_B2_13 is configured as GPIO11_IO14 */
        0U);                                /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_EMC_B2_19_ENET_1G_MDC, /* GPIO_EMC_B2_19 is configured as ENET_1G_MDC */
        0U);                               /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_EMC_B2_20_ENET_1G_MDIO, /* GPIO_EMC_B2_20 is configured as ENET_1G_MDIO */
        0U);                                /* Software Input On Field: Input Path is determined by functionality */
}

void LPI2C_InitPins(void)
{
#ifdef USE_LPI2C5
    CLOCK_EnableClock(kCLOCK_Iomuxc);      /* LPCG on: LPCG is ON. */
    CLOCK_EnableClock(kCLOCK_Iomuxc_Lpsr); /* LPCG on: LPCG is ON. */

    IOMUXC_SetPinMux(
        IOMUXC_GPIO_LPSR_04_LPI2C5_SDA, /* GPIO_LPSR_04 is configured as LPI2C5_SDA */
        1U);                            /* Software Input On Field: Force input path of pad GPIO_LPSR_04 */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_LPSR_05_LPI2C5_SCL, /* GPIO_LPSR_05 is configured as LPI2C5_SCL */
        1U);                            /* Software Input On Field: Force input path of pad GPIO_LPSR_05 */

    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_LPSR_04_LPI2C5_SDA, /* GPIO_LPSR_04 PAD functional properties : */
        0x20U);                         /* Slew Rate Field: Slow Slew Rate
                                           Drive Strength Field: normal driver
                                           Pull / Keep Select Field: Pull Disable
                                           Pull Up / Down Config. Field: Weak pull down
                                           Open Drain LPSR Field: Enabled
                                           Domain write protection: Both cores are allowed
                                           Domain write protection lock: Neither of DWP bits is locked */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_LPSR_05_LPI2C5_SCL, /* GPIO_LPSR_05 PAD functional properties : */
        0x20U);                         /* Slew Rate Field: Slow Slew Rate
                                           Drive Strength Field: normal driver
                                           Pull / Keep Select Field: Pull Disable
                                           Pull Up / Down Config. Field: Weak pull down
                                           Open Drain LPSR Field: Enabled
                                           Domain write protection: Both cores are allowed
                                           Domain write protection lock: Neither of DWP bits is locked */
#endif
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: cm7, enableClock: 'true'}
- pin_list:

  - {pin_num: M17, peripheral: LPSPI1, signal: PCS0, pin_signal: GPIO_AD_29, software_input_on: Disable, pull_up_down_config: Pull_Down, pull_keeper_select: Keeper,
    open_drain: Disable, drive_strength: High, slew_rate: Slow}
  - {pin_num: L17, peripheral: LPSPI1, signal: SCK, pin_signal: GPIO_AD_28, software_input_on: Disable, pull_up_down_config: Pull_Down, pull_keeper_select: Keeper,
    open_drain: Disable, drive_strength: High, slew_rate: Slow}
  - {pin_num: J17, peripheral: LPSPI1, signal: SIN, pin_signal: GPIO_AD_31, software_input_on: Disable, pull_up_down_config: Pull_Down, pull_keeper_select: Keeper,
    open_drain: Disable, drive_strength: High, slew_rate: Slow}
  - {pin_num: K17, peripheral: LPSPI1, signal: SOUT, pin_signal: GPIO_AD_30, software_input_on: Disable, pull_up_down_config: Pull_Down, pull_keeper_select: Keeper,
    open_drain: Disable, drive_strength: High, slew_rate: Slow}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins, assigned for the Cortex-M7F core.
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void LPSPI_InitPins(void)
{
#ifdef USE_LPSPI1
    CLOCK_EnableClock(kCLOCK_Iomuxc); /* LPCG on: LPCG is ON. */

    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_28_LPSPI1_SCK, /* GPIO_AD_28 is configured as LPSPI1_SCK */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_29_LPSPI1_PCS0, /* GPIO_AD_29 is configured as LPSPI1_PCS0 */
        0U);                           /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_30_LPSPI1_SOUT, /* GPIO_AD_30 is configured as LPSPI1_SOUT */
        0U);                           /* Software Input On Field: Input Path is determined by functionality */
    IOMUXC_SetPinMux(
        IOMUXC_GPIO_AD_31_LPSPI1_SIN, /* GPIO_AD_31 is configured as LPSPI1_SIN */
        0U);                          /* Software Input On Field: Input Path is determined by functionality */

    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_28_LPSPI1_SCK, /* GPIO_AD_28 PAD functional properties : */
        0x02U);                       /* Slew Rate Field: Slow Slew Rate
                                         Drive Strength Field: high drive strength
                                         Pull / Keep Select Field: Pull Disable, Highz
                                         Pull Up / Down Config. Field: Weak pull down
                                         Open Drain Field: Disabled
                                         Domain write protection: Both cores are allowed
                                         Domain write protection lock: Neither of DWP bits is locked */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_29_LPSPI1_PCS0, /* GPIO_AD_29 PAD functional properties : */
        0x02U);                        /* Slew Rate Field: Slow Slew Rate
                                          Drive Strength Field: high drive strength
                                          Pull / Keep Select Field: Pull Disable, Highz
                                          Pull Up / Down Config. Field: Weak pull down
                                          Open Drain Field: Disabled
                                          Domain write protection: Both cores are allowed
                                          Domain write protection lock: Neither of DWP bits is locked */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_30_LPSPI1_SOUT, /* GPIO_AD_30 PAD functional properties : */
        0x02U);                        /* Slew Rate Field: Slow Slew Rate
                                          Drive Strength Field: high drive strength
                                          Pull / Keep Select Field: Pull Disable, Highz
                                          Pull Up / Down Config. Field: Weak pull down
                                          Open Drain Field: Disabled
                                          Domain write protection: Both cores are allowed
                                          Domain write protection lock: Neither of DWP bits is locked */
    IOMUXC_SetPinConfig(
        IOMUXC_GPIO_AD_31_LPSPI1_SIN, /* GPIO_AD_31 PAD functional properties : */
        0x02U);                       /* Slew Rate Field: Slow Slew Rate
                                         Drive Strength Field: high drive strength
                                         Pull / Keep Select Field: Pull Disable, Highz
                                         Pull Up / Down Config. Field: Weak pull down
                                         Open Drain Field: Disabled
                                         Domain write protection: Both cores are allowed
                                         Domain write protection lock: Neither of DWP bits is locked */
#endif
}

/* SPDX-License-Identifier: BSD-2-Clause */

/**
 * @file
 *
 * @ingroup RTEMSBSPsARMTMS570
 *
 * @brief This header file provides SYS interfaces.
 */

/* The header file is generated by make_header.py from SYS.json */
/* Current script's version can be found at: */
/* https://github.com/AoLaD/rtems-tms570-utils/tree/headers/headers/python */

/*
 * Copyright (c) 2014-2015, Premysl Houdek <kom541000@gmail.com>
 *
 * Czech Technical University in Prague
 * Zikova 1903/4
 * 166 36 Praha 6
 * Czech Republic
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the FreeBSD Project.
*/
#ifndef LIBBSP_ARM_TMS570_SYS1
#define LIBBSP_ARM_TMS570_SYS1

#include <bsp/utility.h>

typedef struct{
  uint32_t SYSPC1;            /*SYS Pin Control Register 1*/
  uint32_t SYSPC2;            /*SYS Pin Control Register 2*/
  uint32_t SYSPC3;            /*SYS Pin Control Register 3*/
  uint32_t SYSPC4;            /*SYS Pin Control Register 4*/
  uint32_t SYSPC5;            /*SYS Pin Control Register 5*/
  uint32_t SYSPC6;            /*SYS Pin Control Register 6*/
  uint32_t SYSPC7;            /*SYS Pin Control Register 7*/
  uint32_t SYSPC8;            /*SYS Pin Control Register 8*/
  uint32_t SYSPC9;            /*SYS Pin Control Register 9*/
  uint8_t reserved1 [12];
  uint32_t CSDIS;             /*Clock Source Disable Register*/
  uint32_t CSDISSET;          /*Clock Source Disable Set Register*/
  uint32_t CSDISCLR;          /*Clock Source Disable Clear Register*/
  uint32_t CDDIS;             /*Clock Domain Disable Register*/
  uint32_t CDDISSET;          /*Clock Domain Disable Set Register*/
  uint32_t CDDISCLR;          /*Clock Domain Disable Clear Register*/
  uint32_t GHVSRC;            /*GCLK, HCLK, VCLK, and VCLK2 Source Register*/
  uint32_t VCLKASRC;          /*Peripheral Asynchronous Clock Source Register*/
  uint32_t RCLKSRC;           /*RTI Clock Source Register*/
  uint32_t CSVSTAT;           /*Clock Source Valid Status Register*/
  uint32_t MSTGCR;            /*Memory Self-Test Global Control Register*/
  uint32_t MINITGCR;          /*Memory Hardware Initialization Global Control Register*/
  uint32_t MSIENA;            /*Memory Self-Test/Initialization Enable Register*/
  uint8_t reserved2 [4];
  uint32_t MSTCGSTAT;         /*MSTC Global Status Register*/
  uint32_t MINISTAT;          /*Memory Hardware Initialization Status Register*/
  uint32_t PLLCTL1;           /*PLL Control Register 1*/
  uint32_t PLLCTL2;           /*PLL Control Register 2*/
  uint32_t SYSPC10;           /*SYS Pin Control Register 10*/
  uint32_t DIEIDL;            /*Die Identification Register, Lower Word*/
  uint32_t DIEIDH;            /*Die Identification Register, Upper Word*/
  uint8_t reserved3 [4];
  uint32_t LPOMONCTL;         /*LPO/Clock Monitor Control Register*/
  uint32_t CLKTEST;           /*Clock Test Register*/
  uint32_t DFTCTRLREG1;       /*DFT Control Register*/
  uint32_t DFTCTRLREG2;       /*DFT Control Register 2*/
  uint8_t reserved4 [8];
  uint32_t GPREG1;            /*General Purpose Register*/
  uint8_t reserved5 [4];
  uint32_t IMPFASTS;          /*Imprecise Fault Status Register*/
  uint32_t IMPFTADD;          /*Imprecise Fault Write Address Register*/
  uint32_t SSIR1;             /*System Software Interrupt Request 1 Register*/
  uint32_t SSIR2;             /*System Software Interrupt Request 2 Register*/
  uint32_t SSIR3;             /*System Software Interrupt Request 3 Register*/
  uint32_t SSIR4;             /*System Software Interrupt Request 4 Register*/
  uint32_t RAMGCR;            /*RAM Control Register*/
  uint32_t BMMCR1;            /*Bus Matrix Module Control Register 1*/
  uint8_t reserved6 [4];
  uint32_t CPURSTCR;          /*CPU Reset Control Register*/
  uint32_t CLKCNTL;           /*Clock Control Register*/
  uint32_t ECPCNTL;           /*ECP Control Register*/
  uint8_t reserved7 [4];
  uint32_t DEVCR1;            /*DEV Parity Control Register 1*/
  uint32_t SYSECR;            /*System Exception Control Register*/
  uint32_t SYSESR;            /*System Exception Status Register*/
  uint32_t SYSTASR;           /*System Test Abort Status Register*/
  uint32_t GLBSTAT;           /*Global Status Register*/
  uint32_t DEVID;             /*Device Identification Register*/
  uint32_t SSIVEC;            /*Software Interrupt Vector Register*/
  uint32_t SSIF;              /*System Software Interrupt Flag Register*/
} tms570_sys1_t;


/*---------------------TMS570_SYS1_SYSPCx---------------------*/
/* field: ECPCLKFUN - ECLK function. This bit changes the function of the ECLK pin. */
#define TMS570_SYS1_SYSPCx_ECPCLKFUN BSP_BIT32(0)


/*---------------------TMS570_SYS1_CSDIS---------------------*/
/* field: CLKSROFF - Clock source[7-0] off. 2 reserved */
#define TMS570_SYS1_CSDIS_CLKSROFF(val) BSP_FLD32(val,0, 7)
#define TMS570_SYS1_CSDIS_CLKSROFF_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_SYS1_CSDIS_CLKSROFF_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)

/* Clock Source 0                    Oscillator */
#define TMS570_SYS1_CSDIS_CLKSR_OSC_NUM       0
#define TMS570_SYS1_CSDIS_CLKSROFF_OSC        BSP_BIT32(0)

/* Clock Source 1                      PLL1 */
#define TMS570_SYS1_CSDIS_CLKSR_PLL1_NUM      1
#define TMS570_SYS1_CSDIS_CLKSROFF_PLL1       BSP_BIT32(1)

/* Clock Source 3                  EXTCLKIN */
#define TMS570_SYS1_CSDIS_CLKSR_EXTCLKIN_NUM  3
#define TMS570_SYS1_CSDIS_CLKSROFF_EXTCLKIN   BSP_BIT32(3)

/* Clock Source 4 Low Frequency LPO (Low Power Oscillator) clock */
#define TMS570_SYS1_CSDIS_CLKSR_LPO_NUM       4
#define TMS570_SYS1_CSDIS_CLKSROFF_LPO        BSP_BIT32(4)

/* Clock Source 5 High Frequency LPO (Low Power Oscillator) clock */
#define TMS570_SYS1_CSDIS_CLKSR_HPO_NUM       5
#define TMS570_SYS1_CSDIS_CLKSROFF_HPO        BSP_BIT32(5)

/* Clock Source 6                      PLL2 */
#define TMS570_SYS1_CSDIS_CLKSR_PLL2_NUM      6
#define TMS570_SYS1_CSDIS_CLKSROFF_PLL2       BSP_BIT32(6)

/* Clock Source 7                  EXTCLKIN2 */
#define TMS570_SYS1_CSDIS_CLKSR_EXTCLKIN2_NUM 7
#define TMS570_SYS1_CSDIS_CLKSROFF_EXTCLKIN2  BSP_BIT32(7)

/*--------------------TMS570_SYS1_CSDISSET--------------------*/
/* field: SETCLKSR_OFF - Set clock source[7-0] to the disabled state. */
#define TMS570_SYS1_CSDISSET_SETCLKSR_OFF(val) BSP_FLD32(val,0, 7)
#define TMS570_SYS1_CSDISSET_SETCLKSR_OFF_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_SYS1_CSDISSET_SETCLKSR_OFF_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)

/*--------------------TMS570_SYS1_CSDISCLR--------------------*/
/* field: CLRCLKSR_OFF - Enables clock source[7-0] */
#define TMS570_SYS1_CSDISCLR_CLRCLKSR_OFF(val) BSP_FLD32(val,0, 7)
#define TMS570_SYS1_CSDISCLR_CLRCLKSR_OFF_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_SYS1_CSDISCLR_CLRCLKSR_OFF_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)

/*---------------------TMS570_SYS1_CDDIS---------------------*/
/* field: VCLKAOFF - VCLKA4 domain off. */
#define TMS570_SYS1_CDDIS_VCLKAOFF4 BSP_BIT32(11)

/* field: VCLKAOFF - VCLKA3 domain off. */
#define TMS570_SYS1_CDDIS_VCLKAOFF3 BSP_BIT32(10)

/* field: VCLK3OFF - VCLK3 domain off. */
#define TMS570_SYS1_CDDIS_VCLK3OFF BSP_BIT32(8)

/* field: RTICLK1OFF - RTICLK1 domain off. */
#define TMS570_SYS1_CDDIS_RTICLK1OFF BSP_BIT32(6)

/* field: VCLKAOFF - VCLKA2 domain off. */
#define TMS570_SYS1_CDDIS_VCLKAOFF2 BSP_BIT32(5)

/* field: VCLKAOFF - VCLKA1 domain off. */
#define TMS570_SYS1_CDDIS_VCLKAOFF1 BSP_BIT32(4)

/* field: VCLK2OFF - VCLK2 domain off. */
#define TMS570_SYS1_CDDIS_VCLK2OFF BSP_BIT32(3)

/* field: VCLKPOFF - VCLK_periph domain off. */
#define TMS570_SYS1_CDDIS_VCLKPOFF BSP_BIT32(2)

/* field: HCLKOFF - HCLK and VCLK_sys domains off. */
#define TMS570_SYS1_CDDIS_HCLKOFF BSP_BIT32(1)

/* field: GCLKOFF - GCLK domain off. */
#define TMS570_SYS1_CDDIS_GCLKOFF BSP_BIT32(0)


/*--------------------TMS570_SYS1_CDDISSET--------------------*/
/* field: SETVCLKA_OFF - Set VCLKA[4-3] domain. */
#define TMS570_SYS1_CDDISSET_SETVCLKA_OFF(val) BSP_FLD32(val,10, 11)
#define TMS570_SYS1_CDDISSET_SETVCLKA_OFF_GET(reg) BSP_FLD32GET(reg,10, 11)
#define TMS570_SYS1_CDDISSET_SETVCLKA_OFF_SET(reg,val) BSP_FLD32SET(reg, val,10, 11)

/* field: SETVCLK3OFF - Set VCLK3 domain. */
#define TMS570_SYS1_CDDISSET_SETVCLK3OFF BSP_BIT32(8)

/* field: SETRTI1CLKOFF - Set RTICLK1 domain. */
#define TMS570_SYS1_CDDISSET_SETRTI1CLKOFF BSP_BIT32(6)

/* field: SETTVCLKA2OFF - Set VCLKA2 domain. */
#define TMS570_SYS1_CDDISSET_SETTVCLKA2OFF BSP_BIT32(5)

/* field: SETVCLKA1OFF - Set VCLKA1 domain. */
#define TMS570_SYS1_CDDISSET_SETVCLKA1OFF BSP_BIT32(4)

/* field: SETVCLK2OFF - Set VCLK2 domain. */
#define TMS570_SYS1_CDDISSET_SETVCLK2OFF BSP_BIT32(3)

/* field: SETVCLKPOFF - Set VCLK_periph domain. */
#define TMS570_SYS1_CDDISSET_SETVCLKPOFF BSP_BIT32(2)

/* field: SETHCLKOFF - Set HCLK and VCLK_sys domains. */
#define TMS570_SYS1_CDDISSET_SETHCLKOFF BSP_BIT32(1)

/* field: SETGCLKOFF - Set GCLK domain. */
#define TMS570_SYS1_CDDISSET_SETGCLKOFF BSP_BIT32(0)


/*--------------------TMS570_SYS1_CDDISCLR--------------------*/
/* field: CLRVCLKAOFF - Clear VCLKA[4-3] domain. */
#define TMS570_SYS1_CDDISCLR_CLRVCLKAOFF(val) BSP_FLD32(val,10, 11)
#define TMS570_SYS1_CDDISCLR_CLRVCLKAOFF_GET(reg) BSP_FLD32GET(reg,10, 11)
#define TMS570_SYS1_CDDISCLR_CLRVCLKAOFF_SET(reg,val) BSP_FLD32SET(reg, val,10, 11)

/* field: Reserved - Reserved */
#define TMS570_SYS1_CDDISCLR_Reserved BSP_BIT32(9)

/* field: CLRVCLK3OFF - Clear VCLK3 domain. */
#define TMS570_SYS1_CDDISCLR_CLRVCLK3OFF BSP_BIT32(8)

/* field: CLRRTI1CLKOFF - Clear RTICLK1 domain. */
#define TMS570_SYS1_CDDISCLR_CLRRTI1CLKOFF BSP_BIT32(6)

/* field: CLRTVCLKA2OFF - Clear VCLKA2 domain. */
#define TMS570_SYS1_CDDISCLR_CLRTVCLKA2OFF BSP_BIT32(5)

/* field: CLRVCLKA1OFF - Clear VCLKA1 domain. */
#define TMS570_SYS1_CDDISCLR_CLRVCLKA1OFF BSP_BIT32(4)

/* field: CLRVCLK2OFF - Clear VCLK2 domain. */
#define TMS570_SYS1_CDDISCLR_CLRVCLK2OFF BSP_BIT32(3)

/* field: CLRVCLKPOFF - CLRVCLKPOFF */
#define TMS570_SYS1_CDDISCLR_CLRVCLKPOFF BSP_BIT32(2)

/* field: CLRHCLKOFF - Clear HCLK and VCLK_sys domains. */
#define TMS570_SYS1_CDDISCLR_CLRHCLKOFF BSP_BIT32(1)

/* field: CLRGCLKOFF - Clear GCLK domain. */
#define TMS570_SYS1_CDDISCLR_CLRGCLKOFF BSP_BIT32(0)


/*---------------------TMS570_SYS1_GHVSRC---------------------*/
/* field: GHVWAKE - GCLK, HCLK, VCLK, VCLK2 source on wakeup. */
#define TMS570_SYS1_GHVSRC_GHVWAKE(val) BSP_FLD32(val,24, 27)
#define TMS570_SYS1_GHVSRC_GHVWAKE_GET(reg) BSP_FLD32GET(reg,24, 27)
#define TMS570_SYS1_GHVSRC_GHVWAKE_SET(reg,val) BSP_FLD32SET(reg, val,24, 27)

/* field: HVLPM - HCLK, VCLK, VCLK2 source on wakeup when GCLK is turned off. */
#define TMS570_SYS1_GHVSRC_HVLPM(val) BSP_FLD32(val,16, 19)
#define TMS570_SYS1_GHVSRC_HVLPM_GET(reg) BSP_FLD32GET(reg,16, 19)
#define TMS570_SYS1_GHVSRC_HVLPM_SET(reg,val) BSP_FLD32SET(reg, val,16, 19)

/* field: GHVSRC - GCLK, HCLK, VCLK, VCLK2 current source. */
#define TMS570_SYS1_GHVSRC_GHVSRC(val) BSP_FLD32(val,0, 3)
#define TMS570_SYS1_GHVSRC_GHVSRC_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_SYS1_GHVSRC_GHVSRC_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*--------------------TMS570_SYS1_VCLKASRC--------------------*/
/* field: VCLKA2S - Peripheral asynchronous clock2 source. */
#define TMS570_SYS1_VCLKASRC_VCLKA2S(val) BSP_FLD32(val,8, 11)
#define TMS570_SYS1_VCLKASRC_VCLKA2S_GET(reg) BSP_FLD32GET(reg,8, 11)
#define TMS570_SYS1_VCLKASRC_VCLKA2S_SET(reg,val) BSP_FLD32SET(reg, val,8, 11)

/* field: VCLKA1S - Peripheral asynchronous clock1 source. */
#define TMS570_SYS1_VCLKASRC_VCLKA1S(val) BSP_FLD32(val,0, 3)
#define TMS570_SYS1_VCLKASRC_VCLKA1S_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_SYS1_VCLKASRC_VCLKA1S_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*--------------------TMS570_SYS1_RCLKSRC--------------------*/
/* field: RTI1DIV - RTI clock1 Divider. */
#define TMS570_SYS1_RCLKSRC_RTI1DIV(val) BSP_FLD32(val,8, 9)
#define TMS570_SYS1_RCLKSRC_RTI1DIV_GET(reg) BSP_FLD32GET(reg,8, 9)
#define TMS570_SYS1_RCLKSRC_RTI1DIV_SET(reg,val) BSP_FLD32SET(reg, val,8, 9)

/* field: RTI1SRC - RTI clock1 source. */
#define TMS570_SYS1_RCLKSRC_RTI1SRC(val) BSP_FLD32(val,0, 3)
#define TMS570_SYS1_RCLKSRC_RTI1SRC_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_SYS1_RCLKSRC_RTI1SRC_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*--------------------TMS570_SYS1_CSVSTAT--------------------*/
/* field: CLKSRV - Clock source[7-0] valid. */
#define TMS570_SYS1_CSVSTAT_CLKSRV(val) BSP_FLD32(val,3, 7)
#define TMS570_SYS1_CSVSTAT_CLKSRV_GET(reg) BSP_FLD32GET(reg,3, 7)
#define TMS570_SYS1_CSVSTAT_CLKSRV_SET(reg,val) BSP_FLD32SET(reg, val,3, 7)

/* field: CLKSR - Clock source[1-0] valid. */
#define TMS570_SYS1_CSVSTAT_CLKSR(val) BSP_FLD32(val,0, 1)
#define TMS570_SYS1_CSVSTAT_CLKSR_GET(reg) BSP_FLD32GET(reg,0, 1)
#define TMS570_SYS1_CSVSTAT_CLKSR_SET(reg,val) BSP_FLD32SET(reg, val,0, 1)


/*---------------------TMS570_SYS1_MSTGCR---------------------*/
/* field: ROM_DIV - Prescaler divider bits for ROM clock source. */
#define TMS570_SYS1_MSTGCR_ROM_DIV(val) BSP_FLD32(val,8, 9)
#define TMS570_SYS1_MSTGCR_ROM_DIV_GET(reg) BSP_FLD32GET(reg,8, 9)
#define TMS570_SYS1_MSTGCR_ROM_DIV_SET(reg,val) BSP_FLD32SET(reg, val,8, 9)

/* field: MSTGENA - Memory self-test controller global enable key */
#define TMS570_SYS1_MSTGCR_MSTGENA(val) BSP_FLD32(val,0, 3)
#define TMS570_SYS1_MSTGCR_MSTGENA_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_SYS1_MSTGCR_MSTGENA_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*--------------------TMS570_SYS1_MINITGCR--------------------*/
/* field: MINITGENA - Memory hardware initialization global enable key. */
#define TMS570_SYS1_MINITGCR_MINITGENA(val) BSP_FLD32(val,0, 3)
#define TMS570_SYS1_MINITGCR_MINITGENA_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_SYS1_MINITGCR_MINITGENA_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*---------------------TMS570_SYS1_MSIENA---------------------*/
/* field: MSIENA - PBIST controller and memory initialization enable register. */
/* Whole 32 bits */

/*-------------------TMS570_SYS1_MSTCGSTAT-------------------*/
/* field: MINIDONE - Memory hardware initialization complete status. */
#define TMS570_SYS1_MSTCGSTAT_MINIDONE BSP_BIT32(8)

/* field: MSTDONE - Memory self-test run complete status. */
#define TMS570_SYS1_MSTCGSTAT_MSTDONE BSP_BIT32(0)


/*--------------------TMS570_SYS1_MINISTAT--------------------*/
/* field: MIDONE - Memory hardware initialization status bit. */
/* Whole 32 bits */

/*--------------------TMS570_SYS1_PLLCTL1--------------------*/
/* field: ROS - Reset on PLL Slip */
#define TMS570_SYS1_PLLCTL1_ROS BSP_BIT32(31)

/* field: MASK_SLIP - Mask detection of PLL slip */
#define TMS570_SYS1_PLLCTL1_MASK_SLIP(val) BSP_FLD32(val,29, 30)
#define TMS570_SYS1_PLLCTL1_MASK_SLIP_GET(reg) BSP_FLD32GET(reg,29, 30)
#define TMS570_SYS1_PLLCTL1_MASK_SLIP_SET(reg,val) BSP_FLD32SET(reg, val,29, 30)

/* field: PLLDIV - PLL Output Clock Divider */
#define TMS570_SYS1_PLLCTL1_PLLDIV(val) BSP_FLD32(val,24, 28)
#define TMS570_SYS1_PLLCTL1_PLLDIV_GET(reg) BSP_FLD32GET(reg,24, 28)
#define TMS570_SYS1_PLLCTL1_PLLDIV_SET(reg,val) BSP_FLD32SET(reg, val,24, 28)

/* field: ROF - Reset on Oscillator Fail */
#define TMS570_SYS1_PLLCTL1_ROF BSP_BIT32(23)

/* field: REFCLKDIV - Reference Clock Divider */
#define TMS570_SYS1_PLLCTL1_REFCLKDIV(val) BSP_FLD32(val,16, 21)
#define TMS570_SYS1_PLLCTL1_REFCLKDIV_GET(reg) BSP_FLD32GET(reg,16, 21)
#define TMS570_SYS1_PLLCTL1_REFCLKDIV_SET(reg,val) BSP_FLD32SET(reg, val,16, 21)

/* field: PLLMUL - PLL Multiplication Factor */
#define TMS570_SYS1_PLLCTL1_PLLMUL(val) BSP_FLD32(val,0, 15)
#define TMS570_SYS1_PLLCTL1_PLLMUL_GET(reg) BSP_FLD32GET(reg,0, 15)
#define TMS570_SYS1_PLLCTL1_PLLMUL_SET(reg,val) BSP_FLD32SET(reg, val,0, 15)


/*--------------------TMS570_SYS1_PLLCTL2--------------------*/
/* field: FMENA - Frequency Modulation Enable. */
#define TMS570_SYS1_PLLCTL2_FMENA BSP_BIT32(31)

/* field: SPREADINGRATE - NS = SPREADINGRATE + 1 */
#define TMS570_SYS1_PLLCTL2_SPREADINGRATE(val) BSP_FLD32(val,22, 30)
#define TMS570_SYS1_PLLCTL2_SPREADINGRATE_GET(reg) BSP_FLD32GET(reg,22, 30)
#define TMS570_SYS1_PLLCTL2_SPREADINGRATE_SET(reg,val) BSP_FLD32SET(reg, val,22, 30)

/* field: MULMOD - Multiplier Correction when Frequency Modulation is enabled. */
#define TMS570_SYS1_PLLCTL2_MULMOD(val) BSP_FLD32(val,12, 20)
#define TMS570_SYS1_PLLCTL2_MULMOD_GET(reg) BSP_FLD32GET(reg,12, 20)
#define TMS570_SYS1_PLLCTL2_MULMOD_SET(reg,val) BSP_FLD32SET(reg, val,12, 20)

/* field: ODPLL - Internal PLL Output Divider. */
#define TMS570_SYS1_PLLCTL2_ODPLL(val) BSP_FLD32(val,9, 11)
#define TMS570_SYS1_PLLCTL2_ODPLL_GET(reg) BSP_FLD32GET(reg,9, 11)
#define TMS570_SYS1_PLLCTL2_ODPLL_SET(reg,val) BSP_FLD32SET(reg, val,9, 11)

/* field: SPR_AMOUNT - Spreading Amount. */
#define TMS570_SYS1_PLLCTL2_SPR_AMOUNT(val) BSP_FLD32(val,0, 8)
#define TMS570_SYS1_PLLCTL2_SPR_AMOUNT_GET(reg) BSP_FLD32GET(reg,0, 8)
#define TMS570_SYS1_PLLCTL2_SPR_AMOUNT_SET(reg,val) BSP_FLD32SET(reg, val,0, 8)


/*--------------------TMS570_SYS1_SYSPC10--------------------*/
/* field: ECPCLK_SLEW - ECPCLK slew control. This bit controls between the fast or slow slew mode. */
#define TMS570_SYS1_SYSPC10_ECPCLK_SLEW BSP_BIT32(0)


/*---------------------TMS570_SYS1_DIEIDL---------------------*/
/* field: LOT - These read only bits contain the lower 10 bits of the device lot number. */
#define TMS570_SYS1_DIEIDL_LOT(val) BSP_FLD32(val,22, 31)
#define TMS570_SYS1_DIEIDL_LOT_GET(reg) BSP_FLD32GET(reg,22, 31)
#define TMS570_SYS1_DIEIDL_LOT_SET(reg,val) BSP_FLD32SET(reg, val,22, 31)

/* field: WAFER - These read only bits contain the wafer number of the device. */
#define TMS570_SYS1_DIEIDL_WAFER(val) BSP_FLD32(val,16, 21)
#define TMS570_SYS1_DIEIDL_WAFER_GET(reg) BSP_FLD32GET(reg,16, 21)
#define TMS570_SYS1_DIEIDL_WAFER_SET(reg,val) BSP_FLD32SET(reg, val,16, 21)

/* field: Y_WAFER_COORDINATE - These read only bits contain the Y wafer coordinate of the device */
#define TMS570_SYS1_DIEIDL_Y_WAFER_COORDINATE(val) BSP_FLD32(val,8, 15)
#define TMS570_SYS1_DIEIDL_Y_WAFER_COORDINATE_GET(reg) BSP_FLD32GET(reg,8, 15)
#define TMS570_SYS1_DIEIDL_Y_WAFER_COORDINATE_SET(reg,val) BSP_FLD32SET(reg, val,8, 15)

/* field: X_WAFER_COORDINATE - These read only bits contain the X wafer coordinate of the device */
#define TMS570_SYS1_DIEIDL_X_WAFER_COORDINATE(val) BSP_FLD32(val,0, 7)
#define TMS570_SYS1_DIEIDL_X_WAFER_COORDINATE_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_SYS1_DIEIDL_X_WAFER_COORDINATE_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)


/*---------------------TMS570_SYS1_DIEIDH---------------------*/
/* field: LOT - This read-only register contains the upper 14 bits of the device lot number. */
#define TMS570_SYS1_DIEIDH_LOT(val) BSP_FLD32(val,0, 13)
#define TMS570_SYS1_DIEIDH_LOT_GET(reg) BSP_FLD32GET(reg,0, 13)
#define TMS570_SYS1_DIEIDH_LOT_SET(reg,val) BSP_FLD32SET(reg, val,0, 13)


/*-------------------TMS570_SYS1_LPOMONCTL-------------------*/
/* field: BIAS_ENABLE - Bias enable. */
#define TMS570_SYS1_LPOMONCTL_BIAS_ENABLE BSP_BIT32(24)

/* field: OSCFRQCONFIGCNT - Configures the counter based on OSC frequency. */
#define TMS570_SYS1_LPOMONCTL_OSCFRQCONFIGCNT BSP_BIT32(16)

/* field: HFTRIM - High frequency oscillator trim value. */
#define TMS570_SYS1_LPOMONCTL_HFTRIM(val) BSP_FLD32(val,8, 12)
#define TMS570_SYS1_LPOMONCTL_HFTRIM_GET(reg) BSP_FLD32GET(reg,8, 12)
#define TMS570_SYS1_LPOMONCTL_HFTRIM_SET(reg,val) BSP_FLD32SET(reg, val,8, 12)


/*--------------------TMS570_SYS1_CLKTEST--------------------*/
/* field: ALTLIMPCLOCKENABLE - This bit selects a clock driven by the GIOB[0] pin as an alternate limp clock to the clock */
#define TMS570_SYS1_CLKTEST_ALTLIMPCLOCKENABLE BSP_BIT32(26)

/* field: RANGEDETCTRL - Range detection control. */
#define TMS570_SYS1_CLKTEST_RANGEDETCTRL BSP_BIT32(25)

/* field: RANGEDETENASSEL - Selects range detection enable. This bit resets asynchronously on power on reset. */
#define TMS570_SYS1_CLKTEST_RANGEDETENASSEL BSP_BIT32(24)

/* field: CLK_TEST_EN - Clock test enable. This bit enables the clock going to the ECLK pin. */
#define TMS570_SYS1_CLKTEST_CLK_TEST_EN(val) BSP_FLD32(val,16, 19)
#define TMS570_SYS1_CLKTEST_CLK_TEST_EN_GET(reg) BSP_FLD32GET(reg,16, 19)
#define TMS570_SYS1_CLKTEST_CLK_TEST_EN_SET(reg,val) BSP_FLD32SET(reg, val,16, 19)

/* field: SEL_GIO_PIN - GIOB[0] pin clock source valid, clock source select */
#define TMS570_SYS1_CLKTEST_SEL_GIO_PIN(val) BSP_FLD32(val,8, 11)
#define TMS570_SYS1_CLKTEST_SEL_GIO_PIN_GET(reg) BSP_FLD32GET(reg,8, 11)
#define TMS570_SYS1_CLKTEST_SEL_GIO_PIN_SET(reg,val) BSP_FLD32SET(reg, val,8, 11)

/* field: SEL_ECP_PIN - ECLK pin clock source select */
#define TMS570_SYS1_CLKTEST_SEL_ECP_PIN(val) BSP_FLD32(val,0, 3)
#define TMS570_SYS1_CLKTEST_SEL_ECP_PIN_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_SYS1_CLKTEST_SEL_ECP_PIN_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*------------------TMS570_SYS1_DFTCTRLREG1------------------*/
/* field: DFTWRITE - DFT logic access. */
#define TMS570_SYS1_DFTCTRLREG1_DFTWRITE(val) BSP_FLD32(val,12, 13)
#define TMS570_SYS1_DFTCTRLREG1_DFTWRITE_GET(reg) BSP_FLD32GET(reg,12, 13)
#define TMS570_SYS1_DFTCTRLREG1_DFTWRITE_SET(reg,val) BSP_FLD32SET(reg, val,12, 13)

/* field: DFTREAD - DFT logic access. */
#define TMS570_SYS1_DFTCTRLREG1_DFTREAD(val) BSP_FLD32(val,8, 9)
#define TMS570_SYS1_DFTCTRLREG1_DFTREAD_GET(reg) BSP_FLD32GET(reg,8, 9)
#define TMS570_SYS1_DFTCTRLREG1_DFTREAD_SET(reg,val) BSP_FLD32SET(reg, val,8, 9)

/* field: TEST_MODE_KEY - Test mode key. This register is for internal TI use only. */
#define TMS570_SYS1_DFTCTRLREG1_TEST_MODE_KEY(val) BSP_FLD32(val,0, 3)
#define TMS570_SYS1_DFTCTRLREG1_TEST_MODE_KEY_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_SYS1_DFTCTRLREG1_TEST_MODE_KEY_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*------------------TMS570_SYS1_DFTCTRLREG2------------------*/
/* field: IMPDF - DFT Implementation defined bits. */
#define TMS570_SYS1_DFTCTRLREG2_IMPDF(val) BSP_FLD32(val,4, 31)
#define TMS570_SYS1_DFTCTRLREG2_IMPDF_GET(reg) BSP_FLD32GET(reg,4, 31)
#define TMS570_SYS1_DFTCTRLREG2_IMPDF_SET(reg,val) BSP_FLD32SET(reg, val,4, 31)

/* field: TEST_MODE_KEY - Test mode key. This register is for internal TI use only. */
#define TMS570_SYS1_DFTCTRLREG2_TEST_MODE_KEY(val) BSP_FLD32(val,0, 3)
#define TMS570_SYS1_DFTCTRLREG2_TEST_MODE_KEY_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_SYS1_DFTCTRLREG2_TEST_MODE_KEY_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*---------------------TMS570_SYS1_GPREG1---------------------*/
/* field: EMIF_FUNC - Enable EMIF functions to be output. */
#define TMS570_SYS1_GPREG1_EMIF_FUNC BSP_BIT32(31)

/* field: PLL1_FBSLIP_FILTER__COUNT - FBSLIP down counter programmed value. */
#define TMS570_SYS1_GPREG1_PLL1_FBSLIP_FILTER__COUNT(val) BSP_FLD32(val,20, 25)
#define TMS570_SYS1_GPREG1_PLL1_FBSLIP_FILTER__COUNT_GET(reg) BSP_FLD32GET(reg,20, 25)
#define TMS570_SYS1_GPREG1_PLL1_FBSLIP_FILTER__COUNT_SET(reg,val) BSP_FLD32SET(reg, val,20, 25)

/* field: PLL1_RFSLIP_FILTER__KEY - Configures the system response when a FBSLIP is indicated by the */
#define TMS570_SYS1_GPREG1_PLL1_RFSLIP_FILTER__KEY(val) BSP_FLD32(val,16, 19)
#define TMS570_SYS1_GPREG1_PLL1_RFSLIP_FILTER__KEY_GET(reg) BSP_FLD32GET(reg,16, 19)
#define TMS570_SYS1_GPREG1_PLL1_RFSLIP_FILTER__KEY_SET(reg,val) BSP_FLD32SET(reg, val,16, 19)

/* field: OUTPUT_BUFFER_LOW_EMI_MODE - Control field for the low-EMI mode of output buffers for */
#define TMS570_SYS1_GPREG1_OUTPUT_BUFFER_LOW_EMI_MODE(val) BSP_FLD32(val,0, 15)
#define TMS570_SYS1_GPREG1_OUTPUT_BUFFER_LOW_EMI_MODE_GET(reg) BSP_FLD32GET(reg,0, 15)
#define TMS570_SYS1_GPREG1_OUTPUT_BUFFER_LOW_EMI_MODE_SET(reg,val) BSP_FLD32SET(reg, val,0, 15)


/*--------------------TMS570_SYS1_IMPFASTS--------------------*/
/* field: ECPCLKFUN - ECLK function. This bit changes the function of the ECLK pin. */
#define TMS570_SYS1_IMPFASTS_ECPCLKFUN BSP_BIT32(0)


/*--------------------TMS570_SYS1_IMPFTADD--------------------*/
/* field: IMPFTADD - These bits contain the fault address when an imprecise abort occurs. */
/* Whole 32 bits */

/*---------------------TMS570_SYS1_SSIRx---------------------*/
/* field: SSKEY1 - System software interrupt request key. A 075h written to these bits initiates IRQ/FIQ interrupts. */
#define TMS570_SYS1_SSIRx_SSKEY1(val) BSP_FLD32(val,8, 15)
#define TMS570_SYS1_SSIRx_SSKEY1_GET(reg) BSP_FLD32GET(reg,8, 15)
#define TMS570_SYS1_SSIRx_SSKEY1_SET(reg,val) BSP_FLD32SET(reg, val,8, 15)

/* field: SSDATA1 - System software interrupt data. These bits contain user read/write register bits. */
#define TMS570_SYS1_SSIRx_SSDATA1(val) BSP_FLD32(val,0, 7)
#define TMS570_SYS1_SSIRx_SSDATA1_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_SYS1_SSIRx_SSDATA1_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)


/*---------------------TMS570_SYS1_RAMGCR---------------------*/
/* field: RAM_DFT_EN - Functional mode RAM DFT (Design For Test) port enable key. */
#define TMS570_SYS1_RAMGCR_RAM_DFT_EN(val) BSP_FLD32(val,16, 19)
#define TMS570_SYS1_RAMGCR_RAM_DFT_EN_GET(reg) BSP_FLD32GET(reg,16, 19)
#define TMS570_SYS1_RAMGCR_RAM_DFT_EN_SET(reg,val) BSP_FLD32SET(reg, val,16, 19)

/* field: WST_AENA0 - eSRAM data phase wait state enable bit. */
#define TMS570_SYS1_RAMGCR_WST_AENA0 BSP_BIT32(2)

/* field: WST_DENA0 - eSRAM data phase wait state enable bit. */
#define TMS570_SYS1_RAMGCR_WST_DENA0 BSP_BIT32(0)


/*---------------------TMS570_SYS1_BMMCR1---------------------*/
/* field: MEMSW - Memory swap key. */
#define TMS570_SYS1_BMMCR1_MEMSW(val) BSP_FLD32(val,0, 3)
#define TMS570_SYS1_BMMCR1_MEMSW_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_SYS1_BMMCR1_MEMSW_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*--------------------TMS570_SYS1_CPURSTCR--------------------*/
/* field: CPU_RESET - CPU Reset. */
#define TMS570_SYS1_CPURSTCR_CPU_RESET BSP_BIT32(0)


/*--------------------TMS570_SYS1_CLKCNTL--------------------*/
/* field: VCLK2R - VBUS clock2 ratio. */
#define TMS570_SYS1_CLKCNTL_VCLK2R(val) BSP_FLD32(val,24, 27)
#define TMS570_SYS1_CLKCNTL_VCLK2R_GET(reg) BSP_FLD32GET(reg,24, 27)
#define TMS570_SYS1_CLKCNTL_VCLK2R_SET(reg,val) BSP_FLD32SET(reg, val,24, 27)

/* field: VCLKR - VBUS clock ratio. */
#define TMS570_SYS1_CLKCNTL_VCLKR(val) BSP_FLD32(val,16, 19)
#define TMS570_SYS1_CLKCNTL_VCLKR_GET(reg) BSP_FLD32GET(reg,16, 19)
#define TMS570_SYS1_CLKCNTL_VCLKR_SET(reg,val) BSP_FLD32SET(reg, val,16, 19)

/* field: PENA - Peripheral enable bit. */
#define TMS570_SYS1_CLKCNTL_PENA BSP_BIT32(8)


/*--------------------TMS570_SYS1_ECPCNTL--------------------*/
/* field: ECPSSEL - This bit allows the selection between VCLK and OSCIN as the clock source for ECLK. */
#define TMS570_SYS1_ECPCNTL_ECPSSEL BSP_BIT32(24)

/* field: ECPCOS - ECP continue on suspend. */
#define TMS570_SYS1_ECPCNTL_ECPCOS BSP_BIT32(23)

/* field: ECPINSEL - Select ECP input clock source. */
#define TMS570_SYS1_ECPCNTL_ECPINSEL(val) BSP_FLD32(val,6, 17)
#define TMS570_SYS1_ECPCNTL_ECPINSEL_GET(reg) BSP_FLD32GET(reg,6, 17)
#define TMS570_SYS1_ECPCNTL_ECPINSEL_SET(reg,val) BSP_FLD32SET(reg, val,6, 17)

/* field: ECPDIV - ECP divider value. */
#define TMS570_SYS1_ECPCNTL_ECPDIV(val) BSP_FLD32(val,0, 15)
#define TMS570_SYS1_ECPCNTL_ECPDIV_GET(reg) BSP_FLD32GET(reg,0, 15)
#define TMS570_SYS1_ECPCNTL_ECPDIV_SET(reg,val) BSP_FLD32SET(reg, val,0, 15)


/*---------------------TMS570_SYS1_DEVCR1---------------------*/
/* field: DEVPARSEL - Device parity select bit key. */
#define TMS570_SYS1_DEVCR1_DEVPARSEL(val) BSP_FLD32(val,0, 3)
#define TMS570_SYS1_DEVCR1_DEVPARSEL_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_SYS1_DEVCR1_DEVPARSEL_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)


/*---------------------TMS570_SYS1_SYSECR---------------------*/
/* field: RESET - Software reset bits. Setting RESET1 or clearing RESET0 causes a system software reset. */
#define TMS570_SYS1_SYSECR_RESET(val) BSP_FLD32(val,14, 15)
#define TMS570_SYS1_SYSECR_RESET_GET(reg) BSP_FLD32GET(reg,14, 15)
#define TMS570_SYS1_SYSECR_RESET_SET(reg,val) BSP_FLD32SET(reg, val,14, 15)


/*---------------------TMS570_SYS1_SYSESR---------------------*/
/* field: PORST - Power-up reset. This bit is set when VCCOR (VCC Out of Range) is detected. */
#define TMS570_SYS1_SYSESR_PORST BSP_BIT32(15)

/* field: OSCRST - Reset caused by an oscillator failure or PLL cycle slip. */
#define TMS570_SYS1_SYSESR_OSCRST BSP_BIT32(14)

/* field: WDRST - Watchdog reset flag. */
#define TMS570_SYS1_SYSESR_WDRST BSP_BIT32(13)

#if TMS570_VARIANT == 4357

/* field: DBGRST - Debug reset flag. */
#define TMS570_SYS1_SYSESR_DBGRST BSP_BIT32(11)

/* field: ICSTRST - Interconnect reset flag. */
#define TMS570_SYS1_SYSESR_ICSTRST BSP_BIT32(7)

#endif

/* field: CPURST - CPU reset flag. This bit is set when the CPU is reset. */
#define TMS570_SYS1_SYSESR_CPURST BSP_BIT32(5)

/* field: SWRST - Software reset flag. This bit is set when a software system reset has occurred. */
#define TMS570_SYS1_SYSESR_SWRST BSP_BIT32(4)

/* field: EXTRST - External reset flag. This bit is set when a reset is caused by the external reset pin nRST. */
#define TMS570_SYS1_SYSESR_EXTRST BSP_BIT32(3)

/* field: MPMODE - This indicates the current memory protection unit (MPU) mode. */
#define TMS570_SYS1_SYSESR_MPMODE BSP_BIT32(0)


/*--------------------TMS570_SYS1_SYSTASR--------------------*/
/* field: EFUSE_Abort - Test Abort status flag. */
#define TMS570_SYS1_SYSTASR_EFUSE_Abort(val) BSP_FLD32(val,0, 4)
#define TMS570_SYS1_SYSTASR_EFUSE_Abort_GET(reg) BSP_FLD32GET(reg,0, 4)
#define TMS570_SYS1_SYSTASR_EFUSE_Abort_SET(reg,val) BSP_FLD32SET(reg, val,0, 4)


/*--------------------TMS570_SYS1_GLBSTAT--------------------*/
/* field: FBSLIP - PLL over cycle slip detection. */
#define TMS570_SYS1_GLBSTAT_FBSLIP BSP_BIT32(9)

/* field: RFSLIP - PLL under cycle slip detection. */
#define TMS570_SYS1_GLBSTAT_RFSLIP BSP_BIT32(8)

/* field: OSCFAIL - Oscillator fail flag bit. */
#define TMS570_SYS1_GLBSTAT_OSCFAIL BSP_BIT32(0)


/*---------------------TMS570_SYS1_DEVID---------------------*/
/* field: CP15 - CP15 CPU. This bit indicates whether the CPU has a coprocessor 15 (CP15). */
#define TMS570_SYS1_DEVID_CP15 BSP_BIT32(31)

/* field: TECH - These bits define the process technology by which the device was manufactured. */
#define TMS570_SYS1_DEVID_TECH(val) BSP_FLD32(val,13, 16)
#define TMS570_SYS1_DEVID_TECH_GET(reg) BSP_FLD32GET(reg,13, 16)
#define TMS570_SYS1_DEVID_TECH_SET(reg,val) BSP_FLD32SET(reg, val,13, 16)

/* field: I_O_VOLTAGE - Input/output voltage. This bit defines the I/O voltage of the device. */
#define TMS570_SYS1_DEVID_I_O_VOLTAGE BSP_BIT32(12)

/* field: PERIPHERAL_PARITY - The peripheral memories have no parity. */
#define TMS570_SYS1_DEVID_PERIPHERAL_PARITY BSP_BIT32(11)

/* field: FLASH_ECC - These bits indicate which parity is present for the program memory. */
#define TMS570_SYS1_DEVID_FLASH_ECC(val) BSP_FLD32(val,9, 10)
#define TMS570_SYS1_DEVID_FLASH_ECC_GET(reg) BSP_FLD32GET(reg,9, 10)
#define TMS570_SYS1_DEVID_FLASH_ECC_SET(reg,val) BSP_FLD32SET(reg, val,9, 10)

/* field: RAM_ECC - RAM ECC. This bit indicates whether or not RAM memory ECC is present. */
#define TMS570_SYS1_DEVID_RAM_ECC BSP_BIT32(8)

/* field: VERSION - Version. These bits provide the revision of the device. */
#define TMS570_SYS1_DEVID_VERSION(val) BSP_FLD32(val,3, 7)
#define TMS570_SYS1_DEVID_VERSION_GET(reg) BSP_FLD32GET(reg,3, 7)
#define TMS570_SYS1_DEVID_VERSION_SET(reg,val) BSP_FLD32SET(reg, val,3, 7)

/* field: PLATFORM_ID - The device is part of the TMS570Px family. The TMS570Px ID is always 5h. */
#define TMS570_SYS1_DEVID_PLATFORM_ID(val) BSP_FLD32(val,0, 2)
#define TMS570_SYS1_DEVID_PLATFORM_ID_GET(reg) BSP_FLD32GET(reg,0, 2)
#define TMS570_SYS1_DEVID_PLATFORM_ID_SET(reg,val) BSP_FLD32SET(reg, val,0, 2)


/*---------------------TMS570_SYS1_SSIVEC---------------------*/
/* field: SSIDATA - System software interrupt data key. */
#define TMS570_SYS1_SSIVEC_SSIDATA(val) BSP_FLD32(val,8, 15)
#define TMS570_SYS1_SSIVEC_SSIDATA_GET(reg) BSP_FLD32GET(reg,8, 15)
#define TMS570_SYS1_SSIVEC_SSIDATA_SET(reg,val) BSP_FLD32SET(reg, val,8, 15)

/* field: SSIVECT - These bits contain the source for the system software interrupt. */
#define TMS570_SYS1_SSIVEC_SSIVECT(val) BSP_FLD32(val,0, 7)
#define TMS570_SYS1_SSIVEC_SSIVECT_GET(reg) BSP_FLD32GET(reg,0, 7)
#define TMS570_SYS1_SSIVEC_SSIVECT_SET(reg,val) BSP_FLD32SET(reg, val,0, 7)


/*----------------------TMS570_SYS1_SSIF----------------------*/
/* field: SSI_FLAG - System software interrupt flag[4-1]. */
#define TMS570_SYS1_SSIF_SSI_FLAG(val) BSP_FLD32(val,0, 3)
#define TMS570_SYS1_SSIF_SSI_FLAG_GET(reg) BSP_FLD32GET(reg,0, 3)
#define TMS570_SYS1_SSIF_SSI_FLAG_SET(reg,val) BSP_FLD32SET(reg, val,0, 3)



#endif /* LIBBSP_ARM_TMS570_SYS1 */

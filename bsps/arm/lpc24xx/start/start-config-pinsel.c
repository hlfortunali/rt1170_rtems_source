/* SPDX-License-Identifier: BSD-2-Clause */

/**
 * @file
 *
 * @ingroup RTEMSBSPsARMLPC24XX
 *
 * @brief BSP start pin selection configuration.
 */

/*
 * Copyright (C) 2011, 2019 embedded brains GmbH & Co. KG
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <bsp/start-config.h>

BSP_START_DATA_SECTION const lpc24xx_pin_range
  lpc24xx_start_config_pinsel [] = {
#if defined(LPC24XX_EMC_MT48LC4M16A2) \
  && (defined(LPC24XX_EMC_M29W160E) || defined(LPC24XX_EMC_SST39VF3201))
#if defined(LPC24XX_EMC_M29W160E)
  LPC24XX_PIN_EMC_A_0_20,
#elif defined(LPC24XX_EMC_SST39VF3201)
  LPC24XX_PIN_EMC_A_0_21,
#endif
  LPC24XX_PIN_EMC_D_0_15,
  LPC24XX_PIN_EMC_RAS,
  LPC24XX_PIN_EMC_CAS,
  LPC24XX_PIN_EMC_WE,
  LPC24XX_PIN_EMC_DYCS_0,
  LPC24XX_PIN_EMC_CLK_0,
  LPC24XX_PIN_EMC_CKE_0,
  LPC24XX_PIN_EMC_DQM_0,
  LPC24XX_PIN_EMC_DQM_1,
  LPC24XX_PIN_EMC_OE,
  LPC24XX_PIN_EMC_CS_1,
#endif
#if (defined(LPC24XX_EMC_IS42S32800D7) || defined(LPC24XX_EMC_W9825G2JB75I)) \
  && (defined(LPC24XX_EMC_M29W320E70) || defined(LPC24XX_EMC_SST39VF3201))
  LPC24XX_PIN_EMC_A_0_22,
  LPC24XX_PIN_EMC_D_0_31,
  LPC24XX_PIN_EMC_RAS,
  LPC24XX_PIN_EMC_CAS,
  LPC24XX_PIN_EMC_WE,
  LPC24XX_PIN_EMC_DYCS_0,
  LPC24XX_PIN_EMC_CLK_0,
  LPC24XX_PIN_EMC_CKE_0,
  LPC24XX_PIN_EMC_DQM_0,
  LPC24XX_PIN_EMC_DQM_1,
  LPC24XX_PIN_EMC_DQM_2,
  LPC24XX_PIN_EMC_DQM_3,
  LPC24XX_PIN_EMC_OE,
  LPC24XX_PIN_EMC_CS_0,
#endif
#if defined(LPC24XX_EMC_IS42S32800B)
  LPC24XX_PIN_EMC_A_0_14,
  LPC24XX_PIN_EMC_D_0_31,
  LPC24XX_PIN_EMC_RAS,
  LPC24XX_PIN_EMC_CAS,
  LPC24XX_PIN_EMC_WE,
  LPC24XX_PIN_EMC_DYCS_0,
  LPC24XX_PIN_EMC_CLK_0,
  LPC24XX_PIN_EMC_CKE_0,
  LPC24XX_PIN_EMC_DQM_0,
  LPC24XX_PIN_EMC_DQM_1,
  LPC24XX_PIN_EMC_DQM_2,
  LPC24XX_PIN_EMC_DQM_3,
#endif
  LPC24XX_PIN_TERMINAL
};
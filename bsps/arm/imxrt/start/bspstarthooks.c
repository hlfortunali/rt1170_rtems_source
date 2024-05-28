/*
 * @Author: LiHeng
 * @Date: 2024-03-11 09:52:44
 * @LastEditors: LiHeng
 * @LastEditTime: 2024-03-15 17:37:49
 * @FilePath: /rt1170_rtems_source/bsps/arm/imxrt/start/bspstarthooks.c
 * @Description:
 *
 * Copyright (c) 2024 by LiHeng, All Rights Reserved.
 */
/* SPDX-License-Identifier: BSD-2-Clause */

/*
 * Copyright (c) 2013-2023 embedded brains GmbH & Co. KG
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

#include <rtems/score/armv7m.h>

#include <bsp.h>
#include <imxrt/mpu-config.h>

#include <chip.h>
#include <fsl_clock_config.h>

#include "fsl_common.h"
#include "fsl_iomuxc.h"

/* MPU configuration. */
static void BOARD_ConfigMPU(void)
{
  // extern uint32_t __base_NCACHE_REGION;
  // extern uint32_t __top_NCACHE_REGION;
  // uint32_t nonCacheStart = (uint32_t)(&__base_NCACHE_REGION);
  // uint32_t size = (uint32_t)(&__top_NCACHE_REGION) - nonCacheStart;

  volatile uint32_t i = 0;

  /* Disable I cache and D cache */
  SCB_DisableICache();

  SCB_DisableDCache();

  /* Disable MPU */
  ARM_MPU_Disable();

  /* MPU configure:
   * Use ARM_MPU_RASR(DisableExec, AccessPermission, TypeExtField, IsShareable, IsCacheable, IsBufferable,
   * SubRegionDisable, Size)
   * API in mpu_armv7.h.
   * param DisableExec       Instruction access (XN) disable bit,0=instruction fetches enabled, 1=instruction fetches
   * disabled.
   * param AccessPermission  Data access permissions, allows you to configure read/write access for User and
   * Privileged mode.
   *      Use MACROS defined in mpu_armv7.h:
   * ARM_MPU_AP_NONE/ARM_MPU_AP_PRIV/ARM_MPU_AP_URO/ARM_MPU_AP_FULL/ARM_MPU_AP_PRO/ARM_MPU_AP_RO
   * Combine TypeExtField/IsShareable/IsCacheable/IsBufferable to configure MPU memory access attributes.
   *  TypeExtField  IsShareable  IsCacheable  IsBufferable   Memory Attribute    Shareability        Cache
   *     0             x           0           0             Strongly Ordered    shareable
   *     0             x           0           1              Device             shareable
   *     0             0           1           0              Normal             not shareable   Outer and inner write
   * through no write allocate
   *     0             0           1           1              Normal             not shareable   Outer and inner write
   * back no write allocate
   *     0             1           1           0              Normal             shareable       Outer and inner write
   * through no write allocate
   *     0             1           1           1              Normal             shareable       Outer and inner write
   * back no write allocate
   *     1             0           0           0              Normal             not shareable   outer and inner
   * noncache
   *     1             1           0           0              Normal             shareable       outer and inner
   * noncache
   *     1             0           1           1              Normal             not shareable   outer and inner write
   * back write/read acllocate
   *     1             1           1           1              Normal             shareable       outer and inner write
   * back write/read acllocate
   *     2             x           0           0              Device              not shareable
   *  Above are normal use settings, if your want to see more details or want to config different inner/outter cache
   * policy.
   *  please refer to Table 4-55 /4-56 in arm cortex-M7 generic user guide <dui0646b_cortex_m7_dgug.pdf>
   * param SubRegionDisable  Sub-region disable field. 0=sub-region is enabled, 1=sub-region is disabled.
   * param Size              Region size of the region to be configured. use ARM_MPU_REGION_SIZE_xxx MACRO in
   * mpu_armv7.h.
   */

  /*
   * Add default region to deny access to whole address space to workaround speculative prefetch.
   * Refer to Arm errata 1013783-B for more details.
   *
   */
  /* Region 0 setting: Instruction access disabled, No data access permission. */
  MPU->RBAR = ARM_MPU_RBAR(0, 0x00000000U);
  MPU->RASR = ARM_MPU_RASR(1, ARM_MPU_AP_NONE, 0, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_4GB);

  /* Region 1 setting: Memory with Device type, not shareable, non-cacheable. */
  MPU->RBAR = ARM_MPU_RBAR(1, 0x80000000U);
  MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_512MB);

  /* Region 2 setting: Memory with Device type, not shareable,  non-cacheable. */
  MPU->RBAR = ARM_MPU_RBAR(2, 0x60000000U);
  MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_512MB);

  /* Region 3 setting: Memory with Device type, not shareable, non-cacheable. */
  MPU->RBAR = ARM_MPU_RBAR(3, 0x00000000U);
  MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_1GB);

  /* Region 4 setting: Memory with Normal type, not shareable, outer/inner write back */
  MPU->RBAR = ARM_MPU_RBAR(4, 0x00000000U);
  MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 1, 0, ARM_MPU_REGION_SIZE_256KB);

  /* Region 5 setting: Memory with Normal type, not shareable, outer/inner write back */
  MPU->RBAR = ARM_MPU_RBAR(5, 0x20000000U);
  MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 1, 0, ARM_MPU_REGION_SIZE_256KB);

  /* Region 6 setting: Memory with Normal type, not shareable, outer/inner write back */
  MPU->RBAR = ARM_MPU_RBAR(6, 0x20200000U);
  MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 1, 0, ARM_MPU_REGION_SIZE_1MB);

  /* Region 7 setting: Memory with Normal type, not shareable, outer/inner write back */
  MPU->RBAR = ARM_MPU_RBAR(7, 0x20300000U);
  MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 1, 0, ARM_MPU_REGION_SIZE_512KB);

  /* Region 8 setting: Memory with Normal type, not shareable, outer/inner write back. */
  MPU->RBAR = ARM_MPU_RBAR(8, 0x30000000U);
  MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_RO, 0, 0, 1, 1, 0, ARM_MPU_REGION_SIZE_16MB);

  /* Region 9 setting: Memory with Normal type, not shareable, outer/inner write back */
  MPU->RBAR = ARM_MPU_RBAR(9, 0x80000000U);
  MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 0, 0, 1, 1, 0, ARM_MPU_REGION_SIZE_64MB);

  uint32_t base_NCACHE_REGION = 0x83000000;            /* NCACHE_REGION */
  uint32_t top_NCACHE_REGION = 0x83000000 + 0x1000000; /* 16M bytes */
  uint32_t size = top_NCACHE_REGION - base_NCACHE_REGION;
  while ((size >> i) > 0x1U)
  {
    i++;
  }

  if (i != 0)
  {
    /* The MPU region size should be 2^N, 5<=N<=32, region base should be multiples of size. */
    assert(!(base_NCACHE_REGION % size));
    assert(size == (uint32_t)(1 << i));
    assert(i >= 5);

    /* Region 10 setting: Memory with Normal type, not shareable, non-cacheable */
    MPU->RBAR = ARM_MPU_RBAR(10, base_NCACHE_REGION);
    MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 1, 0, 0, 0, 0, i - 1);
  }

  /* Region 11 setting: Memory with Device type, not shareable, non-cacheable */
  MPU->RBAR = ARM_MPU_RBAR(11, 0x40000000);
  MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_16MB);

  /* Region 12 setting: Memory with Device type, not shareable, non-cacheable */
  MPU->RBAR = ARM_MPU_RBAR(12, 0x41000000);
  MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_2MB);

  /* Region 13 setting: Memory with Device type, not shareable, non-cacheable */
  MPU->RBAR = ARM_MPU_RBAR(13, 0x41400000);
  MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_1MB);

  /* Region 14 setting: Memory with Device type, not shareable, non-cacheable */
  MPU->RBAR = ARM_MPU_RBAR(14, 0x41800000);
  MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_2MB);

  /* Region 15 setting: Memory with Device type, not shareable, non-cacheable */
  MPU->RBAR = ARM_MPU_RBAR(15, 0x42000000);
  MPU->RASR = ARM_MPU_RASR(0, ARM_MPU_AP_FULL, 2, 0, 0, 0, 0, ARM_MPU_REGION_SIZE_1MB);

  /* Enable MPU */
  ARM_MPU_Enable(MPU_CTRL_PRIVDEFENA_Msk);

  /* Enable I cache and D cache */
  SCB_EnableDCache();

  SCB_EnableICache();
}

BSP_START_TEXT_SECTION void bsp_start_hook_0(void)
{
  // BOARD_ConfigMPU();

  if ((SCB->CCR & SCB_CCR_IC_Msk) == 0)
  {
    SCB_EnableICache();
  }

  // if ((SCB->CCR & SCB_CCR_DC_Msk) == 0)
  // {
  //   SCB_EnableDCache();
  // }

  SCB_DisableDCache();
  // ARM_MPU_Disable();

  _ARMV7M_MPU_Setup(ARMV7M_MPU_CTRL_DEFAULT, imxrt_config_mpu_region, imxrt_config_mpu_region_count);
}

BSP_START_TEXT_SECTION void bsp_start_hook_1(void)
{
  bsp_start_copy_sections_compact();
  //  SCB_CleanDCache();
  SCB_InvalidateICache();
  bsp_start_clear_bss();

  BOARD_BootClockRUN();
  BOARD_InitDEBUG_UARTPins();

#if IMXRT_IS_MIMXRT10xx
  /* Reduce frequency for I2C */
  CLOCK_SetDiv(kCLOCK_Lpi2cDiv, 5);

  /* Enable EDMA clock. We initialize the EDMA so we need the clock. */
  CLOCK_EnableClock(kCLOCK_Dma);
#endif
}

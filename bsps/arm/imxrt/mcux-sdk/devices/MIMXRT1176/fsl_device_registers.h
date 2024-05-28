/***
 * @Author: LiHeng
 * @Date: 2024-03-14 16:28:34
 * @LastEditors: LiHeng
 * @LastEditTime: 2024-03-14 17:30:00
 * @FilePath: /rt1170_rtems_source_1176/bsps/arm/imxrt/mcux-sdk/devices/MIMXRT1176/fsl_device_registers.h
 * @Description:
 * @
 * @Copyright (c) 2024 by LiHeng, All Rights Reserved.
 */
/*
 * Copyright 2014-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __FSL_DEVICE_REGISTERS_H__
#define __FSL_DEVICE_REGISTERS_H__

#ifdef __rtems__
#include <bspopts.h>
#endif /* __rtems__ */

/*
 * Include the cpu specific register header files.
 *
 * The CPU macro should be declared in the project or makefile.
 */
#if (defined(CPU_MIMXRT1176AVM8A_cm7) || defined(CPU_MIMXRT1176CVM8A_cm7) || defined(CPU_MIMXRT1176DVMAA_cm7))

#define MIMXRT1176_cm7_SERIES

/* CMSIS-style register definitions */
#include "MIMXRT1176_cm7.h"
/* CPU specific feature definitions */
#include "MIMXRT1176_cm7_features.h"

#elif (defined(CPU_MIMXRT1176AVM8A_cm4) || defined(CPU_MIMXRT1176CVM8A_cm4) || defined(CPU_MIMXRT1176DVMAA_cm4))

#define MIMXRT1176_cm4_SERIES

/* CMSIS-style register definitions */
#include "MIMXRT1176_cm4.h"
/* CPU specific feature definitions */
#include "MIMXRT1176_cm4_features.h"

#else
#error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/

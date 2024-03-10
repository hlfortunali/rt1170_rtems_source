/***
 * @Author: LiHeng
 * @Date: 2024-03-08 21:39:31
 * @LastEditors: LiHeng
 * @LastEditTime: 2024-03-10 20:54:13
 * @FilePath: /rt1170_rtems_source/bsps/arm/imxrt/boards/saltshaker/dcd.h
 * @Description:
 * @
 * @Copyright (c) 2024 by LiHeng, All Rights Reserved.
 */
/* SPDX-License-Identifier: BSD-2-Clause */

/*
 * Copyright (C) 2023 embedded brains GmbH & Co. KG
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

#ifndef BOARD_DCD_H
#define BOARD_DCD_H

#include <bsp/flash-headers.h>
#include <stdint.h>

/*! @name Driver version */
/*@{*/
/*! @brief XIP_BOARD driver version 2.0.1. */
#define FSL_XIP_BOARD_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*@}*/

/*************************************
 *  DCD Data
 *************************************/
#define DCD_TAG_HEADER (0xD2)
#define DCD_VERSION (0x41)
#define DCD_TAG_HEADER_SHIFT (24)
#define DCD_ARRAY_SIZE 1

#define XIP_BOOT_HEADER_ENABLE 1
#define XIP_BOOT_HEADER_DCD_ENABLE 1
#define dcd_data imxrt_dcd_data

#endif /* BOARD_DCD_H */

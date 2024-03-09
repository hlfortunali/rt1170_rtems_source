/*
 * @Author: LiHeng
 * @Date: 2024-03-08 21:39:31
 * @LastEditors: LiHeng
 * @LastEditTime: 2024-03-09 14:03:44
 * @FilePath: /rt1170_rtems_source/bsps/arm/imxrt/start/flash-ivt.c
 * @Description:
 *
 * Copyright (c) 2024 by LiHeng, All Rights Reserved.
 */
/* SPDX-License-Identifier: BSD-2-Clause */

/*
 * Copyright (C) 2020 embedded brains GmbH & Co. KG
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

#include <bsp/flash-headers.h>
#include <bspopts.h>

void _start(void);

const ivt imxrt_image_vector_table = {
    .hdr = IVT_HEADER,
    .entry = (uint32_t)_start - 1, /* remove thumb mode flag! */
    .dcd = (uint32_t)&imxrt_dcd_data,
    .boot_data = (uint32_t)&imxrt_boot_data,
    .self = (uint32_t)&imxrt_image_vector_table,
};

// const ivt imxrt_image_vector_table = {
//     IVT_HEADER,                  /* IVT Header */
//     IMAGE_ENTRY_ADDRESS,         /* Image Entry Function */
//     IVT_RSVD,                    /* Reserved = 0 */
//     (uint32_t)DCD_ADDRESS,       /* Address where DCD information is stored */
//     (uint32_t)BOOT_DATA_ADDRESS, /* Address where BOOT Data Structure is stored */
//     (uint32_t)IVT_ADDRESS,       /* Pointer to IVT Self (absolute address) */
//     (uint32_t)CSF_ADDRESS,       /* Address where CSF file is stored */
//     IVT_RSVD                     /* Reserved = 0 */
// };

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

#include <bsp/flash-headers.h>
#include <bspopts.h>

// const flexspi_nor_config_t imxrt_flexspi_config = {
//     .memConfig = {
//         .tag = FLEXSPI_CFG_BLK_TAG,
//         .version = FLEXSPI_CFG_BLK_VERSION,
//         .readSampleClkSrc = kFlexSPIReadSampleClk_LoopbackInternally,
//         .csHoldTime = 1u,         /* In serial Clk cycles. tSLCH = 3ns for the W25Q64JV. */
//         .csSetupTime = 1u,        /* In serial Clk cycles. tCHSH = 3ns for the W25Q64JV. */
//         .columnAddressWidth = 0u, /* W25Q64JV needs one linear address. */
//         .controllerMiscOption = 0u,
//         .deviceType = kFlexSpiDeviceType_SerialNOR,
//         .sflashPadType = kSerialFlash_4Pads,
//         .serialClkFreq = kFlexSpiSerialClk_100MHz, /* FIXME: 133MHz should be possible */
//         .sflashA1Size = IMXRT_MEMORY_FLASH_SIZE,
//         .dataValidTime = {0u, 0u}, /* Only relevant for Clock < 100MHz */
//         .busyOffset = 0,
//         .busyBitPolarity = 0,
//         .lookupTable = {
//             /* Read LUTs */
//             [4 * NOR_CMD_LUT_SEQ_IDX_READ + 0] = FLEXSPI_LUT_SEQ(
//                 CMD_SDR, FLEXSPI_1PAD, 0xEB,
//                 RADDR_SDR, FLEXSPI_4PAD, 24),
//             [4 * NOR_CMD_LUT_SEQ_IDX_READ + 1] = FLEXSPI_LUT_SEQ(
//                 DUMMY_SDR, FLEXSPI_4PAD, 6,
//                 READ_SDR, FLEXSPI_4PAD, 4),
//             /* Read Status LUTs */
//             [4 * NOR_CMD_LUT_SEQ_IDX_READSTATUS + 0] = FLEXSPI_LUT_SEQ(
//                 CMD_SDR, FLEXSPI_1PAD, 0x5,
//                 READ_SDR, FLEXSPI_1PAD, 4),
//             /* Write Enable LUTs */
//             [4 * NOR_CMD_LUT_SEQ_IDX_WRITEENABLE + 0] = 0,
//             /* Erase Sector LUTs */
//             [4 * NOR_CMD_LUT_SEQ_IDX_ERASESECTOR + 0] = 0,
//             /* Page Program LUTs */
//             [4 * NOR_CMD_LUT_SEQ_IDX_PAGEPROGRAM + 0] = 0,
//             /* Erase Chip LUTs */
//             [4 * NOR_CMD_LUT_SEQ_IDX_CHIPERASE + 0] = 0,
//         },
//     },
//     .pageSize = 256,
//     .sectorSize = 4096,
//     .blockSize = 32 * 1024,
//     .isUniformBlockSize = 1,
// };

const flexspi_nor_config_t imxrt_flexspi_config = {
    .memConfig =
        {
            .tag = FLEXSPI_CFG_BLK_TAG,
            .version = FLEXSPI_CFG_BLK_VERSION,
            .readSampleClkSrc = kFlexSPIReadSampleClk_LoopbackFromDqsPad,
            .csHoldTime = 3u,
            .csSetupTime = 3u,
            // Enable DDR mode, Wordaddassable, Safe configuration, Differential clock
            .controllerMiscOption = 0x10,
            .deviceType = kFlexSpiDeviceType_SerialNOR,
            .sflashPadType = kSerialFlash_4Pads,
            .serialClkFreq = kFlexSpiSerialClk_133MHz,
            .sflashA1Size = 16u * 1024u * 1024u,
            .lookupTable =
                {
                    // Read LUTs
                    [0] = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0xEB, RADDR_SDR, FLEXSPI_4PAD, 0x18),
                    [1] = FLEXSPI_LUT_SEQ(DUMMY_SDR, FLEXSPI_4PAD, 0x06, READ_SDR, FLEXSPI_4PAD, 0x04),

                    // Read Status LUTs
                    [4 * 1 + 0] = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0x05, READ_SDR, FLEXSPI_1PAD, 0x04),

                    // Write Enable LUTs
                    [4 * 3 + 0] = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0x06, STOP, FLEXSPI_1PAD, 0x0),

                    // Erase Sector LUTs
                    [4 * 5 + 0] = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0x20, RADDR_SDR, FLEXSPI_1PAD, 0x18),

                    // Erase Block LUTs
                    [4 * 8 + 0] = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0xD8, RADDR_SDR, FLEXSPI_1PAD, 0x18),

                    // Pape Program LUTs
                    [4 * 9 + 0] = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0x02, RADDR_SDR, FLEXSPI_1PAD, 0x18),
                    [4 * 9 + 1] = FLEXSPI_LUT_SEQ(WRITE_SDR, FLEXSPI_1PAD, 0x04, STOP, FLEXSPI_1PAD, 0x0),

                    // Erase Chip LUTs
                    [4 * 11 + 0] = FLEXSPI_LUT_SEQ(CMD_SDR, FLEXSPI_1PAD, 0x60, STOP, FLEXSPI_1PAD, 0x0),
                },
        },
    .pageSize = 256u,
    .sectorSize = 4u * 1024u,
    .ipcmdSerialClkFreq = 0x1,
    .blockSize = 64u * 1024u,
    .isUniformBlockSize = false,
};
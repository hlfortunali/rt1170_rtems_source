/* SPDX-License-Identifier: BSD-2-Clause */

/*
 * Copyright (c) 2012 embedded brains GmbH & Co. KG
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "tmacros.h"

#include <md5.h>

const char rtems_test_name[] = "MD5 1";

#ifndef MD5_BLOCK_SIZE
  #define MD5_BLOCK_SIZE 64
#endif

#ifndef MD5_DIGEST_LENGTH
  #define MD5_DIGEST_LENGTH 16
#endif

/* Test cases according to RFC 2202 */

static const uint8_t key_1[] = {
  0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b,
  0x0b, 0x0b, 0x0b
};

static const uint8_t data_1[] = {
  'H', 'i', ' ', 'T', 'h', 'e', 'r', 'e'
};

static const uint8_t digest_1[MD5_DIGEST_LENGTH] = {
  0x92, 0x94, 0x72, 0x7a, 0x36, 0x38, 0xbb, 0x1c, 0x13, 0xf4, 0x8e, 0xf8, 0x15,
  0x8b, 0xfc, 0x9d
};

static const uint8_t key_2[] = {
  'J', 'e', 'f', 'e'
};

static const uint8_t data_2[] = {
  'w', 'h', 'a', 't', ' ', 'd', 'o', ' ', 'y', 'a', ' ', 'w', 'a', 'n', 't',
  ' ', 'f', 'o', 'r', ' ', 'n', 'o', 't', 'h', 'i', 'n', 'g', '?'
};

static const uint8_t digest_2[MD5_DIGEST_LENGTH] = {
  0x75, 0x0c, 0x78, 0x3e, 0x6a, 0xb0, 0xb5, 0x03, 0xea, 0xa8, 0x6e, 0x31, 0x0a,
  0x5d, 0xb7, 0x38
};

static const uint8_t key_3[] = {
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa
};

static const uint8_t data_3[] = {
  0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd,
  0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd,
  0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd,
  0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd
};

static const uint8_t digest_3[MD5_DIGEST_LENGTH] = {
  0x56, 0xbe, 0x34, 0x52, 0x1d, 0x14, 0x4c, 0x88, 0xdb, 0xb8, 0xc7, 0x33, 0xf0,
  0xe8, 0xb3, 0xf6
};

static const uint8_t key_4[] = {
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d,
  0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19
};

static const uint8_t data_4[] = {
  0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd,
  0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd,
  0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd,
  0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd
};

static const uint8_t digest_4[MD5_DIGEST_LENGTH] = {
  0x69, 0x7e, 0xaf, 0x0a, 0xca, 0x3a, 0x3a, 0xea, 0x3a, 0x75, 0x16, 0x47, 0x46,
  0xff, 0xaa, 0x79
};

static const uint8_t key_5[] = {
  0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c,
  0x0c, 0x0c, 0x0c
};

static const uint8_t data_5[] = {
  'T', 'e', 's', 't', ' ', 'W', 'i', 't', 'h', ' ', 'T', 'r', 'u', 'n', 'c',
  'a', 't', 'i', 'o', 'n'
};

static const uint8_t digest_5[MD5_DIGEST_LENGTH] = {
  0x56, 0x46, 0x1e, 0xf2, 0x34, 0x2e, 0xdc, 0x00, 0xf9, 0xba, 0xb9, 0x95, 0x69,
  0x0e, 0xfd, 0x4c
};

static const uint8_t key_6[] = {
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa
};

static const uint8_t data_6[] = {
  'T', 'e', 's', 't', ' ', 'U', 's', 'i', 'n', 'g', ' ', 'L', 'a', 'r', 'g',
  'e', 'r', ' ', 'T', 'h', 'a', 'n', ' ', 'B', 'l', 'o', 'c', 'k', '-', 'S',
  'i', 'z', 'e', ' ', 'K', 'e', 'y', ' ', '-', ' ', 'H', 'a', 's', 'h', ' ',
  'K', 'e', 'y', ' ', 'F', 'i', 'r', 's', 't'
};

static const uint8_t digest_6[MD5_DIGEST_LENGTH] = {
  0x6b, 0x1a, 0xb7, 0xfe, 0x4b, 0xd7, 0xbf, 0x8f, 0x0b, 0x62, 0xe6, 0xce, 0x61,
  0xb9, 0xd0, 0xcd
};

static const uint8_t key_7[] = {
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
  0xaa, 0xaa
};

static const uint8_t data_7[] = {
  'T', 'e', 's', 't', ' ', 'U', 's', 'i', 'n', 'g', ' ', 'L', 'a', 'r', 'g',
  'e', 'r', ' ', 'T', 'h', 'a', 'n', ' ', 'B', 'l', 'o', 'c', 'k', '-', 'S',
  'i', 'z', 'e', ' ', 'K', 'e', 'y', ' ', 'a', 'n', 'd', ' ', 'L', 'a', 'r',
  'g', 'e', 'r', ' ', 'T', 'h', 'a', 'n', ' ', 'O', 'n', 'e', ' ', 'B', 'l',
  'o', 'c', 'k', '-', 'S', 'i', 'z', 'e', ' ', 'D', 'a', 't', 'a'
};

static const uint8_t digest_7[MD5_DIGEST_LENGTH] = {
  0x6f, 0x63, 0x0f, 0xad, 0x67, 0xcd, 0xa0, 0xee, 0x1f, 0xb1, 0xf5, 0x62, 0xdb,
  0x3a, 0xa5, 0x3e
};

static void test_md5(
 const uint8_t *key,
 size_t key_size,
 const uint8_t *data,
 size_t data_size,
 const uint8_t expected_digest[MD5_DIGEST_LENGTH]
)
{
  MD5_CTX inner_ctx;
  MD5_CTX outer_ctx;
  uint8_t inner_digest[MD5_DIGEST_LENGTH];
  uint8_t outer_digest[MD5_DIGEST_LENGTH];
  uint8_t key_buf[MD5_DIGEST_LENGTH];
  uint8_t buf[MD5_BLOCK_SIZE];
  size_t i;

  if (key_size > MD5_BLOCK_SIZE) {
    MD5_CTX tmp_ctx;

    MD5Init(&tmp_ctx);
    MD5Update(&tmp_ctx, key, key_size);
    MD5Final(&key_buf[0], &tmp_ctx);

    key = &key_buf[0];
    key_size = MD5_DIGEST_LENGTH;
  }

  /* Inner digest */

  MD5Init(&inner_ctx);

  /* Pad the key for the inner digest */
  for (i = 0; i < key_size; ++i) {
    buf[i] = key[i] ^ 0x36;
  }
  for (i = key_size; i < MD5_BLOCK_SIZE; ++i) {
    buf[i] = 0x36;
  }

  MD5Update(&inner_ctx, &buf[0], MD5_BLOCK_SIZE);
  MD5Update(&inner_ctx, data, data_size);

  MD5Final(&inner_digest[0], &inner_ctx);

  /* Outer digest */

  MD5Init(&outer_ctx);

  /* Pad the key for outer digest */
  for (i = 0; i < key_size; ++i) {
    buf[i] = key[i] ^ 0x5c;
  }
  for (i = key_size; i < MD5_BLOCK_SIZE; ++i) {
    buf[i] = 0x5c;
  }

  MD5Update(&outer_ctx, &buf[0], MD5_BLOCK_SIZE);
  MD5Update(&outer_ctx, &inner_digest[0], MD5_DIGEST_LENGTH);

  MD5Final(&outer_digest[0], &outer_ctx);

  rtems_test_assert(
    memcmp(&outer_digest[0], expected_digest, sizeof(outer_digest)) == 0
  );
}

static void test(void)
{
  test_md5(&key_1[0], sizeof(key_1), &data_1[0], sizeof(data_1), &digest_1[0]);
  test_md5(&key_2[0], sizeof(key_2), &data_2[0], sizeof(data_2), &digest_2[0]);
  test_md5(&key_3[0], sizeof(key_3), &data_3[0], sizeof(data_3), &digest_3[0]);
  test_md5(&key_4[0], sizeof(key_4), &data_4[0], sizeof(data_4), &digest_4[0]);
  test_md5(&key_5[0], sizeof(key_5), &data_5[0], sizeof(data_5), &digest_5[0]);
  test_md5(&key_6[0], sizeof(key_6), &data_6[0], sizeof(data_6), &digest_6[0]);
  test_md5(&key_7[0], sizeof(key_7), &data_7[0], sizeof(data_7), &digest_7[0]);
}

static void Init(rtems_task_argument arg)
{
  TEST_BEGIN();

  test();

  TEST_END();

  rtems_test_exit(0);
}

#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_SIMPLE_CONSOLE_DRIVER

#define CONFIGURE_MAXIMUM_TASKS 1

#define CONFIGURE_INITIAL_EXTENSIONS RTEMS_TEST_INITIAL_EXTENSION

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE

#define CONFIGURE_INIT

#include <rtems/confdefs.h>

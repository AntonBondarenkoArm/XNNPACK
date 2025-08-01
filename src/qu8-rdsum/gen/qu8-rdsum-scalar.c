// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/qu8-rdsum/scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/microparams.h"
#include "src/xnnpack/reduce.h"


void xnn_qu8_rdsum_ukernel_7p7x__scalar_c4(
    size_t rows,
    size_t channels,
    const uint8_t* input,
    size_t input_stride,
    const uint8_t* zero,
    uint32_t* output,
    const struct xnn_qs8_rsum_params* restrict params)
{
  assert(rows != 0);
  assert(channels != 0);
  assert(input != NULL);
  assert(output != NULL);

  size_t input_increment = 7 * input_stride;
  for (; channels >= 4; channels -= 4) {
    const uint8_t* i0 = input;
    const uint8_t* i1 = (const uint8_t*) ((uintptr_t) i0 + input_stride);
    const uint8_t* i2 = (const uint8_t*) ((uintptr_t) i1 + input_stride);
    const uint8_t* i3 = (const uint8_t*) ((uintptr_t) i2 + input_stride);
    const uint8_t* i4 = (const uint8_t*) ((uintptr_t) i3 + input_stride);
    const uint8_t* i5 = (const uint8_t*) ((uintptr_t) i4 + input_stride);
    const uint8_t* i6 = (const uint8_t*) ((uintptr_t) i5 + input_stride);
    uint32_t vacc0 = 0;
    uint32_t vacc1 = 0;
    uint32_t vacc2 = 0;
    uint32_t vacc3 = 0;

    for (int r = rows; r > 0; r -= 7) {
      if XNN_UNPREDICTABLE(r < 2) {
        i1 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 2) {
        i2 = zero;
      }
      if XNN_UNPREDICTABLE(r < 4) {
        i3 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 4) {
        i4 = zero;
      }
      if XNN_UNPREDICTABLE(r < 6) {
        i5 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 6) {
        i6 = zero;
      }
      vacc0 += (uint32_t) i0[0];
      vacc1 += (uint32_t) i0[1];
      vacc2 += (uint32_t) i0[2];
      vacc3 += (uint32_t) i0[3];
      vacc0 += (uint32_t) i1[0];
      vacc1 += (uint32_t) i1[1];
      vacc2 += (uint32_t) i1[2];
      vacc3 += (uint32_t) i1[3];
      vacc0 += (uint32_t) i2[0];
      vacc1 += (uint32_t) i2[1];
      vacc2 += (uint32_t) i2[2];
      vacc3 += (uint32_t) i2[3];
      vacc0 += (uint32_t) i3[0];
      vacc1 += (uint32_t) i3[1];
      vacc2 += (uint32_t) i3[2];
      vacc3 += (uint32_t) i3[3];
      vacc0 += (uint32_t) i4[0];
      vacc1 += (uint32_t) i4[1];
      vacc2 += (uint32_t) i4[2];
      vacc3 += (uint32_t) i4[3];
      vacc0 += (uint32_t) i5[0];
      vacc1 += (uint32_t) i5[1];
      vacc2 += (uint32_t) i5[2];
      vacc3 += (uint32_t) i5[3];
      vacc0 += (uint32_t) i6[0];
      vacc1 += (uint32_t) i6[1];
      vacc2 += (uint32_t) i6[2];
      vacc3 += (uint32_t) i6[3];
      i0 = (const uint8_t*) ((uintptr_t) i0 + input_increment);
      i1 = (const uint8_t*) ((uintptr_t) i1 + input_increment);
      i2 = (const uint8_t*) ((uintptr_t) i2 + input_increment);
      i3 = (const uint8_t*) ((uintptr_t) i3 + input_increment);
      i4 = (const uint8_t*) ((uintptr_t) i4 + input_increment);
      i5 = (const uint8_t*) ((uintptr_t) i5 + input_increment);
      i6 = (const uint8_t*) ((uintptr_t) i6 + input_increment);
    }

    *output++ += vacc0;
    *output++ += vacc1;
    *output++ += vacc2;
    *output++ += vacc3;

    input = (const uint8_t*) ((uintptr_t) input + 4);
  }
  if (channels != 0) {
    size_t input_increment = 7 * input_stride;
    const uint8_t* i0 = input;
    const uint8_t* i1 = (const uint8_t*) ((uintptr_t) i0 + input_stride);
    const uint8_t* i2 = (const uint8_t*) ((uintptr_t) i1 + input_stride);
    const uint8_t* i3 = (const uint8_t*) ((uintptr_t) i2 + input_stride);
    const uint8_t* i4 = (const uint8_t*) ((uintptr_t) i3 + input_stride);
    const uint8_t* i5 = (const uint8_t*) ((uintptr_t) i4 + input_stride);
    const uint8_t* i6 = (const uint8_t*) ((uintptr_t) i5 + input_stride);
    uint32_t vacc0 = 0;
    uint32_t vacc1 = 0;
    uint32_t vacc2 = 0;

    for (int r = rows; r > 0; r -= 7) {
      if XNN_UNPREDICTABLE(r < 2) {
        i1 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 2) {
        i2 = zero;
      }
      if XNN_UNPREDICTABLE(r < 4) {
        i3 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 4) {
        i4 = zero;
      }
      if XNN_UNPREDICTABLE(r < 6) {
        i5 = zero;
      }
      if XNN_UNPREDICTABLE(r <= 6) {
        i6 = zero;
      }
      vacc0 += (uint32_t) i0[0];
      vacc1 += (uint32_t) i0[1];
      vacc2 += (uint32_t) i0[2];
      vacc0 += (uint32_t) i1[0];
      vacc1 += (uint32_t) i1[1];
      vacc2 += (uint32_t) i1[2];
      vacc0 += (uint32_t) i2[0];
      vacc1 += (uint32_t) i2[1];
      vacc2 += (uint32_t) i2[2];
      vacc0 += (uint32_t) i3[0];
      vacc1 += (uint32_t) i3[1];
      vacc2 += (uint32_t) i3[2];
      vacc0 += (uint32_t) i4[0];
      vacc1 += (uint32_t) i4[1];
      vacc2 += (uint32_t) i4[2];
      vacc0 += (uint32_t) i5[0];
      vacc1 += (uint32_t) i5[1];
      vacc2 += (uint32_t) i5[2];
      vacc0 += (uint32_t) i6[0];
      vacc1 += (uint32_t) i6[1];
      vacc2 += (uint32_t) i6[2];
      i0 = (const uint8_t*) ((uintptr_t) i0 + input_increment);
      i1 = (const uint8_t*) ((uintptr_t) i1 + input_increment);
      i2 = (const uint8_t*) ((uintptr_t) i2 + input_increment);
      i3 = (const uint8_t*) ((uintptr_t) i3 + input_increment);
      i4 = (const uint8_t*) ((uintptr_t) i4 + input_increment);
      i5 = (const uint8_t*) ((uintptr_t) i5 + input_increment);
      i6 = (const uint8_t*) ((uintptr_t) i6 + input_increment);
    }

    if (channels & 2) {
      *output++ += vacc0;
      *output++ += vacc1;
      vacc0 = vacc2;
    }
    if (channels & 1) {
      *output += vacc0;
    }
  }
}

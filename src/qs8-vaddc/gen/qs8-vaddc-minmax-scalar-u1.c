// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/qs8-vaddc/scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/math.h"
#include "src/xnnpack/microparams.h"
#include "src/xnnpack/vbinary.h"


void xnn_qs8_vaddc_minmax_ukernel__scalar_u1(
    size_t batch,
    const int8_t* input_a,
    const int8_t* input_b,
    int8_t* output,
    const struct xnn_qs8_add_minmax_params* restrict params)
{
  assert(batch != 0);
  assert(batch % sizeof(int8_t) == 0);
  assert(input_a != NULL);
  assert(input_b != NULL);
  assert(output != NULL);

  const int32_t vbias = params->scalar.bias + (int32_t) *input_b * params->scalar.b_multiplier;
  const int32_t va_multiplier = params->scalar.a_multiplier;
  const uint32_t vshift = params->scalar.shift;
  const int32_t voutput_min = params->scalar.output_min;
  const int32_t voutput_max = params->scalar.output_max;
  const int32_t voutput_zero_point = params->scalar.output_zero_point;

  do {
    const int32_t va = *input_a++;
    const int32_t vacc = vbias + va * va_multiplier;

    int32_t vout = math_asr_s32(vacc, vshift);
    vout = vout + voutput_zero_point;
    vout = math_max_s32(vout, voutput_min);
    vout = math_min_s32(vout, voutput_max);
    *output++ = (int8_t) vout;

    batch -= sizeof(int8_t);
  } while (batch != 0);
}

// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/f32-vbinary/vop-scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/microparams.h"
#include "src/xnnpack/vbinary.h"


void xnn_f32_vprelu_ukernel__scalar_u4(
    size_t batch,
    const float* input_a,
    const float* input_b,
    float* output,
    const struct xnn_f32_default_params* restrict params)
{
  assert(batch != 0);
  assert(batch % sizeof(float) == 0);
  assert(input_a != NULL);
  assert(input_b != NULL);
  assert(output != NULL);

  for (; batch >= 4 * sizeof(float); batch -= 4 * sizeof(float)) {
    const float va0 = input_a[0];
    const float va1 = input_a[1];
    const float va2 = input_a[2];
    const float va3 = input_a[3];
    input_a += 4;

    const float vb0 = input_b[0];
    const float vb1 = input_b[1];
    const float vb2 = input_b[2];
    const float vb3 = input_b[3];
    input_b += 4;

    float vacc0 = va0 * vb0;
    float vacc1 = va1 * vb1;
    float vacc2 = va2 * vb2;
    float vacc3 = va3 * vb3;

    vacc0 = XNN_UNPREDICTABLE(va0 < 0.0f) ? va0 * vb0 : va0;
    vacc1 = XNN_UNPREDICTABLE(va1 < 0.0f) ? va1 * vb1 : va1;
    vacc2 = XNN_UNPREDICTABLE(va2 < 0.0f) ? va2 * vb2 : va2;
    vacc3 = XNN_UNPREDICTABLE(va3 < 0.0f) ? va3 * vb3 : va3;

    output[0] = vacc0;
    output[1] = vacc1;
    output[2] = vacc2;
    output[3] = vacc3;
    output += 4;
  }
  if XNN_UNLIKELY(batch != 0) {
    do {
      const float va = *input_a++;
      const float vb = *input_b++;
      float vacc = va * vb;
      vacc = XNN_UNPREDICTABLE(va < 0.0f) ? va * vb : va;
      *output++ = vacc;
      batch -= sizeof(float);
    } while (batch != 0);
  }
}

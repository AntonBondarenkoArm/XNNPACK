// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/f16-f32acc-rsum/avx512skx.c.in
//   Generator: tools/xngen
//
// Copyright 2024 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include <immintrin.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/intrinsics-polyfill.h"
#include "src/xnnpack/math.h"
#include "src/xnnpack/microparams.h"
#include "src/xnnpack/reduce.h"


void xnn_f16_f32acc_rsum_ukernel__avx512skx_u48_acc3(
    size_t batch,
    const xnn_float16* input,
    float* output,
    const struct xnn_f16_f32acc_scale_params* restrict params)
{
  assert(batch != 0);
  assert(batch % sizeof(uint16_t) == 0);
  assert(input != NULL);
  assert(output != NULL);

  const uint16_t* i = (const uint16_t*) input;
  __m512 vacc0 = _mm512_setzero_ps();
  __m512 vacc1 = _mm512_setzero_ps();
  __m512 vacc2 = _mm512_setzero_ps();
  for (; batch >= 48 * sizeof(uint16_t); batch -= 48 * sizeof(uint16_t)) {
    const __m512 vt0 = _mm512_cvtph_ps(_mm256_loadu_si256((const __m256i*) i));
    const __m512 vt1 = _mm512_cvtph_ps(_mm256_loadu_si256((const __m256i*) (i + 16)));
    const __m512 vt2 = _mm512_cvtph_ps(_mm256_loadu_si256((const __m256i*) (i + 32)));
    i += 48;

    vacc0 = _mm512_add_ps(vacc0, vt0);
    vacc1 = _mm512_add_ps(vacc1, vt1);
    vacc2 = _mm512_add_ps(vacc2, vt2);
  }
  if (batch >= 16 * sizeof(uint16_t)) {
    const __m512 vt = _mm512_cvtph_ps(_mm256_loadu_si256((const __m256i*) i));
    i += 16;
    batch -= 16 * sizeof(uint16_t);
    vacc0 = _mm512_add_ps(vacc0, vt);
  }
  if (batch >= 16 * sizeof(uint16_t)) {
    const __m512 vt = _mm512_cvtph_ps(_mm256_loadu_si256((const __m256i*) i));
    i += 16;
    batch -= 16 * sizeof(uint16_t);
    vacc1 = _mm512_add_ps(vacc1, vt);
  }
  vacc0 = _mm512_add_ps(vacc0, vacc2);
  vacc0 = _mm512_add_ps(vacc0, vacc1);
  if XNN_UNLIKELY(batch != 0) {
    assert(batch >= 1 * sizeof(uint16_t));
    assert(batch <= 15 * sizeof(uint16_t));

    // Prepare mask for valid elements (depends on batch).
    batch >>= XNN_LOG2_SIZEOF_HALF;
    const __mmask16 vmask = _cvtu32_mask16((uint32_t) ((UINT32_C(1) << batch) - UINT32_C(1)));

    const __m512 vt = _mm512_cvtph_ps(_mm256_maskz_loadu_epi16(vmask, i));

    vacc0 = _mm512_add_ps(vacc0, vt);
  }
  const __m256 vacc256 = _mm256_add_ps(_mm512_castps512_ps256(vacc0), _mm256_castpd_ps(_mm512_extractf64x4_pd(_mm512_castps_pd(vacc0), 1)));
  __m128 vacc = _mm_add_ps(_mm256_castps256_ps128(vacc256), _mm256_extractf128_ps(vacc256, 1));
  vacc = _mm_add_ps(vacc, _mm_movehl_ps(vacc, vacc));
  vacc = _mm_add_ss(vacc, _mm_movehdup_ps(vacc));
  vacc = _mm_mul_ss(vacc, _mm_load_ss(&params->scalar.scale));

  float vout = _mm_cvtss_f32(vacc);
  *output += vout;
}

// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/qs8-f32-vcvt/avx.c.in
//   Generator: tools/xngen
//
// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include <immintrin.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/microparams.h"
#include "src/xnnpack/unaligned.h"
#include "src/xnnpack/vcvt.h"


void xnn_qu8_f32_vcvt_ukernel__avx_u24(
    size_t batch,
    const uint8_t* input,
    float* output,
    const struct xnn_qu8_f32_cvt_params* restrict params) XNN_OOB_READS
{
  assert(batch != 0);
  assert(batch % sizeof(uint8_t) == 0);
  assert(input != NULL);
  assert(output != NULL);

  const __m128i vzero_point = _mm_set1_epi32(params->scalar.zero_point);
  const __m256 vscale = _mm256_set1_ps(params->scalar.scale);
  XNN_FORCE_REALIZATION(vzero_point);
  XNN_FORCE_REALIZATION(vscale);
  for (; batch >= 24 * sizeof(uint8_t); batch -= 24 * sizeof(uint8_t)) {
    __m128i vx0123 = _mm_cvtepu8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(input)));
    __m128i vx4567 = _mm_cvtepu8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(input + 4)));
    __m128i vx89AB = _mm_cvtepu8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(input + 8)));
    __m128i vxCDEF = _mm_cvtepu8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(input + 12)));
    __m128i vxGHIJ = _mm_cvtepu8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(input + 16)));
    __m128i vxKLMN = _mm_cvtepu8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(input + 20)));
    input += 24;

    vx0123 = _mm_sub_epi32(vx0123, vzero_point);
    vx4567 = _mm_sub_epi32(vx4567, vzero_point);
    vx89AB = _mm_sub_epi32(vx89AB, vzero_point);
    vxCDEF = _mm_sub_epi32(vxCDEF, vzero_point);
    vxGHIJ = _mm_sub_epi32(vxGHIJ, vzero_point);
    vxKLMN = _mm_sub_epi32(vxKLMN, vzero_point);

    const __m256i vx01234567 = _mm256_insertf128_si256(_mm256_castsi128_si256(vx0123), vx4567, 1);
    const __m256i vx89ABCDEF = _mm256_insertf128_si256(_mm256_castsi128_si256(vx89AB), vxCDEF, 1);
    const __m256i vxGHIJKLMN = _mm256_insertf128_si256(_mm256_castsi128_si256(vxGHIJ), vxKLMN, 1);

    __m256 vy01234567 = _mm256_cvtepi32_ps(vx01234567);
    __m256 vy89ABCDEF = _mm256_cvtepi32_ps(vx89ABCDEF);
    __m256 vyGHIJKLMN = _mm256_cvtepi32_ps(vxGHIJKLMN);

    vy01234567 = _mm256_mul_ps(vy01234567, vscale);
    vy89ABCDEF = _mm256_mul_ps(vy89ABCDEF, vscale);
    vyGHIJKLMN = _mm256_mul_ps(vyGHIJKLMN, vscale);

    _mm256_storeu_ps(output, vy01234567);
    _mm256_storeu_ps(output + 8, vy89ABCDEF);
    _mm256_storeu_ps(output + 16, vyGHIJKLMN);
    output += 24;
  }
  for (; batch >= 4 * sizeof(uint8_t); batch -= 4 * sizeof(uint8_t)) {
    __m128i vx = _mm_cvtepu8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(input)));
    vx = _mm_sub_epi32(vx, vzero_point);
    input += 4;

    __m128 vy = _mm_cvtepi32_ps(vx);
    vy = _mm_mul_ps(vy, _mm256_castps256_ps128(vscale));

    _mm_storeu_ps(output, vy);
    output += 4;
  }
  if XNN_UNLIKELY(batch != 0) {
    assert(batch >= 1 * sizeof(uint8_t));
    assert(batch <= 3 * sizeof(uint8_t));

    __m128i vx = _mm_cvtepu8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(input)));
    vx = _mm_sub_epi32(vx, vzero_point);

    __m128 vy = _mm_cvtepi32_ps(vx);
    vy = _mm_mul_ps(vy, _mm256_castps256_ps128(vscale));

    if (batch & (2 * sizeof(uint8_t))) {
      _mm_storel_pi((__m64*) output, vy);
      vy = _mm_movehl_ps(vy, vy);
      output += 2;
    }
    if (batch & (1 * sizeof(uint8_t))) {
      _mm_store_ss(output, vy);
    }
  }
}

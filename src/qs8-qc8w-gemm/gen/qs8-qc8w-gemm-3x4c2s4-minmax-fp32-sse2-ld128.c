// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/qs8-gemm/MRx4c2s4-sse.c.in
//   Generator: tools/xngen
//
// Copyright 2022 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include <emmintrin.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/microparams.h"
#include "src/xnnpack/gemm.h"
#include "src/xnnpack/math.h"
#include "src/xnnpack/unaligned.h"


void xnn_qs8_qc8w_gemm_minmax_fp32_ukernel_3x4c2s4__sse2_ld128(
    size_t mr,
    size_t nc,
    size_t kc,
    const int8_t* restrict a,
    size_t a_stride,
    const void* restrict w,
    int8_t* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    const union xnn_qs8_qc8w_conv_minmax_params* restrict params) XNN_OOB_READS
{
  assert(mr != 0);
  assert(mr <= 3);
  assert(nc != 0);
  assert(kc != 0);
  assert(kc % sizeof(int8_t) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  kc = round_up_po2(kc, 8 * sizeof(int8_t));
  const int8_t* a0 = a;
  int8_t* c0 = c;
  const int8_t* a1 = (const int8_t*) ((uintptr_t) a0 + a_stride);
  int8_t* c1 = (int8_t*) ((uintptr_t) c0 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 2) {
    a1 = a0;
    c1 = c0;
  }
  const int8_t* a2 = (const int8_t*) ((uintptr_t) a1 + a_stride);
  int8_t* c2 = (int8_t*) ((uintptr_t) c1 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 2) {
    a2 = a1;
    c2 = c1;
  }



  const __m128 voutput_max_less_zero_point = _mm_set1_ps((int32_t) params->fp32_scalar.output_max - (int32_t) params->fp32_scalar.output_zero_point);
  const __m128i voutput_zero_point = _mm_set1_epi16(params->fp32_scalar.output_zero_point);
  const __m128i voutput_min = _mm_set1_epi16(params->fp32_scalar.output_min);
  XNN_FORCE_REALIZATION(voutput_max_less_zero_point);
  XNN_FORCE_REALIZATION(voutput_zero_point);
  XNN_FORCE_REALIZATION(voutput_min);

  do {
    __m128i vacc0x0123 = _mm_loadu_si128((const __m128i*) w);
    __m128i vacc1x0123 = vacc0x0123;
    __m128i vacc2x0123 = vacc0x0123;
    w = (const void*) ((const int32_t*) w + 4);

    size_t k = kc;
    do {
      const __m128i va0 = _mm_loadl_epi64((const __m128i*) a0);
      __m128i vxa0 = _mm_srai_epi16(_mm_unpacklo_epi8(va0, va0), 8);
      a0 += 8;
      const __m128i va1 = _mm_loadl_epi64((const __m128i*) a1);
      __m128i vxa1 = _mm_srai_epi16(_mm_unpacklo_epi8(va1, va1), 8);
      a1 += 8;
      const __m128i va2 = _mm_loadl_epi64((const __m128i*) a2);
      __m128i vxa2 = _mm_srai_epi16(_mm_unpacklo_epi8(va2, va2), 8);
      a2 += 8;

      const __m128i vb01 = _mm_loadu_si128((const __m128i*) w);
      const __m128i vsb01 = _mm_cmpgt_epi8(_mm_setzero_si128(), vb01);
      const __m128i vxb0 = _mm_unpacklo_epi8(vb01, vsb01);
      const __m128i vxb1 = _mm_unpackhi_epi8(vb01, vsb01);

      vacc0x0123 = _mm_add_epi32(vacc0x0123, _mm_madd_epi16(vxa0, vxb0));
      vxa0 = _mm_shuffle_epi32(vxa0, _MM_SHUFFLE(0, 3, 2, 1));
      vacc1x0123 = _mm_add_epi32(vacc1x0123, _mm_madd_epi16(vxa1, vxb0));
      vxa1 = _mm_shuffle_epi32(vxa1, _MM_SHUFFLE(0, 3, 2, 1));
      vacc2x0123 = _mm_add_epi32(vacc2x0123, _mm_madd_epi16(vxa2, vxb0));
      vxa2 = _mm_shuffle_epi32(vxa2, _MM_SHUFFLE(0, 3, 2, 1));

      vacc0x0123 = _mm_add_epi32(vacc0x0123, _mm_madd_epi16(vxa0, vxb1));
      vxa0 = _mm_shuffle_epi32(vxa0, _MM_SHUFFLE(0, 3, 2, 1));
      vacc1x0123 = _mm_add_epi32(vacc1x0123, _mm_madd_epi16(vxa1, vxb1));
      vxa1 = _mm_shuffle_epi32(vxa1, _MM_SHUFFLE(0, 3, 2, 1));
      vacc2x0123 = _mm_add_epi32(vacc2x0123, _mm_madd_epi16(vxa2, vxb1));
      vxa2 = _mm_shuffle_epi32(vxa2, _MM_SHUFFLE(0, 3, 2, 1));
      const __m128i vb23 = _mm_loadu_si128((const __m128i*) ((const int8_t*) w + 16));
      const __m128i vsb23 = _mm_cmpgt_epi8(_mm_setzero_si128(), vb23);
      const __m128i vxb2 = _mm_unpacklo_epi8(vb23, vsb23);
      const __m128i vxb3 = _mm_unpackhi_epi8(vb23, vsb23);

      vacc0x0123 = _mm_add_epi32(vacc0x0123, _mm_madd_epi16(vxa0, vxb2));
      vxa0 = _mm_shuffle_epi32(vxa0, _MM_SHUFFLE(0, 3, 2, 1));
      vacc1x0123 = _mm_add_epi32(vacc1x0123, _mm_madd_epi16(vxa1, vxb2));
      vxa1 = _mm_shuffle_epi32(vxa1, _MM_SHUFFLE(0, 3, 2, 1));
      vacc2x0123 = _mm_add_epi32(vacc2x0123, _mm_madd_epi16(vxa2, vxb2));
      vxa2 = _mm_shuffle_epi32(vxa2, _MM_SHUFFLE(0, 3, 2, 1));

      vacc0x0123 = _mm_add_epi32(vacc0x0123, _mm_madd_epi16(vxa0, vxb3));
      vacc1x0123 = _mm_add_epi32(vacc1x0123, _mm_madd_epi16(vxa1, vxb3));
      vacc2x0123 = _mm_add_epi32(vacc2x0123, _mm_madd_epi16(vxa2, vxb3));

      w = (const void*) ((const int8_t*) w + 32);
      k -= 8 * sizeof(int8_t);
    } while (k != 0);

    __m128 vscaled0x0123 = _mm_cvtepi32_ps(vacc0x0123);
    __m128 vscaled1x0123 = _mm_cvtepi32_ps(vacc1x0123);
    __m128 vscaled2x0123 = _mm_cvtepi32_ps(vacc2x0123);

    const __m128 vscale0123 = _mm_loadu_ps((const float*) w);
    w = (const float*) w + 4;
    vscaled0x0123 = _mm_mul_ps(vscaled0x0123, vscale0123);
    vscaled1x0123 = _mm_mul_ps(vscaled1x0123, vscale0123);
    vscaled2x0123 = _mm_mul_ps(vscaled2x0123, vscale0123);

    vscaled0x0123 = _mm_min_ps(vscaled0x0123, voutput_max_less_zero_point);
    vscaled1x0123 = _mm_min_ps(vscaled1x0123, voutput_max_less_zero_point);
    vscaled2x0123 = _mm_min_ps(vscaled2x0123, voutput_max_less_zero_point);

    vacc0x0123 = _mm_cvtps_epi32(vscaled0x0123);
    vacc1x0123 = _mm_cvtps_epi32(vscaled1x0123);
    vacc2x0123 = _mm_cvtps_epi32(vscaled2x0123);

    __m128i vacc01x0123 = _mm_adds_epi16(_mm_packs_epi32(vacc0x0123, vacc1x0123), voutput_zero_point);
    __m128i vacc22x0123 = _mm_adds_epi16(_mm_packs_epi32(vacc2x0123, vacc2x0123), voutput_zero_point);

    vacc01x0123 = _mm_max_epi16(vacc01x0123, voutput_min);
    vacc22x0123 = _mm_max_epi16(vacc22x0123, voutput_min);

    __m128i vout = _mm_packs_epi16(vacc01x0123, vacc22x0123);


    if (nc >= 4) {
      unaligned_store_u32(c0, (uint32_t) _mm_cvtsi128_si32(vout));
      vout = _mm_shuffle_epi32(vout, _MM_SHUFFLE(0, 3, 2, 1));
      unaligned_store_u32(c1, (uint32_t) _mm_cvtsi128_si32(vout));
      vout = _mm_shuffle_epi32(vout, _MM_SHUFFLE(0, 3, 2, 1));
      unaligned_store_u32(c2, (uint32_t) _mm_cvtsi128_si32(vout));

      c0 = (int8_t*) ((uintptr_t) c0 + cn_stride);
      c1 = (int8_t*) ((uintptr_t) c1 + cn_stride);
      c2 = (int8_t*) ((uintptr_t) c2 + cn_stride);

      a0 = (const int8_t*) ((uintptr_t) a0 - kc);
      a1 = (const int8_t*) ((uintptr_t) a1 - kc);
      a2 = (const int8_t*) ((uintptr_t) a2 - kc);

      nc -= 4;
    } else {
      if (nc & 2) {
        unaligned_store_u16(c0, (uint16_t) _mm_extract_epi16(vout, 0));
        c0 += 2;
        unaligned_store_u16(c1, (uint16_t) _mm_extract_epi16(vout, 2));
        c1 += 2;
        unaligned_store_u16(c2, (uint16_t) _mm_extract_epi16(vout, 4));
        c2 += 2;
        vout = _mm_srli_epi32(vout, 16);
      }
      if (nc & 1) {
        *c0 = (int8_t) _mm_cvtsi128_si32(vout);
        *c1 = (int8_t) _mm_extract_epi16(vout, 2);
        *c2 = (int8_t) _mm_extract_epi16(vout, 4);
      }

      nc = 0;
    }
  } while (nc != 0);
}

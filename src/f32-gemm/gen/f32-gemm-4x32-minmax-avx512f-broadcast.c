// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/f32-gemm/avx512-broadcast.c.in
//   Generator: tools/xngen
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include <immintrin.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/gemm.h"
#include "src/xnnpack/intrinsics-polyfill.h"
#include "src/xnnpack/microparams.h"


void xnn_f32_gemm_minmax_ukernel_4x32__avx512f_broadcast(
    size_t mr,
    size_t nc,
    size_t kc,
    const float* restrict a,
    size_t a_stride,
    const float* restrict w,
    float* restrict c,
    size_t cm_stride,
    size_t cn_stride,
    const struct xnn_f32_minmax_params* restrict params)
{
  assert(mr != 0);
  assert(mr <= 4);
  assert(nc != 0);
  assert(kc != 0);
  assert(kc % sizeof(float) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);

  const float* a0 = a;
  float* c0 = c;
  const float* a1 = (const float*) ((uintptr_t) a0 + a_stride);
  float* c1 = (float*) ((uintptr_t) c0 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 2) {
    a1 = a0;
    c1 = c0;
  }
  const float* a2 = (const float*) ((uintptr_t) a1 + a_stride);
  float* c2 = (float*) ((uintptr_t) c1 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 2) {
    a2 = a1;
    c2 = c1;
  }
  const float* a3 = (const float*) ((uintptr_t) a2 + a_stride);
  float* c3 = (float*) ((uintptr_t) c2 + cm_stride);
  if XNN_UNPREDICTABLE(mr != 4) {
    a3 = a2;
    c3 = c2;
  }
  do {
    __m512 vacc0x0 = _mm512_load_ps(w);
    __m512 vacc0x1 = _mm512_load_ps(w + 16);
    __m512 vacc1x0 = vacc0x0;
    __m512 vacc1x1 = vacc0x1;
    __m512 vacc2x0 = vacc0x0;
    __m512 vacc2x1 = vacc0x1;
    __m512 vacc3x0 = vacc0x0;
    __m512 vacc3x1 = vacc0x1;
    w += 32;

    size_t k = kc;
    do {
      const __m512 vb0 = _mm512_load_ps(w);
      const __m512 vb1 = _mm512_loadu_ps(w + 16);
      w += 32;

      const __m512 va0 = _mm512_set1_ps(*a0);
      vacc0x0 = _mm512_fmadd_ps(va0, vb0, vacc0x0);
      vacc0x1 = _mm512_fmadd_ps(va0, vb1, vacc0x1);
      const __m512 va1 = _mm512_set1_ps(*a1);
      vacc1x0 = _mm512_fmadd_ps(va1, vb0, vacc1x0);
      vacc1x1 = _mm512_fmadd_ps(va1, vb1, vacc1x1);
      const __m512 va2 = _mm512_set1_ps(*a2);
      vacc2x0 = _mm512_fmadd_ps(va2, vb0, vacc2x0);
      vacc2x1 = _mm512_fmadd_ps(va2, vb1, vacc2x1);
      const __m512 va3 = _mm512_set1_ps(*a3);
      vacc3x0 = _mm512_fmadd_ps(va3, vb0, vacc3x0);
      vacc3x1 = _mm512_fmadd_ps(va3, vb1, vacc3x1);

      a0 += 1;
      a1 += 1;
      a2 += 1;
      a3 += 1;

      k -= sizeof(float);
    } while (k != 0);

    const __m512 vmin = _mm512_set1_ps(params->scalar.min);
    vacc0x0 = _mm512_max_ps(vmin, vacc0x0);
    vacc1x0 = _mm512_max_ps(vmin, vacc1x0);
    vacc2x0 = _mm512_max_ps(vmin, vacc2x0);
    vacc3x0 = _mm512_max_ps(vmin, vacc3x0);
    vacc0x1 = _mm512_max_ps(vmin, vacc0x1);
    vacc1x1 = _mm512_max_ps(vmin, vacc1x1);
    vacc2x1 = _mm512_max_ps(vmin, vacc2x1);
    vacc3x1 = _mm512_max_ps(vmin, vacc3x1);

    const __m512 vmax = _mm512_set1_ps(params->scalar.max);
    vacc0x0 = _mm512_min_ps(vmax, vacc0x0);
    vacc1x0 = _mm512_min_ps(vmax, vacc1x0);
    vacc2x0 = _mm512_min_ps(vmax, vacc2x0);
    vacc3x0 = _mm512_min_ps(vmax, vacc3x0);
    vacc0x1 = _mm512_min_ps(vmax, vacc0x1);
    vacc1x1 = _mm512_min_ps(vmax, vacc1x1);
    vacc2x1 = _mm512_min_ps(vmax, vacc2x1);
    vacc3x1 = _mm512_min_ps(vmax, vacc3x1);

    if XNN_LIKELY(nc >= 32) {
      _mm512_storeu_ps(c0, vacc0x0);
      _mm512_storeu_ps(c0 + 16, vacc0x1);
      c0 = (float*) ((uintptr_t) c0 + cn_stride);
      _mm512_storeu_ps(c1, vacc1x0);
      _mm512_storeu_ps(c1 + 16, vacc1x1);
      c1 = (float*) ((uintptr_t) c1 + cn_stride);
      _mm512_storeu_ps(c2, vacc2x0);
      _mm512_storeu_ps(c2 + 16, vacc2x1);
      c2 = (float*) ((uintptr_t) c2 + cn_stride);
      _mm512_storeu_ps(c3, vacc3x0);
      _mm512_storeu_ps(c3 + 16, vacc3x1);
      c3 = (float*) ((uintptr_t) c3 + cn_stride);

      a0 = (const float*) ((uintptr_t) a0 - kc);
      a1 = (const float*) ((uintptr_t) a1 - kc);
      a2 = (const float*) ((uintptr_t) a2 - kc);
      a3 = (const float*) ((uintptr_t) a3 - kc);

      nc -= 32;
    } else {
      // NC remainder (1..31)
      assert(nc >= 1);
      assert(nc <= 31);
      // Prepare mask for valid 32-bit elements (depends on nc).
      const __mmask16 vmask0 = _cvtu32_mask16((uint32_t) (((UINT64_C(1) << nc) - 1) >> 0));
      const __mmask16 vmask1 = _cvtu32_mask16((uint32_t) (((UINT64_C(1) << nc) - 1) >> 16));

      _mm512_mask_storeu_ps(c0 + 0, vmask0, vacc0x0);
      _mm512_mask_storeu_ps(c0 + 16, vmask1, vacc0x1);
      _mm512_mask_storeu_ps(c1 + 0, vmask0, vacc1x0);
      _mm512_mask_storeu_ps(c1 + 16, vmask1, vacc1x1);
      _mm512_mask_storeu_ps(c2 + 0, vmask0, vacc2x0);
      _mm512_mask_storeu_ps(c2 + 16, vmask1, vacc2x1);
      _mm512_mask_storeu_ps(c3 + 0, vmask0, vacc3x0);
      _mm512_mask_storeu_ps(c3 + 16, vmask1, vacc3x1);
      nc = 0;
    }
  } while (nc != 0);
}

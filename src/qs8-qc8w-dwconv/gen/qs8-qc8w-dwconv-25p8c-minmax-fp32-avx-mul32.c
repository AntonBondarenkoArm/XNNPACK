// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/qs8-dwconv/unipass-sse-mul32.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include <immintrin.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/dwconv.h"
#include "src/xnnpack/intrinsics-polyfill.h"
#include "src/xnnpack/microparams.h"
#include "src/xnnpack/unaligned.h"


void xnn_qs8_qc8w_dwconv_minmax_fp32_ukernel_25p8c__avx_mul32(
    size_t channels,
    size_t output_width,
    const int8_t** input,
    const void* weights,
    int8_t* output,
    intptr_t input_stride,
    size_t output_increment,
    size_t input_offset,
    size_t input_pixel_stride,
    const int8_t* zero,
    const union xnn_qs8_qc8w_conv_minmax_params* restrict params) XNN_OOB_READS
{
  assert(channels != 0);
  assert(output_width != 0);


  const __m128 voutput_max_less_zero_point = _mm_set1_ps((int32_t) params->fp32_scalar.output_max - (int32_t) params->fp32_scalar.output_zero_point);
  const __m128i voutput_zero_point = _mm_set1_epi16(params->fp32_scalar.output_zero_point);
  const __m128i voutput_min = _mm_set1_epi8(params->fp32_scalar.output_min);
  XNN_FORCE_REALIZATION(voutput_max_less_zero_point);
  XNN_FORCE_REALIZATION(voutput_zero_point);
  XNN_FORCE_REALIZATION(voutput_min);

  do {
    const int8_t* i0 = input[0];
    assert(i0 != NULL);
    if XNN_UNPREDICTABLE(i0 != zero) {
      i0 = (const int8_t*) ((uintptr_t) i0 + input_offset);
    }
    const int8_t* i1 = input[1];
    assert(i1 != NULL);
    if XNN_UNPREDICTABLE(i1 != zero) {
      i1 = (const int8_t*) ((uintptr_t) i1 + input_offset);
    }
    const int8_t* i2 = input[2];
    assert(i2 != NULL);
    if XNN_UNPREDICTABLE(i2 != zero) {
      i2 = (const int8_t*) ((uintptr_t) i2 + input_offset);
    }
    const int8_t* i3 = input[3];
    assert(i3 != NULL);
    if XNN_UNPREDICTABLE(i3 != zero) {
      i3 = (const int8_t*) ((uintptr_t) i3 + input_offset);
    }
    const int8_t* i4 = input[4];
    assert(i4 != NULL);
    if XNN_UNPREDICTABLE(i4 != zero) {
      i4 = (const int8_t*) ((uintptr_t) i4 + input_offset);
    }
    const int8_t* i5 = input[5];
    assert(i5 != NULL);
    if XNN_UNPREDICTABLE(i5 != zero) {
      i5 = (const int8_t*) ((uintptr_t) i5 + input_offset);
    }
    const int8_t* i6 = input[6];
    assert(i6 != NULL);
    if XNN_UNPREDICTABLE(i6 != zero) {
      i6 = (const int8_t*) ((uintptr_t) i6 + input_offset);
    }
    const int8_t* i7 = input[7];
    assert(i7 != NULL);
    if XNN_UNPREDICTABLE(i7 != zero) {
      i7 = (const int8_t*) ((uintptr_t) i7 + input_offset);
    }
    const int8_t* i8 = input[8];
    assert(i8 != NULL);
    if XNN_UNPREDICTABLE(i8 != zero) {
      i8 = (const int8_t*) ((uintptr_t) i8 + input_offset);
    }
    const int8_t* i9 = input[9];
    assert(i9 != NULL);
    if XNN_UNPREDICTABLE(i9 != zero) {
      i9 = (const int8_t*) ((uintptr_t) i9 + input_offset);
    }
    const int8_t* i10 = input[10];
    assert(i10 != NULL);
    if XNN_UNPREDICTABLE(i10 != zero) {
      i10 = (const int8_t*) ((uintptr_t) i10 + input_offset);
    }
    const int8_t* i11 = input[11];
    assert(i11 != NULL);
    if XNN_UNPREDICTABLE(i11 != zero) {
      i11 = (const int8_t*) ((uintptr_t) i11 + input_offset);
    }
    const int8_t* i12 = input[12];
    assert(i12 != NULL);
    if XNN_UNPREDICTABLE(i12 != zero) {
      i12 = (const int8_t*) ((uintptr_t) i12 + input_offset);
    }
    const int8_t* i13 = input[13];
    assert(i13 != NULL);
    if XNN_UNPREDICTABLE(i13 != zero) {
      i13 = (const int8_t*) ((uintptr_t) i13 + input_offset);
    }
    const int8_t* i14 = input[14];
    assert(i14 != NULL);
    if XNN_UNPREDICTABLE(i14 != zero) {
      i14 = (const int8_t*) ((uintptr_t) i14 + input_offset);
    }
    const int8_t* i15 = input[15];
    assert(i15 != NULL);
    if XNN_UNPREDICTABLE(i15 != zero) {
      i15 = (const int8_t*) ((uintptr_t) i15 + input_offset);
    }
    const int8_t* i16 = input[16];
    assert(i16 != NULL);
    if XNN_UNPREDICTABLE(i16 != zero) {
      i16 = (const int8_t*) ((uintptr_t) i16 + input_offset);
    }
    const int8_t* i17 = input[17];
    assert(i17 != NULL);
    if XNN_UNPREDICTABLE(i17 != zero) {
      i17 = (const int8_t*) ((uintptr_t) i17 + input_offset);
    }
    const int8_t* i18 = input[18];
    assert(i18 != NULL);
    if XNN_UNPREDICTABLE(i18 != zero) {
      i18 = (const int8_t*) ((uintptr_t) i18 + input_offset);
    }
    const int8_t* i19 = input[19];
    assert(i19 != NULL);
    if XNN_UNPREDICTABLE(i19 != zero) {
      i19 = (const int8_t*) ((uintptr_t) i19 + input_offset);
    }
    const int8_t* i20 = input[20];
    assert(i20 != NULL);
    if XNN_UNPREDICTABLE(i20 != zero) {
      i20 = (const int8_t*) ((uintptr_t) i20 + input_offset);
    }
    const int8_t* i21 = input[21];
    assert(i21 != NULL);
    if XNN_UNPREDICTABLE(i21 != zero) {
      i21 = (const int8_t*) ((uintptr_t) i21 + input_offset);
    }
    const int8_t* i22 = input[22];
    assert(i22 != NULL);
    if XNN_UNPREDICTABLE(i22 != zero) {
      i22 = (const int8_t*) ((uintptr_t) i22 + input_offset);
    }
    const int8_t* i23 = input[23];
    assert(i23 != NULL);
    if XNN_UNPREDICTABLE(i23 != zero) {
      i23 = (const int8_t*) ((uintptr_t) i23 + input_offset);
    }
    const int8_t* i24 = input[24];
    assert(i24 != NULL);
    if XNN_UNPREDICTABLE(i24 != zero) {
      i24 = (const int8_t*) ((uintptr_t) i24 + input_offset);
    }
    input = (const int8_t**) ((uintptr_t) input + input_stride);

    size_t c = channels;
    const void* w = weights;
    for (; c >= 8; c -= 8) {
      __m128i vacc0123 = _mm_loadu_si128((const __m128i*) w);
      __m128i vacc4567 = _mm_loadu_si128((const __m128i*) ((const int32_t*) w + 4));


      const __m128i vi0x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i0)));
      const __m128i vk0x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 0 * sizeof(int8_t)))));
      const __m128i vi0x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i0 + 4)));
      const __m128i vk0x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 4 * sizeof(int8_t)))));
      i0 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi0x0123, vk0x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi0x4567, vk0x4567));

      const __m128i vi1x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i1)));
      const __m128i vk1x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 8 * sizeof(int8_t)))));
      const __m128i vi1x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i1 + 4)));
      const __m128i vk1x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 12 * sizeof(int8_t)))));
      i1 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi1x0123, vk1x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi1x4567, vk1x4567));

      const __m128i vi2x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i2)));
      const __m128i vk2x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 16 * sizeof(int8_t)))));
      const __m128i vi2x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i2 + 4)));
      const __m128i vk2x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 20 * sizeof(int8_t)))));
      i2 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi2x0123, vk2x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi2x4567, vk2x4567));

      const __m128i vi3x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i3)));
      const __m128i vk3x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 24 * sizeof(int8_t)))));
      const __m128i vi3x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i3 + 4)));
      const __m128i vk3x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 28 * sizeof(int8_t)))));
      i3 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi3x0123, vk3x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi3x4567, vk3x4567));

      const __m128i vi4x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i4)));
      const __m128i vk4x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 32 * sizeof(int8_t)))));
      const __m128i vi4x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i4 + 4)));
      const __m128i vk4x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 36 * sizeof(int8_t)))));
      i4 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi4x0123, vk4x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi4x4567, vk4x4567));

      const __m128i vi5x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i5)));
      const __m128i vk5x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 40 * sizeof(int8_t)))));
      const __m128i vi5x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i5 + 4)));
      const __m128i vk5x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 44 * sizeof(int8_t)))));
      i5 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi5x0123, vk5x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi5x4567, vk5x4567));

      const __m128i vi6x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i6)));
      const __m128i vk6x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 48 * sizeof(int8_t)))));
      const __m128i vi6x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i6 + 4)));
      const __m128i vk6x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 52 * sizeof(int8_t)))));
      i6 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi6x0123, vk6x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi6x4567, vk6x4567));

      const __m128i vi7x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i7)));
      const __m128i vk7x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 56 * sizeof(int8_t)))));
      const __m128i vi7x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i7 + 4)));
      const __m128i vk7x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 60 * sizeof(int8_t)))));
      i7 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi7x0123, vk7x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi7x4567, vk7x4567));

      const __m128i vi8x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i8)));
      const __m128i vk8x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 64 * sizeof(int8_t)))));
      const __m128i vi8x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i8 + 4)));
      const __m128i vk8x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 68 * sizeof(int8_t)))));
      i8 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi8x0123, vk8x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi8x4567, vk8x4567));

      const __m128i vi9x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i9)));
      const __m128i vk9x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 72 * sizeof(int8_t)))));
      const __m128i vi9x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i9 + 4)));
      const __m128i vk9x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 76 * sizeof(int8_t)))));
      i9 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi9x0123, vk9x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi9x4567, vk9x4567));

      const __m128i vi10x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i10)));
      const __m128i vk10x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 80 * sizeof(int8_t)))));
      const __m128i vi10x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i10 + 4)));
      const __m128i vk10x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 84 * sizeof(int8_t)))));
      i10 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi10x0123, vk10x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi10x4567, vk10x4567));

      const __m128i vi11x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i11)));
      const __m128i vk11x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 88 * sizeof(int8_t)))));
      const __m128i vi11x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i11 + 4)));
      const __m128i vk11x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 92 * sizeof(int8_t)))));
      i11 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi11x0123, vk11x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi11x4567, vk11x4567));

      const __m128i vi12x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i12)));
      const __m128i vk12x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 96 * sizeof(int8_t)))));
      const __m128i vi12x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i12 + 4)));
      const __m128i vk12x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 100 * sizeof(int8_t)))));
      i12 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi12x0123, vk12x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi12x4567, vk12x4567));

      const __m128i vi13x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i13)));
      const __m128i vk13x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 104 * sizeof(int8_t)))));
      const __m128i vi13x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i13 + 4)));
      const __m128i vk13x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 108 * sizeof(int8_t)))));
      i13 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi13x0123, vk13x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi13x4567, vk13x4567));

      const __m128i vi14x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i14)));
      const __m128i vk14x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 112 * sizeof(int8_t)))));
      const __m128i vi14x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i14 + 4)));
      const __m128i vk14x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 116 * sizeof(int8_t)))));
      i14 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi14x0123, vk14x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi14x4567, vk14x4567));

      const __m128i vi15x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i15)));
      const __m128i vk15x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 120 * sizeof(int8_t)))));
      const __m128i vi15x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i15 + 4)));
      const __m128i vk15x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 124 * sizeof(int8_t)))));
      i15 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi15x0123, vk15x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi15x4567, vk15x4567));

      const __m128i vi16x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i16)));
      const __m128i vk16x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 128 * sizeof(int8_t)))));
      const __m128i vi16x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i16 + 4)));
      const __m128i vk16x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 132 * sizeof(int8_t)))));
      i16 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi16x0123, vk16x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi16x4567, vk16x4567));

      const __m128i vi17x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i17)));
      const __m128i vk17x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 136 * sizeof(int8_t)))));
      const __m128i vi17x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i17 + 4)));
      const __m128i vk17x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 140 * sizeof(int8_t)))));
      i17 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi17x0123, vk17x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi17x4567, vk17x4567));

      const __m128i vi18x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i18)));
      const __m128i vk18x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 144 * sizeof(int8_t)))));
      const __m128i vi18x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i18 + 4)));
      const __m128i vk18x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 148 * sizeof(int8_t)))));
      i18 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi18x0123, vk18x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi18x4567, vk18x4567));

      const __m128i vi19x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i19)));
      const __m128i vk19x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 152 * sizeof(int8_t)))));
      const __m128i vi19x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i19 + 4)));
      const __m128i vk19x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 156 * sizeof(int8_t)))));
      i19 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi19x0123, vk19x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi19x4567, vk19x4567));

      const __m128i vi20x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i20)));
      const __m128i vk20x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 160 * sizeof(int8_t)))));
      const __m128i vi20x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i20 + 4)));
      const __m128i vk20x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 164 * sizeof(int8_t)))));
      i20 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi20x0123, vk20x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi20x4567, vk20x4567));

      const __m128i vi21x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i21)));
      const __m128i vk21x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 168 * sizeof(int8_t)))));
      const __m128i vi21x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i21 + 4)));
      const __m128i vk21x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 172 * sizeof(int8_t)))));
      i21 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi21x0123, vk21x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi21x4567, vk21x4567));

      const __m128i vi22x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i22)));
      const __m128i vk22x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 176 * sizeof(int8_t)))));
      const __m128i vi22x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i22 + 4)));
      const __m128i vk22x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 180 * sizeof(int8_t)))));
      i22 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi22x0123, vk22x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi22x4567, vk22x4567));

      const __m128i vi23x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i23)));
      const __m128i vk23x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 184 * sizeof(int8_t)))));
      const __m128i vi23x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i23 + 4)));
      const __m128i vk23x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 188 * sizeof(int8_t)))));
      i23 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi23x0123, vk23x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi23x4567, vk23x4567));

      const __m128i vi24x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i24)));
      const __m128i vk24x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 192 * sizeof(int8_t)))));
      const __m128i vi24x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i24 + 4)));
      const __m128i vk24x4567 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) ((uintptr_t) w + 8 * sizeof(int32_t) + 196 * sizeof(int8_t)))));
      i24 += 8;

      vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi24x0123, vk24x0123));
      vacc4567 = _mm_add_epi32(vacc4567, _mm_mullo_epi32(vi24x4567, vk24x4567));

      w = (const void*) ((uintptr_t) w + 8 * sizeof(int32_t) + 200 * sizeof(int8_t));

      __m128 vscaled0123 = _mm_cvtepi32_ps(vacc0123);
      __m128 vscaled4567 = _mm_cvtepi32_ps(vacc4567);

      const __m128 vscale0123 = _mm_loadu_ps((const float*) w);
      const __m128 vscale4567 = _mm_loadu_ps((const float*) w + 4);
      w = (const void*) ((const float*) w + 8);
      vscaled0123 = _mm_mul_ps(vscaled0123, vscale0123);
      vscaled4567 = _mm_mul_ps(vscaled4567, vscale4567);

      vscaled0123 = _mm_min_ps(vscaled0123, voutput_max_less_zero_point);
      vscaled4567 = _mm_min_ps(vscaled4567, voutput_max_less_zero_point);

      vacc0123 = _mm_cvtps_epi32(vscaled0123);
      vacc4567 = _mm_cvtps_epi32(vscaled4567);

      __m128i vout01234567 = _mm_adds_epi16(_mm_packs_epi32(vacc0123, vacc4567), voutput_zero_point);

      __m128i vout0123456701234567 = _mm_packs_epi16(vout01234567, vout01234567);
      vout0123456701234567 = _mm_max_epi8(vout0123456701234567, voutput_min);

      _mm_storel_epi64((__m128i*) output, vout0123456701234567);
      output += 8;
    }
    if XNN_UNLIKELY(c != 0) {
      const int8_t* k = (const int8_t*) ((const int32_t*) w + 8);
      do {
        __m128i vacc0123 = _mm_loadu_si128((const __m128i*) w);

        const __m128i vi0x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i0)));
        const __m128i vk0x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) k)));
        i0 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi0x0123, vk0x0123));
        const __m128i vi1x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i1)));
        const __m128i vk1x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 8))));
        i1 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi1x0123, vk1x0123));
        const __m128i vi2x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i2)));
        const __m128i vk2x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 16))));
        i2 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi2x0123, vk2x0123));
        const __m128i vi3x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i3)));
        const __m128i vk3x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 24))));
        i3 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi3x0123, vk3x0123));
        const __m128i vi4x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i4)));
        const __m128i vk4x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 32))));
        i4 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi4x0123, vk4x0123));
        const __m128i vi5x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i5)));
        const __m128i vk5x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 40))));
        i5 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi5x0123, vk5x0123));
        const __m128i vi6x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i6)));
        const __m128i vk6x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 48))));
        i6 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi6x0123, vk6x0123));
        const __m128i vi7x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i7)));
        const __m128i vk7x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 56))));
        i7 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi7x0123, vk7x0123));
        const __m128i vi8x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i8)));
        const __m128i vk8x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 64))));
        i8 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi8x0123, vk8x0123));
        const __m128i vi9x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i9)));
        const __m128i vk9x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 72))));
        i9 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi9x0123, vk9x0123));
        const __m128i vi10x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i10)));
        const __m128i vk10x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 80))));
        i10 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi10x0123, vk10x0123));
        const __m128i vi11x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i11)));
        const __m128i vk11x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 88))));
        i11 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi11x0123, vk11x0123));
        const __m128i vi12x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i12)));
        const __m128i vk12x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 96))));
        i12 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi12x0123, vk12x0123));
        const __m128i vi13x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i13)));
        const __m128i vk13x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 104))));
        i13 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi13x0123, vk13x0123));
        const __m128i vi14x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i14)));
        const __m128i vk14x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 112))));
        i14 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi14x0123, vk14x0123));
        const __m128i vi15x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i15)));
        const __m128i vk15x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 120))));
        i15 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi15x0123, vk15x0123));
        const __m128i vi16x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i16)));
        const __m128i vk16x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 128))));
        i16 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi16x0123, vk16x0123));
        const __m128i vi17x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i17)));
        const __m128i vk17x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 136))));
        i17 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi17x0123, vk17x0123));
        const __m128i vi18x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i18)));
        const __m128i vk18x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 144))));
        i18 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi18x0123, vk18x0123));
        const __m128i vi19x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i19)));
        const __m128i vk19x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 152))));
        i19 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi19x0123, vk19x0123));
        const __m128i vi20x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i20)));
        const __m128i vk20x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 160))));
        i20 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi20x0123, vk20x0123));
        const __m128i vi21x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i21)));
        const __m128i vk21x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 168))));
        i21 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi21x0123, vk21x0123));
        const __m128i vi22x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i22)));
        const __m128i vk22x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 176))));
        i22 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi22x0123, vk22x0123));
        const __m128i vi23x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i23)));
        const __m128i vk23x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 184))));
        i23 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi23x0123, vk23x0123));
        const __m128i vi24x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128((int) unaligned_load_s32(i24)));
        const __m128i vk24x0123 = _mm_cvtepi8_epi32(_mm_cvtsi32_si128(*((const int*) (k + 192))));
        i24 += 4;

        vacc0123 = _mm_add_epi32(vacc0123, _mm_mullo_epi32(vi24x0123, vk24x0123));

        k += 4;

        __m128 vscaled0123 = _mm_cvtepi32_ps(vacc0123);
        const __m128 vscale0123 = _mm_loadu_ps((const float*) ((uintptr_t) w + 8 * sizeof(int32_t) + 200 * sizeof(int8_t)));
        vscaled0123 = _mm_mul_ps(vscaled0123, vscale0123);
        vscaled0123 = _mm_min_ps(vscaled0123, voutput_max_less_zero_point);
        vacc0123 = _mm_cvtps_epi32(vscaled0123);

        w = (const void*) ((const int32_t*) w + 4);

        __m128i vout0123 = _mm_adds_epi16(_mm_packs_epi32(vacc0123, vacc0123), voutput_zero_point);

        vout0123 = _mm_packs_epi16(vout0123, vout0123);
        vout0123 = _mm_max_epi8(vout0123, voutput_min);

        if XNN_LIKELY(c >= 4) {
          _mm_storeu_si32(output, vout0123);
          output += 4;
          c -= 4;
        } else {
          if (c & 2) {
            unaligned_store_u16(output, (uint16_t) _mm_extract_epi16(vout0123, 0));
            vout0123 = _mm_srli_epi32(vout0123, 16);
            output += 2;
          }
          if (c & 1) {
            *output = (int8_t) _mm_extract_epi8(vout0123, 0);
            output += 1;
          }
          c = 0;
        }
      } while (c != 0);
    }

    input_offset += input_pixel_stride;
    output = (int8_t*) ((uintptr_t) output + output_increment);
  } while (--output_width != 0);
}

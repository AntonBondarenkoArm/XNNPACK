// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/qs8-vmul/neon.c.in
//   Generator: tools/xngen
//
// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <arm_neon.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/microparams.h"
#include "src/xnnpack/vbinary.h"


void xnn_qs8_vmul_minmax_rndnu_ukernel__neon_ld64_u16(
    size_t batch,
    const int8_t* input_a,
    const int8_t* input_b,
    int8_t* output,
    const union xnn_qs8_mul_minmax_params* restrict params) XNN_OOB_READS
{
  assert(batch != 0);
  assert(batch % sizeof(int8_t) == 0);
  assert(input_a != NULL);
  assert(input_b != NULL);
  assert(output != NULL);

  const int8x8_t va_zero_point = vdup_n_s8(params->rndnu_neon.a_zero_point);
  const int8x8_t vb_zero_point = vdup_n_s8(params->rndnu_neon.b_zero_point);
  const int32x4_t vleft_pre_shift = vdupq_n_s32(params->rndnu_neon.left_pre_shift);
  const int32x4_t vmultiplier = vdupq_n_s32(params->rndnu_neon.multiplier);
  const int32x4_t vleft_post_shift = vdupq_n_s32(params->rndnu_neon.left_post_shift);
  const int16x8_t voutput_zero_point = vdupq_n_s16(params->rndnu_neon.output_zero_point);
  const int8x16_t voutput_min = vdupq_n_s8(params->rndnu_neon.output_min);
  const int8x16_t voutput_max = vdupq_n_s8(params->rndnu_neon.output_max);

  for (; batch >= 16 * sizeof(int8_t); batch -= 16 * sizeof(int8_t)) {
    const int8x8_t va01234567 = vld1_s8(input_a); input_a += 8;
    const int8x8_t vb01234567 = vld1_s8(input_b); input_b += 8;
    const int8x8_t va89ABCDEF = vld1_s8(input_a); input_a += 8;
    const int8x8_t vb89ABCDEF = vld1_s8(input_b); input_b += 8;

    const int16x8_t vxa01234567 = vsubl_s8(va01234567, va_zero_point);
    const int16x8_t vxb01234567 = vsubl_s8(vb01234567, vb_zero_point);
    const int16x8_t vxa89ABCDEF = vsubl_s8(va89ABCDEF, va_zero_point);
    const int16x8_t vxb89ABCDEF = vsubl_s8(vb89ABCDEF, vb_zero_point);

    int32x4_t vacc0123 = vmull_s16(vget_low_s16(vxa01234567), vget_low_s16(vxb01234567));
    int32x4_t vacc4567 = vmull_s16(vget_high_s16(vxa01234567), vget_high_s16(vxb01234567));
    int32x4_t vacc89AB = vmull_s16(vget_low_s16(vxa89ABCDEF), vget_low_s16(vxb89ABCDEF));
    int32x4_t vaccCDEF = vmull_s16(vget_high_s16(vxa89ABCDEF), vget_high_s16(vxb89ABCDEF));

    vacc0123 = vqshlq_s32(vacc0123, vleft_pre_shift);
    vacc4567 = vqshlq_s32(vacc4567, vleft_pre_shift);
    vacc89AB = vqshlq_s32(vacc89AB, vleft_pre_shift);
    vaccCDEF = vqshlq_s32(vaccCDEF, vleft_pre_shift);

    vacc0123 = vqdmulhq_s32(vacc0123, vmultiplier);
    vacc4567 = vqdmulhq_s32(vacc4567, vmultiplier);
    vacc89AB = vqdmulhq_s32(vacc89AB, vmultiplier);
    vaccCDEF = vqdmulhq_s32(vaccCDEF, vmultiplier);

    vacc0123 = vrshlq_s32(vacc0123, vleft_post_shift);
    vacc4567 = vrshlq_s32(vacc4567, vleft_post_shift);
    vacc89AB = vrshlq_s32(vacc89AB, vleft_post_shift);
    vaccCDEF = vrshlq_s32(vaccCDEF, vleft_post_shift);

    #if XNN_ARCH_ARM64
      int16x8_t vacc01234567 = vqmovn_high_s32(vqmovn_s32(vacc0123), vacc4567);
      int16x8_t vacc89ABCDEF = vqmovn_high_s32(vqmovn_s32(vacc89AB), vaccCDEF);
    #else
      int16x8_t vacc01234567 = vcombine_s16(vqmovn_s32(vacc0123), vqmovn_s32(vacc4567));
      int16x8_t vacc89ABCDEF = vcombine_s16(vqmovn_s32(vacc89AB), vqmovn_s32(vaccCDEF));
    #endif

    vacc01234567 = vqaddq_s16(vacc01234567, voutput_zero_point);
    vacc89ABCDEF = vqaddq_s16(vacc89ABCDEF, voutput_zero_point);

    #if XNN_ARCH_ARM64
      int8x16_t vout0123456789ABCDEF = vqmovn_high_s16(vqmovn_s16(vacc01234567), vacc89ABCDEF);
    #else
      int8x16_t vout0123456789ABCDEF = vcombine_s8(vqmovn_s16(vacc01234567), vqmovn_s16(vacc89ABCDEF));
    #endif

    vout0123456789ABCDEF = vmaxq_s8(vout0123456789ABCDEF, voutput_min);

    vout0123456789ABCDEF = vminq_s8(vout0123456789ABCDEF, voutput_max);

    vst1q_s8(output, vout0123456789ABCDEF); output += 16;
  }
  if XNN_UNLIKELY(batch != 0) {
    do {
      const int8x8_t va01234567 = vld1_s8(input_a); input_a += 8;
      const int8x8_t vb01234567 = vld1_s8(input_b); input_b += 8;

      const int16x8_t vxa01234567 = vsubl_s8(va01234567, va_zero_point);
      const int16x8_t vxb01234567 = vsubl_s8(vb01234567, vb_zero_point);

      int32x4_t vacc0123 = vmull_s16(vget_low_s16(vxa01234567), vget_low_s16(vxb01234567));
      int32x4_t vacc4567 = vmull_s16(vget_high_s16(vxa01234567), vget_high_s16(vxb01234567));

      vacc0123 = vqshlq_s32(vacc0123, vleft_pre_shift);
      vacc4567 = vqshlq_s32(vacc4567, vleft_pre_shift);

      vacc0123 = vqdmulhq_s32(vacc0123, vmultiplier);
      vacc4567 = vqdmulhq_s32(vacc4567, vmultiplier);

      vacc0123 = vrshlq_s32(vacc0123, vleft_post_shift);
      vacc4567 = vrshlq_s32(vacc4567, vleft_post_shift);

      #if XNN_ARCH_ARM64
        int16x8_t vacc01234567 = vqmovn_high_s32(vqmovn_s32(vacc0123), vacc4567);
      #else
        int16x8_t vacc01234567 = vcombine_s16(vqmovn_s32(vacc0123), vqmovn_s32(vacc4567));
      #endif

      vacc01234567 = vqaddq_s16(vacc01234567, voutput_zero_point);

      int8x8_t vout01234567 = vqmovn_s16(vacc01234567);

      vout01234567 = vmax_s8(vout01234567, vget_low_s8(voutput_min));
      vout01234567 = vmin_s8(vout01234567, vget_low_s8(voutput_max));
      if XNN_LIKELY(batch >= (8 * sizeof(int8_t))) {
        vst1_s8(output, vout01234567); output += 8;
        batch -= 8 * sizeof(int8_t);
      } else {
        if (batch & (4 * sizeof(int8_t))) {
          vst1_lane_u32((void*) output, vreinterpret_u32_s8(vout01234567), 0); output += 4;
          vout01234567 = vext_s8(vout01234567, vout01234567, 4);
        }
        if (batch & (2 * sizeof(int8_t))) {
          vst1_lane_u16((void*) output, vreinterpret_u16_s8(vout01234567), 0); output += 2;
          vout01234567 = vext_s8(vout01234567, vout01234567, 2);
        }
        if (batch & (1 * sizeof(int8_t))) {
          vst1_lane_s8(output, vout01234567, 0);
        }
        batch = 0;
      }
    } while (batch != 0);
  }
}

// clang-format off
// Auto-generated file. Do not edit!
//   Template: src/x16-packw/neon.c.in
//   Generator: tools/xngen
//
// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <arm_neon.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "src/xnnpack/common.h"
#include "src/xnnpack/packw.h"


void xnn_x16_packw_gemm_goi_ukernel_x16__neon_ld4lane_u8(
  size_t g,
  size_t nc,
  size_t kc,
  size_t nr,
  size_t kr,
  size_t sr,
  const uint16_t* weights,
  const uint16_t* bias,
  const void* scale,
  uint16_t* packed_weights,
  size_t extra_bytes,
  const void* params)
{
  assert(g != 0);
  assert(nc != 0);
  assert(kc != 0);
  assert(nr == 16);
  assert(kr == 1);
  assert(sr == 1);
  assert(weights != NULL);
  assert(packed_weights != NULL);

  uint16x8x4_t vtmp0123x01234567;
  vtmp0123x01234567.val[0] = vdupq_n_u16(0);
  vtmp0123x01234567.val[1] = vdupq_n_u16(0);
  vtmp0123x01234567.val[2] = vdupq_n_u16(0);
  vtmp0123x01234567.val[3] = vdupq_n_u16(0);
  uint16x8x4_t vtmp4567x01234567;
  vtmp4567x01234567.val[0] = vdupq_n_u16(0);
  vtmp4567x01234567.val[1] = vdupq_n_u16(0);
  vtmp4567x01234567.val[2] = vdupq_n_u16(0);
  vtmp4567x01234567.val[3] = vdupq_n_u16(0);
  uint16x8x4_t vtmp0123x89ABCDEF;
  vtmp0123x89ABCDEF.val[0] = vdupq_n_u16(0);
  vtmp0123x89ABCDEF.val[1] = vdupq_n_u16(0);
  vtmp0123x89ABCDEF.val[2] = vdupq_n_u16(0);
  vtmp0123x89ABCDEF.val[3] = vdupq_n_u16(0);
  uint16x8x4_t vtmp4567x89ABCDEF;
  vtmp4567x89ABCDEF.val[0] = vdupq_n_u16(0);
  vtmp4567x89ABCDEF.val[1] = vdupq_n_u16(0);
  vtmp4567x89ABCDEF.val[2] = vdupq_n_u16(0);
  vtmp4567x89ABCDEF.val[3] = vdupq_n_u16(0);

  do {
    // NC main loop multiple of 16
    const uint16_t* w0 = weights;
    size_t n = nc;

    for (; n >= 16; n -= 16) {
      if XNN_LIKELY(bias != NULL) {
        uint16x8_t vb0 = vld1q_u16(bias); bias += 8;
        uint16x8_t vb8 = vld1q_u16(bias); bias += 8;
        vst1q_u16(packed_weights, vb0); packed_weights += 8;
        vst1q_u16(packed_weights, vb8); packed_weights += 8;
      } else {
        const uint16x8_t vzero = vmovq_n_u16(0);
        vst1q_u16(packed_weights, vzero); packed_weights += 8;
        vst1q_u16(packed_weights, vzero); packed_weights += 8;
      }

      const uint16_t* w1 = w0 + kc;
      const uint16_t* w2 = w1 + kc;
      const uint16_t* w3 = w2 + kc;
      const uint16_t* w4 = w3 + kc;
      const uint16_t* w5 = w4 + kc;
      const uint16_t* w6 = w5 + kc;
      const uint16_t* w7 = w6 + kc;
      const uint16_t* w8 = w7 + kc;
      const uint16_t* w9 = w8 + kc;
      const uint16_t* w10 = w9 + kc;
      const uint16_t* w11 = w10 + kc;
      const uint16_t* w12 = w11 + kc;
      const uint16_t* w13 = w12 + kc;
      const uint16_t* w14 = w13 + kc;
      const uint16_t* w15 = w14 + kc;

      // KC main loop multiple of 8
      size_t k = kc;
      for (; k >= 8; k -= 8) {
        vtmp0123x01234567 = vld4q_lane_u16(w0, vtmp0123x01234567, 0); w0 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w1, vtmp0123x01234567, 1); w1 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w2, vtmp0123x01234567, 2); w2 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w3, vtmp0123x01234567, 3); w3 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w4, vtmp0123x01234567, 4); w4 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w5, vtmp0123x01234567, 5); w5 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w6, vtmp0123x01234567, 6); w6 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w7, vtmp0123x01234567, 7); w7 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w8, vtmp0123x89ABCDEF, 0); w8 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w9, vtmp0123x89ABCDEF, 1); w9 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w10, vtmp0123x89ABCDEF, 2); w10 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w11, vtmp0123x89ABCDEF, 3); w11 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w12, vtmp0123x89ABCDEF, 4); w12 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w13, vtmp0123x89ABCDEF, 5); w13 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w14, vtmp0123x89ABCDEF, 6); w14 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w15, vtmp0123x89ABCDEF, 7); w15 += 4;
        vtmp4567x01234567 = vld4q_lane_u16(w0, vtmp4567x01234567, 0); w0 += 4;
        vtmp4567x01234567 = vld4q_lane_u16(w1, vtmp4567x01234567, 1); w1 += 4;
        vtmp4567x01234567 = vld4q_lane_u16(w2, vtmp4567x01234567, 2); w2 += 4;
        vtmp4567x01234567 = vld4q_lane_u16(w3, vtmp4567x01234567, 3); w3 += 4;
        vtmp4567x01234567 = vld4q_lane_u16(w4, vtmp4567x01234567, 4); w4 += 4;
        vtmp4567x01234567 = vld4q_lane_u16(w5, vtmp4567x01234567, 5); w5 += 4;
        vtmp4567x01234567 = vld4q_lane_u16(w6, vtmp4567x01234567, 6); w6 += 4;
        vtmp4567x01234567 = vld4q_lane_u16(w7, vtmp4567x01234567, 7); w7 += 4;
        vtmp4567x89ABCDEF = vld4q_lane_u16(w8, vtmp4567x89ABCDEF, 0); w8 += 4;
        vtmp4567x89ABCDEF = vld4q_lane_u16(w9, vtmp4567x89ABCDEF, 1); w9 += 4;
        vtmp4567x89ABCDEF = vld4q_lane_u16(w10, vtmp4567x89ABCDEF, 2); w10 += 4;
        vtmp4567x89ABCDEF = vld4q_lane_u16(w11, vtmp4567x89ABCDEF, 3); w11 += 4;
        vtmp4567x89ABCDEF = vld4q_lane_u16(w12, vtmp4567x89ABCDEF, 4); w12 += 4;
        vtmp4567x89ABCDEF = vld4q_lane_u16(w13, vtmp4567x89ABCDEF, 5); w13 += 4;
        vtmp4567x89ABCDEF = vld4q_lane_u16(w14, vtmp4567x89ABCDEF, 6); w14 += 4;
        vtmp4567x89ABCDEF = vld4q_lane_u16(w15, vtmp4567x89ABCDEF, 7); w15 += 4;
        vst1q_u16(packed_weights, vtmp0123x01234567.val[0]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x89ABCDEF.val[0]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x01234567.val[1]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x89ABCDEF.val[1]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x01234567.val[2]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x89ABCDEF.val[2]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x01234567.val[3]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x89ABCDEF.val[3]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp4567x01234567.val[0]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp4567x89ABCDEF.val[0]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp4567x01234567.val[1]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp4567x89ABCDEF.val[1]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp4567x01234567.val[2]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp4567x89ABCDEF.val[2]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp4567x01234567.val[3]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp4567x89ABCDEF.val[3]); packed_weights += 8;
      }
      // KC remainder multiple of 4
      if (k >= 4) {
        vtmp0123x01234567 = vld4q_lane_u16(w0, vtmp0123x01234567, 0); w0 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w1, vtmp0123x01234567, 1); w1 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w2, vtmp0123x01234567, 2); w2 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w3, vtmp0123x01234567, 3); w3 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w4, vtmp0123x01234567, 4); w4 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w5, vtmp0123x01234567, 5); w5 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w6, vtmp0123x01234567, 6); w6 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w7, vtmp0123x01234567, 7); w7 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w8, vtmp0123x89ABCDEF, 0); w8 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w9, vtmp0123x89ABCDEF, 1); w9 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w10, vtmp0123x89ABCDEF, 2); w10 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w11, vtmp0123x89ABCDEF, 3); w11 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w12, vtmp0123x89ABCDEF, 4); w12 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w13, vtmp0123x89ABCDEF, 5); w13 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w14, vtmp0123x89ABCDEF, 6); w14 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w15, vtmp0123x89ABCDEF, 7); w15 += 4;
        vst1q_u16(packed_weights, vtmp0123x01234567.val[0]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x89ABCDEF.val[0]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x01234567.val[1]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x89ABCDEF.val[1]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x01234567.val[2]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x89ABCDEF.val[2]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x01234567.val[3]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x89ABCDEF.val[3]); packed_weights += 8;
        k -= 4;
      }

      // KC remainder of 1..3
      // Same as main loop but ld1, ld2 or ld3
      if XNN_UNLIKELY(k != 0) {
        assert(k >= 1);
        assert(k <= 3);
        switch (k) {
          // KC remainder of 16x1
          case 1:
          {
            uint16x8_t vtmp0x01234567 = vdupq_n_u16(0);
            uint16x8_t vtmp0x89ABCDEF = vdupq_n_u16(0);

            vtmp0x01234567 = vld1q_lane_u16(w0, vtmp0x01234567, 0); w0 += 1;
            vtmp0x01234567 = vld1q_lane_u16(w1, vtmp0x01234567, 1); w1 += 1;
            vtmp0x01234567 = vld1q_lane_u16(w2, vtmp0x01234567, 2); w2 += 1;
            vtmp0x01234567 = vld1q_lane_u16(w3, vtmp0x01234567, 3); w3 += 1;
            vtmp0x01234567 = vld1q_lane_u16(w4, vtmp0x01234567, 4); w4 += 1;
            vtmp0x01234567 = vld1q_lane_u16(w5, vtmp0x01234567, 5); w5 += 1;
            vtmp0x01234567 = vld1q_lane_u16(w6, vtmp0x01234567, 6); w6 += 1;
            vtmp0x01234567 = vld1q_lane_u16(w7, vtmp0x01234567, 7); w7 += 1;
            vtmp0x89ABCDEF = vld1q_lane_u16(w8, vtmp0x89ABCDEF, 0); w8 += 1;
            vtmp0x89ABCDEF = vld1q_lane_u16(w9, vtmp0x89ABCDEF, 1); w9 += 1;
            vtmp0x89ABCDEF = vld1q_lane_u16(w10, vtmp0x89ABCDEF, 2); w10 += 1;
            vtmp0x89ABCDEF = vld1q_lane_u16(w11, vtmp0x89ABCDEF, 3); w11 += 1;
            vtmp0x89ABCDEF = vld1q_lane_u16(w12, vtmp0x89ABCDEF, 4); w12 += 1;
            vtmp0x89ABCDEF = vld1q_lane_u16(w13, vtmp0x89ABCDEF, 5); w13 += 1;
            vtmp0x89ABCDEF = vld1q_lane_u16(w14, vtmp0x89ABCDEF, 6); w14 += 1;
            vtmp0x89ABCDEF = vld1q_lane_u16(w15, vtmp0x89ABCDEF, 7); w15 += 1;

            vst1q_u16(packed_weights, vtmp0x01234567); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp0x89ABCDEF); packed_weights += 8;
            break;
          }
          // KC remainder of 16x2
          case 2:
          {
            uint16x8x2_t vtmp01x01234567;
            vtmp01x01234567.val[0] = vdupq_n_u16(0);
            vtmp01x01234567.val[1] = vdupq_n_u16(0);
            uint16x8x2_t vtmp01x89ABCDEF;
            vtmp01x89ABCDEF.val[0] = vdupq_n_u16(0);
            vtmp01x89ABCDEF.val[1] = vdupq_n_u16(0);

            vtmp01x01234567 = vld2q_lane_u16(w0, vtmp01x01234567, 0); w0 += 2;
            vtmp01x01234567 = vld2q_lane_u16(w1, vtmp01x01234567, 1); w1 += 2;
            vtmp01x01234567 = vld2q_lane_u16(w2, vtmp01x01234567, 2); w2 += 2;
            vtmp01x01234567 = vld2q_lane_u16(w3, vtmp01x01234567, 3); w3 += 2;
            vtmp01x01234567 = vld2q_lane_u16(w4, vtmp01x01234567, 4); w4 += 2;
            vtmp01x01234567 = vld2q_lane_u16(w5, vtmp01x01234567, 5); w5 += 2;
            vtmp01x01234567 = vld2q_lane_u16(w6, vtmp01x01234567, 6); w6 += 2;
            vtmp01x01234567 = vld2q_lane_u16(w7, vtmp01x01234567, 7); w7 += 2;
            vtmp01x89ABCDEF = vld2q_lane_u16(w8, vtmp01x89ABCDEF, 0); w8 += 2;
            vtmp01x89ABCDEF = vld2q_lane_u16(w9, vtmp01x89ABCDEF, 1); w9 += 2;
            vtmp01x89ABCDEF = vld2q_lane_u16(w10, vtmp01x89ABCDEF, 2); w10 += 2;
            vtmp01x89ABCDEF = vld2q_lane_u16(w11, vtmp01x89ABCDEF, 3); w11 += 2;
            vtmp01x89ABCDEF = vld2q_lane_u16(w12, vtmp01x89ABCDEF, 4); w12 += 2;
            vtmp01x89ABCDEF = vld2q_lane_u16(w13, vtmp01x89ABCDEF, 5); w13 += 2;
            vtmp01x89ABCDEF = vld2q_lane_u16(w14, vtmp01x89ABCDEF, 6); w14 += 2;
            vtmp01x89ABCDEF = vld2q_lane_u16(w15, vtmp01x89ABCDEF, 7); w15 += 2;

            vst1q_u16(packed_weights, vtmp01x01234567.val[0]); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp01x89ABCDEF.val[0]); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp01x01234567.val[1]); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp01x89ABCDEF.val[1]); packed_weights += 8;
            break;
          }
          // KC remainder of 16x3
          case 3:
          {
            uint16x8x3_t vtmp012x01234567;
            vtmp012x01234567.val[0] = vdupq_n_u16(0);
            vtmp012x01234567.val[1] = vdupq_n_u16(0);
            vtmp012x01234567.val[2] = vdupq_n_u16(0);
            uint16x8x3_t vtmp012x89ABCDEF;
            vtmp012x89ABCDEF.val[0] = vdupq_n_u16(0);
            vtmp012x89ABCDEF.val[1] = vdupq_n_u16(0);
            vtmp012x89ABCDEF.val[2] = vdupq_n_u16(0);

            vtmp012x01234567 = vld3q_lane_u16(w0, vtmp012x01234567, 0); w0 += 3;
            vtmp012x01234567 = vld3q_lane_u16(w1, vtmp012x01234567, 1); w1 += 3;
            vtmp012x01234567 = vld3q_lane_u16(w2, vtmp012x01234567, 2); w2 += 3;
            vtmp012x01234567 = vld3q_lane_u16(w3, vtmp012x01234567, 3); w3 += 3;
            vtmp012x01234567 = vld3q_lane_u16(w4, vtmp012x01234567, 4); w4 += 3;
            vtmp012x01234567 = vld3q_lane_u16(w5, vtmp012x01234567, 5); w5 += 3;
            vtmp012x01234567 = vld3q_lane_u16(w6, vtmp012x01234567, 6); w6 += 3;
            vtmp012x01234567 = vld3q_lane_u16(w7, vtmp012x01234567, 7); w7 += 3;
            vtmp012x89ABCDEF = vld3q_lane_u16(w8, vtmp012x89ABCDEF, 0); w8 += 3;
            vtmp012x89ABCDEF = vld3q_lane_u16(w9, vtmp012x89ABCDEF, 1); w9 += 3;
            vtmp012x89ABCDEF = vld3q_lane_u16(w10, vtmp012x89ABCDEF, 2); w10 += 3;
            vtmp012x89ABCDEF = vld3q_lane_u16(w11, vtmp012x89ABCDEF, 3); w11 += 3;
            vtmp012x89ABCDEF = vld3q_lane_u16(w12, vtmp012x89ABCDEF, 4); w12 += 3;
            vtmp012x89ABCDEF = vld3q_lane_u16(w13, vtmp012x89ABCDEF, 5); w13 += 3;
            vtmp012x89ABCDEF = vld3q_lane_u16(w14, vtmp012x89ABCDEF, 6); w14 += 3;
            vtmp012x89ABCDEF = vld3q_lane_u16(w15, vtmp012x89ABCDEF, 7); w15 += 3;

            vst1q_u16(packed_weights, vtmp012x01234567.val[0]); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp012x89ABCDEF.val[0]); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp012x01234567.val[1]); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp012x89ABCDEF.val[1]); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp012x01234567.val[2]); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp012x89ABCDEF.val[2]); packed_weights += 8;
            break;
          }
          default:
            XNN_UNREACHABLE;
        }
      }
      packed_weights = (uint16_t*) ((uintptr_t) packed_weights + extra_bytes);
      w0 = w15;
    }

    // NC remainder (1..15)
    if XNN_UNLIKELY(n != 0) {
      assert(n >= 1);
      assert(n <= 15);
      if XNN_LIKELY(bias != NULL) {
        size_t nb = n;
        do {
          *packed_weights++  = *bias++;
        } while (--nb != 0);
        packed_weights += (16 - n);
      } else {
        const uint16x8_t vzero = vmovq_n_u16(0);
        vst1q_u16(packed_weights, vzero); packed_weights += 8;
        vst1q_u16(packed_weights, vzero); packed_weights += 8;
      }

      // NR remainder has less than 16 rows so last row is not loaded
      const uint16_t* w1 = w0 + kc;
      if XNN_UNPREDICTABLE(n < 2) {
        w1 = w0;
      }
      const uint16_t* w2 = w1 + kc;
      if XNN_UNPREDICTABLE(n <= 2) {
        w2 = w1;
      }
      const uint16_t* w3 = w2 + kc;
      if XNN_UNPREDICTABLE(n < 4) {
        w3 = w2;
      }
      const uint16_t* w4 = w3 + kc;
      if XNN_UNPREDICTABLE(n <= 4) {
        w4 = w3;
      }
      const uint16_t* w5 = w4 + kc;
      if XNN_UNPREDICTABLE(n < 6) {
        w5 = w4;
      }
      const uint16_t* w6 = w5 + kc;
      if XNN_UNPREDICTABLE(n <= 6) {
        w6 = w5;
      }
      const uint16_t* w7 = w6 + kc;
      if XNN_UNPREDICTABLE(n < 8) {
        w7 = w6;
      }
      const uint16_t* w8 = w7 + kc;
      if XNN_UNPREDICTABLE(n <= 8) {
        w8 = w7;
      }
      const uint16_t* w9 = w8 + kc;
      if XNN_UNPREDICTABLE(n < 10) {
        w9 = w8;
      }
      const uint16_t* w10 = w9 + kc;
      if XNN_UNPREDICTABLE(n <= 10) {
        w10 = w9;
      }
      const uint16_t* w11 = w10 + kc;
      if XNN_UNPREDICTABLE(n < 12) {
        w11 = w10;
      }
      const uint16_t* w12 = w11 + kc;
      if XNN_UNPREDICTABLE(n <= 12) {
        w12 = w11;
      }
      const uint16_t* w13 = w12 + kc;
      if XNN_UNPREDICTABLE(n < 14) {
        w13 = w12;
      }
      const uint16_t* w14 = w13 + kc;
      if XNN_UNPREDICTABLE(n <= 14) {
        w14 = w13;
      }

      // KC main loop multiple of 8
      size_t k = kc;
      for (; k >= 8; k -= 8) {
        vtmp0123x01234567 = vld4q_lane_u16(w0, vtmp0123x01234567, 0); w0 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w1, vtmp0123x01234567, 1); w1 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w2, vtmp0123x01234567, 2); w2 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w3, vtmp0123x01234567, 3); w3 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w4, vtmp0123x01234567, 4); w4 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w5, vtmp0123x01234567, 5); w5 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w6, vtmp0123x01234567, 6); w6 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w7, vtmp0123x01234567, 7); w7 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w8, vtmp0123x89ABCDEF, 0); w8 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w9, vtmp0123x89ABCDEF, 1); w9 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w10, vtmp0123x89ABCDEF, 2); w10 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w11, vtmp0123x89ABCDEF, 3); w11 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w12, vtmp0123x89ABCDEF, 4); w12 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w13, vtmp0123x89ABCDEF, 5); w13 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w14, vtmp0123x89ABCDEF, 6); w14 += 4;
        vtmp4567x01234567 = vld4q_lane_u16(w0, vtmp4567x01234567, 0); w0 += 4;
        vtmp4567x01234567 = vld4q_lane_u16(w1, vtmp4567x01234567, 1); w1 += 4;
        vtmp4567x01234567 = vld4q_lane_u16(w2, vtmp4567x01234567, 2); w2 += 4;
        vtmp4567x01234567 = vld4q_lane_u16(w3, vtmp4567x01234567, 3); w3 += 4;
        vtmp4567x01234567 = vld4q_lane_u16(w4, vtmp4567x01234567, 4); w4 += 4;
        vtmp4567x01234567 = vld4q_lane_u16(w5, vtmp4567x01234567, 5); w5 += 4;
        vtmp4567x01234567 = vld4q_lane_u16(w6, vtmp4567x01234567, 6); w6 += 4;
        vtmp4567x01234567 = vld4q_lane_u16(w7, vtmp4567x01234567, 7); w7 += 4;
        vtmp4567x89ABCDEF = vld4q_lane_u16(w8, vtmp4567x89ABCDEF, 0); w8 += 4;
        vtmp4567x89ABCDEF = vld4q_lane_u16(w9, vtmp4567x89ABCDEF, 1); w9 += 4;
        vtmp4567x89ABCDEF = vld4q_lane_u16(w10, vtmp4567x89ABCDEF, 2); w10 += 4;
        vtmp4567x89ABCDEF = vld4q_lane_u16(w11, vtmp4567x89ABCDEF, 3); w11 += 4;
        vtmp4567x89ABCDEF = vld4q_lane_u16(w12, vtmp4567x89ABCDEF, 4); w12 += 4;
        vtmp4567x89ABCDEF = vld4q_lane_u16(w13, vtmp4567x89ABCDEF, 5); w13 += 4;
        vtmp4567x89ABCDEF = vld4q_lane_u16(w14, vtmp4567x89ABCDEF, 6); w14 += 4;
        vst1q_u16(packed_weights, vtmp0123x01234567.val[0]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x89ABCDEF.val[0]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x01234567.val[1]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x89ABCDEF.val[1]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x01234567.val[2]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x89ABCDEF.val[2]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x01234567.val[3]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x89ABCDEF.val[3]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp4567x01234567.val[0]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp4567x89ABCDEF.val[0]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp4567x01234567.val[1]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp4567x89ABCDEF.val[1]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp4567x01234567.val[2]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp4567x89ABCDEF.val[2]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp4567x01234567.val[3]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp4567x89ABCDEF.val[3]); packed_weights += 8;
      }

      // KC remainder multiple of 4
      if (k >= 4) {
        vtmp0123x01234567 = vld4q_lane_u16(w0, vtmp0123x01234567, 0); w0 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w1, vtmp0123x01234567, 1); w1 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w2, vtmp0123x01234567, 2); w2 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w3, vtmp0123x01234567, 3); w3 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w4, vtmp0123x01234567, 4); w4 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w5, vtmp0123x01234567, 5); w5 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w6, vtmp0123x01234567, 6); w6 += 4;
        vtmp0123x01234567 = vld4q_lane_u16(w7, vtmp0123x01234567, 7); w7 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w8, vtmp0123x89ABCDEF, 0); w8 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w9, vtmp0123x89ABCDEF, 1); w9 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w10, vtmp0123x89ABCDEF, 2); w10 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w11, vtmp0123x89ABCDEF, 3); w11 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w12, vtmp0123x89ABCDEF, 4); w12 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w13, vtmp0123x89ABCDEF, 5); w13 += 4;
        vtmp0123x89ABCDEF = vld4q_lane_u16(w14, vtmp0123x89ABCDEF, 6); w14 += 4;
        vst1q_u16(packed_weights, vtmp0123x01234567.val[0]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x89ABCDEF.val[0]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x01234567.val[1]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x89ABCDEF.val[1]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x01234567.val[2]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x89ABCDEF.val[2]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x01234567.val[3]); packed_weights += 8;
        vst1q_u16(packed_weights, vtmp0123x89ABCDEF.val[3]); packed_weights += 8;
        k -= 4;
      }

      // KC remainder of 1..3
      // Same as main loop but ld1, ld2 or ld3
      if XNN_UNLIKELY(k != 0) {
        assert(k >= 1);
        assert(k <= 3);
        switch (k) {
          // KC remainder of 16x1
          case 1:
          {
            uint16x8_t vtmp0x01234567 = vdupq_n_u16(0);
            uint16x8_t vtmp0x89ABCDEF = vdupq_n_u16(0);

            vtmp0x01234567 = vld1q_lane_u16(w0, vtmp0x01234567, 0); w0 += 1;
            vtmp0x01234567 = vld1q_lane_u16(w1, vtmp0x01234567, 1); w1 += 1;
            vtmp0x01234567 = vld1q_lane_u16(w2, vtmp0x01234567, 2); w2 += 1;
            vtmp0x01234567 = vld1q_lane_u16(w3, vtmp0x01234567, 3); w3 += 1;
            vtmp0x01234567 = vld1q_lane_u16(w4, vtmp0x01234567, 4); w4 += 1;
            vtmp0x01234567 = vld1q_lane_u16(w5, vtmp0x01234567, 5); w5 += 1;
            vtmp0x01234567 = vld1q_lane_u16(w6, vtmp0x01234567, 6); w6 += 1;
            vtmp0x01234567 = vld1q_lane_u16(w7, vtmp0x01234567, 7); w7 += 1;
            vtmp0x89ABCDEF = vld1q_lane_u16(w8, vtmp0x89ABCDEF, 0); w8 += 1;
            vtmp0x89ABCDEF = vld1q_lane_u16(w9, vtmp0x89ABCDEF, 1); w9 += 1;
            vtmp0x89ABCDEF = vld1q_lane_u16(w10, vtmp0x89ABCDEF, 2); w10 += 1;
            vtmp0x89ABCDEF = vld1q_lane_u16(w11, vtmp0x89ABCDEF, 3); w11 += 1;
            vtmp0x89ABCDEF = vld1q_lane_u16(w12, vtmp0x89ABCDEF, 4); w12 += 1;
            vtmp0x89ABCDEF = vld1q_lane_u16(w13, vtmp0x89ABCDEF, 5); w13 += 1;
            vtmp0x89ABCDEF = vld1q_lane_u16(w14, vtmp0x89ABCDEF, 6); w14 += 1;

            vst1q_u16(packed_weights, vtmp0x01234567); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp0x89ABCDEF); packed_weights += 8;
            break;
          }
          // KC remainder of 16x2
          case 2:
          {
            uint16x8x2_t vtmp01x01234567;
            vtmp01x01234567.val[0] = vdupq_n_u16(0);
            vtmp01x01234567.val[1] = vdupq_n_u16(0);
            uint16x8x2_t vtmp01x89ABCDEF;
            vtmp01x89ABCDEF.val[0] = vdupq_n_u16(0);
            vtmp01x89ABCDEF.val[1] = vdupq_n_u16(0);

            vtmp01x01234567 = vld2q_lane_u16(w0, vtmp01x01234567, 0); w0 += 2;
            vtmp01x01234567 = vld2q_lane_u16(w1, vtmp01x01234567, 1); w1 += 2;
            vtmp01x01234567 = vld2q_lane_u16(w2, vtmp01x01234567, 2); w2 += 2;
            vtmp01x01234567 = vld2q_lane_u16(w3, vtmp01x01234567, 3); w3 += 2;
            vtmp01x01234567 = vld2q_lane_u16(w4, vtmp01x01234567, 4); w4 += 2;
            vtmp01x01234567 = vld2q_lane_u16(w5, vtmp01x01234567, 5); w5 += 2;
            vtmp01x01234567 = vld2q_lane_u16(w6, vtmp01x01234567, 6); w6 += 2;
            vtmp01x01234567 = vld2q_lane_u16(w7, vtmp01x01234567, 7); w7 += 2;
            vtmp01x89ABCDEF = vld2q_lane_u16(w8, vtmp01x89ABCDEF, 0); w8 += 2;
            vtmp01x89ABCDEF = vld2q_lane_u16(w9, vtmp01x89ABCDEF, 1); w9 += 2;
            vtmp01x89ABCDEF = vld2q_lane_u16(w10, vtmp01x89ABCDEF, 2); w10 += 2;
            vtmp01x89ABCDEF = vld2q_lane_u16(w11, vtmp01x89ABCDEF, 3); w11 += 2;
            vtmp01x89ABCDEF = vld2q_lane_u16(w12, vtmp01x89ABCDEF, 4); w12 += 2;
            vtmp01x89ABCDEF = vld2q_lane_u16(w13, vtmp01x89ABCDEF, 5); w13 += 2;
            vtmp01x89ABCDEF = vld2q_lane_u16(w14, vtmp01x89ABCDEF, 6); w14 += 2;

            vst1q_u16(packed_weights, vtmp01x01234567.val[0]); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp01x89ABCDEF.val[0]); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp01x01234567.val[1]); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp01x89ABCDEF.val[1]); packed_weights += 8;
            break;
          }
          // KC remainder of 16x3
          case 3:
          {
            uint16x8x3_t vtmp012x01234567;
            vtmp012x01234567.val[0] = vdupq_n_u16(0);
            vtmp012x01234567.val[1] = vdupq_n_u16(0);
            vtmp012x01234567.val[2] = vdupq_n_u16(0);
            uint16x8x3_t vtmp012x89ABCDEF;
            vtmp012x89ABCDEF.val[0] = vdupq_n_u16(0);
            vtmp012x89ABCDEF.val[1] = vdupq_n_u16(0);
            vtmp012x89ABCDEF.val[2] = vdupq_n_u16(0);

            vtmp012x01234567 = vld3q_lane_u16(w0, vtmp012x01234567, 0); w0 += 3;
            vtmp012x01234567 = vld3q_lane_u16(w1, vtmp012x01234567, 1); w1 += 3;
            vtmp012x01234567 = vld3q_lane_u16(w2, vtmp012x01234567, 2); w2 += 3;
            vtmp012x01234567 = vld3q_lane_u16(w3, vtmp012x01234567, 3); w3 += 3;
            vtmp012x01234567 = vld3q_lane_u16(w4, vtmp012x01234567, 4); w4 += 3;
            vtmp012x01234567 = vld3q_lane_u16(w5, vtmp012x01234567, 5); w5 += 3;
            vtmp012x01234567 = vld3q_lane_u16(w6, vtmp012x01234567, 6); w6 += 3;
            vtmp012x01234567 = vld3q_lane_u16(w7, vtmp012x01234567, 7); w7 += 3;
            vtmp012x89ABCDEF = vld3q_lane_u16(w8, vtmp012x89ABCDEF, 0); w8 += 3;
            vtmp012x89ABCDEF = vld3q_lane_u16(w9, vtmp012x89ABCDEF, 1); w9 += 3;
            vtmp012x89ABCDEF = vld3q_lane_u16(w10, vtmp012x89ABCDEF, 2); w10 += 3;
            vtmp012x89ABCDEF = vld3q_lane_u16(w11, vtmp012x89ABCDEF, 3); w11 += 3;
            vtmp012x89ABCDEF = vld3q_lane_u16(w12, vtmp012x89ABCDEF, 4); w12 += 3;
            vtmp012x89ABCDEF = vld3q_lane_u16(w13, vtmp012x89ABCDEF, 5); w13 += 3;
            vtmp012x89ABCDEF = vld3q_lane_u16(w14, vtmp012x89ABCDEF, 6); w14 += 3;

            vst1q_u16(packed_weights, vtmp012x01234567.val[0]); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp012x89ABCDEF.val[0]); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp012x01234567.val[1]); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp012x89ABCDEF.val[1]); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp012x01234567.val[2]); packed_weights += 8;
            vst1q_u16(packed_weights, vtmp012x89ABCDEF.val[2]); packed_weights += 8;
            break;
          }
          default:
            XNN_UNREACHABLE;
        }
      }
      packed_weights = (uint16_t*) ((uintptr_t) packed_weights + extra_bytes);
    }

    weights += nc * kc;
  } while (--g != 0);
}

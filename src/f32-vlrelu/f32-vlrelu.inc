// clang-format off
// Copyright 2023 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.


#if XNN_ARCH_ARM || XNN_ARCH_ARM64
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_vlrelu_ukernel__neon_u4, 4, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_arm_neon, xnn_f32_vlrelu_ukernel__neon_u8, 8, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_RISCV && XNN_ENABLE_RISCV_VECTOR
XNN_UKERNEL(xnn_arch_riscv_vector, xnn_f32_vlrelu_ukernel__rvv_u1v, 1, true, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_riscv_vector, xnn_f32_vlrelu_ukernel__rvv_u2v, 2, true, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_riscv_vector, xnn_f32_vlrelu_ukernel__rvv_u4v, 4, true, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_riscv_vector, xnn_f32_vlrelu_ukernel__rvv_u8v, 8, true, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
#endif  // XNN_ARCH_RISCV && XNN_ENABLE_RISCV_VECTOR

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
XNN_UKERNEL(xnn_arch_none, xnn_f32_vlrelu_ukernel__sse_u4, 4, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_none, xnn_f32_vlrelu_ukernel__sse_u8, 8, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_none, xnn_f32_vlrelu_ukernel__sse2_u4, 4, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_none, xnn_f32_vlrelu_ukernel__sse2_u8, 8, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_x86_sse4_1, xnn_f32_vlrelu_ukernel__sse41_u4, 4, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_x86_sse4_1, xnn_f32_vlrelu_ukernel__sse41_u8, 8, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_vlrelu_ukernel__avx_u8, 8, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx, xnn_f32_vlrelu_ukernel__avx_u16, 16, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ENABLE_AVX512F && (XNN_ARCH_X86 || XNN_ARCH_X86_64)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_vlrelu_ukernel__avx512f_u16, 16, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_x86_avx512f, xnn_f32_vlrelu_ukernel__avx512f_u32, 32, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
XNN_UKERNEL(xnn_arch_none, xnn_f32_vlrelu_ukernel__wasmsimd_iminmax_u4, 4, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_none, xnn_f32_vlrelu_ukernel__wasmsimd_iminmax_u8, 8, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_none, xnn_f32_vlrelu_ukernel__wasmsimd_laneselect_u4, 4, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_none, xnn_f32_vlrelu_ukernel__wasmsimd_laneselect_u8, 8, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD

#if XNN_ARCH_WASMRELAXEDSIMD
XNN_UKERNEL(xnn_arch_none, xnn_f32_vlrelu_ukernel__wasmrelaxedsimd_iminmax_u4, 4, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_none, xnn_f32_vlrelu_ukernel__wasmrelaxedsimd_iminmax_u8, 8, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_none, xnn_f32_vlrelu_ukernel__wasmrelaxedsimd_laneselect_u4, 4, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_none, xnn_f32_vlrelu_ukernel__wasmrelaxedsimd_laneselect_u8, 8, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
#endif  // XNN_ARCH_WASMRELAXEDSIMD

XNN_UKERNEL(xnn_arch_none, xnn_f32_vlrelu_ukernel__scalar_u1, 1, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_none, xnn_f32_vlrelu_ukernel__scalar_u2, 2, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)
XNN_UKERNEL(xnn_arch_none, xnn_f32_vlrelu_ukernel__scalar_u4, 4, false, float, struct xnn_f32_lrelu_params, xnn_init_f32_lrelu_scalar_params)

// This file is auto-generated. Do not edit!

//#include "precomp.hpp"
#include "opencl_kernels_stitching.hpp"

namespace cv
{
namespace ocl
{
namespace stitching
{

const struct ProgramEntry multibandblend={"multibandblend",
"#ifndef NL\n"
"#define NL\n"
"#endif\n"
"#define REF(x) x\n"
"#define __CAT(x, y) x##y\n"
"#define CAT(x, y) __CAT(x, y)\n"
"#define DECLARE_MAT_ARG(name) \\\n"
"__global uchar* restrict name ## Ptr, \\\n"
"int name ## StepBytes, \\\n"
"int name ## Offset, \\\n"
"int name ## Height, \\\n"
"int name ## Width NL\n"
"#define MAT_BYTE_OFFSET(name, x, y) mad24((y), name ## StepBytes, ((x)) * (int)(name ## _TSIZE) + name ## Offset)\n"
"#define MAT_RELATIVE_BYTE_OFFSET(name, x, y) mad24(y, name ## StepBytes, (x) * (int)(name ## _TSIZE))\n"
"#define __LOAD_MAT_AT(name, byteOffset) *((const __global name ## _T*)(name ## Ptr + (byteOffset)))\n"
"#define __vload_CN__(name_cn) vload ## name_cn\n"
"#define __vload_CN_(name_cn) __vload_CN__(name_cn)\n"
"#define __vload_CN(name) __vload_CN_(name ## _CN)\n"
"#define __LOAD_MAT_AT_vload(name, byteOffset) __vload_CN(name)(0, ((const __global name ## _T1*)(name ## Ptr + (byteOffset))))\n"
"#define __LOAD_MAT_AT_1 __LOAD_MAT_AT\n"
"#define __LOAD_MAT_AT_2 __LOAD_MAT_AT\n"
"#define __LOAD_MAT_AT_3 __LOAD_MAT_AT_vload\n"
"#define __LOAD_MAT_AT_4 __LOAD_MAT_AT\n"
"#define __LOAD_MAT_AT_CN__(name_cn) __LOAD_MAT_AT_ ## name_cn\n"
"#define __LOAD_MAT_AT_CN_(name_cn) __LOAD_MAT_AT_CN__(name_cn)\n"
"#define __LOAD_MAT_AT_CN(name) __LOAD_MAT_AT_CN_(name ## _CN)\n"
"#define LOAD_MAT_AT(name, byteOffset) __LOAD_MAT_AT_CN(name)(name, byteOffset)\n"
"#define __STORE_MAT_AT(name, byteOffset, v) *((__global name ## _T*)(name ## Ptr + (byteOffset))) = v\n"
"#define __vstore_CN__(name_cn) vstore ## name_cn\n"
"#define __vstore_CN_(name_cn) __vstore_CN__(name_cn)\n"
"#define __vstore_CN(name) __vstore_CN_(name ## _CN)\n"
"#define __STORE_MAT_AT_vstore(name, byteOffset, v) __vstore_CN(name)(v, 0, ((__global name ## _T1*)(name ## Ptr + (byteOffset))))\n"
"#define __STORE_MAT_AT_1 __STORE_MAT_AT\n"
"#define __STORE_MAT_AT_2 __STORE_MAT_AT\n"
"#define __STORE_MAT_AT_3 __STORE_MAT_AT_vstore\n"
"#define __STORE_MAT_AT_4 __STORE_MAT_AT\n"
"#define __STORE_MAT_AT_CN__(name_cn) __STORE_MAT_AT_ ## name_cn\n"
"#define __STORE_MAT_AT_CN_(name_cn) __STORE_MAT_AT_CN__(name_cn)\n"
"#define __STORE_MAT_AT_CN(name) __STORE_MAT_AT_CN_(name ## _CN)\n"
"#define STORE_MAT_AT(name, byteOffset, v) __STORE_MAT_AT_CN(name)(name, byteOffset, v)\n"
"#define T1_uchar uchar\n"
"#define T1_uchar2 uchar\n"
"#define T1_uchar3 uchar\n"
"#define T1_uchar4 uchar\n"
"#define T1_char char\n"
"#define T1_char2 char\n"
"#define T1_char3 char\n"
"#define T1_char4 char\n"
"#define T1_ushort ushort\n"
"#define T1_ushort2 ushort\n"
"#define T1_ushort3 ushort\n"
"#define T1_ushort4 ushort\n"
"#define T1_short short\n"
"#define T1_short2 short\n"
"#define T1_short3 short\n"
"#define T1_short4 short\n"
"#define T1_int int\n"
"#define T1_int2 int\n"
"#define T1_int3 int\n"
"#define T1_int4 int\n"
"#define T1_float float\n"
"#define T1_float2 float\n"
"#define T1_float3 float\n"
"#define T1_float4 float\n"
"#define T1_double double\n"
"#define T1_double2 double\n"
"#define T1_double3 double\n"
"#define T1_double4 double\n"
"#define T1(type) REF(CAT(T1_, REF(type)))\n"
"#define uchar1 uchar\n"
"#define char1 char\n"
"#define short1 short\n"
"#define ushort1 ushort\n"
"#define int1 int\n"
"#define float1 float\n"
"#define double1 double\n"
"#define TYPE(type, cn) REF(CAT(REF(type), REF(cn)))\n"
"#define __CONVERT_MODE_uchar_uchar __NO_CONVERT\n"
"#define __CONVERT_MODE_uchar_char __CONVERT_sat\n"
"#define __CONVERT_MODE_uchar_ushort __CONVERT\n"
"#define __CONVERT_MODE_uchar_short __CONVERT\n"
"#define __CONVERT_MODE_uchar_int __CONVERT\n"
"#define __CONVERT_MODE_uchar_float __CONVERT\n"
"#define __CONVERT_MODE_uchar_double __CONVERT\n"
"#define __CONVERT_MODE_char_uchar __CONVERT_sat\n"
"#define __CONVERT_MODE_char_char __NO_CONVERT\n"
"#define __CONVERT_MODE_char_ushort __CONVERT_sat\n"
"#define __CONVERT_MODE_char_short __CONVERT\n"
"#define __CONVERT_MODE_char_int __CONVERT\n"
"#define __CONVERT_MODE_char_float __CONVERT\n"
"#define __CONVERT_MODE_char_double __CONVERT\n"
"#define __CONVERT_MODE_ushort_uchar __CONVERT_sat\n"
"#define __CONVERT_MODE_ushort_char __CONVERT_sat\n"
"#define __CONVERT_MODE_ushort_ushort __NO_CONVERT\n"
"#define __CONVERT_MODE_ushort_short __CONVERT_sat\n"
"#define __CONVERT_MODE_ushort_int __CONVERT\n"
"#define __CONVERT_MODE_ushort_float __CONVERT\n"
"#define __CONVERT_MODE_ushort_double __CONVERT\n"
"#define __CONVERT_MODE_short_uchar __CONVERT_sat\n"
"#define __CONVERT_MODE_short_char __CONVERT_sat\n"
"#define __CONVERT_MODE_short_ushort __CONVERT_sat\n"
"#define __CONVERT_MODE_short_short __NO_CONVERT\n"
"#define __CONVERT_MODE_short_int __CONVERT\n"
"#define __CONVERT_MODE_short_float __CONVERT\n"
"#define __CONVERT_MODE_short_double __CONVERT\n"
"#define __CONVERT_MODE_int_uchar __CONVERT_sat\n"
"#define __CONVERT_MODE_int_char __CONVERT_sat\n"
"#define __CONVERT_MODE_int_ushort __CONVERT_sat\n"
"#define __CONVERT_MODE_int_short __CONVERT_sat\n"
"#define __CONVERT_MODE_int_int __NO_CONVERT\n"
"#define __CONVERT_MODE_int_float __CONVERT\n"
"#define __CONVERT_MODE_int_double __CONVERT\n"
"#define __CONVERT_MODE_float_uchar __CONVERT_sat_rte\n"
"#define __CONVERT_MODE_float_char __CONVERT_sat_rte\n"
"#define __CONVERT_MODE_float_ushort __CONVERT_sat_rte\n"
"#define __CONVERT_MODE_float_short __CONVERT_sat_rte\n"
"#define __CONVERT_MODE_float_int __CONVERT_rte\n"
"#define __CONVERT_MODE_float_float __NO_CONVERT\n"
"#define __CONVERT_MODE_float_double __CONVERT\n"
"#define __CONVERT_MODE_double_uchar __CONVERT_sat_rte\n"
"#define __CONVERT_MODE_double_char __CONVERT_sat_rte\n"
"#define __CONVERT_MODE_double_ushort __CONVERT_sat_rte\n"
"#define __CONVERT_MODE_double_short __CONVERT_sat_rte\n"
"#define __CONVERT_MODE_double_int __CONVERT_rte\n"
"#define __CONVERT_MODE_double_float __CONVERT\n"
"#define __CONVERT_MODE_double_double __NO_CONVERT\n"
"#define __CONVERT_MODE(srcType, dstType) CAT(__CONVERT_MODE_, CAT(REF(T1(srcType)), CAT(_, REF(T1(dstType)))))\n"
"#define __ROUND_MODE__NO_CONVERT\n"
"#define __ROUND_MODE__CONVERT\n"
"#define __ROUND_MODE__CONVERT_rte _rte\n"
"#define __ROUND_MODE__CONVERT_sat _sat\n"
"#define __ROUND_MODE__CONVERT_sat_rte _sat_rte\n"
"#define ROUND_MODE(srcType, dstType) CAT(__ROUND_MODE_, __CONVERT_MODE(srcType, dstType))\n"
"#define __CONVERT_ROUND(dstType, roundMode) CAT(CAT(convert_, REF(dstType)), roundMode)\n"
"#define __NO_CONVERT(dstType)\n"
"#define __CONVERT(dstType) __CONVERT_ROUND(dstType,)\n"
"#define __CONVERT_rte(dstType) __CONVERT_ROUND(dstType,_rte)\n"
"#define __CONVERT_sat(dstType) __CONVERT_ROUND(dstType,_sat)\n"
"#define __CONVERT_sat_rte(dstType) __CONVERT_ROUND(dstType,_sat_rte)\n"
"#define CONVERT(srcType, dstType) REF(__CONVERT_MODE(srcType,dstType))(dstType)\n"
"#define CONVERT_TO(dstType) __CONVERT_ROUND(dstType,)\n"
"#define CV_8U   0\n"
"#define CV_8S   1\n"
"#define CV_16U  2\n"
"#define CV_16S  3\n"
"#define CV_32S  4\n"
"#define CV_32F  5\n"
"#define CV_64F  6\n"
"#if defined(DEFINE_feed)\n"
"#define workType TYPE(weight_T1, src_CN)\n"
"#if src_DEPTH == 3 && src_CN == 3\n"
"#define convertSrcToWorkType convert_float3\n"
"#else\n"
"#define convertSrcToWorkType CONVERT_TO(workType)\n"
"#endif\n"
"#if dst_DEPTH == 3 && dst_CN == 3\n"
"#define convertToDstType convert_short3\n"
"#else\n"
"#define convertToDstType CONVERT_TO(dst_T)\n"
"#endif\n"
"__kernel void feed(\n"
"DECLARE_MAT_ARG(src), DECLARE_MAT_ARG(weight),\n"
"DECLARE_MAT_ARG(dst), DECLARE_MAT_ARG(dstWeight)\n"
")\n"
"{\n"
"const int x = get_global_id(0);\n"
"const int y = get_global_id(1);\n"
"if (x < srcWidth && y < srcHeight)\n"
"{\n"
"int src_byteOffset = MAT_BYTE_OFFSET(src, x, y);\n"
"int weight_byteOffset = MAT_BYTE_OFFSET(weight, x, y);\n"
"int dst_byteOffset = MAT_BYTE_OFFSET(dst, x, y);\n"
"int dstWeight_byteOffset = MAT_BYTE_OFFSET(dstWeight, x, y);\n"
"weight_T w = LOAD_MAT_AT(weight, weight_byteOffset);\n"
"workType src_value = convertSrcToWorkType(LOAD_MAT_AT(src, src_byteOffset));\n"
"STORE_MAT_AT(dst, dst_byteOffset, LOAD_MAT_AT(dst, dst_byteOffset) + convertToDstType(src_value * w));\n"
"STORE_MAT_AT(dstWeight, dstWeight_byteOffset, LOAD_MAT_AT(dstWeight, dstWeight_byteOffset) + w);\n"
"}\n"
"}\n"
"#endif\n"
"#if defined(DEFINE_normalizeUsingWeightMap)\n"
"#if mat_DEPTH == 3 && mat_CN == 3\n"
"#define workType float3\n"
"#define convertSrcToWorkType convert_float3\n"
"#define convertToDstType convert_short3\n"
"#else\n"
"#define workType TYPE(weight_T1, mat_CN)\n"
"#define convertSrcToWorkType CONVERT_TO(workType)\n"
"#define convertToDstType CONVERT_TO(mat_T)\n"
"#endif\n"
"#if weight_DEPTH >= CV_32F\n"
"#define WEIGHT_EPS 1e-5f\n"
"#else\n"
"#define WEIGHT_EPS 0\n"
"#endif\n"
"__kernel void normalizeUsingWeightMap(\n"
"DECLARE_MAT_ARG(mat), DECLARE_MAT_ARG(weight)\n"
")\n"
"{\n"
"const int x = get_global_id(0);\n"
"const int y = get_global_id(1);\n"
"if (x < matWidth && y < matHeight)\n"
"{\n"
"int mat_byteOffset = MAT_BYTE_OFFSET(mat, x, y);\n"
"int weight_byteOffset = MAT_BYTE_OFFSET(weight, x, y);\n"
"weight_T w = LOAD_MAT_AT(weight, weight_byteOffset);\n"
"workType value = convertSrcToWorkType(LOAD_MAT_AT(mat, mat_byteOffset));\n"
"value = value / (w + WEIGHT_EPS);\n"
"STORE_MAT_AT(mat, mat_byteOffset, convertToDstType(value));\n"
"}\n"
"}\n"
"#endif\n"
, "3320d5f13a357c8ee3c223e66d598244"};
ProgramSource multibandblend_oclsrc(multibandblend.programStr);
const struct ProgramEntry warpers={"warpers",
"__kernel void buildWarpPlaneMaps(__global uchar * xmapptr, int xmap_step, int xmap_offset,\n"
"__global uchar * ymapptr, int ymap_step, int ymap_offset, int rows, int cols,\n"
"__constant float * ck_rinv, __constant float * ct,\n"
"int tl_u, int tl_v, float scale, int rowsPerWI)\n"
"{\n"
"int du = get_global_id(0);\n"
"int dv0 = get_global_id(1) * rowsPerWI;\n"
"if (du < cols)\n"
"{\n"
"int xmap_index = mad24(dv0, xmap_step, mad24(du, (int)sizeof(float), xmap_offset));\n"
"int ymap_index = mad24(dv0, ymap_step, mad24(du, (int)sizeof(float), ymap_offset));\n"
"float u = tl_u + du;\n"
"float x_ = fma(u, scale, -ct[0]);\n"
"float ct1 = 1 - ct[2];\n"
"for (int dv = dv0, dv1 = min(rows, dv0 + rowsPerWI); dv < dv1; ++dv, xmap_index += xmap_step,\n"
"ymap_index += ymap_step)\n"
"{\n"
"__global float * xmap = (__global float *)(xmapptr + xmap_index);\n"
"__global float * ymap = (__global float *)(ymapptr + ymap_index);\n"
"float v = tl_v + dv;\n"
"float y_ = fma(v, scale, -ct[1]);\n"
"float x = fma(ck_rinv[0], x_, fma(ck_rinv[1], y_, ck_rinv[2] * ct1));\n"
"float y = fma(ck_rinv[3], x_, fma(ck_rinv[4], y_, ck_rinv[5] * ct1));\n"
"float z = fma(ck_rinv[6], x_, fma(ck_rinv[7], y_, ck_rinv[8] * ct1));\n"
"if (z != 0)\n"
"x /= z, y /= z;\n"
"else\n"
"x = y = -1;\n"
"xmap[0] = x;\n"
"ymap[0] = y;\n"
"}\n"
"}\n"
"}\n"
"__kernel void buildWarpCylindricalMaps(__global uchar * xmapptr, int xmap_step, int xmap_offset,\n"
"__global uchar * ymapptr, int ymap_step, int ymap_offset, int rows, int cols,\n"
"__constant float * ck_rinv, int tl_u, int tl_v, float scale, int rowsPerWI)\n"
"{\n"
"int du = get_global_id(0);\n"
"int dv0 = get_global_id(1) * rowsPerWI;\n"
"if (du < cols)\n"
"{\n"
"int xmap_index = mad24(dv0, xmap_step, mad24(du, (int)sizeof(float), xmap_offset));\n"
"int ymap_index = mad24(dv0, ymap_step, mad24(du, (int)sizeof(float), ymap_offset));\n"
"float u = (tl_u + du) * scale;\n"
"float x_, z_;\n"
"x_ = sincos(u, &z_);\n"
"for (int dv = dv0, dv1 = min(rows, dv0 + rowsPerWI); dv < dv1; ++dv, xmap_index += xmap_step,\n"
"ymap_index += ymap_step)\n"
"{\n"
"__global float * xmap = (__global float *)(xmapptr + xmap_index);\n"
"__global float * ymap = (__global float *)(ymapptr + ymap_index);\n"
"float y_ = (tl_v + dv) * scale;\n"
"float x, y, z;\n"
"x = fma(ck_rinv[0], x_, fma(ck_rinv[1], y_, ck_rinv[2] * z_));\n"
"y = fma(ck_rinv[3], x_, fma(ck_rinv[4], y_, ck_rinv[5] * z_));\n"
"z = fma(ck_rinv[6], x_, fma(ck_rinv[7], y_, ck_rinv[8] * z_));\n"
"if (z > 0)\n"
"x /= z, y /= z;\n"
"else\n"
"x = y = -1;\n"
"xmap[0] = x;\n"
"ymap[0] = y;\n"
"}\n"
"}\n"
"}\n"
"__kernel void buildWarpSphericalMaps(__global uchar * xmapptr, int xmap_step, int xmap_offset,\n"
"__global uchar * ymapptr, int ymap_step, int ymap_offset, int rows, int cols,\n"
"__constant float * ck_rinv, int tl_u, int tl_v, float scale, int rowsPerWI)\n"
"{\n"
"int du = get_global_id(0);\n"
"int dv0 = get_global_id(1) * rowsPerWI;\n"
"if (du < cols)\n"
"{\n"
"int xmap_index = mad24(dv0, xmap_step, mad24(du, (int)sizeof(float), xmap_offset));\n"
"int ymap_index = mad24(dv0, ymap_step, mad24(du, (int)sizeof(float), ymap_offset));\n"
"float u = (tl_u + du) * scale;\n"
"float cosu, sinu = sincos(u, &cosu);\n"
"for (int dv = dv0, dv1 = min(rows, dv0 + rowsPerWI); dv < dv1; ++dv, xmap_index += xmap_step,\n"
"ymap_index += ymap_step)\n"
"{\n"
"__global float * xmap = (__global float *)(xmapptr + xmap_index);\n"
"__global float * ymap = (__global float *)(ymapptr + ymap_index);\n"
"float v = (tl_v + dv) * scale;\n"
"float cosv, sinv = sincos(v, &cosv);\n"
"float x_ = sinv * sinu;\n"
"float y_ = -cosv;\n"
"float z_ = sinv * cosu;\n"
"float x, y, z;\n"
"x = fma(ck_rinv[0], x_, fma(ck_rinv[1], y_, ck_rinv[2] * z_));\n"
"y = fma(ck_rinv[3], x_, fma(ck_rinv[4], y_, ck_rinv[5] * z_));\n"
"z = fma(ck_rinv[6], x_, fma(ck_rinv[7], y_, ck_rinv[8] * z_));\n"
"if (z > 0)\n"
"x /= z, y /= z;\n"
"else\n"
"x = y = -1;\n"
"xmap[0] = x;\n"
"ymap[0] = y;\n"
"}\n"
"}\n"
"}\n"
, "83a61a49d8be5dcc09a00d8d4651c4f8"};
ProgramSource warpers_oclsrc(warpers.programStr);
}
}}

#ifndef CHECK_SIMD_CHECK_SIMD_H_
#define CHECK_SIMD_CHECK_SIMD_H_

#include <immintrin.h>
#include "cpuid.h"

// Dummy values for computation
constexpr float tnum = 1.007f;

// Test x87 FPU without inlining
float __attribute__ ((noinline)) square(float num);
void testWChar();
void checkFPU();

// Check all the SIMD levels
void checkMMX();
void checkSSE();
void checkSSE2();
void checkSSE3();
void checkSSSE3();
void checkSSE41();
void checkSSE4A();
void checkSSE42();
void checkPCMUL();
void checkAES();
void checkAVX();
void checkFMA3();
void checkFMA4();
void checkAVX2();
void checkAVX512();
void checkVMX();

#endif // CHECK_SIMD_CHECK_SIMD_H_

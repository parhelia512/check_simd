#include <stdio.h>

#include "check_simd.h"
#include "../logger/logger.h"

Log Log("logfile.txt"); 

#ifdef _WIN32
#define cpuid(info, x)    __cpuidex(info, x, 0)
#else
void cpuid(int info[4], int InfoType){
    __cpuid_count(InfoType, 0, info[0], info[1], info[2], info[3]);
}
#endif

float __attribute__ ((noinline)) square(float num) {
    return num * num;
}

void checkFPU() {
  Log.info("The square of ");
  std::cout << "                    " << std::to_string(pi) << " is " << square(pi) << ".\n";
  Log.warn("^ Should have returned 9.8696");
  Log.info("x87 FPU is working!");
  Log.nl(NL);
}

void checkAVX() {
  // Check if AVX is supported
  if (__builtin_cpu_supports("avx")) {
    Log.info("AVX is supported!");

    // Create two 256-bit vectors
    __m256 a = _mm256_set_ps(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
    __m256 b = _mm256_set_ps(8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f);

    // Add the vectors
    __m256 c = _mm256_add_ps(a, b);

    // Print the result
    float* result = (float*)&c;
    
    for (int i = 0; i < 8; ++i) {
      std::cout << result[i] << " ";
    }
    Log.nl(NL);
  } else {
    Log.warn("AVX is not supported.");
  }
}

int main(void) {
  checkFPU();
  checkAVX();
  return 0;
}

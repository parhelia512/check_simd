#include "check_simd.h"

#include <stdio.h>
#include "logger.h"

Log Log("logfile.txt"); 

// Type your code here, or load an example.
float __attribute__ ((noinline)) square(float num1, float num2) {
    return num1 * num2;
}

void checkFPU() {
  square(tnum, pi);
  Log.info("x87 FPU is working!");
  std::wcout << tnum;
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

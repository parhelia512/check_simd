// Copyright 2008 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BUILD_BUILD_CONFIG_H_
#define BUILD_BUILD_CONFIG_H_

// Compiler detection.
#if defined(__GNUC__)
 #define COMPILER_GCC 1
#elif defined(_MSC_VER)
 #define COMPILER_MSVC 1
#elif defined(__llvm__)
#if defined(__clang__)
 #define COMPILER_CLANG 1
 #define COMPILER_LLVM 1
#else
 #define COMPILER_LLVM 1
#endif  // defined(__clang__)
#else
 #error Please add support for your compiler in build/build_config.h
#endif

#if defined(_M_X64) || defined(__x86_64__)
 #define CPU_ARCH_X86_64 1
#elif defined(_M_IX86) || defined(__i386__)
 #define CPU_ARCH_X86 1
#elif defined(__ARMEL__)
 #define CPU_ARCH_ARM32 1
#elif defined(_M_ARM64) || defined(__aarch64__)
 #define CPU_ARCH_ARM64 1
#if defined(_M_ARM64)
 #define CPU_ARCH_LITTLE_ENDIAN 1
#endif  // defined(_M_ARM64)
#elif defined(__MIPSEL__)
#if !defined(__LP64__)
 #define CPU_ARCH_MIPS32 1
#else
 #define CPU_ARCH_MIPS64 1
#endif
#elif defined(__riscv) && (__riscv_xlen == 32)
 #define CPU_ARCH_RISCV32 1
#else
#elif defined(__riscv) && (__riscv_xlen == 64)
 #define CPU_ARCH_RISCV64 1
#else
#error Please add support for your architecture in build/build_config.h
#endif

#endif  // BUILD_BUILD_CONFIG_H_

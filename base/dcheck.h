#ifndef DCHECK_H_
#define DCHECK_H_

#pragma once

#include <stdint.h>
#include <stdlib.h>

// Branch prediction hints for the compiler.  Use in performance critial code
// which almost always branches one way.
//#define LIKELY(expr) __builtin_expect(!!(expr), 1)
//#define UNLIKELY(expr) __builtin_expect(!!(expr), 0)
#define LIKELY(expr) __builtin_expect((expr), 1)
#define UNLIKELY(expr) __builtin_expect((expr), 0)

// overload if you want your own abort fn - w/e
#ifndef CHECK_ABORT_FUNCTION
// need that prototype def
#define CHECK_ABORT_FUNCTION abort
#endif

#define CHECK(expr, ...)                                               \
  do {                                                                 \
    if (UNLIKELY(expr)) {                                              \
      CHECK_ABORT_FUNCTION();                                          \
    }                                                                  \
  } while (0)

// check and bail if nope. however, this only works if `-D DCHECK_IS_ON`
// or equivalent is defined
#ifdef DCHECK_IS_ON
# define DCHECK(...) CHECK(__VA_ARGS__);
#else
# define DCHECK(expr) ((void) expr);
#endif

#endif // DCHECK_H_

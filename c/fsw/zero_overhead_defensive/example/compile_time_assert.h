#ifndef COMPILE_TIME_ASSERT_H
#define COMPILE_TIME_ASSERT_H

#include <stdint.h>

#if __STDC_VERSION__ >= 201112L
#define COMPILE_TIME_ASSERT(expr, msg) static_assert(expr, msg)
#else
#define COMPILE_TIME_ASSERT(expr, msg) uint8_t compile_time_assert_##msg[(expr) ? 1 : -1]
#endif

#endif // COMPILE_TIME_ASSERT_H

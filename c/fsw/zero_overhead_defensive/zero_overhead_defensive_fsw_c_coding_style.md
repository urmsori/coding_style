# zero overhead defensive

## purpose

- defensive programming with zero overhead in release build.

## effect

- catch bugs in debug build.
- no runtime cost in release build.
- no compile-time cost in release build.

## assert

- debug only. removed in release (NDEBUG defined).

```c
#include <assert.h>

void example_read(const uint8_t *data)
{
    // assert: debug only
    assert(data != NULL);
}
```

## COMPILE_TIME_ASSERT

- compile-time check. no runtime cost.
- use static_assert (C11) or array trick (C99).

```c
// compile_time_assert.h
#if __STDC_VERSION__ >= 201112L
#define COMPILE_TIME_ASSERT(expr, msg) static_assert(expr, msg)
#else
#define COMPILE_TIME_ASSERT(expr, msg) uint8_t compile_time_assert_##msg[(expr) ? 1 : -1]
#endif
```

```c
// sizeof check
COMPILE_TIME_ASSERT(sizeof(struct example_data) == 8, sizeof_example_data);

// offsetof check
COMPILE_TIME_ASSERT(offsetof(struct example_data, data2) == 4, offsetof_example_data_data2);
```

## const correctness

- compile-time check. no runtime cost.

```c
// const value
const uint32_t value = 10;

// pointer to const: data is const
void read(const uint8_t *data);

// const pointer: pointer is const
uint8_t *const ptr = buffer;

// const pointer to const: both const
const uint8_t *const ptr = buffer;

// const struct pointer
void process(const struct example_data *data);

// const array parameter
void copy(const uint8_t src[4], uint8_t dst[4]);

// const return (for internal static data)
const struct example_data *example_get_default(void);
```

#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "compile_time_assert.h"

#ifdef __cplusplus
extern "C"
{
#endif

  typedef uint8_t example_id_t;
#define EXAMPLE_ID_MAX (2)

  struct example_data
  {
    uint8_t data1[4];
    uint32_t data2;
  };

  // COMPILE_TIME_ASSERT: sizeof check
  COMPILE_TIME_ASSERT(sizeof(struct example_data) == 8, sizeof_example_data);

  // COMPILE_TIME_ASSERT: offsetof check
  COMPILE_TIME_ASSERT(offsetof(struct example_data, data2) == 4, offsetof_example_data_data2);

  // const correctness: pointer to const
  void example_read(const uint8_t *data);

  // const correctness: const struct pointer
  void example_process(const struct example_data *data);

  // const correctness: const array parameter
  void example_copy(const uint8_t src[4], uint8_t dst[4]);

  // const correctness: const return
  const struct example_data *example_get_default(void);

#ifdef __cplusplus
}
#endif

#endif // EXAMPLE_H

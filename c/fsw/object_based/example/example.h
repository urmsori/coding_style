#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

  // public type
  typedef uint8_t example_id_t;
#define EXAMPLE_ID_0 (0)
#define EXAMPLE_ID_1 (1)
#define EXAMPLE_ID_MAX (2)

  // public struct
  struct example_data
  {
    uint8_t data1[4];
    uint32_t data2;
  };
#ifndef NDEBUG
  int example_struct_example_data_sizeof_checker[sizeof(struct example_data) == 8 ? 1 : -1];
#endif

#define EXAMPLE_DATA_COUNT_MAX (20)

  typedef int8_t example_set_data_result_t;
#define EXAMPLE_SET_DATA_RESULT_SUCCESS (1)
#define EXAMPLE_SET_DATA_RESULT_ERROR_UNDEFINED (-1)
#define EXAMPLE_SET_DATA_RESULT_ERROR_CAPACITY (-2)
#define EXAMPLE_SET_DATA_RESULT_ERROR_INVALID_ID (-3)
#define EXAMPLE_SET_DATA_RESULT_ERROR_NULL_POINTER (-4)
#define EXAMPLE_SET_DATA_RESULT_ERROR_NOT_INITIALIZED (-5)

  // public function
  void example_init(example_id_t id);
  uint32_t example_get_data_count(example_id_t id);
  uint32_t example_get_total_data_size(example_id_t id);
  bool example_get_data(example_id_t id, struct example_data data_out[EXAMPLE_DATA_COUNT_MAX]);
  example_set_data_result_t example_set_data(
      example_id_t id,
      const struct example_data data[EXAMPLE_DATA_COUNT_MAX],
      uint32_t data_count);

#ifdef __cplusplus
}
#endif

#endif // EXAMPLE_H

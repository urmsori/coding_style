#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

  typedef uint8_t example_id_t;
#define EXAMPLE_ID_MAX (2)
#define EXAMPLE_DATA_SIZE_MAX (20)

  // return type: void
  void example_init(example_id_t id);

  // return type: {type} for always success getter
  uint32_t example_get_count(example_id_t id);

  // return type: bool for simple success/fail
  bool example_get_data(example_id_t id, uint8_t data_out[EXAMPLE_DATA_SIZE_MAX]);

  // return type: {function_name}_result_t for detailed result
  typedef int8_t example_set_data_result_t;
#define EXAMPLE_SET_DATA_RESULT_SUCCESS (1)
#define EXAMPLE_SET_DATA_RESULT_ERROR_UNDEFINED (-1)
#define EXAMPLE_SET_DATA_RESULT_ERROR_INVALID_ID (-2)
#define EXAMPLE_SET_DATA_RESULT_ERROR_INVALID_SIZE (-3)
#define EXAMPLE_SET_DATA_RESULT_ERROR_NULL_POINTER (-4)

  // options struct: {function_name}_options
  struct example_set_data_options
  {
    uint32_t timeout_ms;
    bool verify_after_write;
  };

  // argument order: id, {derived from function name}, options
  example_set_data_result_t example_set_data(
      example_id_t id,
      const uint8_t *data,
      uint32_t data_size,
      const struct example_set_data_options *options);

#ifdef __cplusplus
}
#endif

#endif // EXAMPLE_H

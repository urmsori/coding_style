// Header guard
#ifndef EXAMPLE_H
#define EXAMPLE_H

// Standard Types - <stdint.h>, <stdbool.h>
#include <stdbool.h>
#include <stdint.h>

// C++ compatibility handling
#ifdef __cplusplus
extern "C"
{
#endif

  // Result/ID Codes: Use typedef & #define (not enum keyword)
  typedef uint8_t example_id_t;
#define EXAMPLE_ID_0 (0)
#define EXAMPLE_ID_1 (1)
#define EXAMPLE_ID_MAX (2)

  // Struct Definition: Use 'struct' keyword directly (no masking typedef)
  struct example_data
  {
    uint8_t data1[4];
    uint32_t data2;
  };
// Compile-time Check: sizeof struct (Debug only)
#ifndef NDEBUG
  int example_struct_example_data_sizeof_checker[sizeof(struct example_data) == 8 ? 1 : -1];
#endif

  // Public Function Prototypes (Prefix: example_)
  void example_init(example_id_t id);
  uint32_t example_get_data_count(example_id_t id);
  uint32_t example_get_total_data_size(example_id_t id);

  // Macro Placement: Near first use or top of file
#define EXAMPLE_DATA_COUNT_MAX (20)
  // Naming: Output parameter suffix '_out'
  bool example_get_data(example_id_t id, struct example_data data_out[EXAMPLE_DATA_COUNT_MAX]);

  // Result Codes: Use 'typedef <module>_result_t' and #define pattern
  typedef int8_t example_set_data_result_t;
#define EXAMPLE_SET_DATA_RESULT_SUCCESS (0)
#define EXAMPLE_SET_DATA_RESULT_ERROR_UNDEFINED (-1)
#define EXAMPLE_SET_DATA_RESULT_ERROR_CAPACITY (-2)
#define EXAMPLE_SET_DATA_RESULT_ERROR_INVALID_ID (-3)
#define EXAMPLE_SET_DATA_RESULT_ERROR_NULL_POINTER (-4)
#define EXAMPLE_SET_DATA_RESULT_ERROR_NOT_INITIALIZED (-5)
  // Naming: 'const' for read-only parameters
  example_set_data_result_t example_set_data(
      example_id_t id,
      const struct example_data data[EXAMPLE_DATA_COUNT_MAX],
      uint32_t data_count);

// C++ compatibility handling
#ifdef __cplusplus
}
#endif

// Header guard
#endif // EXAMPLE_H

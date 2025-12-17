# function name derived argument and type

## purpose

- derive return type, argument, constant from function name.

## effect

- predictable: infer type from function name.
- consistent: uniform pattern across codebase.
- self-documenting: function name explains interface.

## return type

- void: no return.
- bool: simple success/fail.
- {type}: always success getter.
- {function_name}_result_t: detailed result.

```c
// return type: void
void example_init(example_id_t id);

// return type: {type} for always success getter
uint32_t example_get_count(example_id_t id);

// return type: bool for simple success/fail
bool example_get_data(example_id_t id, uint8_t data_out[EXAMPLE_DATA_SIZE_MAX]);

// return type: {function_name}_result_t for detailed result
example_set_data_result_t example_set_data(
    example_id_t id,
    const uint8_t *data,
    uint32_t data_size,
    const struct example_set_data_options *options);
```

## result type

- typedef: {function_name}_result_t.
- 0: reserved.
- success: positive.
- error: negative.

```c
typedef int8_t example_set_data_result_t;
#define EXAMPLE_SET_DATA_RESULT_SUCCESS (1)
#define EXAMPLE_SET_DATA_RESULT_ERROR_UNDEFINED (-1)
#define EXAMPLE_SET_DATA_RESULT_ERROR_INVALID_ID (-2)
#define EXAMPLE_SET_DATA_RESULT_ERROR_INVALID_SIZE (-3)
#define EXAMPLE_SET_DATA_RESULT_ERROR_NULL_POINTER (-4)
```

## argument order

1. instance/descriptor (id)
2. derived from function name (data, data_size)
3. options struct (optional)

```c
example_set_data_result_t example_set_data(
    example_id_t id,                                  // 1. instance
    const uint8_t *data,                              // 2. derived: data
    uint32_t data_size,                               // 2. derived: data_size
    const struct example_set_data_options *options);  // 3. options
```

## options struct

- name: {function_name}_options.
- use: optional parameters.

```c
struct example_set_data_options
{
    uint32_t timeout_ms;
    bool verify_after_write;
};
```

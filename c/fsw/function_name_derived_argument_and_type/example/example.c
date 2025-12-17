#include "example/example.h"
#ifdef EXAMPLE_H

#include <stddef.h>
#include <string.h>

static struct example_context
{
    uint8_t data[EXAMPLE_DATA_SIZE_MAX];
    uint32_t count;
    bool initialized;
};

static struct example_context example_contexts[EXAMPLE_ID_MAX];

// return type: void
void example_init(example_id_t id)
{
    example_contexts[id].count = 0;
    memset(example_contexts[id].data, 0, sizeof(example_contexts[id].data));
    example_contexts[id].initialized = true;
}

// return type: {type} for always success getter
uint32_t example_get_count(example_id_t id)
{
    return example_contexts[id].count;
}

// return type: bool for simple success/fail
bool example_get_data(example_id_t id, uint8_t data_out[EXAMPLE_DATA_SIZE_MAX])
{
    if (data_out == NULL)
    {
        return false;
    }
    memcpy(data_out, example_contexts[id].data, example_contexts[id].count);
    return true;
}

// return type: {function_name}_result_t for detailed result
example_set_data_result_t example_set_data(
    example_id_t id,
    const uint8_t *data,
    uint32_t data_size,
    const struct example_set_data_options *options)
{
    if (id >= EXAMPLE_ID_MAX)
    {
        return EXAMPLE_SET_DATA_RESULT_ERROR_INVALID_ID;
    }
    if (data_size > EXAMPLE_DATA_SIZE_MAX)
    {
        return EXAMPLE_SET_DATA_RESULT_ERROR_INVALID_SIZE;
    }
    if (data_size > 0 && data == NULL)
    {
        return EXAMPLE_SET_DATA_RESULT_ERROR_NULL_POINTER;
    }

    if (data_size > 0)
    {
        memcpy(example_contexts[id].data, data, data_size);
    }
    example_contexts[id].count = data_size;

    if (options != NULL)
    {
        // use options->timeout_ms, options->verify_after_write
    }

    return EXAMPLE_SET_DATA_RESULT_SUCCESS;
}

#endif // EXAMPLE_H

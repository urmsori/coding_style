#include "example/example.h"
#ifdef EXAMPLE_H

#include <assert.h>
#include <stddef.h>
#include <string.h>

// private struct
static struct example_context
{
    struct example_data data_items[EXAMPLE_DATA_COUNT_MAX];
    uint32_t current_data_count;
    bool initialized;
};

// private variable
static struct example_context example_contexts[EXAMPLE_ID_MAX];

// private function
static inline bool example_is_valid_id(example_id_t id)
{
    return (id < EXAMPLE_ID_MAX);
}

void example_init(example_id_t id)
{
    assert(example_is_valid_id(id));

    example_contexts[id].current_data_count = 0;
    memset(example_contexts[id].data_items, 0, sizeof(example_contexts[id].data_items));
    example_contexts[id].initialized = true;
}

uint32_t example_get_data_count(example_id_t id)
{
    assert(example_is_valid_id(id));
    assert(example_contexts[id].initialized);
    return example_contexts[id].current_data_count;
}

uint32_t example_get_total_data_size(example_id_t id)
{
    assert(example_is_valid_id(id));
    assert(example_contexts[id].initialized);
    return example_contexts[id].current_data_count * sizeof(struct example_data);
}

bool example_get_data(example_id_t id, struct example_data data_out[EXAMPLE_DATA_COUNT_MAX])
{
    if (!example_is_valid_id(id) || !example_contexts[id].initialized)
    {
        return false;
    }
    if (data_out == NULL)
    {
        return false;
    }

    uint32_t count_to_copy = example_contexts[id].current_data_count;

    if (count_to_copy > 0)
    {
        memcpy(data_out, example_contexts[id].data_items, count_to_copy * sizeof(struct example_data));
    }

    return true;
}

example_set_data_result_t example_set_data(
    example_id_t id,
    const struct example_data data[EXAMPLE_DATA_COUNT_MAX],
    uint32_t data_count)
{
    bool is_valid_id = example_is_valid_id(id);
    if (!is_valid_id)
    {
        return EXAMPLE_SET_DATA_RESULT_ERROR_INVALID_ID;
    }
    if (!example_contexts[id].initialized)
    {
        return EXAMPLE_SET_DATA_RESULT_ERROR_NOT_INITIALIZED;
    }
    if (data_count > EXAMPLE_DATA_COUNT_MAX)
    {
        return EXAMPLE_SET_DATA_RESULT_ERROR_CAPACITY;
    }
    if (data_count > 0 && data == NULL)
    {
        return EXAMPLE_SET_DATA_RESULT_ERROR_NULL_POINTER;
    }

    if (data_count > 0)
    {
        memcpy(example_contexts[id].data_items, data, data_count * sizeof(struct example_data));
    }

    example_contexts[id].current_data_count = data_count;

    return EXAMPLE_SET_DATA_RESULT_SUCCESS;
}

#endif // EXAMPLE_H

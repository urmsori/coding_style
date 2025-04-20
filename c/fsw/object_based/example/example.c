// Include own header first
#include "example/example.h"

// Use assert for zero-overhead defensive programming
#include <assert.h>
#include <stddef.h>
#include <string.h>

// Use 'static' for private struct definitions
static struct example_context
{
    struct example_data data_items[EXAMPLE_DATA_COUNT_MAX];
    uint32_t current_data_count;
    bool initialized;
};

// Use 'static' and 'g_' prefix for private global variables
static struct example_context g_example_contexts[EXAMPLE_ID_MAX];

// Use 'static' for private functions
static inline bool example_is_valid_id(example_id_t id)
{
    return (id < EXAMPLE_ID_MAX);
}

void example_init(example_id_t id)
{
    // Defensive Programming: assert preconditions
    assert(example_is_valid_id(id));

    g_example_contexts[id].current_data_count = 0;
    memset(g_example_contexts[id].data_items, 0, sizeof(g_example_contexts[id].data_items));
    g_example_contexts[id].initialized = true;
}

uint32_t example_get_data_count(example_id_t id)
{
    assert(example_is_valid_id(id));
    assert(g_example_contexts[id].initialized);
    return g_example_contexts[id].current_data_count;
}

uint32_t example_get_total_data_size(example_id_t id)
{
    assert(example_is_valid_id(id));
    assert(g_example_contexts[id].initialized);
    return g_example_contexts[id].current_data_count * sizeof(struct example_data);
}

bool example_get_data(example_id_t id, struct example_data data_out[EXAMPLE_DATA_COUNT_MAX])
{
    // Defensive Programming: Runtime checks
    if (!example_is_valid_id(id) || !g_example_contexts[id].initialized)
    {
        return false;
    }
    if (data_out == NULL)
    {
        return false;
    }

    uint32_t count_to_copy = g_example_contexts[id].current_data_count;

    if (count_to_copy > 0)
    {
        memcpy(data_out, g_example_contexts[id].data_items, count_to_copy * sizeof(struct example_data));
    }

    return true;
}

example_set_data_result_t example_set_data(
    example_id_t id,
    const struct example_data data[EXAMPLE_DATA_COUNT_MAX],
    uint32_t data_count)
{
    // Defensive Programming: Runtime checks & Return result codes
    if (!example_is_valid_id(id))
    {
        return EXAMPLE_SET_DATA_RESULT_ERROR_INVALID_ID;
    }
    if (!g_example_contexts[id].initialized)
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
        memcpy(g_example_contexts[id].data_items, data, data_count * sizeof(struct example_data));
    }

    g_example_contexts[id].current_data_count = data_count;

    return EXAMPLE_SET_DATA_RESULT_SUCCESS;
}
#include "example/example.h"
#ifdef EXAMPLE_H

#include <assert.h>
#include <string.h>

static struct example_data example_default = {
    .data1 = {0, 0, 0, 0},
    .data2 = 0
};

void example_read(const uint8_t *data)
{
    // assert: debug only
    assert(data != NULL);

    // read data
}

void example_process(const struct example_data *data)
{
    // assert: debug only
    assert(data != NULL);

    // process data
}

void example_copy(const uint8_t src[4], uint8_t dst[4])
{
    // assert: debug only
    assert(src != NULL);
    assert(dst != NULL);

    memcpy(dst, src, 4);
}

const struct example_data *example_get_default(void)
{
    return &example_default;
}

#endif // EXAMPLE_H

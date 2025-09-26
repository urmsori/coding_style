#include <component/variant_define/component_variant_define.h>
#ifdef COMPONENT_DEFINE_H

#ifndef COMPONENT_H
#define COMPONENT_H

#include <stdint.h>

uint32_t component_read(void);
void component_write(uint8_t data[COMPONENT_WRITE_DATA_SIZE_MAX]);

#endif // COMPONENT_H

#endif // COMPONENT_DEFINE_H

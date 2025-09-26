#include <component/variant_define/component_variant_define.h>
#ifdef COMPONENT_DEFINE_H

#ifndef COMPONENT_H
#define COMPONENT_H

#if (VARIANT_COMPONENT == a)
#include <component/variant_define/a/component_define.h>
#elif (VARIANT_COMPONENT == b)
#include <component/variant_define/b/component_define.h>
#else
#error "VARIANT_COMPONENT undefinded"
#endif

#include <stdint.h>

uint32_t component_read(void);
void component_write(uint8_t data[COMPONENT_WRITE_DATA_SIZE_MAX]);

#endif // COMPONENT_H

#endif // COMPONENT_DEFINE_H

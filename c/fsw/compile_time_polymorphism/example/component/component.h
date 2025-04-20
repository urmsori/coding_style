#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#if (_VARIANT_COMPONENT_ == a)
#include <component/variant_define/a/component_define.h>
#elseif (_VARIANT_COMPONENT_ == b)
#include <component/variant_define/b/component_define.h>
#else
#error "_VARIANT_COMPONENT_ undefinded"
#endif

#include <stdint.h>

uint32_t component_read(void);
void component_write(uint8_t data[COMPONENT_WRITE_DATA_SIZE_MAX]);

#endif // _COMPONENT_H_
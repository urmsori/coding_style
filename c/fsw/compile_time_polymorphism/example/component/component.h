#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#if (_COMPILE_COMPONENT_ == a)
#include <component/define/component_define.h>
#elseif (_COMPILE_COMPONENT_ == b)
#include <component/define/component_define.h>
#else
#error "_COMPILE_COMPONENT_ undefinded"
#endif

#include <stdint.h>

uint32_t component_read(void);
void component_write(uint8_t data[COMPONENT_WRITE_DATA_SIZE_MAX]);

#endif // _COMPONENT_H_
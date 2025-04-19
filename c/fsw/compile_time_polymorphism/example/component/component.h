#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#if (_COMPONENT_ == A)
#include <component/define/component_define.h>
#elseif (_COMPONENT_ == A)
#include <component/define/component_define.h>
#else
#error "_COMPONENT_ undefinded"
#endif

#include <stdint.h>

uint32_t component_read(void);
void component_write(uint8_t data[COMPONENT_WRITE_DATA_SIZE_MAX]);

#endif // _COMPONENT_H_
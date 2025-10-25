#include "component/component.h"
#ifdef COMPONENT_H

#include "component/variant_specific/component_variant_specific.h"

uint32_t component_read(void){
    component_reset();
    return 0;
}

#endif // COMPONENT_H

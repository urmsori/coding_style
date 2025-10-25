#include "component/variant_specific/component_variant_specific.h"
#ifdef COMPONENT_VARIANT_SPECIFIC_H_

#include "component/variant_specific/a/component_a.h"

void component_write(uint8_t data[COMPONENT_WRITE_DATA_SIZE_MAX]){
    // Implementation of component_write with a
}


void component_a_reset(void){
    // Implementation of a-specific function
}

void component_reset(void){
    component_a_reset();
}

#endif // COMPONENT_VARIANT_SPECIFIC_H_

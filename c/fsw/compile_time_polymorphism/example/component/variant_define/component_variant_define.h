#ifndef COMPONENT_VARIANT_DEFINE_H
#define COMPONENT_VARIANT_DEFINE_H

#define COMPONENT_VARIANT_DEFINE_HEADER <component/variant_define/VARIANT_COMPONENT/component_define.h>
#if __has_include (COMPONENT_VARIANT_DEFINE_HEADER)
#include COMPONENT_VARIANT_DEFINE_HEADER
#endif

// if not -std=gnu2x
// #if (VARIANT_COMPONENT == a)
// #include <component/variant_define/a/component_define.h>
// #elif (VARIANT_COMPONENT == b)
// #include <component/variant_define/b/component_define.h>
// #endif

#endif // COMPONENT_VARIANT_DEFINE_H

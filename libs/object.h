#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "object_generics.h"

typedef struct {
  ITERATE_MEMBERS(OBJECT_MEMBER, )
} object;

void print_object(const object * const obj) {
  ITERATE_MEMBERS(PRINT_MEMBERS_FUNCT, obj);
}

#endif //__OBJECT_H__
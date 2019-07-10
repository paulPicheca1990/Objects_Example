#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/object.h"

typedef struct myObject {
  int something;
} TEST_OBJECT_t;

int main (int argc, char **argv) {  
  object number = {1, 2.00, 3.0L, '4', "123"};
  print_object(&number);    
  return 0;   
} 
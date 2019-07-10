#ifndef __OBJECT_GENERICS_H__
#define __OBJECT_GENERICS_H__

// Here to remove Compilor Warning
extern char *strdup(const char *);

#define FORMAT__(x) _Generic(((x)'0'),  \
  _Bool:                    "%d",  \
  char:                     "%c",  \
  signed char:              "%c",  \
  unsigned char:            "%c",  \
  int:                      "%d",  \
  short int:                "%hd", \
  long int:                 "%ld", \
  long long int:            "%lld",\
  unsigned int:             "%u",  \
  unsigned short int:       "%hu", \
  unsigned long int:        "%hlu",\
  unsigned long long int:   "%llu",\
  float:                    "%.2f",  \
  double:                   "%.2f",  \
  long double:              "%lf", \
  void *:                   "%p",  \
  int *:                    "%p",  \
  char *:                   "%s",  \
  float *:                  "%p",  \
  double *:                 "%p",  \
  default:                  "%x"   \
)

#define FORMAT_(type) FORMAT_##type
#define FORMAT_int    "%d"

#define OBJECT_MEMBER(variable_name, variable_type, value) \
  variable_type variable_name;

#define OBJECT_MEMBER_PRINT_FORMAT(variable_type) \
  strcat(strcat(strdup("%s: "), FORMAT__(variable_type)), strdup(" \n"))

#define ITERATE_MEMBERS(_, ...) \
  _(myInteger,   int,    __VA_ARGS__) \
  _(myDouble,    double, __VA_ARGS__) \
  _(myFloat,     float,  __VA_ARGS__) \
  _(myCharacter, char,   __VA_ARGS__) \
  _(myString,    char *, __VA_ARGS__)

#define PRINT_MEMBERS_FUNCT(variable_name, variable_type, obj) do{ \
  char *format = strcat(strcat(strdup("%s: "), FORMAT__(variable_type)), strdup("\n")); \
  printf( format, #variable_name, obj->variable_name ); \
} while(0);
 

#endif //__OBJECT_GENERICS_H__
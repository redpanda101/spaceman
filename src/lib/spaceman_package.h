#ifndef SPACEMAN_PACKAGE_H__
#define SPACEMAN_PACKAGE_H__

#include <stdio.h>

typedef struct spaceman_package_t
{
    FILE* spac_file;
    char** dirs;
    FILE** files;
    char* name;
} spaceman_package;

enum LANGUAGE
{
  C,
  CXX
} LANGUAGE;

const char* language_to_string(enum LANGUAGE language);

//Creates a new spaceman_package
//pack_name is the packages name.
spaceman_package* spaceman_package_new(char* pack_name, enum LANGUAGE language);
spaceman_package* spaceman_package_init(char* pack_name, enum LANGUAGE language);

#endif

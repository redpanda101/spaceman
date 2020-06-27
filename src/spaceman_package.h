#ifndef SPACEMAN_PACKAGE_H__
#define SPACEMAN_PACKAGE_H__

#include <stdio.h>
typedef struct spaceman_package_t 
{
    FILE* spac_file;
    FILE** directories;
    FILE** files;
    char* name;
} spaceman_package;

//Constructor for a spaceman_package
//
spaceman_package* spaceman_package_(char* pack_name);

//Creates a spaceman_package as in it makes directories and files
//package: the package to create
void spaceman_package_create(spaceman_package* package);

#endif

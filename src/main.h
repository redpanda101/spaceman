#ifndef MAIN_H__
#define MAIN_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib/spaceman_package.h"

//Help type
//Type of help to print ie GENERAL is general help.
enum HELP_T {
	GENERAL,
	NEW,
	INIT
};

int main(int, char**);
void help(enum HELP_T help_type);
void new(char* name);
void init(char* dir);

#endif //MAIN_H__

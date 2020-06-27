#ifndef MAIN_H__
#define MAIN_H__

#include <stdio.h>
#include <string.h>
#include "spaceman_package.h"

enum HELP_T {
	GENERAL,
	NEW
};

int main(int, char**);
void parse_args(char *arg);
void help(enum HELP_T help_type);
void new(char* name);

#endif //MAIN_H__

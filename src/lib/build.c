#include "build.h"
#include <stdlib.h>

void build_package(space_package* package, compiler _compiler)
{
	char* command = (char*) malloc (100);
	
	strcpy(command, _compiler.name);
	for(int i = 0; sizeof(package->source_names); i++)
	{
			strcat(command, package->source_names[i]);
			strcat(command, " ");
	}

	strcat(command, "-o ");
	strcat(command, package->name);
	
	system(command);
	
	free(command);
}

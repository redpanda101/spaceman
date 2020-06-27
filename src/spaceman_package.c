#include "spaceman_package.h"

#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

spaceman_package* spaceman_package_(char* pack_name) 
{
	struct stat s = {0};
	if(stat(pack_name, &s) == -1) {
		mkdir(pack_name, 0700);
		spaceman_package* p = (spaceman_package*) malloc (sizeof(spaceman_package));
		p->name = pack_name;
		return p;
	}
	return NULL;
}

void spaceman_package_create(spaceman_package *package)
{

		
	char* spac_file_name = package->name;
	strcat(spac_file_name, "/spaceman.toml");
	
	package->spac_file = fopen(spac_file_name, "w+");
	fputs("#test\n", package->spac_file);
	fputs("[space_project]", package->spac_file);
}

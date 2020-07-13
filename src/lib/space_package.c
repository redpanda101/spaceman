#include "space_package.h"

#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>

const char* language_to_string(enum LANGUAGE language)
{
  const char* str[] = {"c", "cxx"};
  return str[language];
}

space_package* space_package_new(char* pack_name, enum LANGUAGE language)
{
	space_package* p = (space_package *) malloc (sizeof(space_package));
	p->source_names = (char**) calloc (1, 100);
	if(p == NULL)
		return NULL;
	//Make dirs
	struct stat s = {0};
	int dir_exists = stat(pack_name, &s);
	if(dir_exists == -1)
	{
		puts("Creating directories");
		//root
		mkdir(pack_name, 0700);

		//src
		char* src = (char*) malloc (100);
		sprintf(src, "%s/src", pack_name);
		mkdir(src, 0700);
		free(src);

		//build
		char* build = (char*) malloc (100);
		sprintf(build, "%s/build", pack_name);
		mkdir(build, 0700);
		free(build);

		//spaceman.toml
		char* spac_file_name = (char*) malloc (100);

		sprintf(spac_file_name, "%s/spaceman.toml", pack_name);

		printf("Creating %s\n", spac_file_name);

		p->spac_file = fopen(spac_file_name, "w+");
		free(spac_file_name);

		fputs("#SPACEMAN PACKAGE", p->spac_file);
		fputs("[details]", p->spac_file);
		fprintf(p->spac_file, "name = %s\n", pack_name);

		p->sources = (FILE**) calloc (1, sizeof(FILE));
		
		//src/main.*
		char* main_file = (char*) malloc(100);

		sprintf(main_file, "%s/src/main.%s", pack_name, language_to_string(language));
		
		p->sources[0] = fopen(main_file, "w+");
		p->source_names[0] = main_file;

		free(main_file);

		if(p->sources[0] != NULL)
		{
			fprintf(p->sources[0], "//TODO: add licence header\n//Template file created by spaceman\n");
			fprintf(p->sources[0], "\n#include <stdio.h>\n");
			fprintf(p->sources[0], "int main(void)\n{");
			fprintf(p->sources[0], "	printf(\"Hello World\\n\");\n");
			fprintf(p->sources[0], "}\n");
		}
		else
			printf("Could not create %s/src/main.c\n", pack_name);

		return p;
	}
	//If dir exists
	else
	{
		free(p);
		return space_package_init(pack_name, language);
	}
}

space_package* space_package_init(char* pack_name, enum LANGUAGE language)
{
	space_package* p = (space_package *) malloc (sizeof(space_package));
	if(p == NULL)
		return NULL;

	//Variable assignment
	p->name = pack_name;
	p->language = language;

	//Make dirs
	struct stat s = {0};
	int dir_exists = stat(pack_name, &s);
	if(dir_exists != -1)
	{
		puts("Creating directories");
		//src
		char* src = (char*) malloc (100);
		strcpy(src, pack_name);
		strcat(src, "/src");
		mkdir(src, 0700);
		free(src);

		//build
		char* build = (char*) malloc (100);
		strcpy(build, pack_name);
		strcat(build, "/build");
		mkdir(build, 0700);
		free(build);


		char* spac_file_name = (char*) malloc (100);

		strcpy(spac_file_name, pack_name);
		strcat(spac_file_name, "/spaceman.toml");

		printf("Creating %s\n", spac_file_name);

	  p->spac_file = fopen(spac_file_name, "w+");
		free(spac_file_name);

		fputs("#SPACEMAN PACKAGE\n", p->spac_file);
		fputs("[details]\n", p->spac_file);
		fprintf(p->spac_file, "name = %s\n", pack_name);

		char* main_file = (char*) malloc(100);

		p->sources = (FILE**) calloc (1, sizeof(FILE));

		sprintf(main_file, "%s/src/main.%s", pack_name, language_to_string(language));
		p->sources[0] = fopen(main_file, "w+");
		free(main_file);

		if(p->sources[0] != NULL)
		{
			fprintf(p->sources[0], "//TODO: add licence header\n//Template file created by spaceman\n");
			fprintf(p->sources[0], "#include <stdio.h>\n");
			fprintf(p->sources[0], "int main(void)\n{");
			fprintf(p->sources[0], "	printf(\"Hello World\\n\");\n");
			fprintf(p->sources[0], "}\n");
		}
		else
			printf("Could not create %s/src/main.c\n", pack_name);
		return p;
	}
	else {
		free(p);
		return space_package_new(pack_name, LANGUAGE);
	}
}

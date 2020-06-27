#include "main.h"
#include "spaceman_package.h"

int main(int argc, char** argv)
{
	if (argc == 1) 
	{
		help(GENERAL);
		return 1;
	}

#define comp_arg(short_, long_) strcmp(argv[i], short_) == 0 || strcmp(argv[i], long_) == 0 
	int _help = 0;
	for (int i = 1; i < argc; i++)
	{
		if(comp_arg("-h", "help")) 
		{
			_help = 1;
		}
		else if(comp_arg("-n", "new"))
		{
			if(_help)
			{
				_help = 2;
				help(NEW);
			}
			else
				new(argv[i+1]);
		}
	}
	if(_help == 1)
	{
		help(GENERAL);
	}
	return 0;
}


void help(enum HELP_T help_type) 
{
	switch (help_type){
		case GENERAL:
			puts("Usage: spaceman <operation> <options>");
			puts("Operations");
			puts("	new | -n 	: creates a new project, requires a name.");
			puts("	init| -i	: creates a new project in current directory");
			puts("	help| -h	: prints this message");
			break;
		case NEW:
			puts("Creates a new project");
			puts("Usage: spaceman -n/new <project_name> <options>");
			break;
		default:
			help(GENERAL);
	}
}

void new(char* name) 
{
	printf("Making %s\n", name);
	spaceman_package* sp = spaceman_package_(name);
	spaceman_package_create(sp);
}


#include "main.h"

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		help(GENERAL);
		return 1;
	}
	enum LANGUAGE language = C;
	//Compare arguments
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
			{
				if (argc < i+1)
				{
					puts("Too few arguments");
					puts("For current directory or a directory that exits please use `init`");
				}
				else
				{
					spaceman_package *sp = spaceman_package_new(argv[i+1], language);
					if(sp == NULL)
						puts("Could not create package!");
					else
					{
						puts("Successfully created package.");
						free(sp);
					}
				}
		}
	}

	else if (comp_arg("-i", "init"))
	{
		if(_help)
		{
			_help = 2;
			help(INIT);
		}
		else
		{
			spaceman_package *sp;
			if(argc < i+2)
			{
				sp = spaceman_package_init(".", LANGUAGE);
			}
			else
			{
				sp = spaceman_package_init(argv[i+1], LANGUAGE);
			}

			if (sp == NULL)
			{
				puts("Failed to init package.");
			}
			else
			{
				//free(sp);
				puts("Successfully initilised package.");
			}
		}
	}

	else if (comp_arg("cxx", "c++"))
	{ language = CXX; }
}
#undef comp_arg

	if(_help)
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

#include "main.h"

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		help(GENERAL);
		return 1;
	}
	enum LANGUAGE language = C;
	space_package* (*create)(char* name, enum LANGUAGE l);
	space_package *sp;
	enum HELP_T h = GENERAL;
	char* name;

	//Compare arguments
#define comp_arg(short_, long_) strcmp(argv[i], short_) == 0 || strcmp(argv[i], long_) == 0
	int _help = 0;
	for (int i = 1; i < argc; i++) {
		//Help
		if(comp_arg("-h", "help")) {
			_help = 1;
		}
		
		//New
		else if(comp_arg("-n", "new")) {
			if(_help) {
				h=NEW;
			}
			else {
				if (argc < i+1) {
					puts("Too few arguments");
					puts("For current directory or a directory that exits please use `init`");
				}
				else {
					name = argv[i+1];
					create = space_package_new;
				}
			}
		}

		//Init
		else if (comp_arg("-i", "init")) {
		if(_help) {
			_help = 2;
			help(INIT);
		}
		else {
			if(argc < i+2)
				name = ".";
			else
				name = argv[i+1];
			create = space_package_init;
		}
	}

	//C++
	else if (comp_arg("cxx", "c++"))
		language = CXX;

	//Build
	else if (comp_arg("-b", "build")) {
		create = NULL;
	}
}
#undef comp_arg

	if(_help)
		help(GENERAL);
	else
    {
	    //Create package
	    if(create == NULL)
			return 0;
		else {
			sp = create(name, language);
			if(sp == NULL) {
				puts("Could not create package");
				return 1;
			} else
				puts("Successfully created package");
		}
    }
	return 0;
}


///@brief Help messages
///@param help_type type of help
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

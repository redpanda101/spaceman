#ifndef SPACE_BUILD_H__
#define SPACE_BUILD_H__

#include "space_package.h"

//Compiler type
//Holds info to compile like the compiler command ie gcc/g++
typedef struct compiler
{
  char *name, *optimisation, *debug_flag, *debuger;
} compiler;

//List of comonly used linux c/c++ compilers
struct
{
  compiler gcc;     //gcc
  compiler gpp;     //g++
  compiler clang;   //clang
  compiler clangpp; //clang++
} compiler_list = {
  {"gcc", "-O3", "-g", "gdb"},
  {"g++", "-O3", "-g", "gdb"},
  {"clang", "-O3", "-g", "lldb"},
  {"clang++", "-O3", "-g", "lldb"}
};

void build_package(space_package* package, compiler _compiler);

#endif

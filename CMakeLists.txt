cmake_minimum_required(VERSION 3.17)

project(spaceman)

if (CMAKE_BUILD_TYPE EQUAL "RELEASE")
  add_compile_options(-O3 -Wall -Wextra)
endif (CMAKE_BUILD_TYPE EQUAL "RELEASE")
add_executable(spaceman src/main.c src/lib/spaceman_package.c)

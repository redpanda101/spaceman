cmake_minimum_required(VERSION 3.16)

project(spaceman)

if (CMAKE_BUILD_TYPE EQUAL "RELEASE")
  add_compile_options(-O3 -Wall -Wextra)
endif (CMAKE_BUILD_TYPE EQUAL "RELEASE")

add_library(lspaceman src/lib/space_package.c src/lib/build.c)
add_executable(spaceman src/main.c)
target_link_libraries(spaceman lspaceman)

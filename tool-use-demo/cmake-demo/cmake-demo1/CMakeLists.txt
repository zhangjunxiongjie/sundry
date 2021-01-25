# CMake lower version
cmake_minimum_required (VERSION 3.16.3)

# project name
project (cmake_demo)

# find directory all .c file to DIR_SRCS
aux_source_directory (./ DIR_SRCS)

# object
add_executable (cmake_demo.out ${DIR_SRCS})



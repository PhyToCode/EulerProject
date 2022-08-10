cmake_minimum_required(VERSION 3.14)

# name of the project
project(EulerProject)

# include subdirectories
add_subdirectory(Programs)

# default build type
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()
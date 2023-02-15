################################################################################
# EulerProject - Philippe Pinçon and Ny Toby Andrianjatovo - 2022
################################################################################

cmake_minimum_required(VERSION 3.15)

# name of the project
project(EulerProject)

# include subdirectories
add_subdirectory(Programs)

# default build type
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()
## Copyright 2021 The Khronos Group
## SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.11)

message(STATUS "CMake version: ${CMAKE_VERSION}")

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_BUILD_TYPE_INIT Release)
set(CMAKE_INSTALL_MESSAGE LAZY)

project(anari-trace LANGUAGES C)

find_package(anari REQUIRED)
add_executable(${PROJECT_NAME} trace_wrapper.c)
target_link_libraries(${PROJECT_NAME} anari::anari)

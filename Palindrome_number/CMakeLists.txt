cmake_minimum_required(VERSION 3.0.0)
project(palyndrome_number VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(palyndrome_number main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

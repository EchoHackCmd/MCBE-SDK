cmake_minimum_required(VERSION 3.20)
project(MCBE_SDK VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)

add_library(MCBE_SDK)

target_sources(MCBE_SDK PRIVATE
    "Minecraft.cpp"
)

#include_directories(Classes Math Mem)

add_subdirectory(Classes)
add_subdirectory(Math)
add_subdirectory(Mem)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
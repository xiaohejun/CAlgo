cmake_minimum_required(VERSION 3.8)

set(This CAlgo)
project(${This} C CXX)


set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src DIR_SRCS)
message(${DIR_SRCS})
    
add_library(${This} STATIC ${DIR_SRCS})

add_subdirectory(googletest)
add_subdirectory(test)
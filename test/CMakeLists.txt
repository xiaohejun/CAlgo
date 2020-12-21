cmake_minimum_required(VERSION 3.8)

set(This CAlgoTests)

aux_source_directory(. DIR_SRCS)
add_executable(${This} ${DIR_SRCS})
target_link_libraries(${This} PUBLIC
    gtest_main
    CAlgo
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
cmake_minimum_required(VERSION 3.14)

project(TheBowlingGame CXX)

# ==== CONFIGURATION ====

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_TESTS "Build tests and show them in IDE" ON)


# ==== BUILDING TARGET ==== #

set(HEADERS
    game.h
)

set(CLASS_SOURCES
    game.cpp
)

list(TRANSFORM HEADERS PREPEND ${CMAKE_CURRENT_LIST_DIR}/src/)
list(TRANSFORM CLASS_SOURCES PREPEND ${CMAKE_CURRENT_LIST_DIR}/src/)

add_executable(${PROJECT_NAME} src/main.cpp ${HEADERS} ${CLASS_SOURCES})


# ==== TEST SUBMODULE ==== #

if(ENABLE_TESTS)
    add_subdirectory(tests)
endif()

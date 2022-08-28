cmake_minimum_required(VERSION 3.14)

project(TheBowlingGameTests CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# ==== DEPENDENCY MANAGEMENT ==== #

include(../3rd/cmake-conan-0.18.1/conan.cmake)

conan_cmake_configure(REQUIRES gtest/cci.20210126 GENERATORS cmake_find_package)

conan_cmake_autodetect(settings)
conan_cmake_install(
    PATH_OR_REFERENCE .
    BUILD missing
    REMOTE conancenter
    SETTINGS ${settings}
)

find_package(GTest CONFIG REQUIRED)


# ==== BUILDING TARGET ==== #

add_executable(${PROJECT_NAME} test.cpp ${CLASS_SOURCES})
target_link_libraries(${PROJECT_NAME} GTest::gtest_main)
target_include_directories(${PROJECT_NAME} PUBLIC ../src)

cmake_minimum_required(VERSION 3.20)
project(Big_Number)

set(CMAKE_CXX_STANDARD 23)
set(HEADERS generators.h)
set(SOURCES main.cpp generators.cpp tests.h tests.cpp)

add_subdirectory(testing/googletest)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gtest_main gtest gmock)
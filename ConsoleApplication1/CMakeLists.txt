cmake_minimum_required(VERSION 3.5)

project(ConsoleApplication1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
add_subdirectory(googletest)
target_link_libraries(test gtest gmock pthread)

add_executable(ConsoleApplication1 ConsoleApplication1.cpp "ipAdress.cpp" "ipAdress.h")
add_executable(test_ "Test.cpp")


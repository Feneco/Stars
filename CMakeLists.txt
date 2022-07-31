cmake_minimum_required(VERSION 3.0.0)
project(Stars VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)


find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_subdirectory(lib)

add_executable(Stars main.cpp)

target_link_libraries(Stars ${CURSES_LIBRARIES})
target_link_libraries(Stars skies)

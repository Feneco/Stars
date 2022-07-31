cmake_minimum_required(VERSION 3.0.0)
project(Stars VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Curses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
# Stars lib
add_subdirectory(lib)

add_executable(Stars main.cpp)

# Link Curses
target_link_libraries(Stars ${CURSES_LIBRARIES})
# Link Stars
target_link_libraries(Stars skies)

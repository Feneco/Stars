cmake_minimum_required(VERSION 3.0.0)
project(Stars VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add libraries
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_subdirectory(lib)

add_executable(Stars main.cpp)

# Link libraries
target_link_libraries(Stars ${CURSES_LIBRARIES} skies)
target_include_directories(Stars PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/lib"
                          )
                          
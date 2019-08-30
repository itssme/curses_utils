cmake_minimum_required(VERSION 3.9)
project(curses_utils)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lncurses")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

add_executable(curses_utils main.cpp curses_utils.h examples/example0_simple_menu.h)
target_link_libraries(curses_utils ${CURSES_LIBRARIES})
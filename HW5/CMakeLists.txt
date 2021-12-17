cmake_minimum_required(VERSION 3.16)

project("HW5")

set(CMAKE_CXX_FLAGS "-pthread -Wall -Wextra -fsanitize=undefined")

set(SRC main.cpp)

add_executable(hw5 ${SRC})

set_target_properties(
	hw5 PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)


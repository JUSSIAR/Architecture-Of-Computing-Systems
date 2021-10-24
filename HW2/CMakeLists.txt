cmake_minimum_required(VERSION 3.16)

project("HW2")

set(SRC main.cpp src/solution.cpp)

add_executable(hw2 ${SRC})

set_target_properties(
	hw2 PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

target_compile_features(hw2 PUBLIC cxx_std_17)
target_compile_options(hw2 PUBLIC -Wall -Wextra -Wshadow -Wconversion)

option(ENABLE_SANITIZERS OFF)
if(ENABLE_SANITIZERS)
  add_library(sanitizers INTERFACE)
  target_compile_options(sanitizers INTERFACE -fsanitize=address,undefined,leak)
  target_link_options(sanitizers INTERFACE -fsanitize=address,undefined,leak)
  target_link_libraries(hw2 PUBLIC sanitizers)
endif()
cmake_minimum_required(VERSION 3.16)

project("HW1")

add_subdirectory(src)

add_executable(hw1 tests.cpp)

set_target_properties(
	hw1 PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

target_compile_features(hw1 PUBLIC cxx_std_17)
target_compile_options(hw1 PUBLIC -Wall -Wextra -Wshadow -Wconversion)

option(ENABLE_SANITIZERS OFF)
if(ENABLE_SANITIZERS)
  add_library(sanitizers INTERFACE)
  target_compile_options(sanitizers INTERFACE -fsanitize=address,undefined,leak)
  target_link_options(sanitizers INTERFACE -fsanitize=address,undefined,leak)
  target_link_libraries(hw1 PUBLIC sanitizers)
endif()
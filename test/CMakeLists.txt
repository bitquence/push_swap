cmake_minimum_required(VERSION 3.22)

project(push_swap_test)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# targets: `libgtest` `libgmock` (static libraries)
include(${CMAKE_SOURCE_DIR}/fetch_gtest.cmake)

set(LIBRARY_DIR ${CMAKE_SOURCE_DIR}/..)
add_library(pushswap STATIC
  ${LIBRARY_DIR}/build/deque/constructor.o
  ${LIBRARY_DIR}/build/deque/destructor.o
  ${LIBRARY_DIR}/build/deque/push.o
  ${LIBRARY_DIR}/build/deque/pop.o
  ${LIBRARY_DIR}/build/deque/rotate.o
  ${LIBRARY_DIR}/build/deque/get.o
  ${LIBRARY_DIR}/build/deque/first_last.o
  ${LIBRARY_DIR}/build/deque/properties.o
  ${LIBRARY_DIR}/build/deque/unique.o
  ${LIBRARY_DIR}/build/deque/sort_unstable.o
  ${LIBRARY_DIR}/build/deque/ranked.o
  ${LIBRARY_DIR}/build/deque/cmp.o

  ${LIBRARY_DIR}/build/input/string_length.o
  ${LIBRARY_DIR}/build/input/parse_number.o

  ${LIBRARY_DIR}/build/operations.o

  ${LIBRARY_DIR}/build/problem/apply.o
  ${LIBRARY_DIR}/build/problem/opcode.o
)
set_target_properties(pushswap
  PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${LIBRARY_DIR}/include"
    LINKER_LANGUAGE "C"
)

add_executable(test_runner
  src/main.cpp
  src/deque.cpp
  src/parse_number.cpp
  src/operations.cpp
  src/problem.cpp
)

target_link_libraries(test_runner
  libgtest
  pushswap
)

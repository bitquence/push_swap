cmake_minimum_required(VERSION 3.22)

project(libbit)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# GoogleTest-specific build options
include(FetchContent)
FetchContent_Declare(googletest
  #QUIET
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        b514bdc898e2951020cbdca1304b75f5950d1f59 # release-1.15.2
)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(LIBRARY_DIR ..)
add_library(pushswap STATIC
  ${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/build/deque/constructor.o
  ${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/build/deque/destructor.o
  ${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/build/deque/push.o
  ${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/build/deque/pop.o
  ${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/build/deque/rotate.o
  ${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/build/deque/get.o
  ${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/build/deque/first_last.o
  ${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/build/deque/properties.o

  ${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/build/input/parse_number.o

  ${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/build/operations/swap.o
)
set_target_properties(pushswap
  PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/include"
    LINKER_LANGUAGE "C"
)

add_executable(test_runner
  src/deque.cpp
  src/parse_number.cpp
  src/operations.cpp
)

target_link_libraries(test_runner
  gtest_main
  pushswap
)

# Automatic discovery of tests
include(GoogleTest)
gtest_discover_tests(test_runner)

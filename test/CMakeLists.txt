cmake_minimum_required(VERSION 3.22)

project(libbit)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# GoogleTest-specific build options
include(FetchContent)
FetchContent_Declare(googletest
  #QUIET
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(LIBRARY_DIR ..)
add_library(pushswap STATIC
  ${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/build/deque/constructor.o
  ${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/build/deque/destructor.o
  ${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/build/deque/push.o
  ${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/build/deque/pop.o
  ${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/build/deque/get.o
  ${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/build/deque/properties.o

  ${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/build/input/parse_number.o
)
set_target_properties(pushswap
  PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/${LIBRARY_DIR}/include"
    LINKER_LANGUAGE "C"
)

add_executable(test_runner
  src/deque.cpp
  src/parse_number.cpp
)

target_link_libraries(test_runner
  gtest_main
  pushswap
)

# Automatic discovery of tests
include(GoogleTest)
gtest_discover_tests(test_runner)

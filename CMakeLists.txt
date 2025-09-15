cmake_minimum_required(VERSION 3.16)
project(A3ArrayReversal LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(main main.cpp)

# Catch 2
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.6.0  
)
FetchContent_MakeAvailable(Catch2)

add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# warnings
if (MSVC)
  target_compile_options(main PRIVATE /W4 /permissive-)
  target_compile_options(tests PRIVATE /W4 /permissive-)
else()
  target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic)
  target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic)
endif()

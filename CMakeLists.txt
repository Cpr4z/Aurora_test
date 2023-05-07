cmake_minimum_required(VERSION 3.22.1)
project(Aurora_test CXX)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wpedantic -Wextra -Werror ")
set(CMAKE_CXX_STANDARD 20)
add_subdirectory(src/core)

message("AURORA_TEST_LIB_LIBRARIES = ${AURORA_TEST_LIB_LIBRARIES}")
message("AURORA_TEST_LIB_INCLUDE_DIRS = ${AURORA_TEST_LIB_INCLUDE_DIRS}")

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${AURORA_TEST_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${AURORA_TEST_LIB_LIBRARIES})
cmake_minimum_required(VERSION 3.16)

project(algorithm)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(
    googletest
    # URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
    URL ${PROJECT_SOURCE_DIR}/thirdparty/googletest/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)
# file(GLOB ALGORITHM_SOURCE "${PROJECT_SOURCE_DIR}/source/algorithm/*.cpp")
# file(GLOB DATASTRUCT_SOURCE "${PROJECT_SOURCE_DIR}/source/datastruct/*.cpp")
file(GLOB LEETCODE_SOURCE "${PROJECT_SOURCE_DIR}/source/leetcode/*.cpp")
file(GLOB JIANZHIOFFER_SOURCE "${PROJECT_SOURCE_DIR}/source/jianzhioffer/*.cpp")
file(GLOB ALL_SOURCE
    # ${ALGORITHM_SOURCE}
    # ${DATASTRUCT_SOURCE}
    ${LEETCODE_SOURCE}
    ${JIANZHIOFFER_SOURCE}
)
add_executable(${PROJECT_NAME} ${ALL_SOURCE})
target_link_libraries(${PROJECT_NAME}
    gtest
    gtest_main
    gmock
    gmock_main
)
gtest_discover_tests(${PROJECT_NAME})
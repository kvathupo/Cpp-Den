################################################################################
#
#   @TODO:
#       - Clean-up version checking that was due to ubuntu pathing...
#
#   If unfamiliar with cmake, usage (where pwd has my code):
#       > mkdir ./build && cd build
#       > cmake ..
#       > cmake --build .
#       > ctest
#       > ./sqrt_test
#
################################################################################
cmake_minimum_required(VERSION 3.14)
project(CompileTime)

# set provided vars

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_BUILD_TYPE Release)

# set custom vars
add_library(common INTERFACE)
target_link_libraries(common INTERFACE GTest::gtest_main)
target_include_directories(common INTERFACE ${CMAKE_SOURCE_DIR}/include)
target_compile_features(common INTERFACE cxx_std_20)
target_compile_options(common INTERFACE -O3)

################################################################################
# 
#   Fetch third-party libraries:
#       * Google Benchmark
#           - Dependency: Google Test
#
################################################################################

include(FetchContent)

# Fetch Google Test
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Fetch Google Benchmark
FetchContent_Declare(
    benchmark
	GIT_REPOSITORY https://github.com/google/benchmark.git
	GIT_TAG v1.7.0
)
FetchContent_MakeAvailable(benchmark)

enable_testing()

add_executable(sqrt_test ${CMAKE_SOURCE_DIR}/test/sqrt_test.cpp)
target_link_libraries(sqrt_test common)
#target_include_directories(sqrt_test PRIVATE common)
#target_compile_features(sqrt_test PRIVATE common)
#target_compile_options(sqrt_test PRIVATE common)

add_executable(pow_test ${CMAKE_SOURCE_DIR}/test/pow_test.cpp)
#target_include_directories(pow_test PRIVATE common)
#target_compile_features(pow_test PRIVATE common)
#target_compile_options(pow_test PRIVATE common)
#target_link_libraries(pow_test GTest::gtest_main)
target_link_libraries(pow_test common)


include(GoogleTest)
gtest_discover_tests(sqrt_test)

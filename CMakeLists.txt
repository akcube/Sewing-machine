# Works with 3.11 and tested through 3.23
cmake_minimum_required(VERSION 3.11...3.23)

# Project name and a few useful settings. Other commands can pick up the results
project(
  SEWING_MACHINE
  VERSION 1
  DESCRIPTION "A parallelized implemetation of Needleman-Wunsch and more"
  LANGUAGES CXX)

# Make all the libraries created go to /build/lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# The SewingMachine library code is here
add_subdirectory(src)

# Contains all the benchmarking code
add_subdirectory(benchmarks)

# Make sure the Google benchmark package is available
find_package(benchmark REQUIRED)
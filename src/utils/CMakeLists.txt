# Creates the utils lib 
add_library(util_lib utils.cpp)

# We need this directory, and users of our library will need it too
target_include_directories(util_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set optimization flags
target_compile_options(util_lib PRIVATE -O3 -ffast-math -mavx2 -fopenmp -march=native)

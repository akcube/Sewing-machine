# Creates the utils lib 
add_library(base_lib base.cpp)

# We need this directory, and users of our library will need it too
target_include_directories(base_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set optimization flags
target_compile_options(base_lib PRIVATE -O3 -ffast-math -mavx2 -fopenmp -march=native)


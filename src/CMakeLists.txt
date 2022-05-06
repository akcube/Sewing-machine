# Compile util functions
add_subdirectory(utils)

# Creates the library 
add_library(sewingmachine needle.cpp)

# Link necessary libs
target_link_libraries(sewingmachine PRIVATE gomp util_lib)

# We need this directory, and users of our library will need it too
target_include_directories(sewingmachine PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Compiles with optimization flags
target_compile_options(sewingmachine PRIVATE -O3 -ffast-math -mavx2 -fopenmp -march=native)





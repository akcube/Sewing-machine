# Compile util functions
add_subdirectory(utils)

# Create an interface library containing an interface to all required libs 
add_library(intlib INTERFACE)
target_link_libraries(intlib INTERFACE gomp util_lib)

# Creates the library 
add_library(sewingmachine needle.cpp)

# We need this directory, and users of our library will need it too
target_include_directories(sewingmachine PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Compiles with optimization flags
target_compile_options(sewingmachine PRIVATE -O3 -ffast-math -mavx2 -fopenmp -march=native)





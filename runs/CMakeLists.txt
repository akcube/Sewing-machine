# Makes the binary go to /build/bin/benchmarks
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/benchmarks)

# Create an interface library containing an interface to all required libs 
add_library(allbenchlib INTERFACE)
target_link_libraries(allbenchlib INTERFACE gomp sewingmachine util_lib benchmark::benchmark)

set(BENCH_EXECUTABLES 
	bench1)

# Create the targets
foreach(exec ${BENCH_EXECUTABLES})
	add_executable(${exec} ${exec}.cpp)

	# Allow it to find helper.cpp
	target_include_directories(${exec} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

	# Link it with all the required libs using the interface lib we made
	target_link_libraries(${exec} allbenchlib)

	# Compile it with the following compiler flags
	target_compile_options(${exec} PRIVATE -O3 -mavx2 -fopenmp -march=native)
endforeach()
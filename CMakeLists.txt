cmake_minimum_required(VERSION 2.6)
project(bearRPC)


set(CXX_FLAGS
        -fno-omit-frame-pointer # linux perf
        -Wall
        -std=c++17
        -march=native
        -rdynamic)
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
message(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src/RPC
	${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR})
# add_subdirectory(3rd/tinyev )
# add_subdirectory(3rd/jackson)
add_subdirectory(src/RPC)

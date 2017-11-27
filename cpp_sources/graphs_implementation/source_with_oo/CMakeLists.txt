cmake_minimum_required(VERSION 3.8)
project(source_with_oo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        reading_a_graph/driver_file.cpp
        reading_a_graph/edge_node.cpp
        reading_a_graph/edge_node.hpp
        reading_a_graph/graph.cpp
        reading_a_graph/graph.hpp)

add_executable(source_with_oo ${SOURCE_FILES})
cmake_minimum_required(VERSION 4.1)
project(S2_EXTRA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(S2_EXTRA
        Movie.cpp
        Movie.h
        MovieSeries.cpp
        MovieSeries.h
        S2_EXTRA.cpp)

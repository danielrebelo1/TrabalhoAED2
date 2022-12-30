cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled
        Code/main.cpp
        Code/Airport.cpp
        Code/Airport.h
        Code/Airline.cpp
        Code/Airline.h
        Code/FileReader.cpp
        Code/FileReader.h
        Code/City.cpp
        Code/City.h
        Code/Location.h
        Code/Location.cpp
        Code/Graph.cpp
        Code/Graph.h
        Code/Flight.cpp
        Code/Flight.h
        Code/Coordinates.cpp Code/Coordinates.h)

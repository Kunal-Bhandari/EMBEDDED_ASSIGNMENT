cmake_minimum_required(VERSION 3.5)

# project name
project(embeddedAssignment)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# include directories from openCV
include_directories(${OpenCV_INCLUDE_DIRS})

# Adding the executable 1 that needs to run the inbuilt resize function of the OpenCV library
add_executable(embeddedAssignment src/main.cpp)

# linking OpenCV libraries
target_link_libraries(embeddedAssignment ${OpenCV_LIBS})
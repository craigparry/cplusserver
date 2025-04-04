cmake_minimum_required(VERSION 3.10)

project(MyProject)

set(CMAKE_CXX_STANDARD 17)

# Add all .cpp files in the current directory
file(GLOB SOURCES "*.cpp")

# Add all .cpp files in the 'desserts' subdirectory
file(GLOB MORE_SOURCES "desserts/*.cpp")

# Combine the sources from the current directory and the 'desserts' directory
list(APPEND SOURCES ${MORE_SOURCES})

# Create the executable
add_executable(my_program ${SOURCES})
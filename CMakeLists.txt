# cmake_minimum_required(VERSION 3.10)

# project(MyProject)

# set(CMAKE_CXX_STANDARD 17)

# # Add all .cpp files in the current directory
# file(GLOB SOURCES "*.cpp")

# # Add all .cpp files in the 'desserts' subdirectory
# file(GLOB MORE_SOURCES "desserts/*.cpp")

# # Combine the sources from the current directory and the 'desserts' directory
# list(APPEND SOURCES ${MORE_SOURCES})

# # Create the executable
# add_executable(my_program ${SOURCES})

# cmake_minimum_required(VERSION 3.14)
# project(MyWebSocketApp)

# set(CMAKE_CXX_STANDARD 17)

# # Specify the vcpkg toolchain file to find dependencies
# # set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE PATH "Path to vcpkg toolchain file" FORCE)
# # set(VCPKG_TARGET_TRIPLET arm64-osx CACHE STRING "vcpkg triplet" FORCE)
# set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${CMAKE_SOURCE_DIR}/vcpkg_installed/arm64-osx/share")

# # Find Oat++ package (via vcpkg or other method)
# find_package(oatpp CONFIG REQUIRED)

# # Include source files
# file(GLOB SOURCES "*.cpp")

# # Add the executable
# add_executable(server ${SOURCES})

# # Link Oat++ and any other dependencies
# # target_link_libraries(server PRIVATE oatpp::oatpp)
# target_link_libraries(server PRIVATE oatpp::oatpp oatpp::oatpp-test)

cmake_minimum_required(VERSION 3.24)
project(my-app VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 20)

# add_subdirectory(external/uWebsockets)
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${CMAKE_SOURCE_DIR}/vcpkg_installed/arm64-osx/share")
find_package(unofficial-uwebsockets CONFIG REQUIRED)


add_executable(my-app main.cpp)
# target_link_libraries(my-app PRIVATE uwebsockets::uwebsockets)
target_link_libraries(my-app PRIVATE unofficial::uwebsockets::uwebsockets)
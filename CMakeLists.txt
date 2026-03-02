cmake_minimum_required(VERSION 3.15)
project(rapidfuzz-php)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find PHP
find_package(PHP REQUIRED)

# Include rapidfuzz-cpp
add_subdirectory(vendor/rapidfuzz-cpp rapidfuzz-build)

# PHP Extension source files
set(SOURCES
    src/rapidfuzz.cpp
)

# Create shared extension
PHP_ADD_EXTENSION(rapidfuzz ${SOURCES})

# Include directories
target_include_directories(rapidfuzz PRIVATE
    ${PHP_INCLUDE_DIRS}
    vendor/rapidfuzz-cpp
)

# Link rapidfuzz library
target_link_libraries(rapidfuzz PRIVATE rapidfuzz::rapidfuzz)

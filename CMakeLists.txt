cmake_minimum_required(VERSION 3.20)

project(zarr VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINE_HIDDEN ON)

option(BUILD_TESTS "build tests" ON)

find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)

add_subdirectory(src)

if (BUILD_TESTS)
    include(CTest)
    add_subdirectory(tests)
endif()
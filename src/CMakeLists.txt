set(TARGET_NAME zarr)
set(PUBLIC_HEADERS_DIR ${CMAKE_SOURCE_DIR}/include/zarr)

set(SOURCE_CODE
    metadata.cpp
    names.hpp
    storage/directory_store.cpp
    storage/store.cpp
    storage/store.hpp
    zarr.cpp
    zarr_array.cpp
)

set(PUBLIC_HEADERS
    "${PUBLIC_HEADERS_DIR}/directory_store.hpp"
    "${PUBLIC_HEADERS_DIR}/errors.hpp"
    "${PUBLIC_HEADERS_DIR}/metadata.hpp"
    "${PUBLIC_HEADERS_DIR}/zarr.hpp"
    "${PUBLIC_HEADERS_DIR}/zarr_array.hpp"
)

add_library(${TARGET_NAME} ${SOURCE_CODE})

target_include_directories(${TARGET_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/matlib>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>
)

target_link_libraries(${TARGET_NAME} PRIVATE
  fmt::fmt
  nlohmann_json::nlohmann_json
)

set_target_properties(${TARGET_NAME} PROPERTIES
    OUTPUT_NAME ${TARGET_NAME}
    PUBLIC_HEADER "${PUBLIC_HEADERS}"
)

if (BUILD_SHARED_LIBS)
    set_target_properties(${TARGET_NAME} PROPERTIES
        VERSION ${zarr_VERSION_MAJOR}.${zarr_VERSION_MINOR}.${zarr_VERSION_PATCH}
        SOVERSION ${zarr_VERSION_MAJOR}
    )
endif()

include(GenerateExportHeader)
generate_export_header(${TARGET_NAME})
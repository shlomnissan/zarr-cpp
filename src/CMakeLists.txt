set(PUBLIC_HEADERS_DIR ${CMAKE_SOURCE_DIR}/include/zarr)

set(SOURCE_CODE
    metadata.cpp
    store_filesystem.cpp
    store_filesystem.hpp
    zarr.cpp
)

set(PUBLIC_HEADERS
    ${PUBLIC_HEADERS_DIR}/metadata.hpp
    ${PUBLIC_HEADERS_DIR}/store.hpp
    ${PUBLIC_HEADERS_DIR}/zarr.hpp
)

if(NOT_APPLE)
    set(CMAKE_INSTALL_RPATH "$ORIGIN")
endif()

find_package(nlohmann_json CONFIG REQUIRED)

add_library(${PROJECT_NAME} ${SOURCE_CODE} ${PUBLIC_HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${zarr_VERSION_MAJOR}.${zarr_VERSION_MINOR}.${zarr_VERSION_PATCH}
    SOVERSION ${zarr_VERSION_MAJOR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    nlohmann_json::nlohmann_json
)

include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME})

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    VERSION ${zarr_VERSION_MAJOR}.${zarr_VERSION_MINOR}.${zarr_VERSION_PATCH}
    COMPATIBILITY SameMajorVersion
)

set(CONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
configure_package_config_file(
    "${CMAKE_SOURCE_DIR}/cmake/Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION ${CONFIG_INSTALL_DIR}
)

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT {PROJECT_NAME}_runtime
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        COMPONENT {PROJECT_NAME}_runtime
        NAMELINK_COMPONENT {PROJECT_NAME}_development
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY "${PUBLIC_HEADERS_DIR}/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}"
    FILES_MATCHING PATTERN "*.hpp"
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_export.h"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${CONFIG_INSTALL_DIR}
)

install(
    EXPORT ${PROJECT_NAME}
    DESTINATION ${CONFIG_INSTALL_DIR}
    NAMESPACE ${PROJECT_NAME}::
)
set(BUILD_GMOCK OFF CACHE BOOL "")

find_package(GTest REQUIRED)

file(GLOB TEST_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/**/*.cpp"
)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)

foreach(TEST IN LISTS TEST_SOURCES)
    get_filename_component(FILE_NAME ${TEST} NAME)
    string(REGEX REPLACE "\\.[^.]*$" "" NAME_NO_EXT ${FILE_NAME})
    message(STATUS "🧪 Adding test ${FILE_NAME}")

    set(TEST_TARGET run_${NAME_NO_EXT})
    add_executable(${TEST_TARGET} ${TEST})
    target_link_libraries(${TEST_TARGET} PRIVATE GTest::gtest GTest::gtest_main zarr)
    add_test(${NAME_NO_EXT} ${TEST_TARGET})

    add_custom_command(
        TARGET ${TEST_TARGET} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/fixtures
        $<TARGET_FILE_DIR:${TEST_TARGET}>/fixtures
    )
endforeach()
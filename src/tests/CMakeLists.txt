# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

cmake_minimum_required( VERSION ${CMAKE_VERSION} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Project Name
set( PROJECT_NAME "zero-async.tests" )

# Configure Project
project( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C CXX )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_ASYNC_TESTS_PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/" )
set( ZERO_ASYNC_TESTS_HEADERS
    "" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_ASYNC_TESTS_PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/" )
set( ZERO_ASYNC_TESTS_SOURCES
    "${ZERO_ASYNC_TESTS_PRIVATE}async_test.cpp" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Add Executable Object
add_executable( zero_async_tests ${ZERO_ASYNC_TESTS_HEADERS} ${ZERO_ASYNC_TESTS_SOURCES} )

# Configure Executable Object
set_target_properties( zero_async_tests PROPERTIES
    VERSION ${PROJECT_VERSION}
    RUNTIME_OUTPUT_DIRECTORY ${ZERO_OUTPUT_DIR} )

# Link with zero-async
target_include_directories( zero_async_tests PUBLIC "${ZERO_ASYNC_CORE_INCLUDE_DIR}" )
target_include_directories( zero_async_tests PUBLIC "${ZERO_ASYNC_PLATFORM_INCLUDE_DIR}" )
target_link_libraries( zero_async_tests zero_async )

# Link with googletest
target_include_directories( zero_async_tests PUBLIC "${GTEST_INCLUDE_DIR}" )
target_link_libraries( zero_async_tests gtest_main )

add_test( core_test zero_async_tests )
message( STATUS "${PROJECT_NAME} - tests are built" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

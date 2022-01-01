# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

if ( NOT DEFINED PROJECT_CMAKE_VERSION )
	set( PROJECT_CMAKE_VERSION 3.16 )
endif ( NOT DEFINED PROJECT_CMAKE_VERSION )

cmake_minimum_required( VERSION ${PROJECT_CMAKE_VERSION} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONFIGS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Project Name
set( PROJECT_NAME "zero-async" )

# Project Version
set( PROJECT_VERSION 0.1 )

if ( NOT DEFINED PLATFORM )
	message( FATAL_ERROR "${PROJECT_NAME} - <PLATFORM> not configured" )
endif ( NOT DEFINED PLATFORM )

if ( NOT DEFINED ZERO_CONFIG_INCLUDE_DIR )
    message( FATAL_ERROR "${PROJECT_NAME} - <ZERO_CONFIG_INCLUDE_DIR> not configured" )
endif ( NOT DEFINED ZERO_CONFIG_INCLUDE_DIR )

if ( NOT DEFINED ZERO_OUTPUT_DIR )
    message( FATAL_ERROR "${PROJECT_NAME} - <ZERO_OUTPUT_DIR> not configured" )
endif ( NOT DEFINED ZERO_OUTPUT_DIR )

if ( NOT DEFINED ZERO_LOGGER_INCLUDE_DIR )
    message( FATAL_ERROR "${PROJECT_NAME} - <ZERO_LOGGER_INCLUDE_DIR> not configured" )
endif ( NOT DEFINED ZERO_LOGGER_INCLUDE_DIR )

# Tests
if ( NOT DEFINED ZERO_TEST_ENABLED )
    message( STATUS "${PROJECT_NAME} - enabling tests by default. Use <ZERO_TEST_ENABLED> to disable it" )
    set( ZERO_TEST_ENABLED ON )
endif ( NOT DEFINED ZERO_TEST_ENABLED )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Configure Project
project( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C CXX )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# MODULES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Core
include( "${CMAKE_CURRENT_SOURCE_DIR}/src/lib/core/core.cmake" )

# Platform
include( "${CMAKE_CURRENT_SOURCE_DIR}/src/lib/${PLATFORM}/${PLATFORM}.cmake" )

# Tests
if ( ZERO_TEST_ENABLED )
    add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/src/tests" )
endif ( ZERO_TEST_ENABLED )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

if ( ZERO_BUILD_TYPE STREQUAL "STATIC" )
    # Add STATIC Library Object
    add_library( zero_async STATIC ${ZERO_ASYNC_SOURCES} )
elseif ( ZERO_BUILD_TYPE STREQUAL "SHARED" )
    # Add SHARED Library Object
    add_library( zero_async SHARED ${ZERO_ASYNC_SOURCES} )

    # Configure SHARED Library Object
    set_target_properties( zero_async PROPERTIES
        VERSION ${PROJECT_VERSION}
        LIBRARY_OUTPUT_NAME "zero_async"
        RUNTIME_OUTPUT_DIRECTORY "${ZERO_OUTPUT_DIR}"
        ARCHIVE_OUTPUT_DIRECTORY "${ZERO_OUTPUT_DIR}"
        LIBRARY_OUTPUT_DIRECTORY "${ZERO_OUTPUT_DIR}" )
endif ( ZERO_BUILD_TYPE STREQUAL "STATIC" )

# Link with zero-config
target_include_directories( zero_async PUBLIC "${ZERO_CONFIG_INCLUDE_DIR}" )

# Link with zero-logger
if ( DEBUG )
    target_include_directories( zero_async PUBLIC "${ZERO_LOGGER_INCLUDE_DIR}" )
    target_link_libraries( zero_async zero_logger )
endif ( DEBUG )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

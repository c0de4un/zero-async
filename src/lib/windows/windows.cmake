# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_ASYNC_WINDOWS_PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/lib/windows/public/zero/zero/windows/" )
set( ZERO_ASYNC_HEADERS ${ZERO_ASYNC_HEADERS}
	"${ZERO_ASYNC_WINDOWS_PUBLIC}async/WinMutex.hpp" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_ASYNC_WINDOWS_PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/lib/windows/private/zero/windows/" )
set( ZERO_ASYNC_SOURCES ${ZERO_ASYNC_SOURCES}
	"${ZERO_ASYNC_WINDOWS_PRIVATE}async/WinMutex.cpp" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_ASYNC_CORE_PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/lib/core/public/zero/core/" )
set( ZERO_ASYNC_HEADERS
	"${ZERO_ASYNC_CORE_PUBLIC}async/SharedLock.hpp"
	"${ZERO_ASYNC_CORE_PUBLIC}async/SpinLock.hpp"
	"${ZERO_ASYNC_CORE_PUBLIC}async/ILock.hxx"
	"${ZERO_ASYNC_CORE_PUBLIC}async/IMutex.hxx"
	"${ZERO_ASYNC_CORE_PUBLIC}async/BaseMutex.hpp" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ZERO_ASYNC_CORE_PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/lib/core/private/zero/core/" )
set( ZERO_ASYNC_SOURCES
	"${ZERO_ASYNC_CORE_PRIVATE}async/SharedLock.cpp"
	"${ZERO_ASYNC_CORE_PRIVATE}async/SpinLock.cpp"
	"${ZERO_ASYNC_CORE_PRIVATE}async/BaseMutex.cpp" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

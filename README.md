# zero-async
Async Library. Part of zeroEngine. Designed for mobile ecs strategy

# Features
 * STL compatable;
 * lightweight;
 * flexable for statistics & default behavior override (integrate with UE adapter);
 * Use native platform tools without whole STL baggage;
 * shared mutex support;
 * Spin lock support;

# Requirements
 * C++ 14+;
 * CMake;

# Examples
## Mutex
```C++
#include <zero/core/cfg/zero_mutex.hpp>

int main()
{
	zMutex mutex;
	mutex.lock();
}
```

## Lock
```C++
#include <zero/core/cfg/zero_mutex.hpp>

int main()
{
	zMutex mutex;
	zLock lock(mutex);
}
```

## Shared
```C++
#include <zero/core/cfg/zero_mutex.hpp>

int main()
{
	zMutex mutex;
	mutex.try_lock_shared();
}
```

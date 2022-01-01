// All rights reserved.
// License: see LICENSE.txt
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must display the names 'Denis Zyamaev' and
// in the credits of the application, if such credits exist.
// The authors of this work must be notified via email (code4un@yandex.ru) in
// this case of redistribution.
// 3. Neither the name of copyright holders nor the names of its contributors
// may be used to endorse or promote products derived from this software
// without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
// IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
// BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// HEADER
#ifndef ZERO_WIN_MUTEX_HPP
#include "../../../../public/zero/windows/async/WinMutex.hpp"
#endif /// !ZERO_WIN_MUTEX_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// WinMutex
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

	namespace win
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// CONSTRUCTOR & DESTRUCTOR
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		WinMutex::WinMutex()
			: mHandler(),
			mWrite()
		{
			InitializeCriticalSection(&mHandler);
		}

		WinMutex::~WinMutex() ZERO_NOEXCEPT
		{
			DeleteCriticalSection(&mHandler);
		}

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// IMutex: GETTERS & SETTERS
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		void* WinMutex::native_handle() ZERO_NOEXCEPT
		{ return static_cast<void*>(&mHandler); }

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// IMutex: METHODS
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		void WinMutex::lock()
		{
			mLocked = true;

			if (mWrite.test_and_set())
				EnterCriticalSection(&mHandler);
		}

		void WinMutex::lock_shared()
		{
			if (mLocked && mWrite.test_and_set())
				lock();
		}

		bool WinMutex::try_lock() ZERO_NOEXCEPT
		{
			if (mLocked)
				return false;

			try { lock(); }
			catch(...) { return false; }

			return true;
		}

		bool WinMutex::try_lock_shared() ZERO_NOEXCEPT
		{
			if (mLocked)
				return false;

			try { lock_shared(); }
			catch(...) { return false; }

			return true;
		}

		void WinMutex::unlock() ZERO_NOEXCEPT
		{
			if (mWrite.test_and_set())
				LeaveCriticalSection(&mHandler);

			mWrite.clear();
			mLocked = false;
		}

		void WinMutex::unlock_shared() ZERO_NOEXCEPT
		{
			unlock();
		}

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	}

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

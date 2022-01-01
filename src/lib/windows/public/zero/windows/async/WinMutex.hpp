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

#ifndef ZERO_WIN_MUTEX_HPP
#define ZERO_WIN_MUTEX_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::core::BaseMutex
#ifndef ZERO_CORE_BASE_MUTEX_HPP
#include "../../../../../core/public/zero/core/async/BaseMutex.hpp"
#endif /// !ZERO_CORE_BASE_MUTEX_HPP

// Include Windows API
#ifndef ZERO_WINDOWS_HPP
#include "../cfg/zero_windows.hpp"
#endif /// !ZERO_WINDOWS_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

	namespace win
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// WinMutex
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		/*!
		 \brief Mutex implementatopm for Windows platform, based on CRITICAL_SECTION API

		 \version 1.0
		*/
		ZERO_API class WinMutex final : public zBaseMutex
		{

		private:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// TYPES
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			using mutex_t = CRITICAL_SECTION;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// FIELDS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/* CRITICAL_SECTION */
			mutex_t mHandler;
			zFlag mWrite;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// DELETED
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			WinMutex(const WinMutex&) = delete;
			WinMutex(WinMutex&&)      = delete;

			WinMutex& operator=(const WinMutex&) = delete;
			WinMutex& operator=(WinMutex&&)      = delete;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		public:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// CONSTRUCTOR & DESTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			explicit WinMutex();
			
			/*!
			 \brief WinMutex destructor

			 \throws - no exceptions
			*/
			virtual ~WinMutex() ZERO_NOEXCEPT;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// IMutex: GETTERS & SETTERS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/*!
			\brief Returns native mutex

			\throws - no exceptions
			*/
			virtual void* native_handle() ZERO_NOEXCEPT final;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// IMutex: METHODS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			virtual void lock() final;

			virtual void lock_shared() final;

			/*!
			\brief Safely lock

			\throws - no exceptions
			\returns - 'true' if success. 'false' if failed or already locked
			*/
			virtual bool try_lock() ZERO_NOEXCEPT final;

			/*!
			\brief Lock for read
			Actual lock is called only if write-operation is in progress

			\throws - no exceptions
			\returns - 'true' if success. 'false' if failed or already locked
			*/
			virtual bool try_lock_shared() ZERO_NOEXCEPT final;

			virtual void unlock() ZERO_NOEXCEPT final;

			virtual void unlock_shared() ZERO_NOEXCEPT final;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		}; /// zero::win::WinMutex

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	}

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !ZERO_WIN_MUTEX_HPP

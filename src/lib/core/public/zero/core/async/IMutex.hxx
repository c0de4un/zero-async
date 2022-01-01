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

#ifndef ZERO_CORE_I_MUTEX_HXX
#define ZERO_CORE_I_MUTEX_HXX

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include zero::api
#ifndef ZERO_API_HPP
#include <zero/core/cfg/zero_api.hpp>
#endif // !ZERO_API_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// TYPES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace zero
{

	namespace core
	{

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		// zero::core::IMutex
		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		/*
		 \brief IMutex - behavior contract for mutex

		  Designed to be compatable with STL mutex API users

		 \version 1.0
		*/
		ZERO_API class IMutex
		{


		public:

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// DESTRUCTOR
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/*!
			 \brief IMutex destructor

			 \throws - no exceptions
			*/
			virtual ~IMutex() ZERO_NOEXCEPT = default;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// GETTERS & SETTERS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			/*!
			 \brief Is locked

			 \thread_safety - atomics used
			 \throws - no exceptions
			*/
			virtual bool isLocked() const ZERO_NOEXCEPT = 0;

			/*!
			 \brief Returns native mutex

			 \throws - no exceptions
			*/
			virtual void* native_handle() ZERO_NOEXCEPT = 0;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			// METHODS
			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			virtual void lock() = 0;

			virtual void lock_shared() = 0;

			/*!
			 \brief Safely lock

			 \throws - no exceptions
			 \returns - 'true' if success. 'false' if failed or already locked
			*/
			virtual bool try_lock() ZERO_NOEXCEPT = 0;

			/*!
			 \brief Lock for read
			  Actual lock is called only if write-operation is in progress

			 \throws - no exceptions
			 \returns - 'true' if success. 'false' if failed or already locked
			*/
			virtual bool try_lock_shared() ZERO_NOEXCEPT = 0;

			virtual void unlock() ZERO_NOEXCEPT = 0;

			virtual void unlock_shared() ZERO_NOEXCEPT = 0;

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

		}; /// zero::core::IMutex

		// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	} /// zero::core

} /// zero

using zIMutex = zero::core::IMutex;
#define ZERO_CORE_I_MUTEX_DECL

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif // !ZERO_CORE_I_MUTEX_HXX

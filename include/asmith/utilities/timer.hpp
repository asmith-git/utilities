//	Copyright 2017 Adam Smith
//	Licensed under the Apache License, Version 2.0 (the "License");
//	you may not use this file except in compliance with the License.
//	You may obtain a copy of the License at
// 
//	http://www.apache.org/licenses/LICENSE-2.0
//
//	Unless required by applicable law or agreed to in writing, software
//	distributed under the License is distributed on an "AS IS" BASIS,
//	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//	See the License for the specific language governing permissions and
//	limitations under the License.

#ifndef ASMITH_UTILITIES_HPP
#define ASMITH_UTILITIES_HPP

#include <cstdint>
#include <chrono>

namespace asmith {
	
	template<class FORMAT = std::chrono::milliseconds>
	class timer {
	private:
		int64_t mElapsedTime;
		int64_t mPausedSince;
		int64_t mRunningSince;

		static inline int64_t get_time() throw() {
			return std::chrono::duration_cast<FORMAT>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
		}
	public:
		timer() throw() :
			mElapsedTime(0),
			mPausedSince(0),
			mRunningSince(0)
		{}

		inline bool is_running() const throw() {
			return mRunningSince != 0;
		}

		inline bool is_paused() const throw() {
			return mPausedSince != 0;
		}

		inline bool is_stopped() const throw() {
			return mRunningSince == 0 && mPausedSince == 0;
		}

		bool start() throw() {
			if(! is_stopped()) return false;
			mElapsedTime = 0;
			mPausedSince = 0;
			mRunningSince = get_time();
			return true;
		}

		bool stop() throw() {
			if(is_stopped()) return false;
			pause();
			mPausedSince = 0;
			mRunningSince = 0;
			return true;
		}

		bool pause() throw() {
			if(! is_running()) return false;
			mPausedSince = get_time();
			mElapsedTime += mPausedSince - mRunningSince;
			mRunningSince = 0;
			return true;
		}

		bool resume() throw() {
			if(! is_paused()) return false;
			mRunningSince = get_time();
			mPausedSince = 0;
			return true;
		}

		inline int64_t get_elapsed_time() const throw() {
			return is_running() ? mElapsedTime + (get_time() - mRunningSince) : mElapsedTime;
		}
	};
}
#endif
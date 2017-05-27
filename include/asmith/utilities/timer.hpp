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
	
	/*!
		\brief A simple timer interface with a pause/resume feature.
		\version 1.0
		\data Created : 27th May 2017 Modified : 27th May 2017
		\author Adam Smith
	*/
	class timer_interface {
	public:
		/*!
			\brief Destroy the timer.
		*/
		virtual ~timer_interface() {}

		/*!
			\brief Check if the timer is running.
			\return True if the timer is not currently paused or stopped.
		*/
		virtual bool is_running() const throw() = 0;

		/*!
			\brief Check if the timer is paused.
			\return True if the timer is currently running or stopped.
		*/
		virtual bool is_paused() const throw() = 0;

		/*!
			\brief Check if the timer is stopped.
			\return True if the timer is currently running or paused.
		*/
		virtual bool is_stopped() const throw() = 0;

		/*!
			\brief Start the timer.
			\detail The time must be in the stopped state.
			\return True if the timer was sucessfully started.
			\see is_stopped
			\see stop
		*/
		virtual bool start() throw() = 0;

		/*!
			\brief Stop the timer.
			\detail The time must not be in the stopped state. The elapsed time can still be obtained on a stopped timer.
			\return True if the timer was sucessfully stopped.
			\see is_stopped
		*/
		virtual bool stop() throw() = 0;

		/*!
			\brief Pause the timer.
			\detail The time must be in the running state.
			\return True if the timer was sucessfully paused.
			\see is_running
		*/
		virtual bool pause() throw() = 0;

		/*!
			\brief Unpause the timer.
			\detail The time must be in the paused state.
			\return True if the timer was sucessfully resumed.
			\see is_paused
		*/
		virtual bool resume() throw() = 0;

		/*!
			\brief Check how long the timer has been running for.
			\detail Will work in any timer state.
			\return The total run duration of the timer.
		*/
		virtual int64_t get_elapsed_time() const throw() = 0;
	};
	
	/*!
		\brief A simple timer implementation with a pause/resume feature.
		\tparam FORMAT The measurement unit of the timer, can be any std::chrono::duration class. Default value is milliseconds
		\version 1.1
		\data Created : 27th May 2017 Modified : 27th May 2017
		\author Adam Smith
	*/
	template<class FORMAT = std::chrono::milliseconds>
	class timer : public timer_interface {
	private:
		int64_t mElapsedTime;	//!< Total time since the timer was started
		int64_t mPausedSince;	//!< The time that the timer was paused, otherwise 0
		int64_t mRunningSince;	//!< The time that the timer started or resumed, otherwise 0

		/*!
			\brief Obtain the current time.
			\return The current time.
		*/
		static inline int64_t get_time() throw() {
			return std::chrono::duration_cast<FORMAT>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
		}
	public:
		/*!
			\brief Create a new timer
		*/
		timer() throw() :
			mElapsedTime(0),
			mPausedSince(0),
			mRunningSince(0)
		{}
		
		// Inherited from timer_interface

		bool is_running() const throw() override {
			return mRunningSince != 0;
		}

		bool is_paused() const throw() override {
			return mPausedSince != 0;
		}

		bool is_stopped() const throw() {
			return mRunningSince == 0 && mPausedSince == 0;
		}

		bool start() throw() override {
			if(! is_stopped()) return false;
			mElapsedTime = 0;
			mPausedSince = 0;
			mRunningSince = get_time();
			return true;
		}

		bool stop() throw() override {
			if(is_stopped()) return false;
			pause();
			mPausedSince = 0;
			mRunningSince = 0;
			return true;
		}

		bool pause() throw() override {
			if(! is_running()) return false;
			mPausedSince = get_time();
			mElapsedTime += mPausedSince - mRunningSince;
			mRunningSince = 0;
			return true;
		}

		bool resume() throw() override {
			if(! is_paused()) return false;
			mRunningSince = get_time();
			mPausedSince = 0;
			return true;
		}

		int64_t get_elapsed_time() const throw() override {
			return is_running() ? mElapsedTime + (get_time() - mRunningSince) : mElapsedTime;
		}
	};
}
#endif
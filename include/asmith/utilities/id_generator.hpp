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

#ifndef ASMITH_UTILITIES_ID_GENERATOR_HPP
#define ASMITH_UTILITIES_ID_GENERATOR_HPP

#include <cstdint>
#include <vector>

namespace asmith {
	
	/*!
		\brief A interface for generating and maintaining ID numbers.
		\param T The type of ID to manage
		\version 0.0
		\data Created : 16th June 2017 Modified : 16th June 2017
		\author Adam Smith
	*/
	template<class T>
	class id_generator {
	public:
		typedef T id_t;

		virtual ~id_generator() {}

		virtual T generate() throw() = 0;
		virtual bool use(T) throw() = 0;
		virtual bool free(T) throw() = 0;
		virtual bool is_used(T) const throw() = 0;
	};

	/*!
		\brief A implementation of id_generator for generating and maintaining ID numbers.
		\param T The type of ID to manage
		\param R True if ID codes can be reused after they have been freed
		\version 0.0
		\data Created : 16th June 2017 Modified : 16th June 2017
		\author Adam Smith
	*/
	template<class T, bool R>
	class id_generator_example : public id_generator<T> {
	private:
		std::vector<T> mUsed;
		std::vector<T> mFree;
		uint64_t mBase;
	public:
		id_generator_example() :
			mBase(0)
		{}

		// Inherited from id_generator

		T generate() throw() override {
			T id;

			if(R && ! mFree.empty()) {
				id = mFree.back();
				mFree.pop_back();
				return id;
			}else while(true) {
				id = static_cast<T>(mBase++);
				for(const T i : mUsed) if(i == id) continue;
				return id;
			}
			return static_cast<T>(0);
		}

		bool use(T aID) throw() override {
			if(is_used(aID)) return false;
			mUsed.push_back(aID);
			return true;
		}

		bool free(T aID) throw() override {
			const auto end = mUsed.end();
			for(auto i = mUsed.begin(); i < end; ++i) {
				if(*i == aID) {
					mUsed.erase(i);
					mFree.push_back(aID);
					return true;
				}
			}
			return false;
		}

		bool is_used(T aID) const throw() override {
			if(aID < mBase) {
				for(const T i : mFree) if(i == aID) return false;
				return true;
			}else {
				for(const T i : mUsed) if(i == aID) return true;
				return false;
			}
		}
	};
}
#endif
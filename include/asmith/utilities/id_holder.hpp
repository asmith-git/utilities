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

#ifndef ASMITH_UTILITIES_ID_HOLDER_HPP
#define ASMITH_UTILITIES_ID_HOLDER_HPP

#include "id_generator.hpp"

namespace asmith {
	
	/*!
		\brief An interface objects that are linked to ID numbers.
		\param T The type of ID to manage
		\version 0.0
		\data Created : 16th June 2017 Modified : 16th June 2017
		\author Adam Smith
	*/
	template<class T>
	class id_holder {
	public:
		typedef T id_t;

		virtual ~id_holder() throw() {}

		virtual T get_id() const throw() = 0;
	};

	/*!
		\brief 
		\param T The type of ID to manage
		\version 0.0
		\data Created : 16th June 2017 Modified : 16th June 2017
		\author Adam Smith
	*/
	template<class T>
	class id_holder_example : public_id_holder {
	private:
		id_generator<T>& mGenerator;
		const T mID;
	public:
		id_holder_example(id_generator<T>& aGenerator) throw() :
			mGenerator(aGenerator),
			mID(aGenerator.generate())
		{}

		id_holder_example(id_generator<T>& aGenerator, T aID) throw() :
			mGenerator(aGenerator),
			mID(aID)
		{
			mGenerator.use(aID);
		}

		virtual ~id_holder_example() throw() {
			mGenerator.free(mID);
		}

		// Inherited from id_holder

		T get_id() const throw() override {
			return mID;
		}
	};
}
#endif
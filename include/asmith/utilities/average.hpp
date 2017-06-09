//	Copyright 2017 Adam Smith
//	Licensed under the Apache License, Version 2.0 (the "License") throw();
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

#ifndef ASMITH_UTILITIES_AVERAGE_HPP
#define ASMITH_UTILITIES_AVERAGE_HPP

#include <algorithm>

namespace asmith {

	template<class T, class I>
	T mean(const I aBegin, const I aEnd) {
		size_t size = 0;
		T tmp = static_cast<T>(0);
		for(I i = aBegin; i != aEnd; ++i, ++size) {
			tmp += *i;
		}
		return tmp / static_cast<T>(size);
	}

	template<class T, class I>
	T median(const I aBegin, const I aEnd) {
		// Initialise
		T tmp;
		size_t size = 0;
		for(I i = aBegin; i != aEnd; ++i) ++size;
		T* const buf = new T[size];
		try {
			// Sort instances
			I i = aBegin;
			for(size_t j = 0; j < size; ++j, ++i) buf[j] = *i;
			std::sort(buf, buf+size);
			const T* const mid = buf + size / 2;

			// Calculate the median
			tmp = (size & 1) == 0 ? (mid[-1] + mid[0]) / static_cast<T>(2) : *mid;
		}catch (std::exception& e) {
			delete[] buf;
			throw e;
		}
		delete[] buf;
		return tmp;
	}

	template<class T, class I>
	T mode(const I aBegin, const I aEnd) {
		// Initialise
		std::pair<T, size_t> tmp;
		size_t size = 0;
		for(I i = aBegin; i != aEnd; ++i) ++size;
		std::pair<T,size_t>* const buf = new std::pair<T, size_t>[size];
		try {
			// Count instances
			I i = aBegin;
			for(size_t j = 0; j < size; ++j, ++i) {
				buf[j].first = *i;
				buf[j].second = 1;
				for(size_t k = 0; k < j; ++k) {
					if(buf[j].first == buf[k].first) {
						++buf[j].second;
						break;
					}
				}
			}
			
			// Find instance with highest count
			tmp = buf[0];
			for(size_t j = 1; j < size; ++j) if(buf[j].second > tmp.second) tmp = buf[j];
		}catch (std::exception& e) {
			delete[] buf;
			throw e;
		}
		delete[] buf;
		return tmp.first;
	}
}
#endif
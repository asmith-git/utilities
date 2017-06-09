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

#ifndef ASMITH_UTILITIES_STANDARD_DEVIATION_HPP
#define ASMITH_UTILITIES_STANDARD_DEVIATION_HPP

namespace asmith {

	namespace implementation {
		template<class T, class I>
		T standard_deviation(const I aBegin, const I aEnd, const bool aSample) {
			// Calculate the mean
			size_t size = 0;
			T mean = static_cast<T>(0);
			for(I i = aBegin; i != aEnd; ++i, ++size) {
				mean += static_cast<T>(*i);
			}
			mean /= static_cast<T>(size);

			// Calculate the variance
			T variance = static_cast<T>(0);
			for(I i = aBegin; i != aEnd; ++i) {
				const T dif = *i - mean;
				variance += dif * dif;
			}
			variance /= static_cast<T>(aSample ? size - 1 : size);

			// Calculate the standard deviation
			return std::sqrt(variance);
		}
	}

	template<class T, class I>
	inline T standard_deviation_population(const I aBegin, const I aEnd) {
		return implementation::standard_deviation<T, I>(aBegin, aEnd, false);
	}

	template<class T, class I>
	inline T standard_deviation_sample(const I aBegin, const I aEnd) {
		return implementation::standard_deviation<T, I>(aBegin, aEnd, true);
	}
}
#endif
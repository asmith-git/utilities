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

#include "asmith/utilities/reflect.hpp"

namespace asmith {

	static constexpr uint8_t REFLECTION_LOOKUP[16] = {
		0b0000, // 0000 (0)
		0b1000, // 0001 (1)
		0b0100, // 0010 (2)
		0b1100, // 0011 (3)
		0b0010, // 0100 (4)
		0b1010, // 0101 (5)
		0b0110, // 0110 (6)
		0b1110, // 0111 (7)
		0b0001, // 1000 (8)
		0b1001, // 1001 (9)
		0b0101, // 1010 (10)
		0b1101, // 1011 (11)
		0b0011, // 1100 (12)
		0b1011, // 1101 (13)
		0b0111, // 1110 (14)
		0b1111  // 1111 (15)
	};

	uint8_t reflect(uint8_t aValue) throw() {
		uint8_t tmp = 0;
		tmp |= REFLECTION_LOOKUP[aValue & 15] << 4;
		tmp |= REFLECTION_LOOKUP[aValue >> 4];
		return tmp;
	}

	uint16_t reflect(uint16_t aValue) throw() {
		uint16_t tmp;
		uint8_t* const dst = reinterpret_cast<uint8_t*>(&tmp);
		const uint8_t* const src = reinterpret_cast<const uint8_t*>(&aValue);
		dst[0] = reflect(src[1]);
		dst[1] = reflect(src[0]);
		return tmp;
	}

	uint32_t reflect(uint32_t aValue) throw() {
		uint32_t tmp;
		uint8_t* const dst = reinterpret_cast<uint8_t*>(&tmp);
		const uint8_t* const src = reinterpret_cast<const uint8_t*>(&aValue);
		dst[0] = reflect(src[3]);
		dst[1] = reflect(src[2]);
		dst[2] = reflect(src[1]);
		dst[3] = reflect(src[0]);
		return tmp;
	}

	uint64_t reflect(uint64_t aValue) throw() {
		uint64_t tmp;
		uint8_t* const dst = reinterpret_cast<uint8_t*>(&tmp);
		const uint8_t* const src = reinterpret_cast<const uint8_t*>(&aValue);
		dst[0] = reflect(src[7]);
		dst[1] = reflect(src[6]);
		dst[2] = reflect(src[5]);
		dst[3] = reflect(src[4]);
		dst[4] = reflect(src[3]);
		dst[5] = reflect(src[2]);
		dst[6] = reflect(src[1]);
		dst[7] = reflect(src[0]);
		return tmp;
	}

	int8_t reflect(int8_t aValue) throw() {
		int8_t tmp;
		uint8_t* const dst = reinterpret_cast<uint8_t*>(&tmp);
		const uint8_t* const src = reinterpret_cast<const uint8_t*>(&aValue);
		dst[0] = reflect(src[0]);
		return tmp;
	}

	int16_t reflect(int16_t aValue) throw() {
		int16_t tmp;
		uint8_t* const dst = reinterpret_cast<uint8_t*>(&tmp);
		const uint8_t* const src = reinterpret_cast<const uint8_t*>(&aValue);
		dst[0] = reflect(src[1]);
		dst[1] = reflect(src[0]);
		return tmp;
	}

	int32_t reflect(int32_t aValue) throw() {
		int32_t tmp;
		uint8_t* const dst = reinterpret_cast<uint8_t*>(&tmp);
		const uint8_t* const src = reinterpret_cast<const uint8_t*>(&aValue);
		dst[0] = reflect(src[3]);
		dst[1] = reflect(src[2]);
		dst[2] = reflect(src[1]);
		dst[3] = reflect(src[0]);
		return tmp;
	}

	int64_t reflect(int64_t aValue) throw() {
		int64_t tmp;
		uint8_t* const dst = reinterpret_cast<uint8_t*>(&tmp);
		const uint8_t* const src = reinterpret_cast<const uint8_t*>(&aValue);
		dst[0] = reflect(src[7]);
		dst[1] = reflect(src[6]);
		dst[2] = reflect(src[5]);
		dst[3] = reflect(src[4]);
		dst[4] = reflect(src[3]);
		dst[5] = reflect(src[2]);
		dst[6] = reflect(src[1]);
		dst[7] = reflect(src[0]);
		return tmp;
	}

}
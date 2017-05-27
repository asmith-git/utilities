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

#ifndef ASMITH_UTILITIES_CRC_HPP
#define ASMITH_UTILITIES_CRC_HPP

#include <cstdint>

namespace asmith {
	template<class T, uint64_t POLYNOMIAL, bool REVERSE_DATA, bool REVERSED_OUT, uint64_t INITIAL_VALUE, uint64_t FINAL_XOR_VALUE, size_t WIDTH = 8 * sizeof(T)>
	class crc {
	public:
		typedef T checksum_t;
	private:
		template<bool R = REVERSE_DATA>
		static typename std::enable_if<R, uint8_t>::type reflect_byte(const uint8_t aByte) {
			return reflect((aByte), 8) & 0xFF;
		}

		template<bool R = REVERSE_DATA>
		static typename std::enable_if<! R, uint8_t>::type reflect_byte(const uint8_t aByte) {
			return aByte;
		}

		template<bool R = REVERSE_DATA>
		static typename std::enable_if<R, checksum_t>::type reflect_table(checksum_t aValue) {
			return reflect(aValue, WIDTH);
		}

		template<bool R = REVERSE_DATA>
		static typename std::enable_if<!R, checksum_t>::type reflect_table(checksum_t aValue) {
			return aValue;
		}

		static checksum_t reflect(checksum_t aValue, uint8_t aBits) {
			checksum_t tmp = 0;
			for(uint8_t i = 0; i < aBits; ++i) {
				if((aValue & 1) == 1) tmp |= (1 << ((aBits - 1) - i));
				aValue = aValue >> 1;
			}
			return tmp;
		}

		static checksum_t table_value(uint8_t aIndex) {
			enum { LAST_BIT = 1 << (WIDTH - 1) };

			checksum_t tmp = static_cast<checksum_t>(reflect_byte(aIndex)) << (WIDTH - 8);

			for(uint8_t i = 0; i < 8; ++i) {
				tmp = tmp & LAST_BIT ?
					(tmp << 1) ^ POLYNOMIAL :
					(tmp << 1);
			}
			return reflect_table(tmp);
		}
	public:
		static checksum_t calculate(const void* aData, size_t aBytes)	{
			const uint8_t* const data = static_cast<const uint8_t*>(aData);
			checksum_t	checksum = INITIAL_VALUE;

			for(size_t i = 0; i < aBytes; ++i) {
				checksum = REVERSE_DATA ?
					(checksum >> 8) ^ table_value((checksum & 0xFF) ^ data[i]) :
					(checksum << 8) ^ table_value(((checksum >> (WIDTH - 8) & 0xFF)) ^ data[i]);
			}

			if((8 * sizeof(checksum_t)) > WIDTH) checksum = checksum & ((1 << WIDTH) - 1);

			return REVERSED_OUT ?
				checksum ^ FINAL_XOR_VALUE :
				~checksum ^ FINAL_XOR_VALUE;
		}
	};
	
	// CRC-8
	typedef crc<uint8_t,	0x07,		false,	true,	0,			0>		crc_8;
	typedef crc<uint8_t,	0x39,		true,	true,	0x00,		0x00>	crc_8_darc;
	typedef crc<uint8_t,	0x1D,		false,	true,	0xFD,		0x00>	crc_8_i_code;
	typedef crc<uint8_t,	0x07,		false,	true,	0x55,		0x55>	crc_8_itu;		//!\bug Wrong checksum on test
	typedef crc<uint8_t,	0x131,		true,	true,	0x00,		0x00>	crc_8_maxim;
	typedef crc<uint8_t,	0x07,		true,	true,	0xFF,		0x00>	crc_8_rohc;
	typedef crc<uint8_t,	0x9B,		true,	true,	0x00,		0x00>	crc_8_wcdma;

	// CRC-32
	typedef crc<uint32_t,	0x04C11DB7,	true,	true,	0xFFFFFFFF,	0xFFFFFFFF> crc_32;
}
#endif
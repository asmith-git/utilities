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

#include "asmith/utilities/strings.hpp"

namespace asmith {

	enum : char {
		CASE_DIFFERENCE = 'A' - 'a'
	};

	char to_upper_case(char aChar) throw() {
		return is_upper_case(aChar) ? aChar + CASE_DIFFERENCE : aChar;
	}

	void to_upper_case(char* aStr) throw() {
		//! \todo Implement
	}

	void to_upper_case(char* aStr, size_t aSize) throw() {
		//! \todo Implement
	}

	char to_lower_case(char aChar) throw() {
		return is_lower_case(aChar) ? aChar - CASE_DIFFERENCE : aChar;
	}

	void to_lower_case(char* aStr) throw() {
		//! \todo Implement
	}

	void to_lower_case(char* aStr, size_t aSize) throw() {
		//! \todo Implement
	}

	bool is_upper_case(char aChar) throw() {
		return aChar >= 'A' && aChar <= 'Z';
	}

	bool is_upper_case(const char* aStr) throw() {
		//! \todo Implement
		return false;
	}

	bool is_upper_case(const char* aStr, size_t aSize) throw() {
		//! \todo Implement
		return false;
	}

	bool is_lower_case(char aChar) throw() {
		return aChar >= 'a' && aChar <= 'z';
	}

	bool is_lower_case(const char* aStr) throw() {
		//! \todo Implement
		return false;
	}

	bool is_lower_case(const char* aStr, size_t aSize) throw() {
		//! \todo Implement
		return false;
	}

	bool is_letter(char aChar) throw() {
		return is_upper_case(aChar) || is_lower_case(aChar);
	}

	bool is_letter(const char* aStr) throw() {
		//! \todo Implement
		return false;
	}

	bool is_letter(const char* aStr, size_t aSize) throw() {
		//! \todo Implement
		return false;
	}

	bool is_vowel(char aChar) throw() {
		switch(to_lower_case(aChar)) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
		default:
			return false;
		}
	}

	bool is_vowel(const char* aStr) throw() {
		//! \todo Implement
		return false;
	}

	bool is_vowel(const char* aStr, size_t aSize) throw() {
		//! \todo Implement
		return false;
	}

	bool is_consonant(char aChar) throw() {
		return is_letter(aChar) && ! is_vowel(aChar);
	}

	bool is_consonant(const char* aStr) throw() {
		//! \todo Implement
		return false;
	}

	bool is_consonant(const char* aStr, size_t aSize) throw() {
		//! \todo Implement
		return false;
	}

	bool is_number(char aChar) throw() {
		return aChar >= '0' && aChar <= '9';
	}

	bool is_number(const char* aStr) throw() {
		//! \todo Implement
		return false;
	}

	bool is_number(const char* aStr, size_t aSize) throw() {
		//! \todo Implement
		return false;
	}

}
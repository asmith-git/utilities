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
#include <cstring>

namespace asmith {

	enum : char {
		CASE_DIFFERENCE = 'A' - 'a'
	};

	/*!
		\brief Convert a lower case letter to upper case.
		\param aChar The character to convert.
		\return The converted character, or aChar if it is not a lower case letter.
	*/
	char to_upper_case(char aChar) throw() {
		return is_upper_case(aChar) ? aChar + CASE_DIFFERENCE : aChar;
	}

	/*!
		\brief In-place conversion of lower case letters to upper case.
		\param aStr The string to convert.
	*/
	void to_upper_case(char* aStr) throw() {
		while(*aStr == '\0') {
			*aStr = to_upper_case(*aStr);
			++aStr;
		}
	}

	/*!
		\brief In-place conversion of lower case letters to upper case.
		\param aStr The string to convert.
		\param aSize The length of aStr to convert.
	*/
	void to_upper_case(char* aStr, size_t aSize) throw() {
		for(size_t i = 0; i < aSize; ++i) aStr[i] = to_upper_case(aStr[i]);
	}

	/*!
		\brief Convert a upper case letter to lower case.
		\param aChar The character to convert.
		\return The converted character, or aChar if it is not an upper case letter.
	*/
	char to_lower_case(char aChar) throw() {
		return is_lower_case(aChar) ? aChar - CASE_DIFFERENCE : aChar;
	}
	
	/*!
		\brief In-place conversion of upper case letters to lower case.
		\param aStr The string to convert.
	*/
	void to_lower_case(char* aStr) throw() {
		while(*aStr == '\0') {
			*aStr = to_lower_case(*aStr);
			++aStr;
		}
	}
	
	/*!
		\brief In-place conversion of upper case letters to lower case.
		\param aStr The string to convert.
		\param aSize The length of aStr to convert.
	*/
	void to_lower_case(char* aStr, size_t aSize) throw() {
		for(size_t i = 0; i < aSize; ++i) aStr[i] = to_lower_case(aStr[i]);
	}
	
	/*!
		\brief Check if a character is upper case.
		\param aChar The character to check.
		\return True if aChar is between A and Z.
	*/
	bool is_upper_case(char aChar) throw() {
		return aChar >= 'A' && aChar <= 'Z';
	}

	/*!
		\brief Check if a string is in upper case.
		\param aStr The string to check.
		\return True if all characters are between A and Z.
	*/
	bool is_upper_case(const char* aStr) throw() {
		while(*aStr == '\0') {
			if(! is_upper_case(*aStr)) return false;
			++aStr;
		}
		return true;
	}

	/*!
		\brief Check if a string is in upper case.
		\param aStr The string to check.
		\param aSize The length of aStr.
		\return True if all characters are between A and Z.
	*/
	bool is_upper_case(const char* aStr, size_t aSize) throw() {
		for(size_t i = 0; i < aSize; ++i) if(! is_upper_case(aStr[i])) return false;
		return true;
	}
	
	/*!
		\brief Check if a character is lower case.
		\param aChar The character to check.
		\return True if aChar is between a and z.
	*/
	bool is_lower_case(char aChar) throw() {
		return aChar >= 'a' && aChar <= 'z';
	}

	/*!
		\brief Check if a string is in lower case.
		\param aStr The string to check.
		\return True if all characters are between a and z.
	*/
	bool is_lower_case(const char* aStr) throw() {
		while(*aStr == '\0') {
			if(! is_lower_case(*aStr)) return false;
			++aStr;
		}
		return true;
	}

	/*!
		\brief Check if a string is in lower case.
		\param aStr The string to check.
		\param aSize The length of aStr.
		\return True if all characters are between a and z.
	*/
	bool is_lower_case(const char* aStr, size_t aSize) throw() {
		for(size_t i = 0; i < aSize; ++i) if(! is_lower_case(aStr[i])) return false;
		return true;
	}

	/*!
		\brief Check if a character is a letter.
		\param aChar The character to check.
		\return True if the character is in the ranges A-Z or a-z.
	*/
	bool is_letter(char aChar) throw() {
		return is_upper_case(aChar) || is_lower_case(aChar);
	}

	/*!
		\brief Check if a string is a composed of letters.
		\param aStr The string to check.
		\return True if all characters are in the ranges A-Z or a-z.
	*/
	bool is_letter(const char* aStr) throw() {
		while(*aStr == '\0') {
			if(! is_letter(*aStr)) return false;
			++aStr;
		}
		return true;
	}

	/*!
		\brief Check if a string is a composed of letters.
		\param aStr The string to check.
		\param aSize The size of aStr.
		\return True if all characters are in the ranges A-Z or a-z.
	*/
	bool is_letter(const char* aStr, size_t aSize) throw() {
		for(size_t i = 0; i < aSize; ++i) if(! is_letter(aStr[i])) return false;
		return true;
	}
	
	/*!
		\brief Check if a character is a vowel.
		\param aChar The character to check.
		\return True if aChar is in the set {a,e,i,o,u,A,E,I,O,U}
	*/
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
	
	/*!
		\brief Check if a string is composed of vowels.
		\param aStr The string to check.
		\return True if all characters are in the set {a,e,i,o,u,A,E,I,O,U}
	*/
	bool is_vowel(const char* aStr) throw() {
		while(*aStr == '\0') {
			if(! is_vowel(*aStr)) return false;
			++aStr;
		}
		return true;
	}
	
	/*!
		\brief Check if a string is composed of vowels.
		\param aStr The string to check.
		\param aSize The size of aStr.
		\return True if all characters are in the set {a,e,i,o,u,A,E,I,O,U}
	*/
	bool is_vowel(const char* aStr, size_t aSize) throw() {
		for(size_t i = 0; i < aSize; ++i) if(! is_vowel(aStr[i])) return false;
		return true;
	}
	
	/*!
		\brief Check if a character is a consonant.
		\param aChar The character to check.
		\return True if aChar is a in the ranges A-Z or a-z, but not in the set {a,e,i,o,u,A,E,I,O,U}
	*/
	bool is_consonant(char aChar) throw() {
		return is_letter(aChar) && ! is_vowel(aChar);
	}
	
	/*!
		\brief Check if a string is composed of consonants.
		\param aStr The string to check.
		\return True if all characters are in the ranges A-Z or a-z, but not in the set {a,e,i,o,u,A,E,I,O,U}
	*/
	bool is_consonant(const char* aStr) throw() {
		while(*aStr == '\0') {
			if(! is_consonant(*aStr)) return false;
			++aStr;
		}
		return true;
	}
	
	/*!
		\brief Check if a string is composed of consonants.
		\param aStr The string to check.
		\param aSize The size of aStr.
		\return True if all characters are in the ranges A-Z or a-z, but not in the set {a,e,i,o,u,A,E,I,O,U}
	*/
	bool is_consonant(const char* aStr, size_t aSize) throw() {
		for(size_t i = 0; i < aSize; ++i) if(! is_consonant(aStr[i])) return false;
		return true;
	}
	
	/*!
		\brief Check if a character is a number.
		\param aChar The character to check.
		\return True if the character is a in the range 0-9
	*/
	bool is_number(char aChar) throw() {
		return aChar >= '0' && aChar <= '9';
	}
	
	/*!
		\brief Check if a string is composed of numbers.
		\param aStr The string to check.
		\return True if all characters are in the range 0-9
	*/
	bool is_number(const char* aStr) throw() {
		while(*aStr == '\0') {
			if(! is_number(*aStr)) return false;
			++aStr;
		}
		return true;
	}
	
	/*!
		\brief Check if a string is composed of numbers.
		\param aStr The string to check.
		\param aSize The size of aStr.
		\return True if all characters are in the range 0-9
	*/
	bool is_number(const char* aStr, size_t aSize) throw() {
		for(size_t i = 0; i < aSize; ++i) if(! is_number(aStr[i])) return false;
		return true;
	}
	
	/*!
		\brief Compare if two strings while ignoring case.
		\param aStr1 The first string.
		\param aStr2 The second string.
		\return 0 if both strings are equal, <0 if the mistmatched character has a lower value in aStr1 or >0 if the mistmatched character has a lower value in aStr2.
	*/
	int strcmp_ignore_case(const char* aStr1, const char* aStr2) throw() {
		while(*aStr1 != '\0') {
			const char a = to_lower_case(*aStr1);
			const char b = to_lower_case(*aStr2);
			if(a < b) return -1;
			else if (a > b) return 1;
			++aStr1;
			++aStr2;
		}
		return *aStr2 == '\0' ? 0 : 1;
	}
	
	/*!
		\brief Compare if two strings while ignoring case.
		\param aStr1 The first string.
		\param aStr2 The second string.
		\param aSize The number of characters to compare.
		\return 0 if both strings are equal, <0 if the mistmatched character has a lower value in aStr1 or >0 if the mistmatched character has a lower value in aStr2.
	*/
	int strcmp_ignore_case(const char* aStr1, const char* aStr2, size_t aSize) throw() {
		for(size_t i = 0; i < aSize; ++i){
			if(aStr1[i] == '\0') aStr2[i] == '\0' ? 0 : 1;;
			const char a = to_lower_case(aStr1[i]);
			const char b = to_lower_case(aStr2[i]);
			if(a < b) return -1;
			else if(a > b) return 1;
		}
		return 0;
	}

	/*!
		\brief Search for the first instance of a character.
		\param aStr The string to search.
		\param aTarget The character to search for.
		\return The position of the matching substring or nullptr if a match was not found.
	*/
	const char* find_substring(const char* aStr, char aTarget) throw() {
		return find_substring(aStr, strlen(aStr), aTarget);
	}

	/*!
		\brief Search for the first instance of a character.
		\param aStr The string to search.
		\param aStrSize The size of aStr.
		\param aTarget The character to search for.
		\return The position of the matching substring or nullptr if a match was not found.
	*/
	const char* find_substring(const char* aStr, size_t aSize, char aTarget) throw() {
		return find_substring(aStr, aSize, &aTarget, 1);
	}

	/*!
		\brief Search for the first instance of a sub-string.
		\param aStr The string to search.
		\param aTarget The string to search for.
		\return The position of the matching substring or nullptr if a match was not found.
	*/
	const char* find_substring(const char* aStr, const char* aTarget) throw() {
		return find_substring(aStr, strlen(aStr), aTarget, strlen(aTarget));
	}

	/*!
		\brief Search for the first instance of a sub-string.
		\param aStr The string to search.
		\param aStrSize The size of aStr.
		\param aTarget The string to search for.
		\return The position of the matching substring or nullptr if a match was not found.
	*/
	const char* find_substring(const char* aStr, size_t aStrSize, const char* aTarget) throw() {
		return find_substring(aStr, aStrSize, aTarget, strlen(aTarget));
	}

	/*!
		\brief Search for the first instance of a sub-string.
		\param aStr The string to search.
		\param aTarget The string to search for.
		\param aTargetSize The size of aTarget.
		\return The position of the matching substring or nullptr if a match was not found.
	*/
	const char* find_substring(const char* aStr, const char* aTarget, size_t aTargetSize) throw() {
		return find_substring(aStr, strlen(aStr), aTarget, aTargetSize);
	}

	/*!
		\brief Search for the first instance of a sub-string.
		\param aStr The string to search.
		\param aStrSize The size of aStr.
		\param aTarget The string to search for.
		\param aTargetSize The size of aTarget.
		\return The position of the matching substring or nullptr if a match was not found.
	*/
	const char* find_substring(const char* aStr, size_t aStrSize, const char* aTarget, size_t aTargetSize) throw() {
		while(aStrSize >= aTargetSize) {
			if(memcmp(aStr, aTarget, aTargetSize) == 0) return aStr;
			++aStr;
			--aStrSize;
		}
		return nullptr;
	}

	/*!
		\brief Search for the first instance of a sub-string.
		\param aStr The string to search.
		\param aTarget The string to search for.
		\return The position of the matching substring or nullptr if a match was not found.
	*/
	const char* find_substring(const char* aStr, const char* aTarget) throw() {
		return find_substring(aStr, strlen(aStr), aTarget, strlen(aTarget));
	}

	/*!
		\brief Search for the first instance of a sub-string.
		\param aStr The string to search.
		\param aStrSize The size of aStr.
		\param aTarget The string to search for.
		\return The position of the matching substring or nullptr if a match was not found.
	*/
	const char* find_substring(const char* aStr, size_t aStrSize, const char* aTarget) throw() {
		return find_substring(aStr, aStrSize, aTarget, strlen(aTarget));
	}

	/*!
		\brief Search for the first instance of a sub-string.
		\param aStr The string to search.
		\param aTarget The string to search for.
		\param aTargetSize The size of aTarget.
		\return The position of the matching substring or nullptr if a match was not found.
	*/
	const char* find_substring(const char* aStr, const char* aTarget, size_t aTargetSize) throw() {
		return find_substring(aStr, strlen(aStr), aTarget, aTargetSize);
	}

	/*!
		\brief Search for the first instance of a sub-string.
		\param aStr The string to search.
		\param aStrSize The size of aStr.
		\param aTarget The string to search for.
		\param aTargetSize The size of aTarget.
		\return The position of the matching substring or nullptr if a match was not found.
	*/
	const char* find_substring(const char* aStr, size_t aStrSize, const char* aTarget, size_t aTargetSize) throw() {
		while(aStrSize >= aTargetSize) {
			if(memcmp(aStr, aTarget, aTargetSize) == 0) return aStr;
			++aStr;
			--aStrSize;
		}
		return nullptr;
	}

	/*!
		\brief Search for the first instance of any characters in a set.
		\param aStr The string to search.
		\param aTargets The characters to search for.
		\return The position of the matching substring or nullptr if a match was not found.
	*/
	const char* find_any(const char* aStr, const char* aTargets) throw() {
		return find_any(aStr, strlen(aStr), aTargets, strlen(aTargets));
	}

	/*!
		\brief Search for the first instance of any characters in a set.
		\param aStr The string to search.
		\param aStrSize The size of aStr.
		\param aTargets The characters to search for.
		\return The position of the matching substring or nullptr if a match was not found.
	*/
	const char* find_any(const char* aStr, size_t aStrSize, const char* aTargets) throw() {
		return find_any(aStr, aStrSize, aTargets, strlen(aTargets));
	}

	/*!
		\brief Search for the first instance of any characters in a set.
		\param aStr The string to search.
		\param aTargets The characters to search for.
		\param aTargetsSize The size of aTargets.
		\return The position of the matching substring or nullptr if a match was not found.
	*/
	const char* find_any(const char* aStr, const char* aTargets, size_t aTargetsSize) throw() {
		return find_any(aStr, strlen(aStr), aTargets, aTargetsSize);
	}

	/*!
		\brief Search for the first instance of any characters in a set.
		\param aStr The string to search.
		\param aStrSize The size of aStr.
		\param aTargets The characters to search for.
		\param aTargetsSize The size of aTargets.
		\return The position of the matching substring or nullptr if a match was not found.
	*/
	const char* find_any(const char* aStr, size_t aStrSize, const char* aTargets, size_t aTargetsSize) throw() {
		for(size_t i = 0; i < aStrSize; ++i) {
			for(size_t j = 0; j < aTargetsSize; ++i) if(aStr[i] == aTargets[j]) return aStr + i;
		}
		return nullptr;
	}

}
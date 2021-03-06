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

#ifndef ASMITH_UTILITIES_STRINGS_HPP
#define ASMITH_UTILITIES_STRINGS_HPP

#include <cstdint>

namespace asmith { namespace strings {

	char to_upper_case(char) throw();
	void to_upper_case(char*) throw();
	void to_upper_case(char*, size_t) throw();

	char to_lower_case(char) throw();
	void to_lower_case(char*) throw();
	void to_lower_case(char*, size_t) throw();

	bool is_upper_case(char) throw();
	bool is_upper_case(const char*) throw();
	bool is_upper_case(const char*, size_t) throw();

	bool is_lower_case(char) throw();
	bool is_lower_case(const char*) throw();
	bool is_lower_case(const char*, size_t) throw();

	bool is_letter(char) throw();
	bool is_letter(const char*) throw();
	bool is_letter(const char*, size_t) throw();

	bool is_vowel(char) throw();
	bool is_vowel(const char*) throw();
	bool is_vowel(const char*, size_t) throw();

	bool is_consonant(char) throw();
	bool is_consonant(const char*) throw();
	bool is_consonant(const char*, size_t) throw();

	bool is_number(char) throw();
	bool is_number(const char*) throw();
	bool is_number(const char*, size_t) throw();

	bool is_whitespace(char) throw();
	bool is_whitespace(const char*) throw();
	bool is_whitespace(const char*, size_t) throw();

	int strcmp_ignore_case(const char*, const char*) throw();
	int strcmp_ignore_case(const char*, const char*, size_t) throw();

	const char* find_substring(const char*, char) throw();
	const char* find_substring(const char*, size_t, char) throw();
	const char* find_substring(const char*, const char*) throw();
	const char* find_substring(const char*, size_t, const char*) throw();
	const char* find_substring(const char*, const char*, size_t) throw();
	const char* find_substring(const char*, size_t, const char*, size_t) throw();

	const char* find_any(const char*, const char*) throw();
	const char* find_any(const char*, size_t, const char*) throw();
	const char* find_any(const char*, const char*, size_t) throw();
	const char* find_any(const char*, size_t, const char*, size_t) throw();

	const char* find_number(const char*) throw();
	const char* find_number(const char*, size_t) throw();
	const char* find_letter(const char*) throw();
	const char* find_letter(const char*, size_t) throw();
	const char* find_lower_case_letter(const char*) throw();
	const char* find_lower_case_letter(const char*, size_t) throw();
	const char* find_upper_case_letter(const char*) throw();
	const char* find_upper_case_letter(const char*, size_t) throw();
	const char* find_vowel(const char*) throw();
	const char* find_vowel(const char*, size_t) throw();
	const char* find_lower_case_vowel(const char*) throw();
	const char* find_lower_case_vowel(const char*, size_t) throw();
	const char* find_upper_case_vowel(const char*) throw();
	const char* find_upper_case_vowel(const char*, size_t) throw();
	const char* find_consonant(const char*) throw();
	const char* find_consonant(const char*, size_t) throw();
	const char* find_lower_case_consonant(const char*) throw();
	const char* find_lower_case_consonant(const char*, size_t) throw();
	const char* find_upper_case_consonant(const char*) throw();
	const char* find_upper_case_consonant(const char*, size_t) throw();

	const char* read_8u(const char*, uint8_t&) throw();
	const char* read_16u(const char*, uint16_t&) throw();
	const char* read_32u(const char*, uint32_t&) throw();
	const char* read_64u(const char*, uint64_t&) throw();
	const char* read_8i(const char*, int8_t&) throw();
	const char* read_16i(const char*, int16_t&) throw();
	const char* read_32i(const char*, int32_t&) throw();
	const char* read_64i(const char*, int64_t&) throw();
	const char* read_f(const char*, float&) throw();
	const char* read_d(const char*, double&) throw();

	const char* skip(const char*, const char*, size_t) throw();
	const char* skip(const char* aStr, bool(*aCondition)(char)) throw();
	const char* skip_whitespace(const char* aStr) throw();
	const char* skip_letters(const char* aStr) throw();
	const char* skip_lower_case(const char* aStr) throw();
	const char* skip_upper_case(const char* aStr) throw();
	const char* skip_numbers(const char* aStr) throw();
}}
#endif
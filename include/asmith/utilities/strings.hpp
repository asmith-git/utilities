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

namespace asmith { namespace strings {

	enum {
		NUMBER_COUNT = 10,
		LETTER_COUNT = 26,
		VOWEL_COUNT = 5,
		CONSONANT_COUNT = LETTER_COUNT - VOWEL_COUNT
	};

	static constexpr const char* const NUMBERS = "0123456789aeioubcdfghjklmnpqrstvwxyzAEIOUBCDFGHJKLMNPQRSTVWXYZ";
	static constexpr const char* const LETTERS = NUMBERS + NUMBER_COUNT;
	static constexpr const char* const LOWER_CASE_LETTERS = LETTERS;
	static constexpr const char* const UPPER_CASE_LETTERS = LETTERS + LETTER_COUNT;
	static constexpr const char* const LOWER_CASE_VOWELS = LOWER_CASE_LETTERS;
	static constexpr const char* const UPPER_CASE_VOWELS = UPPER_CASE_LETTERS;
	static constexpr const char* const LOWER_CASE_CONSONANTS = LOWER_CASE_VOWELS + VOWEL_COUNT;
	static constexpr const char* const UPPER_CASE_CONSONANTS = UPPER_CASE_VOWELS + VOWEL_COUNT;

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
}}
#endif
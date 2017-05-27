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
}}
#endif
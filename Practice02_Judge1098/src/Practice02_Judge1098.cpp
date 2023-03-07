//============================================================================
// Name        : Practice02_Judge1098.cpp
// Author      : 2019136056 박세현
// Version     : 2022학년도 1학기
// Copyright   : 
// Description : JudgeKoreatech NO.1098
//============================================================================

#include <iostream>

int solve(std::string_view word);

int main() {
	int T;
	std::cout << "Test Case 입력 : ";
	std::cin >> T;
	// 정수 입력받은 후 buffer 제거!
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int t{0}; t<T; ++t) {
		std::string word;
		std::cout << "문자열 입력 : ";
		std::getline(std::cin, word);
		std::cout << solve(word) << '\n';
	}
	return 0;
}

int solve(std::string_view word) {
	int freq[26]{};
	for (size_t i{0}; i<word.size(); ++i) {
		++freq[word[i]-'a'];
	}
	for (int i=0; i<26; i++) {
		std::cout << freq[i] << " ";
	}
	for (int i{0}; i<word.size(); ++i) {
		if(freq[word[i]- 'a'] == 1) return i;
	}
	return -1;
}

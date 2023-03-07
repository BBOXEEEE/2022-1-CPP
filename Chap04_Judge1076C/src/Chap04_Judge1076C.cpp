//============================================================================
// Name        : Chap04_Judge1076C.cpp
// Author      : 2019136056 박세현
// Version     : 2022학년도 1학기
// Copyright   : 
// Description : Judge-Koreatech 1076_C
//============================================================================

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void findOverlap(int size);

int main() {
	int T{0};
	std::cin >> T;
	for (size_t t{0}; t<T; ++t) {
		int size{0};
		std::cin >> size;
		findOverlap(size);
	}
	return 0;
}

void findOverlap(int size) {
	std::vector<int> commonFreq(26, INT_MAX);
	for(size_t i{0}; i<size; ++i) {
		int alpaCount[26]{};
		std::string word;
		std::cin >> word;
		for(auto c : word)
			++alpaCount[static_cast<int>(c-'a')];
		for(size_t j{0}; j<26; ++j) {
			commonFreq[j] = std::min(commonFreq[j], alpaCount[j]);
		}
	}
	for(size_t i{0}; i<26; ++i) {
		for(size_t j{0}; j<commonFreq[i]; ++j) {
			std::cout << static_cast<char>('a' + i);
		}
	}
	std::cout << '\n';
}

// https://judge.koreatech.ac.kr/showsource.php?id=70332

//============================================================================
// Name        : Chap06_Judge1079B.cpp
// Author      : 2019136056 박세현
// Version     : 2022학년도 1학기
// Copyright   : 
// Description : Judge-Koreatech 1079_B
//============================================================================

#include <iostream>
#include <sstream>
#include <string>

int countSegment(std::string S);

int main() {
	int T{0};
	std::cin >> T;
	std::cin.ignore();
	for(int t{0}; t<T; ++t) {
		std::string S;
		getline(std::cin, S);
		std::cout << countSegment(S) << '\n';
	}
	return 0;
}

int countSegment(std::string S) {
	int count{0};
	std::stringstream ss(S);
	std::string strbuffer;
	while(getline(ss, strbuffer, ' ')) {
		if(strbuffer.length() > 0) {
			++count;
		}
	}
	return count;
}

// https://judge.koreatech.ac.kr/showsource.php?id=72508

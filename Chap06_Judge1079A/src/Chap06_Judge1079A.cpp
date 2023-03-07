//============================================================================
// Name        : Chap06_Judge1079A.cpp
// Author      : 2019136056 박세현
// Version     : 2022학년도 1학기
// Copyright   : 
// Description : Judge-Koreatech 1079_A
//============================================================================

#include <iostream>

bool checkSelfDigit(int n);

int main() {
    int T{0};
    std::cin >> T;
    for (int t{0}; t<T; ++t) {
        int left{0}, right{0};
        std::cin >> left >> right;
        int count{0};
        for(int i{left}; i<=right; ++i) {
        	if(checkSelfDigit(i)) ++count;
        }
        std::cout << count << '\n';
    }
    return 0;
}

bool checkSelfDigit(int n) {
	for(int i{n}; i>0; i /= 10) {
		int digit = i % 10;
		if(digit == 0 || n % digit > 0) return false;
	}
	return true;
}

// https://judge.koreatech.ac.kr/showsource.php?id=72524

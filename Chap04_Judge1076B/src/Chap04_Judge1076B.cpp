//============================================================================
// Name        : Chap04_Judge1076B.cpp
// Author      : 2019136056 박세현
// Version     : 2022학년도 1학기
// Copyright   : 
// Description : Judge-Koreatech 1076_B
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>

void movingAverage(std::vector<int> number, int size, int section);

int main() {
	int T{0};
	std::cin >> T;
	for (size_t t{0}; t<T; ++t) {
		int section{0};
		std::cin >> section;
		int size{0};
		std::cin >> size;
		std::vector<int> number(size);
		for (size_t i{0}; i<size; ++i) {
			std::cin >> number[i];
		}
		movingAverage(number, size, section);
	}
	return 0;
}

void movingAverage(std::vector<int> number, int size, int section) {
	for (size_t i{0}; i<size-section + 1; ++i) {
		int sum = 0;
		for (size_t j{i}; j<i + section; ++j) {
			sum += number[j];
		}
		double S {static_cast<double>(section)};
		float avg = std::round(sum / S * 10) / 10;
		printf("%.1f ", avg);
	}
	std::cout << '\n';
}

// https://judge.koreatech.ac.kr/showsource.php?id=69695

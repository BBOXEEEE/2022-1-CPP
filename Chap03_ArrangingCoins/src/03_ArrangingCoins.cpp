//============================================================================
// Name        : 03_ArrangingCoins.cpp
// Author      : 2019136056 박세현
// Version     : 2022학년도 1학기
// Copyright   : 
// Description : 과제 2-2. LeetCode 441번 ArrangingCoins
//============================================================================

#include <iostream>
#include <cmath>

int arrangeCoins(int n);

int main() {
	int number{0};
	std::cout << "정수 입력 : ";
	std::cin >> number;
	std::cout << "정수 " << number << "으로 만들 수 있는 계단의 최대 높이 : " << arrangeCoins(number) << std::endl;

	return 0;
}

// 수학적 접근
// 계단이 완전히 채워지는 정수값 = sqrt(2.0 * n + 0.25) - 0.5, 이 값은 입력한 정수 n보다 작거나 같다.
int arrangeCoins(int n) {
	return (sqrt(2.0 * n +0.25) - 0.5);
}

/* LeetCode Submit 결과
	Runtime: 0 ms, faster than 100.00% of C++ online submissions for Arranging Coins.
	Memory Usage: 6 MB, less than 26.82% of C++ online submissions for Arranging Coins
 */

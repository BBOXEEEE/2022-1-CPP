//============================================================================
// Name        : 02_IntegerReplacement.cpp
// Author      : 2019136056 박세현
// Version     : 2022학년도 1학기
// Copyright   :
// Description : 과제 2-1. LeetCode 397번 IntegerReplacement
//============================================================================

#include <iostream>

int integerReplacement(int n);

int main() {
	int number{0};
	std::cout << "정수 입력 : ";
	std::cin >> number;

	std::cout << number << "이 1이 되기 위한 최소 연산값 : " << integerReplacement(number) << std::endl;

	return 0;
}

int integerReplacement(int n) {
	long int num{n};
	int cnt{0};

	while (num != 1) {
		if (num == 3)
			return cnt + 2;

		// num이 홀수인 경우
		if (num % 2 == 1) {
			// 홀수인 경우 num+1 or num-1 한 다음 과정에서 또 다시 홀수가 되면 최소 연산이 아님.
			if ( (num-1)/2 % 2 == 1)
				num += 1;
			else
				num -= 1;
		}
		// num이 짝수인 경우
		else
			num /= 2;
		++cnt;
	}

	return cnt;
}

/* LeetCode submit 결과
 	 Runtime: 2 ms, faster than 62.17% of C++ online submissions for Integer Replacement.
	 Memory Usage: 5.7 MB, less than 98.11% of C++ online submissions for Integer Replacement.
 */

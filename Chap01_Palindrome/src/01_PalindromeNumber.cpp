//============================================================================
// Name        : 01_PalindromeNumber.cpp
// Author      : 2019136056 박세현
// Version     : 2022학년도 1학기
// Copyright   :
// Description : 과제 1. LeetCode 9번 Palindrome Number
//============================================================================

#include <iostream>

bool isPalindrome (int x);

int main() {
	std::cout << "정수 입력 : ";
	int number{0};
	std::cin >> number;

	if (isPalindrome(number) == true) {
		std::cout << number << " is Palindrome Number!" << std::endl;
	}
	else {
		std::cout << number << " is not Palindrome Number!" << std::endl;
	}

	return 0;
}

bool isPalindrome (int x) {
	// 1자리 숫자는 Palindrome Number
	if (x >= 0 && x <10)
		return true;
	// 0이하 혹은 1의 자리가 0인 수는 NOT Palindrome Number
	else if (x < 0 || x == 10 || x % 10 == 0)
		return false;

	int original{x};
	int palindrome{0};

	// 입력받은 정수의 절반까지 revert하여 나머지 절반과 비교
	while(original > palindrome) {
		palindrome = palindrome * 10 + original % 10;
		original /= 10;
	}

	// first case : 짝수자리 정수 x, second case : 홀수자리 정수
	if (original == palindrome || original == palindrome / 10)
		return true;
	else
		return false;
}


/* LeetCode Submit 결과
 	 Runtime: 8 ms, faster than 90.50% of C++ online submissions for Palindrome Number.
	Memory Usage: 5.9 MB, less than 32.97% of C++ online submissions for Palindrome Number.
 */

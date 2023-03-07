//============================================================================
// Name        : Practice01_LeetCode8.cpp
// Author      : 2019136056 박세현
// Version     : 2022학년도 1학기
// Copyright   : 
// Description : Chap04 LeetCode No.8
//============================================================================

#include <iostream>

int myAtoi(std::string_view s) {
	// int ret : return value
	int ret{0};
	// 배열 or 문자열 색인은 size_t 자료형 사용을 권장!
	size_t i{0};

	bool isNegative(false);
	if(s[0] == '-') {
		isNegative = true;
		++i;
	}
	else if (s[0] == '+') ++i;

	while (i<s.size()) {
		int digit{s[i]-'0'};
		if (ret > (std::numeric_limits<int>::max()-digit)/10)
			return isNegative? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
		ret = ret * 10 + digit;

		++i;
	}
	return isNegative? -ret : ret;
}

int main() {
	std::cout << myAtoi("1234") << '\n';
	std::cout << myAtoi("2147483648") << '\n';
	std::cout << myAtoi("-1234") << '\n';
	std::cout << myAtoi("-2147483648") << '\n';
	std::cout << myAtoi("-2147483649") << '\n';
	return 0;
}

//============================================================================
// Name        : test.cpp
// Author      : 2019136056 박세현
// Version     :
// Copyright   : 
// Description : Test
//============================================================================

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

std::vector<std::pair<int,int>> pairTest() {
	std::vector<std::pair<int,int>> test;
	test.emplace_back(1, 2);
	test.emplace_back(2, 4);
	test.emplace_back(3, 6);
	test.emplace_back(5, 7);
	test.emplace_back(8, 7);
	return test;
}

int main() {
	for(auto[A,B] : pairTest()) {
		std::cout << A << ", " << B << '\n';
	}
	return 0;
}

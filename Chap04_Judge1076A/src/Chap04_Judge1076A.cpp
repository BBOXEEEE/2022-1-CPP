//============================================================================
// Name        : Chap04_Judge1076A.cpp
// Author      : 2019136056 박세현
// Version     : 2022학년도 1학기
// Copyright   : 
// Description : Judge-Koreatech 1076_A
//============================================================================

#include <iostream>
#include <vector>

int RemoveNumber(std::vector<int>& nums, int size, int remove);

int main() {
	int T;
	std::cin >> T;
	for (size_t t{0}; t<T; ++t) {
		int remove{0};
		std::cin >> remove;
		int size{0};
		std::cin >> size;
		std::vector<int> nums(size);
		for (size_t i{0}; i<size; ++i) {
			std::cin >> nums[i];
		}
		std::cout << '\n';
		int newSize{RemoveNumber(nums, size, remove)};
		std::cout << newSize << '\n';
		for (size_t i{0}; i<newSize; ++i) {
			std::cout << nums[i] << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}

int RemoveNumber(std::vector<int>& nums, int size, int remove) {
	int i{0};
	while(i<size) {
		if(nums[i] == remove) {
			nums[i] = nums[size-1];
			--size;
		}
		else ++i;
	}
	return size;
}

// https://judge.koreatech.ac.kr/showsource.php?id=69685

// solution
/*
int solve(int nums[], int N, int N) {
	int size{N};
	int i{0};
	while (i<size) {
		if (nums[i] == V) {
			nums[i] = nums[size-1];
			--size;
		}
		else ++i;
	}

	return size;
}

int main() {
	int T;
	std::cin >> T;
	for (int t{0}; t<T; ++T) {
		int V, N;
		std::cin >> V >> N;
		int* nums{new int[N]};
		for (int i{0}; i<N; ++i)
			std::cin >> nums[i];
		int size{solve(nums, N, V)};
		std::cout << size << '\n';
		if (size != 0) {
			std::cout << nums[0];
			for (int i{0}; i<size; ++i) {
				std::cout << ' ' << nums[i];
			}
			std::cout << '\n';
		}
		delete[] nums;
	}
	return 0;
}

 */

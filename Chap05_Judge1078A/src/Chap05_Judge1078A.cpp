//============================================================================
// Name        : Chap05_Judge1078A.cpp
// Author      : 2019136056 박세현
// Version     : 2022학년도 1학기
// Copyright   : 
// Description : Judge-Koreatech 1078_A
//============================================================================

#include <iostream>
#include <vector>
#include <random>
std::random_device rd;
std::mt19937 mtRand(rd());

struct FieldInfo {
	size_t row;
	size_t col;
	int mines;
};

constexpr FieldInfo smallInfo{9,9,10};
constexpr FieldInfo mediumInfo{16,16,40};
constexpr FieldInfo largeInfo{16,30,99};

void setMines(std::vector<std::vector<int>>& field, const FieldInfo& fieldInfo) {
	std::uniform_int_distribution<> rowDis(0, fieldInfo.row - 1);
	std::uniform_int_distribution<> colDis(0, fieldInfo.col - 1);
	int mines{fieldInfo.mines};
	while(mines > 0) {
		int r{rowDis(mtRand)};
		int c{colDis(mtRand)};
		if(field[r][c] != -1) {
			field[r][c] = -1;
			--mines;
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
    int T{0};
    std::cin >> T;
    for (int t{0}; t<T; ++t) {
        int S{0};
        std::cin >> S;
        const FieldInfo& fieldInfo{S==0? smallInfo: S==1? mediumInfo: largeInfo};
        std::vector<std::vector<int>> minesField(fieldInfo.row, std::vector<int>(fieldInfo.col));
        setMines(minesField, fieldInfo);
        for(size_t r{0}; r<fieldInfo.row; ++r) {
        	for(size_t c{0}; c<fieldInfo.col; ++c) {
        		std::cout << minesField[r][c] << " ";
        	}
        	std::cout << '\n';
        }
    }
}



// https://judge.koreatech.ac.kr/showsource.php?id=71872

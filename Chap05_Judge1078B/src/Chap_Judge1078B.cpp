//============================================================================
// Name        : Chap_Judge1078B.cpp
// Author      : 2019136056 박세현
// Version     : 2022학년도 1학기
// Copyright   : 
// Description : Judge-Koreatech 1078_B
//============================================================================

#include <iostream>
#include <vector>
#include <cstddef>

struct FieldInfo {
	size_t row;
	size_t col;
	int mines;
};

constexpr FieldInfo smallInfo{9,9,10};
constexpr FieldInfo mediumInfo{16,16,40};
constexpr FieldInfo largeInfo{16,30,99};

constexpr int d[8][2]{
    {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}
};

bool isValid(size_t r, size_t c, const FieldInfo& fieldInfo) noexcept {
	return r<fieldInfo.row && c<fieldInfo.col;
}

void setupField(std::vector<std::vector<int>>& field, const FieldInfo& fieldInfo) {
	for(size_t r{0}; r<fieldInfo.row; ++r) {
		for(size_t c{0}; c<fieldInfo.col; ++c) {
			if(field[r][c] == -1) continue;
			int count{0};
			for(size_t i{0}; i<8; ++i) {
				size_t adjR{r+d[i][0]};
				size_t adjC{c+d[i][1]};
				if(isValid(adjR, adjC, fieldInfo) && field[adjR][adjC] == -1)
					++count;
			}
			field[r][c] = count;
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
        for(size_t r{0}; r<fieldInfo.row; ++r) {
        	for(size_t c{0}; c<fieldInfo.col; ++c) {
               	std::cin >> minesField[r][c];
        	}
        }
        std::cout << '\n';
        setupField(minesField, fieldInfo);
        for(size_t r{0}; r<fieldInfo.row; ++r) {
        	for(size_t c{0}; c<fieldInfo.col; ++c) {
        		std::cout << minesField[r][c] << " ";
        	}
        	std::cout << '\n';
        }
    }
}

// https://judge.koreatech.ac.kr/showsource.php?id=71148

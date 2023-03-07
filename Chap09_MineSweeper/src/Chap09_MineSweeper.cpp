//============================================================================
// Name        : Chap09_MineSweeper.cpp
// Author      : 2019136056 박세현
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstddef>
#include <queue>
#include <utility>

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

int openCell(const std::vector<std::vector<int>> field, std::vector<std::vector<bool>>& visited, const FieldInfo& fieldInfo, const int r, const int c) {
	if(field[r][c] > 0)
		return field[r][c];
	else if(field[r][c] == 0) {
		std::queue<std::pair<int, int>> queue;
		queue.emplace(r, c);
		int count{0};
		++count;
		while(!queue.empty()) {
			auto[x,y] {queue.front()};
			queue.pop();
			visited[x][y] = true;

			for(int i{0}; i<8; ++i) {
				int nextR{x+d[i][0]};
				int nextC{y+d[i][1]};
				if(isValid(nextR, nextC, fieldInfo)) {
					if(!visited[nextR][nextC]) {
						visited[nextR][nextC] = true;
						if(field[nextR][nextC] == 0) {
							queue.emplace(nextR, nextC);
							++count;
						}
						else if(field[nextR][nextC] > 0) {
							++count;
						}
					}
				}
			}
		}
	return count;
	}
	else if(field[r][c] == -1)
		return field[r][c];

	return 1;
}

int main() {
	int T{0};
	std::cin >> T;
	for(size_t t{0}; t<T; ++t) {
		int S{0};
		std::cin >> S;
		const FieldInfo& fieldInfo{S==0? smallInfo: S==1? mediumInfo: largeInfo};
		std::vector<std::vector<int>> minesField(fieldInfo.row, std::vector<int>(fieldInfo.col));
		for(size_t r{0}; r<fieldInfo.row; ++r) {
			for(size_t c{0}; c<fieldInfo.col; ++c) {
				std::cin >> minesField[r][c];
			}
		}
		std::vector<std::vector<int>> cellInfo(3, std::vector<int>(2));
		for(size_t i{0}; i<cellInfo.size(); ++i) {
			for(size_t j{0}; j<cellInfo[0].size(); ++j) {
				std::cin >> cellInfo[i][j];
			}
		}
		std::vector<std::vector<bool>> visited(fieldInfo.row, std::vector<bool>(fieldInfo.col, false));
		for(size_t i{0}; i<cellInfo.size(); ++i) {
			std::cout << openCell(minesField, visited, fieldInfo, cellInfo[i][0], cellInfo[i][1]) << " ";
		}
	}
	return 0;
}

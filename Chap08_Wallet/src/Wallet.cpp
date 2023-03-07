/*
 * Wallet.cpp
 *
 *  Created on: 2022. 5. 6.
 *      Author: SEHYEON
 */

#include "Wallet.h"
#include <iostream>
#include <stdexcept>

void Wallet::add(int denomination, int amount)
{
	if(amount <= 0) throw std::invalid_argument{"음수 또는 0개 입력"};
	M[findMType(denomination)] += amount;
}

void Wallet::spend(int amount)
{
	if(amount > getCurrentAmount()) throw std::invalid_argument{"현재금액보다 많은 돈"};
	if(amount % 100 != 0) throw std::invalid_argument{"만들 수 있는 금액 아님"};
	if(amount <= 0) throw std::invalid_argument{"음수 또는 0원 사용 시도"};

	int remind{amount};
	int memoryIDX[6]{0,};
	// 지갑의 현재 상태로 amount를 만들 수 있는 경우
	for(int i{5}; remind != 0 && i>=0; --i) {
		if(M[i] > 0) {
			if(M[i] >= (remind / MONEY[i])) {
				memoryIDX[i] = remind / MONEY[i];
				remind -= MONEY[i] * memoryIDX[i];
			}
			else if(remind >= MONEY[i]) {
				memoryIDX[i] = M[i];
				remind -= MONEY[i] * memoryIDX[i];
			}
		}
	}
	if (remind == 0) {
		for(size_t i{0}; i<6; ++i) {
			M[i] -= memoryIDX[i];
			memoryIDX[i] = 0;
			remind = 0;
		}
	}
	// 지갑의 현재 상태로 만들 수 없고 거스름돈을 활용해야하는 경우
	else {
		int num{0};
		if(amount < 500) 		num = 1;
		else if(amount < 1000)  num = 2;
		else if(amount < 5000)  num = 3;
		else if(amount < 10000) num = 4;
		else if(amount < 50000) num = 5;
		else					num = 6;

		int midSum{0};
		for(size_t i{0}; i<num; ++i) {
			midSum += MONEY[i] * M[i];
		}
		int differ{0};
		// 최소 액면가들로 지불 후 거스름돈 반환
		if(midSum >= amount) {
			int tmp{amount};
			for(size_t i{0}; i<=num; ++i) {
				while((MONEY[i] * M[i] >= tmp) && tmp >= 0) {
					differ += MONEY[i];
					--M[i];
					tmp -= MONEY[i];
				}
			}
			differ -= amount;
		}
		// 큰 액면가를 지불 후 거스름돈 반환
		else {
			while(M[num] == 0) {
				++num;
			}
			differ = MONEY[num] - amount;
			--M[num];
		}
		// 최소 액면가 수 거스름돈 계산
		for(size_t i{5}; differ != 0 && i>=0; --i) {
			M[i] += differ / MONEY[i];
			differ -= MONEY[i] * (differ / MONEY[i]);
		}
	}
}

void Wallet::clear()
{
	for(size_t i{0}; i<6; ++i) {
		M[i] = 0;
	}
}

int Wallet::getCurrentAmount() const noexcept
{
	int totalAmount{0};
	for(int i{0}; i<6; ++i) {
		totalAmount += MONEY[i] * M[i];
	}
	return totalAmount;
}

int Wallet::findMType(int denomination)
{
	int idx{6};
	for (size_t i{0}; i<6; ++i) {
		if(denomination == MONEY[i]){
			idx = i;
		}
	}
	if(idx == 6) throw std::invalid_argument{"올바르지않은 화폐단위"};
	else return idx;
}

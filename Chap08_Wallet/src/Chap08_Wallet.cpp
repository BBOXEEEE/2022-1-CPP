//============================================================================
// Name        : Chap08_Wallet.cpp
// Author      : 2019136056 박세현
// Version     : 2022학년도 1학기
// Copyright   : 
// Description : 과제7. Wallet Class
//============================================================================

#include <iostream>
#include "Wallet.h"

void addTest1() {
	// 정상적인 add 메소드 호출
	Wallet wallet;
	wallet.add(100, 4);
	wallet.add(5000, 1);
	wallet.add(50000, 1);
	std::cout << wallet.getCurrentAmount() << '\n';
}

void addTest2() {
	// 화폐단위가 아닌 denomination 값 입력
	Wallet wallet;
	wallet.add(3000, 3);
}

void addTest3() {
	// amount 인자 범위 error (0 또는 음수)
	Wallet wallet;
	wallet.add(500,0);
}

void clearTest() {
	// 지갑 상태 clear
	Wallet wallet;
	wallet.add(5000, 2);
	wallet.add(50000, 4);
	std::cout << wallet.getCurrentAmount() << '\n';
	wallet.clear();
	std::cout << wallet.getCurrentAmount() << '\n';
}

void spendTest1() {
	// 6가지 화폐단위를 통해 만들 수 없는 금액 (ex. 10원 or 50원 단위)
	Wallet wallet;
	wallet.add(5000, 2);
	wallet.add(10000, 1);
	wallet.spend(15050);
}

void spendTest2() {
	// 지갑의 현재금액보다 많은 양의 돈을 spend 하는 경우
	Wallet wallet;
	wallet.add(1000, 2);
	wallet.add(5000, 1);
	wallet.spend(8000);
}

void spendTest3() {
	// 음수 또는 0원 spend 하는 경우
	Wallet wallet;
	wallet.add(1000, 2);
	wallet.add(10000, 2);
	wallet.spend(0);
}

void spendTest4() {
	// 정상동작하는 경우
	Wallet wallet;
	wallet.add(100, 3);
	wallet.add(500, 4);
	wallet.add(1000, 1);
	wallet.add(5000, 2);
	wallet.add(10000, 2);
	wallet.add(50000, 1);
	std::cout << wallet.getCurrentAmount() << '\n';
	// 지갑의 현재 상태로 만들 수 있는 금액 spend
	wallet.spend(11300);
	std::cout << wallet.getCurrentAmount() << '\n';
	// 거스름돈을 받아야하는 경우 1) 작은 액면가로 지불 후 거스름돈 받는 경우
	wallet.spend(9500);
	std::cout << wallet.getCurrentAmount() << '\n';
	// 거스름돈을 받아야하는 경우 2) 큰 액면가로 지불 후 거스름돈 받는 경우
	wallet.spend(45000);
	std::cout << wallet.getCurrentAmount() << '\n';
	wallet.clear();
	std::cout << wallet.getCurrentAmount() << '\n';
}

int main() {
	// addTest1();
	// addTest2();
	// addTest3();
	// clearTest();
	// spendTest1();
	// spendTest2();
	// spendTest3();
	spendTest4();
	return 0;
}

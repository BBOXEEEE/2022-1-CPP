//============================================================================
// Name        : Practice03_BankAccount.cpp
// Author      : 2019136056 박세현
// Version     : 2022학년도 1학기
// Copyright   : 
// Description : Chap11. 클래스 예제(Bank Account)
//============================================================================

#include <iostream>
#include "BankAccount.h"

int main() {

	BankAccount aliceAccount;
	aliceAccount.deposit(10000);
	std::cout << aliceAccount.getBalance() << '\n';
	aliceAccount.deposit(-5000);
	std::cout << aliceAccount.getBalance() << '\n';
	aliceAccount.withdraw(5000);
	std::cout << aliceAccount.getBalance() << '\n';
	aliceAccount.withdraw(10000);
	std::cout << aliceAccount.getBalance() << '\n';

	BankAccount bobAccount(1000);
	return 0;
}

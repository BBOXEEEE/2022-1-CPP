/*
 * BankAccount.cpp
 *
 *  Created on: 2022. 4. 25.
 *      Author: SEHYEON
 */

#include "BankAccount.h"
#include <stdexcept>
#include <limits>

BankAccount::BankAccount(int amount) {
	deposit(amount);
}

unsigned int BankAccount::getBalance() const noexcept
{
	return mBalance;
}

void BankAccount::deposit(int amount)
{
	if(amount<=0) throw std::invalid_argument{"음수 또는 0원 입급"};
	if(amount > std::numeric_limits<decltype(mBalance)>::max()-mBalance)
		throw std::invalid_argument{"Overflow"};
	mBalance += amount;
}

void BankAccount::withdraw(int amount)
{
	if(amount<=0) throw std::invalid_argument{"음수 또는 0원 출금"};
	if(amount > mBalance) throw Insufficient_fund{};
	if(amount>0 && amount <= mBalance) mBalance -= amount;
}


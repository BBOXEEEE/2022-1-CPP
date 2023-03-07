/*
 * BankAccount.h
 *
 *  Created on: 2022. 4. 25.
 *      Author: SEHYEON
 */

#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include <stdexcept>
#include <string>

class Insufficient_fund: public std::logic_error{
public:
	Insufficient_fund(std::string_view msg="잔액부족!"):
		std::logic_error{msg.data()}{}
	virtual ~Insufficient_fund() = default;
};

class BankAccount {
private:
	unsigned int mBalance{0};
public:
	BankAccount() = default;
	BankAccount(int amount);
	unsigned int getBalance() const noexcept;	// 잔액 조회
	void deposit(int amount);	// 입금
	void withdraw(int amount);	// 출금
};

#endif /* BANKACCOUNT_H_ */

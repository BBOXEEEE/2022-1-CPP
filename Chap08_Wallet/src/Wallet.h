/*
 * Wallet.h
 *
 *  Created on: 2022. 5. 6.
 *      Author: SEHYEON
 */

#ifndef WALLET_H_
#define WALLET_H_

#include <vector>

class Wallet {
private:
	std::vector<int> M = std::vector<int>(6,0);
	const int MONEY[6] {100, 500, 1000, 5000, 10000, 50000};
public:
	Wallet() = default;
	virtual ~Wallet() = default;
	void add(int denomination, int amount);
	void spend(int amount);
	void clear();
	int getCurrentAmount() const noexcept;
private:
	int findMType(int denomination);
};

#endif /* WALLET_H_ */

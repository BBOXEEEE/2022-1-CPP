/*
 * Fraction.cpp
 *
 *  Created on: 2022. 5. 23.
 *      Author: SEHYEON
 */

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <cmath>
#include "Fraction.h"

Fraction::Fraction(int n, int d) : n{n}, d{d} {
	if(d==0) throw std::invalid_argument{"Franction(n, d)_: 분모는 0이 될 수 없음"};
	if((n>=0 && d<0) || (n<0 && d<0)) {
		this->n = -n;
		this->d = -d;
	}
}
int Fraction::numerator() const noexcept {return n;}
int Fraction::denominator() const noexcept {return d;}

Fraction::operator std::string() const noexcept{
	if(n % d == 0) return std::to_string(n/d);
	return std::to_string(n) + "/" + std::to_string(d);
}

Fraction::operator double() const{
	return static_cast<double>(n) / static_cast<double>(d);
}

Fraction Fraction::operator-() const noexcept{
	return Fraction{-n, d};
}

Fraction Fraction::operator+ (const Fraction& other) const{
	int resultN, resultD;
	resultN = (d * other.n) + (n * other.d);
	resultD = d * other.d;
	Fraction tmp{resultN, resultD};
	return tmp.trimFraction();
}
Fraction Fraction::operator- (const Fraction& other) const{
	int resultN, resultD;
	resultN = other.d * n - d * other.n;
	resultD = d * other.d;
	Fraction tmp{resultN, resultD};
	return tmp.trimFraction();
}
Fraction Fraction::operator* (const Fraction& other) const {
	int resultN, resultD;
	resultN = n * other.n;
	resultD = d * other.d;
	Fraction tmp{resultN, resultD};
	return tmp.trimFraction();
}
Fraction Fraction::operator/ (const Fraction& other) const{
	int resultN, resultD;
	resultN = n * other.d;
	resultD = d * other.n;
	Fraction tmp{resultN, resultD};
	return tmp.trimFraction();
}

const Fraction& Fraction::trimFraction() noexcept{
	int min = std::min(std::abs(n), std::abs(d));
	int gcd{0};
	for(int i{1}; i<=min; ++i) {
		if((n % i) == 0 && (d % i) == 0) {
			gcd = i;
		}
	}
	n /= gcd;
	d /= gcd;
	return *this;
}

bool Fraction::operator== (const Fraction& other) const{
	double a{static_cast<double>(*this)};
	double b{static_cast<double>(other)};
	return a==b;
}
bool Fraction::operator!= (const Fraction& other) const{
	return !operator==(other);
}
bool Fraction::operator> (const Fraction& other) const{
	double a{static_cast<double>(*this)};
	double b{static_cast<double>(other)};
	return a > b;
}
bool Fraction::operator>= (const Fraction& other) const{
	return !operator<(other);
}
bool Fraction::operator< (const Fraction& other) const{
	return other.operator>(*this);
}
bool Fraction::operator<= (const Fraction& other) const{
	return !operator>(other);
}

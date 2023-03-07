//============================================================================
// Name        : Chap10_Fraction.cpp
// Author      : 2019136056 박세현
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Fraction.h"

void testConstructor() {
	Fraction a{};
	Fraction b{1,2};
	Fraction c{-1,2};
	Fraction d{1,-2};
	Fraction e{-1,-2};
	std::cout << static_cast<std::string>(a) << '\n';
	std::cout << static_cast<std::string>(b) << '\n';
	std::cout << static_cast<std::string>(c) << '\n';
	std::cout << static_cast<std::string>(d) << '\n';
	std::cout << static_cast<std::string>(e) << '\n';
	Fraction f{1,0};
}

void testTypeCast() {
	Fraction a{1,2};
	Fraction b{3,2};
	std::cout << static_cast<double>(a) << '\n';
	std::cout << static_cast<double>(b) << '\n';
}

void testArithmeticOperator(){
	Fraction a{1,2};
	Fraction b{3,4};
	std::cout << static_cast<std::string>(-a) << '\n';
	std::cout << static_cast<std::string>(a+b) << '\n';
	std::cout << static_cast<std::string>(a-b) << '\n';
	std::cout << static_cast<std::string>(a*b) << '\n';
	std::cout << static_cast<std::string>(a/b) << '\n';
}

void testComparisonOperator(){
	Fraction a{1,3};
	Fraction b{1,2};
	Fraction c{2,4};
	std::cout << "a == b ? " << (a==b) << '\n';
	std::cout << "a != b ? " << (a!=b) << '\n';
	std::cout << "a > b ? " << (a>b) << '\n';
	std::cout << "a >= b ? " << (a>=b) << '\n';
	std::cout << "a < b ? " << (a<b) << '\n';
	std::cout << "a <= b ? " << (a<=b) << '\n';
	std::cout << "b == c ? " << (b==c) << '\n';
	std::cout << "b >= c ? " << (b>=c) << '\n';
	std::cout << "b <= c ? " << (b<=c) << '\n';
}

int main() {
	// testConstructor();
	// testTypeCast();
	 testArithmeticOperator();
	// testComparisonOperator();
	return 0;
}

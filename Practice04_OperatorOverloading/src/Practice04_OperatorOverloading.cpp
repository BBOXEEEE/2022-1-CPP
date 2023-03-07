//============================================================================
// Name        : Practice04_OperatorOverloading.cpp
// Author      : 2019136056 박세현
// Version     : 2022학년도 1학기
// Copyright   : 
// Description : Chpa13. 연산자 재정의 예제 (단항, 이항, 비교, 산술, 대입, 복합)
//============================================================================

#include <iostream>
#include "Group.h"

void test_constructor() {
	Group a{7, 5};
	Group b{7, 11};
	Group c{7, -5};
	a.debugPrint();
	b.debugPrint();
	c.debugPrint();
}

void test_add() {
	Group a{7, 5};
	Group b{7, 3};
	Group c{7, 4};
	c = a+b;
	c.debugPrint();
}

void test_inverse() {
	Group a{7, 5};
	a = -a;
	a.debugPrint();
}

int main() {
	// test_constructor();
	// test_add();
	test_inverse();
	return 0;
}

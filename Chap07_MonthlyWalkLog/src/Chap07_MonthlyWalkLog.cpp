//============================================================================
// Name        : Chap07_MonthlyWalkLog.cpp
// Author      : 2019136056 박세현
// Version     : 2022학년도 1학기
// Copyright   : 
// Description : Chap-09 연습문제 MonthlyWalkLog
//============================================================================

#include <iostream>
#include "MonthlyWalkLog.h"

void test_invalid_year() {
	MonthlyWalkLog log{1950, 2};
	std::cout << log.year << ", " << log.month << '\n';
}

void test_invalid_month() {
	MonthlyWalkLog log{1980,13};
	std::cout << log.year << ", " << log.month << '\n';
}

void test_invalid_days() {
	MonthlyWalkLog log{2007,2};
	log.recordDistance(30, 50.3);
}

void test_leap_year() {
	MonthlyWalkLog log{2000, 2};
	log.recordDistance(29, 100.5);
}

int main() {
	test_invalid_year();
	test_invalid_month();
	test_leap_year();
	test_invalid_days();

	return 0;
}

/* ===========================================================================================================
 1) dailyDistance의 용량이 31인 이유는 월 최소 일과 최대 일이 28~31로 큰 차이가 없기 때문에
	동적할당을 사용하지 않고, 최대값인 31로 용량을 설정하는 것이 효율적이기 때문이다.
 2) year, month 멤버를 private로 접근제어하게 되면, 클래스 외부에서 직접 접근이 불가능하다.
	year와 month는 test를 위해서 자주 접근해야하는데 private로 선언하게 되면 getter 메소드를 별도
	정의해야하기 때문에 public에 선언한다. 이때, year와 month는 최초 객체 생성 후 변하지 않는 값이기에
	const를 붙여 접근은 편하게 하면서 수정은 불가능하게 하기 위해 public에 선언 후 const 수식어를 붙인다.
 3) 예외 1 : 해당 월의 최대 일수를 벗어난 경우
	예외 2 : 윤년일 경우와 아닐 경우 2월의 최대 일 수를 달리 해야함
	예외 3 : 음수인 distance 값이 전달되었을
 4) 방법 1 : 유효하지 않은 년도와 월 정보가 제공되면, 년도의 최소값인 1970년 1월로 초기화한다.
	방법 2 : 유효하지 않은 년도와 월 정보가 제공되면, 년도와 월의 값을 0으로 초기화한다.
			 이 방법이 방법 1보다 안전할 것이라 생각합니다.
=============================================================================================================== */

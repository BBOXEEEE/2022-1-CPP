/*
 * MonthlyWalkLog.cpp
 *
 *  Created on: 2022. 4. 27.
 *      Author: SEHYEON
 */

#include <iostream>
#include "MonthlyWalkLog.h"

MonthlyWalkLog::MonthlyWalkLog(int year, int month): year{checkYear(year)}, month{checkMonth(month)} {}

void MonthlyWalkLog::recordDistance(int day, double distance)
{
	if(day <= getNumberOfDays(year, month) && distance >=0) {
		dailyDistance[day] += distance;
	}
	else throw std::out_of_range("replace: days out of bound");
}

int MonthlyWalkLog::checkYear(int year) const
{
	if(year >= 1970) return year;
	else return 0;
}

int MonthlyWalkLog::checkMonth(int month) const
{
	if(month >= 1 && month <=12) return month;
	else return 0;
}

bool MonthlyWalkLog::isLeapYear(int year)
{
	if((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0)) return true;
	else return false;
}

int MonthlyWalkLog::getNumberOfDays(int year, int month)
{
	switch(month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31; break;
	case 4: case 6: case 9: case 11:
		return 30; break;
	case 2:
		if(isLeapYear(year)) return 29; break;
		return 28; break;
	}
	return 0;
}

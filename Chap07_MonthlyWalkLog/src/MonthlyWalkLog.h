/*
 * MonthlyWalkLog.h
 *
 *  Created on: 2022. 4. 27.
 *      Author: SEHYEON
 */

#ifndef MONTHLYWALKLOG_H_
#define MONTHLYWALKLOG_H_

class MonthlyWalkLog {
private:
	double dailyDistance[31];
public:
	const int year;
	const int month;
public:
	MonthlyWalkLog(int year, int month);
	void recordDistance(int day, double disatance);
private:
	int checkYear(int year) const;
	int checkMonth(int month) const;
	bool isLeapYear(int year);
	int getNumberOfDays(int year, int month);
};

#endif /* MONTHLYWALKLOG_H_ */

/*
 * Person.h
 *
 *  Created on: 2022. 5. 30.
 *      Author: SEHYEON
 */

#ifndef PERSON_H_
#define PERSON_H_
#include <string>

class Person{
private:
	std::string mName;
	int mAge{0};
public:
	Person() = default;
	Person(std::string_view name, int age):
		mName(name.data()), mAge{age}{}
	int getAge() const{
		return mAge;
	}
	void setAge(int age){
		if(age>0&&age<200)
			mAge = age;
	}
	const std::string& getName() const{
		return mName;
	}
	void setName(std::string_view name){
		mName = name;
	}
};
#endif /* PERSON_H_ */

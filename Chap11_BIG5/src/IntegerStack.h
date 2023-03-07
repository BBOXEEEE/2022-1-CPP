/*
 * IntegerStack.h
 *
 *  Created on: 2022. 5. 30.
 *      Author: SEHYEON
 */

#ifndef INTEGERSTACK_H_
#define INTEGERSTACK_H_
#include <cstddef>

class IntegerStack{
private:
	size_t capacity;
	size_t top{0};
	int* buf;
	void increaseCapacity(){
		capacity *= 2;
		int* tmp{new int[capacity]{}};
		std::copy(buf, buf+top, tmp);
		delete [] buf;
		buf = tmp;
	}
public:
	explicit IntegerStack(size_t capacity=5): capacity{capacity}, buf{capacity? new int[capacity]: nullptr}{}
	virtual ~IntegerStack(){
			delete [] buf;
		}
	// 복사 생성자
	IntegerStack(const IntegerStack& other) : capacity{other.capacity}, top(other.top), buf{capacity? new int[capacity]: nullptr} {
		std::cout << "copy constructor" << '\n';
		std::copy(other.buf, other.buf+other.top, buf);
	}
	// 이동 생성자
	IntegerStack(IntegerStack&& other) noexcept: IntegerStack() {
		std::cout << "move constructor" << '\n';
		swap(other);
	}
	/* copy and swap idiom 사용 X
	 IntegerStack(IntegerStack&& other): capacity{other.capacity}, top{other.top}, buf{other.buf}{
		other.buf = nullptr;
	}
	 */
	void swap(IntegerStack& other) noexcept{
		std::swap(capacity, other.capacity);
		std::swap(top, other.top);
		std::swap(buf, other.buf);
	}
	bool isEmpty() const{
		return top==0;
	}
	size_t size() const{
		return top;
	}
	int peek() const{
		return buf[top-1];
	}
	void push(int n){
		if(top==capacity) increaseCapacity();
		buf[top++] = n;
	}
	// 복사 생성자 등의 테스트를 위해 pop한 위치의 값을 바꾸고 있음
	int pop(){
		int ret{-1};
		std::swap(ret, buf[top-1]);
		--top;
		return ret;
	}
	// 복사 대입 연산자
	const IntegerStack& operator=(const IntegerStack& other) {
		std::cout << "copy assignment" << '\n';
		if(this != &other) {
			IntegerStack tmp(other);
			swap(tmp);
		}
		return *this;
	}
	// 이동 대입 연산자
	const IntegerStack& operator=(IntegerStack&& other) noexcept{
		std::cout << "move assignment" << '\n';
		swap(other);
		return *this;
	}
};


#endif /* INTEGERSTACK_H_ */

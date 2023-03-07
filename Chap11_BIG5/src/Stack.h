/*
 * Stack.h
 *
 *  Created on: 2022. 5. 30.
 *      Author: SEHYEON
 */

#ifndef STACK_H_
#define STACK_H_
#include <cstddef>
#include <utility>

template <typename T>
class Stack{
	size_t capacity;
	size_t top{0};
	T* buf;
	void increaseCapacity(){
		capacity *= 2;
		T* tmp{new T[capacity]{}};
		std::copy(buf, buf+top, tmp);
		delete [] buf;
		buf = tmp;
	}
public:
	explicit Stack(size_t capacity=5): capacity{capacity}, buf{capacity? new T[capacity]: nullptr}{}
	virtual ~Stack(){
		delete [] buf;
	}
	// 복사 생성자
	Stack(const Stack& other): capacity{other.capacity}, top{other.top}, buf{capacity? new T[capacity]: nullptr} {
		std::cout << "copy constructor" << '\n';
		std::copy(other.buf, other.buf+other.top, buf);
	}
	// 이동 생성자
	Stack(Stack&& other) noexcept: Stack() {
		std::cout << "move constructor" << '\n';
		swap(other);
	}
	/* copy and swap idiom 사용 X
	Stack(Stack&& other): capacity{other.capacity}, top{other.top}, buf{other.buf}{
		other.buf = nullptr;
	}
	*/
	void swap(Stack& other) noexcept{
		std::swap(capacity, other.capacity);
		std::swap(top, other.top);
		std::swap(buf, other.buf);
	}
	bool isEmpty() const noexcept{
		return top==0;
	}
	size_t size() const noexcept{
		return top;
	}
	T peek() const noexcept{
		return buf[top-1];
	}
	template <typename... Ts>
	void emplace(Ts&&... args){
		if(top==capacity) increaseCapacity();
		new (&buf[top++]) T(std::forward<Ts>(args)...);
	}
	void push(const T& n){
		if(top==capacity) increaseCapacity();
		buf[top++] = n;
	}
	// 복사 생성자 등의 테스트를 위해 pop한 위치의 값을 바꾸고 있음
	T pop(){
		T ret{};
		std::swap(ret, buf[top-1]);
		--top;
		return ret;
	}
	// 복사 대입 연산자
	const Stack& operator=(const Stack& other) {
		std::cout << "copy assignment" << '\n';
		if(this != &other) {
			Stack tmp(other);
			swap(tmp);
		}
		return *this;
	}
	// 이동 대입 연산자
	const Stack& operator=(Stack&& other) noexcept{
		std::cout << "move assignment" << '\n';
		swap(other);
		return *this;
	}
};


#endif /* STACK_H_ */

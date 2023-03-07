//============================================================================
// Name        : Chap11_BIG5.cpp
// Author      : 2019136056 박세현
// Version     : 2022학년도 1학기
// Copyright   : 
// Description : Chap11_ BIG5 (Stack 자료구조)
//============================================================================

#include <iostream>
#include <string>
#include "IntegerStack.h"
#include "Stack.h"
#include "Person.h"

void test_IntegerStack(){
	IntegerStack stack{3};
	stack.push(5);
	stack.push(3);
	stack.push(7);
	stack.push(1);
	while(!stack.isEmpty()){
		std::cout << stack.pop() << '\n';
	}
}

void test_GeneralStack(){
	Stack<std::string> stack{3};
	stack.push("apple");
	stack.push("grape");
	stack.push("tomato");
	stack.push("banana");
	while(!stack.isEmpty()){
		std::cout << stack.pop() << '\n';
	}
}

void test_emplace(){
	Stack<Person> stack{3};
	stack.emplace("홍길동", 15);
	stack.emplace("성춘향", 14);
	stack.emplace("이몽룡", 14);
	stack.emplace("임꺽정", 16);
	while(!stack.isEmpty()){
		std::cout << stack.pop().getName() << '\n';
	}
}

// 복사생성자_IntegerStack
void test_copyConstructor_IntegerStack(){
	IntegerStack stack1{};
	stack1.push(5);
	stack1.push(3);
	stack1.push(7);
	stack1.push(1);
	IntegerStack stack2(stack1);
	while(!stack1.isEmpty()){
		int n{stack1.pop()};
		if(n!=stack2.pop()) throw std::runtime_error("test_copyConstructor: IntegerStack");
		std::cout << n << '\n';
	}
}

// 이동생성자_IntegerStack
void test_moveConstructor_IntegerStack(){
	IntegerStack stack1{};
	stack1.push(5);
	stack1.push(3);
	stack1.push(7);
	stack1.push(1);
	IntegerStack stack2(std::move(stack1));
	if(!stack1.isEmpty()) throw std::runtime_error("test_moveConstructor: IntegerStack, stack1 is not empty");
	while(!stack2.isEmpty()){
		std::cout << stack2.pop() << '\n';
	}
}

// 복사대입연산자_IntegerStack
void test_copyAssignment_IntegerStack(){
	IntegerStack stack1{};
	stack1.push(5);
	stack1.push(3);
	stack1.push(7);
	stack1.push(1);
	IntegerStack stack2{};
	stack2 = stack1;
	while(!stack1.isEmpty()){
		int n{stack1.pop()};
		if(n!=stack2.pop()) throw std::runtime_error("test_copyAssignment: IntegerStack");
		std::cout << n << '\n';
	}
}

// 이동대입연산자_IntegerStack
void test_moveAssignment_IntegerStack(){
	IntegerStack stack1{};
	stack1.push(5);
	stack1.push(3);
	stack1.push(7);
	stack1.push(1);
	IntegerStack stack2{};
	stack2 = std::move(stack1);
	if(!stack1.isEmpty()) throw std::runtime_error("test_moveAssignment: IntegerStack, stack1 is not empty");
	while(!stack2.isEmpty()){
		std::cout << stack2.pop() << '\n';
	}
}

// 복사생성자_Stack
void test_copyConstructor_GeneralStack(){
	Stack<std::string> stack1{3};
	stack1.push("apple");
	stack1.push("grape");
	stack1.push("tomato");
	stack1.push("banana");
	Stack<std::string> stack2(stack1);
	while(!stack1.isEmpty()){
		std::string s(stack1.pop());
		if(s!=stack2.pop()) throw std::runtime_error("test_copyConstructor: GeneralStack");
		std::cout << s << '\n';
	}
}

// 이동생성자_Stack
void test_moveConstructor_GeneralStack(){
	Stack<std::string> stack1{3};
	stack1.push("apple");
	stack1.push("grape");
	stack1.push("tomato");
	stack1.push("banana");
	Stack<std::string> stack2(std::move(stack1));
	if(!stack1.isEmpty()) throw std::runtime_error("test_moveConstructor: GeneralStack, stack1 is not empty");
	while(!stack2.isEmpty()){
		std::cout << stack2.pop() << '\n';
	}
}

// 복사대입연산자_Stack
void test_copyAssignment_GeneralStack(){
	Stack<std::string> stack1{3};
	stack1.push("apple");
	stack1.push("grape");
	stack1.push("tomato");
	stack1.push("banana");
	Stack<std::string> stack2{};
	stack2 = stack1;
	while(!stack1.isEmpty()){
		std::string s(stack1.pop());
		if(s!=stack2.pop()) throw std::runtime_error("test_copyAssignment: GeneralStack");
		std::cout << s << '\n';
	}
}

// 이동대입연산_Stack
void test_moveAssignment_GeneralStack(){
	Stack<std::string> stack1{3};
	stack1.push("apple");
	stack1.push("grape");
	stack1.push("tomato");
	stack1.push("banana");
	Stack<std::string> stack2{};
	stack2 = std::move(stack1);
	if(!stack1.isEmpty()) throw std::runtime_error("test_moveAssignment: GeneralStack, stack1 is not empty");
	while(!stack2.isEmpty()){
		std::cout << stack2.pop() << '\n';
	}
}


int main() {
	// test_IntegerStack();
	// test_GeneralStack();
	// test_emplace();
	// test_copyConstructor_IntegerStack();
	// test_moveConstructor_IntegerStack();
	//test_copyConstructor_GeneralStack();
	// test_moveConstructor_GeneralStack();
	//test_copyAssignment_IntegerStack();
	// test_moveAssignment_IntegerStack();
	// test_copyAssignment_GeneralStack();
	//test_moveAssignment_GeneralStack();
	return 0;
}

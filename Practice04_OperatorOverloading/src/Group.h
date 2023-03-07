/*
 * Group.h
 *
 *  Created on: 2022. 5. 16.
 *      Author: SEHYEON
 */

#ifndef GROUP_H_
#define GROUP_H_
#include <iostream>

class Group {
private:
	const int p;
	int n;
	int reduce(int val) noexcept{
		val %= p;
		return val<0? val+p: val;
	}
	void testModulus(const Group& other) const{
		if(p!=other.p) throw std::invalid_argument{"p가 불일치"};
	}
public:
	Group(int p, int n): p{p}, n{reduce(n)}{};
	virtual ~Group() = default;

	Group operator=(const Group& other) {
		testModulus(other);
		n = other.n;
		return *this;
	}

	// 타입 변환
	explicit operator int() const noexcept{
		return n;
	}
	explicit operator std::string() const noexcept{
		return std::string("("+ std::to_string(n) +" mod " + std::to_string(p) + ")");
	}

	Group operator-() const noexcept{
		/*Group ret(*this);
		ret.n = p-n;
		return ret;
		*/
		return Group(p, p-n);
	}

	const Group& operator++() noexcept{
		n = (n+1) % p;
		return *this;
	}
	// 후위 증감 (현재값 return 후 1증가 -> 참조로 return X
	Group operator++(int) {
		Group tmp(*this);
		n = (n+1) % p;
		return tmp;
	}

	const Group& operator--() noexcept{
		n = (n+p-1) % p;
		return *this;
	}
	// 후위 증감 연산자 (현재값 return 후 1감 -> 참조로 return X
	Group operator--(int) {
		Group tmp(*this);
		--(*this);
		return tmp;
	}

	Group operator+(const Group& other) const{
		testModulus(other);
		Group ret(*this);
		ret.n = (ret.n+other.n) % p;
		return ret;
	}

	Group operator+(int m) const{
		return operator+(Group(p, m));
	}

	Group operator-(const Group& other) const {
		return operator+(-other);
	}

	const Group& operator+=(const Group& other) {
		testModulus(other);
		n = (n + other.n) % p;
		return *this;
	}

	const Group& operator-=(const Group& other) {
		return operator+=(-other);
	}

	// 비교 연산자
	bool operator==(const Group& other) const {
		testModulus(other);
		return n==other.n;
	}
	bool operator!=(const Group& other) const {
		return !operator==(other);
	}
	bool operator>(const Group& other) const {
		testModulus(other);
		return n>other.n;
	}
	bool operator>=(const Group& other) const {
		return !operator<(other);
	}
	bool operator<(const Group& other) const {
		return other.operator>(*this);
	}
	bool operator<=(const Group& other) const {
		return !operator>(other);
	}

	void debugPrint(){
		std::cout << "(" << n << " : mod " << p << ")\n";
	}
	friend std::ostream& operator<<(std::ostream& os, const Group& o);
	friend std::istream& operator<<(std::istream& is, Group& o);
};

std::ostream& operator<<(std::ostream& os, const Group& o) {
	os << "(" << o.n << " : mod " << o.p << ")\n";
	return os;
}

std::istream& operator<<(std::istream& is, Group& o) {
	is >> o.n;
	o.n = o.reduce(o.n);
	return is;
}

#endif /* GROUP_H_ */

/*
 * KString.h
 *
 *  Created on: 2022. 5. 18.
 *      Author: SEHYEON
 */

#ifndef KSTRING_H_
#define KSTRING_H_
#include <cstddef>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

class KString {
private:
	size_t size{0};
	char* sbuf{nullptr};
public:
	KString() = default;
	KString(const char* s): size{strlen(s)}, sbuf{new char[size+1]}{
		std::copy(s, s+size+1, sbuf);
	}
	KString(const KString& other): size{other.size}, sbuf{new char[size+1]}{
		std::copy(other.sbuf, other.sbuf+size+1, sbuf);
	}
	virtual ~KString() {
		delete sbuf;
	}
	const KString& operator=(const KString& other) {
		if(this != &other) {
			delete sbuf;
			size = other.size;
			sbuf = new char[size+1];
			std::copy(other.sbuf, other.sbuf+size+1, sbuf);
		}
		return *this;
	}
	const char& operator[](size_t index) const{
		if(index >= size) throw std::range_error("");
		return sbuf[index];
	}
	char& operator[](size_t index) {
		return const_cast<char&>(std::as_const(*this)[index]);
	}
	const KString operator+(const KString& other) const{
		KString ret{};
		ret.size = size + other.size;
		ret.sbuf = new char[ret.size+1];
		std::copy(sbuf, sbuf+size, ret.sbuf);
		std::copy(other.sbuf, other.sbuf+other.size+1, ret.sbuf+size);
		return ret;
	}

	bool operator==(const KString& other) const{
		if(size==other.size){
			for(size_t i{0}; i<size; ++i)
				if(sbuf[i] != other.sbuf[i]) return false;
			return true;
		}
		else return false;
	}
	bool operator!=(const KString& other) const{
		return !operator==(other);
	}
	bool operator>(const KString& other) const{
		size_t minlen{std::min(size, other.size)};
		for(size_t i{0}; i<minlen; ++i)
			if(sbuf[i] > other.sbuf[i]) return true;
			else if(sbuf[i] < other.sbuf[i]) return false;
		return size > other.size;
	}
	bool operator>=(const KString& other) const{
		return !operator<(other);
	}
	bool operator<(const KString& other) const{
		return other.operator>(*this);
	}
	bool operator<=(const KString& other) const{
		return !operator>(other);
	}
};

#endif /* KSTRING_H_ */

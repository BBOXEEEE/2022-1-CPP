/*
 * Fraction.h
 *
 *  Created on: 2022. 5. 23.
 *      Author: SEHYEON
 */

#ifndef FRACTION_H_
#define FRACTION_H_

class Fraction {
private:
	int n{0};
	int d{1};
public:
	Fraction() = default;
	explicit Fraction(int n, int d=1);
	virtual ~Fraction() = default;
	int numerator() const noexcept;
	int denominator() const noexcept;
	explicit operator std::string() const noexcept;
	explicit operator double() const;
	Fraction operator-() const noexcept;
	Fraction operator+ (const Fraction& other) const;
	Fraction operator- (const Fraction& other) const;
	Fraction operator* (const Fraction& other) const;
	Fraction operator/ (const Fraction& other) const;
	const Fraction& trimFraction() noexcept;
	bool operator== (const Fraction& other) const;
	bool operator!= (const Fraction& other) const;
	bool operator> (const Fraction& other) const;
	bool operator>= (const Fraction& other) const;
	bool operator< (const Fraction& other) const;
	bool operator<= (const Fraction& other) const;
};

#endif /* FRACTION_H_ */

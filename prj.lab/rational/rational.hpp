#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <sstream>	
#include <cstdint>

class Rational {
public:
	Rational() = default;
	Rational(Rational&&) = default;
	Rational(const Rational& rhs) = default;
	~Rational() = default;
	explicit Rational(const std::int64_t num);
	Rational(const std::int64_t num, const std::int64_t denum);

	std::int64_t num() const { return n_; }
	std::int64_t den() const { return de_; }

	Rational& operator=(Rational&&) = default;
	Rational& operator=(const Rational& rhs);
	Rational& operator=(const std::int64_t rhs) { return operator=(Rational(rhs)); }
	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const std::int64_t rhs) { return operator+=(Rational(rhs)); }
	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const std::int64_t rhs) { return operator-=(Rational(rhs)); }
	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const std::int64_t rhs) { return operator*=(Rational(rhs)); }
	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const std::int64_t rhs) { return operator/=(Rational(rhs)); }
	Rational& operator++();
	Rational& operator--();
	Rational& operator-();
	bool operator==(const Rational& rhs) const { return ((rhs.n_ == n_) && (rhs.de_ == de_)) || ((rhs.n_ == 0) && (n_ == 0)); }
	bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	static const char separator{ '/' };

	const std::int64_t& get_Num() const { return n_; }
	const std::int64_t& get_Den() const { return de_; }

private:
	std::int64_t n_{ 0 };
	std::int64_t de_{ 1 };
	void cut_back();
	std::int64_t NOD(std::int64_t x, std::int64_t y);
	std::int64_t NOK(std::int64_t x, std::int64_t y);
};

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rhs);

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, const std::int64_t& rhs);
Rational operator+(const std::int64_t& lhs, const Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const std::int64_t& rhs);
Rational operator-(const std::int64_t& lhs, const Rational& rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const std::int64_t& rhs);
Rational operator*(const std::int64_t& lhs, const Rational& rhs);

Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const std::int64_t& rhs);
Rational operator/(const std::int64_t& lhs, const Rational& rhs);


bool operator==(const Rational& lhs, const std::int64_t& rhs);
bool operator==(const std::int64_t& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const std::int64_t& rhs);
bool operator!=(const std::int64_t& lhs, const Rational& rhs);

bool operator>=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const std::int64_t& rhs);
bool operator>=(const std::int64_t& lhs, const Rational& rhs);

bool operator>(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const std::int64_t& rhs);
bool operator>(const std::int64_t& lhs, const Rational& rhs);

bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const std::int64_t& rhs);
bool operator<=(const std::int64_t& lhs, const Rational& rhs);

bool operator<(const Rational& lhs, const Rational& rhs);
bool operator<(const Rational& lhs, const std::int64_t& rhs);
bool operator<(const std::int64_t& lhs, const Rational& rhs);

#endif
#include <iostream>	
#include <sstream>	
#include "complex.hpp"

/*struct Complex {
	Complex() {}
	~Complex() {}
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);
	bool operator==(const Complex& rhs) const { return (re == rhs.re) && (im == rhs.im); }
	bool operator!=(const Complex& rhs) const { return !operator==(rhs); }
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
	Complex& operator-=(const Complex& rhs);	
	Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }	
	Complex& operator*=(const Complex& rhs);	
	Complex& operator*=(const double rhs) { return operator*=(Complex(rhs)); }
	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs) { return operator/=(Complex(rhs)); }
	Complex& operator=(const Complex& rhs);
	Complex& operator=(const double rhs) { return operator=(Complex(rhs)); }
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double& rhs);
Complex operator+(const double& lhs, const Complex& rhs);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const double& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double& rhs);

Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double& rhs);
Complex operator*(const double& lhs, const Complex& rhs);

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double& rhs);
Complex operator/(const double& lhs, const Complex& rhs);

bool operator==(const Complex& lhs, const double& rhs);
bool operator==(const double& lhs, const Complex& rhs);
*/

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm);
}

bool testParse(const std::string& str)
{
	std::istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good()) {
		std::cout << "Read success: " << str << " -> " << z << "\n";
	}
	else {
		std::cout << "Read error: " << str << " -> " << z << "\n";
	}
	return istrm.good();
}


/*int main()
{
	
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9");

	Complex x, y;
	double d;

	// сумма двух комплексных
	x = Complex{ 1.5, 2.0 };
	y = Complex{ 2.5, 3.5 };
	std::cout << x << " + " << y << " == " << x + y << " Expected: {4.0, 5.5}\n";

	// разность двух комплексных
	x = Complex{ 3.0, 5.0 };
	y = Complex{ 1.5, 2.5 };
	std::cout << x << " - " << y << " == " << x - y << " Expected: {1.5, 2.5}\n";

	// произведение двух комплексных
	x = Complex{ 1.5, 2.0 };
	y = Complex{ 2.0, 3.0 };
	std::cout << x << " * " << y << " == " << x * y << " Expected: {-3,8.5}\n";

	// частное двух комплексных
	x = Complex{ 3.0, 5.0 };
	y = Complex{ 1.5, 2.5 };
	std::cout << x << " / " << y << " == " << x / y << " Expected: {2, 0}\n";

	// сумма вещественного и комплексного
	d = 2.5;
	x = Complex{ 1.5, 1.0 };
	std::cout << d << " + " << x << " == " << d + x << " Expected: {4.0, 1.0}\n";

	// разность вещественного и комплексного
	d = 4.5;
	x = Complex{ 12, 35 };
	std::cout << d << " - " << x << " == " << d - x << " Expected: {-7.5, -35}\n";

	// разность комплексного и вещественного
	x = Complex{ 3.0, -2.0 };
	d = 1.5;
	std::cout << x << " - " << d << " == " << x - d << " Expected: {1.5, -2}\n";

	// произведение вещественного и комплексного
	d = 2.0;
	x = Complex{ 1.5, -1.0 };
	std::cout << d << " * " << x << " == " << d * x << " Expected: {3.0, -2.0}\n";

	// частное вещественного и комплексного
	d = 4.0;
	x = Complex{ 2.0, -1.0 };
	std::cout << d << " / " << x << " == " << d / x << " Expected: {1.6, 0.8}\n";

	// частное комплексного и вещественного
	x = Complex{ -4.0, 5.5 };
	d = 2.5;
	std::cout << x << " / " << d << " == " << x / d << " Expected: {-1.6, 2.2}\n";

	// присваивание комплексному вещественного, а потом комплексному
	d = 43.23;
	x = Complex{ 1, 1 };
	y = Complex{ 12, 33 };
	x = d;
	std::cout << x << " Expected: {43.23,0}\n";
	x = y;
	std::cout << x << " Expected: {12, 33}\n";

	// деление с присваиванием для двух комплексных
	x = Complex{ 11.1, 9.8 };
	y = Complex{ 7, -9 };
	x /= y;
	std::cout << x << " Expected: {-0.0807,1.2961}\n";

	// деление с присваиванием комплексного и вещественного
	x = Complex{ 100, 90 };
	d = 10.0;
	x /= d;
	std::cout << x << " Expected: {10,9}\n";

	// сумма с присваиванием двух комплексных
	x = Complex{ 1.12, 2.49 };
	y = Complex{ 1.88, 2.51 };
	x += y;
	std::cout << x << " Expected: {3,5}\n";

	// разность с присваиванием двух комплексных
	x -= y;
	std::cout << x << " Expected: {1.12,2.49}\n";

	// произведение с присваиванием двух комплексных
	x *= y;
	std::cout << x << " Expected: {-4.1443,7.4924}\n";

	// сумма с присваиванием для комплексного и вещественного
	x = Complex{ 1,1 };
	d = 2.0;
	x += d;
	std::cout << x << " Expected: {3, 1}\n";

	// разность с присваиванием для комплексного и вещественного
	x -= d;
	std::cout << x << " Expected: {1,1}\n";

	// деление с присваиванием для комплексного и вещественного
	x /= d;
	std::cout << x << " Expected: {0.5,0.5}\n";

	// проверка равенства для вещественного и комплексного
	d = 12.5;
	x = Complex{ 12.5, 12.5 };
	std::cout << (d == x) << " Expected: 0\n";
	std::cout << (x == d) << " Expected: 0\n";
	std::cout << (d != x) << " Expected: 1\n";
	std::cout << (x != d) << " Expected: 1\n";

	// проверка равенства для двух комплексных
	y = Complex{ 12.5, 12.5 };
	x = Complex{ 12.5, 12.5 };
	std::cout << (y == x) << " Expected: 1\n";
	std::cout << (x == y) << " Expected: 1\n";
	std::cout << (y != x) << " Expected: 0\n";
	std::cout << (x != y) << " Expected: 0\n";

	// проверка равенства для двух комплексных
	y = Complex{ 1,1 };
	std::cout << (y == x) << " Expected: 0\n";
	std::cout << (x == y) << " Expected: 0\n";
	std::cout << (y != x) << " Expected: 1\n";
	std::cout << (x != y) << " Expected: 1\n";

	// проверка деления комплексных на ноль
	x = Complex{ 2, 1.1 };
	y = Complex{ 0, 0 };
	d = 0;
	try {
		std::cout << x / y;
	}
	catch (const std::invalid_argument& e) {
		std::cout << e.what();
	}

	return 0;
}
*/
Complex::Complex(const double real)
	: Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
	: re(real)
	, im(imaginary)
{
}

Complex& Complex::operator=(const Complex& rhs)
{
	re = rhs.re;
	im = rhs.im;
	return *this;
}

Complex& Complex::operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex& Complex::operator*=(const Complex& rhs)
{
	double k, e;
	k = re;
	e = im;
	re *= rhs.re;
	im *= rhs.im;
	re -= im;
	im = k * rhs.im + e * rhs.re;
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs)
{
	double k;
	k = re;
	if ((rhs.im * rhs.im + rhs.re * rhs.re) == 0) {
		throw std::invalid_argument("Division by zero");
	}
	re = (re * rhs.re + im * rhs.im) / (rhs.im * rhs.im + rhs.re * rhs.re);
	im = (im * rhs.re - k * rhs.im) / (rhs.im * rhs.im + rhs.re * rhs.re);
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex operator+(const Complex& lhs, const double& rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex operator+(const double& lhs, const Complex& rhs)
{
	Complex sum(rhs);
	sum += lhs;
	return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex minus(lhs);
	minus -= rhs;
	return minus;
}

Complex operator-(const Complex& lhs, const double& rhs)
{
	Complex minus(lhs);
	minus -= rhs;
	return minus;
}

Complex operator-(const double& lhs, const Complex& rhs)
{
	Complex minus(rhs);
	minus -= lhs;
	minus *= -1;
	return minus;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex umn(lhs);
	umn *= rhs;
	return umn;
}

Complex operator*(const Complex& lhs, const double& rhs)
{
	Complex umn(lhs);
	umn *= rhs;
	return umn;
}

Complex operator*(const double& lhs, const Complex& rhs)
{
	Complex umn(rhs);
	umn *= lhs;
	return umn;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
	Complex raz(lhs);
	raz /= rhs;
	return raz;
}

Complex operator/(const Complex& lhs, const double& rhs)
{
	Complex raz(lhs);
	raz /= rhs;
	return raz;
}

Complex operator/(const double& lhs, const Complex& rhs)
{
	Complex raz(lhs);
	raz /= rhs;
	return raz;
}

bool operator==(const Complex& lhs, const double& rhs) 
{
	return false;
}

bool operator==(const double& lhs, const Complex& rhs)
{
	return false;
}
std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaganary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaganary;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}

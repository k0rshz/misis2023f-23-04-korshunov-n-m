#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "rational/rational.hpp"
#include "doctest.h" 

TEST_CASE("rational ctor") {
	Rational r_def;
	CHECK(0 == r_def.num());
	CHECK(1 == r_def.den());

	Rational r_int(3);
	CHECK(3 == r_int.num());
	CHECK(1 == r_int.den());

	CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("+") {
	CHECK(Rational(41, 21) == Rational(2, 7) + Rational(5, 3));
	CHECK(Rational(22, 1) == Rational(11, 2) + Rational(33, 2));
	CHECK(Rational(10, 3) == (Rational(4, 3) += Rational(2, 1)));

}

/*
int main() {
	Rational x, y;
	int64_t a;

	// сложениe для двух рациональных
	x = Rational(2, 7);
	y = Rational(5, 3);
	std::cout << x + y << std::endl;

	// сложениe двух рациональных чисел с одинаковыми знаменателями
	x = Rational(11, 2);
	y = Rational(33, 2);
	std::cout << x + y << std::endl;

	// сложениe с присваиванием для двух рациональных
	x = Rational(4, 3);
	y = Rational(2, 1);
	x += y;
	std::cout << x << std::endl;

	// сложениe с присваиванием для рационального и целого
	x = Rational(2, 3);
	a = 3;
	x += a;
	std::cout << x << std::endl;

	// сложениe рационального и целого
	x = Rational(9, 6);
	a = 2;
	std::cout << x + a << " " << a + x << std::endl;

	// разность с присваиванием для двух рациональных c одинаковыми знаменателями
	x = Rational(3, 2);
	y = Rational(1, 2);
	x -= y;
	std::cout << x << std::endl;

	// разность с присваиванием для двух рациональных
	x = Rational(8, 3);
	y = Rational(5, 4);
	x -= y;
	std::cout << x << std::endl;

	// разность двух рациональных
	x = Rational(4, 5);
	y = Rational(5, 4);
	std::cout << x - y << std::endl;

	// разность рационального и целого
	x = Rational(8, 9);
	a = 1;
	std::cout << x - a << " " << a - x << std::endl;

	// произведение с присваиванием для двух рациональных
	x = Rational(2, 5);
	y = Rational(11, 2);
	x *= y;
	std::cout << x << std::endl;

	// произведение двух рациональных
	x = Rational(13, 4);
	y = Rational(1, 3);
	std::cout << x * y << std::endl;

	// произведение для рационального и целого
	x = Rational(7, 21);
	a = 3;
	std::cout << x * a << " " << a * x << std::endl;

	// частное с присваиванием для двух рациональных
	x = Rational(2, 5);
	y = Rational(11, 2);
	x /= y;
	std::cout << x << std::endl;

	// частное двух рациональных
	x = Rational(5, 2);
	y = Rational(8, 5);
	std::cout << x / y << std::endl;

	// частное рационального и целого
	x = Rational(11, 2);
	a = 10;
	std::cout << x / a << " " << a / x << std::endl;

	// присваивание целой переменной к рациональной
	x = Rational(4, 3);
	a = 2;
	x = a;
	std::cout << x << std::endl;

	// попытка сделать рациональное число со знаменателем равным нулю
	try {
		Rational z(2, 0);
	}
	catch (const std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}

	// сначало делаем только знаменатель отрицательным, а потом и знаменатель, и числитель
	Rational z(3, -1);
	std::cout << z << std::endl;
	Rational w(-3, -1);
	std::cout << w << std::endl;

	// сократимая дробь
	Rational r(-5, 100);
	std::cout << r << std::endl;
	r = Rational(64, 16);
	std::cout << r << std::endl;


	// инкремент и дикремент
	x = Rational(8, 5);
	std::cout << ++x << " " << --x << std::endl;;

	// получение числителя и знаменателя
	x = Rational(4, 3);
	std::cout << x.get_Num() << " " << x.get_Den() << std::endl;

	// сравнение двух рациональных на равенство
	x = Rational(12, 13);
	y = Rational(24, 26);
	std::cout << std::boolalpha << std::endl;
	std::cout << (x == y) << std::endl;
	std::cout << (x != y) << std::endl;
	y = Rational(23, 26);
	std::cout << (x == y) << std::endl;
	std::cout << (x != y) << std::endl;

	// сравнение рационального и целого на равенство
	x = Rational(2, 1);
	a = 2;
	std::cout << (x == a) << " " << (a == x) << std::endl;
	std::cout << (x != a) << " " << (a != x) << std::endl;
	x = Rational(2, 3);
	std::cout << (x == a) << " " << (a == x) << std::endl;
	std::cout << (x != a) << " " << (a != x) << std::endl;

	// сравнение рациональных на > и <
	x = Rational(4, 5);
	y = Rational(7, 6);
	std::cout << (x > y) << " " << (x < y) << std::endl;

	// сравнение рациональных на >= и <=
	x = Rational(6, 3);
	y = Rational(2, 1);
	std::cout << (x >= y) << " " << (x <= y) << std::endl;

	// сравнение рационального и целого на > и <
	x = Rational(2, 3);
	a = 1;
	std::cout << (a > x) << " " << (a < x) << std::endl;

	// сравнение рационального и целого на > и <
	x = Rational(1000, 10);
	a = 100;
	std::cout << (a >= x) << " " << (x <= a) << std::endl;

	return 0;
}*/
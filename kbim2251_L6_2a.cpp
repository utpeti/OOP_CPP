#include <iostream>

using namespace std;

class Matr2
{
	double a11, a12, a21, a22;
public:
	Matr2();
	Matr2(double, double, double, double);
	~Matr2();
	Matr2 operator+(const Matr2& m);
	Matr2 operator*(const Matr2& m);
	Matr2 operator+=(const Matr2& m);
	Matr2 operator*=(const Matr2& m);
	double operator~();
	void kiir();
};

Matr2::Matr2()
{

}

Matr2::Matr2(double in11, double in12, double in21, double in22)
{
	a11 = in11;
	a12 = in12;
	a21 = in21;
	a22 = in22;
}

Matr2::~Matr2()
{

}

Matr2 Matr2::operator+(const Matr2& m)
{
	Matr2 ujmatrix(a11 + m.a11, a12 + m.a12, a21 + m.a21, a22 + m.a22);
	return ujmatrix;
}

Matr2 Matr2::operator+=(const Matr2& m)
{
	a11 += m.a11;
	a12 += m.a12;
	a21 += m.a21;
	a22 += m.a22;

	return *this;
}

Matr2 Matr2::operator*(const Matr2& m)
{
	Matr2 ujmatrix;
	ujmatrix.a11 = a11 * m.a11 + a12 * m.a21;
	ujmatrix.a12 = a11 * m.a12 + a12 * m.a22;
	ujmatrix.a21 = a21 * m.a11 + a22 * m.a21;
	ujmatrix.a22 = a21 * m.a12 + a22 * m.a22;

	return ujmatrix;
}

Matr2 Matr2::operator*=(const Matr2& m)
{
	Matr2 ujmatrix;
	ujmatrix.a11 = a11 * m.a11 + a12 * m.a21;
	ujmatrix.a12 = a11 * m.a12 + a12 * m.a22;
	ujmatrix.a21 = a21 * m.a11 + a22 * m.a21;
	ujmatrix.a22 = a21 * m.a12 + a22 * m.a22;

	a11 = ujmatrix.a11;
	a12 = ujmatrix.a12;
	a21 = ujmatrix.a21;
	a22 = ujmatrix.a22;

	return *this;
}

double Matr2::operator~()
{
	return (a11 * a22 - a12 * a21);
}

void Matr2::kiir()
{
	cout << a11 << " " << a12 << endl << a21 << " " << a22 << endl;
}

int main()
{
	Matr2 m1(1, 0, 0, 1);
	Matr2 m2(2, 2, 2, 3);
	
	m1.kiir();
	cout << ~m1 << endl << ~m2 << endl;
	m2.kiir();
	m1 += m2;
	m1.kiir();
	m1 *= m2;
	m1.kiir();

	return 0;
}

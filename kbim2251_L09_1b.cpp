//Korpos Botond
//512/2

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

using namespace std;

class Alakzat
{


public:
	Alakzat() {}
	~Alakzat() {}
	virtual double terulet() = 0;
	virtual double kerulet() = 0;
	virtual void nagyit(double s) = 0;

};

class Haromszog : public Alakzat
{
protected:
	double oldal1, oldal2, oldal3;

public:
	Haromszog() : Alakzat() { oldal1 = oldal2 = oldal3 = 0; }
	~Haromszog() {}
	double terulet()
	{
		double s = kerulet() / 2;
		return sqrt(s * (s - oldal1) * (s - oldal2) * (s - oldal3));
	}
	double kerulet()
	{
		return oldal1 + oldal2 + oldal3;
	}
	void nagyit(double s)
	{
		oldal1 *= s;
		oldal2 *= s;
		oldal3 *= s;
	}

};

class Kor :  public Alakzat
{
	double sugar;

public:
	Kor() : Alakzat() { sugar = 0; }
	Kor(double r) : Alakzat() { sugar = r; }
	~Kor() {}
	double terulet()
	{
		return M_PI * M_PI * sugar;
	}
	double kerulet()
	{
		return 2 * M_PI * sugar;
	}
	void nagyit(double s)
	{
		sugar *= s;
	}

};

class DerekszoguHaromszog : public Haromszog
{

public:
	DerekszoguHaromszog() : Haromszog() { oldal1 = oldal2 = oldal3 = 0; }
	DerekszoguHaromszog(double a, double b, double c) : Haromszog()
	{
		oldal1 = a, oldal2 = b, oldal3 = c;
		try
		{
			if (a > c)
			{
				swap(a, c);
			}
			if (a > b)
			{
				swap(a, b);
			}
			if (b > c)
			{
				swap(b, c);
			}

			if (a * a + b * b != c * c)
			{
				throw("Nem derekszogu haromszog");
			}
		}
		catch (const char* e)
		{
			cerr << e;
		}
	}
	~DerekszoguHaromszog() {}
	double terulet()
	{
		if (oldal1 > oldal3)
		{
			swap(oldal1, oldal3);
		}
		if (oldal1 > oldal2)
		{
			swap(oldal1, oldal2);
		}
		if (oldal2 > oldal3)
		{
			swap(oldal2, oldal3);
		}
		
		return 0.5 * oldal1 * oldal2;
	}
	double kerulet()
	{
		return oldal1 + oldal2 + oldal3;
	}
	void nagyit(double s)
	{
		oldal1 *= s;
		oldal2 *= s;
		oldal3 *= s;
	}

};

int main()
{

	Alakzat* a[] = { new Kor(3), new Haromszog, new DerekszoguHaromszog(2,4,5) };

	cout << a[0]->kerulet() << ", " << a[0]->terulet() << endl;

	cout << a[1]->kerulet() << ", " << a[1]->terulet() << endl;

	cout << a[2]->kerulet() << ", " << a[2]->terulet() << endl;

	return 0;
}
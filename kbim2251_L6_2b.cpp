//Korpos Botond
//512/2

#include <iostream>

using namespace std;

class Intervallum
{
	double kezp, vegp;
public:
	Intervallum();
	Intervallum(int inkezp, int invegp);
	~Intervallum();
	void kiir();
	Intervallum operator--(int);
	Intervallum& operator--();
};

Intervallum::Intervallum()
{

}

Intervallum::Intervallum(int inkezp, int invegp)
{
	if (inkezp > invegp)
	{
		throw ("Invalid parameterek - nem lehet felepiteni az intervallumot");
	}
	kezp = inkezp;
	vegp = invegp;
}

Intervallum::~Intervallum()
{

}

void Intervallum::kiir()
{
	cout << "(" << kezp << ", " << vegp << ")" << endl;
}

Intervallum Intervallum::operator--(int)
{
	Intervallum akt(kezp, vegp);
	--vegp;
	++kezp;
	return akt;
}

Intervallum& Intervallum::operator--()
{
	--vegp;
	++kezp;
	return *this;
}

int main()
{
	try
	{
		Intervallum ainterv(-3, 6);
		ainterv--.kiir();
		(--ainterv).kiir();
	}
	catch (const char* invalidinterv)
	{
		cout << invalidinterv;
	}

	return 0;
}

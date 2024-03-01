#include <iostream>

using namespace std;

class rac
{
public:
	int szamlalo;
	int nevezo;
	rac(int, int);
	void kiir();
	rac operator/(rac);
	rac& operator/=(rac);

	~rac();

};

class rackiir : public rac
{
public:
	using rac::rac;
	rac operator/(rac);
	rac& operator/=(rac);
	~rackiir();

};

rac rackiir::operator/(rac inrac)
{
	rac temp(1, 0);
	temp.szamlalo = szamlalo * inrac.nevezo;
	temp.nevezo = nevezo * inrac.szamlalo;
	cout << "(" << szamlalo << " / " << nevezo << ") / (" << inrac.szamlalo << " / " << inrac.nevezo << ") = " << temp.szamlalo << " / " << temp.nevezo << endl;

	return temp;
}

rac& rackiir::operator/=(rac inrac)
{
	rac::operator/=(inrac);
	cout << "(" << szamlalo << " / " << nevezo << ") / (" << inrac.szamlalo << " / " << inrac.nevezo << ") = " << szamlalo << " / " << nevezo << endl;

	return *this;
}

rackiir::~rackiir()
{

}

rac::rac(int a = 0, int b = 1)
{
	szamlalo = a;
	nevezo = b;
}

rac rac::operator/(rac inrac)
{
	rac temp(1, 0);
	temp.szamlalo = szamlalo * inrac.nevezo;
	temp.nevezo = nevezo * inrac.szamlalo;

	return temp;
}

rac& rac::operator/=(rac inrac)
{
	szamlalo *= inrac.nevezo;
	nevezo *= inrac.szamlalo;

	return *this;
}

void rac::kiir()
{
	cout << szamlalo << "/" << nevezo << endl;
}

rac::~rac()
{

}

int main()
{
	rac p(3, 4), q(5, 2), r;

	r = p /= q;

	p.kiir();

	r.kiir();

	rackiir p1(3, 4), q1(5, 2);

	rac r1, r2;

	r1 = p1 / q1;

	r2 = p1 /= q1;

	p1.kiir();

	r1.kiir();

	r2.kiir();
}

#include <iostream>

using namespace std;

class Lista
{
	int* l;
	int max_meret;
	int aktualis_meret;

public:
	Lista(int m);
	void push(int e);
	int pop();
	~Lista();
	void kiir();
	class Ures {};
	class Betelt {};
};

Lista::Lista(int m)
{
	aktualis_meret = 0;
	max_meret = m;
	l = new int[m];
}

Lista::~Lista()
{

}

void Lista::push(int e)
{
	if (aktualis_meret < max_meret)
	{
		l[aktualis_meret] = e;
		++aktualis_meret;
	}
	else
	{
		throw Betelt();
	}
}

int Lista::pop()
{
	int fo = l[0];
	for (int i = 1; i < aktualis_meret; ++i)
	{
		l[i - 1] = l[i];
	}
	--aktualis_meret;

	return fo;
}

void Lista::kiir()
{
	for (int i = 0; i < aktualis_meret; ++i)
	{
		cout << l[i] << " ";
	}
}

int main()
{
	Lista list(10);
	
	try
	{
		list.push(1);
		list.push(3);
		list.push(5);
		list.push(8);
		list.push(1);
		list.push(3);
		list.push(5);
		list.push(8);
		list.push(1);
		list.push(3);
		list.push(3);
		list.kiir();
		cout << endl;
		list.pop();
		list.pop();
		list.push(20);
		list.push(12);
		list.kiir();
		cout << endl;
		list.pop();
		list.pop();
		list.pop();
		list.pop();
		list.pop();
		list.pop();
		list.pop();
		list.pop();
		list.pop();
		list.pop();
		list.kiir();
	}
	catch (Lista::Betelt)
	{
		cout << "BETELT A LISTA!";
	}
}

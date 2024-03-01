//Korpos Botond
//512/2

#include <iostream>

using namespace std;

template<class T, int N>
class FelsoHMatr
{
	T* hm;
public:
	FelsoHMatr(); //done
	FelsoHMatr(T[N]); //done
	FelsoHMatr(const FelsoHMatr&); //done
	~FelsoHMatr(); //done
	FelsoHMatr szoroz(T skalar); //done
	bool operator == (const FelsoHMatr&); //done
	void kiir(); //done
};

template<class T, int N>
FelsoHMatr<T, N>::FelsoHMatr()
{
	hm = new T[N * (N + 1) / 2];
	int ujN = N + 1, sz = 0;
	for (int i = 0; i < (N * (N + 1) / 2); ++i)
	{
		if (!i || sz == ujN)
		{
			hm[i] = 1;
			--ujN;
			sz = 0;
		}
		else
		{
			hm[i] = 0;
		}
		++sz;
	}
}

template<class T, int N>
FelsoHMatr<T, N>::~FelsoHMatr()
{

}

template<class T, int N>
FelsoHMatr<T, N>::FelsoHMatr(const FelsoHMatr& MFelsoH)
{
	hm = new T[N * (N + 1) / 2];
	for (int i = 0; i < (N * (N + 1) / 2); ++i)
	{
		hm[i] = MFelsoH.hm[i];
	}
}

template<class T, int N>
FelsoHMatr<T, N>::FelsoHMatr(T a[N])
{
	hm = new T[N * (N + 1) / 2];
	for (int i = 0; i < (N * (N + 1) / 2); ++i)
	{
		hm[i] = a[i];
	}

}

template<class T, int N>
FelsoHMatr<T, N> FelsoHMatr<T, N>::szoroz(T skalar)
{
	for (int i = 0; i < (N * (N + 1) / 2); ++i)
	{
		hm[i] *= skalar;
	}
	return hm;
}

template<class T, int N>
void FelsoHMatr<T, N>::kiir()
{
	int hatar = N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < hatar; ++j)
		{
			cout << hm[j] << " ";
		}
		--hatar;
		cout << endl;
	}
}

template<class T, int N>
bool FelsoHMatr<T, N>:: operator == (const FelsoHMatr& m)
{
	for (int i = 0; i < (N * (N + 1) / 2); ++i)
	{
		if (hm[i] != m.hm[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	FelsoHMatr<int, 3> fm1;
	fm1.szoroz(10);
	fm1.kiir();

	FelsoHMatr<int, 3> fm2;
	if (fm1 == fm2)
	{
		cout << "Egyenloek" << endl;
	}
	else
	{
		cout << "Nem egyenloek" << endl;
	}

	fm2.szoroz(10);
	if (fm1 == fm2)
	{
		cout << "Egyenloek" << endl;
	}
	else
	{
		cout << "Nem egyenloek" << endl;
	}

	fm1.~FelsoHMatr();

	return 0;
}

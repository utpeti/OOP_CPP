#include <iostream>

using namespace std;

class E
{
protected:
    int e;
public:
    E() : e(0) {}
    E(string& s)
    {
        e = 0;
        s.append("E");
    }
};

class F
{
protected:
    int f;
public:
    F() : f(0) {}
    F(string& s)
    {
        f = 0;
        s.append("F");
    }
};

class A : virtual public E, virtual public F
{
protected:
    int a;
public:
    A(string& s) : E(s), F(s)
    {
        a = 0;
        s.append("A");
    }
};

class B : virtual public E, virtual public F
{
protected:
    int b;
public:
    B(string& s) : E(s), F(s)
    {
        b = 0;
        s.append("B");
    }
};

class C : virtual public E, virtual public F
{
protected:
    int c;
public:
    C(string& s) : E(s), F(s)
    {
        c = 0;
        s.append("C");
    }
};

class D : virtual public E, virtual public F
{
protected:
    int d;
public:
    D(string& s) : E(s), F(s)
    {
        d = 0;
        s.append("D");
    }
};

class G : public E, public F
{
protected:
    int g;
public:
    G(string& s) : E(s), F(s)
    {
        g = 0;
        s.append("G");
    }
};

class H : public E, public F
{
protected:
    int h;
public:
    H(string& s) : E(s), F(s)
    {
        h = 0;
        s.append("H");
    }
};

class I
{
protected:
    int i;
public:
    I(string& s)
    {
        i = 0;
        s.append("I");
    }
};

class J : public A, public B, public C, public D, public G, public H, virtual public I
{
protected:
    int j;
public:
    J(string& s) : A(s), B(s), C(s), D(s), G(s), H(s), I(s)
    {
        j = 0;
        s.append("J");
    }
    void kiir()
    {
        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
        cout << d << endl;
        cout << "G: " << G::e << " H: " << H::e << endl;
        cout << "G: " << G::f << " H: " << H::f << endl;
        cout << g << endl;
        cout << h << endl;
        cout << i << endl;
        cout << j << endl;
    }
};

int main()
{
    string sorrend = "";
    J viccesoroklodes(sorrend);

    cout << sorrend << endl;
    viccesoroklodes.kiir();

    return 0;
}

#define _USE_MATH_DEFINES
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

class Pont
{
    double x, y;
public:
    Pont();
    Pont(double a, double b)
    {
        x = a;
        y = b;
    }
    void kiir();
    double get_x() const
    {
        return x;
    }
    double get_y() const
    {
        return y;
    }
};

class Kor
{
    Pont kozeppont;
    double sugar;
public:
    Kor() :kozeppont()
    {
        sugar = 1;
    }
    Kor(double x, double y, double r) :kozeppont(x, y), sugar(r) {};
    double kerulet();
    double terulet();
    Pont veletlenpont();
};

void Pont::kiir()
{
    cout << x << ", " << y;
}

double Kor::kerulet()
{
    return 2 * M_PI * sugar;
}

double Kor::terulet()
{
    return M_PI * sugar * sugar;
}

Pont Kor::veletlenpont()
{
    double p = rand() % 361;
    p *= M_PI / 180;

    double korx = cos(p) * sugar + kozeppont.get_x();
    double kory = sin(p) * sugar + kozeppont.get_y();

    Pont randpont(korx, kory);
    return randpont;
}

void init()
{
    srand(time(NULL));
}

int main()
{
    init();
    
    double a, b, r;
    cin >> a >> b >> r;

    Kor kor(a, b, r);

    kor.veletlenpont().kiir();

    cout << endl << kor.kerulet() << endl << kor.terulet();

    return 0;
}

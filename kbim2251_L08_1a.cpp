// Korpos Botond
// 512/2

#include <iostream>

using namespace std;

class Hossz_f;

class Hossz_m
{
    int m, dam, hm, km;
    double maradek;
    
public:
    Hossz_m(int, int, int, int, double d = 0);
    Hossz_m(const Hossz_f& f);
    void kiir();
};

class Hossz_f
{
    int fathom, pole, furlong, statute_mile;

public:
    Hossz_f(int, int, int, int);
    double get_meter() const;
    operator Hossz_m()
    {
        double meter = get_meter();
        int kmeter = meter / 1000;
        meter -= kmeter * 1000;
        int hmeter = meter / 100;
        meter -= hmeter * 100;
        int dmeter = meter / 10;
        meter -= dmeter * 10;
        double maradek = meter;
        return Hossz_m(meter, dmeter, hmeter, kmeter, maradek);
    }
};

double Hossz_f::get_meter() const {
    double meter = 0;
    meter += statute_mile * 1609.344;
    meter += furlong * 201.168;
    meter += pole * 5.03;
    meter += fathom * 1.83;
    return meter;
}

void Hossz_m::kiir()
{
    if (km) cout << km << " km, " << endl;
    if (hm) cout << hm << " hm, " << endl;
    if (dam) cout << dam << " dam," << endl;
    if (maradek) cout << "maradek: " << maradek << endl;
}

Hossz_f::Hossz_f(int a, int b, int c, int d)
{
    fathom = a;
    pole = b;
    furlong = c;
    statute_mile = d;
}

Hossz_m::Hossz_m(int a, int b, int e, int f, double d)
{
    m = a;
    dam = b;
    hm = e;
    km = f;
    maradek = d;
}

Hossz_m::Hossz_m(const Hossz_f& f)
{
    double meter = f.get_meter();
    int kmeter = meter / 1000;
    meter -= kmeter * 1000;
    int hmeter = meter / 100;
    meter -= hmeter * 100;
    int dmeter = meter / 10;
    meter -= dmeter * 10;
    double mmaradek = meter;
    m = meter;
    dam = dmeter;
    hm = hmeter;
    km = kmeter;
    maradek = mmaradek;
}

int main()
{
    Hossz_f tavolsag1(3, 4, 1, 9);
    Hossz_m tav1 = (Hossz_m)tavolsag1;
    tav1.kiir();

    Hossz_f tavolsag2(4, 3, 5, 3);
    Hossz_m tav2(1, 2, 3, 4);

    tav2 = tavolsag2;
    tav2.kiir();
}
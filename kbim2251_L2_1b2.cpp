//Korpos Botond
//512

#include "intervallumheader.h"

using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;

    intervallum_cls intervallum;

    intervallum.init(a, b);

    intervallum.kiir();
    
    intervallum.duplaz();

    intervallum.kiir();

    intervallum.felsz();
}

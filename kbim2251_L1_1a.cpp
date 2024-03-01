//Korpos Botond
//512

#include <iostream>

using namespace std;

int veletlenSzam(int a, int b)
{
    srand(time(NULL));
    int randomszam = a + (rand() % (b - a + 1));
    return randomszam;
}

void jatek(int generaltSzam)
{
    bool talalt = false;
    int kozep, inputSzam;
    while (!talalt)
    {
        cin >> inputSzam;
        if (inputSzam < generaltSzam)
        {
            cout << "nagyobb\n";
        }
        else if (inputSzam > generaltSzam)
        {
            cout << "kisebb\n";
        }
        else
        {
            cout << "gratulalok\n";
            talalt = true;
        }
    }
}

int main()
{
    int a = 1, b = 100;
    
    jatek(veletlenSzam(a, b));

    return 0;
}

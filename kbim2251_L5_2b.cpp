//Korpos Botond
//512/2

#include <iostream>

using namespace std;

template<class T>
T fibonacciElem(T kezdo1, T kezdo2, unsigned int index)
{
    T a = kezdo1, b = kezdo2, c = a + b;
    
    unsigned int aktindex = 0;
    while (aktindex < index)
    {
        c = a + b;
        a = b;
        b = c;
        ++aktindex;
    }
    return c;
}

int main()
{
    cout << fibonacciElem(1.1, 1.3, 4);
}

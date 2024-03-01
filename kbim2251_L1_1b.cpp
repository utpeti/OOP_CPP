//Korpos Botond
//512

#include <iostream>
#include <cmath>

using namespace std;

struct hatar
{
    int felso, also, bal, jobb;
};

void beOlvas(int& n, int matrix[])
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> matrix[i];
    }
}

void kiIr(int n, const int* spiral)
{
    for (int i = 1; i <= n; ++i)
    {
        cout << spiral[i] << " ";
    }
}

void spiralSorrend(const int* matrix, int n, int* spiral)
{
    hatar hatar;
    int gyokn = sqrt(n);
    hatar.felso = gyokn + 1;
    hatar.bal = n - gyokn + 1;
    hatar.also = n;
    hatar.jobb = gyokn;
    int dbfeldolgozva = 0, index = 0, indexsp = 1;

    while (dbfeldolgozva < n)
    {
        while (index < hatar.jobb)
        {
            ++index;
            spiral[indexsp] = matrix[index];
            ++indexsp;
            ++dbfeldolgozva;
        }
        hatar.jobb += gyokn;
        --hatar.jobb;
        while (index < hatar.also)
        {
            index += gyokn;
            spiral[indexsp] = matrix[index];
            ++indexsp;
            ++dbfeldolgozva;
        }
        hatar.also -= gyokn;
        --hatar.also;
        while (index > hatar.bal)
        {
            --index;
            spiral[indexsp] = matrix[index];
            ++indexsp;
            ++dbfeldolgozva;
        }
        hatar.bal -= gyokn;
        ++hatar.bal;
        while (index > hatar.felso)
        {
            index -= gyokn;
            spiral[indexsp] = matrix[index];
            ++indexsp;
            ++dbfeldolgozva;
        }
        hatar.felso += gyokn;
        ++hatar.felso;
    }
}

int main()
{
    int matrix[1000];
    int n;
    beOlvas(n, matrix);

    int spiral[1000];
    spiralSorrend(matrix, n, spiral);

    kiIr(n, spiral);

    return 0;
}

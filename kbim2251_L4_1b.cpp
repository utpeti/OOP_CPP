#include <iostream>

using namespace std;

char* keresCharban(char* a, char* b)
{
    if (strstr(a, b) != NULL)
    {
        return strstr(a, b);
    }
    throw "Nem talalta meg a b-t az a-ban";
}

int main()
{
    char a[100], b[100];
    cin >> a >> b;

    try
    {
        cout << keresCharban(a, b);
    }
    catch (const char* hiba)
    {
        cout << hiba;
    }
}

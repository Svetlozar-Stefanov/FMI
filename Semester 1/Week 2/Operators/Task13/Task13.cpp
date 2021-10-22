#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;
    int x;

    cin >> a;
    cin >> b;
    cin >> x;

    if (x < a)
    {
        cout << 1;

    }
    if (x == a)
    {
        cout << 2;
    }
    if (x > a && x < b)
    {
        cout << 3;
    }
    if (x == b)
    {
        cout << 4;
    }
    if (x > b)
    {
        cout << 5;
    }
}

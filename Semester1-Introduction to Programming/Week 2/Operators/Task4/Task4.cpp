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

    if (a <= x && x <= b)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}

#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;
    int c;

    cin >> a;
    cin >> b;
    cin >> c;

    int D = b * b - 4 * a * c;

    if (D > 0)
    {
        cout << "true";
    }
}

#include <iostream>

using namespace std;

int abs(const int a)
{
    return a > 0 ? a : -a;
}

int main()
{
    cout << abs(-2);
}

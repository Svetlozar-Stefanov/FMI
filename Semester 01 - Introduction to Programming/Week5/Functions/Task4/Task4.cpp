#include <iostream>

using namespace std;

int absolute(const int a)
{
    return a > 0 ? a : -a;
}

int main()
{
    cout << absolute(-2);
}

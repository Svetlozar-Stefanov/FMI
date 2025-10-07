#include <iostream>

using namespace std;

int min(const int a, const int b)
{
    return a > b ? b : a;
}

int main()
{
    cout << min(2, 4);
}

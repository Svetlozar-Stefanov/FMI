#include <iostream>

using namespace std;

bool hasRepeatingBits(const int n) 
{
    int temp = n << 1;

    int output = n & temp;
    
    return output != 0;
}

int main()
{
    int n;
    cin >> n;

    if (hasRepeatingBits(n))
    {
        cout << "false";
    }
    else
    {
        cout << "true";
    }
}

#include <iostream>

using namespace std;

int numberOfBitsInBinary(int num) 
{
    int count = 0;
    while (num != 0)
    {
        num /= 2;
        count++;
    }

    return count;
}

int main()
{
    int num;
    cin >> num;

    int bitCount = numberOfBitsInBinary(num);

    int* bits = new int[bitCount];
    for (int i = bitCount - 1; i >= 0; i--)
    {
        bits[i] = num % 2;
        num /= 2;
    }

    for (int i = 0; i < bitCount; i++)
    {
        cout << bits[i];
    }

    delete[] bits;
}
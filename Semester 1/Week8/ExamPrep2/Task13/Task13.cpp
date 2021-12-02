#include <iostream>

using namespace std;

int main()
{
    int seconds;
    cin >> seconds;

    int minutes = seconds / 60 % 60;
    int hours = seconds / 3600;

    if (hours < 10)
    {
        cout << '0';
    }
    cout << hours << ':';
    if (minutes < 10)
    {
        cout << '0';
    }
    cout << minutes;
}
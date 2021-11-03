#include <iostream>

using namespace std;

void askUser(const int from, const int to)
{
    int input;

    cin >> input;
    while (from > input || input > to)
    {
        cin >> input;
    }
    cout << input;
}

int main()
{
    askUser(4, 9);
}

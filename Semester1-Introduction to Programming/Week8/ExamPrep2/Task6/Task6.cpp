#include <iostream>

using namespace std;

int main()
{
    int x1;
    int y1;

    int x2;
    int y2;

    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;

    cout << sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));

   
}
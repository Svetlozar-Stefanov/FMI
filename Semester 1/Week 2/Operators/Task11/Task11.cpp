#include <iostream>
#include <cmath>

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

    double x1 = (-b + sqrt(D)) / 2 * a;
    double x2 = (-b - sqrt(D)) / 2 * a;

    cout << "x1= " << x1 << endl;
    cout << "x2= " << x2 << endl;

}

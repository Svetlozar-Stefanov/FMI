#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int input;

    cin >> input;

    cout << "square: p=" << 4 * input << " s=" << input * input << endl;
    cout << "circle: p=" << 2 * 3.14 * input << endl;
    cout << "triangle: p=" << 3 * input << " s=" << (input * input * (1.73 / 2)) / 2 << endl;


}

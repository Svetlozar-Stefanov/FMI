#include <iostream>

using namespace std;

int main()
{
    int amount[3];
    double prices[3];

    cout << "Apples: ";
    cin >> amount[0] >> prices[0];

    double price1 = amount[0] * prices[0];

    cout << "Krushi: ";
    cin >> amount[1] >> prices[1];

    double price2 = amount[1] * prices[1];

    cout << "Sushi: ";
    cin >> amount[2] >> prices[2];

    double price3 = amount[2] * prices[2];

    cout<<"Your order is: apples for " << price1 <<", krushi for " << price2 <<" and sushi for " << price3 <<". Total: "<< price1 + price2 + price3;
}

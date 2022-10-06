#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    vector<double> num1;
    vector<double> num2;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        double temp = 0;
        cin >> temp;
        num1.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        double temp = 0;
        cin >> temp;
        num2.push_back(temp);
    }

    vector<double> output;
    for (int i = 0; i < n; i++)
    {
        double x = (-num2[i]) / num1[i];

        output.push_back(x);
    }

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
}
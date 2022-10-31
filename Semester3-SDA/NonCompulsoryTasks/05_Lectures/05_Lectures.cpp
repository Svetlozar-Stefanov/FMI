#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    cin >> input;

    int counter[256] = { 0 };
    for (int i = 0; i < input.size(); i++)
    {
        counter[input[i]]++;
    }

    for (int i = 0; i < input.size(); i++)
    {
        if (counter[input[i]] == 1)
        {
            cout << i << " ";
        }
    }
}

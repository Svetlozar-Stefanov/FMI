#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    vector<int> input;
    vector<int> randNum;
    srand((unsigned)time(NULL));

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        cin >> temp;
        input.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        int temp = rand();
        randNum.push_back(temp);
    }

    vector<int> output;
    for (int i = 0; i < n; i++)
    {
        if (input[i] > randNum[i])
        {
            output.push_back(i);
        }
    }

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
}
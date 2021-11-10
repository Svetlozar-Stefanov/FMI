#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

bool contains(vector<unsigned> vec, int num) {
    bool contains = false;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == num)
        {
            contains = true;
            break;
        }
    }
    return contains;
}

int main()
{
    int n;
    vector<unsigned> randNum;
    srand((unsigned)time(NULL));

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        unsigned temp = rand() % 20;
        randNum.push_back(temp);
    }

    vector<unsigned> output;

    for (int i = 0; i < randNum.size(); i++)
    {
        for (int j = 0; j < randNum.size(); j++)
        {
            if (randNum[i] == randNum[j] && !contains(output, randNum[i]))
            {
                output.push_back(randNum[i]);
                break;
            }
        }
    }

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
}
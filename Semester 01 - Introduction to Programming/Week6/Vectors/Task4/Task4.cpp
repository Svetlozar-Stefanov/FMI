#include <iostream>
#include <vector>

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

    cin >> n;

    vector<unsigned> numbers;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    vector<unsigned> repNum;

    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = 0; j < numbers.size(); j++)
        {
            if (numbers[i] == numbers[j] && !contains(repNum, numbers[i]))
            {
                repNum.push_back(numbers[i]);
                break;
            }
        }
    }

    for (int i = 0; i < repNum.size(); i++)
    {
        cout << repNum[i] << " ";
    }
}
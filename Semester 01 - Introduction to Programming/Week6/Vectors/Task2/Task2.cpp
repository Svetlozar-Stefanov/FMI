#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

double getAvg(vector<int> vec) 
{
    double sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
    }

    return vec.size() > 0 ? sum / vec.size() : 0;
}

int main()
{
    int n;
    vector<int> numbers;
    srand((unsigned)time(NULL));

    cin >> n;


    for (int i = 0; i < n; i++)
    {
        int temp = rand();
        numbers.push_back(temp);
    }

    int avg = getAvg(numbers);
    vector<int> output;

    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] > avg)
        {
            output.push_back(i);
        }
    }

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
}
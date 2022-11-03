#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Num
{
    int n;
    int idx;
};

bool operator<(Num& n1, Num& n2)
{
    return n1.n < n2.n;
}

vector<int> twoSum(vector<int>& nums, int target) 
{
    vector<Num> numbers(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        numbers[i].n = nums[i];
        numbers[i].idx = i;
    }

    sort(numbers.begin(), numbers.end());

    int i = 0;
    int j = numbers.size() - 1;

    int sum = 0;
    while (sum != target)
    {
        sum = numbers[i].n + numbers[j].n;
        if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return { numbers[i].idx, numbers[j].idx };
}

int main()
{
    
}

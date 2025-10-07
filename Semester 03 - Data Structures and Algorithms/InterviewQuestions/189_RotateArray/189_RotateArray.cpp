#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void rotate(vector<int>& nums, int k) {
    queue<int> temp;
    for (int i = nums.size()-1; i >= 0; i--)
    {
        temp.push(nums[i]);
    }

    for (int i = 0; i < k; i++)
    {
        int n = temp.front();
        temp.pop();
        temp.push(n);
    }

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        nums[i] = temp.front();
        temp.pop();
    }
}

int main()
{
    vector<int> arr = { 1,2,3,4,5,6,7 };
    rotate(arr, 3);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

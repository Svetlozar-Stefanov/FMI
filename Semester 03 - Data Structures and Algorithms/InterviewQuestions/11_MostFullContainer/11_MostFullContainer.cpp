#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
	int max = INT_MIN;
	int size = height.size() - 1;
	int i = 0;
	int j = height.size() - 1;
	while (i != j)
	{
		int sum = size * min(height[i], height[j]);
		if (max < sum)
		{
			max = sum;
		}

		if (height[i] <= height[j])
		{
			i++;
		}
		else
		{
			j--;
		}
		size--;
	}

	return max;
}

int main()
{

}

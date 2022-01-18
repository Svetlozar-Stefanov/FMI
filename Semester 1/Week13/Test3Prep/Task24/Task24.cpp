#include <iostream>

double skipThreeSum(const double* arr, const unsigned size) 
{
	if (arr == nullptr)
	{
		return -1;
	}

	double sum = 0;

	for (int i = 2; i < size; i+=3)
	{
		sum += arr[i];
	}

	return sum;
}

int main()
{
	double arr1[] = { 1,1,5,5,4,3,2,3,4,5,2 };
	double arr2[] = { 4,1,5,3,4,3,2,3,4,4,2 };

	std::cout << skipThreeSum(arr1, 11);
	std::cout << skipThreeSum(arr2, 11);
}
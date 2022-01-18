#include <iostream>

int main()
{
	int arr[4000];
	int input;
	int size = 0;

	std::cin >> input;

	while (input >= 0)
	{
		arr[size++] = input;
		std::cin >> input;
	}

	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	std::cout << sum / size;
}
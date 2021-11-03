#include <iostream>

using namespace std;

double average(const int N)
{
	int sum = 0;
	
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;

		sum += input;
	}

	return (double)sum / N;
}

int main()
{
	cout << average(5);
}

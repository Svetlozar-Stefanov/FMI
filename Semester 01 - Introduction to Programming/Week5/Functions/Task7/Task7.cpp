#include <iostream>

using namespace std;

int absolute(const int a)
{
	return a > 0 ? a : -a;
}

double power(const int num, const int N)
{

	double output = 1;

	for (int i = 0; i < absolute(N); i++)
	{
		output *= num;
	}

	return output;
	if (N >= 0)
	{
		return output;
	}
	else
	{
		return 1 / output;
	}

}

int main()
{
	cout << pow(4, 2);
}

#include <iostream>
#include <vector>

using namespace std;

bool hasAlteringBits(unsigned n) 
{
	vector<int> bits = {};

	while (n > 0)
	{
		bits.push_back(n % 2);

		n /= 2;
	}

	bool hasAlteringBits = true;

	int cap = bits.size() - 1;
	for (int i = 0; i < cap; i++)
	{
		if (bits[i] == bits[i + 1])
		{
			hasAlteringBits = false;
			break;
		}
	}

	return hasAlteringBits;
}

int main()
{
	unsigned temp;
	if (!(cin >> temp))
	{
		cout << "-1";
		return 1;
	}

	int n = temp;

	if (hasAlteringBits(n))
	{
		cout << "true";
	}
	else
	{
		cout<<"false";
	}
}

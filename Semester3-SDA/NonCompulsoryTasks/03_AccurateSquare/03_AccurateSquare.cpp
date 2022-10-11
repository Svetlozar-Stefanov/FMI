#include <iostream>
#include <vector>

using namespace std;

const int pow(int a, int n) {
	if (n <= 0)
	{
		return 1;
	}
	
	return a * pow(a, n - 1);
}

vector<unsigned long long> squares;
vector<unsigned long long> initial;

const uint64_t top = pow(10, 18) * 8;

int main()
{
	unsigned long long points = 0;
	cin >> points;

	/*initial.push_back(2);
	initial.push_back(3);
	squares.push_back(1);
	int index = 0;
	int n = 3;
	while (squares[squares.size() - 1] < top)
	{
		if (pow(initial[index], 3) < pow(initial[index + 1], 3))
		{
			initial[index] = pow(initial[index], 3);
			squares.push_back(initial[index]);
		}
		else
		{
			index++;
			n++;
			initial.push_back(n);
		}
	}*/

	/*for (int i = 0; i < squares.size(); i++)
	{
		cout << squares[i] << '\n';
	}*/

	/*int count = 0;
	int last = squares.size() - 1;
	while (points > 0)
	{
		for (int64_t i = last; i >= 0; i--)
		{
			if (squares[i] <= points)
			{
				points -= squares[i];
				cout << points << ' ' << squares[i] << '\n';
				count++;
				last = i;
				break;
			}
		}

		if (points < 8)
		{
			count += points;
			break;
		}
	}*/

	points = top;

	int count = 0;

	while (points > 0)
	{
		points -= pow((int)cbrt(points), 3);
		count++;
	}

	cout << count;
}
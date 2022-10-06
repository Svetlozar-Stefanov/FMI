#include <iostream>

using namespace std;

int main()
{
	int N;

	cin >> N;

	bool hasRoom = false;
	int temp;
	
	for (int i = 0; i < N / 4; i++)
	{
		temp = N - i * 4;
		
		if (temp % 3 == 0)
		{
			hasRoom = true;
			cout << temp / 3 << "x3" << " " << i << "x4\n";
		}
	}

	if (!hasRoom)
	{
		cout << "NO";
	}
}

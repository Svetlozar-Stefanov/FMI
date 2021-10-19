#include <iostream>

using namespace std;

int main()
{
	int roomTemp;
	int condTemp;
	char mode;

	cin >> roomTemp >> condTemp;
	cin >> mode;

	if (mode == 'f')
	{
		if (roomTemp < condTemp)
		{
			cout << roomTemp;
		}
		else if (roomTemp >= condTemp)
		{
			cout << condTemp;
		}
	}
	else if (mode == 'h')
	{
		if (roomTemp <= condTemp)
		{
			cout << condTemp;
		}
		else if (roomTemp > condTemp)
		{
			cout << roomTemp;
		}
	}
	else if (mode == 'a')
	{
		cout << condTemp;
	}
	else if (mode == 'v')
	{
		cout << roomTemp;
	}

}
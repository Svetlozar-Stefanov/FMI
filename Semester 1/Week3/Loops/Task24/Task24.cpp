#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand((unsigned)time(0));

	int randNum = rand() % 9;

	while (time(0)%10 != randNum)
	{
		randNum = rand() % 9;

		cout << "Number: " << randNum<<endl;
		cout << "Date: " << time(0)<<endl;
	}
}

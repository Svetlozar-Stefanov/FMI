#include <iostream>

void segDefOnFive(int num) 
{
	if (num == 5)
	{
		int* p = nullptr;
		int a = *p;
	}
}

int main()
{
	segDefOnFive(5);
}

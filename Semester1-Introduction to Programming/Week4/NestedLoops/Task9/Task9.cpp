#include <iostream>

using namespace std;

void printPlus(int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "*";
	}
}

void printDiez(int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "#";
	}
}

void printUpwardTriangle(int height)
{
	int width = 2 * height - 1;

	for (int i = 1; i <= height; i++)
	{
		printPlus((width - (2 * i - 1)) / 2);
		printDiez((2 * i - 1));
		printPlus((width - (2 * i - 1)) / 2);
		cout << endl;
	}
}

void prindDownwardTriangle(int height)
{
	int width = 2 * height - 1;

	for (int i = height; i >= 1; i--)
	{
		printPlus((width - (2 * i - 1)) / 2);
		printDiez((2 * i - 1));
		printPlus((width - (2 * i - 1)) / 2);
		cout << endl;
	}
}

void printArrowBody(int length) 
{
	for (int i = 0; i < length; i++)
	{
		printPlus(length);
		printDiez(1);
		printPlus(length);
		cout << endl;
	}
}

int main()
{
	int height;
	bool direction;

	cin >> height;
	cin >> direction;

	int width = height * 2 - 1;

	printPlus(width);
	cout << endl;
	if (direction)
	{
		printUpwardTriangle(height);
		printArrowBody(height - 1);
	}
	else if(!direction)
	{
		printArrowBody(height - 1);
		prindDownwardTriangle(height);
	}

	printPlus(width);
	cout << endl;
}

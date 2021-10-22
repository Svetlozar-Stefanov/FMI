#include <iostream>

using namespace std;

int main()
{
	const int key = 51223;

	int value;

	cout << "Enter value: ";
	cin >> value;

	int crypt = value ^ key;
	cout << crypt;

	int userKey;
	cout << "\nEnter key to decrypt: ";
	cin >> userKey;

	cout << "You value was: ";
	cout << (crypt ^ userKey);

}
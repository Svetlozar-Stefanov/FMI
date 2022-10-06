#include <iostream>

using namespace std;

int strlen(char arr[]) 
{
    int count = 0;
    int i = 0;

    while (arr[i] != '\0')
    {
        count++;
        i++;
    }

    return count;
}

int main()
{
    char input[100];

    cin.getline(input, 100);

    cout << strlen(input);
}
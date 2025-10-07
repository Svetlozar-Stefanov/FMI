#include <iostream>

using namespace std;

int main()
{
    int arr[25][25];
    int rows;
    int cols;

    cin >> rows;
    cin >> cols;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        int numberOfNegativeElements = 0;
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] < 0)
            {
                numberOfNegativeElements++;
            }
        }
        cout << numberOfNegativeElements << " ";
    }
}
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
        int min = INT_MAX;
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
        cout << min << " ";
    }
}

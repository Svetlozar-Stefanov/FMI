#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int index = 0;
    do
    {
        cout << arr[index] << " ";

        if (index + k < n)
        {
            index += k;
        }
        else
        {
            index = index + k - n;
        }

    } while (index != 0);
}

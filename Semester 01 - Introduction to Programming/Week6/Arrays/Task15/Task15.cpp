#include <iostream>

using namespace std;

int main()
{
    int arr1[25];
    int arr2[25];

    int n1;
    int n2;

    cin >> n1;

    if (n1 < 1 || n1 > 25)
    {
        return 1;
    }

    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    cout << "\n";

    cin >> n2;

    if (n2 < 1 || n2 > 25)
    {
        return 1;
    }

    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    
    int i1 = 0;
    int i2 = 0;

    int outputArr[50];
    int index = 0;

    while (index < n1 + n2)
    {
        if (arr1[i1] >= arr2[i2] && i2 < n2)
        {
            outputArr[index] = arr2[i2];
            i2++;
            index++;
        }
        else if (arr1[i1] < arr2[i2] && i1 < n1)
        {
            outputArr[index] = arr1[i1];
            i1++;
            index++;
        }
        else if (i1 < n1 && i2 == n2)
        {
            outputArr[index] = arr1[i1];
            i1++;
            index++;
        }
        else if (i2 < n2 && i1 == n1)
        {
            outputArr[index] = arr2[i2];
            i2++;
            index++;
        }
    }


    for (int i = 0; i < n1 + n2; i++)
    {
        cout << outputArr[i] << " ";
    }
}

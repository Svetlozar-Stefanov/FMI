#include <iostream>

using namespace std;

unsigned long countSums(long arr1[], long arr2[], long arr3[],
    const long size1, const long size2, const long size3) 
{
    unsigned long count = 0;

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            for (int k = 0; k < size3; k++)
            {
                if (arr1[i] + arr2[j] == arr3[k]
                    || arr1[i] + arr3[k] == arr2[j]
                    || arr2[j] + arr3[k] == arr1[i])
                {
                    count++;
                }
            }
        }
    }

    return count;
}

int main()
{
    long arr1[3] = {1, 5, 3};
    long arr2[2] = {2, 4};
    long arr3[3] = {6, 3, 0};

    cout << countSums(arr1, arr2, arr3, 3, 2, 3);
}
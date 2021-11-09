#include <iostream>

using namespace std;

int getDigitCount(int n) 
{
    int counter = 0;
    while (n > 0)
    {
        n /= 10;
        counter++;
    }
    return counter;
}

void sortLex(const int n, int arr[]) 
{
    int sortedArr[50];
    

    for (int i = 0; i < n; i++)
    {
        int index = 0;
        int currentNum = arr[i];

        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                int compNum = arr[j];

                if (currentNum == compNum && i > j)
                {
                    index++;
                }
                else if (currentNum != compNum)
                {
                    int temp1 = currentNum;
                    int temp2 = compNum;

                    int dCount1 = getDigitCount(temp1);
                    int dCount2 = getDigitCount(temp2);

                    int minCount = min(dCount1, dCount2);

                    while (minCount >= 1)
                    {
                        int d1 = (temp1 / (int)pow(10, dCount1 - 1)) % 10;
                        int d2 = (temp2 / (int)pow(10, dCount2 - 1)) % 10;

                        if (d1 > d2)
                        {
                            index++;
                            break;
                        }
                        else if (d1 < d2)
                        {
                            break;
                        }

                        dCount1--;
                        dCount2--;
                        minCount--;
                    }

                    if (minCount < 1)
                    {
                        if (dCount1 > dCount2)
                        {
                            index++;
                        }
                    }
                }
            }
        }

        sortedArr[index] = currentNum;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = sortedArr[i];
    }
}

int main()
{
    int arr[50];

    int n;

    cin >> n;

    if (n < 1 || n > 50)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sortLex(n, arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
#include <iostream>

using namespace std;

int getDiv(int a, int divs[]) 
{
    int div = 2;
    int index = 0;

    while (div <= a)
    {
        if (a % div == 0)
        {
            divs[index] = div;

            index++;
        }

        div++;
    }

    return index;
}

bool compDiv(int a, int b) 
{
    int div1[20];
    int div2[20];

    int div1Length = getDiv(a, div1);
    int div2Length= getDiv(b, div2);

    bool areDividable = false;

    for (int i = 0; i < div1Length; i++)
    {
        for (int j = 0; j < div2Length; j++)
        {
            if (div1[i] == div2[j])
            {
                areDividable = true;
                return areDividable;
            }
        }
    }

    return areDividable;
}

int main()
{
    int arr[50];

    int n;
    int k;

    cin >> n;

    if (n < 1 || n > 50)
    {
        return 1;
    }

    cin >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (compDiv(n, k))
    {
        return 1;
    }

    int index = 0;
    int step = 0;
    int output[50];

    do
    {
        output[index] = arr[step];

        if (step + k <= n - 1)
        {
            step += k;
        }
        else if (step + k > n - 1)
        {
            step = step + k - n;
        }
        index++;
    } 
    while (step != 0);

    for (int i = 0; i < n; i++)
    {
        cout<<output[i]<<" ";
    }
}

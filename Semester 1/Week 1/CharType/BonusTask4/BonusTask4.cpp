#include <iostream>

using namespace std;

int main()
{
    int cakeInfo[2][3];

    int weight;
    int diameter;

    for (int i = 0; i < 3; i++)
    {
        cin >> weight >> diameter;

        cakeInfo[0][i] = weight;
        cakeInfo[1][i] = diameter;
    }

    int output[3];

    for (int i = 0; i < 3; i++)
    {
        int currentCakeWeight = cakeInfo[0][i];
        int currentCakeDiameter = cakeInfo[1][i];

        int index = 0;
        for (int j = 0; j < 3; j++)
        {
            if (currentCakeWeight > cakeInfo[0][j]
                && currentCakeDiameter > cakeInfo[1][j])
            {
                index++;
            }
        }

        output[index] = i + 1;
    }

    for (int i = 2; i >= 0; i--)
    {
        cout << output[i] << " ";
    }
}

#include <iostream>

using namespace std;

const char lowerCaseBot = 97;
const char lowerCaseTop = 122;

const char upperCaseBot = 65;
const char upperCaseTop = 90;

unsigned strlen(const char str[])
{
    unsigned counter = 0;

    int index = 0;
    while (str[index] != '\0')
    {
        counter++;
        index++;
    }

    return counter;
}

bool haveSameLetters(const char arr1[], const char arr2[]) 
{
    bool same = true;

    int lenArr1 = strlen(arr1);
    int lenArr2 = strlen(arr2);

    if (lenArr1 != lenArr2)
    {
        same = false;
        return same;
    }

    for (int i = 0; i < lenArr1; i++)
    {
        if (arr1[i] != arr2[i])
        {
            same = false;
            break;
        }
    }

    return same;
}

int main()
{
    char X[255];

    cin >> X;

    char s[255];
    unsigned iLC = 0;

    char S[255];
    unsigned iUC = 0;

    for (int i = 0; i < strlen(X); i++)
    {
        char current = X[i];
        if (lowerCaseBot <= current && current <= lowerCaseTop)
        {
            s[iLC] = current - 32;
            iLC++;
        }
        else if (upperCaseBot <= current && current <= upperCaseTop)
        {
            S[iUC] = current;
            iUC++;
        }
    }
    s[iLC] = '\0';
    S[iUC] = '\0';

    bool same = haveSameLetters(s, S);

    if (same)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}
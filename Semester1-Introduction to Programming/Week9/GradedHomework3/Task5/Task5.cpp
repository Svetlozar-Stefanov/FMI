/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Svetlozar Stefanov
* @idnumber 4MI0600030
* @task 5
* @compiler VC
*
*/

#include <iostream>

using namespace std;

const char LOWERCASE_BOT = 97;
const char LOWERCASE_TOP = 122;

const char UPPERCASE_BOT = 65;
const char UPPERCASE_TOP = 90;

unsigned strleng(const char str[])
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

char toUppercase(char ch) 
{
    if (LOWERCASE_BOT <= ch && ch <= LOWERCASE_TOP)
    {
        ch -= 32;
    }

    return ch;
}

bool haveSameLetters(const char arr1[], const char arr2[]) 
{
    bool same = true;

    int lenArr1 = strleng(arr1);
    int lenArr2 = strleng(arr2);

    if (lenArr1 != lenArr2)
    {
        same = false;
        return same;
    }

    for (int i = 0; i < lenArr1; i++)
    {
        if (toUppercase(arr1[i]) != toUppercase(arr2[i]))
        {
            same = false;
            break;
        }
    }

    return same;
}

bool validateInput(const char input[]) 
{
    bool isValid = true;

    for (int i = 0; i < strleng(input); i++)
    {
        if ((input[i] < UPPERCASE_BOT || input[i] > UPPERCASE_TOP) 
            && (input[i] < LOWERCASE_BOT || input[i] > LOWERCASE_TOP))
        {
            isValid = false;
            break;
        }
    }

    return isValid;
}

int main()
{
    char X[256];
    cin >> X;

    if (!validateInput(X))
    {
        cout << "-1";
        return 1;
    }

    char s[256];
    unsigned iLC = 0;

    char S[256];
    unsigned iUC = 0;

    for (int i = 0; i < strleng(X); i++)
    {
        char current = X[i];
        if (LOWERCASE_BOT <= current && current <= LOWERCASE_TOP)
        {
            s[iLC] = current;
            iLC++;
        }
        else if (UPPERCASE_BOT <= current && current <= UPPERCASE_TOP)
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
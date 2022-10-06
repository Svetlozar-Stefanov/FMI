#include <iostream>

using namespace std;

int strlen(char arr[])
{
    int count = 0;
    int i = 0;

    while (arr[i] != '\0')
    {
        count++;
        i++;
    }

    return count;
}

bool contains(char ch, char arr[]) 
{
    for (int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] == ch)
        {
            return true;
        }
    }

    return false;
}

void encode(const char s1[], const char r1[], const char s2[], char * r2 = '\0')
{
    char temp[100] = {};
    
    r2 = temp;

    char code[26] = {};
    int index;

    int sizeS1 = strlen(s1);
    int sizeR1 = strlen(r1);
    int sizeS2 = strlen(s2);

    if (sizeS1 == sizeR1)
    {
        for (int i = 0; i < sizeS1; i++)
        {
            index = s1[i] - 'a';
            if (code[index] != '\0' && code[index] != r1[i])
            {
                return;
            }
            else
            {
                code[index] = r1[i];
            }
        }

        for (int i = 0; i < sizeS2; i++)
        {
            index = s2[i] - 'a';
            if (code[index] != '\0')
            {
                r2[i] = code[index];
            }
            else
            {
                r2[i] = s2[i];
            }
        }


        for (int i = 0; i < strlen(r2); i++)
        {
            cout << r2[i];
        }
    }
}

int main()
{
    encode("hello", "worrd", "love");
}

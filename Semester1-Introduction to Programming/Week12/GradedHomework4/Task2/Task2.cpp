/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Svetlozar Stefanov
* @idnumber 4MI0600030
* @task 2
* @compiler VC
*
*/

#include <iostream>

int strleng(const char* str)
{
    if (str == nullptr)
    {
        return -1;
    }

    unsigned count = 0;
    unsigned i = 0;
    while (str[i] != '\0')
    {
        count++;
        i++;
    }

    return count;
}

bool match(const char * text, const int index, const char * str) 
{
    if (text == nullptr)
    {
        return false;
    }
    
    for (int i = 0; i < strleng(str); i++)
    {
        if (strleng(text) < index + i 
            || text[index + i] != str[i])
        {
            return false;
        }
    }

    return true;
}

int replace(char* text, const char* const str1, const char* const str2) 
{
    if (text == nullptr
        || str1 == nullptr
        || str2 == nullptr)
    {
        return -2;
    }

    if (strleng(text) <= 0 
        || strleng(str1) <= 0)
    {
        return -3;
    }

    char* newText = new char[4096];
    int count = 0;

    int index = 0;
    for (int i = 0; i < strleng(text); i++)
    {
        if (text[i] == str1[0] && match(text, i, str1))
        {
            for (int j = 0; j < strleng(str2); j++)
            {
                newText[index + j] = str2[j];
            }

            index += strleng(str2);
            i += strleng(str1) - 1;
            count++;
            continue;
        }

        newText[index++] = text[i];
    }
    newText[index] = '\0';

    for (int i = 0; i <= strleng(newText); i++)
    {
        text[i] = newText[i];
    }
    
    return count;
}

int main()
{
    char text[4096];
    char str1[1024];
    char str2[1024];

    std::cin.getline(text, 4096);
    std::cin.getline(str1, 1024);
    std::cin.getline(str2, 1024);

    std::cout << replace(text, str1, str2) << '\n';

    for (int i = 0; i < strleng(text); i++)
    {
        std::cout << text[i];
    }
}
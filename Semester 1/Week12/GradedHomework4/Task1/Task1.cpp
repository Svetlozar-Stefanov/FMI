/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Svetlozar Stefanov
* @idnumber 4MI0600030
* @task 1
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

unsigned numberOfPerm(const char* str)
{
    unsigned lettersCount = 0;
    for (int i = 0; i < strleng(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            lettersCount++;
        }
    }

    return pow(2, lettersCount);
}

char** createMatrix(const unsigned rows)
{
    char** matrix = new char* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = nullptr;
    }

    return matrix;
}

void deleteMatrix(char** matrix, const int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete matrix[i];
    }
    delete[] matrix;
}

bool equal(const char * str1, const char * str2) 
{
    if (str1 == nullptr
        || str2 == nullptr)
    {
        return false;
    }

    unsigned ln1 = strleng(str1);
    unsigned ln2 = strleng(str2);
    if (ln1!=ln2)
    {
        return false;
    }

    for (int i = 0; i < ln1; i++)
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
    }

    return true;
}

bool contains(const char * str, char** permutations, const unsigned nP)
{
    if (str == nullptr
        || permutations == nullptr)
    {
        return false;
    }

    for (int i = 0; i < nP; i++)
    {
        if (permutations[i] != nullptr && equal(permutations[i], str))
        {
            return true;
        }
    }

    return false;
}

char* copy(const char* str)
{
    if (str == nullptr)
    {
        return nullptr;
    }

    unsigned ln = strleng(str);
    char* newStr = new char[ln + 1];
    newStr[ln] = '\0';

    for (int i = 0; i < ln; i++)
    {
        newStr[i] = str[i];
    }

    return newStr;
}

void getPermutations(char* str, const int index, int &pI, char** permutations, const unsigned nP) 
{
    if (str == nullptr
        || permutations == nullptr)
    {
        return;
    }

    permutations[pI] = copy(str);

    for (int i = index; i < strleng(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
            if (!contains(str, permutations, nP))
            {
                getPermutations(str, i, ++pI, permutations, nP);
            }

            str[i] += 32;
            if(!contains(str, permutations, nP))
            {
                getPermutations(str, ++i, ++pI, permutations, nP);
            }
            
        }
    }
}

void sortLexicographically(char** permutations, const unsigned nP)
{
    if (permutations == nullptr)
    {
        return;
    }

    for (int i = 0; i < nP; i++)
    {
        for (int j = 0; j < nP - i - 1; j++)
        {
            for (int l = strleng(permutations[j]) - 1; l >= 0; l--)
            {
                if (permutations[j][l] < permutations[j + 1][l])
                {
                    char* temp = permutations[j];
                    permutations[j] = permutations[j + 1];
                    permutations[j + 1] = temp;
                }
            }
        }
    }
}

char** letterCasePermutation(char* str)
{
    unsigned nP = numberOfPerm(str);

    char** permutations = createMatrix(nP);

    int pI = 0;
    getPermutations(str, 0, pI, permutations, nP);
    sortLexicographically(permutations, nP);
    
    return permutations;
}

int main()
{
    char input[100];
    std::cin >> input;

    char ** permutations = letterCasePermutation(input);

    int nP = numberOfPerm(input);
    for (int i = 0; i < nP; i++)
    {
        std::cout << permutations[i] << " ";
    }

    deleteMatrix(permutations, nP);
}
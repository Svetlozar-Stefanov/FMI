/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Svetlozar Stefanov
* @idnumber 4MI0600030
* @task 4
* @compiler VC
*
*/

#include <iostream>

bool isLesserHacksaw(const int* n, const int size, const int i)
{
    bool hacksaw = false;

    if (i == size - 1 
        && i % 2 != 0 
        && n[i - 1] < n[i])
    {
        hacksaw = true;
        return hacksaw;
    }
    if (i == size - 1
        && i % 2 == 0
        && n[i - 1] > n[i])
    {
        hacksaw = true;
        return hacksaw;
    }
    if (i % 2 != 0 && n[i - 1] < n[i] && n[i] > n[i+1])
    {
        hacksaw = true;
        return hacksaw && isLesserHacksaw(n,size,i + 1);
    }
    if (i % 2 == 0 && n[i - 1] > n[i] && n[i] < n[i + 1])
    {
        hacksaw = true;
        return hacksaw && isLesserHacksaw(n, size, i + 1);
    }

    return hacksaw;
}

bool isBiggerHacksaw(const int* n, const int size, const int i)
{
    bool hacksaw = false;

    if (i == size - 1
        && i % 2 != 0
        && n[i - 1] > n[i])
    {
        hacksaw = true;
        return hacksaw;
    }
    if (i == size - 1
        && i % 2 == 0
        && n[i - 1] < n[i])
    {
        hacksaw = true;
        return hacksaw;
    }
    if (i % 2 != 0 && n[i - 1] > n[i] && n[i] < n[i + 1])
    {
        hacksaw = true;
        return hacksaw && isBiggerHacksaw(n, size, i + 1);
    }
    if (i % 2 == 0 && n[i - 1] < n[i] && n[i] > n[i + 1])
    {
        hacksaw = true;
        return hacksaw && isBiggerHacksaw(n, size, i + 1);
    }

    return hacksaw;
}

bool isHacksaw(const int * n, const int size)
{
    if (n[0] < n[1])
    {
        return isLesserHacksaw(n,size,1);
    }
    if (n[0] > n[1])
    {
        return isBiggerHacksaw(n,size,1);
    }
    return false;
}

int main()
{
    int N;
    std::cin >> N;

    int* n = new int[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> n[i];
    }

    if (N < 3)
    {
        std::cout << "-1";
        return 1;
    }

    if (isHacksaw(n, N))
    {
        std::cout << "yes";
    }
    else
    {
        std::cout << "no";
    }

    delete[] n;
}

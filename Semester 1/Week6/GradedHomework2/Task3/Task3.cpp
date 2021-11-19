#include <iostream>

using namespace std;

int firstNumAfterTarget(unsigned n, const unsigned target) 
{
    while (n < target)
    {
        n *= 2;
    }

    return n;
}

int shortestPath(unsigned startValue, const unsigned target)
{
    unsigned steps = 0;

    while (startValue != target)
    {
        if (startValue > target)
        {
            while (startValue > target)
            {
                startValue--;
                steps++;
            }
        }
        else if (startValue < target)
        {
            unsigned multipiledNum = firstNumAfterTarget(startValue, target);

            unsigned subtractedNum = startValue;
            if (startValue > 1)
            {
                subtractedNum -= 1;
            }
            subtractedNum = firstNumAfterTarget(subtractedNum, target);

            if (multipiledNum - target <= subtractedNum - target)
            {
                startValue *= 2;
                steps++;
            }
            else if (multipiledNum - target > subtractedNum - target)
            {
                startValue -= 1;
                steps++;
            }
        }
    }

    return steps;
}

int main()
{
    unsigned n;
    unsigned target;

    if (!(cin >> n) 
        || n < 0
        || !(cin >> target))
    {
        cout << "-1";
        return 1;
    }
    
    cout << shortestPath(n, target);

    return 0;
}

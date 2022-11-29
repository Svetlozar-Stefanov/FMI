#include <iostream>

const double eps = 0.0000001;

bool equal(double x1, double x2)
{
    return abs(x1 - x2) < eps;
}

double F(double x)
{
    return (3 * x * x - 4 * x + 8) / (x + 4);
}

double nthTerm(double a, int n)
{
    if (n == 1)
    {
        return a;
    }

    return nthTerm(F(a), n-1);
}

int main()
{
    std::cout << "We are given a sequence {an}, where an+1 = F(an) and a1 = p for each natural n\n";
    std::cout << "F(x) = (3x ^ 2 - 4x + 8) / x + 4\n";
    std::cout << "Please enter p: ";
    double p;
    std::cin >> p;

    std::cout << "Limit: ";
    if (p < -4)
    {
        std::cout << "-inf\n";
    }
    else if (equal(p, -4))
    {
        std::cout << "Invalid p\n";
        return 0;
    }
    else if (-4 < p && p < 0)
    {
        std::cout << "+inf\n";
    }
    else if (0 <= p && p <= 2)
    {
        std::cout << "2\n";
    }
    else if (p > 2)
    {
        std::cout << "+inf\n";
    }

    while (true)
    {
        std::cout << "Please enter index: ";
        int index;
        std::cin >> index;
        if (index < 0)
        {
            std::cout << "Invalid index!\n";
            continue;
        }

        std::cout << "a" << index << " = " << nthTerm(p,index) << '\n';
    }
}

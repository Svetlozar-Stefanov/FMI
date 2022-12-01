#include <iostream>
#include <cmath>

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

void menu() {

    char c = 'p';
    double p = 1;
    while (c != 'e')
    {
        if (c == 'p')
        {
            std::cout << "Please enter p: ";
            std::cin >> p;
            while (equal(p, -4))
            {
                std::cout << "Invalid p\n";
                std::cout << "Please enter valid p: ";
                std::cin >> p;
            }

            if (p < -4)
            {
                std::cout << "Limit: ";
                std::cout << "-inf\n";
            }
            else if (-4 < p && p < 0)
            {
                std::cout << "Limit: ";
                std::cout << "+inf\n";
            }
            else if (0 <= p && p <= 2)
            {
                std::cout << "Limit: ";
                std::cout << "2\n";
            }
            else if (p > 2)
            {
                std::cout << "Limit: ";
                std::cout << "+inf\n";
            }
        }
        else if (c == 'i')
        {
            std::cout << "Input 0 to stop\n";
            int index;
            do
            {
                std::cin >> index;
                if (index < 0)
                {
                    std::cout << "Invalid index!\n";
                }
                else if (index == 0)
                {
                    break;
                }

                double n = nthTerm(p, index);
                if (isnan(n) && ((p > -4 && p < 0) || p > 2))
                {
                    std::cout << "a" << index << " = inf\n";
                }
                else if (isnan(n) && p < -4)
                {
                    std::cout << "a" << index << " = -inf\n";
                }
                else
                {
                    std::cout << "a" << index << " = " << n << '\n';
                }
            } while (true);
            
        }
        else if (c == 'h')
        {
            std::cout << "p - new p\ni - index\ne - end\n";
        }
        else
        {
            std::cout << "Invalid command!\n";
        }
        std::cout << "Please enter command: ";
        std::cin >> c;
    }
}

int main()
{
    std::cout << "We are given a sequence {an}, where an+1 = F(an) and a1 = p for each natural n\n";
    std::cout << "F(x) = (3x ^ 2 - 4x + 8) / x + 4\n";
    
    menu();
}

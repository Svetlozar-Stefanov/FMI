#include <iostream>

struct ComplexNumber
{
    double rP;
    double iP;
};

ComplexNumber addNumbers(const ComplexNumber n1, const ComplexNumber n2)
{
    ComplexNumber newNum;
    newNum.rP = n1.rP + n2.rP;
    newNum.iP = n1.iP + n2.iP;

    return newNum;
}

void printCN(const ComplexNumber num) 
{
    std::cout << num.rP << " + i" << num.iP << "\n";
}


int main()
{
    std::cout << "Hello World!\n";
}

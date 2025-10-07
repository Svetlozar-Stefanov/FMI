#include <iostream>

struct Point
{
    int x;
    int y;
};

bool CheckRectangular(const Point& A, const Point& B, const Point& C)
{
    int ABt2 = (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
    int ACt2 = (A.x - C.x) * (A.x - C.x) + (A.y - C.y) * (A.y - C.y);
    int BCt2 = (B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y);

    if (ABt2 > ACt2 + BCt2
        && ACt2 > ABt2 + BCt2
        && BCt2 > ABt2 + ACt2)
    {
        return false;
    }

    if (ABt2 > ACt2 && ABt2 > BCt2
        && ABt2 == ACt2 + BCt2)
    {
        return true;
    }

    if (ACt2 > ABt2 && ACt2 > BCt2
        && ACt2 == ABt2 + BCt2)
    {
        return true;
    }

    if (BCt2 > ABt2 && BCt2 > ACt2
        && BCt2 == ABt2 + ACt2)
    {
        return true;
    }

    return false;
}

int main()
{
    Point A;
    A.x = 5;
    A.y = 0;

    Point B;
    B.x = 0;
    B.y = 4;

    Point C;
    C.x = 5;
    C.y = 4;

    std::cout << CheckRectangular(A,B,C);
}
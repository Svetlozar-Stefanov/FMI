/**
*
* Solution to homework assignment 1
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

#define EPS 0.000001;

using namespace std;

double absOf(const double number) 
{
    if (number < 0)
    {
        return -number;
    }
    return number;
}

bool areEqual(const double n1, const double n2) 
{
    return absOf(n1 - n2) < EPS;
}

int main()
{
    const double mainCircleRadius = 4.0;
    const double coordinateSquareSide = 4.0;

    double x;
    double y;

    if (!(cin >> x))
    {
        cout << "-1";
        return 1;
    }
    if (!(cin >> y))
    {
        cout << "-1";
        return 1;
    }

    double distanceFromCenter = sqrt(x * x + y * y);

    if (distanceFromCenter > mainCircleRadius
        && (absOf(x) > coordinateSquareSide || absOf(y) > coordinateSquareSide))
    {
        cout << "Outside";
    }
    else if (distanceFromCenter > mainCircleRadius
        && (absOf(x) < coordinateSquareSide && absOf(y) < coordinateSquareSide))
    {
        cout << "White";
    }
    else if(areEqual(distanceFromCenter, mainCircleRadius)
        || (areEqual(absOf(x), coordinateSquareSide) && absOf(y) <= coordinateSquareSide)
        || (areEqual(absOf(y), coordinateSquareSide)) && absOf(x) <= coordinateSquareSide)
    {
        cout << "Undefined";
    }
    else if(distanceFromCenter < mainCircleRadius)
    {
        if (x >= 0)
        {
            const double secondaryCircleCenterX = 2.0;
            const double secondaryCircleRadius = 1.0;

            double distanceFromSecondaryCenter = sqrt((x - secondaryCircleCenterX) * (x - secondaryCircleCenterX) + y * y);

            if (distanceFromSecondaryCenter < secondaryCircleRadius)
            {
                cout << "Black";
            }
            else if (areEqual(distanceFromSecondaryCenter, secondaryCircleRadius))
            {
                cout << "Undefined";
            }
            else if (distanceFromSecondaryCenter > secondaryCircleRadius)
            {
                if (y > 0)
                {
                    cout << "White";
                }
                else if (y <= 0)
                {
                    const double semiCircleRadius = 2.0;

                    if (distanceFromSecondaryCenter < semiCircleRadius)
                    {
                        cout << "White";
                    }
                    else if (areEqual(distanceFromSecondaryCenter, semiCircleRadius))
                    {
                        cout << "Undefined";
                    }
                    else if (distanceFromSecondaryCenter > semiCircleRadius)
                    {
                        cout << "Black";
                    }
                }
            }
        }
        else if (x < 0)
        {
            const double secondaryCircleCenterX = -2.0;
            const double secondaryCircleRadius = 1.0;

            double distanceFromSecondaryCenter = sqrt((x - secondaryCircleCenterX) * (x - secondaryCircleCenterX) + y * y);

            if (distanceFromSecondaryCenter < secondaryCircleRadius)
            {
                cout << "White";
            }
            else if (areEqual(distanceFromSecondaryCenter, secondaryCircleRadius))
            {
                cout << "Undefined";
            }
            else if (distanceFromSecondaryCenter > secondaryCircleRadius)
            {
                if (y > 0)
                {
                    const double semiCircleRadius = 2.0;

                    if (distanceFromSecondaryCenter < semiCircleRadius)
                    {
                        cout << "Black";
                    }
                    else if (areEqual(distanceFromSecondaryCenter, semiCircleRadius))
                    {
                        cout << "Undefined";
                    }
                    else if (distanceFromSecondaryCenter > semiCircleRadius)
                    {
                        cout << "White";
                    }
                }
                else if (y < 0)
                {
                    cout << "Black";
                }
            }
        }
    }
}


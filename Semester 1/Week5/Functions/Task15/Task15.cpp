#include <iostream>

using namespace std;

bool isValidTriangle(const int a, const int b, const int c)
{
    return (a < b + c) && (b < a + c) && (c < b + a);
}

void PrintSides(const int* triangles)
{
    int index = 0;

    while (triangles[index] > 0)
    {
        cout << triangles[index++] << " ";
        cout << triangles[index++] << " ";
        cout << triangles[index++] << endl;
    }
}

void printTriangleSides(const int numberOfTriangles) 
{
    int* triangles = new int[numberOfTriangles * 3 + 1];

    int a;
    int b;
    int c;

    int index = 0;

    for (int i = 0; i < numberOfTriangles; i++)
    {
        cin >> a;
        cin >> b;
        cin >> c;

        if (isValidTriangle(a, b, c))
        {
            triangles[index] = a;
            index++;
            triangles[index] = b;
            index++;
            triangles[index] = c;
            index++;
        }
    }

    cout << endl;

    PrintSides(triangles);
}

int main()
{
    int n;
    cin >> n;

    printTriangleSides(n);
}

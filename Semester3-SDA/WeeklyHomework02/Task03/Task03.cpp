#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(int64_t* arr, int i1, int i2)
{
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}

void insertionSort(int64_t* arr, int size) {
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            swap(arr, j, j + 1);
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    string program;
    cin >> program;

    int counter[256] = {0};
    int64_t indices[256];
    for (int i = 0; i < 256; i++)
    {
        indices[i] = -1;
    }

    for (uint64_t i = 0; i < program.size(); i++)
    {
        counter[(int)program[i]]++;
        if (indices[(int)program[i]] == -1)
        {
            indices[(int)program[i]] = i;
        }
    }

    insertionSort(indices, 256);

    for (int i = 0; i < 256; i++)
    {
        if (indices[i] != -1 && counter[(int)program[indices[i]]] == 1)
        {
            cout << indices[i] << " ";
            counter[(int)program[indices[i]]] = 0;
        }
    }
}
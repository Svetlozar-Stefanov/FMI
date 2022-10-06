#include <iostream>
using namespace std;

int partition(int * arr, int left, int right, int pivot) 
{
    int lP = left;
    for (int i = left; i <= right; i++)
    {
        if (arr[i] <= pivot)
        {
            int temp = arr[i];
            arr[i] = arr[lP];
            arr[lP] = temp;
            lP++;
        }
    }
    lP--;

    return lP;
}

void quicksort(int* arr, int left, int right) 
{
    if (left >= right)
    {
        return;
    }

    int pivot = arr[right];

    int middle = partition(arr, left, right, pivot);

    quicksort(arr, left, middle - 1);
    quicksort(arr, middle + 1, right);
}

void merge(int* arr, int left, int middle, int right) 
{
    int s1 = middle - left + 1;
    int s2 = right - middle;

    int* arr1 = new int[s1];
    int* arr2 = new int[s2];

    for (int i = 0; i < s1; i++)
    {
        arr1[i] = arr[left + i];
    }
    for (int i = 0; i < s2; i++)
    {
        arr2[i] = arr[middle + 1 + i];
    }

    int i1 = 0;
    int i2 = 0;
    int mI = left;

    while (i1 < s1 && i2 < s2)
    {
        if (arr1[i1] < arr2[i2])
        {
            arr[mI++] = arr1[i1++];
        }
        else
        {
            arr[mI++] = arr2[i2++];
        }
    }

    while (i1 < s1)
    {
        arr[mI++] = arr1[i1++];
    }
    while (i2 < s2)
    {
        arr[mI++] = arr2[i2++];
    }

    delete[] arr1;
    delete[] arr2;
}

void mergesortHelper(int * arr, int left, int right) 
{
    if (left >= right)
    {
        return;
    }

    int middle = left + (right - left) / 2;

    mergesortHelper(arr, left, middle);
    mergesortHelper(arr, middle + 1, right);

    merge(arr, left, middle, right);
}

void mergesort(int * arr, int size) 
{
    mergesortHelper(arr, 0, size - 1);
}

int main()
{
    int N;
    cin >> N;

    int* T = new int[N];
    int temp = 0;
    int size = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        if (temp > 0)
        {
            T[size++] = temp;
        }
    }

    mergesort(T, size);

    for (int i = 0; i < size; i++)
    {
        cout << T[i] << " ";
    }
    cout << '\n';

    int res = 1;

    for (int i = 0; i < size; i++)
    {
        if (res < T[i])
        {
            std::cout << res;
            return 0;
        }
        else if(res == T[i])
        {
            res++;
        }
    }

    std::cout << res;
}

//bool contains(int* arr, int size, int num)
//{
//    for (int i = 0; i < size; i++)
//    {
//        if (arr[i] == num)
//        {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//int main()
//{
//    int N;
//    cin >> N;
//
//    int* T = new int[N];
//    for (int i = 0; i < N; i++)
//    {
//        cin >> T[i];
//    }
//
//    long long int num = 1;
//    while (contains(T, N, num))
//    {
//        num++;
//    }
//
//    cout << num;
//}
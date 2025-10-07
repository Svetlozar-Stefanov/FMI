#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& arr, int i1, int i2) {
    int temp = arr[i2];
    arr[i2] = arr[i1];
    arr[i1] = temp;
}

int partition(vector<int>& arr, int l, int r)
{
    int pivot = arr[r];
    int s = l;
    for (int i = l; i < r; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr, i, s);
            s++;
        }
    }
    swap(arr, s, r);

    return s;
}

void quicksortHelper(vector<int>& arr, int l, int r)
{
    if (l>=r)
    {
        return;
    }

    int p = partition(arr, l, r);

    quicksortHelper(arr, l, p - 1);
    quicksortHelper(arr, p+1, r);
}

void quicksort(vector<int> &arr) {
    quicksortHelper(arr, 0, arr.size() - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr1(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr1[i];
    }

    int M;
    cin >> M;
    vector<int> arr2(M);
    for (int i = 0; i < M; i++)
    {
        cin >> arr2[i];
    }

    quicksort(arr1);
    quicksort(arr2);

    int i1 = 0;
    int i2 = 0;
    int sum = 0;
    while (i1 < arr1.size() && i2 < arr2.size())
    {
        if (arr1[i1] > arr2[i2])
        {
            i2++;
        }
        else if (arr1[i1] < arr2[i2])
        {
            i1++;
        }
        else
        {
            int u = arr1[i1];
            sum += u;
            while (arr1[i1] == u)
            {
                i1++;
            }
            while (arr2[i2] == u)
            {
                i2++;
            }
        }
    }

    while (i1 < arr1.size())
    {
        if (arr1[i1] == arr2[i2])
        {
            int u = arr1[i1];
            sum += u;
            while (arr1[i1] == u)
            {
                i1++;
            }
            while (arr2[i2] == u)
            {
                i2++;
            }
        }
        i1++;
    }

    while (i2 < arr2.size())
    {
        if (arr1[i1] == arr2[i2])
        {
            int u = arr1[i1];
            sum += u;
            while (arr1[i1] == u)
            {
                i1++;
            }
            while (arr2[i2] == u)
            {
                i2++;
            }
        }
        i2++;
    }
    
    cout << sum;
}

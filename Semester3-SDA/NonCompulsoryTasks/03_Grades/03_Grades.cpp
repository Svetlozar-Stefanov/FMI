#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int findClosestUpper(vector<int64_t> arr, int64_t target, int l, int r)
//{
//    if (r - l <= 1)
//    {
//        if (target >= arr[r])
//        {
//            return r;
//        }
//        return l;
//    }
//
//    int m = l + (r - l) / 2;
//    if (target >= arr[m])
//    {
//        return findClosestUpper(arr, target, m, r);
//    }
//    return findClosestUpper(arr, target, l, m);
//}
//
//int findClosestLower(vector<int64_t> arr, int64_t target, int l, int r)
//{
//    if (r - l <= 1)
//    {
//        if (target <= arr[l])
//        {
//            return l;
//        }
//        return r;
//    }
//
//    int m = l + (r - l) / 2;
//    if (target <= arr[m])
//    {
//        return findClosestLower(arr, target, l, m);
//    }
//    return findClosestLower(arr, target, m, r);
//}

int findClosestUpper(vector<int64_t> arr, int64_t target, int l, int r)
{
    if (l >= r)
    {
        return l;
    }

    int m = l + (r - l) / 2;
    if (target >= arr[m])
    {
        return findClosestUpper(arr, target, m+1, r);
    }
    return findClosestUpper(arr, target, l, m-1);
}

int findClosestLower(vector<int64_t> arr, int64_t target, int l, int r)
{
    if (l >= r)
    {
        return l;
    }

    int m = l + (r - l) / 2;
    if (target <= arr[m])
    {
        return findClosestLower(arr, target, l, m-1);
    }
    return findClosestLower(arr, target, m+1, r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    vector<int64_t> grades(N);
    for (int i = 0; i < N; i++)
    {
        cin >> grades[i];
    }

    sort(grades.begin(), grades.end());

    for (int i = 0; i < Q; i++)
    {
        int64_t lR, rR;
        cin >> lR >> rR;
        if (rR < lR)
        {
            printf("%i\n", 0);
            continue;
        }

        int l = findClosestLower(grades, lR, 0, N - 1);
        int r = findClosestUpper(grades, rR, 0, N - 1);

        if (r >= N || grades[r] > rR)
        {
            r--;
        }
        if (l < 0 || grades[l] < lR)
        {
            l++;
        }

        int res =  r - l + 1;

        printf("%i\n", res);
    }
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Query {
    int64_t S;
    int64_t P;
};

//int findClosestIndex(vector<int64_t>& arr, int64_t n, int l, int r) 
//{
//    if (l >= r)
//    {
//        return l;
//    }
//
//    int middle = l + (r - l) / 2;
//
//    if (n >= arr[middle])
//    {
//        return findClosestIndex(arr, n, middle + 1, r);
//    }
//
//    return findClosestIndex(arr, n, l, middle - 1);
//}

int findClosestIndex(vector<int64_t>& arr, int64_t n, int l, int r)
{
    if (r - l <= 1)
    {
        if (arr[l] >= n)
        {
            return l;
        }

        return r;
    }

    int middle = l + (r - l) / 2;

    if (n >= arr[middle])
    {
        return findClosestIndex(arr, n, middle, r);
    }

    return findClosestIndex(arr, n, l, middle);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;

    cin >> N;
    cin >> Q;
    
    vector<int64_t> numbers(N);
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }

    vector<Query> queries(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> queries[i].S;
        cin >> queries[i].P;
    }

    sort(numbers.begin(), numbers.end());

    /*for (int i = 0; i < N; i++)
    {
        cout << numbers[i] << ' ';
    }
    cout << '\n';

    while (true)
    {
        int n;
        cin >> n;
        cout << findClosestIndex(numbers, n, 0, numbers.size() - 1) << '\n';
    }*/

    vector<int64_t> sums(N);
    for (int i = 0; i < N; i++)
    {
        sums[i] = numbers[i];
        if (i == 0)
        {
            continue;
        }
        sums[i] += sums[i - 1];
    }

    for (int i = 0; i < Q; i++)
    {
        uint64_t S, P;
        S = queries[i].S;
        P = queries[i].P;
        if (P>S)
        {
            printf("%i\n", 0);
            continue;
        }

        int eIdx = findClosestIndex(numbers, P, 0, N - 1);
        if (numbers[eIdx] > queries[i].P)
        {
            eIdx--;
        }
        
        int64_t diff = sums[eIdx] - S;
        int sIdx = 0;
        if (diff > 0)
        {
            sIdx = findClosestIndex(sums, diff, 0, sums.size() - 1) + 1;
        }
         
        printf("%i\n", eIdx - sIdx + 1);
    }
}
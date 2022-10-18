#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Query {
    int64_t S;
    int64_t P;
};

int findClosestIndex(vector<int64_t>& arr, int64_t n, int l, int r) 
{
    if (r - l <= 1)
    {
        if (arr[r] <= n)
        {
            return r;
        }
        else if (arr[l] <= n)
        {
            return l;
        }

        return -1;
    }

    int middle = l + (r - l) / 2;

    if (n < arr[middle])
    {
        return findClosestIndex(arr, n, l, middle);
    }
    else if (n > arr[middle])
    {
        return findClosestIndex(arr, n, middle, r);
    }

    return middle;
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

    for (int i = 0; i < Q; i++)
    {
        uint64_t S, P;
        S = queries[i].S;
        P = queries[i].P;

        int index = findClosestIndex(numbers, P, 0, N - 1);
        int counter = 0;
        uint64_t sum = 0;
        for (int i = index; i >= 0; i--)
        {
            sum += numbers[i];
            if (sum > S)
            {
                break;
            }
            counter++;
        }
        printf("%i\n", counter);
    }
}
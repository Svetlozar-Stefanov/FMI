#include <iostream>
#include <vector>

using namespace std;

void Task01() {

    int counter[70000] = { 0 };
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int number;
        cin >> number;

        counter[number]++;
    }

    for (int i = 0; i < 70000; i++)
    {
        if (counter[i] > 0)
        {
            cout << i << " ";
        }
    }
}

struct Score {
    int64_t n;
    int64_t eN;
};

bool operator==(const Score& s1, const Score& s2)
{
    return s1.n * s1.n * s2.eN == s2.n * s2.n * s1.eN;
}

bool operator>(const Score& s1, const Score& s2) {
    return s1.n * s1.n * s2.eN > s2.n * s2.n * s1.eN;
}

bool operator>=(const Score& s1, const Score& s2) {
    if (s1 == s2 && s1.n > s2.n)
    {
        return true;
    }

    return s1.n * s1.n * s2.eN > s2.n * s2.n * s1.eN;
}

vector<Score> scores;

void swap(vector<int>& arr, int i1, int i2)
{
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}

int partition(vector<int>& arr, int l, int r)
{
    int pivot = arr[r];

    int s = l;
    for (int i = l; i < r; i++)
    {
        if (scores[arr[i]] >= scores[pivot])
        {
            swap(arr, s, i);
            s++;
        }
    }
    swap(arr, s, r);

    return s;
}

int randomized_partition(vector<int>& arr, int l, int r)
{
    int pI = rand() % (r - l) + l;
    swap(arr, pI, r);
    return partition(arr, l, r);
}

void quicksortHelper(vector<int>& arr, int l, int r) {
    if (l >= r)
    {
        return;
    }

    int m = randomized_partition(arr, l, r);

    quicksortHelper(arr, l, m - 1);
    quicksortHelper(arr, m + 1, r);
}

void quicksort(vector<int>& arr) {
    quicksortHelper(arr, 0, arr.size() - 1);
}

void Task02() {
    int N;
    cin >> N;

    vector<int> indices(N);
    for (int i = 0; i < N; i++)
    {
        Score sc;
        cin >> sc.n;
        cin >> sc.eN;

        scores.push_back(sc);
        indices[i] = i;
    }

    quicksort(indices);

    for (int i = 0; i < N; i++)
    {
        cout << indices[i] + 1 << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Task02();
}
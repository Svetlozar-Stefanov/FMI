#include <iostream>
#include <vector>

using namespace std;

int findStrawberryPile(vector<uint64_t> &sums, int64_t target, int l, int r) {
    if (r - l <= 1)
    {
        if (target <= sums[l])
        {
            return l;
        }
        return r;
    }

    int m = l + (r - l) / 2;
    if (target <= sums[m])
    {
        return findStrawberryPile(sums, target, l, m);
    }
    return findStrawberryPile(sums, target, m, r);
}

int main()
{
    int N, Q;
    cin >> N;
    vector<uint64_t> sums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> sums[i];
        if (i == 0)
        {
            continue;
        }
        sums[i] += sums[i-1];
    }

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        uint64_t strawberryNumber;
        cin >> strawberryNumber;

        cout << findStrawberryPile(sums, strawberryNumber, 0, N-1) + 1 << '\n';
    }
}
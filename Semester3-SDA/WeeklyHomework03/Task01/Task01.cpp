#include <iostream>
#include <vector>

using namespace std;

uint64_t power(uint64_t n, uint64_t p)
{
    uint64_t res = 1;
    for (uint64_t i = 0; i < p; i++)
    {
        res *= 3;
    }
    return res;
}

void calcCandy(int64_t idx, int64_t l, int64_t r, uint64_t& c)
{
    c++;
    if (l >= r)
    {
        if (l == r)
        {
            return;
        }
    }

    int64_t m1 = (2 * l + r) / 3;
    int64_t m2 = (l + 2 * r) / 3;

    if (idx <= m1)
    {
        calcCandy(idx, l, m1, c);
    }
    else if (m1 < idx && idx <= m2)
    {
        return;
    }
    else if (idx > m2)
    {
        calcCandy(idx, m2 + 1, r, c);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, P;
    cin >> P;
    cin >> N;

    uint64_t size = power(3, P);

    for (int i = 0; i < N; i++)
    {
        int64_t idx;
        cin >> idx;

        uint64_t c = 0;
        calcCandy(idx - 1, 0, size - 1, c);
        cout << c << "\n";
    }
}
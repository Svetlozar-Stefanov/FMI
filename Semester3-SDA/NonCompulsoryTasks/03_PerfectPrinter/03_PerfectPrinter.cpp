#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool check(vector<int> printers, int64_t time, int64_t target) {
    int64_t sum = 0;
    for (int i = 0; i < printers.size(); i++)
    {
        sum += time / printers[i];
    }
    if (sum >= target)
    {
        return true;
    }
    return false;
}

void findMinimalTime(vector<int> printers, int64_t l, int64_t r, int64_t target, uint64_t& time) {
    if (l > r)
    {
        return;
    }
    int64_t t = l + (r - l) / 2;
    
    if (check(printers, t, target))
    {
        if (time > t)
        {
            time = t;
        }
        findMinimalTime(printers, l, t-1, target, time);
    }
    else
    {
        findMinimalTime(printers, t+1, r, target, time);
    }

}

int main()
{
    int64_t N;
    cin >> N;
    int K;
    cin >> K;

    vector<int> printers(K);
    int max = INT_MIN;
    for (int i = 0; i < K; i++)
    {
        cin >> printers[i];
        if (printers[i] > max)
        {
            max = printers[i];
        }
    }
    uint64_t time = LONG_MAX;
    findMinimalTime(printers, 1, N*max, N, time);
    cout << time;
}
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

bool check(vector<int>& stocks, int s, int K) 
{
    int sum = 0;
    queue<int> temp;
    for (int i = 0; i < s; i++)
    {
        temp.push(stocks[i]);
        sum += stocks[i];
        if (sum >= K)
        {
            return true;
        }
    }

    for (int i = s; i < stocks.size(); i++)
    {
        sum -= temp.front();
        temp.pop();
        sum += stocks[i];
        temp.push(stocks[i]);
        if (sum >= K)
        {
            return true;
        }
    }

    return false;
}

void minDays(vector<int> &stocks, int l, int r, int K, int &res) 
{
    if (l > r)
    {
        return;
    }

    int m = l + (r - l) / 2;

    if (check(stocks, m, K))
    {
        if (m < res)
        {
            res = m;
        }
        minDays(stocks, l, m-1, K, res);
    }
    else
    {
        minDays(stocks, m+1, r, K, res);
    }
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> stocks(N);
    for (int i = 0; i < N; i++)
    {
        cin >> stocks[i];
    }
    int res = INT_MAX;
    minDays(stocks, 1, N, K, res);
    if (res == INT_MAX)
    {
        cout << -1;
        return 0;
    }
    cout << res;
}
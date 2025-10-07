#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int *prices = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> prices[i];
    }

    int profit = 0;
    int buyPrice = INT_MAX;
    for (int i = 0; i < N-1; i++)
    {
        
        if (prices[i] > prices[i+1] && buyPrice != INT_MAX)
        {
            profit += prices[i] - buyPrice;
            buyPrice = INT_MAX;
        }

        if (prices[i] < prices[i + 1] && prices[i] < buyPrice)
        {
            buyPrice = prices[i];
        }
    }
    if (prices[N-1] > buyPrice)
    {
        profit += prices[N - 1] - buyPrice;
    }

    cout << profit;
}
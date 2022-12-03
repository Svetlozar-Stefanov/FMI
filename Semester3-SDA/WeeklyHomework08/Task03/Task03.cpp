#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K, T, B;
    cin >> K >> T >> B;

    int N;
    cin >> N;
    int executed = 0;
    priority_queue<int, vector<int>, greater<int>> pending;
    for (int t = 1; t <= N; t++)
    {
        int q;
        cin >> q;
        pending.push(q);

        if ((t % T == 0 || t == N))
        {
            for (int i = 0; i < K; i++)
            {
                cout << pending.top() << ' ';
                pending.pop();
            }
            executed++;
            if (executed >= B)
            {
                return 0;
            }
        }
    }

    while (executed < B)
    {
        for (int i = 0; i < K; i++)
        {
            cout << pending.top() << ' ';
            pending.pop();
        }
        executed++;
        if (executed >= B)
        {
            return 0;
        }
    }
}
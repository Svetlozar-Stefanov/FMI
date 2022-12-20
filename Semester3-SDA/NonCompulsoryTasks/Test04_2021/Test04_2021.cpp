#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

struct Query
{
    int i;
    int n;
    Query(int i, int n)
    {
        this->i = i;
        this->n = n;
    }
};

bool operator>(Query& q1, Query& q2)
{
    return (q1.n > q2.n) || (q1.n == q2.n && q1.i > q2.i);
}

struct Comp
{
    bool operator()(Query& q1, Query& q2)
    {
        return q1 > q2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int n;
    cin >> n;

    int min = n;
    int max = n;

    int oldT = 0;
    int t = n;

    int c = 1;
    priority_queue<Query, vector<Query>, Comp> q;
    while (c < N || !q.empty())
    {
        for (int i = 0; i < t - oldT && c < N; i++)
        {
            cin >> n;
            q.push(Query(c, n));
            c++;
        }

        Query que = q.top();
        q.pop();
        int r = t - que.i + que.n;
        oldT = t;
        t = t + que.n;
        
        if (r < min)
        {
            min = r;
        }
        if (r > max)
        {
            max = r;
        }
    }

    cout << min << " " << max;
}

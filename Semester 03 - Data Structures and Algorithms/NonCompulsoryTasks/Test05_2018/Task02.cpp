#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

vector<list<int>> graph(300000);
vector<int> paths(300000);
vector<bool> visited(300000);

int minPaths(int s)
{
    visited[s] = true;
    list<int> q;
    q.push_back(s);
    paths[s] = 0;

    int p = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop_front();

        for (auto i = graph[curr].begin(); i != graph[curr].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                paths[*i] = paths[curr] + 1;
                p += paths[*i];
                q.push_back(*i);
            }
        }
    }

    return p;
}

int main() {
    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    cout << minPaths(0);
}
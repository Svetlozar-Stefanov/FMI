#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <list>
#include <set>
#include <algorithm>
using namespace std;

void bfs(int s, vector<list<int>>& graph, int K, set<int>& kthLevel)
{
    vector<bool> visited(graph.size());
    vector<int> depth(graph.size());
    list<int> q;
    q.push_back(s);
    visited[s] = true;
    depth[s] = 0;

    if (depth[s] == K)
    {
        kthLevel.insert(s);
    }
    else if (depth[s] > K)
    {
        return;
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop_front();

        for (auto i = graph[curr].begin(); i != graph[curr].end(); i++)
        {
            if (!visited[*i])
            {
                q.push_back(*i);
                visited[*i] = true;
                depth[*i] = depth[curr] + 1;
                if (depth[*i] == K)
                {
                    kthLevel.insert(*i);
                }
                else if (depth[*i] > K)
                {
                    return;
                }
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    vector<list<int>> graph(V);

    for (int i = 0; i < E; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    set<int> kthLevel;
    bfs(V - 1, graph, K, kthLevel);
    if (kthLevel.empty())
    {
        cout << -1;
        return 0;
    }
    for (auto i = kthLevel.begin(); i != kthLevel.end(); i++)
    {
        cout << (*i) + 1 << " ";
    }
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void bfs(int s, vector<list<int>>& graph, vector<bool>& visited)
{
    list<int> q;
    q.push_back(s);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop_front();

        visited[curr] = true;
        for (auto i = graph[curr].begin(); i != graph[curr].end(); i++)
        {
            if (!visited[*i])
            {
                q.push_back(*i);
            }
        }
    }
}


int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int V, E;
        cin >> V >> E;

        vector<list<int>> graph(V);
        for (int i = 0; i < E; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;

            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        vector<bool> visited(V);
        int subgraphCount = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                subgraphCount++;
                bfs(i, graph, visited);
            }
        }
        cout << subgraphCount << " ";
    }
}

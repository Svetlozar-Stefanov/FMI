#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void getSubgraph(int v, vector<list<int>>& graph, vector<bool>& visited, int& subgraph)
{
    visited[v] = true;
    subgraph++;

    for (auto i = graph[v].begin(); i != graph[v].end(); i++)
    {
        if (!visited[*i])
        {
            getSubgraph(*i, graph, visited, subgraph);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

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

    int subCount = 0;
    vector<bool> visited(V);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            int subgraph = 0;
            getSubgraph(i, graph, visited, subgraph);
            if (subgraph > 1)
            {
                subCount++;
            }
        }
    }
    cout << subCount;
}

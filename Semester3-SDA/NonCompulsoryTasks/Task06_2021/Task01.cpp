#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

void findSubGraphs(int v, vector<list<int>>& graph, vector<bool>& visited, vector<int>& subgraphs, int sI)
{
    visited[v] = true;
    subgraphs[v] = sI;

    for (auto i = graph[v].begin(); i != graph[v].end(); i++)
    {
        if (!visited[*i])
        {
            findSubGraphs(*i, graph, visited, subgraphs, sI);
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
        v1--;
        v2--;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    vector<bool> visited(V);
    vector<int> subgraphs(V);
    int sI = 0;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            sI++;
            findSubGraphs(i, graph, visited, subgraphs, sI);
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;

        cout << (subgraphs[v1] == subgraphs[v2]) << " ";
    }
}
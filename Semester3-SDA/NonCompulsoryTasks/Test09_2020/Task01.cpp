#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <unordered_set>
using namespace std;

bool isValidRoad(int v, vector<unordered_set<int>>& graph, list<int>& path)
{
    if (v < 0 || v >= graph.size())
    {
        return false;
    }
    if (path.empty())
    {
        return true;
    }

    int curr = path.front();
    path.pop_front();
    if (graph[v].find(curr) == graph[v].end())
    {
        return false;
    }

    return isValidRoad(curr, graph, path);
}

int main() {
    int V;
    cin >> V;

    vector<unordered_set<int>> graph(V);
    for (int i = 0; i < V; i++)
    {
        int E;
        cin >> E;
        for (int j = 0; j < E; j++)
        {
            int v;
            cin >> v;
            graph[i].insert(v);
            graph[v].insert(i);
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int L;
        cin >> L;
        list<int> path;
        for (int j = 0; j < L; j++)
        {
            int v;
            cin >> v;
            path.push_back(v);
        }

        int s = path.front();
        path.pop_front();

        cout << isValidRoad(s, graph, path) << " ";
    }
}

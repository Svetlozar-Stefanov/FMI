#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
#include <climits>
using namespace std;

void get_min_dist(int s, vector<list<pair<int, int>>>& graph, vector<uint64_t>& min_dist)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min;

    for (int i = 0; i < graph.size(); i++)
    {
        min_dist[i] = INT_MAX;
    }
    min_dist[s] = 0;
    min.push(pair<int, int>(0, s));

    while (!min.empty())
    {
        int curr = min.top().second;
        min.pop();

        for (auto i = graph[curr].begin(); i != graph[curr].end(); i++)
        {
            if (min_dist[(*i).first] > min_dist[curr] + (*i).second)
            {
                min_dist[(*i).first] = min_dist[curr] + (*i).second;
                min.push(pair<int, int>(min_dist[(*i).first], (*i).first));
            }
        }
    }
}

void dfs(int v, int e,
    vector<list<pair<int, int>>>& graph,
    vector<uint64_t>& min_dist,
    vector<bool>& visited, vector<int>& connected)
{
    if (connected[v] != 0)
    {
        return;
    }
    visited[v] = true;

    for (auto i = graph[v].begin(); i != graph[v].end(); i++)
    {
        if (!visited[(*i).first] && min_dist[v] > min_dist[(*i).first])
        {
            dfs((*i).first, e, graph, min_dist, visited, connected);
            if (connected[(*i).first] != 0)
            {
                (connected[v] += connected[(*i).first]) %= 1000000007;
            }
        }
    }
    visited[v] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, s, e;
    cin >> V >> E >> s >> e;
    vector<list<pair<int, int>>> graph(V);
    for (int i = 0; i < E; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph[v1].push_back(pair<int, int>(v2, w));
        graph[v2].push_back(pair<int, int>(v1, w));
    }

    vector<uint64_t> min_dist(V);
    get_min_dist(e, graph, min_dist);

    vector<bool> visited(V);
    vector<int> connected(V);
    connected[e] = 1;
    dfs(s, e, graph, min_dist, visited, connected);
    cout << connected[s];
}
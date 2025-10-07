#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>

using namespace std;

vector<int> getShortestPaths(int s, int e,
	vector<list<pair<int, int>>>& graph,
	vector<int>& wait)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min;
	vector<int> shortestPaths(graph.size());

	min.push(pair<int, int>(0, s));
	for (int i = 0; i < graph.size(); i++)
	{
		shortestPaths[i] = INT_MAX;
	}
	shortestPaths[s] = 0;

	while (!min.empty())
	{
		int curr = min.top().second;
		int currDist = shortestPaths[curr];
		min.pop();

		for (auto i = graph[curr].begin(); i != graph[curr].end(); i++)
		{
			int v = (*i).first;
			int w = wait[v];
			int dist = (*i).second + currDist;
			if (dist % w != 0 && v != e)
			{
				dist = dist + (w - (dist % w));
			}

			if (dist < shortestPaths[v])
			{
				shortestPaths[v] = dist;
				min.push(pair<int, int>(dist, v));
			}
		}
	}

	return shortestPaths;
}

int main()
{
	int V, E, s, e;
	cin >> V >> E >> s >> e;

	vector<list<pair<int, int>>> graph(V);
	vector<int> wait(V);

	for (int i = 0; i < V; i++)
	{
		cin >> wait[i];
	}

	for (int i = 0; i < E; i++)
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w;

		graph[v1].push_back(pair<int, int>(v2, w));
	}

	vector<int> shortestPaths = getShortestPaths(s, e, graph, wait);

	if (shortestPaths[e] == INT_MAX)
	{
		cout << -1;
		return 0;
	}

	cout << shortestPaths[e];
}

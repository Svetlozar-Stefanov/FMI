#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E, Q;
	cin >> V >> E >> Q;

	vector<vector<int>> graph(V);
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (i == j)
			{
				graph[i].push_back(0);
				continue;
			}
			graph[i].push_back(INT_MAX);
		}
	}

	for (int i = 0; i < E; i++)
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w;

		if (graph[v1][v2] > w)
		{
			graph[v1][v2] = w;
		}
	}

	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if ((graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
					&& (graph[i][j] > (graph[i][k] + graph[k][j])))
				{
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	for (int i = 0; i < Q; i++)
	{
		int s, e;
		cin >> s >> e;

		if (graph[s][e] == INT_MAX)
		{
			cout << -1 << '\n';
			continue;
		}
		cout << graph[s][e] << '\n';
	}
}

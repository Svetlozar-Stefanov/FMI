#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Path
{
    int from;
    int to;
    int work;
    int profit;
    int idx;

    Path()
    {
        this->from = 0;
        this->to = 0;
        this->work = 0;
        this->profit = 0;
        this->idx = 0;
    }

    Path(int from, int to, int work, int profit, int idx)
    {
        this->from = from;
        this->to = to;
        this->work = work;
        this->profit = profit;
        this->idx = idx;
    }
};

bool comparator(Path& p1, Path& p2)
{
    return (p1.work < p2.work) || (p1.work == p2.work && (p1.work * p1.profit) > (p2.work * p2.profit));
}

int findRoot(int node, vector<int>& connected) {
    if (connected[node] == node) {
        return node;
    }

    connected[node] = findRoot(connected[node], connected);
    return connected[node];
}

void getMST(vector<Path> &edges, int N) 
{
    sort(edges.begin(), edges.end(), comparator);
    vector<int> connected(N+1);
    for (int i = 0; i < N+1; i++)
    {
        connected[i] = i;
    }

    for (int i = 0; i < edges.size(); i++)
    {
        Path path = edges[i];
        if (connected[path.from] != connected[path.to])
        {  
            cout << path.idx << '\n';
            for (int i = 0; i < connected.size(); i++)
            {
                if (connected[i] == connected[path.to])
                {
                    connected[i] = connected[path.from];
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<Path> edges(M);
    for (int i = 0; i < M; i++)
    {
        cin >> edges[i].from;
        cin >> edges[i].to;
        cin >> edges[i].work;
        cin >> edges[i].profit;
        edges[i].idx = i + 1;
    }

    getMST(edges, N);
}

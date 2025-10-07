#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Path
{
    int from;
    int to;
    int c;

    Path()
    {
        this->from = 0;
        this->to = 0;
        this->c = 0;
    }

    Path(int from, int to, int c)
    {
        this->from = from;
        this->to = to;
        this->c = c;
    }
};

bool comparator(Path& p1, Path& p2)
{
    return p1.c < p2.c;
}

int findRoot(int node, vector<int>& connected)
{
    if (connected[node] == node)
    {
        return node;
    }

    connected[node] = findRoot(connected[node], connected);
    return connected[node];
}

void getMinST(vector<Path>& paths, int N, vector<Path>& minST)
{
    vector<int> connected(N + 1);
    for (int i = 0; i < N + 1; i++)
    {
        connected[i] = i;
    }

    for (int i = 0; i < paths.size(); i++)
    {
        int fromRoot = findRoot(paths[i].from, connected);
        int toRoot = findRoot(paths[i].to, connected);

        if (fromRoot != toRoot)
        {
            minST.push_back(paths[i]);
            connected[fromRoot] = toRoot;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<Path> paths(M);
    for (int i = 0; i < M; i++)
    {
        cin >> paths[i].from;
        cin >> paths[i].to;
        cin >> paths[i].c;
    }

    int min = 0;
    int max = 50000;

    sort(paths.begin(), paths.end(), comparator);
    while (paths.size() >= N - 1)
    {
        vector<Path> minST;
        getMinST(paths, N, minST);

        int tMin = minST[0].c;
        int tMax = minST[minST.size() - 1].c;

        paths.erase(paths.begin());
        if (minST.size() != N-1)
        {
            continue;
        }

        if (max - min > tMax - tMin)
        {
            min = tMin;
            max = tMax;
        }
    }
    cout << min << " " << max;
}

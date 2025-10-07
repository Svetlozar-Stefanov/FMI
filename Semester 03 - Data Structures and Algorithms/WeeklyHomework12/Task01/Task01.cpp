#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void connectCities(int c1, int c2, vector<unordered_set<int>>& subgraphs)
{
    int s1 = -1;
    int s2 = -1;
    for (int i = 0; i != subgraphs.size(); i++)
    {
        if (subgraphs[i].find(c1) != subgraphs[i].end())
        {
            s1 = i;
        }

        if (subgraphs[i].find(c2) != subgraphs[i].end())
        {
            s2 = i;
        }
    }

    if (s1 != s2)
    {
        for (auto i = subgraphs[s2].begin(); i != subgraphs[s2].end(); i++)
        {
            subgraphs[s1].insert((*i));
        }
        subgraphs.erase(subgraphs.begin() + s2);;
    }
}

bool citiesConnected(int c1, int c2, vector<unordered_set<int>>& subgraphs)
{
    for (int i = 0; i < subgraphs.size(); i++)
    {
        if (subgraphs[i].find(c1) != subgraphs[i].end()
            && subgraphs[i].find(c2) != subgraphs[i].end())
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<unordered_set<int>> subgraphs(N);
    for (int i = 0; i < N; i++)
    {
        unordered_set<int> temp;
        temp.insert(i + 1);
        subgraphs[i] = temp;
    }

    for (int i = 0; i < M; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        connectCities(v1, v2, subgraphs);
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int c, v1, v2;
        cin >> c >> v1 >> v2;

        if (c == 1)
        {
            cout << citiesConnected(v1, v2, subgraphs);
        }
        else if (c == 2)
        {
            connectCities(v1, v2, subgraphs);
        }
    }
}
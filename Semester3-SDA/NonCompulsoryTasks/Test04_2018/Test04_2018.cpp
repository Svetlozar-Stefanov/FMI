#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> dist;
map<int, vector<int>> paths;

void helper(int root, int l)
{
    for (uint64_t i = 0; i < paths[root].size(); i++)
    {
        if (dist[paths[root][i]] == 0)
        {
            dist[paths[root][i]] = l;
        }
        else if (dist[paths[root][i]] != 0 && dist[paths[root][i]] > l)
        {
            dist[paths[root][i]] = l;
        }
        helper(paths[root][i], l + 1);
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int l, r;
        cin >> l >> r;
        paths[l].push_back(r);
    }

    helper(0, 1);

    int sum = 0;
    for (auto i = dist.begin(); i != dist.end(); i++)
    {
        sum += i->second;
    }
    cout << sum;
}
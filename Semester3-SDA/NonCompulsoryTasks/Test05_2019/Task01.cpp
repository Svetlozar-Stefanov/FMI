#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<string, int> tolls;
    for (int i = 0; i < N; i++)
    {
        string s;
        int p;
        cin >> s >> p;

        tolls[s] = p;
    }

    uint64_t price = 0;
    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;
        price += tolls[s];
    }
    cout << price;
}

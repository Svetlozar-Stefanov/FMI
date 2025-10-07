#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, int> counter;

    int N;
    cin >> N;
    vector<string> input(N);

    for (int i = 0; i < N; i++)
    {
        cin >> input[i];

        counter[input[i]]++;
    }

    for (int i = 0; i < input.size(); i++)
    {
        cout << counter[input[i]] << " ";
    }
}

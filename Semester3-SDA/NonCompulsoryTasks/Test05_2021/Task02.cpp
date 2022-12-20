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

    unordered_map<int, int> counter;

    int N;
    cin >> N;
    vector<int> input(N);

    for (int i = 0; i < N; i++)
    {
        cin >> input[i];

        counter[input[i]]++;
    }

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (counter[input[i]] % 2 != 0)
        {
            sum += input[i];
        }
    }

    cout << sum;
}

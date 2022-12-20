#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    int N;
    cin >> N;

    int l = 0;
    unordered_map<int, int> orders;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        orders[n]++;
        l++;
        if (orders[n] >= 10)
        {
            orders.erase(n);
            l -= 10;
        }
    }

    cout << orders.size() << " " << l;
}
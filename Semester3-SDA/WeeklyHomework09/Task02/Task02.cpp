#include <iostream>
#include <unordered_set>
#include <queue>
#include <climits>

using namespace std;

int main()
{
    unordered_set<int> container;
    queue<int> subset;

    int max = INT_MIN;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        if (container.find(n) == container.end())
        {
            subset.push(n);
            container.insert(n);
        }
        else
        {
            while (subset.front() != n)
            {
                container.erase(subset.front());
                subset.pop();
            }
            
            subset.pop();
            subset.push(n);
        }

        int size = subset.size();
        if (size > max)
        {
            max = size;
        }
    }

    cout << max;
}
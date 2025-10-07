#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Range
{
    int low;
    int high;
};

int leftHelper(vector<int>& W, Range& range, int l, int r) {
    if (l > r)
        return l;

    int m = l + (r - l) / 2;
    if (range.low <= W[m])
    {
        return leftHelper(W, range, l, m - 1);
    }
    return leftHelper(W, range, m + 1, r);
}

int rightHelper(vector<int>& W, Range& range, int l, int r) {
    if (l > r)
        return l;

    int m = l + (r - l) / 2;
    if (range.high >= W[m])
    {
        return rightHelper(W, range, m + 1, r);
    }
    return rightHelper(W, range, l, m - 1);
}

int participantsCount(vector<int>& W, Range& range) {
    int sIdx = leftHelper(W, range, 0, W.size() - 1);
    int eIdx = rightHelper(W, range, 0, W.size() - 1);
    
    if (sIdx < 0)
    {
        sIdx++;
    }
    if (eIdx <= W.size())
    {
        eIdx--;
    }

    //cout << sIdx << " " << eIdx << "\n";

    return (eIdx - sIdx) + 1  /*(W[sIdx] < range.low) - (W[eIdx] > range.high)*/;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N;
    cin >> Q;

    vector<int> W(N);
    for (int i = 0; i < N; i++)
    {
        cin >> W[i];
    }

    sort(W.begin(), W.end());

    for (int i = 0; i < Q; i++)
    {
        Range r;
        cin >> r.low;
        cin >> r.high;
        if (r.low > r.high)
        {
            cout << 0 << "\n";
            continue;
        }

        cout << participantsCount(W, r) << '\n';
    }
}
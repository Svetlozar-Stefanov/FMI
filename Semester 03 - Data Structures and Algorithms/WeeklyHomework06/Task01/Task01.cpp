#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int val;
    int x;
    int y;

    int l;
    int r;
    Node()
    {
        val = 0;
        x = 0;
        y = 0;
        l = -1;
        r = -1;
    }

    Node(int val, int l, int r)
    {
        this->val = val;
        this->l = l;
        this->r = r;
    }
};

void findPaths(vector<int64_t>& nSum, vector<int64_t> &pSum, vector<Node> &tree, int curr)
{
    Node current = tree[curr];
    if (curr == 0)
    {
        current.x = 0;
        current.y = 0;
    }

    if (current.x >= 0)
    {
        pSum[current.x] += current.val;
    }
    else
    {
        nSum[abs(current.x)] += current.val;
    }

    if (current.l != -1)
    {
        tree[current.l].x = current.x - 1;
        tree[current.l].y = current.y + 1;
        findPaths(nSum, pSum, tree, current.l);
    }

    if (current.r != -1)
    {
        tree[current.r].x = current.x + 1;
        tree[current.r].y = current.y + 1;
        findPaths(nSum, pSum, tree, current.r);
    }
}

int main()
{
    int N;
    cin >> N;

    vector<Node> tree(N);

    for (int i = 0; i < N; i++)
    {
        int A, l, r;
        cin >> A >> l >> r;

        tree[i].val = A;
        tree[i].l = l;
        tree[i].r = r;
    }

    vector<int64_t> nSum(N);
    vector<int64_t> pSum(N);
    findPaths(nSum, pSum, tree, 0);

    for (int i = nSum.size() - 1; i >= 0; i--)
    {
        if (nSum[i] != 0)
        {
            cout << nSum[i] << " ";
        }
    }

    for (int i = 0; i < pSum.size(); i++)
    {
        if (pSum[i] != 0)
        {
            cout << pSum[i] << " ";
        }
    }
}
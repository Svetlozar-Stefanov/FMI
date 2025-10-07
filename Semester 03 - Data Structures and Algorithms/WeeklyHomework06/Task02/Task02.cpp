#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int val;
    int l;
    int r;
    Node()
    {
        val = 0;
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

bool helper(vector<int> &el, vector<Node>& tree, int nIdx)
{
    if (nIdx == -1)
    {
        return true;
    }

    Node curr = tree[nIdx];
    if (curr.l != -1 && tree[curr.l].val >= curr.val)
    {
        return false;
    }
    else if (curr.r != -1 && tree[curr.r].val <= curr.val)
    {
        return false;
    }

    bool temp = helper(el, tree, curr.l);
    el.push_back(curr.val);
    return temp && helper(el, tree, curr.r);
}

bool isBST(vector<Node> &tree) 
{
    vector<int> el;
    if (!helper(el, tree, 0))
    {
        return false;
    }
    else if(tree.size() > 0)
    {
        for (int i = 0; i < el.size()-1; i++)
        {
            if (el[i] >= el[i+1])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int T;
    cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
        vector<Node> tree(N);

		for (int i = 0; i < N; i++)
		{
            cin>> tree[i].val >> tree[i].l >> tree[i].r;
		}

        cout << isBST(tree) << '\n';
	}
}

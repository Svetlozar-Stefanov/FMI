#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int lVal;
	int rVal;
	int l;
	int m;
	int r;

	Node() {
		lVal = -1;
		rVal = -1;
		l = -1;
		m = -1;
		r = -1;
	}
};

bool operator==(Node &n1, Node& n2)
{
	return n1.lVal == n2.lVal && n1.rVal && n2.rVal;
}

void setVal(vector<Node>& tree, int i, int& min)
{
	if (tree[i].l != -1)
	{
		setVal(tree, tree[i].l, min);
	}
	if (tree[i].lVal == -1)
	{
		tree[i].lVal = min;
		min++;
	}

	if (tree[i].m != -1)
	{
		setVal(tree, tree[i].m, min);
		if (tree[i].rVal == -1)
		{
			tree[i].rVal = min;
			min++;
		}
	}
	if (tree[i].r != -1)
	{
		setVal(tree, tree[i].r, min);
	}
}

void print(vector<Node>& tree, int i)
{
	if (tree[i].l != -1)
	{
		print(tree, tree[i].l);
	}
	cout << tree[i].lVal << " ";
	if (tree[i].m != -1)
	{
		print(tree, tree[i].m);
		cout << tree[i].rVal << " ";
	}
	if (tree[i].r != -1)
	{
		print(tree, tree[i].r);
	}
}

bool isChild(vector<Node>& tree, int i, Node x)
{
    Node curr = tree[i];
    if (curr == x)
    {
        return true;
    }

    if (max(curr.rVal, curr.lVal) < x.lVal && curr.r != -1)
    {
        return isChild(tree, curr.r, x);
    }
    else if (curr.lVal < x.lVal && x.rVal < curr.rVal && curr.m != -1)
    {
        return isChild(tree, curr.m, x);
    }
	else if (curr.lVal > max(x.lVal, x.rVal) && curr.l != -1)
	{
		return isChild(tree, curr.l, x);
	}

    return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<Node> tree(N);
	for (int i = 0; i < N - 1; i++)
	{
		int p, c;
		cin >> p >> c;

		if (tree[p].l == -1)
		{
			tree[p].l = c;
		}
		else if (tree[p].r == -1)
		{
			tree[p].r = c;
		}
		else if (tree[p].m == -1)
		{
			tree[p].m = c;
		}
	}

	int min = 0;
	setVal(tree, 0, min);

	print(tree, 0);

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int p, c;
		cin >> p >> c;
		if (isChild(tree, p, tree[c]))
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
	string val;

	Node* l;
	Node* r;

	Node(string val)
	{
		this->val = val;
		l = nullptr;
		r = nullptr;
	}
};

class BSTree {
	Node* root;

	Node* insert(Node* node, string val)
	{
		if (node == nullptr)
		{
			return new Node(val);
		}

		if (val < node->val)
		{
			node->l = insert(node->l, val);
		}
		else if (val > node->val)
		{
			node->r = insert(node->r, val);
		}

		return node;
	}

	bool contains(Node* node, string val)
	{
		if (node == nullptr)
		{
			return false;
		}
		if (node->val == val)
		{
			return true;
		}

		if (val > node->val)
		{
			return contains(node->r, val);
		}
		return contains(node->l, val);
	}

public:
	BSTree()
	{
		root = nullptr;
	}

	void insert(string val)
	{
		if (root == nullptr)
		{
			root = new Node(val);
			return;
		}

		root = insert(root, val);
	}

	bool contains(string val)
	{
		return contains(root, val);
	}
};

int main()
{
	int N;
	cin >> N;
	BSTree tree;
	for (int i = 0; i < N; i++)
	{
		string val;
		cin >> val;
		tree.insert(val);
	}

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		string s;
		cin >> s;
		if (tree.contains(s))
		{
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	}
}
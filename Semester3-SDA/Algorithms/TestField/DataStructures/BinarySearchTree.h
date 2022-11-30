#pragma once
#include <iostream>

struct Node
{
	int val;
	Node* left;
	Node* right;

	Node(int val) {
		this->val = val;
		left = nullptr;
		right = nullptr;
	}
};

class BSTree
{
	Node* root;

	Node* insertHelper(Node* node, int x)
	{
		if (node == nullptr)
		{
			return new Node(x);
		}

		if (node->val > x)
		{
			node->left = insertHelper(node->left, x);
		}
		else if (node->val < x)
		{
			node->right = insertHelper(node->right, x);
		}

		return node;
	}

	bool dfsHelper(Node* node, int x) 
	{
		if (node == nullptr)
		{
			return false;
		}

		if (node->val == x)
		{
			return true;
		}

		if (node->val > x)
		{
			return dfsHelper(node->left, x);
		}
		return dfsHelper(node->right, x);
	}

	int height(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}

		int l = height(node->left) + 1;
		int r = height(node->right) + 1;

		return max(l, r);
	}

	int min(Node* node)
	{
		if (node->left == nullptr)
		{
			return node->val;
		}
		return min(node->left);
	}

	bool searchLayer(Node* node, int layer, int x) 
	{
		if (node == nullptr)
		{
			return false;
		}

		if (layer == 0 && node->val == x)
		{
			return true;
		}
		else if (layer > 0)
		{
			return searchLayer(node->left, layer - 1, x) || searchLayer(node->right, layer - 1, x);
		}

		return false;
	}

	Node* removeHelper(Node* node, int x)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		if (node->val > x)
		{
			node->left = removeHelper(node->left, x);
		}
		else if (node->val < x)
		{
			node->right = removeHelper(node->right, x);
		}
		else
		{
			if (node->left == nullptr && node->right == nullptr)
			{
				delete node;
				return nullptr;
			}
			else if (node->left != nullptr && node->right == nullptr)
			{
				Node* temp = node->left;
				delete node;
				node = temp;
			}
			else if (node->left == nullptr && node->right != nullptr)
			{
				Node* temp = node->right;
				delete node;
				node = temp;
			}
			else
			{
				int temp = min(node->right);
				node->val = temp;
				node->right = removeHelper(node->right, temp);
			}
		}

		return node;
	}

	void rlt_print_helper(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}

		cout << node->val << " ";
		rlt_print_helper(node->left);
		rlt_print_helper(node->right);
	}

	void lrt_print_helper(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}

		lrt_print_helper(node->left);
		cout << node->val << " ";
		lrt_print_helper(node->right);
	}

public:
	BSTree() {
		root = nullptr;
	}

	void insert(int x)
	{
		root = insertHelper(root, x);
	}

	bool depth_first_search(int x)
	{
		return dfsHelper(root, x);
	}

	bool bredth_first_search(int x) 
	{
		int h = height(root);
		bool contains = false;
		for (int l = 0; l < h; l++)
		{
			contains = searchLayer(root, l, x);
			if (contains)
			{
				return contains;
			}
		}

		return contains;
	}

	void remove(int x) {
		root = removeHelper(root, x);
	}

	void rlt_print() {
		rlt_print_helper(root);
		cout << '\n';
	}

	void lrt_print() {
		lrt_print_helper(root);
		cout << '\n';
	}
};
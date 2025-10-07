#pragma once

struct Node
{
	int val;
	unsigned char height;
	Node* left;
	Node* right;

	Node(int val) {
		this->val = val;
		left = nullptr;
		right = nullptr;
		height = 1;
	}
};

class AVLTree
{
	Node* root;

	unsigned char height(Node* node)
	{
		return node == nullptr ? 0 : node->height;
	}

	int balanceFactor(Node * node)
	{
		return height(node->right) - height(node->left);
	}

	int setHeight(Node * node)
	{
		unsigned char lH = height(node->left);
		unsigned char rH = height(node->right);

		return (lH > rH ? lH : rH) + 1;
	}

	Node* rightRotate(Node* node)
	{
		Node* leftSubTree = node->left;
		node->left = leftSubTree->right;
		leftSubTree->right = node;
		setHeight(node);
		setHeight(leftSubTree);
		return leftSubTree;
	}

	Node* leftRotate(Node* node)
	{
		Node* rightSubtree = node->right;
		node->right = rightSubtree->left;
		rightSubtree->left = node;
		setHeight(node);
		setHeight(rightSubtree);
		return rightSubtree;
	}

	Node* balance(Node* node)
	{
		setHeight(node);
		if (balanceFactor(node) == 2)
		{
			if (balanceFactor(node->right) < 0)
			{
				node->right = rightRotate(node->right);
			}
			return leftRotate(node);
		}
		if (balanceFactor(node) == -2)
		{
			if (balanceFactor(node->left) > 0)
			{
				node->left = leftRotate(node->left);
			}
			return rightRotate(node);
		}

		return node;
	}

	Node* insert(Node* node, int n)
	{
		if (node == nullptr)
		{
			return new Node(n);
		}

		if (node->val < n)
		{
			node->right = insert(node->right, n);
		}
		else if (node->val > n)
		{
			node->left = insert(node->left, n);
		}

		return balance(node);
	}

	Node* min(Node* node)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		if (node->left == nullptr)
		{
			return node;
		}
		min(node->left);
	}

	Node* remove(Node* node, int n)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		if (node->val < n)
		{
			node->right = remove(node->right, n);
		}
		else if (node->val > n)
		{
			node->left = remove(node->left, n);
		}
		else
		{
			if (node->right == nullptr)
			{
				Node* temp = node->left;
				delete node;
				return temp;
			}
			else if (node->left == nullptr && node->right == nullptr)
			{
				delete node;
				return nullptr;
			}
			else
			{
				Node* temp = min(node->right);
				node->val = temp->val;

				node->right = remove(node->right, temp->val);
			}
		}

		return balance(node);
	}

public:
	AVLTree()
	{
		root = nullptr;
	}

	void insert(int n)
	{
		root = insert(root, n);
	}

	void remove(int n)
	{
		root = remove(root, n);
	}
};
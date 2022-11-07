#pragma once
#include <iostream>

struct Node
{
	int key;
	Node* left;
	Node* right;

	Node(int key) {
		this->key = key;
		left = nullptr;
		right = nullptr;
	}
};

class BinarySearchTree {
private:
	Node* root;

	Node* insert(Node* node, int newKey) {
		if (node == nullptr)
		{
			return new Node(newKey);
		}

		if (newKey > node->key)
		{
			node->right = insert(node->right, newKey);
		}
		else if (newKey < node->key) {
			node->left = insert(node->left, newKey);
		}

		return node;
	}

	void inorder(Node* current) {
		if (current == nullptr)
		{
			return;
		}

		inorder(current->left);
		std::cout << current->key << "\n";
		inorder(current->right);
	}

	Node* minVal(Node* current) 
	{
		if(current->left != nullptr)
		{
			minVal(current->left);
		}

		return current;
	}

	Node* remove(Node* current, int key)
	{
		if (current == nullptr)
		{
			return current;
		}

		if (current->key != key)
		{
			if (current->key > key)
			{
				current->left = remove(current->left, key);
			}
			else if (current->key < key)
			{
				current->right = remove(current->right, key);
			}
			return current;
		}

		Node* toDel = current;
		if (current->left != nullptr && current->right == nullptr)
		{
			current = current->left;
			delete toDel;
		}
		else if (current->left == nullptr && current->right != nullptr)
		{
			current = current->right;
			delete toDel;
		}
		else if (current->left != nullptr && current->right != nullptr)
		{
			Node* succ = minVal(current->right);
			current->key = succ->key;

			current->right = remove(current->right, succ->key);
		}
		else
		{
			delete toDel;
			return nullptr;
		}
		return current;
	}

public:
	BinarySearchTree() {
		root = nullptr;
	}

	void insert(int newKey) {
		root = insert(root, newKey);
	}

	void inorderPrint() {
		inorder(root);
	}

	void remove(int key)
	{
		remove(root, key);
	}
};
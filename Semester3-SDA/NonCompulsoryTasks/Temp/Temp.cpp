#include <iostream>
#include <vector>
#include <climits>

struct Tuple {
	long value, first, second;

	Tuple(long val, long x, long y) : value{ val }, first{ x }, second{ y }{}
};

struct Node {
	Tuple value;
	Node* left, * right;

	Node(Tuple value, Node* left = nullptr, Node* right = nullptr) : value{ value } {
		this->left = left;
		this->right = right;
	};
};

std::vector<Tuple> nodes;

void fill_tree(Node* current) {
	if (current != nullptr) {
		current->value.first != -1 ? current->left = new Node(nodes[current->value.first]) : current->left = nullptr;
		current->value.second != -1 ? current->right = new Node(nodes[current->value.second]) : current->right = nullptr;

		fill_tree(current->left);
		fill_tree(current->right);
	}
}

bool is_BST(Node* current, long min, long max) {
	if (current == nullptr)
		return true;

	if (current->value.value <= min || current->value.value >= max)
		return false;

	return is_BST(current->left, min, current->value.value) && is_BST(current->right, current->value.value, max);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	size_t N = 0, T = 0, left_i = 0, right_i = 0;
	long val = 0;

	std::cin >> T;

	Node* christmas_trees[10];
	for (size_t i = 0; i < 10; i++)
		christmas_trees[i] = nullptr;

	for (size_t i = 0; i < T; i++) {
		std::cin >> N;
		for (size_t j = 0; j < N - 1; j++) {
			/*std::cin >> val >> left_i >> right_i;
			nodes.push_back(Tuple(val, left_i, right_i));*/
			nodes.push_back(Tuple(1, j + 1, -1));
		}
		nodes.push_back(Tuple(1, -1, -1));
		christmas_trees[i] = new Node(nodes[0]);
		fill_tree(christmas_trees[i]);
		nodes.clear();
	}

	for (size_t i = 0; i < 10; i++)
		if (christmas_trees[i] != nullptr)
			std::cout << is_BST(christmas_trees[i], LONG_MIN, LONG_MAX) << "\n";

	return 0;
}
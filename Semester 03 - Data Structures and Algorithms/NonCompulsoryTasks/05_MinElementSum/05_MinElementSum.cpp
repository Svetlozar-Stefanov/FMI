#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Node
{
	int val;
	Node* next;
	Node(int val) {
		this->val = val;
		this->next = nullptr;
	}
};

int main()
{
	int N, L;
	cin >> N >> L;
	if (L == 0)
	{
		cout << 0;
		return 0;
	}
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	class Queue {
		Node* head;
		Node* tail;

	public:
		Queue()
		{
			head = nullptr;
			tail = nullptr;
		}

		void push(int n) {
			if (head == tail && head == nullptr)
			{
				head = new Node(n);
				tail = head;
				return;
			}

			tail->next = new Node(n);
			tail = tail->next;
		}

		void pop() {
			if (head != nullptr)
			{
				Node* temp = head;
				head = head->next;
				delete temp;
			}
		}

		int front() {
			return head->val;
		}

		int get_min() {
			int min = INT_MAX;
			Node* iter = head;
			while (iter != nullptr)
			{
				if (iter->val < min)
				{
					min = iter->val;
				}
				iter = iter->next;
			}

			return min;
		}

	} subarr;

	int min = INT_MAX;
	for (int i = 0; i < L; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
		subarr.push(arr[i]);
	}
	int64_t sum = min;
	for (int i = L; i < N; i++)
	{
		int newEl = arr[i];
		int top = subarr.front();
		subarr.pop();
		if (top <= min)
		{
			min = subarr.get_min();
		}
		subarr.push(newEl);
		if (newEl < min)
		{
			min = newEl;
		}

		sum += min;
	}

	cout << sum;
}

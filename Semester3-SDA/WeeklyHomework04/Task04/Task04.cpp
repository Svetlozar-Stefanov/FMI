#include <iostream>

using namespace std;

struct Package
{
	int id;
	Package* next = nullptr;

	Package(int data) {
		id = data;
	}
};

int counter[1000001] = { 0 };

class PackageManager
{
	Package* head = nullptr;
	Package* tail = nullptr;

	int actualSize;
	int size;
	int max_size;
	int* counter;

	void pop_first() {
		while (head != nullptr && counter[head->id] > 1 && actualSize > max_size)
		{
			Package* temp = head->next;
			counter[head->id]--;
			actualSize--;
			delete head;
			head = temp;
		}
		if (head != nullptr)
		{
			Package* temp = head->next;
			counter[head->id]--;
			delete head;
			head = temp;
			size--;
			actualSize--;
			if (head == nullptr)
			{
				tail = head;
			}
		}
	}

public:

	PackageManager(int max_size, int * counter) {
		actualSize=0;
		size = 0;
		this->max_size = max_size;
		this->counter = counter;
	}

	bool search_and_use(int id)
	{
		if (counter[id] > 0)
		{
			tail->next = new Package(id);
			tail = tail->next;
			counter[id]++;
			actualSize++;

			return true;
		}
		return false;
	}

	void install_package(int id)
	{
		if (size >= max_size)
		{
			pop_first();
		}

		if (head == nullptr && tail == nullptr)
		{
			head = new Package(id);
			tail = head;
			counter[id]++;
			size++;
			actualSize++;
			return;
		}

		tail->next = new Package(id);
		tail = tail->next;
		counter[id]++;
		size++;
		actualSize++;
	}

	void print() {
		Package* iterator = head;
		while (iterator != nullptr)
		{
			cout << iterator->id << " ";
			iterator = iterator->next;
		}
		cout << '\n';
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, T;
	cin >> T >> N;

	PackageManager manager(N, counter);
	for (int i = 0; i < T; i++)
	{
		int M;
		cin >> M;
		if (manager.search_and_use(M))
		{
			printf("true\n");
			manager.print();
			continue;
		}

		printf("false\n");
		manager.install_package(M);

		manager.print();
	}
}
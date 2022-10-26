#include <iostream>
using namespace std;

int counter[50001] = { 0 };

struct Ball
{
	int color;
	int index;
	Ball* previous;
	Ball* next;

	Ball(int color, int index) {
		this->color = color;
		this->index = index;
		previous = nullptr;
		next = nullptr;
	}

	Ball(int color, int index, Ball* p, Ball* n) {
		this->color = color;
		this->index = index;
		previous = p;
		next = n;
	}
};

class ZumaLine
{
public:
	ZumaLine(int* counter) {
		head = nullptr;
		tail = nullptr;
		this->counter = counter;
	}

private:
	int* counter;
	Ball* head;
	Ball* tail;

	int getSmallestIndex() {
		for (int i = 0; i < 50001; i++)
		{
			if (counter[i] <= 0)
			{
				counter[i]++;
				return i;
			}
		}

		return -1;
	}

public:
	bool isEmpty() {
		return (tail == head && head == nullptr);
	}

	void push_back(int color, int index) {
		counter[index]++;
		if (head == tail && head == nullptr)
		{
			tail = new Ball(color, index);
			head = tail;
			return;
		}

		tail->next = new Ball(color, index, tail, nullptr);
		tail = tail->next;
	}

	int calcPoints(Ball* ball) {
		int count = 1;

		int col = ball->color;
		Ball* leftIter = ball->previous;
		while (leftIter != nullptr && leftIter->color == col)
		{
			count++;
			leftIter = leftIter->previous;
		}

		Ball* rightIter = ball->next;
		while (rightIter != nullptr && rightIter->color == col)
		{
			count++;
			rightIter = rightIter->next;
		}
		if (count < 3)
		{
			return 0;
		}

		Ball* iter = leftIter;
		if (iter == nullptr)
		{
			iter = head;
		}
		else
		{
			iter = iter->next;
		}

		while (iter != rightIter)
		{
			counter[iter->index]--;
			iter = iter->next;
		}

		if (leftIter == rightIter && rightIter == nullptr)
		{
			head = nullptr;
			tail = nullptr;
		}
		else if (leftIter == nullptr && rightIter != nullptr)
		{
			head = rightIter;
			head->previous = nullptr;
		}
		else if (leftIter != nullptr && rightIter == nullptr)
		{
			tail = leftIter;
			tail->next = nullptr;
		}
		else
		{
			leftIter->next = rightIter;
			rightIter->previous = leftIter;
			if (leftIter->color == rightIter->color)
			{
				return count + calcPoints(rightIter);
			}
		}

		return count;
	}

	void shootAtBall(int pos, int col)
	{
		if (isEmpty())
		{
			printf("Game Over\n");
			return;
		}

		Ball* shot = new Ball(col, getSmallestIndex());
		/*if (pos == 0)
		{
			shot->next = head;
			head = shot;
			return;
		}*/

		Ball* prev = nullptr;
		Ball* curr = head;
		while (curr != nullptr && curr->index != pos)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr != nullptr)
		{
			prev = curr;
			curr = curr->next;
		}

		if (prev != nullptr)
		{
			prev->next = shot;
		}
		shot->previous = prev;
		shot->next = curr;
		if (curr != nullptr)
		{
			curr->previous = shot;
		}
		if (shot->next == nullptr)
		{
			tail = shot;
		}

		int points = calcPoints(shot);
		printf("%d\n", points);
	}

	void print() {
		Ball* iter = head;
		while (iter != nullptr)
		{
			printf("%d ", iter->color);
			//cout << iter->color << /*'-' << iter->index <<*/ ' ';
			iter = iter->next;
		}
		printf("\n");
	}
};

ZumaLine line(counter);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		line.push_back(n, i);
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int pos, col;
		cin >> pos >> col;

		line.shootAtBall(pos, col);
		//line.print();
	}
	if (!line.isEmpty())
	{
		line.print();
	}
	else
	{
		printf("%d", -1);
	}
}

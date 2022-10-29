#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_BALL_NUMBER = 200001;

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
	ZumaLine(int size) {
		unusedIndices.push_back(size);
		head = nullptr;
		tail = nullptr;
	}

private:
	vector<int> unusedIndices;
	Ball* ballIndices[MAX_BALL_NUMBER] = { nullptr };
	Ball* head;
	Ball* tail;

	int getSmallestIndex() {
		int index = 0;
		index = unusedIndices[0];
		unusedIndices.pop_back();
		if (unusedIndices.size() == 0)
		{
			unusedIndices.push_back(index + 1);
		}

		return index;
	}

public:
	bool isEmpty() {
		return (tail == head && head == nullptr);
	}

	void push_back(int color, int index) {
		if (head == tail && head == nullptr)
		{
			tail = new Ball(color, index);
			head = tail;
			ballIndices[index] = tail;
			return;
		}

		tail->next = new Ball(color, index, tail, nullptr);
		ballIndices[index] = tail->next;
		tail = tail->next;
	}

	int calcPoints(Ball* ball) {
		Ball* toBringBack[3];
		int count = 1;
		int i = 0;
		toBringBack[i++] = ball;
		ballIndices[ball->index] = nullptr;
		unusedIndices.push_back(ball->index);

		int col = ball->color;
		Ball* leftIter = ball->previous;
		while (leftIter != nullptr && leftIter->color == col)
		{
			count++;
			if (i < 3)
			{
				toBringBack[i++] = leftIter;
			}
			ballIndices[leftIter->index] = nullptr;
			unusedIndices.push_back(leftIter->index);
			leftIter = leftIter->previous;
		}

		Ball* rightIter = ball->next;
		while (rightIter != nullptr && rightIter->color == col)
		{
			count++;
			if (i < 3)
			{
				toBringBack[i++] = rightIter;
			}
			ballIndices[rightIter->index] = nullptr;
			unusedIndices.push_back(rightIter->index);
			rightIter = rightIter->next;
		}

		if (count < 3)
		{
			for (int j = 0; j < i; j++)
			{
				unusedIndices.pop_back();
				Ball* ball = toBringBack[j];
				ballIndices[ball->index] = ball;
			}
			return 0;
		}
		sort(unusedIndices.rbegin(), unusedIndices.rend());

		Ball* iter = leftIter;
		if (iter == nullptr)
		{
			iter = head;
		}
		else
		{
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

		int index = getSmallestIndex();
		Ball* shot = new Ball(col, index);
		ballIndices[index] = shot;

		Ball* prev = ballIndices[pos];
		Ball* curr = prev->next;

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
			iter = iter->next;
		}
		printf("\n");
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	ZumaLine line(N);

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

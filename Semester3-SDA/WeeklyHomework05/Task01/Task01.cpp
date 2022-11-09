#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

struct RottenApple
{
	int x;
	int y;

	RottenApple(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

void print(vector<vector<bool>>& storage, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << storage[i][j] << " ";
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, T;
	cin >> N >> M >> T;

	vector<vector<bool>> storage(N);
	for (int i = 0; i < N; i++)
	{
		storage[i] = vector<bool>(M);
	}

	queue<RottenApple> rotten;

	int count = 1;
	int x, y;
	cin >> x >> y;
	rotten.push(RottenApple(x-1, y-1));
	storage[x-1][y-1] = 1;

    while (cin >> x)
	{
		cin >> y;
		rotten.push(RottenApple(x - 1, y - 1));
		storage[x - 1][y - 1] = 1;
		count++;
		break;
	}

	for (int i = 0; i < T; i++)
	{
		int currentSize = rotten.size();
		for (int j = 0; j < currentSize; j++)
		{
			RottenApple curr = rotten.front();

			if (curr.x + 1 < N && storage[curr.x + 1][curr.y] != 1)
			{
				storage[curr.x + 1][curr.y] = 1;
				rotten.push(RottenApple(curr.x + 1, curr.y));
				count++;
			}
			if (curr.x - 1 >= 0 && storage[curr.x - 1][curr.y] != 1)
			{
				storage[curr.x - 1][curr.y] = 1;
				rotten.push(RottenApple(curr.x - 1, curr.y));
				count++;
			}
			if (curr.y + 1 < M && storage[curr.x][curr.y + 1] != 1)
			{
				storage[curr.x][curr.y + 1] = 1;
				rotten.push(RottenApple(curr.x, curr.y + 1));
				count++;
			}
			if (curr.y - 1 >= 0 && storage[curr.x][curr.y - 1] != 1)
			{
				storage[curr.x][curr.y - 1] = 1;
				rotten.push(RottenApple(curr.x, curr.y - 1));
				count++;
			}

			rotten.pop();
		}
	}

	cout << N * M - count;
}
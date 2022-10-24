#include <iostream>
#include <vector>

using namespace std;

struct Demon {
	int64_t attack;
	int64_t deffence;
};

void findMaxDemonsSlain(vector<Demon> demons, int l, int r, int &depth) {

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<Demon> demons(N);
	for (int i = 0; i < N; i++)
	{
		cin >> demons[i].attack;
		cin >> demons[i].deffence;
	}
}
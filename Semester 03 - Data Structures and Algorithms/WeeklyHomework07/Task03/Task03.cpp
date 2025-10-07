#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    set<int> intervals;
    intervals.insert(0);
    intervals.insert(N+1);

    int K, A;
    cin >> K >> A;

    int Q;
    cin >> Q;

    int possibleShips = 0;
    int temp = N;
    while (temp >= A)
    {
        temp -= A;
        possibleShips++;
        temp--;
    }

    for (int s = 1; s <= Q; s++)
    {
        int x;
        cin >> x;
        intervals.insert(x);
        auto mid = intervals.find(x);
        int prev = *(--mid);
        mid++;
        int next = *(++mid);
        mid--;

        int toRep = 0;
        int iS1 = next - prev - 1;
        while (iS1 >= A)
        {
            iS1 -= A;
            toRep++;
            iS1--;
        }
        possibleShips -= toRep;

        int iS2 = *mid - prev - 1;
        while (iS2 >= A)
        {
            iS2 -= A;
            possibleShips++;
            iS2--;
        }
        int iS3 = next - *mid - 1;
        while (iS3 >= A)
        {
            iS3 -= A;
            possibleShips++;
            iS3--;
        }

        if (possibleShips < K)
        {
            cout << s;
            return 0;
        }
    }

    cout << -1;
    return 0;
}

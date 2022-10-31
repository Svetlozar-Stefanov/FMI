#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    stack<int> lToR;
    queue<int> rToL;

    for (int i = 0; i < N; i++)
    {
        int warrior = arr[i];
        if (warrior > 0)
        {
            lToR.push(warrior);
            while (rToL.size() > 0)
            {
                cout << rToL.front() << " ";
                rToL.pop();
            }
        }
        else if (warrior < 0)
        {
            rToL.push(warrior);
            if (lToR.size() > 0)
            {
                i++;
                while (i < N && arr[i] < 0)
                {
                    rToL.push(arr[i]);
                    i++;
                }
                i--;

                while (lToR.size() > 0 && rToL.size() > 0)
                {
                    if (lToR.top() > -rToL.front())
                    {
                        rToL.pop();
                    }
                    else if (lToR.top() < -rToL.front())
                    {
                        lToR.pop();
                    }
                    else
                    {
                        rToL.pop();
                        lToR.pop();
                    }
                }

                while (rToL.size() > 0)
                {
                    cout << rToL.front() << " ";
                    rToL.pop();
                }
            }
        }
    }

    vector<int> lres;
    while (lToR.size() > 0)
    {
        lres.push_back(lToR.top());
        lToR.pop();
    }

    for (int i = lres.size() - 1; i >= 0; i--)
    {
        cout << lres[i] << " ";
    }
}

#include <iostream>
#include <vector>

using namespace std;

//int numberOfPlantVar(vector<uint64_t> &table, int pos)
//{
//    if (pos < 0)
//    {
//        return 0;
//    }
//
//    if (table[pos] == 0)
//    {
//        table[pos] = (numberOfPlantVar(table, pos - 1) + 
//            numberOfPlantVar(table, pos - 2)) % 1000000007;
//    }
//
//    return table[pos];
//}

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 2;
        return 0;
    }

    vector<uint64_t> table(n);
    table[0] = 1;
    table[1] = 1;

    for (int i = 2; i < n; i++)
    {
        table[i] = (table[i - 1] + table[i - 2]) % 1000000007;
    }

    cout << (2 * table[n-1]) % 1000000007;
}

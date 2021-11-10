#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<string> words;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        words.push_back(temp);
    }

    char letter;
    cin >> letter;

    vector<int> positions;
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i][0] == letter)
        {
            positions.push_back(i);
        }
    }

    for (int i = 0; i < positions.size(); i++)
    {
        cout << positions[i] << " ";
    }
}
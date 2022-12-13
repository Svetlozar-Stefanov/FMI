#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

struct Dir
{
    string name;
    int idx;

    Dir(string name, int idx) {
        this->name = name;
        this->idx = idx;
    }
};

bool operator<(Dir& d1, Dir& d2)
{
    return d1.name < d2.name;
}

struct Comparator
{
    bool operator()(const Dir& d1, const Dir& d2) const
    {
        return d1.name < d2.name;
    }
};


int main()
{
    string path = "/";

    vector<string> dirs;
    dirs.push_back("/");

    stack<int> current;
    current.push(0);

    unordered_map<int, set<Dir, Comparator>> directories;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        
        if (input == "ls")
        {
            for (auto j = directories[current.top()].begin(); j != directories[current.top()].end(); j++)
            {
                cout << (*j).name << " ";
            }
            cout << '\n';
        }
        else if (input == "pwd")
        {
            cout << path << '\n';
        }
        else if (input == "mkdir")
        {
            string name;
            cin >> name;
            Dir newDir(name, dirs.size());
            if (directories[current.top()].find(newDir) != directories[current.top()].end())
            {
                cout << "Directory already exists\n";
                continue;
            }

            dirs.push_back(name);
            directories[current.top()].insert(newDir);
        }
        else if (input == "cd")
        {
            string name;
            cin >> name;
            Dir searchedDir(name, -1);
            if (name == ".." && current.size() <= 1)
            {
                cout << "No such directory\n";
                continue;
            }
            else if(name != ".." 
                && directories[current.top()].find(searchedDir) == directories[current.top()].end())
            {
                cout << "No such directory\n";
                continue;
            }

            if (name == "..")
            {
                path.erase(path.end() - (dirs[current.top()].size() + 1), path.end());
                current.pop();
            }
            else
            {
                current.push((*directories[current.top()].find(searchedDir)).idx);
                path += name;
                path += '/';
            }
        }
    }
}

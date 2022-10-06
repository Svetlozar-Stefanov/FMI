#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct tourist {
    string name;
    string author;
    string publisher;
    unsigned year
};

void printAllBooksFromYear(vector<tourist> & library, const unsigned year) 
{
    for (int i = 0; i < library.size(); i++)
    {
        if (library[i].year == year)
        {
            cout << library[i].title << '\n';
        }
    }
}

void printAllAuthorsFromPublisher(vector<tourist>& library, const string publisher)
{
    for (int i = 0; i < library.size(); i++)
    {
        if (library[i].publisher == publisher)
        {
            cout << library[i].author << '\n';
        }
    }
}

int titlesStartingWithLetter(vector<tourist>& library, const char letter)
{
    int count = 0;

    for (int i = 0; i < library.size(); i++)
    {
        if (library[i].title[0] == letter)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct tourist {
    string name;
    bool isMale;
    string country;
    unsigned short age;
    unsigned daysInBulgaria;
};

float avgAge(vector<tourist> tourists) 
{
    unsigned avgAge = 0;
    for (int i = 0; i < tourists.size(); i++)
    {
        avgAge += tourists[i].age;
    }

    return avgAge / 2.0;
}

int numberOfFemaleVisitors(vector<tourist> tourists)
{
    unsigned count = 0;
    for (int i = 0; i < tourists.size(); i++)
    {
        if (!tourists[i].isMale)
        {
            count++;
        }
    }

    return count;
}

string oldestMaleVisitor(vector<tourist> tourists)
{
    unsigned age = 0;
    tourist oldestTourist;
    for (int i = 0; i < tourists.size(); i++)
    {
        if (tourists[i].isMale && tourists[i].age > age)
        {
            age = tourists[i].age;
            oldestTourist = tourists[i];
        }
    }

    return oldestTourist.name;
}

int numberOfFemalesFromSweden(vector<tourist> tourists)
{
    unsigned count = 0;
    for (int i = 0; i < tourists.size(); i++)
    {
        if (!tourists[i].isMale 
            && tourists[i].age < 25
            && tourists[i].daysInBulgaria > 30)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    
}

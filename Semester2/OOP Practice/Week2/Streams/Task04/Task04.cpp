#include <iostream>
#include <fstream>

const int BUFF_SIZE = 1024;
const int MAX_PAIRS = 25;

struct Pair {
    unsigned a;
    unsigned b;
};

struct Relation {
    Pair pairs[MAX_PAIRS];

    unsigned NumOfPairs;
};

void addPair(Relation& rel, Pair pr) {
    if (rel.NumOfPairs < MAX_PAIRS)
    {
        rel.pairs[rel.NumOfPairs++] = pr;
    }
}

Relation readRelation(const char * fileName, std::fstream& file) 
{
    file.open(fileName, std::fstream::in);

    Relation rel;
    rel.NumOfPairs = 0;

    if (file.is_open())
    {
        char buffer[BUFF_SIZE];
        while (!file.eof())
        {
            file.getline(buffer, BUFF_SIZE);

            Pair newPair;
            newPair.a = buffer[0] - '0';
            newPair.b = buffer[2] - '0';

            rel.pairs[rel.NumOfPairs++] = newPair;
        }
    }

    file.close();
    rel.NumOfPairs--;

    return rel;
}

void writeRelation(const char* fileName, std::fstream &file, Relation &realation)
{
    file.open(fileName, std::fstream::out);

    if (file.is_open())
    {
        for (int i = 0; i < realation.NumOfPairs; i++)
        {
            file << realation.pairs[i].a << "," << realation.pairs[i].b << std::endl;
        }
    }

    file.close();
}

int main()
{
    std::fstream file;
    Relation rel = readRelation("rel.txt", file);

    Pair newP;
    newP.a = 2;
    newP.b = 1;

    addPair(rel, newP);

    writeRelation("rel.txt", file, rel);
}
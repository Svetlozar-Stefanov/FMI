#include <iostream>
#include <fstream>

const char* sfileNmae = "source.txt";
const char* cfileNmae = "copy.txt";
const int BUFF_SIZE = 1024;

int main()
{
    std::fstream sourceFile;
    std::fstream copyFile;

    sourceFile.open(sfileNmae, std::fstream::in);
    copyFile.open(cfileNmae, std::fstream::out);

    if (sourceFile.is_open() && copyFile.is_open())
    {
        char buffer[BUFF_SIZE];

        while (!sourceFile.eof())
        {
            sourceFile.getline(buffer, BUFF_SIZE);

            copyFile << buffer;
            copyFile << std::endl;
        }
    }
}
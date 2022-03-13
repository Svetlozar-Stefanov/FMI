#include <iostream>
#include <fstream>

const unsigned int BUFFER_SIZE = 1024;

int main()
{
    const char* fileName = "Task01.cpp";

    std::fstream myFile;

    myFile.open(fileName, std::fstream::in);

    char buffer[BUFFER_SIZE];

    if (myFile.is_open())
    {
        while (!myFile.eof())
        {
            myFile.getline(buffer, BUFFER_SIZE);

            std::cout << buffer << std::endl;
        }
    }
}
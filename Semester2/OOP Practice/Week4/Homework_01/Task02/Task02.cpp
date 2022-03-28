#include <iostream>
#include <fstream>

const int NAME_SIZE = 25;
const int EMAIL_SIZE = 25;
const int BUFF_SIZE = 2024;
const int SEPARATE_DATA_SIZE = 50;
const int NUMBER_OF_STUDENTS = 100;

char** createMatrix(const int rows, const int cols)
{
    char** matrix = new char* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new char[cols];
    }

    return matrix;
}

void deleteMatrix(char** matrix, const int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int sleng(const char* str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }

    return count;
}

bool equal(const char* s1, const char* s2)
{
    int size1 = sleng(s1);
    int size2 = sleng(s2);
    if (size1 != size2)
    {
        return false;
    }
    for (int i = 0; i < size1; i++)
    {
        if (s1[i] != s2[i])
        {
            return false;
        }
    }

    return true;
}

char * copy(const char* str)
{
    int size = sleng(str);
    char* copy = new char[size + 1];

    for (int i = 0; i < size + 1; i++)
    {
        copy[i] = str[i];
    }

    return copy;
}

int strToNum(const char* str)
{
    int size = sleng(str);
    int num = 0;

    for (int i = 0; i < size; i++)
    {
        num += (str[i] - '0') * pow(10, size - i - 1);
    }

    return num;
}

float strToFloat(const char* str)
{
    int size = sleng(str);
    int num = 0;
    int commaI = 1;

    for (int i = 0; i < size; i++)
    {
        if (str[i] == '.')
        {
            commaI = i;
            break;
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (i < commaI)
        {
            num += (str[i] - '0') * pow(10, size - i - 2);
        }
        else if (i == commaI)
        {
            continue;
        }
        else
        {
            num += (str[i] - '0') * pow(10, size - i - 1);
        }
    }

    return (float)num / pow(10, size - commaI - 1);
}

enum Genders
{
    Male,
    Female,
    Other
};

struct Student
{
    char * Name;
    unsigned int FN;
    unsigned int Age;
    Genders Gender;
    char * Email;
    float AvgGrade;

};

Student** readFile(const char* path, std::fstream &file) 
{
    file.open(path, std::fstream::in);
    if (!file.is_open())
    {
        std::cout << "Failed to open file!\n";
        return nullptr;
    }

    Student** students = new Student * [NUMBER_OF_STUDENTS];
    int sI = 0;

    char buffer[BUFF_SIZE];
    Student* temp = nullptr;

    while (!file.eof())
    {
        file.getline(buffer, BUFF_SIZE);

        int size = sleng(buffer);


        char tag[SEPARATE_DATA_SIZE];
        char info[SEPARATE_DATA_SIZE];
        int tI = 0;
        int iI = 0;

        for (int i = 0; i < size; i++)
        {
            if (buffer[i] == '<' && i < size - 1 && buffer[i + 1] != '\\')
            {
                i++;
                while (buffer[i] != '>' && i < size)
                {
                    tag[tI++] = buffer[i++];
                }
                tag[tI] = '\0';
                if (equal(tag, "student"))
                {
                    temp = new Student;
                }

                i++;
                while (buffer[i] != '<' && i < size - 1 && buffer[i + 1] != '\\')
                {
                    info[iI++] = buffer[i++];
                }
                info[iI] = '\0';

                if (equal(tag, "name"))
                {
                    temp->Name = copy(info);
                }
                else if (equal(tag, "fn"))
                {
                    temp->FN = strToNum(info);
                }
                else if (equal(tag, "age"))
                {
                    temp->Age = strToNum(info);
                }
                else if (equal(tag, "gender"))
                {
                    if (equal(info,"Male"))
                    {
                        temp->Gender = Genders::Male;
                    }
                    if (equal(info, "Female"))
                    {
                        temp->Gender = Genders::Female;
                    }
                }
                else if (equal(tag, "email"))
                {
                    temp->Email = copy(info);
                }
                else if (equal(tag, "grade"))
                {
                    temp->AvgGrade = strToFloat(info);
                }

                tI = 0;
                iI = 0;
            }
            else if (buffer[i] == '<' && i < size - 1 && buffer[i + 1] == '\\')
            {
                students[sI++] = temp;
                temp = nullptr;
            }
        }
    }

    return students;
}


int main()
{
    std::fstream file;

    Student** students = readFile("s.txt", file);

}
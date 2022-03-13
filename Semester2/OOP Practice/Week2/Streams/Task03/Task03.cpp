#include <iostream>
#include <fstream>

const char* sfileNmae = "source.txt";
const char* cfileNmae = "copy.txt";
const int BUFF_SIZE = 1024;
const int FILE_NAME_SIZE = 256;
const int DATA_SIZE = 256;

struct Student
{
	char Name[DATA_SIZE];
	char Surname[DATA_SIZE];
	char Email[DATA_SIZE];
	char Fn[DATA_SIZE];
};

bool isEqual(const char* fn1, const char* fn2)
{
	for (int i = 0; i < strlen(fn2); i++)
	{
		if (fn1[i] != fn2[i])
		{
			return false;
		}
	}

	return true;
}

void copy(char * str1, const char* str2) {
	for (int i = 0; i < strlen(str2) + 1; i++)
	{
		str1[i] = str2[i];
	}
}

void print(const char* fn, Student * students, const int num) {
	for (int i = 0; i < num; i++)
	{
		if (isEqual(students[i].Fn, fn))
		{
			std::cout << students[i].Name << " " << students[i].Surname << " " << students[i].Email << " " << students[i].Fn << std::endl;
		}
	}

}

void edit(const char* fn, const char* newEmail, Student* students, const int num) {
	for (int i = 0; i < num; i++)
	{
		if (isEqual(students[i].Fn, fn))
		{
			copy(students[i].Email, newEmail);
		}
	}

}

void save(const char* fileName, Student* students, const int num)
{
	std::fstream file;
	file.open(fileName, std::fstream::out);
	if (file.is_open())
	{
		for (int i = 0; i < num; i++)
		{
			file << students[i].Name << "," << students[i].Surname << "," << students[i].Email << "," << students[i].Fn << '\n';
		}
	}
}

int main()
{
	std::fstream file;
	char fileName[FILE_NAME_SIZE];

	std::cin >> fileName;
	Student students[500];
	int num = 0;

	file.open(fileName, std::fstream::in);
	if (file.is_open())
	{
		while (!file.eof())
		{
			char buffer[BUFF_SIZE];
			int indx = 0;
			char name[DATA_SIZE];
			char surname[DATA_SIZE];
			char email[DATA_SIZE];
			char fNum[DATA_SIZE];

			file.getline(buffer, BUFF_SIZE);

			int pos = 0;
			int i = 0;
			while (buffer[i] != '\0')
			{
				if (buffer[i] == ',')
				{
					switch (pos)
					{
					case 0: name[indx++] = '\0'; break;
					case 1: surname[indx++] = '\0'; break;
					case 2: email[indx++] = '\0'; break;
					case 3: fNum[indx++] = '\0'; break;
					default:
						break;
					}
					pos++;
					indx = 0;
				}
				else
				{
					switch (pos)
					{
					case 0: name[indx++] = buffer[i]; break;
					case 1: surname[indx++] = buffer[i]; break;
					case 2: email[indx++] = buffer[i]; break;
					case 3: fNum[indx++] = buffer[i]; break;
					default:
						break;
					}
				}

				if (buffer[i + 1] == '\0')
				{
					fNum[indx++] = '\0';
				}

				i++;
			}

			copy(students[num].Name, name);
			copy(students[num].Surname, surname);
			copy(students[num].Email, email);
			copy(students[num++].Fn, fNum);
		}
	}

	print("80000", students, num);
	edit("80001", "kuncho.org", students, num);

	save(fileName, students, num);
}

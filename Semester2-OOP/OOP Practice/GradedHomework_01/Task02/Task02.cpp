#include <iostream>
#include <fstream>

const int INPUT_SIZE = 2024;
const int NAME_SIZE = 25;
const int EMAIL_SIZE = 25;
const int BUFF_SIZE = 2024;
const int SEPARATE_DATA_SIZE = 50;
const int MAX_NUMBER_OF_STUDENTS = 100;
const int AGE_BOT = 15;
const int AGE_TOP = 65;
const int TEXT_TOP = 25;
const float GRADE_BOT = 2.0f;
const float GRADE_TOP = 6.0f;

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
	if (matrix == nullptr)
	{
		return;
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int sleng(const char* str)
{
	if (str == nullptr)
	{
		return -1;
	}

	int count = 0;
	while (str[count] != '\0')
	{
		count++;
	}

	return count;
}

int wordCount(const char* str, const char sep)
{
	if (str == nullptr)
	{
		return -1;
	}

	int size = sleng(str);
	int count = 1;

	for (int i = 0; i < size - 1; i++)
	{
		if (str[i] == sep && str[i + 1] != sep)
		{
			count++;
		}
	}

	return count;
}

char** parse(const char* str, const char sep)
{
	if (str == nullptr)
	{
		return nullptr;
	}

	char** words = createMatrix(wordCount(str, sep), INPUT_SIZE);
	int size = sleng(str);

	int row = 0;
	int col = 0;
	for (int i = 0; i < size; i++)
	{
		if (str[i] == sep)
		{
			words[row][col] = '\0';
			row++;
			col = 0;
			while (i < size && str[i] == sep)
			{
				i++;
			}
			i--;

			continue;
		}

		words[row][col++] = str[i];
	}
	words[row][col] = '\0';

	return words;
}

bool equal(const char* s1, const char* s2)
{
	if (s1 == nullptr || s2 == nullptr)
	{
		return false;
	}

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

char* copy(const char* str)
{
	if (str == nullptr)
	{
		return nullptr;
	}

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
	if (str == nullptr)
	{
		return -1;
	}

	int size = sleng(str);
	int num = 0;

	for (int i = 0; i < size; i++)
	{
		num += (str[i] - (int)'0') * pow(10, size - i - 1);
	}

	return num;
}

double strToFloat(const char* str)
{
	if (str == nullptr)
	{
		return -1;
	}

	int size = sleng(str);
	double num = 0;
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
			num += (str[i] - (int)'0') * pow(10, size - i - 2);
		}
		else if (i == commaI)
		{
			continue;
		}
		else
		{
			num += (str[i] - (int)'0') * pow(10, size - i - 1);
		}
	}

	return num / pow(10, size - commaI - 1);
}

enum class Genders
{
	Female,
	Male
};

struct Student
{
	char* Name;
	unsigned int FN;
	unsigned int Age;
	Genders Gender;
	char* Email;
	float AvgGrade;

	~Student() {
		delete[] Name;
		delete[] Email;
	}

};

bool isValidLength(const char* str, const int maxLength)
{
	if (str == nullptr)
	{
		return false;
	}

	return sleng(str) <= maxLength;
}

bool containsSymbol(const char* str, const char ch)
{
	if (str == nullptr)
	{
		return false;
	}

	for (int i = 0; i < sleng(str); i++)
	{
		if (str[i] == ch)
		{
			return true;
		}
	}

	return false;
}

bool contains(Student** students, const int studentCount, const unsigned int fn)
{
	if (students == nullptr)
	{
		return false;
	}

	for (int i = 0; i < studentCount; i++)
	{
		if (students[i]->FN == fn)
		{
			return true;
		}
	}

	return false;
}

Student* find(Student** students, const int studentCount, const unsigned int fn)
{
	if (students == nullptr)
	{
		return nullptr;
	}

	for (int i = 0; i < studentCount; i++)
	{
		if (students[i]->FN == fn)
		{
			return students[i];
		}
	}

	return nullptr;
}

bool isInInterval(const int num, const int iStart, const int iEnd)
{
	return iStart <= num <= iEnd;
}

bool isInInterval(const float num, const float iStart, const float iEnd)
{
	return iStart <= num <= iEnd;
}

bool isValidStudent(Student** students, const int studentCount, Student*& student)
{
	if (students == nullptr || student == nullptr)
	{
		return false;
	}

	return isValidLength(student->Name, TEXT_TOP)
		&& !contains(students, studentCount, student->FN)
		&& isInInterval(student->Age, AGE_BOT, AGE_TOP)
		&& isValidLength(student->Email, TEXT_TOP)
		&& containsSymbol(student->Email, '@')
		&& isInInterval(student->AvgGrade, GRADE_BOT, GRADE_TOP);
}

Student** readFile(const char* path, std::fstream& file, int& studentCount)
{
	file.open(path, std::fstream::in);
	if (!file.is_open())
	{
		std::cout << "Failed to open file!\n";
		return nullptr;
	}

	Student** students = new Student * [MAX_NUMBER_OF_STUDENTS];

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
					if (equal(info, "Male"))
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
				if (isValidStudent(students, studentCount, temp))
				{
					students[studentCount++] = temp;
					temp = nullptr;
				}
				else
				{
					delete temp;
				}

			}
		}
	}

	file.close();

	return students;
}

void change(Student** students, const int studentCount, const unsigned int fn, const char* tag, char* value)
{
	if (students == nullptr)
	{
		return;
	}

	Student* student = find(students, studentCount, fn);
	if (student == nullptr)
	{
		std::cout << "Invalid student!\n";
	}

	if (equal(tag, "name"))
	{
		if (isValidLength(value, 25))
		{
			student->Name = copy(value);
		}
		else
		{
			std::cout << "Invalid Name!\n";
			return;
		}
	}
	else if (equal(tag, "fn"))
	{
		unsigned int newFn = strToNum(value);
		if (!contains(students, studentCount, newFn))
		{
			student->FN = newFn;
		}
		else
		{
			std::cout << "Invalid FN!\n";
			return;
		}
	}
	else if (equal(tag, "age"))
	{
		unsigned int age = strToNum(value);
		if (isInInterval(age, AGE_BOT, AGE_TOP))
		{
			student->Age = age;
		}
		else
		{
			std::cout << "Invalid Age!\n";
			return;
		}
	}
	else if (equal(tag, "gender"))
	{

		if (equal(value, "male"))
		{
			student->Gender = Genders::Male;
		}
		else if (equal(value, "female"))
		{
			student->Gender = Genders::Female;
		}
		else
		{
			std::cout << "Invalid Gender!\n";
			return;
		}
	}
	else if (equal(tag, "email"))
	{

		if (isValidLength(value, 25) && containsSymbol(value, '@'))
		{
			student->Email = copy(value);
		}
		else
		{
			std::cout << "Invalid Email!\n";
			return;
		}
	}
	else if (equal(tag, "grade"))
	{
		float grade = strToNum(value);
		if (isInInterval(grade, GRADE_BOT, GRADE_TOP))
		{
			student->AvgGrade = grade;
		}
		else
		{
			std::cout << "Invalid Grade!\n";
			return;
		}
	}
	else
	{
		std::cout << "Invalid Operation!\n";
		return;
	}

	std::cout << "Operation successful!\n";

}

const char* genderToStr(Genders gender)
{
	if (gender == Genders::Male)
	{
		return "Male";
	}
	else if (gender == Genders::Female)
	{
		return "Female";
	}
}

void printStudent(Student* student)
{
	std::cout << "--------------------------------\n";

	std::cout << "Name: " << student->Name << '\n';
	std::cout << "FN: " << student->FN << '\n';
	std::cout << "Age: " << student->Age << '\n';
	std::cout << "Gender: " << genderToStr(student->Gender) << '\n';
	std::cout << "Email: " << student->Email << '\n';
	std::cout << "Average Grade: " << student->AvgGrade << '\n';

	std::cout << "--------------------------------\n";
}

void print(Student** students, const int studentCount)
{
	for (int i = 0; i < studentCount; i++)
	{
		printStudent(students[i]);
	}
}

void sortFN(Student**& students, const int studentCount, int* indices)
{
	for (int i = 0; i < studentCount; i++)
	{
		for (int j = 0; j < studentCount - i - 1; j++)
		{
			if (students[indices[j]]->FN > students[indices[j + 1]]->FN)
			{
				int temp = indices[j];
				indices[j] = indices[j + 1];
				indices[j + 1] = temp;
			}
		}
	}
}

void sortAge(Student**& students, const int studentCount, int* indices)
{
	for (int i = 0; i < studentCount; i++)
	{
		for (int j = 0; j < studentCount - i - 1; j++)
		{
			if (students[indices[j]]->Age > students[indices[j + 1]]->Age)
			{
				int temp = indices[j];
				indices[j] = indices[j + 1];
				indices[j + 1] = temp;
			}
		}
	}
}

void sortGender(Student**& students, const int studentCount, int* indices)
{
	for (int i = 0; i < studentCount; i++)
	{
		for (int j = 0; j < studentCount - i - 1; j++)
		{
			if (students[indices[j]]->Gender > students[indices[j + 1]]->Gender)
			{
				int temp = indices[j];
				indices[j] = indices[j + 1];
				indices[j + 1] = temp;
			}
		}
	}
}

void sortGrade(Student**& students, const int studentCount, int* indices)
{
	for (int i = 0; i < studentCount; i++)
	{
		for (int j = 0; j < studentCount - i - 1; j++)
		{
			if (students[indices[j]]->AvgGrade > students[indices[j + 1]]->AvgGrade)
			{
				int temp = indices[j];
				indices[j] = indices[j + 1];
				indices[j + 1] = temp;
			}
		}
	}
}

bool isLetter(const char l)
{
	return ('A' <= l && l <= 'Z')
		|| ('a' <= l && l <= 'z');
}

bool isLetterOrNum(const char l)
{
	return ('A' <= l && l <= 'Z')
		|| ('a' <= l && l <= 'z')
		|| ('0' <= l && l <= '9');
}

void sortName(Student**& students, const int studentCount, int* indices)
{
	for (int i = 0; i < studentCount; i++)
	{
		for (int j = 0; j < studentCount - i - 1; j++)
		{
			int wI1 = 0;
			int wI2 = 0;

			int s1 = sleng(students[indices[j]]->Name);
			int s2 = sleng(students[indices[j + 1]]->Name);
			int minS = std::min(s1, s2);

			while (students[indices[j]]->Name[wI1] == students[indices[j + 1]]->Name[wI2]
				&& wI1 < minS && wI2 < minS)
			{
				if (isLetter(students[indices[j]]->Name[wI1]) && isLetter(students[indices[j]]->Name[wI2])
					|| !(isLetter(students[indices[j]]->Name[wI1]) && isLetter(students[indices[j]]->Name[wI2])))
				{
					wI1++;
					wI2++;
				}
				else if (!isLetter(students[indices[j]]->Name[wI1]))
				{
					wI1++;
				}
				else if (!isLetter(students[indices[j]]->Name[wI2]))
				{
					wI2++;
				}
			}

			if (students[indices[j]]->Name[wI1] > students[indices[j + 1]]->Name[wI2]
				|| ((wI1 > minS || wI2 > minS) && s1 > s2))
			{
				int temp = indices[j];
				indices[j] = indices[j + 1];
				indices[j + 1] = temp;
			}
		}
	}
}

void sortEmail(Student**& students, const int studentCount, int* indices)
{
	for (int i = 0; i < studentCount; i++)
	{
		for (int j = 0; j < studentCount - i - 1; j++)
		{
			int wI1 = 0;
			int wI2 = 0;

			int s1 = sleng(students[indices[j]]->Email);
			int s2 = sleng(students[indices[j + 1]]->Email);
			int minS = std::min(s1, s2);

			while (students[indices[j]]->Email[wI1] == students[indices[j + 1]]->Email[wI2]
				&& wI1 < minS && wI2 < minS)
			{
				if (isLetterOrNum(students[indices[j]]->Email[wI1]) && isLetterOrNum(students[indices[j]]->Email[wI2])
					|| !(isLetterOrNum(students[indices[j]]->Email[wI1]) && isLetterOrNum(students[indices[j]]->Email[wI2])))
				{
					wI1++;
					wI2++;
				}
				else if (!isLetterOrNum(students[indices[j]]->Email[wI1]))
				{
					wI1++;
				}
				else if (!isLetterOrNum(students[indices[j]]->Email[wI2]))
				{
					wI2++;
				}
			}

			if (students[indices[j]]->Email[wI1] > students[indices[j + 1]]->Email[wI2]
				|| ((wI1 > minS || wI2 > minS) && s1 > s2))
			{
				int temp = indices[j];
				indices[j] = indices[j + 1];
				indices[j + 1] = temp;
			}
		}
	}
}

void sort(Student** students, const int studentCount, const char* sortTag)
{
	int* indices = new int[studentCount];
	for (int i = 0; i < studentCount; i++)
	{
		indices[i] = i;
	}
	if (equal(sortTag, "name"))
	{
		sortName(students, studentCount, indices);
	}
	else if (equal(sortTag, "fn"))
	{
		sortFN(students, studentCount, indices);
	}
	else if (equal(sortTag, "age"))
	{
		sortAge(students, studentCount, indices);
	}
	else if (equal(sortTag, "gender"))
	{
		sortGender(students, studentCount, indices);
	}
	else if (equal(sortTag, "email"))
	{
		sortEmail(students, studentCount, indices);
	}
	else if (equal(sortTag, "grade"))
	{
		sortGrade(students, studentCount, indices);
	}
	else
	{
		std::cout << "Invalid input!\n";
		return;
	}

	Student** sCopy = new Student * [studentCount];
	for (int i = 0; i < studentCount; i++)
	{
		sCopy[i] = students[i];
	}
	for (int i = 0; i < studentCount; i++)
	{
		students[i] = sCopy[indices[i]];
	}

	delete[] sCopy;
	delete[] indices;

	std::cout << "Operation successful!\n";
}

void save(const char* path, std::fstream& file, Student** students, const int studentCount)
{
	if (students == nullptr)
	{
		return;
	}

	file.open(path, std::fstream::out);
	if (!file.is_open())
	{
		std::cout << "Failed to open file!\n";
		return;
	}

	for (int i = 0; i < studentCount; i++)
	{
		Student* current = students[i];

		file << "<student>\n";
		file << "\t<name>" << current->Name << "<\\name>\n";
		file << "\t<fn>" << current->FN << "<\\fn>\n";
		file << "\t<age>" << current->Age << "<\\age>\n";
		file << "\t<gender>" << genderToStr(current->Gender) << "<\\gender>\n";
		file << "\t<email>" << current->Email << "<\\email>\n";
		file << "\t<grade>" << current->AvgGrade << "<\\grade>\n";
		file << "<\\student>\n";
	}

	file.close();

	std::cout << "Operation successful!\n";
}


int main()
{
	std::fstream file;

	char path[INPUT_SIZE];

	std::cout << "Please enter a file path:\n";
	std::cin.getline(path, INPUT_SIZE);

	int studentCount = 0;
	Student** students = readFile(path, file, studentCount);
	if (students == nullptr)
	{
		std::cout << "No valid students found!\n";
		return 1;
	}
	std::cout << "File successfully loaded!\n";

	char input[INPUT_SIZE];
	do
	{
		std::cout << "Please enter a command:\n";

		std::cin.getline(input, INPUT_SIZE);
		char** data = parse(input, ' ');

		if (equal(data[0], "edit"))
		{
			int fn = strToNum(data[1]);
			char* tag = data[2];
			char value[INPUT_SIZE];
			int vI = 0;

			int wCount = wordCount(input, ' ');
			for (int i = 3; i < wCount; i++)
			{
				for (int j = 0; j < sleng(data[i]); j++)
				{
					value[vI++] = data[i][j];
				}
				if (i + 1 != wCount)
				{
					value[vI++] = ' ';
					continue;
				}
				value[vI] = '\0';
			}

			change(students, studentCount, fn, tag, value);
		}
		else if (equal(data[0], "sort"))
		{
			char* tag = data[1];

			sort(students, studentCount, tag);
		}
		else if (equal(data[0], "view"))
		{
			print(students, studentCount);
		}

		deleteMatrix(data, wordCount(input, ' '));

	} while (!equal(input, "save"));

	save(path, file, students, studentCount);

	return 0;
}
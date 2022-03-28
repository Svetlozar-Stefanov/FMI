#include <iostream>
#include <fstream>

const int BUFF_SIZE = 2024;

const int INPUT_SIZE = 256;

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

int sleng(const unsigned char* str)
{
	int count = 0;
	while (str[count] != '\0')
	{
		count++;
	}

	return count;
}

int wordCount(const char* str, const char sep)
{
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

int getFileSize(std::fstream& file)
{
	size_t currentPos = file.tellg();

	file.seekg(0, std::ios::end);
	size_t endPos = file.tellg();

	file.seekg(currentPos);

	return endPos;
}

int getFileSize(const char* path, std::fstream& file)
{
	file.open(path, std::ios::out | std::ios::in);
	if (!file.is_open())
	{
		std::cout << "-1" << '\n';
		return -1;
	}

	size_t currentPos = file.tellg();

	file.seekg(0, std::ios::end);
	size_t endPos = file.tellg();

	file.seekg(currentPos);

	file.close();

	return endPos;
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

char* byteToHexStr(int n)
{
	char* hex = new char[100];

	int i = 0;
	for (; i < 2; i++)
	{
		int temp = 0;

		temp = n % 16;
		if (temp < 10)
		{
			hex[i] = temp + '0';
		}
		else
		{
			hex[i] = temp + 55;
		}

		n /= 16;
	}
	hex[i] = '\0';

	for (int i = 0; i < sleng(hex) / 2; i++)
	{
		char temp = hex[i];

		hex[i] = hex[sleng(hex) - i - 1];

		hex[sleng(hex) - i - 1] = temp;
	}

	return hex;
}

unsigned char hexStrToByte(char* hex)
{
	int size = sleng(hex);
	int byte = 0;
	for (int i = 0; i < size; i++)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			byte += (hex[i] - '0') * pow(16, size - i - 1);
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			byte += (hex[i] - 55) * pow(16, size - i - 1);
		}
	}

	return (unsigned char)byte;
}

unsigned char* readFile(const char* path, std::fstream& file)
{
	file.open(path, std::ios::binary | std::ios::in);
	if (!file.is_open())
	{
		std::cout << "-1" << "\n";
		return nullptr;
	}

	int size = getFileSize(file);
	unsigned char* buffer = new unsigned char[size];

	file.read((char*)buffer, size);

	file.close();

	return buffer;
}

void view(const unsigned char* data, const int size)
{
	for (int i = 0; i < size; i++)
	{

		char* hex = byteToHexStr((int)data[i]);
		std::cout << hex;
		std::cout << " ";
	}
	std::cout << '\n';
	for (int i = 0; i < size; i++)
	{
		if (!(data[i] >= 'a' && data[i] <= 'z')
			&& !(data[i] >= 'A' && data[i] <= 'Z'))
		{
			std::cout << ". ";
		}
		else
		{
			std::cout << data[i] << " ";
		}
	}
	std::cout << "\n";
}

void change(unsigned char* data, const int size, const int index, const unsigned char value)
{
	if (index < 0 || index >= size)
	{
		std::cout << "-1";
		return;
	}
	data[index] = value;
}

void remove(unsigned char*& data, int& size)
{
	unsigned char* newData = new unsigned char[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	size--;
}

void add(unsigned char*& data, int& size, const unsigned char value)
{
	unsigned char* newData = new unsigned char[size + 1];
	for (int i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}
	newData[size] = value;
	delete[] data;

	data = newData;
	size++;
}

void saveAs(const char* path, std::fstream& file, unsigned char* data, const int size)
{
	file.open(path, std::ios::binary | std::ios::out);
	if (!file.is_open())
	{
		std::cout << "-1" << "\n";
		return;
	}

	file.write((const char*)data, size);

	file.close();
}

int main()
{
	char initialPath[INPUT_SIZE];
	std::cin.getline(initialPath, INPUT_SIZE);

	std::fstream file;

	unsigned char* data = readFile(initialPath, file);
	int fileSize = getFileSize(initialPath, file);

	char input[INPUT_SIZE];

	do
	{
		std::cin.getline(input, INPUT_SIZE);
		char** inputData = parse(input, ' ');
		if (equal(inputData[0], "view"))
		{
			view(data, fileSize);
		}
		else if (equal(inputData[0], "change"))
		{
			change(data, fileSize, strToNum(inputData[1]), hexStrToByte(inputData[2]));
		}
		else if (equal(inputData[0], "remove"))
		{
			remove(data, fileSize);
		}
		else if (equal(inputData[0], "add"))
		{
			add(data, fileSize, hexStrToByte(inputData[1]));
		}
		else if (equal(inputData[0], "save") && wordCount(input, ' ') > 1)
		{
			saveAs(inputData[2], file, data, fileSize);
		}
		else if (equal(inputData[0], "save"))
		{
			saveAs(initialPath, file, data, fileSize);
		}

		deleteMatrix(inputData, wordCount(input, ' '));

	} while (!equal(input, "end"));

	delete[] data;
}

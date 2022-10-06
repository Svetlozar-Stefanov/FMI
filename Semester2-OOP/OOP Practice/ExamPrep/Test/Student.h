#pragma once
class Student
{
private:
	int* grades;
	int size;

	void copy(const Student& other);
	void free();
public:
	Student(int* grades, int size);
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();
};


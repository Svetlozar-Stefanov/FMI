#include <iostream>
#include <fstream>
#include <string>
#include "String.h"
#include "Stack.h"

class Base {
public:
	int i;
	virtual void func() = 0;
};

class Der1 : public Base {
	void func() override {
		std::cout << "Im doing my part!\n";
	}
};

class Der2 : private Base {
	void func() override {
		std::cout << "Im also doing my part!\n";
	}
};

class Adaptee {
public:
	std::string specialFunc() {
		return "I wont do my part!\n";
	}
};

class Adapter : public Base {

	Adaptee a;

	void func() override {
		std::string temp(a.specialFunc());
		temp[3] = 'i';
		temp[4] = 'l';
		temp[5] = 'l';
		std::cout << temp << '\n';
	}
};

int main() {
	Der2 d;
	d.i;
}
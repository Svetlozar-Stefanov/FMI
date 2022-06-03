#pragma once
#include "myVector.h"

unsigned int strleng(const char* str);

unsigned digitsCount(int n);

char* numToStr(int n);

int strToNum(const char * str);

char* append(const char* str1, const char* str2);

char* append(const char* str1, const char filler, const char* str2);

char* copy(const char* str);

bool compare(const char* str1, const char* str2);

bool contains(const myVector<unsigned int> &arr, const unsigned int n);

myVector<char*>* parse(const char* str, const char passEl, const unsigned int wordSize);
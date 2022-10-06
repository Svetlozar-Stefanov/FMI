#pragma once

const double PI = 3.14159265359;

const float EPS = 0.0000001;

float abst(const float n);

unsigned int strleng(const char* str);

char* copy(const char* str);

unsigned dCount(int n);

char* itos(int n);

char* ftos(float n);

bool areEqual(const float n1, const float n2);

bool strcomp(const char* s1, const char* s2);

char** parse(const char* str, const char d);


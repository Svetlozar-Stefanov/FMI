#pragma once

const double EPS = 0.000000001;
const double PI = 3.14159265358979323846;

inline bool epseq(double a, double b)
{
	return abs(a - b) < EPS;
}
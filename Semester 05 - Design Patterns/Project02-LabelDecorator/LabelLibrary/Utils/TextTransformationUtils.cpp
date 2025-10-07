#include "TextTransformationUtils.h"

#include <algorithm>
#include <regex>

using std::string;
using std::find_if;
using std::isspace;
using std::unique;
using std::regex_replace;
using std::regex;

void ltrim(string& str)
{
	str.erase(str.begin(), find_if(str.begin(), str.end(), [](unsigned char ch) {
		return !isspace(ch);
		}));
}

void rtrim(string& str)
{
	str.erase(find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
		return !isspace(ch);
		}).base(), str.end());
}

void normalizeBySpace(string& str)
{
	auto new_end = std::unique(str.begin(), str.end(), [](char ch1, char ch2) {
		return (ch1 == ch2 && ch1 == ' ');
		});
	str.erase(new_end, str.end());
}

void replace(string& str, const string& toReplace, const string& replacement)
{
	str = regex_replace(str, regex(toReplace), replacement);
}
#pragma once
#include <string>

void ltrim(std::string& str);

void rtrim(std::string& str);

void normalizeBySpace(std::string& str);

void replace(std::string& str, const std::string& toReplace, const std::string& replacement);
#pragma once

#include <vector>
#include <string>

bool meetsMinimumArgsCriteria(const std::vector<std::string>& args, int nargs);
bool isValidAmount(const std::string& str);
double parseAmount(const std::string& str);
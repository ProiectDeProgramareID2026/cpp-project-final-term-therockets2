#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool meetsMinimumArgsCriteria(const vector<string>& args, int nargs) {
	if (args.size() < nargs) {
		cout << "Current command does not meet minimum arguments criteria! Expected " << nargs << " arguments" << endl;
		return false;
	}
	return true;
}

//validare suma pentru deposit / withdraw services.
bool isValidAmount(const string& str) {
	if (str.empty()) return false;
	int dotCount = 0;
	int dotPos = -1;
	for (int i = 0; i < (int)str.size(); i++) {
		if (str[i] == '.') {
			dotCount++;
			if (dotCount > 1) return false;
			dotPos = i;
		} else if (!isdigit((unsigned char)str[i])) {
			return false;
		}
	}
	if (dotPos != -1 && (int)str.size() - dotPos - 1 > 2) return false;
	return true;
}

double parseAmount(const string& str) {
	return stod(str);
}
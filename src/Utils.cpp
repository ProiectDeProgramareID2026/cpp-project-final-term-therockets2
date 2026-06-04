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
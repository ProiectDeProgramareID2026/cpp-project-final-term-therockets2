#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

constexpr int leftpad = 18;
void printCommands();

bool meetsMinimumArgsCriteria(const vector<string>& args, int nargs) {
	if (args.size() < nargs) {
		cout << "Current command does not meet minimum arguments criteria! Expected " << nargs << " arguments" << endl;
		printCommands();
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

void printCommands() {
	cout << "=========== Bank Management System ===========" << endl;
	cout << left << setw(leftpad)<< "Command"			<< "<arg1> <arg2> ... <argN>" << endl << endl;
	cout << left << setw(leftpad)<< "--add-client"		<< "<clientName>" << endl;
	cout << left << setw(leftpad)<< "--open-account"	<< "<clientName> <accountType> <currency>" << endl;
	cout << left << setw(leftpad)<< "--close-account"	<< "<clientName> <IBAN>" << endl;
	cout << left << setw(leftpad)<< "--deposit"			<< "<clientName> <IBAN> <amount>" << endl;
	cout << left << setw(leftpad)<< "--withdraw"		<< "<clientName> <IBAN> <amount>" << endl;
	cout << left << setw(leftpad)<< "--list-owner-acc"	<< "<clientName>" << endl;
	cout << left << setw(leftpad)<< "--show-account"	<< "<IBAN>" << endl << endl;
	cout << "Note: values that contain whitespaces need to be wrapped in quotes(e.g. --add-client \"Ion Ionescu\")" << endl;
}


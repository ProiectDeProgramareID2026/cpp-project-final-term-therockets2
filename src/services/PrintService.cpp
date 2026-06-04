#include "../../include/services/PrintService.h"

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

static string formatBalance(double balance, const string& currency) {
    ostringstream oss;
    oss << fixed << setprecision(2) << balance << " " << currency;
    return oss.str();
}

void PrintService::printClientAccounts(shared_ptr<Client> client, const vector<shared_ptr<Account>>& accounts) const {
    cout << "Client: " << client->getName() << endl;
    if (accounts.empty()) {
        cout << "  No accounts found." << endl;
        return;
    }
    for (const auto& account : accounts) {
        cout << "  " << account->getIBAN()
             << " | " << account->getType()
             << " | " << formatBalance(account->getBalance(), account->getCurrency())
             << endl;
    }
}

void PrintService::printAccount(shared_ptr<Account> account) const {
    cout << "IBAN: " << account->getIBAN()
         << " | Type: " << account->getType()
         << " | Balance: " << formatBalance(account->getBalance(), account->getCurrency())
         << endl;
}

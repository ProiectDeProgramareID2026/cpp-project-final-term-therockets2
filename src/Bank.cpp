#include "../include/Bank.h"
#include "../include/CurrentAccount.h"
#include "../include/SavingsAccount.h"
#include <iostream>
#include <algorithm>

using namespace std;

Bank::Bank(){}

bool Bank::clientExists(const string& clientName) const {
    return any_of(clients.begin(), clients.end(),
        [&](const shared_ptr<Client>& client) { return client->getName() == clientName; });
}

bool Bank::clientExists(int id) const {
    return any_of(clients.begin(), clients.end(),
        [&](const shared_ptr<Client>& client) { return client->getId() == id; });
}

bool Bank::accountExists(const string& iban) const {
    return any_of(accounts.begin(), accounts.end(),
        [&](const shared_ptr<Account>& account) { return account->getIBAN() == iban; });
}

void Bank::addClient(shared_ptr<Client> client) {
    clients.push_back(std::move(client));
}

// use with care, makre sure client exists frist, no time to do optional stuff
shared_ptr<Client> Bank::getClient(const string& clientName) {
    auto it = find_if(clients.begin(), clients.end(),
        [&](const shared_ptr<Client>& client) { return client->getName() == clientName; });

    return *it;
}

shared_ptr<Client> Bank::getClient(int id) {
    auto it = find_if(clients.begin(), clients.end(),
        [&](const shared_ptr<Client>& client) { return client->getId() == id; });

    return *it;
}

vector<shared_ptr<Client>>& Bank::getClients() { return clients; }

vector<shared_ptr<Account>>& Bank::getAccounts() { return accounts; }

void Bank::addAccount(int id, int clientId, string type, string IBAN, string currency, double balance, double accountSpecificTrait) {
    if (!clientExists(clientId)) {
        cout << "Error when adding account: client not found " << clientId << endl;
        cout << "Account " << id << " not imported!" << endl;
        return;
    }

    shared_ptr<Account> account;
    shared_ptr<Client> client = getClient(clientId);

    if (type == "Current") {
        accounts.push_back(make_shared<CurrentAccount>(id, client, IBAN, currency, balance, accountSpecificTrait));
    }
    else {
        accounts.push_back(make_shared<SavingsAccount>(id, client, IBAN, currency, balance, accountSpecificTrait));
    }
}

void Bank::openAccount(shared_ptr<Account> account) {
    accounts.push_back(account);
}

shared_ptr<Account> Bank::getAccount(const string& iban) {
    auto it = find_if(accounts.begin(), accounts.end(),
        [&](const shared_ptr<Account>& account) { return account->getIBAN() == iban; });

    return *it;
}

void Bank::closeAccount(shared_ptr<Account> account) {
    erase_if(accounts, [&](const shared_ptr<Account>& a) {return a->getId() == account->getId(); });
}
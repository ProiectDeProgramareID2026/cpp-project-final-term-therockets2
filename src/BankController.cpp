#include "../include/BankController.h"
#include "../include/Bank.h"
#include "../include/CurrentAccount.h"
#include "../include/SavingsAccount.h"
#include "../include/services/PrintService.h"
#include "../include/services/DepositService.h"
#include "../include/services/WithdrawService.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <memory>

using namespace std;

BankController::BankController(shared_ptr<Bank> bank) : bank(bank) {}

void BankController::addClient(const string& clientName) {
    if (bank->clientExists(clientName)) {
        cout << "Client already exists!" << endl;
        cout << "Client not added!" << endl;
        return;
    }

    auto newClient = make_shared<Client>(clientName);

    bank->addClient(newClient);
    cout << "New client added: " << newClient->toString() << endl;
}

void BankController::openAccount(const string& clientName, const string& accountType, const string& currency) {
    if (!bank->clientExists(clientName)) {
        cout << "Unable to find client ID " << clientName << endl;
        cout << "Account not added!" << endl;
        return;
    }

    shared_ptr<Account> newAccount;
    shared_ptr<Client> client = bank->getClient(clientName);

    if (accountType == "Current") {
        newAccount = make_shared<CurrentAccount>(CurrentAccount(client, currency, 0.5));
    }
    else if (accountType == "Savings") {
        newAccount = make_shared<SavingsAccount>(SavingsAccount(client, currency, 2.0));
    }
    else {
        cout << "Unknown account type!" << endl;
        cout << "Account not opened!" << endl;
        return;
    }
    
    bank->openAccount(newAccount);

    cout << "Successfully opened account " << newAccount->getIBAN() << " for " << client->getName() << endl;
}

void BankController::closeAccount(string clientName, string iban) {
    if (!bank->clientExists(clientName)) {
        cout << "Unable to find client ID " << clientName << endl;
        cout << "Account not closed!" << endl;
        return;
    }

    if (!bank->accountExists(iban)) {
        cout << "Unable to find account with IBAN " << iban << endl;
        cout << "Account not closed!" << endl;
        return;
    }

    shared_ptr<Account> account = bank->getAccount(iban);
    shared_ptr<Client> client = bank->getClient(clientName);

    if (account->getOwner() != client) {
        cout << "Invalid owner-account pair specified: " << clientName << "-" << iban << endl;
        return;
    }
    
    bank->closeAccount(account);

    cout << "Successfully closed account " << iban << endl;
}

//functie de adaugare fonduri cu verificare dupa numele clientului
void BankController::deposit(string clientName, string iban, double amount) {
    if (!bank->clientExists(clientName)) {
        cout << "Unable to find client: " << clientName << endl;
        return;
    }
    if (!bank->accountExists(iban)) {
        cout << "Unable to find account with IBAN: " << iban << endl;
        return;
    }

    shared_ptr<Account> account = bank->getAccount(iban);
    shared_ptr<Client> client = bank->getClient(clientName);

    if (account->getOwner() != client) {
        cout << "Account " << iban << " does not belong to " << clientName << endl;
        return;
    }

    depositService.deposit(account, amount);
}

//functie de extragere fonduri cu verificare dupa numele clientului.
void BankController::withdraw(string clientName, string iban, double amount) {
    if (!bank->clientExists(clientName)) {
        cout << "Unable to find client: " << clientName << endl;
        return;
    }
    if (!bank->accountExists(iban)) {
        cout << "Unable to find account with IBAN: " << iban << endl;
        return;
    }

    shared_ptr<Account> account = bank->getAccount(iban);
    shared_ptr<Client> client = bank->getClient(clientName);

    if (account->getOwner() != client) {
        cout << "Account " << iban << " does not belong to " << clientName << endl;
        return;
    }

    withdrawService.withdraw(account, amount);
}

void BankController::listAccounts(string clientName) {
    if (!bank->clientExists(clientName)) {
        cout << "Unable to find client: " << clientName << endl;
        return;
    }

    shared_ptr<Client> client = bank->getClient(clientName);
    vector<shared_ptr<Account>> clientAccounts;

    for (const auto& account : bank->getAccounts()) {
        if (account->getOwner()->getName() == clientName) {
            clientAccounts.push_back(account);
        }
    }

    printer.printClientAccounts(client, clientAccounts);
}

void BankController::showAccount(string iban) {
    if (!bank->accountExists(iban)) {
        cout << "Unable to find account with IBAN: " << iban << endl;
        return;
    }

    printer.printAccount(bank->getAccount(iban));
}

int BankController::readClients(string filepath) {
    cout << "Reading clients" << endl;
    ifstream file(filepath);
    if (!file.is_open()) {
        cerr << "Error: Could not open the file for reading: " << filepath << endl;
        return 1;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<std::string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 2) continue;

        int id = stoi(tokens[0]);
        string name = tokens[1];
        bank->addClient(make_shared<Client>(id, name));
    }

    return 0;
}

int BankController::readAccounts(string filepath) {
    cout << "Reading accounts" << endl;
    ifstream file(filepath);
    if (!file.is_open()) {
        cerr << "Error: Could not open the file for reading: " << filepath << endl;
        return 1;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<std::string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 7) continue;

        int id = stoi(tokens[0]);
        int ownerId = stoi(tokens[1]);
        string type = tokens[2];
        string iban = tokens[3];
        string currency = tokens[4];
        double balance = stod(tokens[5]);
        double accountSpecificTrait = stod(tokens[6]);

        bank->addAccount(id, ownerId, type, iban, currency, balance, accountSpecificTrait);
    }
    return 0;
}

int BankController::writeClients(string filepath) {
    cout << "Writing clients" << endl;
    ofstream file(filepath);
    if (!file.is_open()) {
        cerr << "Error: Could not open the file for writing: " << filepath << endl;
        return 1;
    }

    for (const auto& client : bank->getClients()) {
        file << client->toFileEntry() << endl;
    }

    return 0;
}

int BankController::writeAccounts(string filepath) {
    cout << "Writing accounts" << endl;
    ofstream file(filepath);
    if (!file.is_open()) {
        cerr << "Error: Could not open the file for writing: " << filepath << endl;
        return 1;
    }

    for (const auto& account : bank->getAccounts()) {
        file << account->toFileEntry() << endl;
    }

    return 0;
}
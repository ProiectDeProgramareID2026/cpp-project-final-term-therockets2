#pragma once
#include "../include/Client.h"
#include "../include/Account.h"
#include "../include/Transaction.h"

#include <vector>

class Bank {
    vector<shared_ptr<Account>> accounts;
    vector<shared_ptr<Client>> clients;
    vector<shared_ptr<Transaction>> transactions;

public:
    Bank();

    void openAccount(shared_ptr<Account>);
    void closeAccount(shared_ptr<Account>);
    void addAccount(int, int, string, string, string, double, double);

    bool clientExists(const string& name) const;
    bool clientExists(int id) const;
    bool accountExists(const string& iban) const;
    void addClient(shared_ptr<Client> client);
    vector<shared_ptr<Client>>& getClients();
    vector<shared_ptr<Account>>& getAccounts();
    shared_ptr<Client> getClient(const string& clientName);
    shared_ptr<Client> getClient(int id);
    shared_ptr<Account> getAccount(const string& iban);
};
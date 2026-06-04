//
// Created by razva on 5/27/2026.
//

#ifndef CPP_PROJECT_PLANNING_THEROCKETS_CLIENT_H
#define CPP_PROJECT_PLANNING_THEROCKETS_CLIENT_H

#include <memory>
#include <vector>

#include "Entity.h"

class Account;
class Bank;

class Client : public Entity{
private:
    string name;
    vector<weak_ptr<Account>> accounts;
    //weak_ptr<Bank> bank;
public:
    Client(string name);
    Client(int id, string name);
    ~Client() override = default;

    string getName() const;
    vector<weak_ptr<Account>> getAccounts() const;
    //weak_ptr<Bank> getBank() const;

    void addFunds(Account &account, double amount);

    void withDrawFunds(Account &account, double amount);

    void makePayement(double ammount, Account &account);

    string toString() const override;
    string toFileEntry() const override;
};

#endif //CPP_PROJECT_PLANNING_THEROCKETS_CLIENT_H

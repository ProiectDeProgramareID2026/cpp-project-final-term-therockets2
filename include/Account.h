//
// Created by razva on 5/26/2026.
//

#ifndef CPP_PROJECT_PLANNING_THEROCKETS_ACCOUNT_H
#define CPP_PROJECT_PLANNING_THEROCKETS_ACCOUNT_H

#include "Entity.h"

#include <string>
#include <memory>

using namespace std;

class Client;

class Account : public Entity{
private:
    weak_ptr<Client> owner;
    string IBAN, currency;
    double balance;
public:
    Account(weak_ptr<Client> owner, string IBAN, string currency, double balance);
    virtual ~Account() = default;
    weak_ptr<Client> getOwner() const;
    string getIBAN() const;
    double getBalance() const;
    string getCurrency() const;

    void addFunds(double amount);
    void withdrawFunds(double amount);

    virtual string toString() const;
    virtual string toFileEntry() const = 0;
};


#endif //CPP_PROJECT_PLANNING_THEROCKETS_ACCOUNT_H

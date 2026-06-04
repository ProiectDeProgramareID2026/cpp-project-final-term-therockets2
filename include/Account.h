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
    shared_ptr<Client> owner;
    string IBAN, currency;
    double balance;
    inline static int IBANID = 0;
public:
    Account(shared_ptr<Client> owner, const string& currency);
    Account(int id, shared_ptr<Client> owner, const string& currency, const string& iban, double balance);
    virtual ~Account() = default;
    shared_ptr<Client> getOwner() const;
    string getIBAN() const;
    double getBalance() const;
    string getCurrency() const;

    void addFunds(double amount);
    void withdrawFunds(double amount);

    virtual string toString() const;
    virtual string toFileEntry() const = 0;
};


#endif //CPP_PROJECT_PLANNING_THEROCKETS_ACCOUNT_H

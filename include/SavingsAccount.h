//
// Created by razva on 5/31/2026.
//

#ifndef CPP_PROJECT_PLANNING_THEROCKETS_SAVINGSACCOUNT_H
#define CPP_PROJECT_PLANNING_THEROCKETS_SAVINGSACCOUNT_H
#include "Account.h"


class SavingsAccount : public Account{
private:
    double interestRate;
public:
    SavingsAccount(shared_ptr<Client> owner, const string& currency, double interestRate);
    SavingsAccount(int id, shared_ptr<Client> owner, const string& iban, const string& currency, double balance, double interestRate);
    ~SavingsAccount();

    double getInterestRate() const;
    string toString() const override;
    string toFileEntry() const override;
};


#endif //CPP_PROJECT_PLANNING_THEROCKETS_SAVINGSACCOUNT_H

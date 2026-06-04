//
// Created by razva on 5/31/2026.
//

#ifndef CPP_PROJECT_PLANNING_THEROCKETS_CURRENTACCOUNT_H
#define CPP_PROJECT_PLANNING_THEROCKETS_CURRENTACCOUNT_H
#include "Account.h"
#include <string>


class CurrentAccount : public Account{
private:
    double managementFee;
public:
    CurrentAccount(shared_ptr<Client> owner, const string& currency, double managementFee);
    CurrentAccount(int id, shared_ptr<Client> owner, const string& iban, const string& currency, double balance, double managementFee);
    ~CurrentAccount();

    double getManagementFee() const;

    string getType() const override;
    string toString() const override;
    string toFileEntry() const override;
};


#endif //CPP_PROJECT_PLANNING_THEROCKETS_CURRENTACCOUNT_H

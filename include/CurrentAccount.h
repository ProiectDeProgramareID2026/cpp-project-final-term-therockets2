//
// Created by razva on 5/31/2026.
//

#ifndef CPP_PROJECT_PLANNING_THEROCKETS_CURRENTACCOUNT_H
#define CPP_PROJECT_PLANNING_THEROCKETS_CURRENTACCOUNT_H
#include "Account.h"


class CurrentAccount : public Account{
private:
    double managementFee;
public:
    CurrentAccount(const weak_ptr<Client>& owner, string IBAN, string currency, double balance, double managementFee);
    ~CurrentAccount();

    double getManagementFee() const;

    string toString() const override;
    string toFileEntry() const override;
};


#endif //CPP_PROJECT_PLANNING_THEROCKETS_CURRENTACCOUNT_H

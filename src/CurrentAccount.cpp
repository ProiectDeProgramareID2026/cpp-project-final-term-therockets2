//
// Created by razva on 5/31/2026.
//

#include "../include/CurrentAccount.h"
#include "../include/Client.h"

CurrentAccount::CurrentAccount(const weak_ptr<Client>& owner,
    string IBAN,
    string currency,
    double balance,
    double managementFee) : Account(owner, IBAN, currency, balance){
        this->managementFee = managementFee;
    }

CurrentAccount::~CurrentAccount()= default;

double CurrentAccount::getManagementFee() const {
    return managementFee;
}

string CurrentAccount::toString() const {
    return Account::toString() +  "| Type: Current |Fee: " + to_string(managementFee);
}

string CurrentAccount::toFileEntry() const {
    string ownerId = "0";
    if (auto client = getOwner().lock()) {
        ownerId = to_string(client->getId());
    }
    return ownerId + ","
    + getIBAN() + "," + to_string(getBalance()) + "," + getCurrency()
    + "," + to_string(managementFee);
}

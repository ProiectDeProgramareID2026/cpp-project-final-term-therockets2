//
// Created by razva on 5/31/2026.
//

#include "../include/CurrentAccount.h"
#include "../include/Client.h"

CurrentAccount::CurrentAccount(shared_ptr<Client> owner, const string& currency, double managementFee) : Account(owner, currency){
        this->managementFee = managementFee;
    }
CurrentAccount::CurrentAccount(int id, shared_ptr<Client> owner, const string& iban, const string& currency, double balance, double managementFee) : Account(id, owner, currency, iban, balance){
        this->managementFee = managementFee;
    }

CurrentAccount::~CurrentAccount()= default;

double CurrentAccount::getManagementFee() const {
    return managementFee;
}

string CurrentAccount::toString() const {
    return Account::toString() +  "| Type: Current | Fee: " + to_string(managementFee);
}

string CurrentAccount::toFileEntry() const {
    return to_string(getId()) + "," + to_string(getOwner()->getId()) + "," + "Current" + ","
    + getIBAN() + "," + getCurrency() + "," + to_string(getBalance())
    + "," + to_string(managementFee);
}

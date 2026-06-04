//
// Created by razva on 5/31/2026.
//

#include "../include/SavingsAccount.h"
#include "../include/Client.h"

SavingsAccount::SavingsAccount(shared_ptr<Client> owner, const string& currency, double interestRate) : Account(owner, currency){
    this->interestRate = interestRate;
}
SavingsAccount::SavingsAccount(int id, shared_ptr<Client> owner, const string& iban, const string& currency, double balance, double interestRate) : Account(id, owner, currency, iban, balance){
    this->interestRate = interestRate;
}

SavingsAccount::~SavingsAccount() = default;

double SavingsAccount::getInterestRate() const {
    return interestRate;
}

string SavingsAccount::toString() const {
    return Account::toString() +  "| Type: Savings | Interest: " + to_string(interestRate);
}

string SavingsAccount::toFileEntry() const {
    return to_string(getId()) + "," + to_string(getOwner()->getId()) + "," + "Savings" + ","
    + getIBAN() + "," + getCurrency() + "," + to_string(getBalance())
    + "," + to_string(interestRate);
}

//
// Created by razva on 5/31/2026.
//

#include "../include/SavingsAccount.h"
#include "../include/Client.h"

SavingsAccount::SavingsAccount(weak_ptr<Client> owner,
    string IBAN,
    string currency,
    double balance,
    double interestRate) : Account(owner, IBAN, currency, balance){
this->interestRate = interestRate;
}

SavingsAccount::~SavingsAccount() = default;

double SavingsAccount::getInterestRate() const {
    return interestRate;
}

string SavingsAccount::toString() const {
    return Account::toString() +  "| Type: Savings |Interest: " + to_string(interestRate);
}

string SavingsAccount::toFileEntry() const {
    string ownerId = "0";
    if (auto client = getOwner().lock()) {
        ownerId = to_string(client->getId());
    }
    return ownerId + ","
    + getIBAN() + "," + to_string(getBalance()) + "," + getCurrency()
    + "," + to_string(interestRate);
}

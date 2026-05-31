//
// Created by razva on 5/26/2026.
//

#include "../include/Account.h"
#include "../include/Client.h"

#include <string>

using namespace std;

Account::Account(weak_ptr<Client> owner, string IBAN, string currency, double balance)
    : Entity(){
    this->owner = owner;
    this->IBAN = IBAN;
    this-> currency = currency;
    this->balance = balance;
}

weak_ptr<Client> Account::getOwner() const {return owner;}
string Account::getIBAN() const {return IBAN;}
double Account::getBalance() const {return balance;}
string Account::getCurrency() const {return currency;}

void Account::addFunds(double amount){
    if (amount < 0) {
        throw runtime_error("Suma introdusa nu poate fi negativa!");
    }
    balance += amount;
}
void Account::withdrawFunds(double amount){
    if (amount < 0) {
        throw runtime_error("Suma introdusa nu poate fi negativa!");
    }
    if (amount > balance) {
        throw runtime_error("Fonduri insuficiente");
    }
    balance -= amount;
}

string Account::toString() const {
    return "Account #" + to_string(getId())
        + " | IBAN: " + IBAN
        + " | Balance: " + to_string(balance)
        + " " + currency;
}


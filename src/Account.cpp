//
// Created by razva on 5/26/2026.
//

#include "../include/Account.h"
#include "../include/Client.h"

#include <string>
#include <stdexcept>

using namespace std;

Account::Account(shared_ptr<Client> owner, const string& currency)
    : Entity(){
    this->owner = owner;
    this->currency = currency;
    this->IBAN = "IBAN" + to_string(getId());
    this->balance = 0.0;
}
Account::Account(int id, shared_ptr<Client> owner, const string& currency, const string& iban, double balance)
    : Entity(id){
    this->owner = owner;
    this->currency = currency;
    this->IBAN = iban;
    this->balance = balance;
}

shared_ptr<Client> Account::getOwner() const {return owner;}
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


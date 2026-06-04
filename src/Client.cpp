//
// Created by razva on 5/27/2026.
//

#include "../include/Account.h"
#include "../include/Client.h"
#include "../include/Bank.h"

#include <stdexcept>

Client::Client(string name)
        : Entity(){
    this->name = name;
}

Client::Client(int id, string name)
        : Entity(id){
    this->name = name;
}

string Client::getName() const{
    return name;
}
vector<weak_ptr<Account>> Client::getAccounts() const{
    return accounts;
}
//weak_ptr<Bank> Client::getBank() const{
//    return bank;
//}

//void Client::addFunds(Account &account, double amount) {
//    if (amount < 0) {
//        throw runtime_error("Suma introdusa nu poate fi negativa!");
//    }
//
//    if (auto owner = account.getOwner().lock()) {
//        if (owner.get() != this) {
//            throw runtime_error("Contul nu apartine acestui client");
//        }
//    }else {
//        throw runtime_error("Contul nu are proprietar");
//    }
//
//    if (auto b = bank.lock()) {
//        //b->addFunds(account, amount);
//    }else {
//        throw runtime_error("Banca nu este disponibile, reveniti");
//    }
//}

//void Client::withDrawFunds(Account &account, double amount) {
//    if (amount < 0) {
//        throw runtime_error("Suma introdusa nu poate fi negativa!");
//    }
//
//    if (auto owner = account.getOwner().lock()) {
//        if (owner.get() != this) {
//            throw runtime_error("Contul nu apartine acestui client");
//        }
//    }else {
//        throw runtime_error("Contul nu are proprietar");
//    }
//
//    if (auto b = bank.lock()) {
//        //b->withdrawFunds(account, amount);
//    }else {
//        throw runtime_error("Banca nu este disponibile, reveniti");
//    }
//}
//
//void Client::makePayement(double ammount, Account &account){
//
//}

string Client::toString() const{
    return "Client #" + to_string(getId())
    + " | Name: " + name + " | Accounts: "
    + to_string(accounts.size()) ;
}
string Client::toFileEntry() const {
    return to_string(getId()) + "," + name;
}
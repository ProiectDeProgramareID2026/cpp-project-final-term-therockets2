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

string Client::toString() const{
    return "Client #" + to_string(getId())
        + " | Name: " + name;
}
string Client::toFileEntry() const {
    return to_string(getId()) + "," + name;
}
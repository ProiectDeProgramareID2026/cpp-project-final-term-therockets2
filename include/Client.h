//
// Created by razva on 5/27/2026.
//

#ifndef CPP_PROJECT_PLANNING_THEROCKETS_CLIENT_H
#define CPP_PROJECT_PLANNING_THEROCKETS_CLIENT_H

#include <memory>
#include <vector>

#include "Entity.h"

class Account;
class Bank;

class Client : public Entity{
private:
    string name;
public:
    Client(string name);
    Client(int id, string name);
    ~Client() override = default;

    string getName() const;

    string toString() const override;
    string toFileEntry() const override;
};

#endif //CPP_PROJECT_PLANNING_THEROCKETS_CLIENT_H

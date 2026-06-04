#pragma once
#include "../Account.h"
#include "../Client.h"

#include <vector>
#include <memory>

using namespace std;

class PrintService {
public:
    void printClientAccounts(shared_ptr<Client> client, const vector<shared_ptr<Account>>& accounts) const;
    void printAccount(shared_ptr<Account> account) const;
};

#pragma once
#include "../Account.h"
#include <memory>

using namespace std;

class DepositService {
public:
    bool deposit(shared_ptr<Account> account, double amount) const;
};

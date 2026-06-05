#pragma once
#include "../Account.h"
#include <memory>

using namespace std;

class WithdrawService {
public:
    bool withdraw(shared_ptr<Account> account, double amount) const;
};

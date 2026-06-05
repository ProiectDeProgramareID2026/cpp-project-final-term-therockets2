#include "../../include/services/DepositService.h"
#include <iostream>
#include <iomanip>

using namespace std;

bool DepositService::deposit(shared_ptr<Account> account, double amount) const {
    if (amount < 0.01) {
        cout << "Deposit failed: minimum amount is 0.01." << endl;
        return false;
    }

    account->addFunds(amount);

    cout << fixed << setprecision(2);
    cout << "Deposited " << amount << " " << account->getCurrency()
         << " into " << account->getIBAN()
         << ". New balance: " << account->getBalance()
         << " " << account->getCurrency() << endl;

    return true;
}

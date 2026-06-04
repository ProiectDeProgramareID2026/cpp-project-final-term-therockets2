#include "../../include/services/WithdrawService.h"
#include <iostream>
#include <iomanip>

using namespace std;

bool WithdrawService::withdraw(shared_ptr<Account> account, double amount) const {
    if (amount < 0.01) {
        cout << "Withdrawal failed: minimum amount is 0.01." << endl;
        return false;
    }

    if (amount > account->getBalance()) {
        cout << fixed << setprecision(2);
        cout << "Withdrawal failed: insufficient funds. Balance: "
             << account->getBalance() << " " << account->getCurrency() << endl;
        return false;
    }

    account->withdrawFunds(amount);

    cout << fixed << setprecision(2);
    cout << "Withdrew " << amount << " " << account->getCurrency()
         << " from " << account->getIBAN()
         << ". New balance: " << account->getBalance()
         << " " << account->getCurrency() << endl;

    return true;
}

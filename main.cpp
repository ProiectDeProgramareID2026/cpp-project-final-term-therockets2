#include "include/Bank.h"
#include "include/BankController.h"
#include "include/CLICMD.h"
#include "include/Utils.h"

#include <iostream>
#include <memory>
#include <map>
#include <functional>


using namespace std;

int main(int argc, char** argv) {

    shared_ptr<Bank> bank = make_shared<Bank>();
    BankController bctrl(bank);

    CLICMD cmd;
    cmd.parse_args(argc, argv);

    if (!cmd.valid) {
        cout << "Invalid command! See tool usage:" << endl;
        // print menu
        return 0;
    }

    bctrl.readClients();
    bctrl.readAccounts();

    if(cmd.action == "--add-client") {
        if (!meetsMinimumArgsCriteria(cmd.values, 1)) return 0;
        const string& clientName = cmd.values[0];
        bctrl.addClient(clientName);
    }
    else if (cmd.action == "--open-account") {
        if (!meetsMinimumArgsCriteria(cmd.values, 3)) return 0;
        const string& clientName = cmd.values[0];
        const string& accountType = cmd.values[1];
        const string& accountCurrency = cmd.values[2];
        bctrl.openAccount(clientName, accountType, accountCurrency);
    }
    else if (cmd.action == "--close-account") {
        if (!meetsMinimumArgsCriteria(cmd.values, 2)) return 0;
        const string& clientName = cmd.values[0];
        const string& iban = cmd.values[1];
        bctrl.closeAccount(clientName, iban);
    }
    else {
        cout << "Unknown command: " << "\"" << cmd.action << "\"" << endl;
    }

    bctrl.writeClients();
    bctrl.writeAccounts();

    return 0;
}

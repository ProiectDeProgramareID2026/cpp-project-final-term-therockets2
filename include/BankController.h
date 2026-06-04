#pragma once
#include "Bank.h"
#include "services/PrintService.h"

class BankController {
	shared_ptr<Bank> bank;
	PrintService printer;
public:
	BankController(shared_ptr<Bank>);

	/// <summary>
	/// Adds a new client to the bank
	/// </summary>
	/// <param name="clientName">Name of the client to be added</param>
	/// <returns>void</returns>
	void addClient(const string&);

	/// <summary>
	/// Opens account of given type and currency for given client
	/// </summary>
	/// <param name="clientName">Name of the client that will be the owner of the account</param>
	/// <param name="accountType">Type of the account. Either Current or Savings</param>
	/// <param name="currency">Account currency. Either RON or EUR</param>
	/// <returns>void</returns>
	void openAccount(const string&, const string&, const string&);

	void closeAccount(string, string);
	void deposit(string, string, double);
	void withdraw(string, string, double);
	void transfer(string);
	void listAccounts(string clientName);
	void showAccount(string iban);

	int readClients(string = "data/clients.csv");
	int readAccounts(string = "data/accounts.csv");
	int readTransactions(string = "data/transactions.csv");

	int writeClients(string = "data/clients.csv");
	int writeAccounts(string = "data/accounts.csv");
	int writeTransactions(string = "data/transactions.csv");
};
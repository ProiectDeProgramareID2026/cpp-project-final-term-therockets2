#pragma once
#include "Bank.h"
#include "services/PrintService.h"
#include "services/DepositService.h"
#include "services/WithdrawService.h"

class BankController {
	shared_ptr<Bank> bank;
	PrintService printer;
	DepositService depositService;
	WithdrawService withdrawService;
public:
	BankController(shared_ptr<Bank>);

	/// <summary>
	/// Adds a new client to the bank
	/// </summary>
	/// <param name="clientName">Name of the client</param>
	/// <returns>void</returns>
	void addClient(const string&);

	/// <summary>
	/// Opens account of given type and currency for given client
	/// </summary>
	/// <param name="clientName">Name of the client - account ownert</param>
	/// <param name="accountType">Type of the account. Either Current or Savings</param>
	/// <param name="currency">Account currency. Either RON or EUR</param>
	/// <returns>void</returns>
	void openAccount(const string&, const string&, const string&);

	/// <summary>
	/// Closes account of given client, if client is owner
	/// </summary>
	/// <param name="clientName">Name of the client </param>
	/// <param name="iban">Iban of the account</param>
	/// <returns>void</returns>
	void closeAccount(string, string);

	/// <summary>
	/// Deposits money in account
	/// </summary>
	/// <param name="clientName">Name of the client</param>
	/// <param name="iban">Iban of the account</param>
	/// <param name="amount">Amount of currency</param>
	/// <returns>void</returns>
	void deposit(string, string, double);

	/// <summary>
	/// Withdraws money from account
	/// </summary>
	/// <param name="clientName">Name of the clientt</param>
	/// <param name="iban">Iban of the account</param>
	/// <param name="amount">Amount of currency</param>
	/// <returns>void</returns>
	void withdraw(string, string, double);

	/// <summary>
	/// Lists accounts for a client
	/// </summary>
	/// <param name="clientName">Name of the clientt</param>
	/// <returns>void</returns>
	void listAccounts(string);

	/// <summary>
	/// Lists details of an account
	/// </summary>
	/// <param name="iban">Iban of the account</param>
	/// <returns>void</returns>
	void showAccount(string);

	int readClients(string = "data/clients.csv");
	int readAccounts(string = "data/accounts.csv");

	int writeClients(string = "data/clients.csv");
	int writeAccounts(string = "data/accounts.csv");
};
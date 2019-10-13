/*
 * Bank.cpp
 */

#include "Bank.h"
#include <algorithm>
#include <string>

Bank::Bank() {}

void Bank::addAccount(Account *a) {
	accounts.push_back(a);
}

void Bank::addBankOfficer(BankOfficer b){
	bankOfficers.push_back(b);
}

vector<BankOfficer> Bank::getBankOfficers() const {
	return bankOfficers;
}

vector<Account *> Bank::getAccounts() const {
	return accounts;
}


// ----------------------------------------------------------------------------------------------

// a alterar
double Bank::getWithdraw(string cod1) const{
    unsigned int totalAmount = 0;
    for (int i = 0; i < accounts.size(); ++i) {
        if(accounts.at(i)->codeHolder == cod1)
            totalAmount += balance;
        else
            continue;
    }
    return totalAmount;
}


// a alterar
vector<Account *> Bank::removeBankOfficer(string name){
    for (int i = 0; i < bankOfficers.size() ; ++i) {
        if(bankOfficers.at(i).name == name){
            return bankOfficers.at(i).myAccounts;
        }
        else
            continue;
    }
    return vector<Account *>v;
}


// a alterar
const BankOfficer & Bank::addAccountToBankOfficer(Account *ac, string name) {
}


// a alterar
void Bank::sortAccounts() {
}


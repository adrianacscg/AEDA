/*
 * Bank.cpp
 */

#include "Bank.h"
#include <algorithm>
#include <string>
#include <vector>

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
    unsigned int montante = 0;
	for(int i = 0; i < accounts.size(); i++ ){
	    if(accounts.at(i)->getCodH() == cod1)
	        montante += accounts.at(i)->getWithdraw();
	}
	return montante;
}


// a alterar
vector<Account *> Bank::removeBankOfficer(string name){
    for(auto i = 0; i < bankOfficers.size(); i++){
        if(bankOfficers.at(i).getName()==name){
            bankOfficers.erase(bankOfficers.begin(), bankOfficers.begin()+i);
            return bankOfficers.at(i).getAccounts();
        }
    }
    vector<Account*> empty;
    return empty;

}


// a alterar
const BankOfficer & Bank::addAccountToBankOfficer(Account *ac, string name) {
    BankOfficer *bo= new BankOfficer();
    return *bo;
}


// a alterar
void Bank::sortAccounts() {
}


/*
 * BankOfficer.cpp
 */
#include "BankOfficer.h"


BankOfficer::BankOfficer(): id(0) {}

void BankOfficer::setName(string nm){
	name = nm;
}

string BankOfficer::getName() const{
	return name;
}

vector<Account *> BankOfficer::getAccounts() const {
	return myAccounts;
}

void BankOfficer::addAccount(Account *a) {
	myAccounts.push_back(a);
}

unsigned int BankOfficer::getID() const{
	return id;
}


// ----------------------------------------------------------------------------------------------

// a alterar
int BankOfficer::counter = 0;

BankOfficer::BankOfficer(string name) {
    this->name = name;
    vector<Account*> myAccounts;
    id = ++counter;
}

const bool BankOfficer::operator>(BankOfficer &b1) {
    if(this->getAccounts().size() > b1.getAccounts().size())
        return true;
    else if(this->getAccounts().size() == b1.getAccounts().size())
        if(this->getName()>b1.getName())
            return true;
    return false;
}





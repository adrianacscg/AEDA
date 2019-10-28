/*
 * BankOfficer.h
 */

#ifndef SRC_BANKOFFICER_H_
#define SRC_BANKOFFICER_H_

#include "Account.h"
#include <string>
#include <vector>

class BankOfficer {
	unsigned int id;
	string name;
	vector<Account *> myAccounts;
	static int counter;
public:
	BankOfficer();
	void setName(string nm);
	void addAccount(Account *a);
	void addAccount(vector<Account *> accounts);
	string getName() const;
	vector<Account *> getAccounts() const;
	unsigned int getID() const;
	const bool operator>(BankOfficer & b1);


	//-------
	BankOfficer(string nm);

};

template <class T>
unsigned int numberDifferent(const vector<T> &v1) {

    vector<T> elementos;

    for(auto item : v1){
        bool flag = false;
        for(auto element : elementos){
            if(element == item){
                flag = true;
                break;
            }
            else
                continue;

        }

        if(!flag) elementos.push_back(item);
    }
    return elementos.size();
};

#endif /* SRC_BANKOFFICER_H_ */

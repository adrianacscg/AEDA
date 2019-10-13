#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "Account.h"
#include "Bank.h"
#include <vector>
#include <string>
#include "BankOfficer.h"
using namespace std;

void test_a() {
/*	vector<int> v1;
	v1.push_back(10); v1.push_back(8);
	v1.push_back(12);
	ASSERT_EQUAL(3, numberDifferent(v1));
	vector<string> v2;
	ASSERT_EQUAL(0, numberDifferent(v2));
	v2.push_back("mar"); v2.push_back("rio");
	ASSERT_EQUAL(2, numberDifferent(v2));
	v2.push_back("sol"); v2.push_back("rio");
	v2.push_back("sol");
	ASSERT_EQUAL(3, numberDifferent(v2));*/
}

void test_b() {
	CheckingAccount c1("manuel", "bi123","PT311", 200.0, 500.0);
	CheckingAccount c2("manuel", "bi123","PT311", 200.0, 800.0);
	CheckingAccount c3("manuel", "bi123","PT311", 200.0, 5000.0);
	SavingsAccount c4("ana", "bi567","PT115", 0.0, 1.9);
	SavingsAccount c5("ana", "bi567","PT115", 0.0, 2.1);

	ASSERT_EQUAL(0.5, c1.getCharge());
	ASSERT_EQUAL(0.25, c2.getCharge());
	ASSERT_EQUAL(0.0, c3.getCharge());
	ASSERT_EQUAL(0.0, c4.getCharge());
	ASSERT_EQUAL(0.8, c5.getCharge());
}

void test_c() {
	/*string codH1= "bi123";
	string codH2= "bi444";
	Account *d1 = new SavingsAccount("ana", codH1,"PT411", 200.0, 2.0);
	Account *d2 = new TimeAccount("ana", codH1,"PT412", 500.0, 5.0);
	Account *d3 = new CheckingAccount("joao", codH2,"PT312", 350.0,1000.0);
	ASSERT_EQUAL_DELTA(200.0, d1->getWithdraw(),0.01);
	ASSERT_EQUAL_DELTA(25.0, d2->getWithdraw(),0.01);
	ASSERT_EQUAL_DELTA(350.0, d3->getWithdraw(),0.01);

	Bank ba;
	ba.addAccount(d1);
	ba.addAccount(d2);
	ba.addAccount(d3);

	ASSERT_EQUAL_DELTA(225.0,ba.getWithdraw(codH1),0.01);
	ASSERT_EQUAL_DELTA(350.0,ba.getWithdraw(codH2),0.01);
	ASSERT_EQUAL_DELTA(0.0,ba.getWithdraw("XYZ"),0.01);

	ba.addAccount(new TimeAccount("ana", codH1,"PT413", 1000.0, 5.0));
	ASSERT_EQUAL_DELTA(275.0,ba.getWithdraw(codH1),0.01);*/
}

void test_d() {
	/*Bank ba;
	BankOfficer b1;
	b1.setName("joao");
	b1.addAccount(new SavingsAccount("luis", "bi123","PT111", 0.0, 2.0));
	BankOfficer b2;
	b2.setName("paulo");
	b2.addAccount(new SavingsAccount("maria", "bi234","PT112", 0.0, 2.0));
	b2.addAccount(new SavingsAccount("joaquim", "bi345","PT113", 0.0, 2.0));
	b2.addAccount(new SavingsAccount("manuel", "bi456","PT114", 0.0, 2.0));
	b2.addAccount(new SavingsAccount("ana", "bi567","PT115", 0.0, 2.0));
	BankOfficer b3;
	b3.setName("fernando");
	b3.addAccount(new SavingsAccount("carmo", "bi678","PT116", 0.0, 2.0));
	ba.addBankOfficer(b1);
	ba.addBankOfficer(b2);
	ba.addBankOfficer(b3);

	vector <Account *> accountB = ba.removeBankOfficer("joao");
	ASSERT_EQUAL(1, accountB.size());
	ASSERT_EQUAL(2,ba.getBankOfficers().size());

	accountB.clear();
	accountB = ba.removeBankOfficer("sergio");
	ASSERT_EQUAL(0, accountB.size());

	accountB.clear();
	accountB = ba.removeBankOfficer("paulo");
	ASSERT_EQUAL(4, accountB.size());

	accountB.clear();
	accountB = ba.removeBankOfficer("fernando");
	ASSERT_EQUAL(1, accountB.size());

	ASSERT_EQUAL(0,ba.getBankOfficers().size());*/
}

void test_e() {
	/*BankOfficer b1("joao");
	BankOfficer b2("rui");
	BankOfficer b3("paulo");
	BankOfficer b4("maria");

	ASSERT_EQUAL(1, b1.getID());
	ASSERT_EQUAL(2, b2.getID());
	ASSERT_EQUAL(3, b3.getID());
	ASSERT_EQUAL(4, b4.getID());*/
}

void test_f() {
/*	BankOfficer b1;
	b1. setName("joao");
	b1.addAccount(new CheckingAccount("rui", "bi123","PT611", 200.0, 500.0));
	b1.addAccount(new SavingsAccount("rui", "bi123","PT612", 500000, 2.0));
	b1.addAccount(new TimeAccount("rui", "bi123","PT613", 0.0, 3.0));

	BankOfficer b2;
	b2. setName("paulo");
	b2.addAccount(new SavingsAccount("ana", "bi234","PT621", 500000, 2.0));
	b2.addAccount(new SavingsAccount("maria", "bi345","PT622", 100000, 1.5));

	ASSERT_EQUAL(true, b1>b2);
	ASSERT_EQUAL(false, b2>b1);

	b2.addAccount(new SavingsAccount("manuel", "bi456","PT623", 10000, 1.9));
	ASSERT_EQUAL(true, b2>b1);
	ASSERT_EQUAL(false, b1>b2);

	BankOfficer b3;
	b3. setName("rui");

	ASSERT_EQUAL(true, b2>b3);
	ASSERT_EQUAL(false, b3>b1);*/
}

void test_g() {
	/*Bank ba;
	BankOfficer b1;
	b1. setName("joao");
	b1.addAccount(new CheckingAccount("rui", "bi123","PT711", 200.0, 500.0));
	b1.addAccount(new CheckingAccount("francisca", "bi234","PT712", 200.0, 500.0));
	BankOfficer b2;
	b2. setName("paulo");
	BankOfficer b3;
	b3.setName("fernando");
	b3.addAccount(new SavingsAccount("manuel", "bi345","PT731", 10000, 1.9));

	ba.addBankOfficer(b1);
	ba.addBankOfficer(b2);
	ba.addBankOfficer(b3);

	Account *ac1;
	vector<Account *> accounts;
	ac1= new CheckingAccount("maria", "bi456","PT721", 200.0, 500.0);

	BankOfficer bx = ba.addAccountToBankOfficer(ac1,"paulo");
	accounts = bx.getAccounts();
	ASSERT_EQUAL(1,accounts.size());
	ASSERT_EQUAL("bi456",accounts[0]->getCodH());

	ac1 = new CheckingAccount("maria", "bi456","PT741", 200.0, 500.0);
	ASSERT_THROWS(ba.addAccountToBankOfficer(ac1,"luis"), NoBankOfficerException);

	try {
		ac1 = new SavingsAccount("maria", "bi567","PT713", 10000, 1.9);
		bx = ba.addAccountToBankOfficer(ac1,"joao");
		ASSERT_EQUAL(3,bx.getAccounts().size());
		ac1 = new SavingsAccount("maria", "bi567","PT751", 10000, 1.9);
		bx = ba.addAccountToBankOfficer(ac1,"ricardo");
	}
	catch(NoBankOfficerException &e) {
		ASSERT_EQUAL("ricardo", e.getName());
	}

	new CheckingAccount("rui", "bi678","PT732", 200.0, 500.0);
	bx = ba.addAccountToBankOfficer(ac1,"fernando");
	ASSERT_EQUAL(2,bx.getAccounts().size());*/
}


void test_h() {
	/*Bank ba;
	ba.addAccount(new CheckingAccount("rui", "bi123","PT714", 200.0, 500.0));
	ba.addAccount(new CheckingAccount("francisca", "bi234","PT712", 200.0, 500.0));

	ba.sortAccounts();
	ASSERT_EQUAL(2,ba.getAccounts().size());
	ASSERT_EQUAL("PT712",ba.getAccounts()[0]->getCodIBAN());

	ba.addAccount(new SavingsAccount("manuel", "bi345","PT731", 100, 1.9));
	ba.addAccount(new CheckingAccount("maria", "bi456","PT721", 700.0, 500.0));
	ba.addAccount(new CheckingAccount("maria", "bi456","PT741", 500.0, 500.0));
	ba.addAccount(new SavingsAccount("maria", "bi456","PT713", 500, 1.9));
	ba.addAccount(new SavingsAccount("maria", "bi456","PT751", 1200, 1.9));

	ba.sortAccounts();
	ASSERT_EQUAL(7,ba.getAccounts().size());
	ASSERT_EQUAL("PT731",ba.getAccounts()[0]->getCodIBAN());
	ASSERT_EQUAL("PT713",ba.getAccounts()[3]->getCodIBAN());
	ASSERT_EQUAL("PT741",ba.getAccounts()[4]->getCodIBAN());
	ASSERT_EQUAL("PT751",ba.getAccounts()[6]->getCodIBAN());*/
}

void runSuite(){
	cute::suite s;
	s.push_back(CUTE(test_a));
	s.push_back(CUTE(test_b));
	s.push_back(CUTE(test_c));
	s.push_back(CUTE(test_d));
	s.push_back(CUTE(test_e));
	s.push_back(CUTE(test_f));
	s.push_back(CUTE(test_g));
	s.push_back(CUTE(test_h));
	cute::ide_listener<> lis;
	cute::makeRunner(lis)(s, "AEDA 2018/2019 - Componente Individual 1 - Testes Unitarios Estudantes");
}

int main(){
    runSuite();
    return 0;
}


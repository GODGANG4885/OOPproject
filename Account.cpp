#include"BankingCommonDec1.h"
#include "Account.h"

Account::Account(int ID, int money, String name) :AccID(ID), balance(money) {
	//cusName = new char[strlen(name) + 1];
	//strcpy(cusName, name);
	cusName = name;
}
/* Account::Account(const Account& ref) :AccID(ref.AccID), balance(ref.balance) {
		cusName = new char[strlen(ref.cusName) + 1];
		strcpy(cusName, ref.cusName);
	}*/
int Account::GetAccID() const {
		return AccID;
	}
String Account::NameInfo() const {
		return cusName;
	}
/*Account::~Account() {
		delete[] cusName;
	}*/
void Account::Deposit(int money) {
		balance += money;
	}
int Account::Withdraw(int money) { //출금액 반환, 부족시 0반환 
	
	try {
		if (balance < money)
			throw money;
		balance -= money;
	}
	catch(int expn)
	{
		cout << "잔액이 부족합니다" << endl;
		return 0;
	}
	return money;
}
void Account::ShowInfo() const {
		cout << "계좌 ID : " << AccID << endl;
		cout << "이름 : " << cusName << endl;
		cout << "잔액 : " << balance << endl;
	}
#include"BankingCommonDec1.h"
#include "Account.h"

Account::Account(int ID, int money, char * name) :AccID(ID), balance(money) {
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}
Account::Account(const Account& ref) :AccID(ref.AccID), balance(ref.balance) {
		cusName = new char[strlen(ref.cusName) + 1];
		strcpy(cusName, ref.cusName);
	}
int Account::GetAccID() const {
		return AccID;
	}
char* Account::NameInfo() const {
		return cusName;
	}
Account::~Account() {
		delete[] cusName;
	}
void Account::Deposit(int money) {
		balance += money;
	}
int Account::Withdraw(int money) { //��ݾ� ��ȯ, ������ 0��ȯ 
		if (balance < money) {

			return 0;
		}
		balance -= money;
		return money;
	}
void Account::ShowInfo() const {
		cout << "���� ID : " << AccID << endl;
		cout << "�̸� : " << cusName << endl;
		cout << "�ܾ� : " << balance << endl;
	}
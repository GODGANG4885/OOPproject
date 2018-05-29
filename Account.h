#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include "String.h"
class Account {
private:
	int AccID;
	String cusName;//char * cusName;
	int balance;
public:
	Account(int ID, int money, String name);
	//Account(int ID, int money, char * name) ;
	
	//Account(const Account& ref);
	int GetAccID() const;
	String NameInfo() const;
	//~Account();
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowInfo() const;
};
#endif __ACCOUNT_H__
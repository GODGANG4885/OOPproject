#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__
#include "Account.h"
class AccountHandler {
private:
	Account * accArr[100];
	int Accnum = 0;
public:
	AccountHandler();
	void CreateAccount();
	void ChoiceFunc(int choice = 0);
	void DepositMoney();
	void WithdrawMoney();
	~AccountHandler();
};
#endif __ACCOUNT_HANDLER_H__
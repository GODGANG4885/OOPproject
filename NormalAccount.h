#ifndef __NORMAL_ACCOOUNT_H__
#define __NORMAL_ACCOOUNT_H__

#include "Account.h"
#include "String.h"
class NormalAccount : public Account
{
private:
	int iza;
public:
	NormalAccount(int ID, int money, String name, int izarate) :Account(ID, money, name), iza(izarate) {}
	//NormalAccount(int ID, int money, char* name, int izarate) :Account(ID, money, name), iza(izarate)

	virtual void Deposit(int money) {
		Account::Deposit(money);
		Account::Deposit(int(money*iza / 100.0));
	}
};
#endif  __NORMAL_ACCOOUNT_H__
#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__
#include"NormalAccount.h"
#include"String.h"
class HighCreditAccount : public NormalAccount
{
private:
	int creditLevel;
public:
	HighCreditAccount(int ID, int money, String name, int izarate, int creditLevel)
	//HighCreditAccount(int ID, int money, char* name, int izarate, int creditLevel)
		:NormalAccount(ID, money, name, izarate), creditLevel(creditLevel)
	{}
	virtual void Deposit(int money) {
		NormalAccount::Deposit(money);
		Account::Deposit(int(money*creditLevel / 100.0));
	}
};
#endif __HIGHCREDIT_ACCOUNT_H__
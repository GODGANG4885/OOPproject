#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
class Account {
private:
	int AccID;
	char * cusName;
	int balance;
public:
	Account(int ID, int money, char * name) ;
	
	Account(const Account& ref);
	int GetAccID() const;
	char* NameInfo() const;
	~Account();
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowInfo() const;
};
#endif __ACCOUNT_H__
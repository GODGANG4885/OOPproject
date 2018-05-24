//c++ OOP-05 2018-5-24

#include <iostream>
#include<cstring>
#pragma warning(disable : 4996)

using namespace std;

class Account {
private :
	int AccID;
	char * cusName;
	int balance;
public:
	Account(int ID, int money, char * name) :AccID(ID), balance(money) {
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}
	Account(const Account& ref) :AccID(ref.AccID), balance(ref.balance) {
		cusName = new char[strlen(ref.cusName) + 1];
		strcpy(cusName, ref.cusName);
	}
	int GetAccID() const {
		return AccID; 
	}
	char* NameInfo() const{
		return cusName;
	}
	~Account() {
		delete[] cusName;
	}
	void Deposit(int money) {
		balance += money;
	}
	int Withdraw(int money) { //출금액 반환, 부족시 0반환 
		if (balance < money) {
			
			return 0;
		}
		balance -= money;
		return money;
	}
	void ShowInfo() const {
		cout << "계좌 ID : " << AccID << endl;
		cout << "이름 : " << cusName << endl;
		cout << "잔액 : " << balance << endl;
	}
};



class AccountHander {
private:
	Account * accArr[100];
	int Accnum = 0;
public:
	AccountHander();
	void CreateAccount();
	void ChoiceFunc(int choice = 0);
	void DepositMoney();
	void WithdrawMoney();
	~AccountHander();
};
	AccountHander::AccountHander() :Accnum(0){}
	AccountHander::~AccountHander() 
	{
		for (int i = 0; i < Accnum; i++) 
		{
			delete accArr[i];
		}
	}
	void AccountHander::ChoiceFunc(int choice) {

		switch (choice) {
		case 1: CreateAccount(); break;
		case 2: DepositMoney(); break;
		case 3: WithdrawMoney(); break;
		case 4: for (int i = 0; i < Accnum; i++)  accArr[i]->ShowInfo(); break;
		case 5:cout << "프로그램을 종료합니다" << endl; break;
		}
	}
	void AccountHander::CreateAccount() {
		int AccountID;
		char name[20];
		int balance;
		bool cycle = false;
		while (1) {
			cout << "계좌ID :";
			cin >> AccountID;
			for (int i = 0; i < Accnum; i++)
			{
				if (accArr[i]->GetAccID() == AccountID) {
					cout << "계좌ID 중복" << endl;
					cycle = true;
					break;
				}
				else
					cycle = false;

			}
			if (!cycle)
				break;
		}
		cout << "이름 :";
		cin >> name;
		cout << "입금액 :";
		cin >> balance;
		accArr[Accnum++] = new Account(AccountID, balance, name);

	}

	void AccountHander::DepositMoney() {
		int AccountID;
		int balance;
		int i = 0;
		int YesOr;
		bool IsAccountIDcorrect = false;
		while (!IsAccountIDcorrect) {
			cout << "입금할 계좌ID :";
			cin >> AccountID;
			for (i = 0; i < Accnum; i++) {
				if (accArr[i]->GetAccID() == AccountID) {
					IsAccountIDcorrect = true;
					break;
				}
			}
			if (IsAccountIDcorrect != true) {
				cout << "계좌ID 오류" << endl;
				continue;
			}
			cout << "입금 계좌 " << accArr[i]->NameInfo() << "가 맞습니까? 맞으면 1, 틀리면2 입력:";
			cin >> YesOr;
			if (YesOr != 1)
				continue;
			cout << "입금할 금액 :";
			cin >> balance;
			accArr[i]->Deposit(balance);
			cout << "입금완료" << endl;
		}
	}

	void AccountHander::WithdrawMoney() {
		int AccountID;
		int balance;
		int i = 0;
		int YesOr;
		bool IsAccountIDcorrect = false;
		while (!IsAccountIDcorrect) {
			cout << "출금할 계좌ID :";
			cin >> AccountID;
			for (i = 0; i < Accnum; i++) {
				if (accArr[i]->GetAccID() == AccountID) {
					IsAccountIDcorrect = true;
					break;
				}
			}
			if (IsAccountIDcorrect != true) {
				cout << "계좌ID 오류" << endl;
				continue;
			}
			cout << "출금 계좌 " << accArr[i]->NameInfo() << "가 맞습니까? 맞으면 1, 틀리면2 입력:";
			cin >> YesOr;
			if (YesOr != 1)
				continue;
			cout << "출금할 금액 :";
			cin >> balance;
			if (accArr[i]->Withdraw(balance))
				cout << "출금완료" << endl;
			else
				cout << "출금실패: 출금금액 부족" << endl;
		}
	}

	int main(void) {
		AccountHander manager;
		int choice = 0;
		while (choice != 5) {
			cout << "-----Menu-----" << endl;
			cout << "1. 계좌개설" << endl;
			cout << "2. 입 금" << endl;
			cout << "3. 출금" << endl;
			cout << "4. 계좌정보 전체 출력" << endl;
			cout << "5. 프로그램 종료" << endl;
			cout << "선택: ";
			cin >> choice;
			manager.ChoiceFunc(choice);
		}
		return 0;
	}
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
	int Withdraw(int money) { //��ݾ� ��ȯ, ������ 0��ȯ 
		if (balance < money) {
			
			return 0;
		}
		balance -= money;
		return money;
	}
	void ShowInfo() const {
		cout << "���� ID : " << AccID << endl;
		cout << "�̸� : " << cusName << endl;
		cout << "�ܾ� : " << balance << endl;
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
		case 5:cout << "���α׷��� �����մϴ�" << endl; break;
		}
	}
	void AccountHander::CreateAccount() {
		int AccountID;
		char name[20];
		int balance;
		bool cycle = false;
		while (1) {
			cout << "����ID :";
			cin >> AccountID;
			for (int i = 0; i < Accnum; i++)
			{
				if (accArr[i]->GetAccID() == AccountID) {
					cout << "����ID �ߺ�" << endl;
					cycle = true;
					break;
				}
				else
					cycle = false;

			}
			if (!cycle)
				break;
		}
		cout << "�̸� :";
		cin >> name;
		cout << "�Աݾ� :";
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
			cout << "�Ա��� ����ID :";
			cin >> AccountID;
			for (i = 0; i < Accnum; i++) {
				if (accArr[i]->GetAccID() == AccountID) {
					IsAccountIDcorrect = true;
					break;
				}
			}
			if (IsAccountIDcorrect != true) {
				cout << "����ID ����" << endl;
				continue;
			}
			cout << "�Ա� ���� " << accArr[i]->NameInfo() << "�� �½��ϱ�? ������ 1, Ʋ����2 �Է�:";
			cin >> YesOr;
			if (YesOr != 1)
				continue;
			cout << "�Ա��� �ݾ� :";
			cin >> balance;
			accArr[i]->Deposit(balance);
			cout << "�ԱݿϷ�" << endl;
		}
	}

	void AccountHander::WithdrawMoney() {
		int AccountID;
		int balance;
		int i = 0;
		int YesOr;
		bool IsAccountIDcorrect = false;
		while (!IsAccountIDcorrect) {
			cout << "����� ����ID :";
			cin >> AccountID;
			for (i = 0; i < Accnum; i++) {
				if (accArr[i]->GetAccID() == AccountID) {
					IsAccountIDcorrect = true;
					break;
				}
			}
			if (IsAccountIDcorrect != true) {
				cout << "����ID ����" << endl;
				continue;
			}
			cout << "��� ���� " << accArr[i]->NameInfo() << "�� �½��ϱ�? ������ 1, Ʋ����2 �Է�:";
			cin >> YesOr;
			if (YesOr != 1)
				continue;
			cout << "����� �ݾ� :";
			cin >> balance;
			if (accArr[i]->Withdraw(balance))
				cout << "��ݿϷ�" << endl;
			else
				cout << "��ݽ���: ��ݱݾ� ����" << endl;
		}
	}

	int main(void) {
		AccountHander manager;
		int choice = 0;
		while (choice != 5) {
			cout << "-----Menu-----" << endl;
			cout << "1. ���°���" << endl;
			cout << "2. �� ��" << endl;
			cout << "3. ���" << endl;
			cout << "4. �������� ��ü ���" << endl;
			cout << "5. ���α׷� ����" << endl;
			cout << "����: ";
			cin >> choice;
			manager.ChoiceFunc(choice);
		}
		return 0;
	}

#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDec1.h"
#include "String.h"

AccountHandler::AccountHandler() :Accnum(0) {}
AccountHandler::~AccountHandler()
{
	for (int i = 0; i < Accnum; i++)
	{
		delete accArr[i];
	}
}
void AccountHandler::ChoiceFunc(int choice) {

	switch (choice) {
	case 1: CreateAccount(); break;
	case 2: DepositMoney(); break;
	case 3: WithdrawMoney(); break;
	case 4: for (int i = 0; i < Accnum; i++)  accArr[i]->ShowInfo(); break;
	case 5: cout << "���α׷��� �����մϴ�" << endl; break;
	}
}
void AccountHandler::CreateAccount() {
	int AccountID;
	//char name[20];
	String name;
	int balance;
	bool cycle = false;
	int select = 0;
	int iza;
	int creditLevel;
	while (1) {
		while (select != 1 || select != 2) {
			cout << "[������������]" << endl;
			cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
			cout << "����: ";
			cin >> select;
			switch (select) {
			case 1: cout << "[���뿹�ݰ��� ����]" << endl;
				break;
			case 2: cout << "[�ſ�ŷڰ���]" << endl;
				break;
			default: cout << "Wrong choice" << endl;
				continue;
			}
			break;
		}
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
	cout << "������: ";
	cin >> iza;
	if (select == 1)
		accArr[Accnum++] = new NormalAccount(AccountID, balance, name, iza);
	else
	{
		cout << "�ſ���(1toA, 2toB, 3toC): ";
		cin >> creditLevel;
		switch (creditLevel) {
		case 1:creditLevel = CREDIT::A;
			break;
		case 2:creditLevel = CREDIT::B;
			break;
		case 3:creditLevel = CREDIT::C;
			break;
		}
		accArr[Accnum++] = new HighCreditAccount(AccountID, balance, name, iza, creditLevel);
	}
}

void AccountHandler::DepositMoney() {
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

void AccountHandler::WithdrawMoney() {
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
			cout << "��ݿϷ�" << endl<<endl;
		else
			cout << "��ݽ���: ��ݱݾ� ����" << endl;
	}
}

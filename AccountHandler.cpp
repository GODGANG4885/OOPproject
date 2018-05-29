
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
	case 5: cout << "프로그램을 종료합니다" << endl; break;
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
			cout << "[계좌종류선택]" << endl;
			cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
			cout << "선택: ";
			cin >> select;
			switch (select) {
			case 1: cout << "[보통예금계좌 개설]" << endl;
				break;
			case 2: cout << "[신용신뢰계좌]" << endl;
				break;
			default: cout << "Wrong choice" << endl;
				continue;
			}
			break;
		}
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
	cout << "이자율: ";
	cin >> iza;
	if (select == 1)
		accArr[Accnum++] = new NormalAccount(AccountID, balance, name, iza);
	else
	{
		cout << "신용등급(1toA, 2toB, 3toC): ";
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

void AccountHandler::WithdrawMoney() {
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
			cout << "출금완료" << endl<<endl;
		else
			cout << "출금실패: 출금금액 부족" << endl;
	}
}

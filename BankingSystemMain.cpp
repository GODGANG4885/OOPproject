//c++ OOP-06 2018-5-28


#include"AccountHandler.h"
#include"BankingCommonDec1.h"




	int main(void) {
		AccountHandler manager;
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
//c++ OOP-06 2018-5-28


#include"AccountHandler.h"
#include"BankingCommonDec1.h"




	int main(void) {
		AccountHandler manager;
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
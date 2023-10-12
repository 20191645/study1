/*
	OOP 11�ܰ�:
	- ���� �ݾ׺��� ���� ��� �䱸�ϴ� ���ܻ�Ȳ
	- ����� �� 0���� ���� �� �ԷµǴ� ���ܻ�Ȳ
	- �ΰ��� ���ܻ�Ȳ �� Ŭ���� �����ϰ� ó��
	- �߰� ����: AccountException.h, AccountException.cpp
	- ���� ����: Account.cpp, AccountHandler.cpp
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void) {
	int menu;
	AccountHandler handler;

	//����ȭ��
	while (1) {
		handler.ShowMenu();
		cout << "����: ";
		cin >> menu;
		cout << endl;

		switch (menu) {
		case MAKE:
			handler.MakeAccount();
			break;
		case DEPOSIT:
			handler.DepositMoney();
			break;
		case WITHDRAW:
			handler.WithdrawMoney();
			break;
		case INQUIRE:
			handler.SnowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Menu�� �����ϴ� ��ȣ�� �Է����ּ���.\n";
		}
	}

	return 0;
}
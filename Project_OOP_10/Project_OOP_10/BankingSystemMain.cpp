/*
	OOP 10�ܰ�:
	- BoundCheckAccountPtrArray Ŭ������ 'Ŭ���� ���ø�'���� ����
	- ���� ����: AccountArray.h, AccountArray.cpp
	- �߰� ����: BoundCheckArray.h
	- ���� ����: AccountHandler.h
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
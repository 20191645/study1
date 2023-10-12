/*
	OOP 8단계:
	- Account 배열을 BoundCheckPointPtrArray 배열 클래스로 대체
	- 변경 파일: Account.h, Account.cpp, AccountHandler.h
	- 추가 파일: AccountArray.h, AccountArray.cpp
*/


#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void) {
	int menu;
	AccountHandler handler;

	//메인화면
	while (1) {
		handler.ShowMenu();
		cout << "선택: ";
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
			cout << "Menu에 존재하는 번호를 입력해주세요.\n";
		}
	}

	return 0;
}
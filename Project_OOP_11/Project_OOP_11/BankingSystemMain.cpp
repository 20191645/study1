/*
	OOP 11단계:
	- 예금 금액보다 많은 출금 요구하는 예외상황
	- 입출금 시 0보다 작은 값 입력되는 예외상황
	- 두가지 예외상황 별 클래스 정의하고 처리
	- 추가 파일: AccountException.h, AccountException.cpp
	- 변경 파일: Account.cpp, AccountHandler.cpp
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
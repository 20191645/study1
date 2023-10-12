/*
	OOP 9단계:
	- 직접 정의한 String 클래스로 문자열 표현
	- 변경 파일: Account.h, Account.cpp, NormalAccount.h, 
					HighCreditAccount.h, AccountHandler.cpp
	- 추가 파일: String.h, String.cpp
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
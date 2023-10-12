/*
	OOP 7단계:
	클래스의 선언과 정의를 각각 헤더 파일과 소스 파일로 분리
	- Account.h, Account.cpp: Account 클래스
	- NormalAccount.h: NormalAccount 클래스
	- HighCreditAccout.h: HighCreditAccount 클래스
	- AccountHandler.h, AccountHandler.cpp: AccountHandler 클래스
	- BankingCommonDecl.h: 공통헤더 및 상수선언
	- BankingSystemMain.cpp: main 함수
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
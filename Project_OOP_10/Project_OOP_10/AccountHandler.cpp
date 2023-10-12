#include "BankingCommonDecl.h"
#include "AccountHandler.h"

AccountHandler::AccountHandler() : accNum(0) {}	//생성자

void AccountHandler::ShowMenu(void) const {
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설\n2. 입 금\n3. 출 금\n4. 계좌정보 전체 출력\n5. 프로그램 종료\n";
}//메뉴 화면

void AccountHandler::MakeAccount(void) {
	int type;	//계좌종류

	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> type;

	if (type == NORMAL)
		MakeNormalAccount();
	else if (type == CREDIT) {
		MakeCreditAccount();
	}
}//계좌 개설 선택

void AccountHandler::MakeNormalAccount(void) {
	int id, money;
	//char name[NAME_LEN];
	String name;
	int rate;	//이자율

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이름: "; cin >> name;
	cout << "입금액: "; cin >> money;
	cout << "이자율: "; cin >> rate;
	cout << "개설완료" << endl << endl;
	accArr[accNum] = new NormalAccount(id, name, money, rate);
	accNum++;
	return;
}

void AccountHandler::MakeCreditAccount(void) {
	int id, money;
	//char name[NAME_LEN];
	String name;
	int rate, rank;	//이자율, 등급

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이름: "; cin >> name;
	cout << "입금액: "; cin >> money;
	cout << "이자율: "; cin >> rate;
	cout << "신용등급(1toA, 2toB, 3toC): "; cin >> rank;
	switch (rank) {
	case 1:
		rank = LEVEL_A;
		break;
	case 2:
		rank = LEVEL_B;
		break;
	case 3:
		rank = LEVEL_C;
		break;
	}
	cout << "개설완료" << endl << endl;
	accArr[accNum] = new HighCreditAccount(id, name, money, rate, rank);
	accNum++;
	return;
}

void AccountHandler::DepositMoney(void) {
	int id, money;
	cout << "[입\t금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetID() == id) {
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}

	cout << "존재하지 않는 ID입니다." << endl << endl;
}//입금

void AccountHandler::WithdrawMoney(void) {
	int id, money;
	cout << "[입\t금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetID() == id) {
			int result = accArr[i]->Withdraw(money);

			if (result == -1) {
				cout << "잔액부족" << endl << endl;
				return;
			}

			cout << "출금완료" << endl << endl;
			return;
		}
	}

	cout << "존재하지 않는 ID입니다." << endl << endl;
}//출금


void AccountHandler::SnowAllAccInfo(void) const {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
	}
}//전체계좌출력

AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++) {
		delete accArr[i];
	}
}//소멸자
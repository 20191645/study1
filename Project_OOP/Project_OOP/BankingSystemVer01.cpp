/*
	OOP 1단계:
	'은행계좌 관리 프로그램'을 C 스타일로 구현한다
	기능 1. 계좌개설
	기능 2. 입금
	기능 3. 출금
	기능 4. 전체고객 잔액조회
*/

#include <iostream>
#include <string>
using namespace std;

typedef struct {
	int id;
	string name;
	int money;
}account;

account accArr[100];
int accNum = 0;

void MakeAccount(void); //계좌개설
void DepositMoney(void); //입금
void WithdrawMoney(void); //출금
void SnowAllAccInfo(void); //전체계좌출력

int main(void) {
	//메인화면
	int menu;

	while (1) {
		cout << "-----Menu-----" << endl << "1. 계좌개설\n2. 입 금\n3. 출 금\n4. 계좌정보 전체 출력\n5. 프로그램 종료\n선택: ";
		cin >> menu;
		cout << endl;

		switch (menu) {
		case 1:
			MakeAccount();
			break;
		case 2:
			DepositMoney();
			break;
		case 3:
			WithdrawMoney();
			break;
		case 4:
			SnowAllAccInfo();
			break;
		case 5:
			return 0;
		default:
			cout << "Menu에 존재하는 번호를 입력해주세요.\n";
		}
	}

	return 0;
}


void MakeAccount(void) {
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> accArr[accNum].id;
	cout << "이름: "; cin >> accArr[accNum].name;
	cout << "입금액: "; cin >> accArr[accNum].money;
	cout << "개설완료" << endl << endl;
	accNum++;
}

void DepositMoney(void) {
	int id, money;
	cout << "[입\t금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].id == id) {
			accArr[i].money += money;
			cout << "입금완료" << endl << endl;
			return;
		}
	}

	cout << "존재하지 않는 ID입니다." << endl << endl;
}

void WithdrawMoney(void) {
	int id, money;
	cout << "[입\t금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].id == id) {
			if (money > accArr[i].money) {
				cout << "잔액부족" << endl << endl;
				return;
			}

			accArr[i].money -= money;
			cout << "출금완료" << endl << endl;
			return;
		}
	}

	cout << "존재하지 않는 ID입니다." << endl << endl;
}


void SnowAllAccInfo(void) {
	for (int i = 0; i < accNum; i++) {
		cout << "계좌ID: " << accArr[i].id << endl;
		cout << "이름: " << accArr[i].name << endl;
		cout << "잔액: " << accArr[i].money << endl << endl;
	}
}

/*
	OOP 3단계:
	- Account 클래스에 깊은 복사를 진행하는 복사 생성자 정의
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Account {
private:
	int id;
	char* name;
	int balance;

public:
	Account(int id, char* name, int money)
		: id(id), balance(money)
	{
		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy(this->name, name);
	}

	//깊은 복사를 위한 복사 생성자
	Account(const Account& copy)
		:id(copy.id), balance(copy.balance)
	{
		this->name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}

	int GetID() {
		return id;
	}

	int GetMoney() {
		return balance;
	}

	void Deposit(int money) {
		this->balance += money;
	}

	int Withdraw(int money) {
		if (this->balance < money)
			return -1;

		this->balance -= money;
		return money;
	}

	void ShowAccInfo(void) {
		cout << "계좌ID: " << id << endl;
		cout << "이름: " << name << endl;
		cout << "잔액: " << balance << endl << endl;
	}

	~Account() {
		delete[]name;
	}
};

//함수
void ShowMenu(void);		//메뉴화면
void MakeAccount(void);		//계좌개설
void DepositMoney(void);	//입금
void WithdrawMoney(void);	//출금
void SnowAllAccInfo(void);	//전체계좌출력


//전역변수
Account* accArr[100];
int accNum = 0;
const int NAME_LEN = 20;
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

int main(void) {
	int menu;

	//메인화면
	while (1) {
		ShowMenu();
		cout << "선택: ";
		cin >> menu;
		cout << endl;

		switch (menu) {
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			SnowAllAccInfo();
			break;
		case EXIT:
			for (int i = 0; i < 100; i++) {
				delete accArr[i];
			}
			return 0;
		default:
			cout << "Menu에 존재하는 번호를 입력해주세요.\n";
		}
	}

	return 0;
}

void ShowMenu(void) {
	int menu;
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설\n2. 입 금\n3. 출 금\n4. 계좌정보 전체 출력\n5. 프로그램 종료\n";
}


void MakeAccount(void) {
	int id, money;
	char name[NAME_LEN];

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이름: "; cin >> name;
	cout << "입금액: "; cin >> money;
	cout << "개설완료" << endl << endl;

	accArr[accNum] = new Account(id, name, money);
	accNum++;
}

void DepositMoney(void) {
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
}

void WithdrawMoney(void) {
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
}


void SnowAllAccInfo(void) {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
	}
}

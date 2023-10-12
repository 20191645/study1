/*
	OOP 5단계:
	- AccountHandler라는 컨트롤 클래스 정의
	- 앞서 정의한 전역함수를 위 클래스의 멤버함수에 포함
	- Account 객체 저장을 위한 배열과 변수도 멤버에 포함
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

//전역변수
const int NAME_LEN = 20;
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

/*
* 클래스 이름: Account
* 클래스 유형: Entity 클래스
*/
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

	//멤버함수에 const 추가
	int GetID() const { return id; }
	int GetBalance() const { return balance; }
	void Deposit(int money) { this->balance += money; }

	int Withdraw(int money) {
		if (this->balance < money)
			return -1;

		this->balance -= money;
		return money;
	}

	void ShowAccInfo(void) const {
		cout << "계좌ID: " << id << endl;
		cout << "이름: " << name << endl;
		cout << "잔액: " << balance << endl << endl;
	}

	~Account() {
		delete[]name;
	}
};

/*
* 클래스 이름: AccountHandler
* 클래스 유형: Handler 클래스
*/
class AccountHandler {
private:
	Account* accArr[100];
	int accNum;

public:
	AccountHandler()
		: accNum(0) {}//생성자

	void ShowMenu(void) const {
		cout << "-----Menu-----" << endl;
		cout << "1. 계좌개설\n2. 입 금\n3. 출 금\n4. 계좌정보 전체 출력\n5. 프로그램 종료\n";
	}//메뉴 화면

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
	}//계좌 개설

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
	}//입금

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
	}//출금


	void SnowAllAccInfo(void) const {
		for (int i = 0; i < accNum; i++) {
			accArr[i]->ShowAccInfo();
		}
	}//전체계좌출력

	~AccountHandler() {
		for (int i = 0; i < accNum; i++) {
			delete accArr[i];
		}
	}//소멸자
};

/*
* main 함수
*/
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

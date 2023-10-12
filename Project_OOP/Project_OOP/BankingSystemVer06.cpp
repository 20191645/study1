/*
	문제 6:
	- Account 클래스를 상속하는 두 클래스를 추가로 정의
	- NormalAccount: 객체 생성과정에서 기본이율 등록
	- HighCreditAccount: 기본이율 등록, 신용등급 등록
	- AccountHandler 클래스는 큰 변화가 없어야 한다
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

//전역변수

const int NAME_LEN = 20;
//메뉴선택
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
//HighCreditAccount 신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
//계좌종류
enum { NORMAL = 1, CREDIT };



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

	Account(const Account& copy)
		:id(copy.id), balance(copy.balance)
	{
		this->name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}

	int GetID() const { return id; }

	virtual void Deposit(int money) { balance += money; }

	int Withdraw(int money) {
		if (balance < money)
			return -1;

		balance -= money;
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
* 클래스 이름: NormalAccount
* 클래스 유형: Entity 클래스 - Account 상속
*/
class NormalAccount :public Account {
private:
	int interRate;	//이자율

public:
	NormalAccount(int id, char* name, int money, int rate)
		:Account(id, name, money), interRate(rate)
	{}

	void Deposit(int money) {
		Account::Deposit(money);
		Account::Deposit(money * (interRate / 100.0));
	}
};



/*
* 클래스 이름: HighCreditAccount
* 클래스 유형: Entity 클래스 - NormalAccount 상속
*/
class HighCreditAccount :public NormalAccount {
private:
	int creditRank;		//신용등급

public:
	HighCreditAccount(int id, char* name, int money, int rate, int rank)
		:NormalAccount(id, name, money, rate), creditRank(rank)
	{ }

	void Deposit(int money) {
		NormalAccount::Deposit(money);
		Account::Deposit(money * (creditRank / 100.0));
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

	void MakeNormalAccount(void) {
		int id, money;
		char name[NAME_LEN];
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

	void MakeCreditAccount(void) {
		int id, money;
		char name[NAME_LEN];
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

/*
	���� 6:
	- Account Ŭ������ ����ϴ� �� Ŭ������ �߰��� ����
	- NormalAccount: ��ü ������������ �⺻���� ���
	- HighCreditAccount: �⺻���� ���, �ſ��� ���
	- AccountHandler Ŭ������ ū ��ȭ�� ����� �Ѵ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

//��������

const int NAME_LEN = 20;
//�޴�����
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
//HighCreditAccount �ſ���
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
//��������
enum { NORMAL = 1, CREDIT };



/*
* Ŭ���� �̸�: Account
* Ŭ���� ����: Entity Ŭ����
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
		cout << "����ID: " << id << endl;
		cout << "�̸�: " << name << endl;
		cout << "�ܾ�: " << balance << endl << endl;
	}

	~Account() {
		delete[]name;
	}
};



/*
* Ŭ���� �̸�: NormalAccount
* Ŭ���� ����: Entity Ŭ���� - Account ���
*/
class NormalAccount :public Account {
private:
	int interRate;	//������

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
* Ŭ���� �̸�: HighCreditAccount
* Ŭ���� ����: Entity Ŭ���� - NormalAccount ���
*/
class HighCreditAccount :public NormalAccount {
private:
	int creditRank;		//�ſ���

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
* Ŭ���� �̸�: AccountHandler
* Ŭ���� ����: Handler Ŭ����
*/
class AccountHandler {
private:
	Account* accArr[100];
	int accNum;

public:
	AccountHandler()
		: accNum(0) {}//������

	void ShowMenu(void) const {
		cout << "-----Menu-----" << endl;
		cout << "1. ���°���\n2. �� ��\n3. �� ��\n4. �������� ��ü ���\n5. ���α׷� ����\n";
	}//�޴� ȭ��

	void MakeAccount(void) {
		int type;	//��������

		cout << "[������������]" << endl;
		cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
		cout << "����: ";
		cin >> type;

		if (type == NORMAL)
			MakeNormalAccount();
		else if (type == CREDIT) {
			MakeCreditAccount();
		}
	}//���� ���� ����

	void MakeNormalAccount(void) {
		int id, money;
		char name[NAME_LEN];
		int rate;	//������

		cout << "[���뿹�ݰ��� ����]" << endl;
		cout << "����ID: "; cin >> id;
		cout << "�̸�: "; cin >> name;
		cout << "�Աݾ�: "; cin >> money;
		cout << "������: "; cin >> rate;
		cout << "�����Ϸ�" << endl << endl;
		accArr[accNum] = new NormalAccount(id, name, money, rate);
		accNum++;
		return;
	}

	void MakeCreditAccount(void) {
		int id, money;
		char name[NAME_LEN];
		int rate, rank;	//������, ���

		cout << "[���뿹�ݰ��� ����]" << endl;
		cout << "����ID: "; cin >> id;
		cout << "�̸�: "; cin >> name;
		cout << "�Աݾ�: "; cin >> money;
		cout << "������: "; cin >> rate;
		cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> rank;
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
		cout << "�����Ϸ�" << endl << endl;
		accArr[accNum] = new HighCreditAccount(id, name, money, rate, rank);
		accNum++;
		return;
	}

	void DepositMoney(void) {
		int id, money;
		cout << "[��\t��]" << endl;
		cout << "����ID: "; cin >> id;
		cout << "�Աݾ�: "; cin >> money;

		for (int i = 0; i < accNum; i++) {
			if (accArr[i]->GetID() == id) {
				accArr[i]->Deposit(money);
				cout << "�ԱݿϷ�" << endl << endl;
				return;
			}
		}

		cout << "�������� �ʴ� ID�Դϴ�." << endl << endl;
	}//�Ա�

	void WithdrawMoney(void) {
		int id, money;
		cout << "[��\t��]" << endl;
		cout << "����ID: "; cin >> id;
		cout << "��ݾ�: "; cin >> money;

		for (int i = 0; i < accNum; i++) {
			if (accArr[i]->GetID() == id) {
				int result = accArr[i]->Withdraw(money);

				if (result == -1) {
					cout << "�ܾ׺���" << endl << endl;
					return;
				}

				cout << "��ݿϷ�" << endl << endl;
				return;
			}
		}

		cout << "�������� �ʴ� ID�Դϴ�." << endl << endl;
	}//���


	void SnowAllAccInfo(void) const {
		for (int i = 0; i < accNum; i++) {
			accArr[i]->ShowAccInfo();
		}
	}//��ü�������

	~AccountHandler() {
		for (int i = 0; i < accNum; i++) {
			delete accArr[i];
		}
	}//�Ҹ���
};

/*
* main �Լ�
*/
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

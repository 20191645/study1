/*
	OOP 3�ܰ�:
	- Account Ŭ������ ���� ���縦 �����ϴ� ���� ������ ����
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

	//���� ���縦 ���� ���� ������
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
		cout << "����ID: " << id << endl;
		cout << "�̸�: " << name << endl;
		cout << "�ܾ�: " << balance << endl << endl;
	}

	~Account() {
		delete[]name;
	}
};

//�Լ�
void ShowMenu(void);		//�޴�ȭ��
void MakeAccount(void);		//���°���
void DepositMoney(void);	//�Ա�
void WithdrawMoney(void);	//���
void SnowAllAccInfo(void);	//��ü�������


//��������
Account* accArr[100];
int accNum = 0;
const int NAME_LEN = 20;
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

int main(void) {
	int menu;

	//����ȭ��
	while (1) {
		ShowMenu();
		cout << "����: ";
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
			cout << "Menu�� �����ϴ� ��ȣ�� �Է����ּ���.\n";
		}
	}

	return 0;
}

void ShowMenu(void) {
	int menu;
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���\n2. �� ��\n3. �� ��\n4. �������� ��ü ���\n5. ���α׷� ����\n";
}


void MakeAccount(void) {
	int id, money;
	char name[NAME_LEN];

	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�̸�: "; cin >> name;
	cout << "�Աݾ�: "; cin >> money;
	cout << "�����Ϸ�" << endl << endl;

	accArr[accNum] = new Account(id, name, money);
	accNum++;
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
}

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
}


void SnowAllAccInfo(void) {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
	}
}

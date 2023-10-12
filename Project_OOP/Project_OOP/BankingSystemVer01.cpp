/*
	OOP 1�ܰ�:
	'������� ���� ���α׷�'�� C ��Ÿ�Ϸ� �����Ѵ�
	��� 1. ���°���
	��� 2. �Ա�
	��� 3. ���
	��� 4. ��ü�� �ܾ���ȸ
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

void MakeAccount(void); //���°���
void DepositMoney(void); //�Ա�
void WithdrawMoney(void); //���
void SnowAllAccInfo(void); //��ü�������

int main(void) {
	//����ȭ��
	int menu;

	while (1) {
		cout << "-----Menu-----" << endl << "1. ���°���\n2. �� ��\n3. �� ��\n4. �������� ��ü ���\n5. ���α׷� ����\n����: ";
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
			cout << "Menu�� �����ϴ� ��ȣ�� �Է����ּ���.\n";
		}
	}

	return 0;
}


void MakeAccount(void) {
	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> accArr[accNum].id;
	cout << "�̸�: "; cin >> accArr[accNum].name;
	cout << "�Աݾ�: "; cin >> accArr[accNum].money;
	cout << "�����Ϸ�" << endl << endl;
	accNum++;
}

void DepositMoney(void) {
	int id, money;
	cout << "[��\t��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].id == id) {
			accArr[i].money += money;
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
		if (accArr[i].id == id) {
			if (money > accArr[i].money) {
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			accArr[i].money -= money;
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}

	cout << "�������� �ʴ� ID�Դϴ�." << endl << endl;
}


void SnowAllAccInfo(void) {
	for (int i = 0; i < accNum; i++) {
		cout << "����ID: " << accArr[i].id << endl;
		cout << "�̸�: " << accArr[i].name << endl;
		cout << "�ܾ�: " << accArr[i].money << endl << endl;
	}
}

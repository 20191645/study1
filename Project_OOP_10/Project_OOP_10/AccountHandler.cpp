#include "BankingCommonDecl.h"
#include "AccountHandler.h"

AccountHandler::AccountHandler() : accNum(0) {}	//������

void AccountHandler::ShowMenu(void) const {
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���\n2. �� ��\n3. �� ��\n4. �������� ��ü ���\n5. ���α׷� ����\n";
}//�޴� ȭ��

void AccountHandler::MakeAccount(void) {
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

void AccountHandler::MakeNormalAccount(void) {
	int id, money;
	//char name[NAME_LEN];
	String name;
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

void AccountHandler::MakeCreditAccount(void) {
	int id, money;
	//char name[NAME_LEN];
	String name;
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

void AccountHandler::DepositMoney(void) {
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

void AccountHandler::WithdrawMoney(void) {
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


void AccountHandler::SnowAllAccInfo(void) const {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
	}
}//��ü�������

AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++) {
		delete accArr[i];
	}
}//�Ҹ���
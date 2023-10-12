#ifndef __ACCOUNTEXCEPTION_H__
#define __ACCOUNTEXCEPTION_H__

#include <iostream>
using namespace std;

class AccountException {
public:
	virtual void ShowExceptionReason() = 0;	//���������Լ�
};

class InputException :public AccountException {
private:
	int money;	//�Է� �ݾ�

public:
	InputException(int money) :money(money) {}
	void ShowExceptionReason() {
		cout << "0������ ���� ���� " << money << "���� �Է��� �� �����ϴ�." << endl;
	}
};	//����� 0���� ���� ��

class WithdrawException :public AccountException {
private:
	int balance;	//�ܾ�
	int money;	//�Է� �ݾ�

public:
	WithdrawException(int balance, int money) :balance(balance), money(money) {}
	void ShowExceptionReason() {
		cout << "�ܾ��� " << balance << "������ ���� ����� " << money << "���� ����� �� �����ϴ�." << endl;
	}
};	//�ܾ׺��� ���� ��� �䱸

#endif
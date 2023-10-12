#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "Account.h"

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

#endif
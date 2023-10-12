#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"

/*
* Ŭ���� �̸�: HighCreditAccount
* Ŭ���� ����: Entity Ŭ���� - NormalAccount ���
*/
class HighCreditAccount :public NormalAccount {
private:
	int creditRank;		//�ſ���

public:
	//HighCreditAccount(int id, char* name, int money, int rate, int rank)
	HighCreditAccount(int id, String name, int money, int rate, int rank)
		:NormalAccount(id, name, money, rate), creditRank(rank)
	{ }

	void Deposit(int money) {
		NormalAccount::Deposit(money);
		Account::Deposit(money * (creditRank / 100.0));
	}
};

#endif
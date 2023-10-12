#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"

/*
* 클래스 이름: HighCreditAccount
* 클래스 유형: Entity 클래스 - NormalAccount 상속
*/
class HighCreditAccount :public NormalAccount {
private:
	int creditRank;		//신용등급

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
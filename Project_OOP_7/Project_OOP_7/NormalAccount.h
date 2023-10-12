#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "Account.h"

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

#endif
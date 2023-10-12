#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "HighCreditAccount.h"
#include "AccountArray.h"

class AccountHandler {
private:
	AccountArray accArr;
	int accNum;

public:
	AccountHandler();

	void ShowMenu(void) const;
	void MakeAccount(void);
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void SnowAllAccInfo(void) const;

	~AccountHandler();
};

#endif
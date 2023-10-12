#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "HighCreditAccount.h"
#include "BoundCheckArray.h"

typedef Account* ACCOUNT_POINT;

class AccountHandler {
private:
	//AccountArray accArr;
	BoundCheckArray<ACCOUNT_POINT> accArr;
	int accNum;

public:
	AccountHandler();

	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void SnowAllAccInfo(void) const;

	~AccountHandler();

protected:
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);

};

#endif
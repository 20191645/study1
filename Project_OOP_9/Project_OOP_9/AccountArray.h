#ifndef __ACCOUNTARRAY_H__
#define __ACCOUNTARRAY_H__

#include "Account.h"

typedef Account* ACCOUNT_POINT;

class AccountArray {
private:
	ACCOUNT_POINT* arr;
	int arrlen;
	AccountArray(const AccountArray& ref) {}
	AccountArray& operator=(const AccountArray& ref) {}

public:
	AccountArray(int len = 100);

	ACCOUNT_POINT& operator[](const int idx);
	ACCOUNT_POINT operator[](const int idx) const;
	int GetLen() const;

	~AccountArray();
};

#endif
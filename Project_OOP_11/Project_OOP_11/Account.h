#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

/*
* Ŭ���� �̸�: Account
* Ŭ���� ����: Entity Ŭ����
*/
class Account {
private:
	int id;
	//char* name;
	String name;
	int balance;

public:
	//Account(int myid, char* myname, int mybalance);
	Account(int myid, String myname, int mybalance);
	Account(const Account& ref);

	Account& operator=(const Account& ref);

	int GetID() const;
	virtual void Deposit(int);
	int Withdraw(int);
	void ShowAccInfo() const;

	~Account();
};

#endif
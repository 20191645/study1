#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

/*
* 클래스 이름: Account
* 클래스 유형: Entity 클래스
*/
class Account {
private:
	int id;
	char* name;
	int balance;

public:
	Account(int, char*, int);
	Account(const Account& ref);

	Account& operator=(const Account& ref);

	int GetID() const;
	virtual void Deposit(int);
	int Withdraw(int);
	void ShowAccInfo() const;

	~Account();
};

#endif
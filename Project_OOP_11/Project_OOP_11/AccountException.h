#ifndef __ACCOUNTEXCEPTION_H__
#define __ACCOUNTEXCEPTION_H__

#include <iostream>
using namespace std;

class AccountException {
public:
	virtual void ShowExceptionReason() = 0;	//순수가상함수
};

class InputException :public AccountException {
private:
	int money;	//입력 금액

public:
	InputException(int money) :money(money) {}
	void ShowExceptionReason() {
		cout << "0원보다 작은 값인 " << money << "원은 입력할 수 없습니다." << endl;
	}
};	//입출금 0보다 작은 값

class WithdrawException :public AccountException {
private:
	int balance;	//잔액
	int money;	//입력 금액

public:
	WithdrawException(int balance, int money) :balance(balance), money(money) {}
	void ShowExceptionReason() {
		cout << "잔액인 " << balance << "원보다 많은 요금인 " << money << "원은 출금할 수 없습니다." << endl;
	}
};	//잔액보다 많은 출금 요구

#endif
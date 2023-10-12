#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountException.h"

Account::Account(int myid, String myname, int mybalance)
	: id(myid), balance(mybalance), name(myname)
{
	/*int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy(this->name, name);*/
}

Account::Account(const Account& ref)
	:id(ref.id), balance(ref.balance), name(ref.name)
{
	/*name = new char[strlen(ref.name) + 1];
	strcpy(name, ref.name);*/
}

Account& Account::operator=(const Account& ref) {
	id = ref.id;
	balance = ref.balance;
	name = ref.name;

	return *this;
}

int Account::GetID() const { return id; }

void Account::Deposit(int money){
	if (money < 0)
		throw InputException(money);
	balance += money; 
}

int Account::Withdraw(int money){
	if (balance < money)
		throw WithdrawException(balance, money);
	else if (money < 0)
		throw InputException(money);

	balance -= money;
	return money;
}

void Account::ShowAccInfo(void) const {
	cout << "°èÁÂID: " << id << endl;
	cout << "ÀÌ¸§: " << name << endl;
	cout << "ÀÜ¾×: " << balance << endl << endl;
}

Account::~Account() {

}
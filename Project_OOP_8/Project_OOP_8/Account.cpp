#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int id, char* name, int money)
	: id(id), balance(money)
{
	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy(this->name, name);
}

Account::Account(const Account& ref)
	:id(ref.id), balance(ref.balance)
{
	name = new char[strlen(ref.name) + 1];
	strcpy(name, ref.name);
}

Account& Account::operator=(const Account& ref) {
	delete[]name;
	id = ref.id;
	balance = ref.balance;
	name = new char[strlen(ref.name) + 1];
	strcpy(name, ref.name);

	return *this;
}

int Account::GetID() const { return id; }

void Account::Deposit(int money) { balance += money; }

int Account::Withdraw(int money) {
	if (balance < money)
		return -1;

	balance -= money;
	return money;
}

void Account::ShowAccInfo(void) const {
	cout << "°èÁÂID: " << id << endl;
	cout << "ÀÌ¸§: " << name << endl;
	cout << "ÀÜ¾×: " << balance << endl << endl;
}

Account::~Account() {
	delete[]name;
}
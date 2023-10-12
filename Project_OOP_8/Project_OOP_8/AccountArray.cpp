#include "BankingCommonDecl.h"
#include "AccountArray.h"

AccountArray::AccountArray(int len):arrlen(len) {
	arr = new ACCOUNT_POINT[len];
}

ACCOUNT_POINT& AccountArray::operator[](const int idx) {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array iddex out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}

ACCOUNT_POINT AccountArray::operator[](const int idx) const {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array iddex out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}

int AccountArray::GetLen() const {
	return arrlen;
}

AccountArray::~AccountArray() {
	delete[] arr;
}
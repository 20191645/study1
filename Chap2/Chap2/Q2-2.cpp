/*
	문제 2:
	SwapPointer(ptr1, ptr2);
	에서 ptr1과 ptr2가 가리키는 대상이 서로 바뀌도록 함수를 정의
*/

#include <iostream>
using namespace std;

void SwapPointer(int* (&pref1), int* (&pref2)) {
	int* ptr = pref1;
	pref1 = pref2;
	pref2 = ptr;
}

int main(void) {
	int num1 = 5;
	int* ptr1 = &num1;
	int num2 = 10;
	int* ptr2 = &num2;

	cout << "ptr1 address: " << ptr1 << endl;
	cout << "ptr2 address: " << ptr2 << endl;

	SwapPointer(ptr1, ptr2);

	cout << "ptr1 address: " << ptr1 << endl;
	cout << "ptr2 address: " << ptr2 << endl;

	return 0;
}
/*
	문제 1:
	참조자를 이용하여 다음 요구사항에 부합하는 함수를 각각 정의하라
	- 인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수
	- 인자로 전달된 int형 변수의 부호를 바꾸는 함수
*/

#include <iostream>
using namespace std;

void IncNum(int& ref) { ref++; }
void ChangeSign(int& ref) {
	ref = -ref;
}

int main(void) {
	int num = -1;

	IncNum(num);
	cout << "Increase Result: " << num << endl;

	ChangeSign(num);
	cout << "Change Sign Result: " << num << endl;

	return 0;
}
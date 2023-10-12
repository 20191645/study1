/*
	문제 3:
	문자열 정보를 저장하는 클래스 Printer 구현
	기능은 '문자열 저장, 출력'
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Printer {
private:
	char myStr[100];

public:
	void SetString(const char* str);
	void ShowString();
};

int main(void) {
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();

	return 0;
}

void Printer::SetString(const char* str) {
	strcpy(myStr, str);
}

void Printer::ShowString() {
	cout << myStr << endl;
}
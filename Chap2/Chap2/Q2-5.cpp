/*
	문제 5:
	표준함수 'strlen, strcat, strcpy, strcmp'를 호출하는 예제 작성
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
	char str1[30] = "Happy New Year! ";
	char str2[30] = "Hello World! ";
	//char* str1 = "Happy New Year ";
	//char* str2 = "Hello World! ";

	cout << "str1의 길이: " << strlen(str1) << endl;
	cout << "str2의 길이: " << strlen(str2) << endl;

	cout << "str1에 str2 붙이기: " << strcat(str1, str2) << endl;

	cout << "str1에 str2 복사하기: " << strcpy(str1, str2) << endl;

	if (strcmp(str1, str2)) {
		cout << "str1과 str2는 같습니다." << endl;
	}
	else {
		cout << "str1과 str2는 같지 않습니다." << endl;
	}

	return 0;
}
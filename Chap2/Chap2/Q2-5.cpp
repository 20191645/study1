/*
	���� 5:
	ǥ���Լ� 'strlen, strcat, strcpy, strcmp'�� ȣ���ϴ� ���� �ۼ�
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

	cout << "str1�� ����: " << strlen(str1) << endl;
	cout << "str2�� ����: " << strlen(str2) << endl;

	cout << "str1�� str2 ���̱�: " << strcat(str1, str2) << endl;

	cout << "str1�� str2 �����ϱ�: " << strcpy(str1, str2) << endl;

	if (strcmp(str1, str2)) {
		cout << "str1�� str2�� �����ϴ�." << endl;
	}
	else {
		cout << "str1�� str2�� ���� �ʽ��ϴ�." << endl;
	}

	return 0;
}
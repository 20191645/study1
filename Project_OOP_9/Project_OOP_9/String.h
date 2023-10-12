#ifndef __STRING_H__
#define __STRING_H__

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
	char* str;
	int len;	//���ڿ� ����

public:
	String();	//����Ʈ ������
	String(const char* mystr);	//������
	String(const String& ref);	//���������

	String& operator=(const String& ref);	//���� ������ �����ε�
	String operator+(const String& ref);	//+ ������ �����ε�
	String& operator+=(const String& ref);	//+= ������ �����ε�
	bool operator==(const String& ref);	//==������ �����ε�

	friend ostream& operator<<(ostream& os, const String& mystr);
	friend istream& operator>>(istream& is, String& mystr);

	~String();	//�Ҹ���
};

#endif
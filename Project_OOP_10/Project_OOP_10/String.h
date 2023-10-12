#ifndef __STRING_H__
#define __STRING_H__

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
	char* str;
	int len;	//문자열 길이

public:
	String();	//디폴트 생성자
	String(const char* mystr);	//생성자
	String(const String& ref);	//복사생성자

	String& operator=(const String& ref);	//대입 연산자 오버로딩
	String operator+(const String& ref);	//+ 연산자 오버로딩
	String& operator+=(const String& ref);	//+= 연산자 오버로딩
	bool operator==(const String& ref);	//==연산자 오버로딩

	friend ostream& operator<<(ostream& os, const String& mystr);
	friend istream& operator>>(istream& is, String& mystr);

	~String();	//소멸자
};

#endif
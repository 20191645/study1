/*
	문제 2:
	클래스 MyFriendInfo, MyFriendDetailInfo에 적절한 생성자와 소멸자 정의
	이를 확인하기 위해 main 함수도 적절히 정의
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo {
private:
	char* name;
	int age;

public:
	MyFriendInfo(const char* myname, int myage) : age(myage) {
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}

	void ShowMyFriendInfo() {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

	~MyFriendInfo() {
		delete[]name;
	}
};

class MyFriendDetailInfo :public MyFriendInfo {
private:
	char* addr;
	char* phone;

public:
	MyFriendDetailInfo(const char* myname, int myage, const char* myaddr, const char* myphone)
		: MyFriendInfo(myname, myage) {
		addr = new char[strlen(myaddr) + 1];
		strcpy(addr, myaddr);

		phone = new char[strlen(myphone) + 1];
		strcpy(phone, myphone);
	}

	void ShowMyFriendDetailInfo() {
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl;
	}

	~MyFriendDetailInfo() {
		delete[]addr;
		delete[]phone;
	}
};

int main() {
	MyFriendDetailInfo fr("Kim", 20, "서울시 마포구", "010-1234-5678");
	fr.ShowMyFriendDetailInfo();

	return 0;
}
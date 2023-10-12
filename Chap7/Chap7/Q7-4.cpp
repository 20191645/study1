/*
	���� 4:
	å�� �ǹ��ϴ� Book Ŭ���� ����,
	�̸� ����Ͽ� ���� å�� �ǹ��ϴ� EBook Ŭ���� ����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
	char* title;	//å�� ����
	char* isbn;		//����ǥ�ص�����ȣ
	int price;		//å�� ����

public:
	Book(const char* t, const char* i, int p)
		:price(p)
	{
		title = new char[strlen(t) + 1];
		strcpy(title, t);

		isbn = new char[strlen(i) + 1];
		strcpy(isbn, i);
	}

	void ShowBookInfo() {
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}

	~Book() {
		delete title;
		delete isbn;
	}
};

class EBook :public Book {
private:
	char* DRMKey;	//���Ȱ��� Ű

public:
	EBook(const char* t, const char* i, int p, const char* key)
		:Book(t, i, p)
	{
		DRMKey = new char[strlen(key) + 1];
		strcpy(DRMKey, key);
	}

	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << endl;
	}

	~EBook() {
		delete DRMKey;
	}
};

int main() {
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;

	EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();

	return 0;
}
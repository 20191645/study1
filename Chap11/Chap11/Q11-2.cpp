/*
	���� 2:
	Q7-4.cpp���� ������ Book, EBook Ŭ�������� ���� ���簡 ����ǵ���
	���� ������, ���� ������ �����ϰ�
	�̸� Ȯ���ϱ� ���� main �Լ��� ������ ����
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

	//���� ���縦 ���� ���� ������ �����ε�
	Book(const Book& ref)
		:price(ref.price) {
		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);
	}

	void ShowBookInfo() {
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}

	~Book() {
		delete[] title;
		delete[] isbn;
	}

	//���� ������ �����ε�
	Book& operator=(const Book& ref) {
		price = ref.price;
		delete[] title;
		delete[] isbn;

		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);

		return *this;
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

	//���� ���縦 ���� ���� ������ �����ε�
	EBook(const EBook& ref)
		:Book(ref) {
		//���� Ŭ������ ���� ������ ȣ��!!
		//Book::Book(ref); <- 72�� ��� ���� ����
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}

	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << endl;
	}

	~EBook() {
		delete[] DRMKey;
	}

	//���� ������ �����ε�
	EBook& operator=(const EBook& ref) {
		delete[] DRMKey;
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);

		//���� Ŭ������ ���� ������ ȣ��!!
		Book::operator=(ref);

		return *this;
	}
};

int main() {
	Book book1("���� C++", "555-12345-890-0", 20000);
	Book book2 = book1;
	Book book3("����", "ISBN", 0);
	book1.ShowBookInfo();
	book2.ShowBookInfo();
	book3.ShowBookInfo();

	book2 = book3;
	book2.ShowBookInfo();
	cout << endl;

	EBook ebook1("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	EBook ebook2 = ebook1;
	EBook ebook3("����", "ISBN2", 0, "xxxxx");
	ebook1.ShowEBookInfo();
	ebook2.ShowEBookInfo();
	ebook3.ShowEBookInfo();

	ebook2 = ebook3;
	ebook2.ShowEBookInfo();

	return 0;
}
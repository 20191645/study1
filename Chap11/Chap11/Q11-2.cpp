/*
	문제 2:
	Q7-4.cpp에서 정의한 Book, EBook 클래스에서 깊은 복사가 진행되도록
	복사 생성자, 대입 연산자 정의하고
	이를 확인하기 위한 main 함수도 적절히 정의
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
	char* title;	//책의 제목
	char* isbn;		//국제표준도서번호
	int price;		//책의 정가

public:
	Book(const char* t, const char* i, int p)
		:price(p)
	{
		title = new char[strlen(t) + 1];
		strcpy(title, t);

		isbn = new char[strlen(i) + 1];
		strcpy(isbn, i);
	}

	//깊은 복사를 위한 복사 생성자 오버로딩
	Book(const Book& ref)
		:price(ref.price) {
		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);
	}

	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}

	~Book() {
		delete[] title;
		delete[] isbn;
	}

	//대입 연산자 오버로딩
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
	char* DRMKey;	//보안관련 키

public:
	EBook(const char* t, const char* i, int p, const char* key)
		:Book(t, i, p)
	{
		DRMKey = new char[strlen(key) + 1];
		strcpy(DRMKey, key);
	}

	//깊은 복사를 위한 복사 생성자 오버로딩
	EBook(const EBook& ref)
		:Book(ref) {
		//기초 클래스의 복사 생성자 호출!!
		//Book::Book(ref); <- 72줄 대신 선언 가능
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}

	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}

	~EBook() {
		delete[] DRMKey;
	}

	//대입 연산자 오버로딩
	EBook& operator=(const EBook& ref) {
		delete[] DRMKey;
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);

		//기초 클래스의 대입 연산자 호출!!
		Book::operator=(ref);

		return *this;
	}
};

int main() {
	Book book1("좋은 C++", "555-12345-890-0", 20000);
	Book book2 = book1;
	Book book3("제목", "ISBN", 0);
	book1.ShowBookInfo();
	book2.ShowBookInfo();
	book3.ShowBookInfo();

	book2 = book3;
	book2.ShowBookInfo();
	cout << endl;

	EBook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	EBook ebook2 = ebook1;
	EBook ebook3("제목군", "ISBN2", 0, "xxxxx");
	ebook1.ShowEBookInfo();
	ebook2.ShowEBookInfo();
	ebook3.ShowEBookInfo();

	ebook2 = ebook3;
	ebook2.ShowEBookInfo();

	return 0;
}
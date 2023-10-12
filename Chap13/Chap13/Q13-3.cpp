/*
	문제 3:
	직접 정의한 스마트 포인터를 템플릿으로 정의
*/

#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	void SetPos(int x, int y) {
		xpos = x;
		ypos = y;
	}
};

template <typename T>
class SmartPtr {
private:
	T* ptr;

public:
	SmartPtr(T* temp) :ptr(temp) {}
	T& operator*() const { return *ptr; }
	T* operator->() const { return ptr; }
	~SmartPtr() { delete ptr; }
};


int main() {
	SmartPtr<Point> sptr1(new Point(1, 2));
	SmartPtr<Point> sptr2(new Point(3, 4));
	sptr1->ShowPosition();
	sptr2->ShowPosition();

	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr1->ShowPosition();
	sptr2->ShowPosition();

	return 0;
}
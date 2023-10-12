/*
	문제 3:
	직사각형을 의미하는 Rectangle 클래스 정의,
	이를 상속하여 정사각형을 의미하는 Square 클래스 정의
*/

#include <iostream>
using namespace std;

class Rectangle {
private:
	int base;
	int height;

public:
	Rectangle(int b, int h) : base(b), height(h) {}

	void ShowAreaInfo() {
		cout << "면적: " << base * height << endl;
	}
};

class Square :public Rectangle {
public:
	Square(int b) : Rectangle(b, b) {}
};

int main(void) {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();

	return 0;
}
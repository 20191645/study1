/*
	���� 3:
	���簢���� �ǹ��ϴ� Rectangle Ŭ���� ����,
	�̸� ����Ͽ� ���簢���� �ǹ��ϴ� Square Ŭ���� ����
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
		cout << "����: " << base * height << endl;
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
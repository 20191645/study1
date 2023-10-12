/*
	���� 2:
	Point Ŭ������ Ȱ���Ͽ� ���� �ǹ��ϴ� Circle Ŭ���� ����
	Circle Ŭ������ ������� Ring Ŭ������ ����
*/

#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;

public:
	void Init(int x, int y) {
		xpos = x;
		ypos = y;
	}

	void ShowPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};


class Circle {
private:
	Point pt;	//���� �߽�
	int radius;	//������

public:
	void Init(int x, int y, int r) {
		pt.Init(x, y);
		radius = r;
	}

	void ShowCircleInfo() const {
		cout << "radius: " << radius << endl;
		pt.ShowPointInfo();
	}
};

class Ring {
private:
	Circle inner;
	Circle outer;

public:
	void Init(int inner_x, int inner_y, int inner_r, int outer_x, int outer_y, int outer_r) {
		inner.Init(inner_x, inner_y, inner_r);
		outer.Init(outer_x, outer_y, outer_r);
	}

	void ShowRingInfo() const {
		cout << "Inner Circle Info..." << endl;
		inner.ShowCircleInfo();
		cout << "Outer Circle Info..." << endl;
		outer.ShowCircleInfo();
	}
};

int main(void) {
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	return 0;

}
/*
	문제 3:
	Q4-2.cpp에서 정의한 클래스 Point, Circle, Ring에 생성자 정의
*/

#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;

public:
	Point(int x, int y) : xpos(x), ypos(y) {}

	void ShowPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};


class Circle {
private:
	Point* pt;	//원의 중심
	int radius;	//반지름

public:
	Circle(int x, int y, int r) {
		pt = new Point(x, y);
		radius = r;
	}

	void ShowCircleInfo() const {
		cout << "radius: " << radius << endl;
		pt->ShowPointInfo();
	}

	~Circle() {
		delete pt;
	}
};

class Ring {
private:
	Circle* inner;
	Circle* outer;

public:
	Ring(int inner_x, int inner_y, int inner_r, int outer_x, int outer_y, int outer_r) {
		inner = new Circle(inner_x, inner_y, inner_r);
		outer = new Circle(outer_x, outer_y, outer_r);
	}

	void ShowRingInfo() const {
		cout << "Inner Circle Info..." << endl;
		inner->ShowCircleInfo();
		cout << "Outer Circle Info..." << endl;
		outer->ShowCircleInfo();
	}

	~Ring() {
		delete inner;
		delete outer;
	}
};

int main(void) {
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	return 0;

}
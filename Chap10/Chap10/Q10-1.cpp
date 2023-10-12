/*
	문제 1-1:
	Point 클래스 - 연산자 오버로딩

	문제 1-2:
	Point 클래스 += 연산자, -= 연산자 오버로딩

	문제 1-3:
	Point 클래스 == 연산자, != 연산자 오버로딩
*/

#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y) { }

	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	// 문제 1-1
	friend Point operator- (const Point pos1, const Point pos2);

	// 문제 1-2
	Point& operator+= (const Point pos) {
		xpos += pos.xpos;
		ypos += pos.ypos;
		return *this;
	}
	Point& operator-= (const Point pos) {
		xpos -= pos.xpos;
		ypos -= pos.ypos;
		return *this;
	}

	// 문제 1-3
	friend bool operator== (const Point pos1, const Point pos2);
	friend bool operator!= (const Point pos1, const Point pos2);
};

// 문제 1-1
Point operator- (const Point pos1, const Point pos2) {
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

// 문제 1-3
bool operator==(const Point pos1, const Point pos2) {
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
		return true;
	else
		return false;
}
bool operator!=(const Point pos1, const Point pos2) {
	if (operator==(pos1, pos2))
		return false;
	else
		return true;

	/*
	return !(pos1==pos2);
	*/
}

int main() {
	Point pos1(10, 20);
	Point pos2(5, 5);
	Point pos3(5, 5);
	Point pos4 = (pos1 += pos2);
	Point pos5 = (pos1 -= pos2);

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	pos4.ShowPosition();
	pos5.ShowPosition();

	if (operator==(pos1, pos2))
		cout << "pos1과 pos2는 같다" << endl;
	if (operator!=(pos1, pos2))
		cout << "pos1과 pos2는 다르다" << endl;


	(pos1 - pos2).ShowPosition();
	(pos2 += pos3).ShowPosition();

	if (pos2 == pos3)
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;

	(pos2 -= pos3).ShowPosition();

	if (pos2 != pos3)
		cout << "not equal" << endl;
	else
		cout << "equal" << endl;

	return 0;
}
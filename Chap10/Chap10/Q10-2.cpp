/*
	���� 2-1:
	Point Ŭ���� - ������ �����ε�

	���� 2-2:
	Point Ŭ���� ~ ������ �����ε�
*/

#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y) {}

	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	// ���� 2-1
	Point operator-() {
		Point pos(-xpos, -ypos);
		return pos;
	}

	// ���� 2-2
	friend Point operator~(const Point& ref);
};

// ���� 2-2
Point operator~(const Point& ref) {
	Point pos(~ref.xpos, ~ref.ypos);
	return pos;
}

int main() {
	Point pos1(2, 3);
	Point pos2 = -pos1;

	pos1.ShowPosition();
	pos2.ShowPosition();
	(-pos2).ShowPosition();
	(~pos2).ShowPosition();
	pos2.ShowPosition();

	return 0;
}
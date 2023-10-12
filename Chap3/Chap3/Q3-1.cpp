/*
	문제 1:
	2차원 평면상 좌표를 표현하는 구조체 Point를 기반으로
	void MovePos(int x, int y);
	void AddPoint(const Point& pos);
	void ShowPosition();
	함수를 구조체 안에 정의한다
*/

#include <iostream>
using namespace std;

struct Point {
	int xpos;
	int ypos;

	void MovePos(int x, int y) {
		xpos += x;
		ypos += y;
	}//점의 좌표이동

	void AddPoint(const Point& pos) {
		xpos += pos.xpos;
		ypos += pos.ypos;
	}//점의 좌표증가

	void ShowPosition() {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}//현재 x, y 좌표정보 출력
};

int main(void) {
	Point pos1 = { 12,4 };
	Point pos2 = { 20,30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition();
	//[5, 14] 출력

	pos1.AddPoint(pos2);
	pos1.ShowPosition();
	//[25, 44] 출력

	return 0;
}
/*
	문제 4:
	2차원 평면상 좌표를 표현하는 구조체 __Point를 기반으로, 두 점의 합을 계산하는 함수를 
	Point& PntAdder(const Point &p1, const Point &p2); 형태로 정의한다
*/

#include <iostream>
using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
}Point;

Point& PntAdder(const Point& p1, const Point& p2) {
	Point* ptemp = new Point;

	ptemp->xpos = p1.xpos + p2.xpos;
	ptemp->ypos = p1.ypos + p2.ypos;

	return *ptemp;
}

int main(void) {
	Point* pt1 = new Point;
	Point* pt2 = new Point;
	pt1->xpos = 3; pt1->ypos = 2;
	pt2->xpos = 5; pt2->ypos = -1;

	Point& pref = PntAdder(*pt1, *pt2);
	cout << "[" << pref.xpos << ", " << pref.ypos << "]" << endl;

	delete pt1;
	delete pt2;
	delete& pref;

	return 0;
}
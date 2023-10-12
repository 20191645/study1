/*
	���� 1:
	2���� ���� ��ǥ�� ǥ���ϴ� ����ü Point�� �������
	void MovePos(int x, int y);
	void AddPoint(const Point& pos);
	void ShowPosition();
	�Լ��� ����ü �ȿ� �����Ѵ�
*/

#include <iostream>
using namespace std;

struct Point {
	int xpos;
	int ypos;

	void MovePos(int x, int y) {
		xpos += x;
		ypos += y;
	}//���� ��ǥ�̵�

	void AddPoint(const Point& pos) {
		xpos += pos.xpos;
		ypos += pos.ypos;
	}//���� ��ǥ����

	void ShowPosition() {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}//���� x, y ��ǥ���� ���
};

int main(void) {
	Point pos1 = { 12,4 };
	Point pos2 = { 20,30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition();
	//[5, 14] ���

	pos1.AddPoint(pos2);
	pos1.ShowPosition();
	//[25, 44] ���

	return 0;
}
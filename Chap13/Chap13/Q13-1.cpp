/*
	���� 1:
	���ڷ� ���޵Ǵ� �� ���� ���� ��ȯ�ϴ� SwapData �Լ��� ���ø����� ����
	Point Ŭ������ ������� Ȯ���ϱ� ���� main �Լ� ����
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
};

template <class T>
void SwapData(T& data1, T& data2) {
	T temp = data1;
	data1 = data2;
	data2 = temp;
}

int main() {
	Point pos1(2, 3);
	Point pos2(4, 5);
	pos1.ShowPosition();
	pos2.ShowPosition();

	SwapData(pos1, pos2);
	pos1.ShowPosition();
	pos2.ShowPosition();

	return 0;
}
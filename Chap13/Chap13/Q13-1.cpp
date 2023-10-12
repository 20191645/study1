/*
	문제 1:
	인자로 전달되는 두 변수 값을 교환하는 SwapData 함수를 템플릿으로 정의
	Point 클래스를 대상으로 확인하기 위해 main 함수 구성
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
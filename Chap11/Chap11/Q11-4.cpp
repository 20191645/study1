/*
	문제 4:
	2차원 배열 접근에 대한 연산자 오버로딩
*/

#include <iostream>
#include <cstdlib>
using namespace std;


class BoundCheckIntArray {
private:
	int* arr;
	int row;
	BoundCheckIntArray(const BoundCheckIntArray& ref) {}
	BoundCheckIntArray& operator=(const BoundCheckIntArray& ref) {}

public:
	BoundCheckIntArray(int len) :row(len) {
		arr = new int[len];
	}

	int& operator[](int idx) {
		if (idx < 0 || idx >= row) {
			cout << "Array out of index exception" << endl;
			exit(1);
		}

		return arr[idx];
	}

	~BoundCheckIntArray() {
		delete[]arr;
	}
};

typedef BoundCheckIntArray* IntArray_PTR;

class BoundCheck2DIntArray {
private:
	IntArray_PTR* arr2D;
	int column;

	BoundCheck2DIntArray(const BoundCheck2DIntArray& ref) {}
	BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& ref) {}

public:
	BoundCheck2DIntArray(int n, int m)
		:column(n) {
		arr2D = new IntArray_PTR[n];
		for (int i = 0; i < n; i++)
			arr2D[i] = new BoundCheckIntArray(m);
	}

	BoundCheckIntArray& operator[](int idx) {
		if (idx < 0 || idx >= column) {
			cout << "Array out of index exception" << endl;
			exit(1);
		}

		return *(arr2D[idx]);
	}

	~BoundCheck2DIntArray() {
		for (int i = 0; i < column; i++) {
			delete arr2D[i];
		}
		delete[] arr2D;
	}
};


int main() {
	BoundCheck2DIntArray arr2d(3, 4);

	for (int n = 0; n < 3; n++)
		for (int m = 0; m < 4; m++)
			arr2d[n][m] = n + m;

	for (int n = 0; n < 3; n++) {
		for (int m = 0; m < 4; m++)
			cout << arr2d[n][m] << ' ';
		cout << endl;
	}
}
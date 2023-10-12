/*
	문제 2:
	배열에 저장된 값을 모두 더해 결과를 반환하는 함수를 템플릿으로 정의
*/

#include <iostream>
using namespace std;

template <class T>
T SumArray(T arr[], int len) {

	//T sum = (T)0;
	T sum = 0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

int main() {
	int iarr[5] = { 1,2,3,4,5 };
	double darr[3] = { 2.4, 1.2, 0.7 };

	//cout << SumArray(iarr, sizeof(iarr)/sizeof(int)) << endl;
	cout << SumArray<int>(iarr, 5) << endl;
	cout << SumArray<double>(darr, 3) << endl;

	return 0;
}
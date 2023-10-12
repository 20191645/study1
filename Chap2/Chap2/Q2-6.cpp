/*
	문제 6:
	'rand, srand, time'을 이용하여 0이상 100미만의 난수를 총 5개 생성한다
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(void) {
	srand(time(NULL));
	cout << "Random Number(5): ";
	for (int i = 0; i < 5; i++) {
		cout << rand() % 100 << " ";
	}

	return 0;
}
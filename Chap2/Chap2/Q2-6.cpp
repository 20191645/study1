/*
	���� 6:
	'rand, srand, time'�� �̿��Ͽ� 0�̻� 100�̸��� ������ �� 5�� �����Ѵ�
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
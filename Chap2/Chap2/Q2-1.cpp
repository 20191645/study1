/*
	���� 1:
	�����ڸ� �̿��Ͽ� ���� �䱸���׿� �����ϴ� �Լ��� ���� �����϶�
	- ���ڷ� ���޵� int�� ������ ���� 1�� ������Ű�� �Լ�
	- ���ڷ� ���޵� int�� ������ ��ȣ�� �ٲٴ� �Լ�
*/

#include <iostream>
using namespace std;

void IncNum(int& ref) { ref++; }
void ChangeSign(int& ref) {
	ref = -ref;
}

int main(void) {
	int num = -1;

	IncNum(num);
	cout << "Increase Result: " << num << endl;

	ChangeSign(num);
	cout << "Change Sign Result: " << num << endl;

	return 0;
}
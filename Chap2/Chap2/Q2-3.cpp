/*
	���� 3:
	������ ������ �����Ͽ� const int ������ ����Ű�� �Ѵ�
	�� ������ ������ �����ϴ� �����ڸ� �ϳ� �����Ѵ�
	������ ������ �����ڸ� �̿��ؼ� ������ ����� ���� ����Ѵ�
*/

#include <iostream>
using namespace std;

int main(void) {
	const int num = 12;
	const int* ptr = &num;

	//const int& ref = *ptr; : Ʋ��
	const int* (&ref) = ptr;

	cout << "ptr value: " << *ptr << endl;
	cout << "ref value: " << *ref << endl;

	return 0;
}
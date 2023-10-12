/*
	문제 3:
	포인터 변수를 선언하여 const int 변수를 가리키게 한다
	이 포인터 변수를 참조하는 참조자를 하나 선언한다
	포인터 변수와 참조자를 이용해서 변수에 저장된 값을 출력한다
*/

#include <iostream>
using namespace std;

int main(void) {
	const int num = 12;
	const int* ptr = &num;

	//const int& ref = *ptr; : 틀림
	const int* (&ref) = ptr;

	cout << "ptr value: " << *ptr << endl;
	cout << "ref value: " << *ref << endl;

	return 0;
}
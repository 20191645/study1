/*
	문제 1:
	함수 BoxVolume를 '매개변수의 디폴트 값 지정' 형태가 아닌,
	'함수 오버로딩'의 형태로 재구현하기
*/

#include <iostream>

int BoxVolume(int length, int width, int height) {
	return length * width * height;
}

int BoxVolume(int length, int width) {
	return length * width;
}

int BoxVolume(int length) {
	return length;
}

int BoxVolume(void) {
	return 1;
}

int main(void) {
	std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
	std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
	std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;
	std::cout << "[D, D, D] : " << BoxVolume() << std::endl;

	return 0;
}
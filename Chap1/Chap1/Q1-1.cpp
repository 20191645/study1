#include <iostream>

int main(void) {

	/*
		문제 1:
		사용자로부터 5개의 정수를 입력 받아 그 합을 출력하는 프로그램
	*/
	int a, b, c, d, e;
	int result = 0;

	std::cout << "1번째 정수 입력: ";
	std::cin >> a;

	std::cout << "2번째 정수 입력: ";
	std::cin >> b;

	std::cout << "3번째 정수 입력: ";
	std::cin >> c;

	std::cout << "4번째 정수 입력: ";
	std::cin >> d;

	std::cout << "5번째 정수 입력: ";
	std::cin >> e;

	result = a + b + c + d + e;
	std::cout << "합계: " << result << std::endl;
	


	/*
		문제 2:
		프로그램 사용자로부터 이름과 전화번호를 문자열로 입력받아,
		그대로 출력하는 프로그램
	*/
	char name[100];
	char tel[100];

	std::cout << "당신의 이름은? ";
	std::cin >> name;

	std::cout << "당신의 전화번호는? ";
	std::cin >> tel;

	std::cout << "당신의 이름은 " << name << "입니다.\n";
	std::cout << "당신의 전화번호는 " << tel << "입니다.\n";
	


	/*
		문제 3:
		숫자를 하나 입력 받아서 그 숫자에 해당하는 구구단을 출력하는 프로그램
	*/
	int n;

	std::cout << "숫자를 입력해주세요: ";
	std::cin >> n;

	for (int i = 1; i < 10; i++) {
		std::cout << n << "*" << i << "=" << n * i << std::endl;
	}


	/*
		문제 4:
		판매원들의 급여 계산 프로그램
	*/
	int n;

	while (1) {
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		std::cin >> n;

		if (n == -1) {
			std::cout << "프로그램을 종료합니다.\n";
			break;
		}

		std::cout << "이번 달 급여: " << 50 + n * 0.12 << "만원\n";
	}

	return 0;
}
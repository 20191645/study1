#include <iostream>

int main(void) {

	/*
		���� 1:
		����ڷκ��� 5���� ������ �Է� �޾� �� ���� ����ϴ� ���α׷�
	*/
	int a, b, c, d, e;
	int result = 0;

	std::cout << "1��° ���� �Է�: ";
	std::cin >> a;

	std::cout << "2��° ���� �Է�: ";
	std::cin >> b;

	std::cout << "3��° ���� �Է�: ";
	std::cin >> c;

	std::cout << "4��° ���� �Է�: ";
	std::cin >> d;

	std::cout << "5��° ���� �Է�: ";
	std::cin >> e;

	result = a + b + c + d + e;
	std::cout << "�հ�: " << result << std::endl;
	


	/*
		���� 2:
		���α׷� ����ڷκ��� �̸��� ��ȭ��ȣ�� ���ڿ��� �Է¹޾�,
		�״�� ����ϴ� ���α׷�
	*/
	char name[100];
	char tel[100];

	std::cout << "����� �̸���? ";
	std::cin >> name;

	std::cout << "����� ��ȭ��ȣ��? ";
	std::cin >> tel;

	std::cout << "����� �̸��� " << name << "�Դϴ�.\n";
	std::cout << "����� ��ȭ��ȣ�� " << tel << "�Դϴ�.\n";
	


	/*
		���� 3:
		���ڸ� �ϳ� �Է� �޾Ƽ� �� ���ڿ� �ش��ϴ� �������� ����ϴ� ���α׷�
	*/
	int n;

	std::cout << "���ڸ� �Է����ּ���: ";
	std::cin >> n;

	for (int i = 1; i < 10; i++) {
		std::cout << n << "*" << i << "=" << n * i << std::endl;
	}


	/*
		���� 4:
		�Ǹſ����� �޿� ��� ���α׷�
	*/
	int n;

	while (1) {
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		std::cin >> n;

		if (n == -1) {
			std::cout << "���α׷��� �����մϴ�.\n";
			break;
		}

		std::cout << "�̹� �� �޿�: " << 50 + n * 0.12 << "����\n";
	}

	return 0;
}
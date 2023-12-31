/*
	���� 2:
	���� ����� Calculator Ŭ���� ���� [����, ����, ����, ������]
	�� ������ ��� �����ߴ��� ����Ѵ�
*/

#include <iostream>
using namespace std;

class Calculator {
private:
	int AddCount;
	int DivCount;
	int MinCount;
	int MulCount;

public:
	void Init();
	double Add(double a, double b);
	double Div(double a, double b);
	double Min(double a, double b);
	double Mul(double a, double b);
	void ShowOpCount();
};


int main(void) {
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();

	return 0;
}

void Calculator::Init() {
	AddCount = 0; DivCount = 0;
	MinCount = 0; MulCount = 0;
}

double Calculator::Add(double a, double b) {
	AddCount++;
	return a + b;
}

double Calculator::Div(double a, double b) {
	if (b == 0) {
		cout << "0���� ���� �� �����ϴ�." << endl;
		return 0;
	}

	DivCount++;
	return a / b;
}

double Calculator::Min(double a, double b) {
	MinCount++;
	return a - b;
}

double Calculator::Mul(double a, double b) {
	MulCount++;
	return a * b;
}

void Calculator::ShowOpCount() {
	cout << "����: " << AddCount << " ����: " << MinCount << " ����: " << MulCount << " ������: " << DivCount << endl;
}
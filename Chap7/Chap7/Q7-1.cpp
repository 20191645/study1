/*
	���� 1:
	Ŭ���� Car�� ������ �����ڸ� �����ϰ�
	�̸� Ȯ���ϱ� ���� main �Լ��� ������ ����
*/

#include <iostream>
using namespace std;

class Car {
private:
	int gasolineGauge;

public:
	Car(int gauge) : gasolineGauge(gauge) {}
	int GetGasGauge() { return gasolineGauge; }
};	//�⺻ ���� �ڵ���

class HybridCar :public Car {
private:
	int electricGauge;

public:
	HybridCar(int gasoline, int electric) : Car(gasoline), electricGauge(electric) {}
	int GetElecGauge() { return electricGauge; }
};	//���̺긮�� �ڵ���

class HybridWaterCar :public HybridCar {
private:
	int waterGuage;

public:
	HybridWaterCar(int gasoline, int electric, int water) :HybridCar(gasoline, electric), waterGuage(water) {}
	void ShowCurrentGauge() {
		cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
		cout << "�ܿ� ���ⷮ: " << GetElecGauge() << endl;
		cout << "�ܿ� ���ͷ�: " << waterGuage << endl;
	}
};

int main() {
	HybridWaterCar c1(10, 20, 30);
	c1.ShowCurrentGauge();

	return 0;
}
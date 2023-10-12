/*
	문제 1:
	클래스 Car에 적절한 생성자를 정의하고
	이를 확인하기 위해 main 함수를 적절히 정의
*/

#include <iostream>
using namespace std;

class Car {
private:
	int gasolineGauge;

public:
	Car(int gauge) : gasolineGauge(gauge) {}
	int GetGasGauge() { return gasolineGauge; }
};	//기본 연료 자동차

class HybridCar :public Car {
private:
	int electricGauge;

public:
	HybridCar(int gasoline, int electric) : Car(gasoline), electricGauge(electric) {}
	int GetElecGauge() { return electricGauge; }
};	//하이브리드 자동차

class HybridWaterCar :public HybridCar {
private:
	int waterGuage;

public:
	HybridWaterCar(int gasoline, int electric, int water) :HybridCar(gasoline, electric), waterGuage(water) {}
	void ShowCurrentGauge() {
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGuage << endl;
	}
};

int main() {
	HybridWaterCar c1(10, 20, 30);
	c1.ShowCurrentGauge();

	return 0;
}
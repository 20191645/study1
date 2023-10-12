/*
	���� 1:
	- ForeignSalesWorker Ŭ���� �߰� ����
	- Employee Ŭ������ �߻� Ŭ������ ��ȯ
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

namespace RISK_LEVEL {
	enum { RISK_A = 3, RISK_B = 2, RISK_C = 1 };
}

class Employee {
private:
	char name[100];

public:
	Employee(const char* name) { strcpy(this->name, name); }

	void ShowYourName() const {
		cout << "name: " << name << endl;
	}

	//���� �����Լ��� ���� -> Employee�� �߻� Ŭ������ ��ȯ
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker :public Employee {
private:
	int salary;	//�� �޿�

public:
	PermanentWorker(const char* name, int money)
		:Employee(name), salary(money) {}

	int GetPay() const { return salary; }

	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker :public Employee {
private:
	int workTime;	//�� �޿� ���� �ð��� �հ�
	int payPerHour;	//�ð��� �޿�

public:
	TemporaryWorker(const char* name, int pay)
		:Employee(name), workTime(0), payPerHour(pay) {}

	void AddWorkTime(int time) {
		workTime += time;
	}//���� �ð��� �߰�

	int GetPay() const {
		return workTime * payPerHour;
	}

	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker :public PermanentWorker {
private:
	int salesResult;	//�� �ǸŽ���
	double bonusRatio;	//�󿩱� ����

public:
	SalesWorker(const char* name, int money, double ratio)
		:PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}

	void AddSalesResult(int value) {
		salesResult += value;
	}

	int GetPay() const {
		//PermanentWorker�� GetPay �Լ� ȣ��
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}

	void ShowSalaryInfo() const {
		//SalesWorkey�� GetPay �Լ� ȣ��
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class ForeignSalesWorker :public SalesWorker {
private:
	const int riskLevel;	//����ũ �ܰ�

public:
	ForeignSalesWorker(const char* name, int money, double ratio, int risk)
		:SalesWorker(name, money, ratio), riskLevel(risk) {}

	int GetRiskPay() const {
		return SalesWorker::GetPay() * (riskLevel / 10.0);
	}

	int GetPay() const {
		return SalesWorker::GetPay() + GetRiskPay();
	}

	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << SalesWorker::GetPay() << endl;
		cout << "risk pay: " << GetRiskPay() << endl;
		cout << "sum: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler {
private:
	Employee* empList[50];
	int empNum;

public:
	EmployeeHandler() :empNum(0) {}

	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}

	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}

	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
		cout << "salary sum: " << sum << endl;
	}

	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main() {
	//���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
	EmployeeHandler handler;

	//�ؿ� ������ ���
	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	//�̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	return 0;
}
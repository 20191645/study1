/*
	���� 1:
	Police Ŭ���� ������� ���� ���簡 �̷�������
	���� ������, ���� ������ �����ϰ�
	�̸� Ȯ���ϱ� ���� main �Լ��� ������ ����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Gun {
private:
	int bullet;	//������ �Ѿ��� ��

public:
	Gun(int bnum) : bullet(bnum) {}

	void Shot() {
		cout << "BBANG!" << endl;
		bullet--;
	}

	//�߰��� �Լ�
	int GetBullet() { return bullet; }
};

class Police {
private:
	int handcuffs;	//������ ������ ��
	Gun* pistol;	//�����ϰ� �ִ� ����

public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff) {
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}

	//���� ���縦 ���� ���� ������ �߰�
	Police(const Police& ref) {
		handcuffs = ref.handcuffs;

		if (ref.pistol != NULL) {
			//Gun ���� ������ ȣ��
			//pistol = new Gun(*(ref.pistol));
			pistol = new Gun(ref.pistol->GetBullet());
		}
		else {
			pistol = NULL;
		}
	}

	void PutHandcuff() {
		cout << "SNAP!" << endl;
		handcuffs--;
	}

	void Shot() {
		if (pistol != NULL)
			pistol->Shot();
		else
			cout << "Hut BBANG!" << endl;
	}

	~Police() {
		if (pistol != NULL)
			delete pistol;
	}

	//���� ������ �����ε� �߰�
	Police& operator=(const Police& ref) {
		handcuffs = ref.handcuffs;

		if (pistol != NULL)
			delete pistol;

		if (ref.pistol != NULL) {
			//Gun ���� ������ ȣ��
			//pistol = new Gun(*(ref.pistol));
			pistol = new Gun(ref.pistol->GetBullet());
		}
		else {
			pistol = NULL;
		}

		return *this;
	}

	//���� Ȯ�ο�
	void ShowNum() {
		cout << "handcuffs: " << handcuffs << endl;
		if (pistol != NULL)
			cout << "bullet: " << pistol->GetBullet() << endl;
		cout << endl;
	}
};


int main() {
	Police p1(5, 3);
	Police p2(0, 1);
	Police p3 = p1;
	p1.ShowNum();
	p2.ShowNum();
	p3.ShowNum();
	p3 = p2;
	p3.ShowNum();

	return 0;
}
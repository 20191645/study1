/*
	문제 1:
	Police 클래스 대상으로 깊은 복사가 이뤄지도록
	대입 연산자, 복사 생성자 정의하고
	이를 확인하기 위해 main 함수도 적절히 정의
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Gun {
private:
	int bullet;	//장전된 총알의 수

public:
	Gun(int bnum) : bullet(bnum) {}

	void Shot() {
		cout << "BBANG!" << endl;
		bullet--;
	}

	//추가된 함수
	int GetBullet() { return bullet; }
};

class Police {
private:
	int handcuffs;	//소유한 수갑의 수
	Gun* pistol;	//소유하고 있는 권총

public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff) {
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}

	//깊은 복사를 위한 복사 생성자 추가
	Police(const Police& ref) {
		handcuffs = ref.handcuffs;

		if (ref.pistol != NULL) {
			//Gun 복사 생성자 호출
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

	//대입 연산자 오버로딩 추가
	Police& operator=(const Police& ref) {
		handcuffs = ref.handcuffs;

		if (pistol != NULL)
			delete pistol;

		if (ref.pistol != NULL) {
			//Gun 복사 생성자 호출
			//pistol = new Gun(*(ref.pistol));
			pistol = new Gun(ref.pistol->GetBullet());
		}
		else {
			pistol = NULL;
		}

		return *this;
	}

	//변수 확인용
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
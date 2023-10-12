/*
	문제 4:
	명함을 의미하는 NameCard 클래스 정의 [성명, 회사이름, 전화번호, 직급]
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
	enum {
		CLERK, SENIOR, ASSIST, MANAGER
	};
}

class NameCard {
private:
	char* name;
	char* comp;
	char* tel;
	int rank;

public:
	NameCard(const char* n, const char* c, const char* t, int r) {
		int n_len = strlen(n);
		int c_len = strlen(c);
		int t_len = strlen(t);

		name = new char[n_len + 1];
		comp = new char[c_len + 1];
		tel = new char[t_len + 1];

		strcpy(name, n);
		strcpy(comp, c);
		strcpy(tel, t);
		rank = r;
	}

	const char* Position(int r) const {
		switch (r) {
		case 0:
			return "사원";
		case 1:
			return "주임";
		case 2:
			return "대리";
		case 3:
			return "과장";
		default:
			return NULL;
		}
	}

	void ShowNameCardInfo() const {
		cout << "이름: " << name << endl;
		cout << "회사: " << comp << endl;
		cout << "전화번호: " << tel << endl;
		cout << "직급: " << Position(rank) << endl << endl;
	}

	~NameCard() {
		delete[]name;
		delete[]comp;
		delete[]tel;
	}
};


int main(void) {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();

	return 0;
}
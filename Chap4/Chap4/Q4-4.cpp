/*
	���� 4:
	������ �ǹ��ϴ� NameCard Ŭ���� ���� [����, ȸ���̸�, ��ȭ��ȣ, ����]
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
			return "���";
		case 1:
			return "����";
		case 2:
			return "�븮";
		case 3:
			return "����";
		default:
			return NULL;
		}
	}

	void ShowNameCardInfo() const {
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << comp << endl;
		cout << "��ȭ��ȣ: " << tel << endl;
		cout << "����: " << Position(rank) << endl << endl;
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
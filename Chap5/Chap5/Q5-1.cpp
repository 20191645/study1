/*
	���� 1:
	Q4-4.cpp���� �����ߴ� NameCard Ŭ������ ���� �����ڸ� ����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
	enum {
		CLERK, SENIOR, ASSIST, MANAGER
	};

	void ShowPosition(int r) {
		switch (r) {
		case CLERK:
			cout << "���" << endl;
			break;
		case SENIOR:
			cout << "����" << endl;
			break;
		case ASSIST:
			cout << "�븮" << endl;
			break;
		case MANAGER:
			cout << "����" << endl;
			break;
		}
	}
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

	//���� ���縦 ���� �߰��� ���� ������
	NameCard(NameCard& copy) {
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
		comp = new char[strlen(copy.comp) + 1];
		strcpy(comp, copy.comp);
		tel = new char[strlen(copy.tel) + 1];
		strcpy(tel, copy.tel);
		rank = copy.rank;
	}

	void ShowNameCardInfo() const {
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << comp << endl;
		cout << "��ȭ��ȣ: " << tel << endl;
		cout << "����: ";
		COMP_POS::ShowPosition(rank);
		cout << endl;
	}

	~NameCard() {
		delete[]name;
		delete[]comp;
		delete[]tel;
	}
};


int main(void) {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;

	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;

	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}
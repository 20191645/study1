/*
	���� 1:
	��� ���ϰ� �ҽ� ������ �����Ͽ� �ϳ��� ���� ���Ϸ� �������ϱ�
*/

#include "Q1-5.h"

void BestComImpl::SimpleFunc(void) {
	std::cout << "BestCom�� ������ �Լ�" << std::endl;
}

void ProgComImpl::SimpleFunc(void) {
	std::cout << "ProgCom�� ������ �Լ�" << std::endl;
}

int main(void) {
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
	return 0;
}
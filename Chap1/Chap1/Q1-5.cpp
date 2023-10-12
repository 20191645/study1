/*
	문제 1:
	헤더 파일과 소스 파일을 구분하여 하나의 실행 파일로 컴파일하기
*/

#include "Q1-5.h"

void BestComImpl::SimpleFunc(void) {
	std::cout << "BestCom이 정의한 함수" << std::endl;
}

void ProgComImpl::SimpleFunc(void) {
	std::cout << "ProgCom이 정의한 함수" << std::endl;
}

int main(void) {
	BestComImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();
	return 0;
}
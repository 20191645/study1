#ifndef __BANKINGCOMMONDECL_H__
#define __BANKINGCOMMONDECL_H__

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

//전역변수

const int NAME_LEN = 20;
//메뉴선택
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
//HighCreditAccount 신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
//계좌종류
enum { NORMAL = 1, CREDIT };

#endif
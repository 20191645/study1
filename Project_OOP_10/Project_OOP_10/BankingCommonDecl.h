#ifndef __BANKINGCOMMONDECL_H__
#define __BANKINGCOMMONDECL_H__

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

//��������

const int NAME_LEN = 20;
//�޴�����
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
//HighCreditAccount �ſ���
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
//��������
enum { NORMAL = 1, CREDIT };

#endif
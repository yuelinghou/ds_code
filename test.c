#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

int main()
{
	//����һ��˳������s
	SL s = { 0 };
	//˳���ӿڹ��ܵĲ���
	SeqListInit(&s);
	SeqListInsert(&s,0,1);
	SeqListInsert(&s, 1, 2);
	SeqListInsert(&s, 2, 3);
	SeqListErase(&s, 1);
	SeqListPrint(&s);
	printf("\n");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

int main()
{
	//定义一个顺序表变量s
	SL s = { 0 };
	//顺序表接口功能的测试
	SeqListInit(&s);
	SeqListInsert(&s,0,1);
	SeqListInsert(&s, 1, 2);
	SeqListInsert(&s, 2, 3);
	SeqListErase(&s, 1);
	SeqListPrint(&s);
	printf("\n");
	return 0;
}

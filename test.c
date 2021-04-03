#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

int main()
{
	//≤‚ ‘
	SListNode* p = NULL;
	SListPushBack(&p, 1);
	SListPushBack(&p, 2);
	SListPushBack(&p, 3);
	SListEraseAfter(p);
	SListEraseAfter(p);
	SListPrint(p);
	return 0;
}
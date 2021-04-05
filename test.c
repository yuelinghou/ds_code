#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

int main()
{
	ListNode* head = ListCreate();
	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPushBack(head, 5);
	/*ListInsert(ListFind(head, 3), 33);*/
	ListErase(ListFind(head,3));
	ListErase(ListFind(head,1));
	ListPrint(head);
	ListDestory(&head);
	return 0;
}

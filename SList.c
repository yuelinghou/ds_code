#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

// 动态申请一个节点
static SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPrint(SListNode* plist)
{
	while (plist)
	{
		printf("%d->", plist->data);
		plist = plist->next;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	SListNode* cur = *pplist;
	if (!cur)
	{
		*pplist = newnode;
	}
	else
	{
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}

void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

void SListPopBack(SListNode** pplist)
{
	SListNode* pre = NULL;
	SListNode* cur = *pplist;
	if (!cur)
	{
		return;
	}
	while (cur->next)
	{
		pre = cur;
		cur = cur->next;
	}
	if (!pre)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	pre->next = NULL;
	free(cur);
	cur = NULL;
}

void SListPopFront(SListNode** pplist)
{
	if (!(*pplist))
	{
		return;
	}
	SListNode* next = (*pplist)->next;
	free(*pplist);
	*pplist = next;
}

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	while (plist)
	{
		if (plist->data == x)
		{
			return plist;
		}
		plist = plist->next;
	}
	return NULL;
}

void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	SListNode* newnode = (SListNode*)BuySListNode(x);
	if (!pos)
	{
		return;
	}
	else
	{
		newnode->next = pos->next;
		pos->next = newnode;
	}
}

void SListEraseAfter(SListNode* pos)
{
	if (!pos)
	{
		return;
	}
	SListNode* tmp = pos->next;
	if (tmp)
	{
		pos->next = tmp->next;
		free(tmp);
		tmp = NULL;
	}
}



#define _CRT_SECURE_NO_WARNINGS 1

//SeqList.c
#include"SeqList.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a=NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

static void CheckCapacity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 2: (ps->capacity) * 2;
		SLDateType* tmp = realloc(ps->a,sizeof(SLDateType)*newcapacity);
		if (tmp)
		{
			ps->a = tmp;
			tmp = NULL;
			ps->capacity = newcapacity;
		}
		else
		{
			printf("malloc fail\n");
			exit(-1);
		}
	}
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	if (!ps->size)
	{
		printf("NULL\n");
	}
}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[(ps->size)] = x;
	ps->size++;
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	CheckCapacity(ps);
	size_t end = ps->size;
	while (end)
	{
		ps->a[end] = ps->a[end-1];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	size_t start = 0;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	if (ps->size)
	{
		ps->size--;
	}
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if (ps->size)
	{
		ps->size--;
	}
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	CheckCapacity(ps);
	size_t end = ps->size;
	while (end > pos)
	{
		ps->a[end] = ps->a[end-1];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	size_t start = pos;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}






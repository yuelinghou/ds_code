#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	ps->top = 0;
	ps->capacity = 4;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackPush(Stack* ps,STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		ps->capacity = ps->top == 0 ? 4 : 2 * ps->top;
		STDataType* tmp = realloc(ps->a, sizeof(STDataType)*ps->capacity);
		if (!tmp)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
	}
	ps->a[ps->top++] = x;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0 ? 1 : 0;
}

int StackSize(Stack* ps)
{
	return ps->top;
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top-1];
}

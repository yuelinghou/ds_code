#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* ps);
void StackDestroy(Stack* ps);
void StackPush(Stack* ps,STDataType x);
void StackPop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);
STDataType StackTop(Stack* ps);


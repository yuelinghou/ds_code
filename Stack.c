#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

// 初始化栈
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

// 入栈
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	// 入栈之前判断容量是否满了
	if (ps->_capacity == ps->_top)
	{
		int newcapacity = ps->_capacity == 0 ? 4 : 2 * ps->_capacity;
		STDataType* tmp = (STDataType*)realloc(ps->_a, newcapacity*sizeof(STDataType));
		if (!tmp)
		{
			printf("Realloc Fail!\n");
			exit(-1);
		}
		ps->_a = tmp;
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top++] = data;
}

// 出栈
void StackPop(Stack* ps)
{
	assert(ps&&ps->_top>0);
	ps->_top--;
}

// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps&&ps->_top > 0);
	return ps->_a[ps->_top-1];
}

// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

// 检测栈是否为空，如果为空返回1，如果不为空返回0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}

// 销毁栈
void StackDestroy(Stack* ps)
{
	assert(ps);
	//释放空间之前先判断是否开辟了空间
	if (ps->_a != NULL)
	{
		free(ps->_a);
		ps->_a = NULL;
	}
	ps->_capacity = 0;
	ps->_top = 0;
}
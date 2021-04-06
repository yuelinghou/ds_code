#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

// ��ʼ��ջ
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

// ��ջ
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	// ��ջ֮ǰ�ж������Ƿ�����
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

// ��ջ
void StackPop(Stack* ps)
{
	assert(ps&&ps->_top>0);
	ps->_top--;
}

// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps&&ps->_top > 0);
	return ps->_a[ps->_top-1];
}

// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ���1�������Ϊ�շ���0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}

// ����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);
	//�ͷſռ�֮ǰ���ж��Ƿ񿪱��˿ռ�
	if (ps->_a != NULL)
	{
		free(ps->_a);
		ps->_a = NULL;
	}
	ps->_capacity = 0;
	ps->_top = 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void SeqListInit(SL* ps)
{
	//断言，保证指针的有效性，防止野指针
	assert(ps);
	ps->data = (SeqListDateType*)malloc(4 * sizeof(SeqListDateType));
	if (ps->data == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

void SqeListDestory(SL* ps)
{
	//断言，保证指针的有效性，防止野指针
	assert(ps);
	free(ps->data);
	ps->data = NULL;
}

void SeqListPrint(SL* ps)
{
	//断言，保证指针的有效性，防止野指针
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->data[i]);
	}
}

//检查空间，如果满了，进行增容
static void CheckCapacity(SL* ps)
{
	//断言，保证指针的有效性，防止野指针
	assert(ps);
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;
		ps->data = (SeqListDateType*)realloc(ps->data, ps->capacity * sizeof(SeqListDateType));
		if (ps->data == NULL)
		{
			printf("增容失败\n");
			exit(-1);
		}
	}
}

void SeqListInsert(SL* ps, size_t pos, SeqListDateType x)
{
	//断言，保证指针的有效性，防止野指针，和保证输入的位置正确
	assert(ps&& pos <= ps->size);
	CheckCapacity(ps);//插入数据之前先检查空间是否足够
	//把pos位置后面的数据往后移动
	int end = (int)ps->size - 1;
	while ((int)pos <= end)
	{
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	//在pos上插入数据
	ps->data[pos] = x;
	//插入之后有效数据加一
	ps->size++;
}

void SeqListErase(SL* ps, size_t pos)
{
	//断言，保证指针的有效性，防止野指针，和保证输入的位置正确
	assert(ps&&pos < ps->size);
	//把pos位置后面的数据往前移动
	size_t start = pos;
	while ((int)start <= (int)ps->size - 2)
	{
		ps->data[start] = ps->data[start + 1];
		start++;
	}
	//删除之后有效数据减一
	ps->size--;
}

void SeqListPushBack(SL* ps, SeqListDateType x)
{
	//断言，保证指针的有效性，防止野指针
	assert(ps);
	CheckCapacity(ps);//插入数据之前先检查空间是否足够
	//直接在最后一个位置插入数据
	ps->data[ps->size] = x;
	//插入之后有效数据加一
	ps->size++;
}

void SeqListPopBack(SL* ps)
{
	//断言，保证指针的有效性，防止野指针
	assert(ps);
	//直接有效数据减一，不会打印出来最后一个数据
	ps->size--;
}

void SeqListPushFront(SL* ps, SeqListDateType x)
{
	//断言，保证指针的有效性，防止野指针
	assert(ps);
	CheckCapacity(ps);//插入数据之前先检查空间是否足够
	//把原来的所有数据往后移动，腾出第一个位置来
	size_t end = ps->size - 1;
	while ((int)end >= 0)
	{
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	//头插
	ps->data[0] = x;
	//有效数据加一
	ps->size++;
}

void SeqListPopFront(SL* ps)
{
	//断言，保证指针的有效性，防止野指针
	assert(ps);
	//把第二个数据开始所有的数据往前移动
	for (size_t i = 0; i < ps->size - 1; i++)
	{
		ps->data[i] = ps ->data[i + 1];
	}
	//有效数据减一
	ps->size--;
}

int SeqListFind(SL* ps, SeqListDateType x)
{
	//断言，保证指针的有效性，防止野指针
	assert(ps);
	//根据下标遍历所有数据来查找
	for (size_t i = 0; i < ps->size; i++)
	{
		if (ps->data[i] == x)
		{
			//找到了就返回下标
			return i;
		}
	}
	//没找到就返回-1
	return -1;
}
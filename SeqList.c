#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void SeqListInit(SL* ps)
{
	//���ԣ���ָ֤�����Ч�ԣ���ֹҰָ��
	assert(ps);
	ps->data = (SeqListDateType*)malloc(4 * sizeof(SeqListDateType));
	if (ps->data == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

void SqeListDestory(SL* ps)
{
	//���ԣ���ָ֤�����Ч�ԣ���ֹҰָ��
	assert(ps);
	free(ps->data);
	ps->data = NULL;
}

void SeqListPrint(SL* ps)
{
	//���ԣ���ָ֤�����Ч�ԣ���ֹҰָ��
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->data[i]);
	}
}

//���ռ䣬������ˣ���������
static void CheckCapacity(SL* ps)
{
	//���ԣ���ָ֤�����Ч�ԣ���ֹҰָ��
	assert(ps);
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;
		ps->data = (SeqListDateType*)realloc(ps->data, ps->capacity * sizeof(SeqListDateType));
		if (ps->data == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
	}
}

void SeqListInsert(SL* ps, size_t pos, SeqListDateType x)
{
	//���ԣ���ָ֤�����Ч�ԣ���ֹҰָ�룬�ͱ�֤�����λ����ȷ
	assert(ps&& pos <= ps->size);
	CheckCapacity(ps);//��������֮ǰ�ȼ��ռ��Ƿ��㹻
	//��posλ�ú�������������ƶ�
	int end = (int)ps->size - 1;
	while ((int)pos <= end)
	{
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	//��pos�ϲ�������
	ps->data[pos] = x;
	//����֮����Ч���ݼ�һ
	ps->size++;
}

void SeqListErase(SL* ps, size_t pos)
{
	//���ԣ���ָ֤�����Ч�ԣ���ֹҰָ�룬�ͱ�֤�����λ����ȷ
	assert(ps&&pos < ps->size);
	//��posλ�ú����������ǰ�ƶ�
	size_t start = pos;
	while ((int)start <= (int)ps->size - 2)
	{
		ps->data[start] = ps->data[start + 1];
		start++;
	}
	//ɾ��֮����Ч���ݼ�һ
	ps->size--;
}

void SeqListPushBack(SL* ps, SeqListDateType x)
{
	//���ԣ���ָ֤�����Ч�ԣ���ֹҰָ��
	assert(ps);
	CheckCapacity(ps);//��������֮ǰ�ȼ��ռ��Ƿ��㹻
	//ֱ�������һ��λ�ò�������
	ps->data[ps->size] = x;
	//����֮����Ч���ݼ�һ
	ps->size++;
}

void SeqListPopBack(SL* ps)
{
	//���ԣ���ָ֤�����Ч�ԣ���ֹҰָ��
	assert(ps);
	//ֱ����Ч���ݼ�һ�������ӡ�������һ������
	ps->size--;
}

void SeqListPushFront(SL* ps, SeqListDateType x)
{
	//���ԣ���ָ֤�����Ч�ԣ���ֹҰָ��
	assert(ps);
	CheckCapacity(ps);//��������֮ǰ�ȼ��ռ��Ƿ��㹻
	//��ԭ�����������������ƶ����ڳ���һ��λ����
	size_t end = ps->size - 1;
	while ((int)end >= 0)
	{
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	//ͷ��
	ps->data[0] = x;
	//��Ч���ݼ�һ
	ps->size++;
}

void SeqListPopFront(SL* ps)
{
	//���ԣ���ָ֤�����Ч�ԣ���ֹҰָ��
	assert(ps);
	//�ѵڶ������ݿ�ʼ���е�������ǰ�ƶ�
	for (size_t i = 0; i < ps->size - 1; i++)
	{
		ps->data[i] = ps ->data[i + 1];
	}
	//��Ч���ݼ�һ
	ps->size--;
}

int SeqListFind(SL* ps, SeqListDateType x)
{
	//���ԣ���ָ֤�����Ч�ԣ���ֹҰָ��
	assert(ps);
	//�����±������������������
	for (size_t i = 0; i < ps->size; i++)
	{
		if (ps->data[i] == x)
		{
			//�ҵ��˾ͷ����±�
			return i;
		}
	}
	//û�ҵ��ͷ���-1
	return -1;
}
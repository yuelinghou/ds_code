#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"

// ��ʼ������
void QueueInit(Queue* q)
{
	//���ԣ���ָ֤�����Ч��
	assert(q);
	//��ָ���һ�������һ���ڵ��ָ���ʼ��ΪNULL
	q->_head = q->_tail = NULL;
}

// ��β�����
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	//�¿���һ���µĽڵ�
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	//���µĽڵ��ʼ��
	newnode->_data = data;
	newnode->_pnext = NULL;
	//1.����û�нڵ�����
	if (q->_tail == NULL)
	{
		q->_head = q->_tail = newnode;
	}
	else//2.�����Ѿ��нڵ�����
	{
		q->_tail->_pnext = newnode;
		q->_tail = newnode;
	}
}

// ��ͷ������
void QueuePop(Queue* q)
{
	assert(q);
	//1.����ֻ��һ���ڵ�����
	//�ͷ��˿ռ��Ҫ��ԭ��ָ���һ�������һ���ڵ��ָ����ΪNULL
	if (q->_head->_pnext == NULL)
	{
		free(q->_head);
		q->_head = q->_tail = NULL;
	}
	//2.��������һ���ڵ�����
	else
	{
		//�ͷŵ�һ���ڵ�ǰҪ�����ڶ����ڵ�ĵ�ַ
		QNode* next = q->_head->_pnext;
		//�ͷŵ�һ���ڵ�
		free(q->_head);
		//֮ǰ�ĵڶ����ڵ��Ϊ��һ���ڵ�
		q->_head = next;
	}
}

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_head->_data;
}

// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_tail->_data;
}

// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q)
{
	assert(q);
	QNode* cur = q->_head;
	int n = 0;
	//��������
	while (cur)
	{
		n++;
		cur = cur->_pnext;
	}
	return n;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ���1������ǿշ���0
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_head == NULL ? 1 : 0;
}

// ���ٶ���
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->_head;
	//��������
	while (cur)
	{
		//����֮ǰ������һ���ڵ�ĵ�ַ
		QNode* next = cur->_pnext;
		free(cur);
		cur = next;
	}
	//��ֹҰָ��
	q->_head = q->_tail = NULL;
}

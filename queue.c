#define _CRT_SECURE_NO_WARNINGS 1

#include "queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	while (pq->head)
	{
		QueueNode* tmp = pq->head->next;
		free(pq->head);
		pq->head = tmp;
	}
	pq->head = NULL;
	pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->next = NULL;
	newnode->data = x;
	if (!pq->head)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	QueueNode* tmp = pq->head->next;
	free(pq->head);
	pq->head = tmp;
}

int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL ? 1 : 0;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->tail);
	return pq->tail->data;
}

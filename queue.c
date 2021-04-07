#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"

// 初始化队列
void QueueInit(Queue* q)
{
	//断言，保证指针的有效性
	assert(q);
	//把指向第一个和最后一个节点的指针初始化为NULL
	q->_head = q->_tail = NULL;
}

// 队尾入队列
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	//新开辟一个新的节点
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	//对新的节点初始化
	newnode->_data = data;
	newnode->_pnext = NULL;
	//1.队列没有节点的情况
	if (q->_tail == NULL)
	{
		q->_head = q->_tail = newnode;
	}
	else//2.队列已经有节点的情况
	{
		q->_tail->_pnext = newnode;
		q->_tail = newnode;
	}
}

// 队头出队列
void QueuePop(Queue* q)
{
	assert(q);
	//1.队列只有一个节点的情况
	//释放了空间后还要把原来指向第一个和最后一个节点的指针置为NULL
	if (q->_head->_pnext == NULL)
	{
		free(q->_head);
		q->_head = q->_tail = NULL;
	}
	//2.队列至少一个节点的情况
	else
	{
		//释放第一个节点前要保留第二个节点的地址
		QNode* next = q->_head->_pnext;
		//释放第一个节点
		free(q->_head);
		//之前的第二个节点变为第一个节点
		q->_head = next;
	}
}

// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_head->_data;
}

// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_tail->_data;
}

// 获取队列中有效元素个数
int QueueSize(Queue* q)
{
	assert(q);
	QNode* cur = q->_head;
	int n = 0;
	//遍历队列
	while (cur)
	{
		n++;
		cur = cur->_pnext;
	}
	return n;
}

// 检测队列是否为空，如果为空返回1，如果非空返回0
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_head == NULL ? 1 : 0;
}

// 销毁队列
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->_head;
	//遍历队列
	while (cur)
	{
		//销毁之前保留后一个节点的地址
		QNode* next = cur->_pnext;
		free(cur);
		cur = next;
	}
	//防止野指针
	q->_head = q->_tail = NULL;
}

#pragma once

//ͷ�ļ�������
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//�ڵ�洢����������
typedef int QDataType;

// ��ʽ�ṹ����ʾ����
typedef struct QListNode
{
	struct QListNode* _pnext;
	QDataType _data;
}QNode;

// ���еĽṹ
typedef struct Queue
{
	QNode* _head;
	QNode* _tail;
}Queue;

// ��ʼ������
void QueueInit(Queue* q);

// ��β�����
void QueuePush(Queue* q, QDataType data);

// ��ͷ������
void QueuePop(Queue* q);

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q);

// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q);

// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q);

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* q);

// ���ٶ���
void QueueDestroy(Queue* q);

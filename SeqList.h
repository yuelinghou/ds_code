#pragma once

//C�⺯����ͷ�ļ�����
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//�Զ���˳���Ԫ�ص�����
typedef int SeqListDateType;

//˳���Ľṹ��
typedef struct SeqList
{
	SeqListDateType* data;
	size_t size;
	size_t capacity;
}SL;

//��������ɾ��Ľӿ�
//˳���ĳ�ʼ��
void SeqListInit(SL* ps);
//˳�������
void SqeListDestory(SL* ps);
//˳����ӡ
void SeqListPrint(SL* ps);
//˳�����posλ�ò���x
void SeqListInsert(SL* ps, size_t pos, SeqListDateType x);
//˳���ɾ��posλ�õ�ֵ
void SeqListErase(SL* ps, size_t pos);
//˳���β��
void SeqListPushBack(SL* ps, SeqListDateType x);
//˳���βɾ
void SeqListPopBack(SL* ps);
//˳���ͷ��
void SeqListPushFront(SL* ps, SeqListDateType x);
//˳���ͷɾ
void SeqListPopFront(SL* ps);
//˳������(�ҵ��˷����±꣬�Ҳ�������-1)
int SeqListFind(SL* ps, SeqListDateType x);



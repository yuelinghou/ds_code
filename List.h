#pragma once

//�⺯��������
#include<stdio.h>
#include<stdlib.h>

//�ڵ���������͵��ض���
typedef int LTDataType;

//�ڵ�����
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

// �������������ͷ���.
ListNode* ListCreate();

// ˫����������
void ListDestory(ListNode** pplist);

// ˫�������ӡ
void ListPrint(ListNode* plist);

// ˫������β��
void ListPushBack(ListNode* plist, LTDataType x);

// ˫������βɾ
void ListPopBack(ListNode* plist);

// ˫������ͷ��
void ListPushFront(ListNode* plist, LTDataType x);

// ˫������ͷɾ
void ListPopFront(ListNode* plist);

// ˫���������
ListNode* ListFind(ListNode* plist, LTDataType x);

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);


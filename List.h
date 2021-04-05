#pragma once

//库函数的声明
#include<stdio.h>
#include<stdlib.h>

//节点的数据类型的重定义
typedef int LTDataType;

//节点声明
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

// 创建返回链表的头结点.
ListNode* ListCreate();

// 双向链表销毁
void ListDestory(ListNode** pplist);

// 双向链表打印
void ListPrint(ListNode* plist);

// 双向链表尾插
void ListPushBack(ListNode* plist, LTDataType x);

// 双向链表尾删
void ListPopBack(ListNode* plist);

// 双向链表头插
void ListPushFront(ListNode* plist, LTDataType x);

// 双向链表头删
void ListPopFront(ListNode* plist);

// 双向链表查找
ListNode* ListFind(ListNode* plist, LTDataType x);

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);


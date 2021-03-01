#pragma once

//C库函数的头文件声明
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//自定义顺序表元素的类型
typedef int SeqListDateType;

//顺序表的结构体
typedef struct SeqList
{
	SeqListDateType* data;
	size_t size;
	size_t capacity;
}SL;

//基本的增删查改接口
//顺序表的初始化
void SeqListInit(SL* ps);
//顺序表销毁
void SqeListDestory(SL* ps);
//顺序表打印
void SeqListPrint(SL* ps);
//顺序表在pos位置插入x
void SeqListInsert(SL* ps, size_t pos, SeqListDateType x);
//顺序表删除pos位置的值
void SeqListErase(SL* ps, size_t pos);
//顺序表尾插
void SeqListPushBack(SL* ps, SeqListDateType x);
//顺序表尾删
void SeqListPopBack(SL* ps);
//顺序表头插
void SeqListPushFront(SL* ps, SeqListDateType x);
//顺序表头删
void SeqListPopFront(SL* ps);
//顺序表查找(找到了返回下标，找不到返回-1)
int SeqListFind(SL* ps, SeqListDateType x);



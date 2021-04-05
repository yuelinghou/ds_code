#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

// 创建并返回链表的头节点
//PS:头结点就是不存有效数据，只存第一个和最后一个节点地址的节点
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	//指针变量最好初始化，防止野指针
	head->_prev = head;
	head->_next = head;
	//返回头节点
	return head;
}

// 创建并返回新的节点
static ListNode* BuyListNode(LTDataType x)
{
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	//对新节点进行初始化
	new_node->_data = x;
	new_node->_prev = NULL;
	new_node->_next = NULL;
	return new_node;
}

// 双向链表销毁
//PS：形参为头节点的指针，传指针是为了在最后销毁时把外面的头节点置为NULL，防止野指针
void ListDestory(ListNode** pplist)
{
	//把链表的第一个节点给cur
	ListNode* cur = (*pplist)->_next;
	//当cur等于头节点时说明链表已经遍历完了
	while (cur != *pplist)
	{
		//销毁节点之前先把cur的下一个节点保存起来
		ListNode* tmp = cur->_next;
		free(cur);
		cur = tmp;
	}
	//最后把头节点置为NULL
	*pplist = NULL;
}

// 双向链表打印
void ListPrint(ListNode* plist)
{
	//遍历链表
	ListNode* cur = plist->_next;
	while (cur!=plist)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

// 双向链表尾插
void ListPushBack(ListNode* plist, LTDataType x)
{
	//新的节点
	ListNode* new_node = BuyListNode(x);
	//链表的最后一个节点
	ListNode* list_tail = plist->_prev;
	//连接头节点 - 新的节点 - 链表的最后一个节点
	//让新的节点变为链表最后一个节点
	list_tail->_next = new_node;
	new_node->_prev = list_tail;
	plist->_prev = new_node;
	new_node->_next = plist;
}

// 双向链表尾删
void ListPopBack(ListNode* plist)
{
	//不能把头节点伤了
	if (plist->_prev == plist)
	{
		return;
	}
	//链表的最后一个节点
	ListNode* list_tail = plist->_prev;
	//链表的倒数第二个节点
	ListNode* tail_prev = list_tail->_prev;
	//释放最后一个节点
	free(list_tail);
	//连接倒数第二个节点和头节点
	tail_prev->_next = plist;
	plist->_prev = tail_prev;
}

// 双向链表头插
void ListPushFront(ListNode* plist, LTDataType x)
{
	//开辟一个新的节点
	ListNode* new_node = BuyListNode(x);
	//链表的第一个节点
	ListNode* list_head = plist->_next;
	//连接头节点 - 新的节点 - 链表的第一个节点
	plist->_next = new_node;
	new_node->_prev = plist;
	new_node->_next = list_head;
	list_head->_prev = new_node;
}

// 双向链表头删
void ListPopFront(ListNode* plist)
{
	//不能把头节点删了
	if (plist->_next == plist)
	{
		return;
	}
	//链表的第一个节点
	ListNode* list_head = plist->_next;
	//链表的第二个节点
	ListNode* head_next = list_head->_next;
	//删除第一个节点
	free(list_head);
	//连接头节点 - 链表的第二个节点
	plist->_next = head_next;
	head_next->_prev = plist;
}

// 双向链表查找
ListNode* ListFind(ListNode* plist, LTDataType x)
{
	//遍历链表
	ListNode* cur = plist->_next;
	while (cur != plist)
	{
		if (cur->_data == x)
		{
			//找到了就返回节点的地址
			return cur;
		}
		cur = cur->_next;
	}
	//找不到就返回NULL
	return NULL;
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	//开辟新的节点
	ListNode* new_node = BuyListNode(x);
	//pos前一个节点
	ListNode* pos_prev = pos->_prev;
	//连接pos前一个节点 - 新的节点 - pos位置节点
	pos_prev->_next = new_node;
	new_node->_prev = pos_prev;
	new_node->_next = pos;
	pos->_prev = new_node;
}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	//pos位置前一个节点
	ListNode* pos_prev = pos->_prev;
	//pos位置后一个节点
	ListNode* pos_next = pos->_next;
	//删除pos位置节点
	free(pos);
	//连接pos位置前一个节点和pos位置后一个节点
	pos_prev->_next = pos_next;
	pos_next->_prev = pos_prev;
}

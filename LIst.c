#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

// ���������������ͷ�ڵ�
//PS:ͷ�����ǲ�����Ч���ݣ�ֻ���һ�������һ���ڵ��ַ�Ľڵ�
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	//ָ�������ó�ʼ������ֹҰָ��
	head->_prev = head;
	head->_next = head;
	//����ͷ�ڵ�
	return head;
}

// �����������µĽڵ�
static ListNode* BuyListNode(LTDataType x)
{
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	//���½ڵ���г�ʼ��
	new_node->_data = x;
	new_node->_prev = NULL;
	new_node->_next = NULL;
	return new_node;
}

// ˫����������
//PS���β�Ϊͷ�ڵ��ָ�룬��ָ����Ϊ�����������ʱ�������ͷ�ڵ���ΪNULL����ֹҰָ��
void ListDestory(ListNode** pplist)
{
	//������ĵ�һ���ڵ��cur
	ListNode* cur = (*pplist)->_next;
	//��cur����ͷ�ڵ�ʱ˵�������Ѿ���������
	while (cur != *pplist)
	{
		//���ٽڵ�֮ǰ�Ȱ�cur����һ���ڵ㱣������
		ListNode* tmp = cur->_next;
		free(cur);
		cur = tmp;
	}
	//����ͷ�ڵ���ΪNULL
	*pplist = NULL;
}

// ˫�������ӡ
void ListPrint(ListNode* plist)
{
	//��������
	ListNode* cur = plist->_next;
	while (cur!=plist)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

// ˫������β��
void ListPushBack(ListNode* plist, LTDataType x)
{
	//�µĽڵ�
	ListNode* new_node = BuyListNode(x);
	//��������һ���ڵ�
	ListNode* list_tail = plist->_prev;
	//����ͷ�ڵ� - �µĽڵ� - ��������һ���ڵ�
	//���µĽڵ��Ϊ�������һ���ڵ�
	list_tail->_next = new_node;
	new_node->_prev = list_tail;
	plist->_prev = new_node;
	new_node->_next = plist;
}

// ˫������βɾ
void ListPopBack(ListNode* plist)
{
	//���ܰ�ͷ�ڵ�����
	if (plist->_prev == plist)
	{
		return;
	}
	//��������һ���ڵ�
	ListNode* list_tail = plist->_prev;
	//����ĵ����ڶ����ڵ�
	ListNode* tail_prev = list_tail->_prev;
	//�ͷ����һ���ڵ�
	free(list_tail);
	//���ӵ����ڶ����ڵ��ͷ�ڵ�
	tail_prev->_next = plist;
	plist->_prev = tail_prev;
}

// ˫������ͷ��
void ListPushFront(ListNode* plist, LTDataType x)
{
	//����һ���µĽڵ�
	ListNode* new_node = BuyListNode(x);
	//����ĵ�һ���ڵ�
	ListNode* list_head = plist->_next;
	//����ͷ�ڵ� - �µĽڵ� - ����ĵ�һ���ڵ�
	plist->_next = new_node;
	new_node->_prev = plist;
	new_node->_next = list_head;
	list_head->_prev = new_node;
}

// ˫������ͷɾ
void ListPopFront(ListNode* plist)
{
	//���ܰ�ͷ�ڵ�ɾ��
	if (plist->_next == plist)
	{
		return;
	}
	//����ĵ�һ���ڵ�
	ListNode* list_head = plist->_next;
	//����ĵڶ����ڵ�
	ListNode* head_next = list_head->_next;
	//ɾ����һ���ڵ�
	free(list_head);
	//����ͷ�ڵ� - ����ĵڶ����ڵ�
	plist->_next = head_next;
	head_next->_prev = plist;
}

// ˫���������
ListNode* ListFind(ListNode* plist, LTDataType x)
{
	//��������
	ListNode* cur = plist->_next;
	while (cur != plist)
	{
		if (cur->_data == x)
		{
			//�ҵ��˾ͷ��ؽڵ�ĵ�ַ
			return cur;
		}
		cur = cur->_next;
	}
	//�Ҳ����ͷ���NULL
	return NULL;
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	//�����µĽڵ�
	ListNode* new_node = BuyListNode(x);
	//posǰһ���ڵ�
	ListNode* pos_prev = pos->_prev;
	//����posǰһ���ڵ� - �µĽڵ� - posλ�ýڵ�
	pos_prev->_next = new_node;
	new_node->_prev = pos_prev;
	new_node->_next = pos;
	pos->_prev = new_node;
}

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	//posλ��ǰһ���ڵ�
	ListNode* pos_prev = pos->_prev;
	//posλ�ú�һ���ڵ�
	ListNode* pos_next = pos->_next;
	//ɾ��posλ�ýڵ�
	free(pos);
	//����posλ��ǰһ���ڵ��posλ�ú�һ���ڵ�
	pos_prev->_next = pos_next;
	pos_next->_prev = pos_prev;
}

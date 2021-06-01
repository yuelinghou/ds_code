#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"

BTNode* BinaryTreeCreate(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	// �ѽڵ�ĳ�Ա��ʼ��
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	// ��󷵻ؽڵ�ĵ�ַ
	return newnode;
}

void BinaryTreeDestory(BTNode* root)
{
	if (!root)
	{
		return;
	}
	// �����������������һ������ÿ���ڵ�
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}

int BinaryTreeSize(BTNode* root)
{
	// �����Ļ�����0���ڵ�
	// ���յĻ����ڵ������������ڵ����1�����������ڵ���������������ڵ����
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	// �����Ļ�Ҷ�ӽڵ��������0
	if (!root)
	{
		return 0;
	}
	// ���յ����
	// ��ǰ�ڵ���Ҷ�ӽڵ�ͷ���1
	if (!root->left && !root->right)
	{
		return 1;
	}
    // ��ǰ����Ҷ�ӽڵ�ͼ����ݹ����Һ��ӽڵ�
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	// �����Ļ�����0
	if (!root)
	{
		return 0;
	}
	// kΪ1���k��Ľڵ�
	if (k == 1)
	{
		return 1;
	}
	// k��Ϊ1����������һ����
	else
	{
		return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
	}
}

// ע�����Ҫ���ؽڵ�ĵ�ַ
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	// �����Ļ��Ҳ��������ؿ�
	if (!root)
	{
		return NULL;
	}
	// ���ڵ����Ҫ�ҵģ��ͷ��ظ��ڵ�
	if (root->data == x)
	{
		return root;
	}
	else
	{
		// ���������ҵ��ˣ��ͷ����Ǹ��ڵ�
		BTNode* lret = BinaryTreeFind(root->left, x);
		if (lret)
			return lret;
		// ���������ҵ��ˣ�Ҳ�����Ǹ��ڵ�
		BTNode* rret = BinaryTreeFind(root->right, x);
		if (rret)
			return rret;
	}
	// �Ҳ���������null
	return NULL;
}

// ǰ�򣺸�->������->������
void BinaryTreePrevOrder(BTNode* root)
{
	// �����Ļ�ֱ�ӽ�������
	if (!root)
	{
		return;
	}
	// ��ӡ�ڵ�
	printf("%c ", root->data);
	// �ݹ����������
	BinaryTreePrevOrder(root->left);
	// �ݹ����������
	BinaryTreePrevOrder(root->right);
}

void BinaryTreeInOrder(BTNode* root)
{
	// �����Ļ�ֱ�ӽ�������
	if (!root)
	{
		return;
	}
	// �ݹ����������
	BinaryTreeInOrder(root->left);
	// ��ӡ�ڵ�
	printf("%c ", root->data);
	// �ݹ����������
	BinaryTreeInOrder(root->right);
}

void BinaryTreePostOrder(BTNode* root)
{
	// �����Ļ�ֱ�ӽ�������
	if (!root)
	{
		return;
	}
	// �ݹ����������
	BinaryTreePostOrder(root->left);
	// �ݹ����������
	BinaryTreePostOrder(root->right);
	// ��ӡ�ڵ�
	printf("%c ", root->data);
}

void BinaryTreeLevelOrder(BTNode* root)
{
	// ����һ�����࣬���ڴ�Žڵ��ָ��
	std::queue<BTNode*> p;
	// �Ѹ��ڵ������
	if (root)
	{
		p.push(root);
	}
	while (!p.empty())
	{
		// ���õ���ͷ�ڵ�
		BTNode* front = p.front();
		// ��ͷ�ڵ㴦����
		p.pop();
		// ��ӡ�ڵ��ֵ
		printf("%c ", front->data);
		// �����к�Ѹýڵ�����Һ���Ҳ���������
		if (front->left)
		{
			p.push(front->left);
		}
		if (front->right)
		{
			p.push(front->right);
		}
	}
}

void BinaryTreeLevelOrder(BTNode* root)
{
	std::queue<BTNode*> p;
	if (root)
	{
		p.push(root);
	}
	while (!p.empty())
	{
		BTNode* front = p.front();
		p.pop();
		printf("%c ", front->data);
		if (front->left)
		{
			p.push(front->left);
		}
		if (front->right)
		{
			p.push(front->right);
		}
	}
}

bool BinaryTreeComplete(BTNode* root)
{
	std::queue<BTNode*> p;
	// �ʼ�ĸ��ڵ㣬���ǿյĻ�������У�ִֻ��һ�Σ�
	if (root)
	{
		p.push(root);
	}
	while (!p.empty())
	{
		// �õ���ͷ����
		BTNode* front = p.front();
		// ����ͷ����
		p.pop();
		// �ó������Ǹ���ͷ�ڵ㲻�յĻ������������Һ��ӽڵ㶼�����
		// �յĻ��˳�ѭ��
		if (!front)
		{
			break;
		}
		p.push(front->left);
		p.push(front->right);
	}
	// ��������л��зǿսڵ㣬�Ͳ�����ȫ������
	while (!p.empty())
	{
		if (p.front())
		{
			return false;
		}
		p.pop();
	}
	return true;
}







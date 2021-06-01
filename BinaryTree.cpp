#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"

BTNode* BinaryTreeCreate(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	// 把节点的成员初始化
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	// 最后返回节点的地址
	return newnode;
}

void BinaryTreeDestory(BTNode* root)
{
	if (!root)
	{
		return;
	}
	// 后序遍历，从下往上一次销毁每个节点
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}

int BinaryTreeSize(BTNode* root)
{
	// 空树的话就是0个节点
	// 不空的话，节点个数就是自身节点个数1加上左子树节点个数加上有子树节点个数
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	// 空树的话叶子节点个数就是0
	if (!root)
	{
		return 0;
	}
	// 不空的情况
	// 当前节点是叶子节点就返回1
	if (!root->left && !root->right)
	{
		return 1;
	}
    // 当前不是叶子节点就继续递归左右孩子节点
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	// 空树的话返回0
	if (!root)
	{
		return 0;
	}
	// k为1算第k层的节点
	if (k == 1)
	{
		return 1;
	}
	// k不为1，继续往下一层走
	else
	{
		return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
	}
}

// 注意最后要返回节点的地址
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	// 空树的话找不到，返回空
	if (!root)
	{
		return NULL;
	}
	// 根节点就是要找的，就返回根节点
	if (root->data == x)
	{
		return root;
	}
	else
	{
		// 左子树中找到了，就返回那个节点
		BTNode* lret = BinaryTreeFind(root->left, x);
		if (lret)
			return lret;
		// 右子树若找到了，也返回那个节点
		BTNode* rret = BinaryTreeFind(root->right, x);
		if (rret)
			return rret;
	}
	// 找不到，返回null
	return NULL;
}

// 前序：根->左子树->右子树
void BinaryTreePrevOrder(BTNode* root)
{
	// 空树的话直接结束函数
	if (!root)
	{
		return;
	}
	// 打印节点
	printf("%c ", root->data);
	// 递归遍历左子树
	BinaryTreePrevOrder(root->left);
	// 递归遍历右子树
	BinaryTreePrevOrder(root->right);
}

void BinaryTreeInOrder(BTNode* root)
{
	// 空树的话直接结束函数
	if (!root)
	{
		return;
	}
	// 递归遍历左子树
	BinaryTreeInOrder(root->left);
	// 打印节点
	printf("%c ", root->data);
	// 递归遍历右子树
	BinaryTreeInOrder(root->right);
}

void BinaryTreePostOrder(BTNode* root)
{
	// 空树的话直接结束函数
	if (!root)
	{
		return;
	}
	// 递归遍历左子树
	BinaryTreePostOrder(root->left);
	// 递归遍历右子树
	BinaryTreePostOrder(root->right);
	// 打印节点
	printf("%c ", root->data);
}

void BinaryTreeLevelOrder(BTNode* root)
{
	// 创建一个队类，用于存放节点的指针
	std::queue<BTNode*> p;
	// 把根节点入队列
	if (root)
	{
		p.push(root);
	}
	while (!p.empty())
	{
		// 先拿到队头节点
		BTNode* front = p.front();
		// 队头节点处队列
		p.pop();
		// 打印节点的值
		printf("%c ", front->data);
		// 出队列后把该节点的左右孩子也放入队列中
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
	// 最开始的根节点，不是空的话就入队列（只执行一次）
	if (root)
	{
		p.push(root);
	}
	while (!p.empty())
	{
		// 拿到队头数据
		BTNode* front = p.front();
		// 出队头数据
		p.pop();
		// 拿出来的那个队头节点不空的话，把他的左右孩子节点都入队列
		// 空的话退出循环
		if (!front)
		{
			break;
		}
		p.push(front->left);
		p.push(front->right);
	}
	// 如果队列中还有非空节点，就不是完全二叉树
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







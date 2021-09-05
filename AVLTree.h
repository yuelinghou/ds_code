#pragma once
#include <iostream>
#include <map>
using namespace std;

// 树节点的定义
template<class k, class v>
struct AVLNode
{
  // 构造一个节点
  AVLNode(const pair<k,v>& kv)
    :_left(nullptr)
    ,_right(nullptr)
    ,_parent(nullptr)
    ,_kv(kv)
    ,_bf(0)
  {}
  
  AVLNode<k,v>* _left; 
  AVLNode<k,v>* _right; 
  AVLNode<k,v>* _parent;
  pair<k,v> _kv;
  int _bf;
};

// 树
template<class k, class v>
class AVLTree
{
  public:
    typedef AVLNode<k,v> Node;
    
    // 插入节点
    bool Insert(const pair<k,v>& kv)
    {
      // 空树的话，就让插入的那个节点作为根
      if(!_root)
      {
        _root=new Node(kv);
        return true;
      }
      // 不是空树，就按照搜索树的性质找到插入的位置和它的父亲
      Node* cur=_root;
      Node* parent=nullptr;
      while(cur)
      {
        parent=cur;
        if(cur->_kv.first==kv.first)
        {
          return false;
        }
        else if(cur->_kv.first > kv.first)
        {
          cur=cur->_left;
        }
        else 
        {
          cur=cur->_right;
        }
      }
      // 创建要插入的节点
      Node* newNode=new Node(kv);
      // 更新关系，插入节点
      newNode->_parent=parent;
      if(parent->_kv.first < newNode->_kv.first)
      {
        parent->_right=newNode;
      }
      else 
      {
        parent->_left=newNode;
      }
      
      cur=newNode;
      parent=cur->_parent;
      while(parent)
      {
        // 向上更新平衡因子
        if(cur==parent->_left)
        {
          --(parent->_bf);
        }
        else 
        {
          ++(parent->_bf);
        }
        // 检查是否需要调整
        // 0的话就平衡了
        // -1或1的话还要向上更新
        // -2或2的话需要旋转处理
        if(parent->_bf==0)// 平衡因子为0，整棵树高度依然不变，只是补了原来低的那边，依然平衡
        {
          break;
        }
        else if(parent->_bf==1 || parent->_bf==-1)// 整棵树高度增加了，但是这颗树依然平衡，再往上是否平衡不知道需要继续验证
        {
          cur=parent;
          parent=parent->_parent;
        }
        else if(parent->_bf==2 || parent->_bf==-2)
        {
          // 右子树高
          if(parent->_bf==2)
          {
            if(cur->_bf==1)// 右子树的右子树也高 -->  左单旋
            {
              RotateL(parent);
            }
            else if(cur->_bf==-1)// 右子树的左子树也高  -->  右左双旋
            {
              RotateRL(parent);
            }
          }
          else if(parent->_bf==-2)// 左子树高
          {
            if(cur->_bf==-1)// 左子树的左子树也高  -->  右单旋
            {
              RotateR(parent);
            }
            else if(cur->_bf==1)// 左子树的右子树也高  -->  左右双旋
            {
              RotateLR(parent);
            }
          }
          break;
        }
      }
      return true;
    }

    // 得到树的高度
    int Height(Node* root)
    {
      if(!root)
      {
        return 0;
      }

      int letfHeight=Height(root->_left);
      int rightHeight=Height(root->_right); 

      return letfHeight > rightHeight? letfHeight+1 : rightHeight+1;
    }

    // 判断树是否平衡
    bool _IsBalance(Node* root)
    {
      if(!root)
      {
        return true;
      }

      int letfHeight=Height(root->_left);
      int rightHeight=Height(root->_right);
      
      return abs(letfHeight-rightHeight)<=1
        && _IsBalance(root->_left)
        && _IsBalance(root->_right);
    }

    bool  IsBalance()
    {
      return _IsBalance(_root); 
    }

    // 中序遍历，用来检查是否满足搜索树性质(中序遍历的结果有序)
    void _InOrder(Node* root)
    {
      if(!root)
      {
        return;
      }
      _InOrder(root->_left);
      cout<<(root->_kv.first)<<":"<<(root->_kv.second)<<endl;
      _InOrder(root->_right);
    }
    
    void InOrder()
    {
      _InOrder(_root);
    }

  private:
    // 左单旋
    void RotateL(Node* parent)
    {
      Node* subR=parent->_right;
      Node* subRL=subR->_left;
      // 更新节点之间的连接关系
      parent->_right=subRL;
      if(subRL)// subRL不为空才需要更新它的父亲
      {
        subRL->_parent=parent;
      }
      subR->_left=parent;
      Node* pparent=parent->_parent;
      parent->_parent=subR;
      if(!pparent)// parent为根时的处理
      {
        _root=subR;
        subR->_parent=nullptr;
      }
      else 
      {
        if(pparent->_left==parent)
        {
          pparent->_left=subR;
        }
        else 
        {
          pparent->_right=subR;
        }
        subR->_parent=pparent;
      }
      // 更新平衡因子
      parent->_bf=subR->_bf=0;
    }

    // 右单旋
    void RotateR(Node* parent)
    {
      Node* subL=parent->_left;
      Node* subLR=subL->_right;
      // 更新节点之间的连接关系
      parent->_left=subLR;
      if(subLR)
      {
        subLR->_parent=parent;
      }
      subL->_right=parent;
      Node* pparent=parent->_parent;
      parent->_parent=subL;
      if(!pparent)
      {
        _root=subL;
        subL->_parent=nullptr;
      }
      else 
      {
        if(pparent->_left==parent)
        {
          pparent->_left=subL;
        }
        else if(pparent->_right==parent)
        {
          pparent->_right=subL;
        }
        subL->_parent=pparent;
      }
      // 更新平衡因子
      parent->_bf=subL->_bf=0;
    }

    // 左右双旋
    void RotateLR(Node* parent)
    {
      Node* subL=parent->_left;
      Node* subLR=subL->_right;
      int flag=subLR->_bf;// 记录subLR的平衡因子，最后要依据它来更新其他节点的平衡因子
      // 依次旋转
      RotateL(subL);
      RotateR(parent);
      // 根据subLR平衡因子的值更新不同插入情况下的平衡因子
      if(flag==1)// 说明是在subLR的右子树插入的，那么subLR的左子树变为subL的右子树，subL平衡因子变为-1，subLR和parent的为0
      {
        subL->_bf==-1;
      }
      else if(flag==-1)// 说明是在subLR的左子树插入的，subLR的右子树最后会被分给parent作为左子树，parent的平衡因子变为-1，subL和subLR的平衡因子变为0
      {
        parent->_bf==1;
      }
    }

    // 右左双旋
    void RotateRL(Node* parent)
    {
      Node* subR=parent->_right;
      Node* subRL=subR->_left;
      int flag=subRL->_bf;
      // 依次旋转
      RotateR(subR);
      RotateL(parent);
      // 更新平衡因子
      if(flag==1)
      {
        parent->_bf==-1;
      }
      else if(flag==-1) 
      {
        subR->_bf==1;
      }
    }

    Node* _root=nullptr;
};


void TestAVLTree()
{
  int a[]={4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
  AVLTree<int,int> t;
  for(auto& e : a)
  {
   t.AVLTree::Insert(make_pair(e,e));
  }
  t.InOrder();
  cout<<t.IsBalance()<<endl;
}


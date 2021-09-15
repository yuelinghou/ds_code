#pragma once

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::pair;

// 枚举定义颜色
enum COLOR
{
  RED,
  BLACK
};

// 节点的定义
template<class k, class v>
struct RBTreeNode
{
  // 构造函数，颜色默认给为红色
  RBTreeNode(const pair<k, v>& kv)
    :_color(RED)
    ,_kv(kv)
    ,_parent(nullptr)
    ,_left(nullptr)
    ,_right(nullptr)
  {}

  COLOR _color;
  pair<k, v> _kv;
  RBTreeNode<k, v>* _parent;
  RBTreeNode<k, v>* _left;
  RBTreeNode<k, v>* _right;
};

// 树的定义
template<class k, class v>
class RBTree 
{
  public:
    typedef RBTreeNode<k, v> Node;

    // 插入一个节点
    bool Insert(const pair<k, v>& kv)
    {
      // 第一步：按搜索树规则插入一个节点
      // 1、空树的话插入节点作为根节点
      // 2、不空的话，按搜索树规则找到插入的位置，然后插入
      if(!_root)
      {
        _root=new Node(kv);
        _root->_color=BLACK;
        return true;
      }
      // 寻找插入的位置
      Node* parent=nullptr;
      Node* cur=_root;
      while(cur)
      {
        parent=cur;
        if(cur->_kv.first == kv.first)
        {
          return false;
        }
        else if(cur->_kv.first < kv.first)
        {
          cur=cur->_right;
        }
        else if(cur->_kv.first > kv.first)
        {
          cur=cur->_left;
        }
      }
      // 找到后插入
      Node* newNode=new Node(kv);
      newNode->_parent=parent;
      if(parent->_kv.first > kv.first)
      {
        parent->_left=newNode;
      }
      else if(parent->_kv.first < kv.first) 
      {
        parent->_right=newNode;
      }
      // 第二步：调整节点的颜色
      // 1、如果父亲颜色为黑就不用调整
      // 2、如果父亲节点颜色为红，调整方式由叔叔决定
      //    a、叔叔存在且为红 --> 把叔叔和父亲的颜色调整为黑，爷爷颜色调整为红，然后继续往上调整
      //    b、叔叔不存在或存在且为黑 --> 看爷爷、父亲、和cur的相对位置来决定用什么旋转，旋转后调整父亲和爷爷的颜色
      cur=newNode;
      while(parent &&  parent->_color == RED)
      {
        // 既然进来了这个循环内部，说明父亲一定是红色，那么一定有爷爷且爷爷颜色为黑
        Node* grandfather = parent->_parent;
        // 确定叔叔的位置
        if(grandfather->_left == parent)
        {
          Node* uncle=grandfather->_right;
          if(uncle && uncle->_color == RED)// 叔叔存在且为红
          {
            parent->_color=uncle->_color=BLACK;
            grandfather->_color=RED;
            cur=grandfather;
            parent=cur->_parent;
          }
          else // 叔叔不存在或者存在且为黑
          {
            if(cur == parent->_right)
            {
              RotateL(parent);
              std::swap(parent,cur);
            }
            RotateR(grandfather);
            parent->_color=BLACK;
            grandfather->_color=RED;
            break;
          }
        }
        else if(grandfather->_right == parent)
        {
          Node* uncle=grandfather->_left;
          if(uncle && uncle->_color==RED)// 叔叔存在且为红
          {
            uncle->_color=parent->_color=BLACK;
            grandfather->_color=RED;
            cur=grandfather;
            parent=cur->_parent;
          }
          else // 叔叔不存在或存在且为黑
          {
            if(cur == parent->_left)
            {
              RotateR(parent);
              std::swap(parent,cur);
            }
            RotateL(grandfather);
            parent->_color=BLACK;
            grandfather->_color=RED;
            break;
          }
        }
      }
      _root->_color=BLACK;
    }


    void _InOrder(Node* root)
    {
      if(!root)
      {
        return;
      }
      _InOrder(root->_left);
      cout<<root->_kv.first<<":"<<root->_kv.second<<endl;
      _InOrder(root->_right);
    }

    void InOrder()
    {
      _InOrder(_root);
    }

    bool _IsRBTree(Node* root, int curCount, const int blackCount)
    {
      if(!root)
      {
        if(curCount != blackCount)
        {
          cout<<"路径上黑色节点数量不同"<<endl;
          return false;
        }
        return true;
      }
      Node* parent=root->_parent;
      while(parent && parent->_color == RED && root->_color == RED)
      {
        cout<<"出现连续的红色节点"<<endl;
        return false;
      }
      if(root->_color == BLACK)
      {
        ++curCount;
      }
      return _IsRBTree(root->_left, curCount, blackCount) && _IsRBTree(root->_right, curCount, blackCount);
    }

    bool IsRBTree()
    {
      if(!_root)
      {
        return true;
      }
      if(_root->_color == RED)
      {
        cout<<"根节点为红色"<<endl;
        return false;
      }
      int blackCount=0;
      Node* cur=_root;
      while(cur)
      {
        if(cur->_color == BLACK)
        {
          ++blackCount;
        }
        cur=cur->_left;
      }
      return _IsRBTree(_root, 0, blackCount);
    }

 // private:
    // 左单旋
    void RotateL(Node* parent)
    {
      Node* subR=parent->_right;
      Node* subRL=subR->_left;
      parent->_right=subRL;
      if(subRL != nullptr)
      {
        subRL->_parent=parent;
      }
      subR->_left=parent;
      Node* pparent=parent->_parent;
      parent->_parent=subR;
      if(pparent == nullptr)
      {
        _root=subR;
        subR->_parent=nullptr;
      }
      else 
      {
        subR->_parent=pparent;
        if(pparent->_left == parent)
        {
          pparent->_left=subR;
        }
        else if(pparent->_right == parent)
        {
          pparent->_right=subR;
        }
      }
    }

    // 右单旋
    void RotateR(Node* parent)
    {
      Node* subL=parent->_left;
      Node* subLR=subL->_right;

      parent->_left=subLR;
      if(subLR != nullptr)
      {
        subLR->_parent=parent;
      }
      subL->_right=parent;
      Node* pparent=parent->_parent;
      parent->_parent=subL;
      if(pparent == nullptr)
      {
        _root=subL;
        subL->_parent=nullptr;
      }
      else 
      {
        subL->_parent=pparent;
        if(pparent->_left == parent)
        {
          pparent->_left=subL;
        }
        else if(pparent->_right == parent) 
        {
          pparent->_right=subL;
        }
      }
    }


    Node* _root=nullptr;
};

void TestRBTree()
{
  int a[]={4, 2, 6, 1, 3, 5, 15, 7, 16, 14};                                                                                                      
  RBTree<int,int> t;    
  for(auto& e : a)    
  {    
   t.RBTree::Insert(std::make_pair(e,e));    
  }    
  t.InOrder();
  cout<<t.IsRBTree()<<endl;
}


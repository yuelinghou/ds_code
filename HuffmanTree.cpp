#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

struct HuffmanNode 
{
  HuffmanNode()
    :_weight(0)
    ,_parent(0)
    ,_left(0)
    ,_right(0)
    ,_data(0)
  {}

  HuffmanNode(const HuffmanNode& hnode)
  {
    _weight = hnode._weight;
    _parent = hnode._parent;
    _left = hnode._left;
    _right = hnode._right;
    _data = hnode._data;
  }


  int _weight;
  int _parent;
  int _left;
  int _right;
  char _data;
};

class HuffmanTree 
{
  typedef HuffmanNode Node;
  public:
    HuffmanTree()
    {}
    HuffmanTree(int n, const string& s, const vector<int>& weightArray)
    {
      // 1、开空间
      int m = 2*n-1;
      _num = m;
      _t.resize(m + 1);
      for(int i = 0; i <= m; ++i)
      {
        _t[i] = new HuffmanNode;
      }

      // 2、处理子树的权重和数据
      for(int i = 1; i <= n; ++i)
      {
        _t[i]->_data = s[i-1];
        _t[i]->_weight = weightArray[i-1];
      }

      // 3、构造哈夫曼树
      for(int i = n+1; i <= m; ++i)
      {
        int s1 = 0;
        int s2 = 0;
        Select(i, s1, s2);
        _t[i]->_left = s1;
        _t[i]->_right = s2;
        _t[i]->_weight = _t[s1]->_weight + _t[s2]->_weight;
        _t[s1]->_parent = i;
        _t[s2]->_parent = i;
      }

      // 4、处理编码、译码列表
      for(int i = 1; i <= n; ++i)
      {
        string code;
        int cur = i;
        int parent = _t[cur]->_parent;
        while(parent)
        {
          if(_t[parent]->_left == cur)
          {
            code += '0';
          }
          else 
          {
            code += '1';
          }
          cur = parent;
          parent = _t[cur]->_parent;
        }
        reverse(code.begin(), code.end());
        _makeCodeList.insert(make_pair(_t[i]->_data, code));
        _translateCodeList.insert(make_pair(code, _t[i]->_data));
      }
    }

    // 5、编码
    void MakeCode(const string& s)
    {
      for(auto e : s)
      {
        cout<<_makeCodeList.find(e)->second;
      }
      cout<<endl;
    }

    // 6、译码
    void TranslateCode(const string& s)
    {
      size_t pos = 0;
      size_t first = 0;
      while(first < s.size())
      {
        ++pos;
        auto it = _translateCodeList.find(s.substr(first, pos));
        if(it != _translateCodeList.end())
        {
          cout<<it->second;
          first += pos;
          pos = 0;
        }
      }
      cout<<endl;
    }

    // 5、析构函数释放空间
    ~HuffmanTree()
    {
      for(auto e : _t)
      {
        delete e;
      }
    }

    void swap(HuffmanTree& ht)
    {
      _t.swap(ht._t);
      ::swap(_num, ht._num);
      _makeCodeList.swap(ht._makeCodeList);
      _translateCodeList.swap(ht._translateCodeList);
    }

  private:
    static bool cmp(Node* n1, Node* n2)
    {
      return n1->_weight <= n2->_weight;
    }

    void Select(int index, int& s1, int& s2)
    {
      vector<Node*> tmp(index);
      for(int i = 0; i < index; ++i)
      {
        tmp[i] = new HuffmanNode(*_t[i+1]);
      }
      sort(tmp.begin(), tmp.end(), cmp);
      vector<int> ret(2);
      int count = 0;
      for(int i = 1; i < index; ++i)
      {
        if(tmp[i]->_parent == 0)
        {
          for(int j = 1; j < index; ++j)
          {
            if(_t[j]->_weight == tmp[i]->_weight && _t[j]->_parent == 0 && j != ret[0])      
            {
              ret[count++] = j; 
              break;
            }
          }
        }
        if(count == 2)
        {
          break;
        }
      }
      s1 = ret[0];
      s2 = ret[1];
      for(auto& e : tmp)
      {
        delete e;
      }
    }

    int _num;
    vector<Node*> _t;
    unordered_map<char, string> _makeCodeList;
    unordered_map<string, char> _translateCodeList;
};

int main()
{
  int Q = 0;
  cin>>Q;
  HuffmanTree ht;
  while(Q--)
  {
    int T = 0;
    cin>>T;
    if(T == 0)
    {
      int n = 0;
      cin>>n;
      string s;
      for(int i = 0; i < n; ++i)
      {
        char ch = 0;
        cin>>ch;
        s+=ch;
      }
      vector<int> v(n);
      for(auto& e : v)
      {
        cin>>e;
      }
      HuffmanTree tmp(n, s, v);
      tmp.swap(ht);
    }
    else if(T == 1)
    {
      string s;
      cin>>s;
      ht.MakeCode(s);
    }
    else if(T == 2)
    {
      string s;
      cin>>s;
      ht.TranslateCode(s);
    }
  }
  return 0;
}

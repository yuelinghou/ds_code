#include <vector>
#include <iostream>
using namespace std;

class UnionFindSet
{
  public:
    UnionFindSet(int n)
    {
      _ufs.resize(n, -1);
    }

    int FindRoot(int index)
    {
      while(_ufs[index] >= 0)
      {
        index = _ufs[index];
      }
      return index;
    }

    void Union(int x1, int x2)
    {
      int root1 = FindRoot(x1);
      int root2 = FindRoot(x2);
      if(root1 != root2)
      {
        _ufs[root1] += _ufs[root2];
        _ufs[root2] = root1;
      }
    }

    int GetSet()
    {
      int count = 0;
      for(auto e : _ufs)
      {
        if(e < 0)
        {
          ++count;
        }
      }
      return count;
    }

  private:
    vector<int> _ufs;
};

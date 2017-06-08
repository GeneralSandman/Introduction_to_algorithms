#ifndef Rb_TREE
#define Rb_TREE
#include <iostream>
#include <vector>
namespace Rb
{
using namespace std;

  typedef enum { red,
                 black } color;
class RbTreeNode
{
private:
  color m_nColor;
  int m_nValue;
  RbTreeNode *m_pParent;
  RbTreeNode *m_pLeft;
  RbTreeNode *m_pRight;

public:
  RbTreeNode(const int &value, const color &co = red)
  {
    m_nColor = co;
    m_nValue = value;
    m_pParent = m_pLeft = m_pRight = nullptr;
  }
  ~RbTreeNode()
  {
    std::cout << "distory RbTreeNode:" << m_nValue << std::endl;
  }

  color getColor(void) { return m_nColor; }
  int getValue(void) { return m_nValue; }
  RbTreeNode *getParent(void) { return m_pParent; }
  RbTreeNode *getLeft(void) { return m_pLeft; }
  RbTreeNode *getRight(void) { return m_pRight; }

  RbTreeNode *getGParent(void)
  {
    if (getParent())
      return getParent()->getParent();
    else
      return nullptr;
  }

  RbTreeNode *getUncle(void)
  {
    RbTreeNode *parent = getParent(), *gparent = getGParent();
    if (gparent)
    {
      if (parent == gparent->getLeft())
        return gparent->getRight();
      else if (parent == gparent->getRight())
        return gparent->getLeft();
      else
        return nullptr;
    }

    else
      return nullptr;
  }

  void setColor(color co) { m_nColor = co; }
  void setValue(const int &value) { m_nValue = value; }
  void setParent(RbTreeNode *parent) { m_pParent = parent; }
  void setLeft(RbTreeNode *left) { m_pLeft = left; }
  void setRight(RbTreeNode *right) { m_pRight = right; }
};

class RbTree
{

private:
  RbTreeNode *m_pRoot;
  int m_nNumber;
  RbTreeNode *m_fFindNode(const int &);
  void m_fFixAfterInsert(RbTreeNode *);
  void m_fInsertNode(const int &, RbTreeNode *);
  void m_fDeleteRoot();
  void m_fDeleteGeneralNode(RbTreeNode *);
  RbTreeNode *m_fFindLeftSubTreeMaxNode(RbTreeNode *);
  RbTreeNode *m_fFindRightSubTreeMinNode(RbTreeNode *);
  void m_fPreorder(RbTreeNode *);
  void m_fInorder(RbTreeNode *);
  void m_fPostorder(RbTreeNode *);
  void m_fLevel(vector<vector<int>> &result, RbTreeNode *node, int level);
  void m_fDisplay(vector<string> &, RbTreeNode *, int);
  void m_fDeleteAllNode(RbTreeNode *node, int &);

  int m_fGetHeight(RbTreeNode *);

  void m_fLeftRotate(RbTreeNode *node);
  void m_fRightRotate(RbTreeNode *node);
  void m_fRoatLeftLeft(RbTreeNode *node);
  void m_fRoatLeftRight(RbTreeNode *node);
  void m_fRoatRightLeft(RbTreeNode *node);
  void m_fRoatRightRight(RbTreeNode *node);

public:
  RbTree();
  ~RbTree();
  bool FindNode(const int &);
  void PrintTreePreorder();
  void PrintTreeInorder();
  void PrintTreePostorder();
  void PrintTreeLevel();
  void DisplayTree();
  void InsertNode(const int &);
  void DeleteNode(const int &);
  int getNumber(void);
  bool testBalance(void);
  void testRoat(void);
};
}

#endif
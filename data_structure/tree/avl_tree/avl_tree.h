#ifndef AVL_TREE
#define AVL_TREE
#include<iostream>
#include<vector>
#include<string>
std::string int2str(int);
namespace Avl
{
  using namespace std;
class AvlTreeNode
{
private:
  int m_nValue;
  AvlTreeNode *m_pParent;
  AvlTreeNode *m_pLeft;
  AvlTreeNode *m_pRight;
  int m_nHeight;
  int m_nBalanceFactor;

public:
  AvlTreeNode(const int &value)
  {
    m_nValue = value;
    m_pParent = m_pRight = m_pLeft = nullptr;
    m_nHeight = m_nBalanceFactor = 0;
  }

  int getValue(void) { return m_nValue; }
  AvlTreeNode *getParent(void) { return m_pParent; }
  AvlTreeNode *getLeft(void) { return m_pLeft; }
  AvlTreeNode *getRight(void) { return m_pRight; }

  void setValue(const int &value) { m_nValue = value; }
  void setParent(AvlTreeNode *parent) { m_pParent = parent; }
  void setLeft(AvlTreeNode *left) { m_pLeft = left; }
  void setRight(AvlTreeNode *right) { m_pRight = right; }

  int getHeight(void) { return m_nHeight; }
  void setHeight(const int &value) { m_nHeight = value; }

  int getFactor(void) { return m_nBalanceFactor; }
  void setFactor(const int &value) { m_nBalanceFactor = value; }

  ~AvlTreeNode()
  {
    std::cout << "distory AvlTreeNode:" << m_nValue << std::endl;
  }
};

class AvlTree
{
private:
  AvlTreeNode *m_pRoot;
  int m_nNumber;
  AvlTreeNode *m_fFindNode(const int &);
  void m_fInsertNode(const int &,AvlTreeNode *);
  void m_fDeleteRoot();
  void m_fDeleteGeneralNode(AvlTreeNode *);
  AvlTreeNode *m_fFindLeftSubTreeMaxNode(AvlTreeNode *);
  AvlTreeNode *m_fFindRightSubTreeMinNode(AvlTreeNode *);
  void m_fPreorder(AvlTreeNode *);
  void m_fInorder(AvlTreeNode *);
  void m_fPostorder(AvlTreeNode *);
  void m_fLevel(vector<vector<int>> &result, AvlTreeNode *node, int level);
  void m_fDisplay(vector<string> &, AvlTreeNode *, int);
  void m_fDeleteAllNode(AvlTreeNode *node, int &);

  int m_fGetHeight(AvlTreeNode *);


  void m_fLeftRotate(AvlTreeNode *node);
  void m_fRightRotate(AvlTreeNode *node);
  void m_fRoatLeftLeft(AvlTreeNode * node);
  void m_fRoatLeftRight(AvlTreeNode *node);
  void m_fRoatRightLeft(AvlTreeNode *node);
  void m_fRoatRightRight(AvlTreeNode * node);


public:
  AvlTree();
  ~AvlTree();
  void PrintTreePreorder();
  void PrintTreeInorder();
  void PrintTreePostorder();
  void PrintTreeLevel();
  void DisplayTree();
  virtual void InsertNode(const int &);
  virtual void DeleteNode(const int &);
  int getNumber(void);
  bool testBalance(void);
  void testRoat(void);
};
}

#endif
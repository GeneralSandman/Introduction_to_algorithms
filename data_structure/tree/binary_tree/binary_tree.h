#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

std::string int2str(int);

namespace Tree
{
using namespace std;

class BinaryTreeNode
{
private:
  int m_nValue;
  BinaryTreeNode *m_pParent;
  BinaryTreeNode *m_pLeft;
  BinaryTreeNode *m_pRight;

public:
  BinaryTreeNode(const int &value)
  {
    m_nValue = value;
    m_pParent = nullptr;
    m_pRight = m_pLeft = nullptr;
  }

  int getValue(void) { return m_nValue; }
  BinaryTreeNode *getParent(void) { return m_pParent; }
  BinaryTreeNode *getLeft(void) { return m_pLeft; }
  BinaryTreeNode *getRight(void) { return m_pRight; }

  void setValue(const int &value) { m_nValue = value; }
  void setParent(BinaryTreeNode *parent) { m_pParent = parent; }
  void setLeft(BinaryTreeNode *left) { m_pLeft = left; }
  void setRight(BinaryTreeNode *right) { m_pRight = right; }

  ~BinaryTreeNode()
  {
    std::cout << "distory BinaryTreeNode:" << m_nValue << endl;
  }
};

class BinaryTree
{
private:
  BinaryTreeNode *m_pRoot;
  int m_nNumber;
  BinaryTreeNode *m_fFindNode(const int &);
  void m_fInsertNode(const int &, BinaryTreeNode *);
  void m_fDeleteRoot();
  void m_fDeleteGeneralNode(BinaryTreeNode *);
  BinaryTreeNode *m_fFindLeftSubTreeMaxNode(BinaryTreeNode *);
  BinaryTreeNode *m_fFindRightSubTreeMinNode(BinaryTreeNode *);
  void m_fPreorder(BinaryTreeNode *);
  void m_fInorder(BinaryTreeNode *);
  void m_fPostorder(BinaryTreeNode *);
  void m_fLevel(vector<vector<int>> &result, BinaryTreeNode *node, int level);
  void m_fDisplay(vector<string> &, BinaryTreeNode *, int);
  void m_fDeleteAllNode(BinaryTreeNode *node, int &);

public:
  BinaryTree();
  ~BinaryTree();
  bool FindNode(const int &);
  void PrintTreePreorder();
  void PrintTreeInorder();
  void PrintTreePostorder();
  void PrintTreeLevel();
  void DisplayTree();
  void InsertNode(const int &);
  void DeleteNode(const int &);
  int getNumber(void);
};
}

#endif

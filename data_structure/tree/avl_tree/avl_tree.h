#ifndef AVL_TREE
#define AVL_TREE
#include"../binary_tree/binary_tree.h"
namespace Avl
{
using namespace Tree;

class AvlTreeNode : public BinaryTreeNode
{
public:
  int m_nHeight;
  int m_nBalanceFactor;

public:
  AvlTreeNode(const int &value);

  virtual int GetValue(void);
  virtual AvlTreeNode * GetParent(void);
  virtual AvlTreeNode * GetLeft(void);
  virtual AvlTreeNode * GetRight(void);

  virtual void SetValue(const int &);
  virtual void SetParent(AvlTreeNode *);
  virtual void SetLeft(AvlTreeNode *);
  virtual void SetRight(AvlTreeNode *);

  ~AvlTreeNode();
};

class AvlTree : public BinaryTree
{
private:
  void m_fBalance(AvlTreeNode *node);
  AvlTreeNode *m_fFindMinUnbalanceNode();
  void m_fLeftRotate(AvlTreeNode *node);
  void m_fRightRotate(AvlTreeNode *node);
  void m_fRoatLeftRight(AvlTreeNode *node);
  void m_fRoatRightLeft(AvlTreeNode *node);
  void m_fUpdateNodeHeight(AvlTreeNode *node);
  void m_fUpdateTreeHeight();
  void m_fUpdateNodeBalanceFactor(AvlTreeNode *node);
  void m_fUpdateTreeBalanceFactor();

public:
  AvlTree();
  ~AvlTree();
  virtual void InsertNode(const int &value);
  virtual void DeleteNode(const int &value);
};
}

#endif
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
  virtual AvlTreeNode * GetParent(void){return (AvlTreeNode *)(m_pParent);}
  virtual AvlTreeNode * GetLeft(void){return (AvlTreeNode *)(m_pLeft);}
  virtual AvlTreeNode * GetRight(void){return (AvlTreeNode *)(m_pRight);}

  virtual void SetValue(const int &);
  virtual void SetParent(AvlTreeNode *parent){m_pParent=parent;}
  virtual void SetLeft(AvlTreeNode *left){m_pLeft=left;}
  virtual void SetRight(AvlTreeNode *right){m_pRight=right;}

  int GetHeight(void);
  void SetHeight(const int & value);

  int GetFactor(void);
  void SetFactor(const int & value);

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
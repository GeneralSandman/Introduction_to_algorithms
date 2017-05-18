#ifndef AVL_TREE
#define AVL_TREE
namespace Avl
{
using namespace Tree;

class AvlTreeNode : public BinaryTreeNode
{
private:
  int m_nHeight;
  int m_nBalanceFactor;

public:
  AvlTreeNode(const int &value);
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
  int m_fGetHeight(AvlTreeNode *node);
  void m_fUpdateNodeHeight(AvlTreeNode *node);
  void m_fUpdateTreeHeight();
  void m_fUpdateNodeBalanceFactor(AvlTreeNode *node);
  void m_fUpdateTreeBalanceFactor();

public:
  AvlTree();
  ~AvlTree();
  virtual void insertNode(const int &value);
  virtual void deleteNode(const int &value);
};
}

#endif
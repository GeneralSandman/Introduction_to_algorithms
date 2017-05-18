#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
namespace Tree
{
using namespace std;

class BinaryTreeNode
{
  public:
    int m_nValue;
    BinaryTreeNode *m_pParent;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;

  public:
    BinaryTreeNode(const int &);
    
    int GetValue(void);
    BinaryTreeNode * GetParent(void);
    BinaryTreeNode * GetLeft(void);
    BinaryTreeNode * GetRight(void);

    void SetValue(const int &);
    void SetParent(BinaryTreeNode *);
    void SetLeft(BinaryTreeNode *);
    void SetRight(BinaryTreeNode *);

    ~BinaryTreeNode();
};

class BinaryTree
{
  private:
    BinaryTreeNode *m_pRoot;
    int m_nNumber;
    BinaryTreeNode *m_fFindNode(const int &);
    void m_fDeleteRoot();
    void m_fDeleteGeneralNode(BinaryTreeNode *);
    BinaryTreeNode *m_fFindLeftSubTreeMaxNode(BinaryTreeNode *);
    BinaryTreeNode *m_fFindRightSubTreeMinNode(BinaryTreeNode *);
    void m_fPreorder(BinaryTreeNode *);
    void m_fInorder(BinaryTreeNode *);
    void m_fPostorder(BinaryTreeNode *);
    vector<vector<int> > m_fLevel();
    void m_fDeleteAllNode(BinaryTreeNode * node,int &);

  public:
    BinaryTree();
    ~BinaryTree();
    void PrintTreePreorder();
    void PrintTreeInorder();
    void PrintTreePostorder();
    void PrintTreeLevel();
    virtual void InsertNode(const int &);
    virtual void DeleteNode(const int &);
    int GetNumber(void);
};
}

#endif

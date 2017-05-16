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
  private:
    int m_nValue;
    BinaryTreeNode *m_pParent;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;

  public:
    BinaryTreeNode(const int &);
    ~BinaryTreeNode();
};

class BinaryTree
{
  private:
    BinaryTreeNode *m_pRoot;
    BinaryTreeNode *m_fFindNode(const int &);
    void m_fDeleteRoot();
    void m_fDeleteGeneralNode(BinaryTreeNode *);
    BinaryTreeNode *m_fFindLeftSubTreeMaxNode(BinaryTreeNode *);
    BinaryTreeNode *m_fFindRightSubTreeMinNode(BinaryTreeNode *);
    void m_fPreorder(BinaryTreeNode *);
    void m_fInorder(BinaryTreeNode *);
    void m_fPostorder(BinaryTreeNode *);

  public:
    BinaryTree();
    ~BinaryTree();
    void PrintTreePreorder();
    void PrintTreeInorder();
    void PrintTreePostorder();
    vector<vector<int>> PrintTreeLevel();
    virtual void InsertNode(const int &);
    virtual void DeleteNode(const int &);
}
}

namespace Avl
{
using namespace TREE;

class AvlTreeNode : public BinaryTreeNode()
{
  private:
    int m_nHeight;
    int m_nBalanceFactor;

  public:
    AvlTreeNode(const int &value);
    ~AvlTreeNode();
}

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
    virtual void deleteNode(const int &value)
}
}

namespace Huffman
{
using namespace std;

class Node
{
  private:
    char m_nChar;
    int m_nFrequency;

  public:
    Node(char Char, int Frequency) : m_nChar(Char), m_nFrequency(Frequency) {}
    ~Node(){};
}

class Code
{
  private:
    char m_nChar;
    vector<int> m_nCode;

  public:
    Code(char Char, vector<int> &Code) : m_nChar(Char), m_nCode(Code) {}
    ~Code(){};
}

class HuffmanNode
{
  private:
    char m_nChar;
    int m_nFrequency;
    HuffmanNode *m_pParent;
    HuffmanNode *m_pLeft;
    HuffmanNode *m_pRight;

  public:
    HuffmanNode(const Node &);
    HuffmanNode(HuffmanNode &, HuffmanNode &);
    ~HuffmanNode(){};
}

class HuffmanTree
{
  private:
    privoity_queue<HuffmanNode, vector<HuffmanNode>, decltype(m_fCompare)> m_nQueue;
    HuffmanNode *m_pRoot;
    bool m_fCompare(HuffmanNode *, HuffmanNode *);

  public:
    HuffmanTree(vector<Node> &);
    //continue
    void GenerateCode(HuffmanNode *, vector<int> &);
    ~HuffmanTree();
}
}

namespace B_tree
{

class BtreeNode
}

namespace RBtree
{

using namespace TREE;

class RBNode : public BinaryTreeNode
{
  private:
    typedef enum { red,
		   black } color;
    color m_nColor;
}

class RBTree
{
  private:
    void m_fLeftRotate(RBNode *);
    void m_fRightRotate(RBNode *);

  public:
    RBNode *GrandParent(RBNode *);
    RBNode *Uncle(RBNode *);
}
}

#endif

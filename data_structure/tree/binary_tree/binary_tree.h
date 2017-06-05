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
  public:
    int m_nValue;
    BinaryTreeNode *m_pParent;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;

  public:
    BinaryTreeNode(const int & value){
      m_nValue=value;
      m_pParent=nullptr;
      m_pRight=m_pLeft=nullptr;
    }
    
    virtual int getValue(void){return m_nValue;}
    virtual BinaryTreeNode * getParent(void){return m_pParent;}
    virtual BinaryTreeNode * getLeft(void){return m_pLeft;}
    virtual BinaryTreeNode * getRight(void){return m_pRight;}

    virtual void setValue(const int & value){m_nValue=value;}
    virtual void setParent(BinaryTreeNode * parent){m_pParent=parent;}
    virtual void setLeft(BinaryTreeNode * left){m_pLeft=left;}
    virtual void setRight(BinaryTreeNode * right){m_pRight=right;}

    ~BinaryTreeNode(){
      std::cout<<"distory BinaryTreeNode:"<<m_nValue<<endl;
    }
};

class BinaryTree
{
  private:
    BinaryTreeNode *m_pRoot;
    int m_nNumber;
    BinaryTreeNode *m_fFindNode(const int &);
    void m_fInsertNode(const int &,BinaryTreeNode *);
    void m_fDeleteRoot();
    void m_fDeleteGeneralNode(BinaryTreeNode *);
    BinaryTreeNode *m_fFindLeftSubTreeMaxNode(BinaryTreeNode *);
    BinaryTreeNode *m_fFindRightSubTreeMinNode(BinaryTreeNode *);
    void m_fPreorder(BinaryTreeNode *);
    void m_fInorder(BinaryTreeNode *);
    void m_fPostorder(BinaryTreeNode *);
    void m_fLevel(vector<vector<int>> & result,BinaryTreeNode *node,int level);
    void m_fDisplay(vector<string> &,BinaryTreeNode *,int);
    void m_fDeleteAllNode(BinaryTreeNode * node,int &);

  public:
    BinaryTree();
    ~BinaryTree();
    void PrintTreePreorder();
    void PrintTreeInorder();
    void PrintTreePostorder();
    void PrintTreeLevel();
    void DisplayTree();
    virtual void InsertNode(const int &);
    virtual void DeleteNode(const int &);
    int getNumber(void);
};
}

#endif

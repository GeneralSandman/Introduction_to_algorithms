#include <iostream>
#include "binary_tree.h"

namespace Tree
{
using namespace std;
BinaryTreeNode::BinaryTreeNode(const int &value)
{
    m_nValue = value;
    m_pParent = nullptr;
    m_pLeft = nullptr;
    m_pRight = nullptr;
}

int BinaryTreeNode::GetValue(void){
    return m_nValue;
}

BinaryTreeNode* BinaryTreeNode::GetParent(void){
    return m_pParent;
}

BinaryTreeNode* BinaryTreeNode::GetLeft(void){
    return m_pLeft;
}

BinaryTreeNode* BinaryTreeNode::GetRight(void){
    return m_pRight;
}

void BinaryTreeNode::SetValue(const int & value){
    m_nValue=value;
}

void BinaryTreeNode::SetParent(BinaryTreeNode * parent){
    m_pParent=parent;
}

void BinaryTreeNode::SetLeft(BinaryTreeNode * left){
    m_pLeft=left;
}

void BinaryTreeNode::SetRight(BinaryTreeNode * right){
    m_pRight=right;
}

BinaryTreeNode::~BinaryTreeNode()
{
    cout << "distory BinaryTreeNode: " << m_nValue << endl;
}

BinaryTreeNode * BinaryTree::m_fFindNode(const int &value)
{
    if (m_pRoot == nullptr)
        return nullptr;
    BinaryTreeNode *node = m_pRoot;
    while (node)
    {
        if (value < node->m_nValue)
            node = node->m_pLeft;
        else if (value > node->m_nValue)
            node = node->m_pRight;
        else
            break;
    }
    return node;
}

void BinaryTree::m_fDeleteRoot()
{
    BinaryTreeNode *_deletenode = m_pRoot;

    if (_deletenode->m_pLeft == nullptr && _deletenode->m_pRight == nullptr)
    {
    }
    else if (_deletenode->m_pLeft != nullptr && _deletenode->m_pRight == nullptr)
    {
        m_pRoot = _deletenode->m_pLeft;
        m_pRoot->m_pParent = nullptr;
    }
    else if (_deletenode->m_pLeft == nullptr && _deletenode->m_pRight != nullptr)
    {
        m_pRoot = _deletenode->m_pRight;
        m_pRoot->m_pParent = nullptr;
    }
    else
    {
        BinaryTreeNode *LeftMaxNode = m_fFindLeftSubTreeMaxNode(m_pRoot);
        if (LeftMaxNode == _deletenode->m_pLeft)
        {
            LeftMaxNode->m_pRight = m_pRoot->m_pRight;
            m_pRoot->m_pRight->m_pParent = LeftMaxNode;
            m_pRoot = LeftMaxNode;
            m_pRoot->m_pParent = nullptr;
        }
        else
        {
            m_pRoot->m_nValue = LeftMaxNode->m_nValue;
            LeftMaxNode->m_pParent->m_pRight = LeftMaxNode->m_pLeft;
            if (LeftMaxNode->m_pLeft)
                LeftMaxNode->m_pLeft->m_pParent = LeftMaxNode->m_pParent;
        }
    }

    delete _deletenode;
    _deletenode = nullptr;
}

void BinaryTree::m_fDeleteGeneralNode(BinaryTreeNode *_deletenode)
{
    BinaryTreeNode *_deletenodeparent;
    _deletenodeparent = _deletenode->m_pParent;

    if (_deletenode->m_pLeft == nullptr && _deletenode->m_pRight == nullptr)
    {
        if (_deletenode->m_nValue < _deletenodeparent->m_nValue)
            _deletenodeparent->m_pLeft = nullptr;
        else
            _deletenodeparent->m_pRight = nullptr;
    }
    else if (_deletenode->m_pLeft != nullptr && _deletenode->m_pRight == nullptr)
    {
        if (_deletenode->m_nValue < _deletenodeparent->m_nValue)
            _deletenodeparent->m_pLeft = _deletenode->m_pLeft;
        else
            _deletenodeparent->m_pRight = _deletenode->m_pLeft;
        _deletenode->m_pLeft->m_pParent = _deletenodeparent;
    }
    else if (_deletenode->m_pLeft == nullptr && _deletenode->m_pRight != nullptr)
    {
        if (_deletenode->m_nValue < _deletenodeparent->m_nValue)
            _deletenodeparent->m_pLeft = _deletenode->m_pRight;
        else
            _deletenodeparent->m_pRight = _deletenode->m_pRight;
        _deletenode->m_pRight->m_pParent = _deletenodeparent;
    }
    else
    {
        BinaryTreeNode *LeftMaxNode = m_fFindLeftSubTreeMaxNode(_deletenode);
        if (LeftMaxNode == _deletenode->m_pLeft)
        {
            LeftMaxNode->m_pParent = _deletenodeparent;
            _deletenodeparent->m_pLeft = LeftMaxNode;
            LeftMaxNode->m_pRight = _deletenode->m_pRight;
            _deletenode->m_pRight->m_pParent = LeftMaxNode;
        }
        else
        {
            _deletenode->m_nValue = LeftMaxNode->m_nValue;
            LeftMaxNode->m_pParent->m_pRight = LeftMaxNode->m_pLeft;
            if (LeftMaxNode->m_pLeft)
                LeftMaxNode->m_pLeft->m_pParent = LeftMaxNode->m_pParent;
            _deletenode = LeftMaxNode;
        }
    }

    delete _deletenode;
    _deletenode = nullptr;
}

BinaryTreeNode *BinaryTree::m_fFindLeftSubTreeMaxNode(BinaryTreeNode *node)
{
    BinaryTreeNode *leftmax = nullptr, *left = node->m_pLeft;
    while (left)
    {
        leftmax = left;
        left = left->m_pRight;
    }
    return leftmax;
}

BinaryTreeNode *BinaryTree::m_fFindRightSubTreeMinNode(BinaryTreeNode *node)
{
    BinaryTreeNode *rightmin = nullptr, *right = node->m_pRight;
    while (right!=nullptr)
    {
        rightmin = right;
        right = right->m_pLeft;
    }
    return rightmin;
}

void BinaryTree::m_fPreorder(BinaryTreeNode *node)
{
    if (node)
    {
        cout << node->m_nValue << " ";
        m_fPreorder(node->m_pLeft);
        m_fPreorder(node->m_pRight);
    }
}

void BinaryTree::m_fInorder(BinaryTreeNode *node)
{
    if (node)
    {
        m_fInorder(node->m_pLeft);
        cout << node->m_nValue << " ";
        m_fInorder(node->m_pRight);
    }
}

void BinaryTree::m_fPostorder(BinaryTreeNode *node)
{
    if (node)
    {
        m_fPostorder(node->m_pLeft);
        m_fPostorder(node->m_pRight);
        cout << node->m_nValue << " ";
    }
}

vector<vector<int>> BinaryTree::m_fLevel()
{
}

void BinaryTree::m_fDeleteAllNode(BinaryTreeNode * node,int & deleteNumber){
    
    if(node->m_pLeft!=nullptr)
        m_fDeleteAllNode(node->m_pLeft,deleteNumber);
    if(node->m_pRight!=nullptr)
        m_fDeleteAllNode(node->m_pRight,deleteNumber);
    if(node->m_pLeft==nullptr && node->m_pRight==nullptr){
        BinaryTreeNode * parent=node->m_pParent;
        if(parent!=nullptr){
            if(node->m_nValue<parent->m_nValue)
                parent->m_pLeft=nullptr;
            else 
                parent->m_pRight=nullptr;
        }

        node->m_pParent=nullptr;
        deleteNumber++;
        m_nNumber--;
        delete node;
    }
}

BinaryTree::BinaryTree()
{
    m_pRoot = nullptr;
    m_nNumber=0;
}

BinaryTree::~BinaryTree()
{
    int deleteNumber=0;
    int number=GetNumber();
    m_fDeleteAllNode(m_pRoot,deleteNumber);
    if(number==deleteNumber && GetNumber()==0)
        cout<<"all node are deleted\n";
    else
        cout<<"delete tree failed\n";
}

void BinaryTree::PrintTreePreorder()
{
    m_fPreorder(m_pRoot);
}

void BinaryTree::PrintTreeInorder()
{
    m_fInorder(m_pRoot);
}

void BinaryTree::PrintTreePostorder()
{
    m_fPostorder(m_pRoot);
}

void BinaryTree::PrintTreeLevel()
{
    vector<vector<int>> result;
    result = m_fLevel();
    for (int i = 0; i < result.size(); i++)
    {
        cout << "level " << i + 1 << ":";
        for (auto t : result[i])
            cout << t << " ";
        cout << endl;
    }
}

void BinaryTree::InsertNode(const int &value)
{
    BinaryTreeNode *newNode = new BinaryTreeNode(value);
    BinaryTreeNode *previous = m_pRoot;
    BinaryTreeNode *insertPosition = m_pRoot;

    while (insertPosition != nullptr)
    {
        previous = insertPosition;
        if (value < insertPosition->m_nValue)
            insertPosition = insertPosition->m_pLeft;
        else if (value == insertPosition->m_nValue)
        {
            cout << "this value exists.\n";
            goto DONE;
        }
        else
            insertPosition = insertPosition->m_pRight;
    }

    if (previous == nullptr)
    {
        m_pRoot = newNode;
    }
    else
    {
        if (value < previous->m_nValue)
            previous->m_pLeft = newNode;
        else
            previous->m_pRight = newNode;

        newNode->m_pParent = previous;
    }
    
    m_nNumber++;

DONE:
    return;
}

void BinaryTree::DeleteNode(const int &value)
{
    BinaryTreeNode *DeleteNode = m_fFindNode(value);
    if (DeleteNode == m_pRoot)
        m_fDeleteRoot();
    else
        m_fDeleteGeneralNode(DeleteNode);
}

int BinaryTree::GetNumber(void){
    return m_nNumber;
}
}
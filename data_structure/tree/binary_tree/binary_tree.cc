#include <iostream>
#include <vector>
#include <string>
#include "binary_tree.h"

std::string int2str(int value)
{
    std::string result;

    while (value)
    {
        char tmp = (value % 10 + '0');
        value /= 10;
        result = tmp + result;
    }

    return result;
}

namespace Tree
{
using namespace std;

BinaryTreeNode *BinaryTree::m_fFindNode(const int &value)
{
    if (m_pRoot == nullptr)
    {
        return nullptr;
    }

    BinaryTreeNode *node = m_pRoot;
    while (node)
    {
        if (value < node->getValue())
            node = node->getLeft();
        else if (value > node->getValue())
            node = node->getRight();
        else
            break;
    }
    return node;
}
void BinaryTree::m_fInsertNode(const int &value, BinaryTreeNode *node)
{
    if (value < node->getValue())
    {
        if (node->getLeft() == nullptr)
        {
            BinaryTreeNode *newnode = new BinaryTreeNode(value);
            newnode->setParent(node);
            node->setLeft(newnode);
        }
        else
            m_fInsertNode(value, node->getLeft());
    }
    else if (value > node->getValue())
    {
        if (node->getRight() == nullptr)
        {
            BinaryTreeNode *newnode = new BinaryTreeNode(value);
            newnode->setParent(node);
            node->setRight(newnode);
        }
        else
            m_fInsertNode(value, node->getRight());
    }
}

void BinaryTree::m_fDeleteRoot()
{
    BinaryTreeNode *_deletenode = m_pRoot;

    if (_deletenode->getLeft() == nullptr && _deletenode->getRight() == nullptr)
    {
        m_pRoot = nullptr;
    }
    else if (_deletenode->getLeft() != nullptr && _deletenode->getRight() == nullptr)
    {
        m_pRoot = _deletenode->getLeft();
        m_pRoot->setParent(nullptr);
    }
    else if (_deletenode->getLeft() == nullptr && _deletenode->getRight() != nullptr)
    {
        m_pRoot = _deletenode->getRight();
        m_pRoot->setParent(nullptr);
    }
    else
    {
        BinaryTreeNode *LeftMaxNode = m_fFindLeftSubTreeMaxNode(m_pRoot);
        if (LeftMaxNode == _deletenode->getLeft())
        {
            LeftMaxNode->setRight(m_pRoot->getRight());
            m_pRoot->getRight()->setParent(LeftMaxNode);
            m_pRoot = LeftMaxNode;
            m_pRoot->setParent(nullptr);
        }
        else
        {
            int tmp = m_pRoot->getValue();
            m_pRoot->setValue(LeftMaxNode->getValue());
            LeftMaxNode->setValue(tmp);
            LeftMaxNode->getParent()->setRight(LeftMaxNode->getLeft());
            if (LeftMaxNode->getLeft() != nullptr)
                LeftMaxNode->getLeft()->setParent(LeftMaxNode->getParent());
            _deletenode = LeftMaxNode;
        }
    }

    delete _deletenode;
    _deletenode = nullptr;
}

void BinaryTree::m_fDeleteGeneralNode(BinaryTreeNode *_deletenode)
{
    BinaryTreeNode *_deletenodeparent;
    _deletenodeparent = _deletenode->getParent();

    if (_deletenode->getLeft() == nullptr && _deletenode->getRight() == nullptr)
    {
        if (_deletenode->getValue() < _deletenodeparent->getValue())
            _deletenodeparent->setLeft(nullptr);
        else
            _deletenodeparent->setRight(nullptr);
    }
    else if (_deletenode->getLeft() != nullptr && _deletenode->getRight() == nullptr)
    {
        if (_deletenode->getValue() < _deletenodeparent->getValue())
            _deletenodeparent->setLeft(_deletenode->getLeft());
        else
            _deletenodeparent->setRight(_deletenode->getLeft());
        _deletenode->getLeft()->setParent(_deletenodeparent);
    }
    else if (_deletenode->getLeft() == nullptr && _deletenode->getRight() != nullptr)
    {
        if (_deletenode->getValue() < _deletenodeparent->getValue())
            _deletenodeparent->setLeft(_deletenode->getRight());
        else
            _deletenodeparent->setRight(_deletenode->getRight());
        _deletenode->getRight()->setParent(_deletenodeparent);
    }
    else
    {
        BinaryTreeNode *LeftMaxNode = m_fFindLeftSubTreeMaxNode(_deletenode);
        if (LeftMaxNode == _deletenode->getLeft())
        {
            LeftMaxNode->setParent(_deletenodeparent);
            if (_deletenodeparent->getLeft() == _deletenode)
                _deletenodeparent->setLeft(LeftMaxNode);
            else
                _deletenodeparent->setRight(LeftMaxNode);
            LeftMaxNode->setRight(_deletenode->getRight());
            _deletenode->getRight()->setParent(LeftMaxNode);
        }
        else
        {
            _deletenode->setValue(LeftMaxNode->getValue());
            LeftMaxNode->getParent()->setRight(LeftMaxNode->getLeft());
            if (LeftMaxNode->getLeft())
                LeftMaxNode->getLeft()->setParent(LeftMaxNode->getParent());
            _deletenode = LeftMaxNode;
        }
    }

    delete _deletenode;
    _deletenode = nullptr;
}

BinaryTreeNode *BinaryTree::m_fFindLeftSubTreeMaxNode(BinaryTreeNode *node)
{
    BinaryTreeNode *leftmax = nullptr, *left = node->getLeft();
    while (left)
    {
        leftmax = left;
        left = left->getRight();
    }
    return leftmax;
}

BinaryTreeNode *BinaryTree::m_fFindRightSubTreeMinNode(BinaryTreeNode *node)
{
    BinaryTreeNode *rightmin = nullptr, *right = node->getRight();
    while (right != nullptr)
    {
        rightmin = right;
        right = right->getLeft();
    }
    return rightmin;
}

void BinaryTree::m_fPreorder(BinaryTreeNode *node)
{
    if (node)
    {
        cout << node->getValue() << " ";
        m_fPreorder(node->getLeft());
        m_fPreorder(node->getRight());
    }
}

void BinaryTree::m_fInorder(BinaryTreeNode *node)
{
    if (node)
    {
        m_fInorder(node->getLeft());
        cout << node->getValue() << " ";
        m_fInorder(node->getRight());
    }
}

void BinaryTree::m_fPostorder(BinaryTreeNode *node)
{
    if (node)
    {
        m_fPostorder(node->getLeft());
        m_fPostorder(node->getRight());
        cout << node->getValue() << " ";
    }
}

void BinaryTree::m_fLevel(vector<vector<int>> &result, BinaryTreeNode *node, int level)
{
    if (node == nullptr)
        return;
    if (level == result.size())
        result.push_back(vector<int>());
    result[level].push_back(node->getValue());
    m_fLevel(result, node->getLeft(), level + 1);
    m_fLevel(result, node->getRight(), level + 1);
}

void BinaryTree::m_fDisplay(vector<string> &result, BinaryTreeNode *node, int level)
{
    if (node != nullptr)
    {
        string tmp;

        for (int i = 0; i < level - 1; i++)
            tmp += "      ";
        if (level)
            tmp += "+-----";
        tmp += int2str(node->getValue());

        result.push_back(tmp);
        m_fDisplay(result, node->getLeft(), level + 1);
        string t;
        for (int i = 0; i < level; i++)
            t += "      ";
        t += '|';
        result.push_back(t);
        result.push_back(t);
        m_fDisplay(result, node->getRight(), level + 1);
    }
}

void BinaryTree::m_fDeleteAllNode(BinaryTreeNode *node, int &deleteNumber)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->getLeft() != nullptr)
        m_fDeleteAllNode(node->getLeft(), deleteNumber);
    if (node->getRight() != nullptr)
        m_fDeleteAllNode(node->getRight(), deleteNumber);
    if (node->getLeft() == nullptr && node->getRight() == nullptr)
    {
        BinaryTreeNode *parent = node->getParent();
        if (parent != nullptr)
        {
            if (node->getValue() < parent->getValue())
                parent->setLeft(nullptr);
            else
                parent->setRight(nullptr);
        }

        node->setParent(nullptr);
        deleteNumber++;
        m_nNumber--;
        delete node;
    }
}

BinaryTree::BinaryTree()
{
    m_pRoot = nullptr;
    m_nNumber = 0;
}

BinaryTree::~BinaryTree()
{
    int deleteNumber = 0;
    int number = getNumber();
    m_fDeleteAllNode(m_pRoot, deleteNumber);
    if (number == deleteNumber && getNumber() == 0)
        cout << "all node are deleted\n";
    else
        cout << "delete tree failed\n";
}

bool BinaryTree::FindNode(const int &value)
{
    BinaryTreeNode *node = m_fFindNode(value);
    if (node != nullptr)
        return true;
    else
        return false;
}

void BinaryTree::PrintTreePreorder()
{
    cout << "preorder: ";
    m_fPreorder(m_pRoot);
    cout << endl;
}

void BinaryTree::PrintTreeInorder()
{
    cout << "inorder: ";
    m_fInorder(m_pRoot);
    cout << endl;
}

void BinaryTree::PrintTreePostorder()
{
    cout << "postorder: ";
    m_fPostorder(m_pRoot);
    cout << endl;
}

void BinaryTree::PrintTreeLevel()
{
    vector<vector<int>> result;
    m_fLevel(result, m_pRoot, 0);
    if (result.empty())
        cout << "empty\n";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "level " << i + 1 << ":";
        for (auto t : result[i])
            cout << t << " ";
        cout << endl;
    }
}

void BinaryTree::DisplayTree()
{
    vector<string> result;
    m_fDisplay(result, m_pRoot, 0);
    for (auto t : result)
        cout << t << endl;
}

void BinaryTree::InsertNode(const int &value)
{
    if (m_pRoot == nullptr)
    {
        m_pRoot = new BinaryTreeNode(value);
    }
    else
    {
        m_fInsertNode(value, m_pRoot);
    }
    m_nNumber++;
}

void BinaryTree::DeleteNode(const int &value)
{
    BinaryTreeNode *DeleteNode = m_fFindNode(value);
    if (DeleteNode == nullptr)
    {
        cout << "no this value:" << value << endl;
        return;
    }
    else if (DeleteNode == m_pRoot)
    {
        m_fDeleteRoot();
    }
    else
    {
        m_fDeleteGeneralNode(DeleteNode);
    }
    m_nNumber--;
}

int BinaryTree::getNumber(void)
{
    return m_nNumber;
}
}
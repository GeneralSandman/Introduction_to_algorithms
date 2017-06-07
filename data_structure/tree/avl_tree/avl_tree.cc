#include <iostream>
#include "avl_tree.h"

namespace Avl
{

AvlTreeNode *AvlTree::m_fFindNode(const int &value)
{
    if (m_pRoot == nullptr)
    {
        return nullptr;
    }

    AvlTreeNode *node = m_pRoot;
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

void AvlTree::m_fInsertNode(const int &value, AvlTreeNode *node)
{

    if (value < node->getValue())
    {
        if (node->getLeft() == nullptr)
        {
            AvlTreeNode *newnode = new AvlTreeNode(value);
            newnode->setParent(node);
            node->setLeft(newnode);
        }
        else
            m_fInsertNode(value, node->getLeft());

        if (m_fGetHeight(node->getLeft()) - m_fGetHeight(node->getRight()) == 2)
        {
            if (value < node->getLeft()->getValue())
            {
                m_fRoatLeftLeft(node);
            }
            else
            {
                m_fRoatLeftRight(node);
            }
        }
    }
    else if (value > node->getValue())
    {
        if (node->getRight() == nullptr)
        {
            AvlTreeNode *newnode = new AvlTreeNode(value);
            newnode->setParent(node);
            node->setRight(newnode);
        }
        else
            m_fInsertNode(value, node->getRight());

        if (m_fGetHeight(node->getLeft()) - m_fGetHeight(node->getRight()) == -2)
        {
            if (value > node->getRight()->getValue())
            {
                m_fRoatRightRight(node);
            }
            else
            {
                m_fRoatRightLeft(node);
            }
        }
    }
}

void AvlTree::m_fFixAfterInsert(AvlTreeNode *node){

}

void AvlTree::m_fDeleteRoot()
{
    AvlTreeNode *_deletenode = m_pRoot;

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
        AvlTreeNode *LeftMaxNode = m_fFindLeftSubTreeMaxNode(m_pRoot);
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

void AvlTree::m_fDeleteGeneralNode(AvlTreeNode *_deletenode)
{
    AvlTreeNode *_deletenodeparent;
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
        AvlTreeNode *LeftMaxNode = m_fFindLeftSubTreeMaxNode(_deletenode);
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
            int tmp = _deletenode->getValue();
            _deletenode->setValue(LeftMaxNode->getValue());
            LeftMaxNode->setValue(tmp);
            LeftMaxNode->getParent()->setRight(LeftMaxNode->getLeft());
            if (LeftMaxNode->getLeft())
                LeftMaxNode->getLeft()->setParent(LeftMaxNode->getParent());
            _deletenode = LeftMaxNode;
        }
    }

    delete _deletenode;
    _deletenode = nullptr;
}

AvlTreeNode *AvlTree::m_fFindLeftSubTreeMaxNode(AvlTreeNode *node)
{
    AvlTreeNode *leftmax = nullptr, *left = node->getLeft();
    while (left)
    {
        leftmax = left;
        left = left->getRight();
    }
    return leftmax;
}

AvlTreeNode *AvlTree::m_fFindRightSubTreeMinNode(AvlTreeNode *node)
{
    AvlTreeNode *rightmin = nullptr, *right = node->getRight();
    while (right != nullptr)
    {
        rightmin = right;
        right = right->getLeft();
    }
    return rightmin;
}

void AvlTree::m_fPreorder(AvlTreeNode *node)
{
    if (node)
    {
        cout << node->getValue() << " ";
        m_fPreorder(node->getLeft());
        m_fPreorder(node->getRight());
    }
}

void AvlTree::m_fInorder(AvlTreeNode *node)
{
    if (node)
    {
        m_fInorder(node->getLeft());
        cout << node->getValue() << " ";
        m_fInorder(node->getRight());
    }
}

void AvlTree::m_fPostorder(AvlTreeNode *node)
{
    if (node)
    {
        m_fPostorder(node->getLeft());
        m_fPostorder(node->getRight());
        cout << node->getValue() << " ";
    }
}

void AvlTree::m_fLevel(vector<vector<int>> &result, AvlTreeNode *node, int level)
{
    if (node == nullptr)
        return;
    if (level == result.size())
        result.push_back(vector<int>());
    result[level].push_back(node->getValue());
    m_fLevel(result, node->getLeft(), level + 1);
    m_fLevel(result, node->getRight(), level + 1);
}

void AvlTree::m_fDisplay(vector<string> &result, AvlTreeNode *node, int level)
{
    if (node != nullptr)
    {
        string tmp;

        for (int i = 0; i < level - 1; i++)
            tmp += "      ";
        if (level)
            tmp += "+-----";
        tmp += std::to_string(node->getValue());

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

void AvlTree::m_fDeleteAllNode(AvlTreeNode *node, int &deleteNumber)
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
        AvlTreeNode *parent = node->getParent();
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

int AvlTree::m_fGetHeight(AvlTreeNode *node)
{
    if (node == nullptr)
        return 0;
    return max(m_fGetHeight(node->getLeft()), m_fGetHeight(node->getRight())) + 1;
}

AvlTree::AvlTree()
{
    m_pRoot = nullptr;
    m_nNumber = 0;
}

AvlTree::~AvlTree()
{
    int deleteNumber = 0;
    int number = getNumber();
    m_fDeleteAllNode(m_pRoot, deleteNumber);
    if (number == deleteNumber && getNumber() == 0)
        cout << "all node are deleted\n";
    else
        cout << "delete tree failed\n";
}

bool AvlTree::FindNode(const int &value)
{
    AvlTreeNode *node = m_fFindNode(value);
    if (node != nullptr)
        return true;
    else
        return false;
}

void AvlTree::PrintTreePreorder()
{
    cout << "preorder: ";
    m_fPreorder(m_pRoot);
    cout << endl;
}

void AvlTree::PrintTreeInorder()
{
    cout << "inorder: ";
    m_fInorder(m_pRoot);
    cout << endl;
}

void AvlTree::PrintTreePostorder()
{
    cout << "postorder: ";
    m_fPostorder(m_pRoot);
    cout << endl;
}

void AvlTree::PrintTreeLevel()
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

void AvlTree::DisplayTree()
{
    vector<string> result;
    m_fDisplay(result, m_pRoot, 0);
    for (auto t : result)
        cout << t << endl;
}

void AvlTree::InsertNode(const int &value)
{
    if (m_pRoot == nullptr)
    {
        m_pRoot = new AvlTreeNode(value);
    }
    else
    {
        m_fInsertNode(value, m_pRoot);
    }
    m_nNumber++;
}

void AvlTree::DeleteNode(const int &value)
{
    AvlTreeNode *DeleteNode = m_fFindNode(value);
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

int AvlTree::getNumber(void)
{
    return m_nNumber;
}

bool AvlTree::testBalance(void)
{
    int balace = abs(m_fGetHeight(m_pRoot->getLeft()) - m_fGetHeight(m_pRoot->getRight()));
    if (balace > 1)
        return false;
    else
        return true;
}

void AvlTree::testRoat(void)
{
    AvlTreeNode *node = m_fFindNode(10);
    m_fRoatLeftRight(node);
}
void AvlTree::m_fLeftRotate(AvlTreeNode *node)
{
    /* 
		 * 左旋示意图：对节点x进行左旋 
		 *     p                       p 
		 *    /                       / 
		 *   x                       y 
		 *  / \                     / \ 
		 * lx  y      ----->       x  ry 
		 *    / \                 / \ 
		 *   ly ry               lx ly 
		 */
    AvlTreeNode *x = node;
    AvlTreeNode *p = x->getParent();
    AvlTreeNode *lx = x->getLeft();
    AvlTreeNode *y = x->getRight();
    AvlTreeNode *ly = y->getLeft();
    AvlTreeNode *ry = y->getRight();

    x->setRight(ly);
    if (ly)
        ly->setParent(x);

    y->setParent(p);
    if (p)
    {
        if (x == p->getLeft())
            p->setLeft(y);
        else
            p->setRight(y);
    }
    else
    {
        m_pRoot = y;
    }

    y->setLeft(x);
    x->setParent(y);
}
void AvlTree::m_fRightRotate(AvlTreeNode *node)
{
    /* 
		 * 左旋示意图：对节点y进行右旋 
		 *        p                   p 
		 *       /                   / 
		 *      y                   x 
		 *     / \                 / \ 
		 *    x  ry   ----->      lx  y 
		 *   / \                     / \ 
		 * lx  rx                   rx ry 

		 */

    AvlTreeNode *y = node;
    AvlTreeNode *p = y->getParent();
    AvlTreeNode *x = y->getLeft();
    AvlTreeNode *lx = x->getLeft();
    AvlTreeNode *rx = x->getRight();
    AvlTreeNode *ry = y->getRight();

    y->setLeft(rx);
    if (rx)
        rx->setParent(y);

    x->setParent(p);
    if (p)
    {
        if (y == p->getLeft())
            p->setLeft(x);
        else
            p->setRight(x);
    }
    else
    {
        m_pRoot = x;
    }

    x->setRight(y);
    y->setParent(x);
}

void AvlTree::m_fRoatLeftLeft(AvlTreeNode *node)
{
    /*
            x            y
           / \         /    \
          y   q       z     x
         /           /        \
        z           w           q
       /
       w
      
      */

    m_fRightRotate(node);
}
void AvlTree::m_fRoatLeftRight(AvlTreeNode *node)
{
    m_fLeftRotate(node->getLeft());
    PrintTreeLevel();

    m_fRightRotate(node);
}
void AvlTree::m_fRoatRightLeft(AvlTreeNode *node)
{
    m_fRightRotate(node->getRight());
    m_fLeftRotate(node);
}
void AvlTree::m_fRoatRightRight(AvlTreeNode *node)
{
    m_fLeftRotate(node);
}
}
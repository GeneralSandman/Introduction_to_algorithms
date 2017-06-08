#include <iostream>
#include "rb_tree.h"

namespace Rb
{
using namespace std;
RbTreeNode *RbTree::m_fFindNode(const int &value)
{
    if (m_pRoot == nullptr)
    {
        return nullptr;
    }

    RbTreeNode *node = m_pRoot;
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

void RbTree::m_fFixAfterInsert(RbTreeNode *node)
{
    RbTreeNode *parent = nullptr, *gparent = nullptr;

    while ((parent = node->getParent()) != nullptr && parent->getColor() == red)
    {
        gparent = node->getGParent();

        if (parent == gparent->getLeft())
        {
            RbTreeNode *uncle = node->getUncle();

            if (uncle != nullptr && uncle->getColor() == red)
            {
                parent->setColor(black);
                uncle->setColor(black);
                gparent->setColor(red);
                node = gparent;
                continue;
            }

            if (node == parent->getRight())
            { //uncle is black && node is parent's right-node
                m_fLeftRotate(parent);
                RbTreeNode *tmp = parent;
                parent = node;
                node = tmp;
            }

            parent->setColor(black);
            gparent->setColor(red);
            m_fRightRotate(gparent);
        }
        else
        {
            RbTreeNode *uncle = node->getUncle();

            if (uncle != nullptr && uncle->getColor() == red)
            {
                parent->setColor(black);
                uncle->setColor(black);
                gparent->setColor(red);
                node = gparent;
                continue;
            }

            if (node == parent->getLeft())
            {
                m_fRightRotate(parent);
                RbTreeNode *tmp = parent;
                parent = node;
                node = tmp;
            }

            parent->setColor(black);
            gparent->setColor(red);
            m_fLeftRotate(gparent);
        }
    }

    m_pRoot->setColor(black);
}

void RbTree::m_fInsertNode(const int &value, RbTreeNode *node)
{
    RbTreeNode *pre = node, *insert = node;
    while (insert != nullptr)
    {
        pre = insert;

        if (value < insert->getValue())
            insert = insert->getLeft();
        else if (value > insert->getValue())
            insert = insert->getRight();
    }

    RbTreeNode *newnode = new RbTreeNode(value);
    newnode->setParent(pre);
    if (value < pre->getValue())
        pre->setLeft(newnode);
    else if (value > pre->getValue())
        pre->setRight(newnode);

    m_fFixAfterInsert(newnode);
}

void RbTree::m_fDeleteRoot()
{
    RbTreeNode *_deletenode = m_pRoot;

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
        RbTreeNode *LeftMaxNode = m_fFindLeftSubTreeMaxNode(m_pRoot);
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

void RbTree::m_fDeleteGeneralNode(RbTreeNode *_deletenode)
{
    RbTreeNode *_deletenodeparent;
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
        RbTreeNode *LeftMaxNode = m_fFindLeftSubTreeMaxNode(_deletenode);
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

RbTreeNode *RbTree::m_fFindLeftSubTreeMaxNode(RbTreeNode *node)
{
    RbTreeNode *leftmax = nullptr, *left = node->getLeft();
    while (left)
    {
        leftmax = left;
        left = left->getRight();
    }
    return leftmax;
}

RbTreeNode *RbTree::m_fFindRightSubTreeMinNode(RbTreeNode *node)
{
    RbTreeNode *rightmin = nullptr, *right = node->getRight();
    while (right != nullptr)
    {
        rightmin = right;
        right = right->getLeft();
    }
    return rightmin;
}

void RbTree::m_fPreorder(RbTreeNode *node)
{
    if (node)
    {
        cout << node->getValue() << " ";
        m_fPreorder(node->getLeft());
        m_fPreorder(node->getRight());
    }
}

void RbTree::m_fInorder(RbTreeNode *node)
{
    if (node)
    {
        m_fInorder(node->getLeft());
        cout << node->getValue() << " ";
        m_fInorder(node->getRight());
    }
}

void RbTree::m_fPostorder(RbTreeNode *node)
{
    if (node)
    {
        m_fPostorder(node->getLeft());
        m_fPostorder(node->getRight());
        cout << node->getValue() << " ";
    }
}

void RbTree::m_fLevel(vector<vector<int>> &result, RbTreeNode *node, int level)
{
    if (node == nullptr)
        return;
    if (level == result.size())
        result.push_back(vector<int>());
    result[level].push_back(node->getValue());
    m_fLevel(result, node->getLeft(), level + 1);
    m_fLevel(result, node->getRight(), level + 1);
}

void RbTree::m_fDisplay(vector<string> &result, RbTreeNode *node, int level)
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

void RbTree::m_fDeleteAllNode(RbTreeNode *node, int &deleteNumber)
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
        RbTreeNode *parent = node->getParent();
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

int RbTree::m_fGetHeight(RbTreeNode *node)
{
    if (node == nullptr)
        return 0;
    return max(m_fGetHeight(node->getLeft()), m_fGetHeight(node->getRight())) + 1;
}

RbTree::RbTree()
{
    m_pRoot = nullptr;
    m_nNumber = 0;
}

RbTree::~RbTree()
{
    int deleteNumber = 0;
    int number = getNumber();
    m_fDeleteAllNode(m_pRoot, deleteNumber);
    if (number == deleteNumber && getNumber() == 0)
        cout << "all node are deleted\n";
    else
        cout << "delete tree failed\n";
}

bool RbTree::FindNode(const int &value)
{
    RbTreeNode *node = m_fFindNode(value);
    if (node != nullptr)
        return true;
    else
        return false;
}

void RbTree::PrintTreePreorder()
{
    cout << "preorder: ";
    m_fPreorder(m_pRoot);
    cout << endl;
}

void RbTree::PrintTreeInorder()
{
    cout << "inorder: ";
    m_fInorder(m_pRoot);
    cout << endl;
}

void RbTree::PrintTreePostorder()
{
    cout << "postorder: ";
    m_fPostorder(m_pRoot);
    cout << endl;
}

void RbTree::PrintTreeLevel()
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

void RbTree::DisplayTree()
{
    vector<string> result;
    m_fDisplay(result, m_pRoot, 0);
    for (auto t : result)
        cout << t << endl;
}

void RbTree::InsertNode(const int &value)
{
    if (m_pRoot == nullptr)
    {
        m_pRoot = new RbTreeNode(value);
    }
    else
    {
        m_fInsertNode(value, m_pRoot);
    }
    m_nNumber++;
}

void RbTree::DeleteNode(const int &value)
{
    RbTreeNode *DeleteNode = m_fFindNode(value);
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

int RbTree::getNumber(void)
{
    return m_nNumber;
}

bool RbTree::testBalance(void)
{
    int balace = abs(m_fGetHeight(m_pRoot->getLeft()) - m_fGetHeight(m_pRoot->getRight()));
    if (balace > 1)
        return false;
    else
        return true;
}

void RbTree::testRoat(void)
{
    RbTreeNode *node = m_fFindNode(10);
    m_fRoatLeftRight(node);
}
void RbTree::m_fLeftRotate(RbTreeNode *node)
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
    RbTreeNode *x = node;
    RbTreeNode *p = x->getParent();
    RbTreeNode *lx = x->getLeft();
    RbTreeNode *y = x->getRight();
    RbTreeNode *ly = y->getLeft();
    RbTreeNode *ry = y->getRight();

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
void RbTree::m_fRightRotate(RbTreeNode *node)
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

    RbTreeNode *y = node;
    RbTreeNode *p = y->getParent();
    RbTreeNode *x = y->getLeft();
    RbTreeNode *lx = x->getLeft();
    RbTreeNode *rx = x->getRight();
    RbTreeNode *ry = y->getRight();

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

void RbTree::m_fRoatLeftLeft(RbTreeNode *node)
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
void RbTree::m_fRoatLeftRight(RbTreeNode *node)
{
    m_fLeftRotate(node->getLeft());
    PrintTreeLevel();

    m_fRightRotate(node);
}
void RbTree::m_fRoatRightLeft(RbTreeNode *node)
{
    m_fRightRotate(node->getRight());
    m_fLeftRotate(node);
}
void RbTree::m_fRoatRightRight(RbTreeNode *node)
{
    m_fLeftRotate(node);
}
}

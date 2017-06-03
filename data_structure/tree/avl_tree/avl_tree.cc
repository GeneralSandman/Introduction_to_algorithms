#include <iostream>
#include "../binary_tree/binary_tree.h"
#include "avl_tree.h"
namespace Avl
{
using namespace Tree;

AvlTreeNode::AvlTreeNode(const int &value) : BinaryTreeNode(value)
{
    m_nHeight = 0;
    m_nBalanceFactor = 0;
}

AvlTreeNode::~AvlTreeNode()
{
    cout << "distory avltreenode" << endl;
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
    AvlTreeNode *p = (AvlTreeNode *)(x->m_pParent);
    AvlTreeNode *lx = x->GetLeft();
    AvlTreeNode *y = x->GetRight();
    AvlTreeNode *ly = y->GetLeft();
    AvlTreeNode *ry = y->GetRight();

    x->SetRight(ly);
    if (ly)
        ly->SetParent(x);
    
    y->SetParent(p);
    if (p)
    {
        if (x == p->m_pLeft)
            p->SetLeft(y);
        else
            p->SetRight(y);
    }
    else
    {
        m_pRoot = y;
    }

    y->SetLeft(x);
    x->SetParent(y);
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
    AvlTreeNode *p = y->m_pParent;
    AvlTreeNode *x = y->m_pLeft;
    AvlTreeNode *lx = x->m_pLeft;
    AvlTreeNode *rx = y->m_pRight;
    AvlTreeNode *ry = y->m_pRight;

    y->m_pLeft = rx;
    if (rx)
        rx->m_pParent = y;

    x->m_pParent = p;
    if (p)
    {
        if (y == p->m_pLeft)
            p->m_pLeft = x;
        else
            p->m_pRight = x;
    }
    else
    {
        m_pRoot = x;
    }

    x->m_pRight = y;
    y->m_pParent = x;
}
}
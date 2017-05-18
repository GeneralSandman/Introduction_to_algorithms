

namespace RBtree
{

void RBTree::m_fLeftRotate(RBNode *node)
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
    RBNode *x = node;
    RBNode *p = x->m_pParent;
    RBNode *lx = x->m_pLeft;
    RBNode *y = x->m_pRight;
    RBNode *ly = y->m_pLeft;
    RBNode *ry = y->m_pRight;

    x->m_pRight = ly;
    if (ly)
        ly->m_pParent = x;

    y->m_pParent = p;
    if (p)
    {
        if (x == p->m_pLeft)
            p->m_pLeft = y;
        else
            p->m_pRight = y;
    }
    else
    {
        m_pRoot = y;
    }

    y->m_pLeft = x;
    x->m_pParent = y;
}
void RBTree::m_fRightRotate(RBNode *node)
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

    RBNode *y = node;
    RBNode *p = y->m_pParent;
    RBNode *x = y->m_pLeft;
    RBNode *lx = x->m_pLeft;
    RBNode *rx = y->m_pRight;
    RBNode *ry = y->m_pRight;

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

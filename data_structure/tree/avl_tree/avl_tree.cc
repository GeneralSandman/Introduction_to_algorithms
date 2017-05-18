
namespace Avl
{

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
    AvlTreeNode *p = x->m_pParent;
    AvlTreeNode *lx = x->m_pLeft;
    AvlTreeNode *y = x->m_pRight;
    AvlTreeNode *ly = y->m_pLeft;
    AvlTreeNode *ry = y->m_pRight;

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

int AvlTree::m_nGetHeight(AvlTreeNode *node)
{
    return node->m_nHeight;
}

void AvlTree::m_nUpdateNodeHeight(AvlTreeNode *node)
{
    //continue
    node->m_nHeight = 1 + max()
}
}
#include <iostream>
#include "head.h"

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

BinaryTreeNode::~BinaryTreeNode()
{
    cout << "distory BinaryTreeNode: " << m_nValue << endl;
}

BinaryTree::BinaryTree()
{
    m_nRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
    //distory node from bottom
    //invoke the deleteNode() function
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

vector<vector<int>> BinaryTree::PrintTreeLevel()
{
    //
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
	    insertPosition = insertPoition->m_pLeft;
	else if (value == insertPosition->m_nValue)
	{
	    cout << "this value exists.\n";
	    goto DONE;
	}
	else
	    insertPosition = insertPosition->m_pRight;
    }

    if (m_pRoot == nullptr)
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

DONE:
}

void BinaryTree::DeleteNode(const int &value)
{
    BinaryTreeNode *DeleteNode = m_fFindNode(value);
    if (DeleteNode == m_pRoot)
	m_fDeleteRoot();
    else
	m_fDeleteGeneralNode();
}

BinaryTreeNode *BinaryTree::m_fFindNode(const int &value)
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
	BinaryTreeNode *LeftMaxNode = FindLeftSubTreeMaxNode();
	if (LeftMaxNode == _deletenode->m_pLeft)
	{
	    LeftMaxNode->m_pRight = m_pRoot->m_pRight;
	    m_pRoot->Right->m_pParent = LeftMaxNode;
	    m_pRoot = LeftMaxNode;
	    m_PRoot->m_pParent = nullptr;
	}
	else
	{
	    m_nRoot->m_nValue = LeftMaxNode->m_nValue;
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
	BinaryTreeNode *LeftMaxNode = FindLeftSubTreeMaxNode(_deletenode);
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
    BinaryTreeNode *leftmax = nullptr, left = node->m_pLeft;
    while (left)
    {
	leftmax = left;
	left = left->m_pRight;
    }
    return leftmax;
}

BinaryTreeNode *BinaryTree::m_fFindRightSubTreeMinNode(BinaryTreeNode *node)
{
    BinaryTreeNode *rightmin = nullptr, right = node->m_pRight;
    while (right)
    {
	rightmin = right;
	right = right->m_pLeft;
    }
    return rightmin;
}

void BinaryTree::Preorder(BinaryTreeNode *node)
{
    if (node)
    {
	cout << node->m_nValue << " ";
	Preorder(node->m_pLeft);
	Preorder(node->m_pRight);
    }
}

void BinaryTree::Inorder(BinaryTreeNode *node)
{
    if (node)
    {
	Inorder(node->m_pLeft);
	cout << node->m_nValue << " ";
	Inorder(node->m_pRight);
    }
}

void BinaryTree::Postorder(BinaryTreeNode *node)
{
    if (node)
    {
	Postorder(node->m_pLeft);
	Postorder(node->m_pRight);
	cout << node->m_nValue << " ";
    }
}
}
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

namespace Huffman
{

HuffmanNode::HuffmanNode(const Node &node)
{
    m_nChar = node.m_nChar;
    m_nFrequency = node.m_nFrequency;
    m_pParent = nullptr;
    m_pLeft = nullptr;
    m_pRight = nullptr;
}

HuffmanNode::HuffmanNode(HuffmanNode &node1, HuffmanNode &node2)
{
    m_nChar = '\0';
    m_nFrequency = node1.m_nFrequency + node2.m_nFrequency;
    m_pParent = nullptr;
    if (node1.m_nFrequency > node2.m_nFrequency)
    {
	m_pLeft = node1;
	node1.m_pParent = this;
	m_pRight = node2;
	node2.m_pParent = this;
    }
    else
    {
	m_pLeft = node2;
	node1.m_pParent = this;
	m_pRight = node1;
	node2.m_pParent = this;
    }
}

////
HuffmanTree::HuffmanTree(vector<Node> &source)
{
    for (auto t : source)
    {
	HuffmanNode tmp(t);
	m_nQueue.push(tmp);
    }
    //in this way,all the HuffmanNode will be deleted
    //we must change the function!!!!!
    while (m_nQueue.size())
    {
	if (m_nQueue.size() == 1)
	{
	    HuffmanNode root = m_nQueue.top();
	    m_nQueue.pop();
	    m_pRoot = &root;
	    break;
	}

	HuffmanNode node1, node2;
	node1 = m_nQueue.top();
	m_nQueue.pop();
	node2 = m_nQueue.top();
	m_nQueue.pop();

	HuffmanNode NewNode(node1, node2);
	m_nQueue.push(NewNode);
    }
}

bool HuffmanTree::m_fCompare(HuffmanNode *node1, HuffmanNode *node2)
{
    return node1->m_nFrequency < node2->m_nFrequency;
}

void HuffmanTree::GenerateCode(HuffmanNode *node, vector<int> &code)
{
    ///continue
}
}

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

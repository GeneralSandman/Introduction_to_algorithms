#include <iostream>
#include "head.h"

using namespace std;
/*
   15
   10		20
   8	12		17	25
   6 9	11 13		16 18	21 27


 */
int main()
{

    return 0;
}

void TreeTest(void)
{

    BinaryTree tree;
    tree.insertNode(15);
    tree.insertNode(10);
    tree.insertNode(20);
    tree.insertNode(8);
    tree.insertNode(12);
    tree.insertNode(17);
    tree.insertNode(25);
    tree.insertNode(6);
    tree.insertNode(9);
    tree.insertNode(11);
    tree.insertNode(13);
    tree.insertNode(16);
    tree.insertNode(18);
    tree.insertNode(21);
    tree.insertNode(27);
    tree.printTreePreorder();
    tree.printTreeLevel();

    tree.deleteNode(15);
    tree.deleteNode(13);
    tree.deleteNode(12);

    tree.printTreeLevel();

    //test AvlTree
    AvlTree balancedtree;

    balancedtree.insertNode(1);
    balancedtree.insertNode(2);
    balancedtree.printTreePreorder();
    balancedtree.printTreeLevel();
    balancedtree.insertNode(3);
    balancedtree.insertNode(4);
    balancedtree.printTreePreorder();
    balancedtree.printTreeLevel();
    balancedtree.insertNode(5);
    balancedtree.insertNode(6);
    balancedtree.printTreePreorder();
    balancedtree.printTreeLevel();
    balancedtree.insertNode(7);
    balancedtree.insertNode(8);
    balancedtree.printTreePreorder();
    balancedtree.printTreeLevel();
    balancedtree.insertNode(9);
    balancedtree.insertNode(10);
    balancedtree.printTreePreorder();
    balancedtree.printTreeLevel();
}

void BlancedTreeTest(void)
{
}

void HuffmanTest(void)
{
    vector<Node> inode;
    inode.push_back(Node('a', 4));
    inode.push_back(Node('e', 4));
    inode.push_back(Node('f', 3));
    inode.push_back(Node('h', 2));
    inode.push_back(Node('i', 2));
    inode.push_back(Node('m', 2));
    inode.push_back(Node('n', 2));
    inode.push_back(Node('s', 2));
    inode.push_back(Node('t', 2));
    inode.push_back(Node('l', 1));
    inode.push_back(Node('o', 1));
    inode.push_back(Node('p', 1));
    inode.push_back(Node('r', 1));
    inode.push_back(Node('u', 1));
    inode.push_back(Node('x', 1));
    inode.push_back(Node(' ', 7));

    HuffmanTree htree(inode);
    cout << "the huffman code is:\n";
    htree.PrintCode();
}

void B_TreeTest()
{
}

void RBTreeTest()
{
}

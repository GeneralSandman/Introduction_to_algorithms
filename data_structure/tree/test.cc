#include <iostream>
#include "./binary_tree/binary_tree.h"

using namespace std;
/*
        15
    10		        20
   8	12		    17	    25
   6 9	11 13		16 18	21 27


 */

void BinaryTreeTest(void);

int main()
{
    BinaryTreeTest();

    return 0;
}

void BinaryTreeTest(void)
{
     using namespace Tree;
    {
        BinaryTree tree;
        tree.InsertNode(15);
        tree.InsertNode(10);
        tree.InsertNode(20);
        tree.InsertNode(8);
        tree.InsertNode(12);
        tree.InsertNode(17);
        tree.InsertNode(25);
        tree.InsertNode(6);
        tree.InsertNode(9);
        tree.InsertNode(11);
        tree.InsertNode(13);
        tree.InsertNode(16);
        tree.InsertNode(18);
        tree.InsertNode(21);
        tree.InsertNode(27);
        tree.PrintTreePreorder();
        tree.PrintTreeLevel();

        tree.DeleteNode(15);
        tree.PrintTreeLevel();

        tree.DeleteNode(27);
        tree.PrintTreeLevel();

        tree.DeleteNode(12);
        tree.PrintTreeLevel();
    }
}

void BlancedTreeTest(void)
{
   
}

void HuffmanTest(void)
{
    // vector<Node> inode;
    // inode.push_back(Node('a', 4));
    // inode.push_back(Node('e', 4));
    // inode.push_back(Node('f', 3));
    // inode.push_back(Node('h', 2));
    // inode.push_back(Node('i', 2));
    // inode.push_back(Node('m', 2));
    // inode.push_back(Node('n', 2));
    // inode.push_back(Node('s', 2));
    // inode.push_back(Node('t', 2));
    // inode.push_back(Node('l', 1));
    // inode.push_back(Node('o', 1));
    // inode.push_back(Node('p', 1));
    // inode.push_back(Node('r', 1));
    // inode.push_back(Node('u', 1));
    // inode.push_back(Node('x', 1));
    // inode.push_back(Node(' ', 7));

    // HuffmanTree htree(inode);
    // cout << "the huffman code is:\n";
    // htree.PrintCode();
}

void B_TreeTest()
{
}

void RBTreeTest()
{
}

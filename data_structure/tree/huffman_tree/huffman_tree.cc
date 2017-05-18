#include<iostream>
#include"huffman_tree.h"

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
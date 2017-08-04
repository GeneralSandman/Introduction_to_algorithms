#ifndef SKIPLIST_H
#define SKIPLIST_H
#include <iostream>
#include <cstddef>

namespace list
{
template <typename T>
class SkipListNode;

template <typename T>
class SkipListNode
{
  private:
    T m_nValue;
    double m_nScore;
    SkipListNode *m_pBack;
    struct SkipListLevel
    {
        SkipListNode *m_pForward;
        size_t m_nSpan;
    } m_vLevel[];

public:
    SkipListNode();
    ~SkipListNode();
};

template <typename T>
class SkipList
{
  private:
    SkipListNode<T> *m_pHead;
    SkipListNode<T> *m_pTail;
    size_t m_nLen;
    int m_nMaxLevel;
    public:
    SkipList();
    bool insertNode(SkipListNode<T> *);
    bool deleteNode(SkipListNode<T> *);
    ~SkipList();
};

//api
}

#endif // !SKIPLIST_H
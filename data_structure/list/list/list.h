#ifndef LIST_H
#define LIST_H
#include <iostream>

namespace list
{
template <typename T>
class ListNode
{
  private:
    ListNode *m_pPrev;
    ListNode *m_pNext;
    T m_nValue;

  public:
    ListNode(const T &v) : m_nValue(v), m_pPrev(nullptr), m_pNext(nullptr) {}
    ListNode *getPrev() { return m_pPrev; }
    ListNode *getNext() { return m_pNext; }
    ListNode *getValue() { return m_nValue; }

    void setPrev(ListNode *node) { m_pPrev = node; }
    void setNext(ListNode *node) { m_pNext = node; }
    void setValue(const T &v) { m_nValue = m_nValue; }
    ~ListNode()
    {
        std::cout << "delete node:" << m_nValue << std::endl;
    }
};

template <typename T>
class List
{
  private:
    size_t m_nLen;
    ListNode<T> *m_pHead;
    ListNode<T> *m_pTail;

  public:
    List();
    void insertNode();
    void deleteNode();
    void insertNodeHead(ListNode<T> *);
    void insertNodeTail(ListNode<T> *);
    List duplict();
    List findNode(const T &m_nValue);
    ~List();
};

template <typename T>
class Iter
{
    ListNode<T> *m_pNext;
    int dirction;
};


template <typename T> List<T>::List():m_nLen{

}

}



#endif
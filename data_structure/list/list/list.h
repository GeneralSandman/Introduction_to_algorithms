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
  size_t getLen() { return m_nLen; }
  bool insertNode(ListNode<T> *, ListNode<T> *, int);
  bool deleteNode(ListNode<T> *);
  bool addNodeHead(ListNode<T> *);
  bool addNodeTail(ListNode<T> *);
  List dupLict();
  List findNode(const T &m_nValue);
  ~List();
};

template <typename T>
class Iter
{
  ListNode<T> *m_pNext;
  int dirction;
};

// api-------------------
template <typename T>
List<T>::List()
{
  m_nLen = 0;
  m_pHead = nullptr;
  m_pTail = nullptr;
}

template <typename T>
bool List<T>::insertNode(ListNode<T> *newnode, ListNode<T> *oldnode, int after)
{

  if (after)
  {
    ListNode<T> *oldnext = oldnode->m_pNext;
    newnode->m_pNext = oldnext;
    newnode->m_pPrev = oldnode;
    oldnode->m_pNext = newnode;
    if (oldnext)
      oldnext->m_pPrev = newnode;
    if (m_pTail == oldnode)
      m_pTail = newnode;
  }
  else
  {
    ListNode<T> *oldprev = oldnode->m_pPrev;
    newnode->m_pPrev = oldprev;
    newnode->m_pNext = oldnode;
    oldnode->m_pPrev = newnode;
    if (oldprev)
      oldprev->m_pNext = newnode;
    if (m_pHead == oldnode)
      m_pHead = newnode;
  }

  m_nLen++;
  return true;
}

template <typename T>
bool List<T>::deleteNode(ListNode<T> *node){
  

  m_nLen--;
  return true;
}

template <typename T>
bool List<T>::addNodeHead(ListNode<T> *node)
{

  if (getLen() == 0)
  {
    m_pHead = m_pTail = node;
    node->m_pPrev = node->m_pNext = nullptr;
  }
  else
  {
    node->m_pPrev = nullptr;
    m_pHead->m_pPrev = node;
    node->m_pNext = m_pHead;
    m_pHead = node;
  }
  m_nLen++;
  return true;
}

template <typename T>
bool List<T>::addNodeTail(ListNode<T> *node)
{
  if (getLen() == 0)
  {
    m_pHead = m_pTail = node;
    node->m_pPrev = node->m_pNext = nullptr;
  }
  else
  {
    node->m_pNext = nullptr;
    m_pTail->m_pNext = node;
    node->m_pPrev = m_pTail;
    m_pTail = node;
  }
  m_nLen++;
  return true;
}

template <typename T>
List<T>::~List()
{
  size_t len = getLen();
  ListNode<T> *cur = m_pHead, *next = nullptr;

  while (len)
  {
    len--;
    next = cur->m_pNext;
    delete cur;
    cur = next;
  }
}
}

#endif
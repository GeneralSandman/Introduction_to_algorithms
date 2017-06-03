#ifndef LIST_H
#define LIST_H
#include <iostream>

namespace list
{
template <typename T>
class listNode
{
  private:
    listNode *prev;
    listNode *next;
    T value;

  public:
    listNode(const T &v) : value(v), prev(nullptr), next(nullptr) {}
    listNode *getPrev() { return prev; }
    listNode *getNext() { return next; }
    listNode *getValue() { return value; }

    void setPrev(listNode *node) { prev = node; }
    void setNext(listNode *node) { next = node; }
    void setValue(const T &v) { value = value; }
    ~listNode()
    {
        std::cout << "delete node:" << value << std::endl;
    }
};

template <typename T>
class List
{
  private:
    size_t len;
    listNode<T> *head;
    listNode<T> *tail;

  public:
    List();
    void insertNode();
    void deleteNode();
    void insertNodeHead(listNode<T> *);
    void insertNodeTail(listNode<T> *);
    List duplict();
    List findNode(const T &value);
    ~List();
};

template <typename T>
class Iter
{
    listNode<T> *next;
    int dirction;
};

}



#endif
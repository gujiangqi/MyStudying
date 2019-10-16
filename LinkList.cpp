#include "LinkList.h"

template <class T>
LinkList<T>::LinkList()
{
    this->header = new LinkListNode;
    this->header->next = NULL;
    len = 0;
}

template <class T>
LinkList<T>::~LinkList()
{
    this->len = 0;
    delete header;
    header->next = NULL;
}

template <class T>
int LinkList<T>::insert(T &node, int pos)
{

    if (&node == NULL)
    {
        return -1;
    }

    DataType *ret = NULL;
    ret = new DataType;
    ret->data = &node;
    LinkListNode *tempNode = (LinkListNode *)ret;

    LinkListNode *current = this->header;

    // 假设pos为1，则在头部插入
    for (int i = 0; i < pos; i++)
    {
        current = current->next;
    }

    tempNode->next = current->next;
    current->next = tempNode;
    this->len++;
    return 0;
}

template <class T>
int LinkList<T>::length()
{
    return this->len;
}

template <class T>
T LinkList<T>::at(int pos)
{
    LinkListNode *current = this->header;
    for (int i = 0; i < pos; i++)
    {
        current = current->next;
    }
    DataType *dataTemp = (DataType *)current->next;
    // dataTemp =
    T *ret = NULL;
    ret = (T *)dataTemp->data;

    return *ret;
}

template <class T>
void LinkList<T>::del(int pos)
{
    LinkListNode *current = this->header;
    for (int i = 0; i < pos; i++)
    {
        current = current->next;
    }
    delete current->next;
    current->next = NULL;
    this->len--;
}
#include "LinkList.h"

template <typename T>
LinkList<T>::LinkList()
{
    this->length = 0;
    this->header = new LinkListNode;
    header->next = NULL;
}

template <typename T>
LinkList<T>::~LinkList()
{
}

template <typename T>
void LinkList<T>::insert(T &t, int index)
{
    // 将数据取地址赋值给业务节点
    DataType *tempdata = NULL;
    tempdata = new DataType;
    tempdata->data = &t;

    // 将业务节点赋值给链表节点
    LinkListNode *Node = (LinkListNode *)tempdata;

    LinkListNode *current = this->header;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    Node->next = current->next;
    current->next = Node;
    length++;
    // return 0;
}

template <typename T>
T LinkList<T>::at(int index)
{
    LinkListNode *current = this->header;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    // 将链表节点转成业务节点
    DataType *temp = (DataType *)current->next;

    // 将数据指针转成
    T *ret = (T *)temp->data;
    return *ret;
}

template <typename T>
void LinkList<T>::del(int index)
{
    LinkListNode *current = this->header;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    // 将删除的节点接出来
    LinkListNode *ret = NULL;
    ret = new LinkListNode;
    ret = current->next;

    // 将下下节点与当前节点相连接
    current->next = ret->next;

    // 释放内存，并置为空
    delete ret;
    ret = NULL;

    // 长度减少
    length--;
}

template <typename T>
int LinkList<T>::len()
{
    return this->length;
}
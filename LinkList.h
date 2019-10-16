#pragma once

typedef struct _tag_LinkListNode
{
    struct _tag_LinkListNode *next;
} LinkListNode;

typedef struct _tag_data
{
    LinkListNode node;
    void *data;
} DataType;

template <class T>
class LinkList
{
public:
    LinkList();                    // 初始化链表
    ~LinkList();                   // 析构链表

    int insert(T &node, int pos);  // 插入

    int length();                  // 求长度

    T at(int pos);                 // 取值

    void del(int pos);             // 删除某个元素

private:
    int len;
    LinkListNode *header;
};
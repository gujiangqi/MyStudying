/* 
    Linux内核版本的链表
    数据中包含单独的数据节点
 */

#include <iostream>
#include <cstdlib>
#include "string.h"

using namespace std;

struct LinkListNode
{
    LinkListNode *next;
};

typedef struct _Data
{
    int age;
    char name[64];
    LinkListNode next;
} NodeDef;

class MyLinkList
{
public:
    MyLinkList();                                           //初始化链表表头
    ~MyLinkList();                                          //删除链表
    NodeDef *LinkList_Insert(NodeDef *node, int index = 0); //默认头部插入数据
    // NodeDef *LinkList_InsertBack(NodeDef *node);            //默认头部插入数据
    // NodeDef *LinkList_Traval(int index);                    //查询某个节点数据
    // NodeDef *LinkList_delete(int index);                    //删除某个节点数据

private:
    int m_length;
    LinkListNode *Header;
};

MyLinkList::MyLinkList()
{
    m_length = 0;
    Header = (LinkListNode *)malloc(sizeof(LinkListNode));
    Header->next = NULL;
};
MyLinkList::~MyLinkList()
{
    m_length = 0;
    free(Header);
}

NodeDef *MyLinkList::LinkList_Insert(NodeDef *node, int index)
{
    if (node == NULL)
    {
        printf("pls input again:");
        return NULL;
    }
    NodeDef *current = Header;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    m_length++;
    return Header;
}
// NodeDef *MyLinkList::LinkList_InsertBack(NodeDef *node)
// {
//     if (node == NULL)
//     {
//         printf("pls input again:");
//         return NULL;
//     }
//     NodeDef *current = Header;
//     for (int i = 0; i < m_length; i++)
//     {
//         current = current->next;
//     }

//     current->next = node;
//     node->next = NULL;
//     m_length++;
//     return Header;
// }
// NodeDef *MyLinkList::LinkList_Traval(int index)
// {
//     NodeDef *current = Header;
//     for (int i = 0; i < index; i++)
//     {
//         current = current->next;
//     }
//     return current->next;
// }

// NodeDef *MyLinkList::LinkList_delete(int index)
// {
//     NodeDef *current = Header;
//     for (int i = 0; i < index; i++)
//     {
//         current = current->next;
//     }
//     current->next = current->next->next;
//     m_length--;
//     return Header;
// }
int main()
{
    MyLinkList myList;
    NodeDef d1, d2, d3, d4;
    // d1.age = 1;
    // strcpy(d1.name, "a");

    // d2.age = 2;
    // strcpy(d2.name, "b");

    // d3.age = 3;
    // strcpy(d3.name, "c");

    // d4.age = 4;
    // strcpy(d4.name, "d");

    // myList.LinkList_Insert(&d1);

    // NodeDef *temp = myList.LinkList_Traval(0);
    // // cout << temp->name << endl;

    // myList.LinkList_Insert(&d2);
    // myList.LinkList_InsertBack(&d3);
    // NodeDef *temp2 = myList.LinkList_Traval(2);
    // cout << temp2->name << endl;
    system("pause");
    return 0;
}

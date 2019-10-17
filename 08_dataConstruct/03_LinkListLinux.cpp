#include <iostream>
#include <cstdlib>
#include "string.h"
using namespace std;

typedef struct _tag_LinkListNode
{
    struct _tag_LinkListNode *next;
} LinkListNode;

typedef struct _tag_LinkList
{
    int length;
    LinkListNode header;
} TLinkList;

typedef struct _Teacher
{
    LinkListNode node;
    int age;
    char name[64];
} Teacher;

TLinkList *Linklist_Create()
{
    TLinkList *ret = NULL;
    ret = (TLinkList *)malloc(sizeof(TLinkList));
    memset(ret, 0, sizeof(TLinkList));
    ret->header.next = NULL;
    ret->length = 0;
    return ret;
}

void LinkList_Destory(void *list)
{
    TLinkList *tlist = (TLinkList *)list;
    if (tlist != NULL)
    {
        free(tlist);
        tlist = NULL;
    }
    return;
}

void LinkList_Clear(void *list)
{
    TLinkList *tlist = NULL;
    if (tlist == NULL)
    {
        return;
    }
    tlist = (TLinkList *)list;
    tlist->length = 0;
    tlist->header.next = NULL;
    return;
}

int LinkList_Length(void *list)
{
    TLinkList *tlist = NULL;
    tlist = (TLinkList *)list;
    if (tlist == NULL)
    {
        return -1;
    }

    return tlist->length;
}

int LinkList_Insert(void *list, LinkListNode *node, int pos)
{
    int ret = 0;
    if (list == NULL || node == NULL || pos < 0)
    {
        ret = 0;
        printf("func LinkList_Insert() err :%d \n", ret);
        return ret;
    }
    TLinkList *tlist = (TLinkList *)list;
    LinkListNode *current = &(tlist->header);
    for (int i = 0; i < pos && current->next != NULL; i++)
    {
        current = current->next;
    }

    node->next = current->next;

    // 让前面的链表链接新的节点
    current->next = node;
    tlist->length++;
    cout << tlist->length << endl;
    return 0;
}
void *LinkList_Delete(void *list, int index)
{
    TLinkList *tlist = (TLinkList *)list;
    LinkListNode *current = NULL;
    current = &(tlist->header);

    // 这个会循环至要删的节点的前一个
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    LinkListNode *temp = current->next; //先把要删的节点拿出来
    current->next = temp->next;         // 让删除节点的前一个节点指向删除节点的下一个节点
    tlist->length--;
    return temp;
}

void *Linklist_Get(void *list, int index)
{
    TLinkList *tlist = (TLinkList *)list;
    LinkListNode *current = NULL;
    current = &(tlist->header);

    //
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->next;
}

// 链表是单向的，所以3号位置保存在2号位置的next域中
int main01()
{

    system("pause");
    return 0;
}
#include <iostream>
#include <cstdlib>

using namespace std;
typedef void LinkList;

typedef struct _tag_DLinkListNode
{
    _tag_DLinkListNode *next;
    _tag_DLinkListNode *pre;
} DlinkListNode;

typedef struct _tag_DLinkList
{
    DlinkListNode head;
    int length;
    DlinkListNode *slider;
} TDLinkList;

TDLinkList *DlinkList_Creat()
{
    TDLinkList *ret = 0;
    ret = (TDLinkList *)malloc(sizeof(TDLinkList));
    ret->length = 0;
    ret->slider = (DlinkListNode *)malloc(sizeof(DlinkListNode));
    ret->slider = NULL;
    ret->head.next = NULL;
    ret->head.pre = NULL;
    return ret;
}
void DlinkList_Destroy(TDLinkList *list)
{
    free(list);
    list = NULL;
}

void DlinkList_Clear(void *list)
{
    TDLinkList *ret = (TDLinkList *)list;
    if (ret != NULL)
    {
        ret->length = 0;
        ret->head.next = NULL;
        ret->head.pre = NULL;
        ret->slider = NULL;
    }
}

int DLinkList_length(void *list)
{
    TDLinkList *ret = (TDLinkList *)list;
    return ret->length;
}

TDLinkList *DLinkList_Insert(void *list, DlinkListNode *node, int index)
{
    TDLinkList *dlist = (TDLinkList *)list;
    DlinkListNode *current = &(dlist->head); //也可以类型强制转换
    for (int i = 0; (i < index) && (current->next != NULL); i++)
    {
        current = current->next;
    }
    DlinkListNode *CurrentNext = current->next;

    // 步骤1-2
    current->next = node;
    node->next = CurrentNext;

    // 步骤3-4
    if (CurrentNext != NULL)
    {
        CurrentNext->pre = node;
    }
    node->pre = current;

    if (dlist->length == 0)
    {
        dlist->slider = node; //当插入第一个元素的时候处理游标
    }

    // 若在0处插入，需要特殊处理，新来节点next前pre指向null
    if (current == (&dlist->head))
    {
        node->pre = NULL;
    }

    return dlist;
}

DlinkListNode *DLinkList_Get(void *list, int index)
{
    TDLinkList *dlist = (TDLinkList *)list;
    DlinkListNode *current = &(dlist->head); //也可以类型强制转换
    for (int i = 0; (i < index); i++)
    {
        current = current->next;
    }
    return current->next;
}

TDLinkList *Dlinklist_Delete(void *list, int index)
{
    TDLinkList *dlist = (TDLinkList *)list;
    DlinkListNode *current = &(dlist->head); //也可以类型强制转换
    for (int i = 0; (i < index); i++)
    {
        current = current->next;
    }

    DlinkListNode *ret = current->next;
    //下下个节点，假设只有节点的时候会报错
    if (DLinkList_length(dlist) == 1)
    {
        current->next = NULL;
        free(ret);
        ret = NULL;
        return dlist;
    }

    DlinkListNode *CurrentNext = current->next->next;

    current->next = CurrentNext;
    if (index == 0)
    {
        CurrentNext->pre = NULL;
    }
    else
    {
        CurrentNext->pre = current;
    }

    free(ret);
    ret = NULL;
    return dlist;
}
int main()
{
    LinkList *p;
    system("pause");
    return 0;
}
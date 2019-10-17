#include <iostream>
#include <cstdlib>

using namespace std;

// 循环链表节点
typedef struct _tag_CircleListNode
{
    struct _tag_CircleListNode *next;
} CircleListNode;

// 数据结构体
struct value
{
    CircleListNode circlenode;
    int v;
};

typedef struct _tag_CircleList
{
    CircleListNode header;
    CircleListNode *slider;
    int length;
} TCircleList;

TCircleList *CircleList_Create()
{
    TCircleList *ret = (TCircleList *)malloc(sizeof(TCircleList));
    if (ret == NULL)
    {
        return NULL;
    }

    ret->length = 0;
    ret->header.next = NULL;
    ret->slider = NULL;
    return ret;
}

void Circle_Destory(void *list)
{
    if (list == NULL)
    {
        return;
    }
    free(list);
}

void Circle_Clear(void *list)
{
    TCircleList *slist = (TCircleList *)list;
    if (list == NULL)
    {
        return;
    }

    slist->length = 0;
    slist->slider = NULL;
    slist->header.next = NULL;
}

int CircleList_Length(void *list)
{
    TCircleList *slist = (TCircleList *)list;
    if (slist == NULL)
    {
        return -1;
    }
    return slist->length;
}
void *CircleListNode_Get(void *list, int index)
{
    TCircleList *slist = (TCircleList *)list;
    if (slist == NULL)
    {
        return (void *)-1;
    }
    CircleListNode *current = (CircleListNode *)slist;
    for (int i = 0; i <= index; i++)
    {
        current = current->next;
    }
    return current;
}
void CircleList_Insert(void *list, CircleListNode *node, int pos)
{
    TCircleList *slist = (TCircleList *)list;
    if (slist == NULL)
    {
        return;
    }

    {
        // 直接将头节点指针转成节点指针
        CircleListNode *current = (CircleListNode *)slist;
        for (int i = 0; (i < pos) && (current->next != NULL); i++)
        {
            current = current->next;
        }

        node->next = current->next;
        current->next = node;
        if (slist->length == 0)
        {
            slist->slider = node;
        }
        slist->length++;
        //若头插法
        if (current == (CircleListNode *)slist)
        {
            CircleListNode *last = (CircleListNode *)CircleListNode_Get(slist, slist->length - 1);
            last->next = current->next;
        }
    }
}

int main()
{

    value v1, v2, v3, v4;
    v1.v = 1;
    v2.v = 2;
    v3.v = 3;
    v4.v = 4;
    TCircleList *list = CircleList_Create();
    //循环链表插入
    CircleList_Insert(list, (CircleListNode *)&v1, 0);

    // 遍历
    for (int i = 0; i < 2 * CircleList_Length(list); i++)
    {
        value *vTemp = (value *)CircleListNode_Get(list, i);
        printf("%d \n", vTemp->v);
    }

    system("pause");
    return 0;
}
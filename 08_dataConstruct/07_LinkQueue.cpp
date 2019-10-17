#include <iostream>
#include <cstdlib>
#include "03_LinkListLinux.cpp"
using namespace std;
typedef struct _node_LinkQueue
{
    LinkListNode linklistnode;
    void *p;
} LinkQueueNode;
// 创建队列，相当于创建线性表
void *LinkQueue_Create()
{
    return Linklist_Create();
}

// 获取长度
int LinkQueue_Length(void *queue)
{ 
    return LinkList_Length(queue);
}

// 向队列中添加元素，相当于在尾部添加元素
void LinkQueue_Insert(void *queue, void *node)
{
    // 需要把栈的item(栈的业务节点)转化成链表的节点
    LinkQueueNode *temp = NULL;
    temp = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    memset(temp, 0, sizeof(LinkQueueNode));
    temp->p = node;
    LinkList_Insert(queue, (LinkListNode *)temp, LinkQueue_Length(queue));
}

// 从队列中删除元素 相当于从线性表的头部删除元素
void LinkQueue_Retrieve(void *queue)
{
    LinkQueueNode *temp = NULL;
    TLinkList *tempHeader = (TLinkList *)queue;
    temp = (LinkQueueNode *)LinkList_Delete(queue, 0);

    free(temp);
    temp = NULL;
}

// 获取队列头部元素，相当于从线性表的0号位置 拿数据
void *LinkQueue_Header(void *queue)
{
    LinkQueueNode *ret = NULL;
    ret = (LinkQueueNode *)Linklist_Get(queue, 0);
    return ret->p;
}

// 清空队列
void LinkQueue_Clear(void *queue)
{
    while (LinkQueue_Length > 0)
    {
        LinkQueue_Retrieve(queue);
    }
    LinkList_Clear(queue);
}

// 销毁队列
void LinkQueue_Destroy(void *queue)
{
    LinkQueue_Clear(queue);
    LinkQueue_Destroy(queue);
}
int main()
{
    int i = 0;
    int a[10];
    void *queue = NULL;
    queue = LinkQueue_Create();
    if (queue == NULL)
    {
        return -1;
    }

    for (int i = 0; i < 5; i++)
    {
        a[i] = i + 1;
        LinkQueue_Insert(queue, &a[i]);
    }

    // // 打印队列的属性
    // printf("len: %d \n", SeqQueue_Length(queue));
    // printf("header: %d \n", *(int *)(SeqQueue_Header(queue)));
    // printf("capacity: %d \n", (SeqQueue_Capacity(queue)));

    // while (SeqQueue_Length > 0)
    // {
    //     int tmp = *((int *)SeqQueue_Retrieve(queue));
    // }
    system("pause");
    return 0;
}
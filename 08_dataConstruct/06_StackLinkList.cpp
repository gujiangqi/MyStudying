/* 栈的链式存储实现 */
#include <iostream>
#include <cstdlib>
#include "03_LinkListLinux.cpp"
using namespace std;
typedef void LinkStack;

typedef struct _tag_LinkStackNode
{
    LinkListNode node; // 链表的业务节点
    void *item;        // 栈的业务节点
} LinkStackNode;

// 函数声明
LinkStack *LinkStack_Create();
LinkStack LinkStack_Destory(LinkStack *stack);
LinkStack LinkStack_Clear(LinkStack *stack);
int LinkStack_Push(LinkStack *stack, void *item);
LinkStack *LinkStack_Pop(LinkStack *stack);
LinkStack *LinkStack_Top(LinkStack *stack);
int LinkStack_Size(LinkStack *stack);

int main()
{
    int i = 0;
    int a[10];

    LinkStack *stack = NULL;
    stack = LinkStack_Create();
    // 添加元素
    for (i = 0; i < 5; i++)
    {
        a[i] = i + 1;
        LinkStack_Push(stack, &a[i]);
    }

    // 获取栈的基本属性
    printf("len: %d\n", LinkStack_Size(stack));
    printf("top: %d\n", *((int *)LinkStack_Top(stack)));

    // 删除栈的元素
    while (LinkStack_Size(stack) > 0)
    {
        int tmp = *((int *)LinkStack_Pop(stack));
        printf("tmp: %d", tmp);
    }
    printf("len: %d\n", LinkStack_Size(stack));
    // 销毁栈
    LinkStack_Destory(stack);
    system("pause");
    return 0;
}

// 函数定义
LinkStack *LinkStack_Create()
{
    // 创建一个线性链式存储结构的头部
    return Linklist_Create();
}

LinkStack LinkStack_Destory(LinkStack *stack)
{
    LinkStack_Clear(stack);
    LinkList_Destory(stack);
}

// 清空栈，
// 情空栈涉及到栈元素生命周期的管理
// 所有入栈的元素都是malloc出来的
LinkStack LinkStack_Clear(LinkStack *stack)
{
    if (stack == NULL)
    {
        return;
    }
    while (LinkList_Length(stack) > 0)
    {
        LinkStack_Pop(stack);
    }

    return;
}

// 向栈中添加元素，相当于 向线性表的头部插入元素
// void * item 栈的业务节点----->转换成链表的业务节点
int LinkStack_Push(LinkStack *stack, void *item)
{
    LinkStackNode *tmp = NULL;
    tmp = (LinkStackNode *)malloc(sizeof(LinkStackNode));
    if (tmp == NULL)
    {
        return -1;
    }
    memset(tmp, 0, sizeof(LinkStackNode));
    tmp->item = item;

    int ret = LinkList_Insert(stack, (LinkListNode *)tmp, 0);
    if (ret != 0)
    {
        printf("func LinkStack_Push Fail：%d", ret);
        if (tmp != NULL)
        {
            free(tmp);
        }
        return ret;
    }
    return ret;
}

// 从栈中弹出元素，相当于从线性表的头部删除元素
// 吧线性表的业务节点转化成栈的业务节点
LinkStack *LinkStack_Pop(LinkStack *stack)
{
    void *item = NULL;
    LinkStackNode *tmp = NULL;
    tmp = (LinkStackNode *)LinkList_Delete(stack, 0); //函数返回一个栈节点指针，通过业务节点指针转化成业务节点
    if (tmp == NULL)
    {
        return NULL;
    }
    item = tmp->item;
    // 因为LinkList_Insert的时候分配了内存，所以Pop需要释放内存
    free(tmp);
    return item;
}
LinkStack *LinkStack_Top(LinkStack *stack)
{
    LinkStackNode *tmp = NULL;
    tmp = (LinkStackNode *)Linklist_Get(stack, 0);
    if (tmp == NULL)
    {
        return NULL;
    }
    return tmp->item;
}

int LinkStack_Size(LinkStack *stack)
{
    return LinkList_Length(stack);
}
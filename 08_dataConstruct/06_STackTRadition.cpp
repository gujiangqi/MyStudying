/* 栈的顺序存储结构实现 */

#include <iostream>
#include <cstdlib>
#include "02_LinearTable.cpp"
using namespace std;
typedef void SeqStack;
// extern SeList_Create(int capacity);

// 创建一个栈，相当于创建一个线性表
SeqStack *SeqStack_Create(int capacity)
{
    return SeqList_Create(capacity);
    // return NULL;
}
void SeqStack_Destory(SeqStack *stack)
{
    SeqList_Destroy(stack);
}

// 情况栈，相当于清空线性表
void SeqStack_Clear(SeqStack *stack)
{
    SeqList_Clear(stack);
}

// 向栈中压入元素，相当于向链表的尾部插入元素
int SeqStack_Push(SeqStack *stack, void *item)
{
    // 尾插法
    return SeqList_Insert(stack, item, SeqList_Length(stack));
}

// 从栈中弹出元素，相当于从链表的尾部拿出元素
void *SeqStack_Pop(SeqStack *stack)
{
    return SeqList_Delete(stack, SeqList_Length(stack) - 1);
}

// 获取栈顶元素，相当于获取链表的尾部元素
void *SeqStack_Top(SeqStack *stack)
{
    return SeqList_Get(stack, SeqList_Length(stack) - 1);
}
// 获取栈的大小，相当于获取链表的实际长度
int SeqStack_Size(SeqStack *stack)
{
    return SeqList_Length(stack);
}

// 获取栈的容量，相当于获取链表的实际长度
int SeqStack_Capacity(SeqStack *stack)
{

    return SeqList_Capacity(stack);
}

int main()
{
    int i = 0;
    int a[10];
    SeqStack *stack = NULL;
    stack = SeqStack_Create(10);
    if (stack == NULL)
    {
        return 0;
    }
    // a[1] = 20;
    // int b = a[1];
    // SeqStack_Push(stack, &a[1]);
    // int result = *(int *)SeqStack_Top(stack);
    // cout << result << endl;
    // 压栈
    // for (int i = 0; i < 5; i++)
    // {
    //     a[i] = i + 1;
    //     SeqStack_Push(stack, &a[i]);
    // }
    a[0] = 1;
    SeqStack_Push(stack, &a[0]);
    a[1] = 2;
    SeqStack_Push(stack, &a[1]);

    int result = *(int *)SeqStack_Top(stack);
    cout << result << endl;
    // printf("capacity: %d\n", SeqStack_Capacity(stack));
    // printf("Length: %d\n", SeqStack_Size(stack));
    // int *tempInt = (int *)SeqStack_Top(stack);

    // cout << *tempInt << endl;

    // while (SeqStack_Size(stack) > 0)
    // {
    //     int *tmp = (int *)SeqStack_Pop(stack);
    //     cout << *tmp << endl;
    //     // printf("tmp:%d ", tmp);
    // }

    system("pause");
    return 0;
}
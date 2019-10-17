#include <iostream>
#include <cstdlib>
#include "02_LinearTable.cpp"
using namespace std;

//队列是一种特殊的线性表
// 相当于创建一个线性存储表

// 创建一个队列
void *SeqQueue_Create(int a)
{
    return SeqList_Create(a);
}

// 销毁一个队列
void SeqQueue_Destroy(void *queue)
{
    SeqList_Destroy(queue);
}

// 清空一个队列
void SeqQueue_Clear(void *queue)
{
    SeqList_Clear(queue);
}

// 进队列
// 队列的尾部进行插入
int SeqQueue_Append(void *queue, void *node)
{
    return SeqList_Insert(queue, node, SeqList_Length(queue));
}

// 出队列
// 队列的前段进行删除
void *SeqQueue_Retrieve(void *queue)
{
    return SeqList_Delete(queue, 0);
}

void *SeqQueue_Header(void *queue)
{
    return SeqList_Get(queue, 0);
}
int SeqQueue_Length(void *queue)
{
    return SeqList_Length(queue);
}
int SeqQueue_Capacity(void *queue)
{
    return SeqList_Capacity(queue);
}
int main()
{
    int i = 0;
    int a[10];
    void *queue = NULL;
    queue = SeqQueue_Create(10);
    if (queue == NULL)
    {
        return -1;
    }

    for (int i = 0; i < 5; i++)
    {
        a[i] = i + 1;
        int ret = SeqQueue_Append(queue, &a[i]);
    }

    // 打印队列的属性
    printf("len: %d \n", SeqQueue_Length(queue));
    printf("header: %d \n", *(int *)(SeqQueue_Header(queue)));
    printf("capacity: %d \n", (SeqQueue_Capacity(queue)));

    while (SeqQueue_Length > 0)
    {
        int tmp = *((int *)SeqQueue_Retrieve(queue));
    }

    system("pause");
    return 0;
}
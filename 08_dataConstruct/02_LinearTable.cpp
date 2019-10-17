#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

typedef void SeqList;
typedef void SeqListNode;
//在结构体中套一级指针
typedef struct _tag_SeqList
{
    int Length;
    int capacity;
    unsigned int *node; //指向内存空间
} TSeqList;

struct Teacher
{
    int age;
    char name[64];
};
SeqList *SeqList_Create(int capacity)
{
    SeqList *ret = 0;
    TSeqList *tmp;

    tmp = (TSeqList *)malloc(sizeof(TSeqList));
    if (tmp == NULL)
    {
        ret = (SeqList *)-1;
        printf("func SeqList_Create() err:%d \n", ret);
        return ret;
    }
    memset(tmp, 0, sizeof(TSeqList));

    // 根据capacity的大小分配节点的大小
    tmp->node = (unsigned int *)malloc(sizeof(unsigned int *) * capacity);
    if (tmp->node == NULL)
    {
        ret = (SeqList *)-1;
        printf("func SeqList_Create() malloc err:%d \n", ret);
        return ret;
    }
    tmp->capacity = capacity;
    tmp->Length = 0;
    return tmp;
}

void SeqList_Destroy(SeqList *list)
{
    TSeqList *tlist = NULL;
    if (list == NULL)
    {
        return;
    }
    tlist = (TSeqList *)list;
    if (tlist->node != NULL)
    {
        free(tlist->node);
    }

    free(tlist);
    return;
}

//清空链表 //回到初始化状态
void SeqList_Clear(SeqList *list)
{
    TSeqList *tlist = NULL;
    if (list == NULL)
    {
        return;
    }
    tlist = (TSeqList *)list;

    tlist->Length = 0;
    return;
}

//返回长度
int SeqList_Length(SeqList *list)
{
    TSeqList *tlist = NULL;
    if (list == NULL)
    {
        return -1;
    }
    tlist = (TSeqList *)list;

    return tlist->Length;
}

//返回长度
int SeqList_Capacity(SeqList *list)
{
    TSeqList *tlist = NULL;
    if (list == NULL)
    {
        return -1;
    }
    tlist = (TSeqList *)list;

    return tlist->capacity;
}

int SeqList_Insert(SeqList *list, SeqListNode *node, int pos)
{
    int i = 0, ret = 0;
    // 元素后移
    if (list == NULL || node == NULL || pos < 0)
    {
        ret = -1;
        printf("func SeqList_Insert() err: %d \n", ret);
        return ret;
    }
    TSeqList *tlist = NULL;
    tlist = (TSeqList *)list;

    //判断是不是满了
    if (tlist->Length >= tlist->capacity)
    {
        ret = -1;
        printf("func SeqList_Insert() err: %d \n", ret);
        return ret;
    }
    //容错修正 6个长度 容量20；用户pos10位置插入
    if (pos > tlist->Length)
    {
        ret = -1;
        printf("func SeqList_Insert() err: %d \n", ret);
        return ret;
    }

    for (int i = tlist->Length; i > pos; i--)
    {
        tlist->node[i] = tlist->node[i - 1];
        //a[7] = a[6];
    }
    tlist->Length++;
    // cout << node << " ";
    tlist->node[pos] = (unsigned int)node;
    //cout << tlist->node[i] << endl;

    return 0;
}

SeqListNode *SeqList_Get(SeqList *list, int pos)
{
    int i = 0;
    SeqListNode *ret = 0;
    // 元素后移
    if (list == NULL || pos < 0)
    {
        ret = (SeqListNode *)-1;
        printf("func SeqList_Get() err: %d \n", ret);
        return ret;
    }
    TSeqList *tlist = NULL;
    tlist = (TSeqList *)list;
    ret = (SeqListNode *)tlist->node[pos];
    return ret;
}

SeqListNode *SeqList_Delete(SeqList *list, int pos)
{

    SeqListNode *ret = 0;
    // 元素后移
    if (list == NULL || pos < 0)
    {
        ret = (SeqListNode *)-1;
        printf("func SeqList_Get() err: %d \n", ret);
        return ret;
    }
    TSeqList *tlist = NULL;
    tlist = (TSeqList *)list;
    ret = (SeqListNode *)tlist->node[pos];

    for (int i = pos + 1; i < tlist->Length; i++)
    {
        tlist->node[i - 1] = tlist->node[i];
    }
    tlist->Length--;

    return ret;
}
int main01()
{
    int ret = 0, i = 0;
    SeqList *list = NULL;
    Teacher t1, t2, t3, t4, t5, t6;
    t1.age = 31;
    strcpy(t1.name, "a");
    cout << t1.name << endl;
    t2.age = 32;
    strcpy(t2.name, "b");

    t3.age = 33;
    strcpy(t3.name, "c");

    t4.age = 34;
    strcpy(t4.name, "d");

    t5.age = 35;
    strcpy(t5.name, "e");

    t6.age = 36;
    strcpy(t6.name, "f");

    list = SeqList_Create(10); //指针

    if (list == NULL)
    {
        printf("func Seqlist_Create() ret : %d \n", ret);
        return -1;
    }
    ret = SeqList_Insert(list, (SeqListNode *)&t1, 0);
    Teacher *tempT1 = (Teacher *)SeqList_Get(list, 0);
    cout << tempT1->name << endl;
    ret = SeqList_Insert(list, (SeqListNode *)&t2, 0);
    ret = SeqList_Insert(list, (SeqListNode *)&t3, 0);
    ret = SeqList_Insert(list, (SeqListNode *)&t4, 0);
    ret = SeqList_Insert(list, (SeqListNode *)&t5, 0);
    ret = SeqList_Insert(list, (SeqListNode *)&t6, 2);

    // 遍历
    for (int i = 0; i < SeqList_Length(list); i++)
    {
        Teacher *tmp = (Teacher *)SeqList_Get(list, i);
        if (tmp == NULL)
        {
            return -1;
        }
        printf("tmp->age: %d", tmp->age);
    }

    // 删除链表中的节点
    while (SeqList_Length(list) > 0)
    {
        SeqList_Delete(list, 0);
    }

    system("pause");
    return 0;
}

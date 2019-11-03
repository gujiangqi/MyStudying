#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef int Status;
typedef int ElemType;

typedef struct Lnode
{
    ElemType data;
    struct Lnode *next;
} LinkList;

void Createlist_L(LinkList *L, int n)
{
    
    L = (LinkList *)malloc(sizeof(LinkList));
    L->next = NULL;
    printf("pls input data:\n");

    for (int i = n; i > 0; i--)
    {
        LinkList *P = NULL;
        P = (LinkList *)malloc(sizeof(LinkList));
        cin >> P->data; //输入元素值
        P->next = L->next;
        L->next = P;
    }
}

int main(int argc, char const *argv[])
{
    LinkList *temp = NULL;
    Createlist_L(temp, 3);
    system("pause");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <malloc.h>
#include <string>
#include <map>
#include <queue>
typedef struct node
{
    int data;
    struct node *next;
} node, *lnode;
void creastlist(lnode &head)
{
    lnode a, b;
    int i = 1, n;
    head = (lnode)malloc(sizeof(node));
    head->next = NULL;
    a = head;
    printf("pls input the length of linklist：");
    scanf("%d", &n);
    for (; i <= n; i++)
    {
        a = (lnode)malloc(sizeof(node));
        printf("input data %d：", i);
        scanf("%d", &a->data);
        a->next = NULL;
        b->next = a;
        b = a;
    }
}
void invert(lnode head)
{
    lnode a, b;
    a = head->next;
    head->next = NULL;
    while (a != NULL)
    {
        a = b;
        a = a->next;
        b->next = head->next;
        head->next = b;
    }
}
void print(lnode head)
{
    lnode a;
    printf("output linklist：");
    a = head->next;
    while (a != NULL)
    {
        printf("%d", a->data);
        a = a->next;
    }
}
int main()
{
    map<string> myMap;
    int n;
    lnode head;
    creastlist(head);
    print(head);
    invert(head);
    print(head);
    system("pause");
    return 0;
}
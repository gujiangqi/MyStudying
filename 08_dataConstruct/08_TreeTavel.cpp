#include <iostream>
#include <cstdlib>
#include "string.h"
#include <stack>
using namespace std;

// 二叉树链表表示法
struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
};
void preOrder(BiTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);

    // 遍历左子树
    preOrder(root->lchild);

    // 遍历右子树
    preOrder(root->rchild);
};
void inOrder(BiTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    // 遍历左子树
    inOrder(root->lchild);
    printf("%d ", root->data);

    // 遍历右子树
    inOrder(root->rchild);
};
void postOrder(BiTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    // 遍历左子树
    postOrder(root->lchild);

    // 遍历右子树
    postOrder(root->rchild);

    printf("%d ", root->data);
};
int sum = 0;
void countLeaf(BiTNode *T)
{
    if (T != NULL)
    {
        if (T->lchild == NULL && T->rchild == NULL)
        {
            sum++;
        }
        if (T->lchild)
        {
            countLeaf(T->lchild);
        }

        if (T->rchild)
        {
            countLeaf(T->rchild);
        }
    }
}

// 一直向左走，找到中序遍历的起点
BiTNode *goLeft(BiTNode *T, stack<BiTNode *> &s)
{
    if (T == NULL)
    {
        return NULL;
    }
    while (T->lchild != NULL) // 如果左节点非空，压栈，同时T指向下一个节点
    {
        s.push(T);
        T = T->lchild;
    }

    return T;
}

void inOrderNodigui(BiTNode *T)
{
    BiTNode *t = NULL;
    stack<BiTNode *> s;

    // 开始遍历找寻左节点
    t = goLeft(T, s);
    // t此时没有左节点
    while (t)
    {
        printf("%d", t->data);

        // 如果t有右子树，重复步骤1
        // 如果t有右节点
        if (t->rchild != NULL)
        {
            t = goLeft(t->rchild, s); //右子树中中序遍历的起点
        }
        else if (!s.empty())
        {
            t = s.top();
            s.pop();
        }
        else
        {
            t = NULL;
        }

        // 如果t没有右子树，根据栈顶指示， 回退
    }
}

// 先序遍历
void countLeaf3(BiTNode *T, int *sum)
{
    if (T != NULL)
    {
        if (T->lchild == NULL && T->rchild == NULL)
        {
            (*sum)++;
        }
        if (T->lchild)
        {
            countLeaf3(T->lchild, sum);
        }

        if (T->rchild)
        {
            countLeaf3(T->rchild, sum);
        }
    }
}

// 中序遍历
void countLeaf4(BiTNode *T, int *sum)
{
    if (T != NULL)
    {

        if (T->lchild)
        {
            countLeaf4(T->lchild, sum);
        }
        if (T->lchild == NULL && T->rchild == NULL)
        {
            (*sum)++;
        }
        if (T->rchild)
        {
            countLeaf4(T->rchild, sum);
        }
    }
}

// 后序遍历
void countLeaf5(BiTNode *T, int *sum)
{
    if (T != NULL)
    {

        if (T->lchild)
        {
            countLeaf5(T->lchild, sum);
        }

        if (T->rchild)
        {
            countLeaf5(T->rchild, sum);
        }
        if (T->lchild == NULL && T->rchild == NULL)
        {
            (*sum)++;
        }
    }
}

BiTNode *copyTree(BiTNode *T1)
{

    BiTNode *newlchild = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *newrchild = (BiTNode *)malloc(sizeof(BiTNode));

    if (T1 == NULL)
    {
        return NULL;
    }
    if (T1->lchild != NULL)
    {
        newlchild = copyTree(T1->lchild);
    }
    else
    {
        newlchild = NULL;
    }

    if (T1->rchild != NULL)
    {
        newrchild = copyTree(T1->rchild);
    }
    else
    {
        newrchild = NULL;
    }

    //malloc 根节点
    BiTNode *newT1 = (BiTNode *)malloc(sizeof(BiTNode));
    if (newT1 == NULL)
    {
        return NULL;
    }
    newT1->lchild = newlchild;
    newT1->rchild = newrchild;

    newT1->data = T1->data;

    return newT1;
}
int main()
{
    int mysum = 0;
    BiTNode t1, t2, t3, t4, t5;
    memset(&t1, 0, sizeof(BiTNode));
    memset(&t2, 0, sizeof(BiTNode));
    memset(&t3, 0, sizeof(BiTNode));
    memset(&t4, 0, sizeof(BiTNode));
    memset(&t5, 0, sizeof(BiTNode));

    t1.data = 1;
    t2.data = 2;
    t3.data = 3;
    t4.data = 4;
    t5.data = 5;

    // 建立关系
    t1.lchild = &t2;
    t1.rchild = &t3;
    t2.lchild = &t4;
    t3.lchild = &t5;

    // preOrder(&t1);

    // cout << endl;

    // inOrder(&t1);

    // cout << endl;

    // // postOrder(&t1);

    // // countLeaf3(&t1, &mysum);

    // // cout << endl;
    // // printf("Sum: %d", mysum);

    // countLeaf4(&t1, &mysum);

    // cout << endl;
    // printf("Sum: %d", mysum);

    // // 树的拷贝
    // BiTNode *p = copyTree(&t1);

    // preOrder(&t1);

    // cout << endl;

    // preOrder(p);

    // cout << endl;
    system("pause");
    return 0;
}
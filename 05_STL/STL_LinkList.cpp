#include <iostream>
#include "stdlib.h"
#include <cstdlib>

typedef int DataType;
#define Node ElemType
#define ERROR NULL

using namespace std;

struct node
{
    int data;
    node *next;
};

// 构建一个节点类
class Node
{
public:
    int Data;
    Node *next;

private:
    /* data */
public:
    Node(/* args */) {}
    ~Node() {}
};
class LinkList
{
private:
    ElemType *Head;

public:
    LinkList();
    ~LinkList();

public:
    void CreateLinkList(int n);                   //创建一个单链表
    void TravalLinkList();                        //遍历线性表
    int GetLength();                              //获取线性表长度
    bool IsEmpty();                               //判断单链表是否为空
    ElemType *Find(DataType data);                //查找节点
    void InsertElemAtEnd(DataType data);          //在尾部插入指定的元素
    void InsertElemAtIndex(DataType data, int n); //在指定位置插入指定元素
    void InsertElemAtHead(DataType data);         //在头部插入指定元素
    void DeleteElemAtEnd();                       //在尾部删除元素
    void DeleteAll();                             //删除所有数据
    void DeleteElemAtPoint(DataType data);        //删除指定的数据
    void DeleteElemAtHead();                      //在头部删除节点
};
LinkList::LinkList()
{
    Head = new ElemType;
    Head->Data = 0;    //将头节点的数据定义为0
    Head->next = NULL; //头节点的下一个定义为NULL
}
LinkList::~LinkList()
{
    delete Head; //删除头节点
}

void LinkList::CreateLinkList(int n)
{
    ElemType *pnew, *ptemp;
    ptemp = Head;
    if (n < 0)
    {
        std::cout << "输入的节点个数有误： " << std::endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++)
    {
        pnew = new ElemType;
        std::cout << "请输入第" << i + 1 << "个值";
        cin >> pnew->Data;
        pnew->next = NULL;
        ptemp->next = pnew; //讲当前节点的下一个地址设为新节点
        ptemp = pnew;       //将当前节点设为新节点
    }
}

void LinkList::TravalLinkList()
{
    if (Head == NULL || Head->next == NULL)
    {
        std::cout << "链表为空" << std::endl;
    }
    ElemType *p = Head;
    while (p->next != NULL)
    {
        p = p->next;
        std::cout << p->Data << " ";
    }
}

int LinkList::GetLength()
{
    int count = 0;
    ElemType *p = Head->next;
    while (p->next != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
bool LinkList::IsEmpty()
{
    if (Head->next == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
ElemType *LinkList::Find(DataType data)
{
    ElemType *p = Head;
    if (p == NULL)
    {
        std::cout << "此链表为空链表" << std::endl;
    }
    else
    {
        while (p->next != NULL)
        {
            if (p->Data == data)
            {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }
    return NULL;
}

//尾部插入指定的元素
void LinkList::InsertElemAtEnd(DataType data)
{
    ElemType *newNode = new ElemType;
    newNode->Data = data;
    newNode->next = NULL;
    ElemType *p = Head;
    if (Head == NULL)
    {
        Head = newNode;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newNode;
    }
}

//在指定位置插入指定元素
void LinkList::InsertElemAtIndex(DataType data, int n)
{
    if (n < 1 || n > GetLength())
    {
        std::cout << "输入的值有错误" << std::endl;
    }
    else
    {
        ElemType *p = Head;
        ElemType *ptemp = new ElemType;
        ptemp->Data = data;
        int i = 1;
        while (n > i)
        {
            p = p->next;
            i++;
        }
        ptemp->next = p->next;
        p = ptemp;
    }
}

//在头部插入指定元素
void LinkList::InsertElemAtHead(DataType data)
{
    ElemType *ptemp = new ElemType;
    ptemp->Data = data;
    ElemType *p = Head;
    if (Head == NULL)
    {
        std::cout << "单链表空" << std::endl;
    }
    else
    {
        ptemp->next = p->next;
        p->next = ptemp;
    }
}

//在尾部删除元素
void LinkList::DeleteElemAtEnd()
{
    ElemType *p = Head;
    ElemType *ptemp;
    ptemp = Head;
    if (p == NULL)
    {
        std::cout << "为单链表" << std::endl;
    }
    else
    {
        while (p->next != NULL)
        {
            ptemp = p;   //加上这句话可以存储尾部的前第二个值得地址
            p = p->next; //然后将倒数第一个赋值给p
        }
        delete p; //这样的话，倒数2个所指下一个也不是空，被删除了;
        p = NULL;
        ptemp->next = NULL;
    }
}
void LinkList::DeleteAll()
{
    ElemType *p = Head->next;
    ElemType *ptemp = new ElemType;
    while (p->next != NULL)
    {
        //自己写的没有吧头节点指向下下个
        ptemp = p;
        p = p->next;        //吧第三个地址取出来赋值给p
        Head->next = p;     //把第三个赋值给第一个的下一个
        ptemp->next = NULL; //
        delete ptemp;
    }
    Head->next = NULL;
}
//删除指定的数据
void LinkList::DeleteElemAtPoint(DataType data)
{
    ElemType *ptemp = Find(data);
    if (ptemp = Head->next)
    {
        DeleteElemAtHead();
    }
    else
    {
        ElemType *p = Head;
        while (p->next != ptemp)
        {
            p = p->next;
        }
        p->next = ptemp->next;
        delete ptemp;
        ptemp = NULL;
    }
}
void LinkList::DeleteElemAtHead()
{
    ElemType *p = Head;
    if (p == NULL || p->next == NULL)
    {
        std::cout << "该链表为空" << std::endl;
    }
    else
    {
        ElemType *ptemp = new ElemType;
        p = p->next;
        ptemp = p->next;
        delete p;
        p = NULL;
        Head->next = ptemp;
    }
}
int main()
{
    LinkList l;
    int i;
    do
    {
        cout << "请输入要执行的操作: ";
        cin >> i;
        switch (i)
        {
        case 1:
            int n;
            cout << "请输入单链表的长度: ";
            cin >> n;
            l.CreateLinkList(n);
            break;
        }
    } while (i != 0);

    system("pause");
    return 0;
}
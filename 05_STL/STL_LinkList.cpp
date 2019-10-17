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

// ����һ���ڵ���
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
    void CreateLinkList(int n);                   //����һ��������
    void TravalLinkList();                        //�������Ա�
    int GetLength();                              //��ȡ���Ա���
    bool IsEmpty();                               //�жϵ������Ƿ�Ϊ��
    ElemType *Find(DataType data);                //���ҽڵ�
    void InsertElemAtEnd(DataType data);          //��β������ָ����Ԫ��
    void InsertElemAtIndex(DataType data, int n); //��ָ��λ�ò���ָ��Ԫ��
    void InsertElemAtHead(DataType data);         //��ͷ������ָ��Ԫ��
    void DeleteElemAtEnd();                       //��β��ɾ��Ԫ��
    void DeleteAll();                             //ɾ����������
    void DeleteElemAtPoint(DataType data);        //ɾ��ָ��������
    void DeleteElemAtHead();                      //��ͷ��ɾ���ڵ�
};
LinkList::LinkList()
{
    Head = new ElemType;
    Head->Data = 0;    //��ͷ�ڵ�����ݶ���Ϊ0
    Head->next = NULL; //ͷ�ڵ����һ������ΪNULL
}
LinkList::~LinkList()
{
    delete Head; //ɾ��ͷ�ڵ�
}

void LinkList::CreateLinkList(int n)
{
    ElemType *pnew, *ptemp;
    ptemp = Head;
    if (n < 0)
    {
        std::cout << "����Ľڵ�������� " << std::endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++)
    {
        pnew = new ElemType;
        std::cout << "�������" << i + 1 << "��ֵ";
        cin >> pnew->Data;
        pnew->next = NULL;
        ptemp->next = pnew; //����ǰ�ڵ����һ����ַ��Ϊ�½ڵ�
        ptemp = pnew;       //����ǰ�ڵ���Ϊ�½ڵ�
    }
}

void LinkList::TravalLinkList()
{
    if (Head == NULL || Head->next == NULL)
    {
        std::cout << "����Ϊ��" << std::endl;
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
        std::cout << "������Ϊ������" << std::endl;
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

//β������ָ����Ԫ��
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

//��ָ��λ�ò���ָ��Ԫ��
void LinkList::InsertElemAtIndex(DataType data, int n)
{
    if (n < 1 || n > GetLength())
    {
        std::cout << "�����ֵ�д���" << std::endl;
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

//��ͷ������ָ��Ԫ��
void LinkList::InsertElemAtHead(DataType data)
{
    ElemType *ptemp = new ElemType;
    ptemp->Data = data;
    ElemType *p = Head;
    if (Head == NULL)
    {
        std::cout << "�������" << std::endl;
    }
    else
    {
        ptemp->next = p->next;
        p->next = ptemp;
    }
}

//��β��ɾ��Ԫ��
void LinkList::DeleteElemAtEnd()
{
    ElemType *p = Head;
    ElemType *ptemp;
    ptemp = Head;
    if (p == NULL)
    {
        std::cout << "Ϊ������" << std::endl;
    }
    else
    {
        while (p->next != NULL)
        {
            ptemp = p;   //������仰���Դ洢β����ǰ�ڶ���ֵ�õ�ַ
            p = p->next; //Ȼ�󽫵�����һ����ֵ��p
        }
        delete p; //�����Ļ�������2����ָ��һ��Ҳ���ǿգ���ɾ����;
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
        //�Լ�д��û�а�ͷ�ڵ�ָ�����¸�
        ptemp = p;
        p = p->next;        //�ɵ�������ַȡ������ֵ��p
        Head->next = p;     //�ѵ�������ֵ����һ������һ��
        ptemp->next = NULL; //
        delete ptemp;
    }
    Head->next = NULL;
}
//ɾ��ָ��������
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
        std::cout << "������Ϊ��" << std::endl;
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
        cout << "������Ҫִ�еĲ���: ";
        cin >> i;
        switch (i)
        {
        case 1:
            int n;
            cout << "�����뵥����ĳ���: ";
            cin >> n;
            l.CreateLinkList(n);
            break;
        }
    } while (i != 0);

    system("pause");
    return 0;
}
#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};
void CreatList(Node *Head, int n)
{
    //�����µ�Node��ʱ����Ҫ���µ�ֵ�ȴ��ڽṹ���У���Ȼ�����overstack
    Node *pnew;
    Node *ptemp = Head;
    for (int i = 0; i < n; i++)
    {
        pnew = new Node;
        std::cout << "�������һ�����ݣ�int����" << std::endl;
        cin >> pnew->data;
        pnew->next = NULL;
        ptemp->next = pnew;
        ptemp = pnew;
    }
 
}
int main()
{
    Node Head;
    std::cout << "����������ĳ��ȣ�" << std::endl;
    int n;
    cin >> n;
    CreatList(&Head, n);
    system("pause");
    return 0;
}
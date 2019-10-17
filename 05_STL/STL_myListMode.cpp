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
    //输入新的Node的时候需要将新的值先存在结构体中，不然会存在overstack
    Node *pnew;
    Node *ptemp = Head;
    for (int i = 0; i < n; i++)
    {
        pnew = new Node;
        std::cout << "请输入第一个数据（int）：" << std::endl;
        cin >> pnew->data;
        pnew->next = NULL;
        ptemp->next = pnew;
        ptemp = pnew;
    }
 
}
int main()
{
    Node Head;
    std::cout << "请输入链表的长度：" << std::endl;
    int n;
    cin >> n;
    CreatList(&Head, n);
    system("pause");
    return 0;
}